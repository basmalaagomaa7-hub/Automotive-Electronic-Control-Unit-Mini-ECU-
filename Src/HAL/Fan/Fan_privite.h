#ifndef FAN_PRIVATE_H
#define FAN_PRIVATE_H

typedef enum
{
    FAN_STOP ,
    FAN_LOW_SPEED,
    FAN_MEDIUM_SPEED,
    FAN_HIGH_SPEED

}Fan_Speed_t;

// OC0 pin 

#define FAN_PWM_PIN   DIO_PIN3
#define FAN_PWM_PORT  DIO_PORTB

#endif