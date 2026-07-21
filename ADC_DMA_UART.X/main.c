
/* 
 * File:   main.c
 * Author: Intern08
 *
 * Created on 16 July, 2026, 10:39 AM
 */

#include <xc.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <p33EP512GM710.h>

/*
 * 
 */
int sampleCount = 0;
volatile uint16_t samples[16]
    __attribute__((space(xmemory), aligned(32))); //buffer that holds adc1buf0 values


int Data_Ready_flag = 0;

volatile uint16_t values;

int machine_state = 0;  // 1 => running , 0=>stop/paused

long sampling_speed_reset = 0;

int lock_state = 0;

char buffer[100];
void GPIO_Init(void){
    
    ANSELGbits.ANSG10 = 0;
    ANSELGbits.ANSG11 = 0;
    ANSELGbits.ANSG2 = 0;
    ANSELGbits.ANSG3 = 0;
    
    ANSELFbits.ANSF4 = 0 ;
    ANSELFbits.ANSF5 = 0;
    
    TRISFbits.TRISF4 = 0;   //LED 7
    TRISFbits.TRISF5 = 0;   //LED 8
    TRISFbits.TRISF6 = 0;   //LED 9
    TRISFbits.TRISF7 = 0;  //LED 10
    
    TRISGbits.TRISG10 = 0;   //LED 3
    TRISGbits.TRISG11 = 0;   //LED 4
    TRISGbits.TRISG2 = 0;   //LED 5
    TRISGbits.TRISG3 = 0;   //LED 6
    
    LATFbits.LATF4 = 0;   //LED 7
    LATFbits.LATF5 = 0;   //LED 8
    LATFbits.LATF6 = 0;   //LED 9
    LATFbits.LATF7 = 0;  //LED 10
    
    LATGbits.LATG10 = 0;   //LED 3
    LATGbits.LATG11 = 0;  //LED 4
    LATGbits.LATG2 = 0;   //LED 5
    LATGbits.LATG3 = 0;   // All LEDs initialized to 0 //LED 6
    
    
}





void UART_Init(void){
    
  
    
    // Set pin RB4 (the TX pin) as a digital output
    TRISBbits.TRISB4 = 0; 
    
    // Open the hardware safety lock to reassign mapping paths
    __builtin_write_OSCCONL(OSCCON & 0xBF); // Clear bit 6 to unlock PPS
    
    // Connect internal UART1 TX engine out to physical pin RP36 (RB4)
    RPOR1bits.RP36R = 0x0001;    //RB4->UART1:U1TX
    RPINR18bits.U1RXR = 0x0018;    // 24 points to pin RA8
    
    // Relock the safety gate to protect against accidental changes at runtime
    __builtin_write_OSCCONL(OSCCON | 0x40); // Set bit 6 to lock PPS
    
   
    
    U1MODEbits.UARTEN = 0;  // Keep module turned off while we edit settings
    U1STA = 0x00;           // Clear any residual error flags
    
    U1MODEbits.PDSEL = 0;   // 00 = 8 data bits, no parity bit
    U1MODEbits.STSEL = 0;   // 0  = 1 stop bit
    
    U1MODEbits.BRGH = 1;    // Enable High-Speed Mode (divides clock by 4)
    U1BRG = 95;             // 95 matches 9600 Baud at 3.685 MHz instruction clock
    
 
    
    U1MODEbits.UARTEN = 1;  // Turn on the core UART1 module engine
    U1STAbits.UTXEN = 1;    // Power up the transmission hardware circuit pin
    
    IFS0bits.U1RXIF = 0;
    IEC0bits.U1RXIE = 1; //enable recieve interrupt
}

void TImer3_Init(void){
        
   
    T3CON = 0; //clean slate
    T3CONbits.TCS = 0; 
    T3CONbits.TCKPS = 2; //1:64 prescaler
    
    TMR3 = 0;//<-init time
    PR3 = 10000; //<-count to
    
    IFS0bits.T3IF = 0; //timer 3 interrupt flag clear
    IEC0bits.T3IE = 0; //timer 3 interrupt enable
    T3CONbits.TON = 1; //switch on timer   




}

void DMA_Init(void){
    DMA0CONbits.CHEN = 0; //disable channel before changing configs
    DMA0CONbits.SIZE = 0; //transfer bit size (0 => 16 bits)
    DMA0CONbits.DIR = 0; //sets dma direction from peripheral to ram
    
    
    DMA0CONbits.AMODE = 0; //register indirect with post increment
    DMA0CONbits.MODE = 0; //continuous mode
    
    DMA0PAD = (volatile unsigned int)&ADC1BUF0; //source location for dma
    
    DMA0STAL = __builtin_dmaoffset(samples);
    DMA0STAH = 0;
    DMA0CNT = 15; //16 count
    
    DMA0REQ = 13;
    IFS0bits.DMA0IF = 0; //clear dma interrupt flag
    IEC0bits.DMA0IE = 1; //enable dma interrupts
    
    DMA0CONbits.CHEN = 1; //enable dma 

}


