# 65C02-SPI

Routines to bitbang the SPI protocol on a 65C02 using a 65C22

These routines are derived from SPI routines written by Garth Wilson.
Visit his web site at [http://wilsonminesco.com]

Routines for bit-banging the SPI protocol using the 65C22 VIA
Port A is used for the SPI data, clock, and slave select lines.

  Mapping of bits in VIA Port A to the SPI interface.

```
    PA7     PA6     PA5     PA4     PA3     PA2     PA1     PA0 
 +-------+-------+-------+-------+-------+-------+-------+-------+
 |       |       |       |       |       |       |       |       |
 |       |  MISO |       |  SS2  |  SS1  |  SS0  |  MOSI |  SCLK |
 |       |       |       |       |       |       |       |       |
 +-------+-------+-------+-------+-------+-------+-------+-------+
             IN             OUT     OUT     OUT     OUT     OUT
```

PA2, PA3, and PA4 are connected to the A, B, and C inputs on a 74xx138 3 to 8 decoder to provide
chip selects for up to 7 devices 1-7, 0 is reserved for no device selected.
See spi_select_device: routine for implementation.

Call spi_init: to initialize the 65C22 and prepare it for use.

To initiate a transfer first call spi_select_device: with the number of the device to select in
the A register (device 1-7). Set the X register to the desired SPI communication mode (mode 0 - 3).

Call spi_transceive: to transmit and recieve 8 bits of data as many times as needed. The A register
holds the data to transmit, on return A will hold the data recieved. On return the carry flag will
indicate success (carry = 0 success, carry = 1 failure).

To end a transfer call spi_select_device: 0 in the A register to deselect the device.

NOTE:
All SPI routines should be called with Interrupts disabled to prevent disruption of data transfer
