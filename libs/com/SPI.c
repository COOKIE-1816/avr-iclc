#include "SPI.h"

inline void spi_init() {
    SPI_DDR |= (1 << MOSI_PIN) | (1 << SCK_PIN) | (1 << SS_PIN);
    SPI_DDR &= ~(1 << MISO_PIN);

    SPCR |= (1 << SPE) | (1 << MSTR);
    SPCR |= (1 << SPR1) | (1 << SPR0);
}

inline uint8_t spi_writeByte(uint8_t __data) {
    SPDR = __data;

    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}

inline void spi_selectSalve() {
    SPI_PORT &= ~(1 << SS_PIN);
}