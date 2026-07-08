/* 
 * File:   main.c
 * Author: Intern08
 *
 * Created on 8 July, 2026, 8:53 AM
 */
#include <xc.h>
#include <stdio.h>
#include "bsp/lcd.h"
/*
 * 
 */

volatile int state=0;
void GPIO_init(void){
    TRISDbits.TRISD6 = 1;  //s3 -> left button set to input
    TRISDbits.TRISD13 = 1; //s4 -> right button set to input
    LATDbits.LATD13 = 0; //init no use tbh
    LATDbits.LATD6 = 0;
    
}

void Timer_init(void){
    T1CONbits.TCS = 0; //
    T1CONbits.TCKPS = 3;//<-set 1:256 timer increments every 256 clock pulses (prescaler)
    TMR1 = 0;//<-init time
    PR1 = 65535; //<-count to
    IFS0bits.T1IF = 0; //clear timer interrupt flag
    IEC0bits.T1IE = 1; //enable timer interrupt
    IPC0bits.T1IP = 4; // set timer interrupt priority to 4
    INTCON2bits.GIE = 1; //allow interrupts 
     // timer on
    

}
void start_msg(){
    LCD_ClearScreen();
    LCD_PutString(" PRESS SMTG PLS",15);

}

void __attribute__((interrupt,auto_psv))_T1Interrupt(void){
    state++;
    if(state>5){
        state = 0;
    }
    switch(state){
        
            case 0 :    LCD_ClearScreen();
                        LCD_PutString("Please stop.",12);
                        break;
        
            case 1:     LCD_ClearScreen();
                        LCD_PutString("Still pressing?",15);
                        break;
            
            case 2:     LCD_ClearScreen();
                        LCD_PutString(" Really?",8);
                        break;
            case 3:
                        LCD_ClearScreen();
                        LCD_PutString("I'm judging you.",16);
                        break;
            case 4:     
                        LCD_ClearScreen();
                        LCD_PutString("This is awkward.",16);
                        break;
            case 5:  
                        LCD_ClearScreen();
                        LCD_PutString("Have a nice day.",16);
                        break;
        }
    
    IFS0bits.T1IF = 0; //clear interrupt flag
    
}
int main(void) {
    SYS_Initialize();
    GPIO_init();
    Timer_init();
    start_msg(); 
    while(1){
        
        if(!PORTDbits.RD13){                     //since buttons S3 and S$ are active low
            LCD_ClearScreen();
            LCD_PutString("DO NOT PRESS THE",16);
            LCD_PutString(" RIGHT BUTTON",13);
            T1CONbits.TON = 1;
            while(!PORTDbits.RD13);
            start_msg();
            TMR1=0;
            T1CONbits.TON = 0;
            state = 0;
        }
        if(!PORTDbits.RD6){
            LCD_ClearScreen();
            LCD_PutString("DO NOT PRESS THE",16);
            LCD_PutString(" LEFT BUTTON",12);
            T1CONbits.TON = 1;
            while(!PORTDbits.RD6);//without this while loop the lcd is cleared and written multiple times if the button is pressed
            start_msg();
            TMR1=0;
            T1CONbits.TON = 0;
            state = 0;
        }
        
    
    }
}

