# AVR-Servo-motor
An AVR code to control the servo motor .

# Based on the following condition.
- The door is connected with the shaft of the servo motor 
- IR sensor is attached to the door
- If the object is detected through IR sensor then door will open 90 degree,
- Otherwise door will remain closed i.e, 0 degree. 

# Servomotor
- A servomotor is a linear actuator or rotary actuator that allows for precise control of linear or angular position, acceleration, and velocity.
- It consists of a motor coupled to a sensor for position feedback. 
- It also requires a relatively sophisticated controller, often a dedicated module designed specifically for use with servomotors.
- A servo motor (or servo motor) is a simple electric motor, controlled with the help of servomechanism. 
- If the motor as a controlled device, associated with servomechanism is a DC motor, then it is commonly known as a DC Servo Motor.
- If AC operates the controlled motor, it is known as an AC Servo Motor.

# IR Sensor
- An infrared (IR) sensor is an electronic device that measures and detects infrared radiation in its surrounding environment.  - Infrared radiation was accidentally discovered by an astronomer named William Herchel in 1800. 
- While measuring the temperature of each color of light (separated by a prism), he noticed that the temperature just beyond the red light was highest.
- IR is invisible to the human eye, as its wavelength is longer than that of visible light (though it is still on the same electromagnetic spectrum).
- Anything that emits heat (everything that has a temperature above around five degrees Kelvin) gives off infrared radiation.

# Calculations and Settings
Consider a digital output IR sensor connected to PORTB pin0For SG90 servo motor as per datasheet :

                                 ^ 0° = 1.5ms pulse
                                 |
                                 |
                                 |
                                 |
     +90°= 2ms pulse <----------[ ]----------> -90° = 1ms pulse


- Consider an AVR microcontroller Atmega32 with fuse bits set to internal RC Oscillator mode.> Frequency of the oscillator (Fosc) is 1Mhz.    
- Servo Frequency=50Hz means each cycle is (T= 1/50 = 20ms) long.
- And each cycle for the internal oscillator is (T=1/10^6 = 1us) long.
- Hence we can relate that the oscillator undergoes many cycles when one cycle in servo.
- How many oscillator cycles per 1 cycle of servo = Fosc/Fservo = 10^6 / 50 = 20000.
- Since counting starts from 0 to 20000-1 = 19999
- TOP value of count for 50 Hz cycle = 19999
- So, ICR1=19999
AND,
- 20ms or 50 Hz == 19999
- 1ms or -90° == 19999/20 ~= 1000 
- 1.5ms or 0° == 1000 x 1.5 ~= 1500
- 2ms or +90° == 1000x2 ~= 2000
- we need to make the pulse on for 2ms and off for 18 ms for +90°
- WAVEFORM GENERATION MODE: FAST
- PWMPRESCALAR : NO PRESCALAR (Since the values for cycles are below 65535 and can be loaded into 16-bit OCR1A Register



