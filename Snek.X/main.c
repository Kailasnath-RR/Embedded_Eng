/* 
 * File:   main.c
 * Author: Intern08
 *
 * Created on July 9, 2026, 2:41 PM
 */
#define FCY 4000000UL 
#include <xc.h>
#include "bsp/lcd.h"
#include <stdlib.h>
#include <libpic30.h>
/*
 * 
 */
#define lcd_size  33

int length = 32;
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
void new_pos_calc(void)
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


void GPIO_init(void){
    TRISDbits.TRISD6 = 1;  //s3 -> left button set to input
    TRISDbits.TRISD13 = 1; //s4 -> right button set to input
    TRISCbits.TRISC9 = 1; //s6 -> up button
    TRISFbits.TRISF7 = 1; // s5-> down button
}
void Timer_init(void){
    T1CONbits.TCS = 0; 
    T1CONbits.TCKPS = 2;
    TMR1 = 0;//<-init time
    PR1 = 30000; //<-count to
    IFS0bits.T1IF = 0; //clear timer interrupt flag
    IEC0bits.T1IE = 1; //enable timer interrupt
    IPC0bits.T1IP = 4; // set timer interrupt priority to 4
    INTCON2bits.GIE = 1; //allow interrupts 
    
    

}

void __attribute__((interrupt,auto_psv))_T1Interrupt(void){

    if(state == PLAYING){
        currentDirection = nextDirection;
        move_snake(currentDirection);
       
        
    }
    IFS0bits.T1IF = 0;
   
}

void shiftPos(void){
    for(int i = length-1; i>0 ;i--){
        Snake[i] = Snake[i-1];
    }

}






void check_button(void){
    
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

void draw_snake(void){
    
    LCD_ClearScreen();
    for(int i = 0 ;i < length; i ++){
        LCD_ShiftCursorTo(Snake[i].x,Snake[i].y);
        if(i == 0){
            LCD_PutChar(1);
        }else{
            LCD_PutChar(2);
        }
    
    }
    
    
}
void draw_apple(void){
    LCD_ShiftCursorTo(Apple.x,Apple.y);
    LCD_PutChar(0);
    
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
        LCD_PutString("   PRESS S4  ",13);
        LCD_PutString("      To Start",14);
}
void won(void){
        LCD_ClearScreen();
        LCD_PutString("    WON",7);
        
}
void game_over(){
        LCD_ClearScreen();
        LCD_PutString("  GAME OVER",11);
        
       
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

void restart(){
    length = 1;
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 0;
    Snake[0].x = 0;
    Snake[0].y = 0;
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
    
}


int main(void) {
    SYS_Initialize();
    GPIO_init();
    Timer_init();
    init_game();
    menu();
    while(PORTDbits.RD13);
    srand(TMR1);
    T1CONbits.TON = 1;
    state = PLAYING;
    new_pos_calc();
    draw_snake();
    draw_apple();
    while(1){
        check_button();
        switch(state){
            
            case MENU:  menu();
                        break;
            
            case WON:
                    won();
                    __delay_ms(1000);
                    state = RESTART;               
                    break;
            case PLAYING : break;      
            case RESTART : 
                restart();
                break;
                        
            case GAME_OVER: game_over();
                            __delay_ms(1000);
                            state = RESTART;
                            break;
        }
        
         
        
    }
}

