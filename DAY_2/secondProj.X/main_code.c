/* 
 * File:   main_code.c
 * Author: Intern08
 *
 * Created on July 6, 2026, 11:37 AM
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
    ANSELFbits.ANSF4 = 0;
    ANSELFbits.ANSF5 = 0;
    TRISFbits.TRISF4 = 0; //led 7
    TRISFbits.TRISF5 = 0; //led 8
    TRISFbits.TRISF6 = 0; //led 9
    int state = 0;
    volatile long i;
    while(1){
        switch(state){
                
            case 0:  state = 1; 
                      break;
            
            case 1:  
                LATFbits.LATF4 = 1;
                     state = 2;
                     for(i = 0 ; i < 500000;i++ );
                     LATFbits.LATF4 = 0;
                     break;
            
            case 2: 
                
                    LATFbits.LATF5 = 1;
                    state = 3;
                    for(i = 0 ; i < 500000;i++ );
                    LATFbits.LATF5 = 0;
                    break;
            case 3:
                
                LATFbits.LATF6 = 1;
                state = 4;
                for(i = 0 ; i < 500000;i++ );
                LATFbits.LATF6 = 0;
                break;
            case 4: LATFbits.LATF5 = 1;
                    state = 1;
                    for(i = 0 ; i < 500000;i++ );
                    LATFbits.LATF5 = 0;
                    break;
            
       }
       
        
    }
}

