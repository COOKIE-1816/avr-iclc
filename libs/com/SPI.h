#ifndef _SPI_H_
#define _SPI_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define SPI_DDR  DDRB
#define SPI_PORT PORTB
#define SS_PIN   PB2
#define MOSI_PIN PB3
#define MISO_PIN PB4
#define SCK_PIN  PB5

// Prepares MCU for SPI communication.
static void spi_init();

static uint8_t spi_writeByte(uint8_t __data);
static void spi_selectSalve();

#endif