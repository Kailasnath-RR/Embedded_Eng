/* 
 * File:   main_code.c
 * Author: Intern08
 *
 * Created on 3 July, 2026, 3:13 PM
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
    ANSELFbits.ANSF4=0;
    TRISFbits.TRISF4=0;
    TRISDbits.TRISD6=1;
    int ledState = 0;
    int prevState=0;
    while(1){
        int currState=PORTDbits.RD6;
        if(currState==1 && prevState==0){
            ledState=!ledState;
            LATFbits.LATF4=ledState;
            
            
            
        }
        prevState = currState;
        
    }
}

