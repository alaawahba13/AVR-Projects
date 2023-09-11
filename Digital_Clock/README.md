# Digital Clock Project

## Overview

This Digital Clock project is designed for the ATmega32 microcontroller and offers a range of features to provide timekeeping and alarm functionality. It is an excellent platform for learning about microcontroller programming and interfacing with peripherals like LCD displays, buttons, and LEDs.

### Features

- Display current time and date on an LCD.
- Set alarms with customizable time.
- Display the currently set alarm time.
- Snooze functionality to temporarily silence the alarm.
- LED indicator turns on when an alarm is set.
- Ability to disable the alarm.

## Hardware Requirements

- ATmega32 microcontroller (or compatible).
- 20x4 LCD display.
- RTC (Real-Time Clock) module for accurate timekeeping.
- Keypad for user input (e.g., Set, Snooze, Disable).
- LEDs for status indication (e.g., Alarm set indicator).
- Buzzer for alarm sound.
- Power source (battery or external power supply).

## Software Requirements

- AVR-GCC and AVR-GCC libraries for programming the ATmega32.
- I2C and RTC libraries for interfacing with the RTC module.
- LCD library for controlling the LCD display.


## Usage



 ****************************************************************************************************
            ____________________________________
           |         |         |         |      |
           |   decH  | decMin  | decSec  | 3    |--------- R0
           |_________|_________|_________|______|
           |         |         |         |      |
		       |   incH  | incMin  | incSec  | SET  |--------- R1
           |_________|_________|_________|______|
           |         |         |         |      |
           |   Start |         | A       | B    |--------- R2
		       |_________|_________|_________|______|
		       |         |         |         |      |
		       | Disable |   View  |  Stop   |Snooze|--------- R3
           |_________|_________|_________|______|
             |            |          |        |
             |            |          |        |____________ C3
             |            |          |
             |            |          |_________________ C2
             |            |
             |            |______________________ C1
             |
             |___________________________ C0




### Setting an Alarm

1. Press the "Set" button to enter the alarm-setting mode.
2. Navigate through the alarm hours, minutes, and seconds using the buttons.
3. Set the desired alarm time and date.
4. Press "Set" again to confirm the alarm settings.

### Snooze Functionality

When the alarm sounds, press the "Snooze" button to temporarily silence the alarm. The alarm will sound again after a predefined snooze duration.

### Disabling the Alarm

Press the "Disable" button to disable the alarm entirely. The LED indicator will turn off, and the alarm will not sound.

### Viewinng the Alarm

Press the "view" button to view the alarm set.


### Hardware Test


##### Setting & Viewing an alarm 

https://github.com/alaawahba13/AVR-Projects/assets/101985923/64f78208-d036-4e41-a29a-30bcb2646830


#### Alarm is set & snoozing it

https://github.com/alaawahba13/AVR-Projects/assets/101985923/99a44ac6-72b5-42a2-94e0-22fc990e774a


#### Stoping alarm

https://github.com/alaawahba13/AVR-Projects/assets/101985923/97183c44-c6cd-422a-b14c-348982e01b66


