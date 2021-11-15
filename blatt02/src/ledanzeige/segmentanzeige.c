/**
 * @file segmentanzeige.c
 * @author Finn Bechinka (finn.bechinka@fh-bielefeld.de)
 * @author Michel-Andre Witt (michel-andre.witt@fh-bielefeld.de)
 * @author Dennis Edler (dennis.edler@fh-bielefeld.de)
 * @brief TODO
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "ledanzeige/TM1637.h"
#include "ledanzeige/TM1637_intern.h"
#include "ledanzeige/segmentanzeige.h" 
#include <wiringPi.h>

#define one_second 1000000

/**
 * @brief Überprüft ob bei einem byte bestimmte bits gesetzt sind
 * 
 * @param x der byte welcher überprüft wird
 * @param mask die maske gegen welche gerüft wird
 * @return int 0 wenn bit(s) nicht übereinstimmen, 1 wenn bit(s) übereinstimmen
 */
int check_for_bits(byte x, byte mask)
{
    return (x & mask) == mask ? 1 : 0;
}

/**
 * @brief Überträgt einen byte an die Segmentanzeige
 * 
 * @param wr_data der byte welcher bit-weise übertragen wird
 */
void TM1637_write_byte(byte wr_data)
{
    int i;
    /*printf("byte, %d: \n",wr_data);*/
    for(i = 0; i < 8; i++)
    {
        digitalWrite(PIN_CLOCK, LOW);
        delayMicroseconds(DELAY_TIMER);
        /*printf("%d %d %d\n",wr_data, (byte) pow(2.0,i), check_for_bits(wr_data, (byte) pow(2.0, i)));*/
        if(check_for_bits(wr_data, (byte) pow(2.0, i)))
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
    /*printf("write byte\n");*/
}

/**
 * @brief Demonstriert LED Anzeige
 * 
 * Wenns denn funktioniert...
 * 
 */
void led_demo(void)
{
    delayMicroseconds(one_second);
    TM1637_display_number(69.0);
    delayMicroseconds(one_second);
    TM1637_display_number(133.7);
    delayMicroseconds(one_second);
    TM1637_display_number(081.5);
    delayMicroseconds(one_second);
    TM1637_display_number(187.0);
    delayMicroseconds(one_second);
    TM1637_display_number(000.0);
}

int main()
{
    printf("start\n");
    TM1637_setup();
    delayMicroseconds(one_second);
    TM1637_brightness(0);
    delayMicroseconds(one_second);
    led_demo();
    printf("ende\n");
    return EXIT_SUCCESS;
}