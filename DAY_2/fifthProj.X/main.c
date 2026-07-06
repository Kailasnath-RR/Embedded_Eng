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
void GPIO_init(void){
    ANSELFbits.ANSF4 = 0;
    ANSELFbits.ANSF5 = 0;
    ANSELGbits.ANSG3 = 0;
    TRISFbits.TRISF4 = 0;
    TRISFbits.TRISF5 = 0;
    TRISFbits.TRISF6 = 0;
    TRISGbits.TRISG3 = 0;
    LATFbits.LATF4 = 0;
    LATFbits.LATF5 = 0;
    LATFbits.LATF6 = 0;
    LATGbits.LATG3 = 0;
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
    GPIO_init();
    Timer_init();
    volatile long i ;
    while(1){
        LATGbits.LATG3 =!LATGbits.LATG3;
        for(i = 0;i<500000;i++);
    }
   
}

