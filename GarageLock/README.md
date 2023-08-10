# Garage lock project 

## Features

- Password-based authentication for secure access to the garage.
- Motor rotation control with configurable direction (clockwise or anticlockwise).
- Automatic stop after a specified duration (one second).
- Limited number of iterations for incorrect password attempts.
- Red LED alarm activation for incorrect password attempts.

## Components Used

- Atmega32 microcontroller.
- LCD (16x2) to display system messages and prompts.
- Keypad to input password and motor direction.
- DC motor connected to the garage lock mechanism.
- Red LED for alarm indication.

## Software and Drivers

The project utilizes the following software and drivers:

- Atmel Studio or any other compatible IDE for programming the Atmega32 microcontroller.
- Atmega32 DIO driver for controlling digital input/output operations.
- Atmega32 LCD driver for interfacing with the LCD display.
- Atmega32 Keypad driver for capturing input from the keypad.

## Project Structure

The project consists of the following main files:

1. `main.c`: The main source file containing the project logic.
1. `dio.c` and `dio.h`: DIO driver implementation and header files.
1. `lcd.c` and `lcd.h`: LCD driver implementation and header files.
1. `keypad.c` and `keypad.h`: Keypad driver implementation and header files.

## Customization

The project can be customized according to specific requirements:

- Password: Modify the password in the code by changing the value of the password variable.
- Motor Control: Adjust the motor control logic in the code to meet the specific requirements of the garage lock mechanism.
- Alarm Behavior: Customize the alarm behavior, such as the number of incorrect attempts allowed, LED activation duration, etc.

## Simulation




https://github.com/alaawahba13/AVR-Projects/assets/101985923/9e273121-a0ad-4c4a-8027-5a225a5d516b





## Acknowledgments

This project was developed by 
- [@Alaa Wahba](https://github.com/alaawahba13)
  Special thanks to  [@Mohamed Khodary](https://github.com/moekhodry11) for providing the simulation file.


