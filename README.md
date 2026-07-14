# Embedded Lab

## Hardware

* Board : Explorer 16/32
* MCU : dsPIC33EP512GM710

## Day 1:

* Learnt navigating the mplab ide and flashing firmware onto the Explorer16 dev kit
* Learnt Clocks and Configs



## Day 2:

* Learnt TRIS , PORT AND LAT
* Learnt ANSEL and requiring ANSEL = 0 for digital input config
* Learnt level detection and edge detection
* Detecting button pushes and toggling LEDs on press
* Learnt to blink the led(firstProj.x)
* Learnt delays (firstproj.X)
* Learnt FSMs (secondProj.x) -> \[made a LED blink pattern of 7->8->9->8->7->repeat]
* Learnt timers(T1COn/TMR1/PR1) and timer interrupt flag(IFS0bits.T1IF)\[thirdProj.x]
* Learnt how to use Timer interrupts to avoid cpu polling\[fourthProj.x]
* Applied interrupts and FSMs for 3 LEDs while using software delay for one LEDs \[fifthProj.x = fourthProj+secondProj]

#### 

#### **DAY 3:**

* Learnt UART architecture (TX, RX, Baud Rate Generator)
* Manually configured UART using U1MODE, U1STA and U1BRG (without MCC)
* Learnt the relationship between FCY, BRG and baud rate generation
* Debugged UART baud rate issues caused by incorrect clock assumptions
* Successfully transmitted data over UART (garbled output due to baud rate mismatch)
* Learnt the HD44780 LCD communication protocol (Commands, Data, RS, RW, Enable)
* Implemented a manual GPIO-based LCD driver
* Configured LCD control and data pins using TRIS, LAT and ANSEL
* Failed to get the manual GPIO LCD driver working, switched to the official PMP-based implementation

#### **DAY 4:**

* Learnt the difference between GPIO-driven LCD interface and Parallel Master Port (PMP) interface
* Learnt PMCON, PMMODE, PMAEN, PMDIN1 and PMADDR registers (PMP config in datasheet)
* Learnt why the Explorer 16 LCD uses PMP instead of manual GPIO control
* Implemented Microchip's official LCD driver and verified LCD functionality
* Combined GPIO, LCD, Timer1 and interrupts into a single application (sixthProj.X)
* Explored the limitations of performing peripheral operations (LCD updates) inside an ISR and understood why non-blocking main loops are preferred
* Built an interactive LCD application with timed warning messages using Timer1 interrupts (sixthProj.X)
* Learnt ADC fundamentals and ADC configuration
* Configured the ADC using Microchip's official driver
* Read analog voltage from the onboard potentiometer (P20\_POT)
* Converted the 10-bit ADC value (0–1023) into voltage (0–3.3V)
* Displayed the ADC reading and calculated voltage on the LCD \[seventhProj.X]

#### 

#### DAY 5,6 ,7 \& 8:

* spent day 5 studying SPI \& building snake game(built movement and loopback logic alongside game state implementation) \[snek.x]
* spent day 6 doing pwm configuration and oscilloscope measurement using mcc and further worked on my game implementation(built apple spawn logic, apple collision logic)\[eightProj.x,snek.X]
* implemented CGRAM characters and gave final touches to the game
* Also did a bit more on Clock config (used mcc) and how to out Fcy onto REFCLOCK pin \[ninthProj.x]
* Also learnt more about PPS and its benefits



#### DAY 9:

* used adc to measure potentiometer and use that to change the duty cycles of PWM (AdcToPwm.x)
* learnt DMA theory 

