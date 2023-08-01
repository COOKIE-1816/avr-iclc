#ifndef _74HC595_H_
#define _74HC595_H_

#include <avr/io.h>

typedef struct ic_74HC595_t {
    // master reset
    int mr;

    // Shift register clock
    int shcp;

    // Storage register clock
    int stpc;

    // Output enable
    int oe;

    // Serial data input
    int ds;

    // Output serial data
    int q7s;
} ic_74HC595_t;

typedef uint8_t* ic_74HC595_serialData_t;

/*
    Moves
*/
static void ic_74HC595_writeByte(uint8_t __value);
static void ic_74HC595_setSerial(ic_74HC595_serialData_t __serialData);

static ic_74HC595_serialData_t ic_74HC595_readSerial();
static uint8_t ic_74HC595_readByte(uint8_t __byte);


#endif