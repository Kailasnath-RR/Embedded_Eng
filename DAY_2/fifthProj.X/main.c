/* 
 * File:   main.c
 * Author: Intern08
 *
 * Created on 6 July, 2026, 3:37 PM
 */

#include <xc.h>

#pragma config FNOSC=PRIPLL
#pragma config POSCMD=HS
#pragma config IESO=OFF
#pragma config FCKSM=CSDCMD
#pragma config OSCIOFNC=ON

int state = 0;
void Clock_Init(){
    PLLFBD = 68;
    CLKDIVbits.PLLPRE = 0;
    CLKDIVbits.PLLPOST = 0;
    while(OSCCONbits.LOCK==0);
}
void GPIO_init(void){
    ANSELFbits.ANSF4 = 0;
    ANSELFbits.ANSF5 = 0;
    ANSELGbits.ANSG2 = 0;
    ANSELGbits.ANSG3 = 0;
    ANSELGbits.ANSG11 = 0;
    TRISFbits.TRISF4 = 0;
    TRISFbits.TRISF5 = 0;
    TRISFbits.TRISF6 = 0;
    TRISGbits.TRISG2 = 0;
    TRISGbits.TRISG3 = 0;
    TRISGbits.TRISG11 = 0;
    TRISBbits.TRISB10 = 0;
    LATFbits.LATF4 = 0;
    LATFbits.LATF5 = 0;
    LATFbits.LATF6 = 0;
    LATGbits.LATG3 = 0;
    LATGbits.LATG2 = 0;
    LATGbits.LATG11 = 0;
    LATBbits.LATB10 = 0;
}

void Timer_init(void){
    T1CONbits.TCS = 0;
    T1CONbits.TCKPS = 3;
    TMR1 = 0;
    PR1 = 65535;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    IPC0bits.T1IP = 4;
    INTCON2bits.GIE = 1;
    T1CONbits.TON = 1;
    

}


void __attribute__((interrupt,auto_psv))_T1Interrupt(void){
    LATBbits.LATB10 = !LATBbits.LATB10; // Toggle RB10 to measure the output frequency and period using an oscilloscope
    switch(state){
        case 0: 
            state = 1;
            break;
        case 1:
            LATFbits.LATF5 = 0;
            LATFbits.LATF4 = 1;
            state = 2;
            break;
        case 2:
            LATFbits.LATF4 = 0;
            LATFbits.LATF5 = 1;
            state = 3;
            break;
        case 3:
            LATFbits.LATF5 = 0;
            LATFbits.LATF6 = 1;
            state = 4;
            break;
        case 4:
            LATFbits.LATF6 = 0;
            LATFbits.LATF5 = 1;
            state = 1;
            break;
    }
    IFS0bits.T1IF = 0;

}

int main(void) {
    Clock_Init();
    GPIO_init();
    Timer_init();
    volatile long i;
    int state2=0;
    while(1){
        
        switch(state2){
                
            case 0:  state2 = 1; 
                      break;
            
            case 1:  
                    LATGbits.LATG3 =1;
                     state2 = 2;
                     for(i = 0 ; i < 6553500;i++ );
                     LATGbits.LATG3 = 0;
                     break;
            
            case 2: 
                
                    LATGbits.LATG2 = 1;
                    state2 = 3;
                    for(i = 0 ; i < 6553500;i++ );
                    LATGbits.LATG2 = 0;
                    break;
            case 3:
                
                LATGbits.LATG11 = 1;
                state2 = 4;
                for(i = 0 ; i < 6553500;i++ );
                LATGbits.LATG11 = 0;
                break;
                
            case 4: 
                    LATGbits.LATG2 = 1;
                    state2 = 1;
                    for(i = 0 ; i < 6553500;i++ );
                    LATGbits.LATG2 = 0;
                    break;
            
       }

    }
   
}

