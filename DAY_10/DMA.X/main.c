/* 
 * File:   main.c
 * Author: Intern08
 *
 * Created on July 14, 2026, 12:37 PM
 */
#include <xc.h>
#include "bsp/adc.h"


/*
 * 
 */

volatile uint16_t samples[16]
    __attribute__((space(xmemory), aligned(32)));

void Timer_init(void){
    T3CON = 0;
    T3CONbits.TCS = 0; 
    T3CONbits.TCKPS = 2; //1:64 prescaler
    
    TMR3 = 0;//<-init time
    PR3 = 30000; //<-count to
    
    IFS0bits.T3IF = 0; //timer 3 interrupt flag clear
    IEC0bits.T3IE = 0; //timer 3 interrupt enable
    T3CONbits.TON = 1; //switch on timer   

}


void InitDMA0(void)
{
    DMA0CONbits.CHEN = 0; //disable channel before changing configs
    DMA0CONbits.SIZE = 0; //transfer bit size (0 => 16 bits)
    DMA0CONbits.DIR = 0; //sets dma direction from peripheral to ram
    
    DMA0CONbits.AMODE = 0; //register indirect with post increment
    DMA0CONbits.MODE = 0; //one-shot mode
    
    DMA0PAD = (volatile unsigned int)&ADC1BUF0; //source location for dma
    
    DMA0STAL = __builtin_dmaoffset(samples);
    DMA0STAH = 0;
    DMA0CNT = 15; //16 count
    
    DMA0REQ = 13;
    IFS0bits.DMA0IF = 0; //clear dma interrupt flag
    IEC0bits.DMA0IE = 1; //enable dma interrupts
    
    DMA0CONbits.CHEN = 1; //enable dma 
}



void __attribute__((interrupt,no_auto_psv)) _DMA0Interrupt(void)
{
    IFS0bits.DMA0IF = 0;
}


int main(int argc, char** argv) {

    SYS_Initialize();
    InitDMA0();
    Timer_init();
    
    while(1){
    
    }
    
}