void UART_WriteCHar(char data){
    while(U1STAbits.UTXBF == 1);
    
    U1TXREG = data;

}

void UART_WriteString(char *str){

    while(*str !='\0'){
        UART_WriteCHar(*str);
        str++;
    
    }
}

void lock_check(char c){
    if(c == '\r' || c == ' ' || c == '\n') return;
    
    
    if(lock_state == 0 && c == 'A'){
        lock_state = 1;
    }
    else if(lock_state == 1 && c == 'B'){
        lock_state = 2;
    }
    else if (lock_state == 2 && c == 'C'){
        lock_state = 3;
        UART_WriteString("TYPE=STATUS,STATE=UNLOCKED\r\n");
        
    }else{
        lock_state = 0;
        UART_WriteString("TYPE=STATUS,STATE=LOCKED\r\n");
    }

}


void set_machine_state(char c){
    if(lock_state < 3){
        lock_check(c);
    }
    else if(lock_state == 3){
    
            if(c == '\r' || c ==' ' || c == '\n') return;

            if(c == 'p' || c == 'P'){
                machine_state = 0;
                UART_WriteString("TYPE=STATUS,STATE=PAUSED\r\n");
            }
            else if(c == 's' || c == 'S'){
                machine_state = 1;
                UART_WriteString("TYPE=STATUS,STATE=RUNNING\r\n");
            }
            else if(c == '+'){
                if(PR3 < 4000){ PR3 = 4000;}
                PR3 -=2000;
                UART_WriteString("TYPE=STATUS,STATE=SPEED_INCREASED\r\n");

            }
            else if(c == '-'){
                if(PR3 < 4000){ PR3 = 4000;}

                if(PR3>4000){
                    PR3 +=2000;
                    UART_WriteString("TYPE=STATUS,STATE=SPEED_DECREASED\r\n");
                }

            }
            else if(c == 'L'){
                lock_state = 0;
                UART_WriteString("TYPE=STATUS,STATE=LOCKED\r\n");
        
            }       
    
        else{
            UART_WriteString("TYPE=ERROR,STATE=INVALID_COMMAND\r\n");
        }
    }
    
    
    

}
void LED_ON(uint16_t values){
    if(values >0){
         LATFbits.LATF7 = 1;  
    }
    if(values > 128){
         LATFbits.LATF6 = 1;  
    }
    if(values > 256){
        LATFbits.LATF5 = 1;  
    }
    if(values > 384){
        LATFbits.LATF4 = 1;   //LED 7
    }
    if(values > 512){
        LATGbits.LATG3 = 1; //LED 6
    }
    if(values > 640){
        LATGbits.LATG2 = 1;   //LED 5
    }
    if(values > 768){
        LATGbits.LATG11 = 1;  //LED 4
    }
    if(values > 896){
        LATGbits.LATG10 = 1;   //LED 3
    }
    if(values == 0){
         LATFbits.LATF7 = 0;  
    }
    if(values  < 128){
         LATFbits.LATF6 = 0;  
    }
    if(values < 256){
        LATFbits.LATF5 = 0;  
    }
    if(values < 384){
        LATFbits.LATF4 = 0;   //LED 7
    }
    if(values < 512){
        LATGbits.LATG3 = 0; //LED 6
    }
    if(values < 640){
        LATGbits.LATG2 = 0;   //LED 5
    }
    if(values < 768){
        LATGbits.LATG11 = 0;  //LED 4
    }
    if(values < 896){
        LATGbits.LATG10 = 0;   //LED 3
    }
    
}

void __attribute__((interrupt,no_auto_psv)) _DMA0Interrupt(void)
{   
    Data_Ready_flag = 1;
    IFS0bits.DMA0IF = 0;
}

void __attribute__((interrupt,no_auto_psv)) _U1RXInterrupt(void){
    if(U1STAbits.OERR == 1){
        U1STAbits.OERR = 0; // Clear buffer overrun error if telemetry flooded RX
    }
    set_machine_state(U1RXREG);
     IFS0bits.U1RXIF = 0;
}


int main() {
    SYS_Initialize();
    GPIO_Init();
    UART_Init();
    DMA_Init();
    TImer3_Init();
    
    
    
    
    while(1){
       if(machine_state == 1)
            LED_ON(ADC1BUF0);
       if(machine_state == 1){
            if(Data_Ready_flag == 1){
            
                values = samples[15];
                LED_ON(values);
                //float voltage  = (values *3.3)/1023;
                sprintf(buffer,"TYPE=DATA,COUNT=%u,ADC=%u,SAMPLE_PERIOD=%u\r\n",sampleCount++,values,PR3);
                UART_WriteString(buffer);
                Data_Ready_flag = 0;
            }
       }
       else if(machine_state == 0){
           Data_Ready_flag = 0;
       }
       
    }
}

