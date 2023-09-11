# Smart Home System 

## Introduction
This smart home project is designed to provide various home automation and monitoring features. It is implemented on an embedded system and includes functionalities such as password-based access control, temperature and light monitoring, and control of appliances like lamps and fans. The project also supports different operation modes, including automatic and Bluetooth control.

## Features
### Password-Based Access Control
- Users can enter a 4-digit password to gain access to the smart home system.
- If the entered password matches the predefined password, the system grants access.
- If the password is incorrect, the system keeps track of the number of failed attempts. After a maximum number of attempts, it locks the system.

### Temperature Monitoring
- The system monitors the temperature using an LM35 sensor.

### Light Monitoring
- The system monitors the light intensity using an LDR (Light Dependent Resistor).
- The intensity is displayed as a percentage.

### Appliance Control
- The system can control two appliances: lamps and fans.
- The lamp and fan are controlled based on predefined thresholds for temperature and light intensity.

### Operation Modes
- Automatic Mode: The system operates in this mode by default.
  - Appliances are controlled automatically based on predefined thresholds.
- Bluetooth Mode: The system can be switched to Bluetooth mode.
  - In Bluetooth mode, the user can control the lamp and fan remotely using a Bluetooth interface.

## How the Project Works
1. **Password Entry**: The user is prompted to enter a 4-digit password using a keypad. Each key press is displayed on an LCD screen as an asterisk (*). Once the correct password is entered, access is granted. Otherwise, the system tracks the number of failed attempts.
2. **Maximum Attempts**: If the user enters an incorrect password multiple times, the system locks and displays a "MAX COUNT" message on the LCD screen. The LEDs also flash to indicate the lock state.


https://github.com/alaawahba13/AVR-Projects/assets/101985923/710cc7a5-cf7c-443a-a842-b4a01a90d499


3. **Operation Modes**: The system has two operation modes:
   - Automatic Mode: In this mode, the system automatically controls the appliances based on predefined thresholds for temperature and light intensity.
     

https://github.com/alaawahba13/AVR-Projects/assets/101985923/dcfaa324-2bac-4f9a-b7a0-7911d209bb57


   - Bluetooth Mode: In Bluetooth mode, the user can control the lamp and fan remotely using a Bluetooth interface. Commands are sent via UART to control the appliances.


https://github.com/alaawahba13/AVR-Projects/assets/101985923/d6b6a79d-8a9b-451d-bb85-c414857a4e55


4. **Fire Alarm**: If the temperature exceeds a certain threshold, the system triggers a fire alarm. The alarm is indicated by sound and a message displayed on the LCD screen.


https://github.com/alaawahba13/AVR-Projects/assets/101985923/2b80d0d2-7304-4267-acfd-434d5d5fac49



## Usage
1. Power on the system and interact with it using the keypad:
   - Enter the correct password using keypad to access the system.
   - Observe temperature and light readings on the LCD screen.
   - Switch between automatic and Bluetooth modes (using the dip switch).
   - Monitor the system for fire alarms (triggered by smoke detection).
  
 ## Hardware 
  [Full Video](https://drive.google.com/file/d/1qaf56CY_-kIVj_D5ZhLVknjAH4-dEX6W/view?usp=drive_link)
            
 ## UML Diagram
    to be implemented
    
## Author
- Author: Alaa Wahba
