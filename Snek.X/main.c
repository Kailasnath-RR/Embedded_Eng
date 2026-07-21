/* 
 * File:   main.c
 * Author: Intern08
 *
 * Created on July 9, 2026, 2:41 PM
 */ 
#include <xc.h>
#include "bsp/lcd.h"
#include <stdlib.h>

/*
 * 
 */
#define lcd_size  32  //not used anywhere yet
void update_state(char controls);
int length = 1; // keeps track of snake length
int menu_drawn_flag = 0; // flag to check if the menu has been drawn once

typedef struct{
    int x;
    int y;

}Position;

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,


};

enum State {
    MENU,
    PLAYING,
    GAME_OVER,
    WON,
    RESTART


};

enum State state = MENU;


void move_snake(enum Direction direction);
void move_snake_left(void);
void move_snake_right(void);
void draw_snake(void);



volatile enum Direction nextDirection = RIGHT;
volatile enum Direction currentDirection = RIGHT;
Position Snake[32] = {0,0};


Position Apple;


const unsigned char apple[8] = {
  0b00100,
  0b01110,
  0b10101,
  0b10101,
  0b10001,
  0b10001,
  0b01110,
  0b00000,    
};
const unsigned char snakeHead[8] =
{
    0b00000,
    0b01110,
    0b11011,
    0b11111,
    0b10001,
    0b01110,
    0b00000,
    0b00000
};
const unsigned char snakeBody[8] =
{
    0b00000,
    0b00000,
    0b10101,
    0b01010,
    0b10101,
    0b01010,
    0b10101,
    0b00000
};

void init_game(){
    LCD_createChar(0x40,apple);
    LCD_createChar(0x48,snakeHead);
    LCD_createChar(0x50,snakeBody);
 
    

    
}
void new_pos_calc(void) //calculates apple position on the lcd and also checks for collision with snake body 
{   
    int collision;
    do{
        collision = 0;
        Apple.x = rand() % 16;
        Apple.y = rand() % 2;
        for(int i = 0 ; i < length ; i++){
            if(Apple.x == Snake[i].x && Apple.y == Snake[i].y){
                collision =1;
                break;
            }
        }
    }while(collision);
}


