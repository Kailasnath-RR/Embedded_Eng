    /* 
     * File:   main.c
     * Author: Intern08
     *
     * Created on 8 July, 2026, 1:50 PM
     */

    #include <xc.h>
    #include <stdint.h>
    #include <stdio.h>    
    #include "bsp/adc.h"
    #include "bsp/lcd.h"
    
    /*
     * 
     */

    uint16_t values = 0;
    char buffer[20] = {0};
    float voltage = 0;
    int main(void) {
        SYS_Initialize();
        ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT);
        ADC_ChannelEnable(ADC_CHANNEL_12);
        while(1){
             values = ADC_Read10bit(ADC_CHANNEL_12);
             voltage = (values*3.3f)/1023.0f; //formula to convert the 10bit value to volatage value in float
             sprintf(buffer,"Voltage: %.1f V",voltage); //preserves the voltage value as character to display onto lcd
             LCD_ClearScreen();
             LCD_PutString(buffer,14);

        }

    }

