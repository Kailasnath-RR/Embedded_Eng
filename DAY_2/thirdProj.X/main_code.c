/* 
 * File:   main_code.c
 * Author: Intern08
 *
 * Created on 6 July, 2026, 2:06 PM
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
int main(void) {
        T1CONbits.TCS = 0;
        T1CONbits.TCKPS = 3;
        TMR1 = 0;
        PR1 = 65535;
        IFS0bits.T1IF = 0;
        T1CONbits.TON=1;
        ANSELFbits.ANSF4 = 0;
        TRISFbits.TRISF4 = 0;
        LATFbits.LATF4 = 0;
        
    while(1){
        if(IFS0bits.T1IF){
            LATFbits.LATF4 = !LATFbits.LATF4;
             IFS0bits.T1IF = 0;
             TMR1 = 0;
            
        }
       
        
        
        
        
    }
}

