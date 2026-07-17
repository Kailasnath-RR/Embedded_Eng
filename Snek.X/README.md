# Snake Game (dsPIC33EP512GM710)

A simple Snake game developed in C for the Microchip Explorer 16/32 Development Board using the dsPIC33EP512GM710 microcontroller and a 16×2 HD44780-compatible LCD.

This project was built during my embedded systems internship to practice interrupt-driven programming, finite state machines, LCD interfacing, and embedded software design without using any game engine or graphics library.

\----------------------------------------------------------

## Hardware

* dsPIC33EP512GM710
* Microchip Explorer 16/32 Development Board
* 16×2 HD44780 Character LCD
* Push Buttons (S3, S4, S5, S6)
* UART

\----------------------------------------------------------

## Features

* Interrupt-driven snake movement using Timer1
* Four-direction movement using hardware push buttons
* also applied UART based command movements
* Random apple generation
* Apple collision detection
* Snake growth
* Screen wrap-around between LCD rows
* Win condition when the display is completely filled
* Restart after game completion
* Custom HD44780 CGRAM characters

  * Apple sprite
  * Snake head
  * Snake body

\----------------------------------------------------------

## Software Concepts Used

* GPIO
* Timer1
* UART
* Interrupt Service Routines (ISR)
* Finite State Machine (FSM)
* Structures
* Enumerations
* Arrays
* Random number generation (`rand()`)
* LCD command interface
* HD44780 CGRAM programming
* State-based application design

\----------------------------------------------------------



## Controls

|Button|Function|
|-|-|
|S3|Move Left|
|S4|Move Right / Start / Restart|
|S5|Move Down|
|S6|Move Up|





\--------------------------------------------------------------------or-------------------------------------------------------------------





|Button|Function|
|-|-|
|'a'|Move Left|
|'d'|Move Right|
|'s'|Move Down|
|'w'|Move Up|
|'r'|start|



\----------------------------------------------------------

## Challenges Faced

While building this project I encountered and fixed several embedded-specific issues including:

* Snake body synchronization during growth
* Interrupt timing issues
* Direction reversal handling
* LCD flickering caused by full-screen redraws
* Random apple generation
* Preventing apples from spawning inside the snake
* Restarting the game by correctly resetting application state
* Creating and displaying custom CGRAM characters

\----------------------------------------------------------

## Future Improvements

* Self-collision detection
* Adjustable game speed
* Score display
* Direction-specific snake head sprites
* Better pseudo-random number seeding
* Sound effects using PWM
* Pause functionality

\----------------------------------------------------------

## What I Learned

This project helped reinforce concepts such as:

* Interrupt-driven embedded programming
* Designing software using finite state machines
* implementing UART based command parsing and movement
* Managing shared state between ISRs and the main loop
* Working directly with hardware peripherals
* Programming the HD44780 LCD controller
* Creating custom LCD characters using CGRAM
* Structuring a medium-sized embedded C project

\----------------------------------------------------------

## Author

**Kailasnath R.**

Embedded Systems Fun Project

