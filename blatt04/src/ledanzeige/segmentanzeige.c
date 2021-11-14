/** @file segmentanzeige.c */
#include <C:\Users\finn-\Documents\code\sp\blatt02\include\ledanzeige\segmentanzeige.h> /* IDK MAN THIS THIS DOESNT WORK WITH RELATIVE PATH FOR SOME FUCKING REASON FUCK ME*/ 
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ledanzeige/TM1637_intern.h>
#include <ledanzeige/wiringPi.h>

/**
 * Überprüft of bestimmte Bits gesetzt sind.
 * 
 * TODO
 */
int check_for_bits(byte x, byte mask)
{
    return (x & mask) == mask ? 1 : 0;
}

/**
 * Überträgt einen Byte an die Segmentanzeige.
 * 
 * TODO
 */
void TM1637_write_byte(byte wr_data)
{
    int i;
    for(i = 0; i < 8; i++)
    {
        digitalWrite(PIN_CLOCK, LOW);
        delayMicroseconds(DELAY_TIMER);
        if(check_for_bits(wr_data, pow(2, i)))
        {
            digitalWrite(PIN_DATA, HIGH);
            delayMicroseconds(DELAY_TIMER);
        }
        else
        {
            digitalWrite(PIN_DATA, LOW);
            delayMicroseconds(DELAY_TIMER);
        }
        digitalWrite(PIN_CLOCK, HIGH);
        delayMicroseconds(DELAY_TIMER);
    }
    TM1637_ack();
}

int main()
{
    
    return EXIT_SUCCESS;
}