void GPIO_Init(void){
    TRISDbits.TRISD6 = 1;  //s3 -> left button set to input
    TRISDbits.TRISD13 = 1; //s4 -> right button set to input
    TRISCbits.TRISC9 = 1; //s6 -> up button
    TRISFbits.TRISF7 = 1; // s5-> down button
}
void Timer_Init(void){
    T1CONbits.TCS = 0; 
    T1CONbits.TCKPS = 2;
    TMR1 = 0;//<-init time
    PR1 = 30000; //<-count to
    IFS0bits.T1IF = 0; //clear timer interrupt flag
    IEC0bits.T1IE = 1; //enable timer interrupt
    IPC0bits.T1IP = 4; // set timer interrupt priority to 4
    INTCON2bits.GIE = 1; //allow interrupts 
    
    

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
void UART_write_char(char c){

    while(U1STAbits.UTXBF == 1);
    
    U1TXREG = c;

}

void UART_Write_string(char *st){

    while(*st !='\0'){
        UART_write_char(*st);
        st++;
    }

}


void __attribute__((interrupt,auto_psv))_T1Interrupt(void){

    if(state == PLAYING){
        currentDirection = nextDirection;
        move_snake(currentDirection);
       
        
    }
    IFS0bits.T1IF = 0;
   
}
void __attribute__((interrupt,no_auto_psv)) _U1RXInterrupt(void){
    char controls = U1RXREG;
    update_state(controls);
    IFS0bits.U1RXIF = 0;
}

void shiftPos(void){
    for(int i = length-1; i>0 ;i--){
        Snake[i] = Snake[i-1];
    }

}






void check_button(void){   //can use this function to implement buttons instead of uart based commands
    
    if(state != WON){
       
        if(!PORTDbits.RD13){
            if(currentDirection != LEFT){
                nextDirection =RIGHT ;
            }
            while(!PORTDbits.RD13);
        }
        if(!PORTDbits.RD6){
            if( currentDirection!= RIGHT){
                nextDirection = LEFT;
            }
                while(!PORTDbits.RD6);
        }
        if(!PORTCbits.RC9){
            if(currentDirection!= DOWN){
                nextDirection = UP;
            }
            while(!PORTCbits.RC9);
        }
        if(!PORTFbits.RF7){
            if(currentDirection != UP){
                nextDirection = DOWN;
            }
            while(!PORTFbits.RF7);
        }
    }

}

void check_direction_conflict(char controls){
    
   
    if(state != WON){
        if(controls == 'd'){
            if(currentDirection != LEFT) nextDirection = RIGHT;
        }
        else if(controls == 'a'){
            if(currentDirection != RIGHT) nextDirection = LEFT;
        }
        else if(controls == 'w'){
            if(currentDirection != DOWN) nextDirection = UP;
        }
        else if(controls == 's'){
            if(currentDirection != UP) nextDirection = DOWN;
        }
    }
}





void draw_snake(void){
    
    LCD_ClearScreen();
    for(int i = 0 ;i < length; i ++){
        LCD_ShiftCursorTo(Snake[i].x,Snake[i].y);
        if(i == 0){
            LCD_PutChar(1);   //1 <-position 1 in CGRAM corresponds to bitmap for SNAKE head
        }else{
            LCD_PutChar(2);   //2 <-position 2 in CGRAM corresponds to bitmap for SNAKE body
        }
    
    }
    
    
}
void draw_apple(void){
    LCD_ShiftCursorTo(Apple.x,Apple.y);
    LCD_PutChar(0); //0 <-position 0 in CGRAM corresponds to bitmap for apple
    
}
void apple_consumed_check(void){
    if((Snake[0].x == Apple.x) &&(Snake[0].y == Apple.y)){
        if(length < 32){
            Snake[length] = Snake[length-1];
            length++;
        }
        new_pos_calc();
        check_win();
    }

}



void menu(void){
    LCD_ClearScreen();
    LCD_ShiftCursorTo(0, 0);
    LCD_PutString("   S4 OR 'R'    ", 16);
    LCD_ShiftCursorTo(0, 1);
    LCD_PutString("    TO START    ", 16);
}


void won(void){
        LCD_ClearScreen();
        LCD_PutString("    WON",7);
        
}
void game_over(){   //not used anywhere
        LCD_ClearScreen();
        LCD_PutString("  GAME OVER",11);
        
       
}
void check_win(void)
{
    if(length == 32)
    {
        T1CONbits.TON = 0;
        state = WON;

        LCD_ClearScreen();
        LCD_PutString("    WON", 7);
        
    }
}

void move_snake(enum Direction currentDirection){
    
    switch(currentDirection){
        case LEFT: 
            move_snake_left();
            break;
        case RIGHT: 
            move_snake_right();
            break;
        case UP: 
            move_snake_up();
            break;
        case DOWN:
            move_snake_down();
            break;
    }
    if(state == WON)
        return;
    draw_snake();
    draw_apple();
    
    
}
void move_snake_right(void){
    
    shiftPos();
    Snake[0].x++;
            if(Snake[0].x > 15 ){
                if(Snake[0].y==0){
                    Snake[0].y = 1;
                }else if(Snake[0].y == 1){
                    Snake[0].y = 0;
                    
                }
                 Snake[0].x = 0;
            }
    apple_consumed_check();
}

void move_snake_left(void){
        shiftPos();
        Snake[0].x--;
            if(Snake[0].x < 0 ){
                if(Snake[0].y==0){
                    Snake[0].y = 1;
                }else if(Snake[0].y == 1){
                    Snake[0].y = 0;
                    
                }
                 Snake[0].x = 15;
            }
        apple_consumed_check();
}

void move_snake_up(void){
    shiftPos();
    if(Snake[0].y == 0){
        //nothing
    }else{
        Snake[0].y = 0;
    }
    apple_consumed_check();
}
void move_snake_down(void){
    shiftPos();
    if(Snake[0].y == 1){
        //nothing
    }else{
        Snake[0].y = 1;
    }
    apple_consumed_check();
}

//snake movement has been implemented in such a way that it wraps around the lcd back to start incase it goes out of bounds

void restart(){
    length = 1;
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 0;
    Snake[0].x = 0;
    Snake[0].y = 0;
    menu_drawn_flag = 0;
    state = MENU;
    for(int i = 1; i < 32; i++)
    {
        Snake[i].x = 0;
        Snake[i].y = 0;
    }      
    currentDirection = RIGHT;
    nextDirection = RIGHT;
    LCD_ClearScreen();
    LCD_PutString("   PRESS S4  ",13);
    LCD_PutString("      To Restart",16);
    while(PORTDbits.RD13);
    TMR1 = 0;
    T1CONbits.TON = 1;
    state = PLAYING;
    new_pos_calc();
    draw_snake();
    draw_apple();
    
} //holds the lcd in restart state unless the S4 button is pressed


void update_state(char controls){
    if(controls== ' ' || controls == '\r' || controls == '\n' || controls == '\0') {  //not letting these guys mess up my program
        IFS0bits.U1RXIF = 0;
        return;
    }
    
    if(state == MENU && controls == 'r'){
        
        state = PLAYING;
        T1CONbits.TON = 1;
        new_pos_calc();
        draw_snake();
        draw_apple();   
    }
    
    else if(state == PLAYING){
        if(controls == 'w' ||  controls == 'a' ||controls == 's' || controls == 'd' ){
            
            check_direction_conflict(controls);
        }
        else {
            UART_Write_string("Invalid movement\r\n");
        }
    
    }

}



int main(void) {
    SYS_Initialize();
    GPIO_Init();
    UART_Init();
    Timer_Init();
    init_game();
    srand(TMR1);
   
    while(1){
        // check_button(); 
        
        switch(state){
            
            case MENU:  
                    if(!menu_drawn_flag) {
                        menu();
                        menu_drawn_flag = 1; 
                    }
                    break;
            
            case WON:
                    won();
                    for(int i = 0; i<5000;i++);
                    state = RESTART;               
                    break;
            
            case PLAYING : break;      
            
            case RESTART : 
                restart();
                break;
                        
            case GAME_OVER: game_over();   // hasnt been implemented yet (probably never will))
                            for(int i = 0; i<5000;i++);
                            state = RESTART;
                            break;
        }
        
         
        
    }
}

