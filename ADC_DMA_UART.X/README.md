# dsPIC33E Bare-Metal ADC-to-UART Telemetry Pipeline

A high-performance, non-blocking telemetry system built from the ground up on the Microchip dsPIC33EP512GM710 (Explorer 16/32 Development Board). This project bypasses high-level software code configurators (like MCC) to maximize silicon efficiency, implementing a synchronized hardware pipeline for real-time serial output and digital visual metrics.

## 

## System Architecture

The project features an autonomous background data acquisition pipeline synchronized perfectly to a timed rhythm:

* **Timer3 (The Metronome):** Ticks in the background at a precise period using a 1:64 prescaler, serving as the automated trigger clock source.
* **10-Bit ADC (The Bridge):** Sparked directly by the Timer3 event, it captures the analog voltage from the physical potentiometer dial (Channel 20) and converts it to a digital range (`0x0000` to `0x03FF`).
* **DMA Channel 0 (The Delivery Driver):** Operates via Register Indirect Post-Increment mode. The instant the ADC signals a completed conversion, the DMA bypasses the CPU entirely to deposit the 10-bit value into a 32-byte memory-aligned RAM array (`samples[16]`).
* **The Grand Finale Interrupt:** Fires exclusively when all 16 slots are populated, raising a data-ready software flag (`Data_Ready_flag = 1`) and passing control to the main loop to process telemetry data and update the physical LED VU meter pins on Ports F and G.

## 

### Firmware State Machine \& Command Set

The system boots up into a secure, silent `LOCKED` mode (`lock_state = 0`, `machine_state = 0`). Terminal telemetry text is suppressed until the correct sequential key conditions are satisfied.

#### 

#### 1\. Sequential Security Authorization (Password Engine)

To unlock terminal output, the user must input the exact multi-byte sequence consecutively:
$$\\text{Input Key Sequence: } \\text{'A'} \\rightarrow \\text{'B'} \\rightarrow \\text{'C'}$$



* Any unexpected character inputs or formatting noise immediately clear the step index, resetting the state machine back to zero.

#### 

#### 2\. Operational Command Set (Post-Unlock)

Once unlocked (`lock_state = 3`), the firmware accepts the following runtime instructions:

* **`p` / `P` (Pause):** Freezes the scrolling terminal text stream while keeping the background data array actively polling.
* **`s` / `S` (Start/Resume):** Resumes active telemetry data streaming to the terminal window.
* **`+` (Speed Increase):** Overwrites the hardware `PR3` timer register down by 2000 ticks, forcing the clock to overflow faster and increasing the telemetry sample frequency.
* **`-` (Speed Decrease):** Scales the hardware `PR3` timer register up by 2000 ticks, expanding the period cycle and decreasing the data stream rate.
* **`L` (Lock System):** A global hotkey override that instantly wipes security authorizations, halts data output, and forces the device back into secure lockdown mode.

## 

## Physical Hardware Interface

### 

* ##### Peripherals / Hardware Indicator

|Peripheral|Hardware Pin Mapped|Functional Mode|
|-|-|-|
|Potentiometer Dial|AN12 / CH0SA = 20|Analog Input|
|UART1 TX Line|RB4 (RP36)|Digital Peripheral Output|
|UART1 RX Line|RA8 (RPI24)|Digital Peripheral Input|
|LED Bar Graph Indicators|Port F (RF4-RF7) \& Port G (RG2, RG3, RG10, RG11)|Digital Push-Pull Outputs|

### 

* ##### Hardware Register Blueprint



Timer3: T3CON = 0; T3CONbits.TCKPS = 2 ; Prescaler 1:64; PR3 = 30000;
ADC1: AD1CON1bits.SSRC = 2; AD1CON1bits.ASAM = 1; AD1CHS0bits.CH0SA = 20;
DMA0: DMA0CON in continuous mode; DMA0PAD points to \\\&ADC1BUF0; DMA0REQ = 13; DMA0CNT = 15;
UART1: U1MODE with BRGH=1; U1BRG = 95;



## Key Takeaways \& Engineering Triumphs



* **CPU Offloading:** Leveraged hardware DMA buffers to gather, store, and increment array indexes seamlessly in the background without stealing clock cycles from standard main loop executions.
* **Hysteresis \& Latch Control:** Implemented full structural logic boundaries within the LED driving blocks to ensure pins switch down dynamically when input levels decline, avoiding sticky LED runtime states.
* **Buffer Security:** Handled C string boundaries by explicitly managing workspace bounds (`char buffer[30]`) to protect neighboring operational pointers from data overflow events.

