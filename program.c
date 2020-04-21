#include <avr/io.h>
#include <util/delay.h>

const int sensorPin = 4;
const int servoPin = 5;
#define servoFrequency 50
#define Fosc 1//mhz
#define TOP (((Fosc*1000000) / (servoFrequency)) -1 ) 
void servoSetAngle(int angle)
{
    int newAngle =1000 +( (angle/180)*1000);
    OCR1A =  TOP-newAngle;
}
int main(void)
{
                                                    //IR sensor set as input in PORTB0
    DDRB&=~(1<<sensorPin);
                                                    //PWM output pin OC1A or PD5
     DDRD|=(1<<servoPin);
                                                    //waveform generation mode: fast pwm AND Set OC1 on compare match
          TCCR1A|=(1<<WGM11)|(1<<COM1A0)|(1<<COM1A1);
          TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS10);
    ICR1=TOP;
           while(1)
                        {
                          if((PINB&(1<<PINB4)))     //masking pinb4 so that if b4 is high means ir sensor detects door opens for 1 second    
                 {
            servoSetAngle(90);
            _delay_ms(1000);
                  }
                        else
                        {
            servoSetAngle(0);
    
                         }
}
