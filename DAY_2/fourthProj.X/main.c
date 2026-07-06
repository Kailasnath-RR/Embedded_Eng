/* 
 * File:   main.c
 * Author: Intern08
 *
 * Created on 6 July, 2026, 2:54 PM
 */

#include <xc.h>
#pragma config FNOSC=PRIPLL
#pragma config POSCMD=HS
#pragma config IESO=OFF
#pragma config FCKSM=CSDCMD
#pragma config OSCIOFNC=ON

/*
 * 
 */

void GPIO_init(void){
    ANSELFbits.ANSF4 = 0;
    TRISFbits.TRISF4 = 0;
    LATFbits.LATF4=0;
}
void Timer_init(void){
    T1CONbits.TCS = 0;
    T1CONbits.TCKPS = 3;
    TMR1=0;
    PR1=65535;
    IFS0bits.T1IF= 0;
    IEC0bits.T1IE = 1; 
    IPC0bits.T1IP= 4;
    T1CONbits.TON=1;
    INTCON2bits.GIE =1;
}

void __attribute__((interrupt,auto_psv)) _T1Interrupt(void){
    LATFbits.LATF4=!LATFbits.LATF4;
    IFS0bits.T1IF = 0;
}

int main(void) {
    GPIO_init();
    Timer_init();
    while(1){
        
    }
}

