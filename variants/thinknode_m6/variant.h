#ifndef _VARIANT_THINKNODE_M6_
#define _VARIANT_THINKNODE_M6_

// Elecrow ThinkNode M6 (nRF52840 + SX1262, 2x18650, 6 W solar, L76K GPS).
// Pin table from Meshtastic variants/nrf52840/ELECROW-ThinkNode-M6 (LGPL-2.1
// core-variant boilerplate), cross-checked against MeshCore variants/thinknode_m6
// and Elecrow's demo code; all three agree on every LoRa pin.
// The pin map is the identity map: Arduino pin N = P0.N for N < 32, P1.(N-32) above.

/** Master clock frequency */
#define VARIANT_MCK             (64000000ul)

#define USE_LFXO                // Board uses 32khz crystal for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define PINS_COUNT              (48)
#define NUM_DIGITAL_PINS        (48)
#define NUM_ANALOG_INPUTS       (1)
#define NUM_ANALOG_OUTPUTS      (0)

// LEDs (active HIGH)
#define LED_RED                 (12)    // P0.12 red power LED
#define LED_BLUE                (7)     // P0.07 blue data LED (bootloader LED)
#define PIN_LED                 LED_BLUE
#define LED_BUILTIN             PIN_LED
#define LED_STATE_ON            (1)

// USB / external power detect
#define EXT_PWR_DETECT          (13)    // P0.13

// Button (active LOW, pull-up); also the bootloader's BUTTON_1
#define PIN_BUTTON1             (17)    // P0.17

// Battery ADC on P0.28 / AIN4, divider connected while ADC_CTRL is HIGH
#define PIN_A0                  (28)
#define BATTERY_PIN             PIN_A0
#define ADC_CTRL                (11)    // P0.11
#define ADC_CTRL_ENABLED        (1)
#define AREF_VOLTAGE            (3.0F)
#define ADC_MULTIPLIER          (1.75F)
#define ADC_RESOLUTION          (12)

// Solar charger status (active LOW)
#define EXT_CHRG_DETECT         (15)    // P0.15

// Peripheral power enable: drive HIGH (SX1262 rail)
#define PIN_POWER_EN            (27)    // P0.27

// NFC pins, not used
#define PIN_NFC1                (9)
#define PIN_NFC2                (10)

// I2C on the SP11 header (PCF8563 RTC at 0x51)
#define WIRE_INTERFACES_COUNT   (1)
#define PIN_WIRE_SDA            (32 + 9)    // P1.09
#define PIN_WIRE_SCL            (8)         // P0.08

// QSPI flash: Macronix MX25R1635F, 2 MB, powered by VDD_FLASH_EN
#define PIN_QSPI_SCK            (32 + 3)    // P1.03
#define PIN_QSPI_CS             (23)        // P0.23
#define PIN_QSPI_IO0            (32 + 1)    // P1.01
#define PIN_QSPI_IO1            (32 + 2)    // P1.02
#define PIN_QSPI_IO2            (32 + 4)    // P1.04
#define PIN_QSPI_IO3            (32 + 5)    // P1.05
#define VDD_FLASH_EN            (21)        // P0.21, drive HIGH before QSPI init

#define EXTERNAL_FLASH_DEVICES  MX25R1635F
#define EXTERNAL_FLASH_USE_QSPI

// SX1262 on SPI0
#define SX126X_CS               (32 + 12)   // P1.12
#define SX126X_DIO1             (32 + 6)    // P1.06
#define SX126X_BUSY             (32 + 11)   // P1.11
#define SX126X_RESET            (32 + 10)   // P1.10

#define SPI_INTERFACES_COUNT    (1)
#define PIN_SPI_MISO            (32 + 15)   // P1.15
#define PIN_SPI_MOSI            (32 + 14)   // P1.14
#define PIN_SPI_SCK             (32 + 13)   // P1.13
#define PIN_SPI_CS              SX126X_CS

// GPS: Quectel L76K on UART1, 9600 baud. Not used by this firmware; held off.
// PIN_GPS_REINIT (P0.29) must be left floating: driving it silences NMEA.
#define GPS_BAUDRATE            9600
#define PIN_GPS_EN              (6)     // P0.06, HIGH = on
#define PIN_GPS_REINIT          (29)    // P0.29, leave floating
#define PIN_GPS_STANDBY         (30)    // P0.30
#define PIN_GPS_PPS             (31)    // P0.31
#define PIN_SERIAL1_TX          (2)     // P0.02, MCU TX -> GPS RX
#define PIN_SERIAL1_RX          (3)     // P0.03, MCU RX <- GPS TX

// Secondary UART on the SP11 header
#define PIN_SERIAL2_RX          (22)
#define PIN_SERIAL2_TX          (24)

#define PIN_AREF                (PINS_COUNT)

#ifdef __cplusplus
}
#endif

// Standard Arduino symbols the Adafruit core and libraries (SdFat, Wire) expect.
#ifdef __cplusplus
static const uint8_t A0   = PIN_A0;
static const uint8_t AREF = PIN_AREF;
static const uint8_t SDA  = PIN_WIRE_SDA;
static const uint8_t SCL  = PIN_WIRE_SCL;
static const uint8_t SS   = PIN_SPI_CS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;
#endif

#endif
