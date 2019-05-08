;--------------------------------------------------------------------------------------------------
; SPI protocol and interface defines.
;--------------------------------------------------------------------------------------------------

; SPI device deselection id
NONE_DEV			= $00

; SPI input/output pin defines used with VIA 1 port A
SPI_SCLK            = %00000001
SPI_MOSI            = %00000010
SPI_MISO            = %01000000
SPI_SSEL            = %00011100
