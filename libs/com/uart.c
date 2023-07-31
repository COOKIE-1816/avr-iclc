#include "uart.h"
#include <avr/io.h>

void _uart_txwait() {
    while (!(UCSR0A & (1 << UDRE0)));
}

void _uart_rxwait() {
    while (!(UCSR0A & (1 << RXC0)));
}

void uart_init(unsigned long __baudrate) {
    uint16_t ubrr = F_CPU / 16 / __baudrate - 1;

    UBRR0H = (ubrr >> 8);
    UBRR0L = (ubrr & 0xFF);

    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}

void uart_writeByte(uint8_t __byte) {
    _uart_txwait();

    UDR0 = __byte;
}

uint8_t uart_readByte() {
    _uart_rxwait();
    
    return UDR0;
}