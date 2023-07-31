#ifndef _UART_H_
#define _UART_H_

#ifndef F_CPU
    #pragma message ( "WARNING: MCU Frequency (F_CPU) is unset -> 16 MHz" )
    #define F_CPU 16000000UL
#endif

#ifndef BAUD
    #pragma message ( "WARNING: Baud (BAUD) is unset -> 9600" )
    #define BAUD 9600
#endif

#include <stdint.h>

void uart_init(unsigned long __baudrate);
void uart_writeByte(uint8_t __byte);
uint8_t uart_readByte();

//void uart_writeString(uint8_t* __data);

#endif