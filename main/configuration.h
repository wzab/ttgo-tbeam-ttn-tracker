/*

TTGO T-BEAM Tracker for The Things Network

Copyright (C) 2018 by Xose Pérez <xose dot perez at gmail dot com>

This code requires LMIC library by Matthijs Kooijman
https://github.com/matthijskooijman/arduino-lmic

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#pragma once

#include <Arduino.h>
#include <lmic.h>
void ttn_register(void (*callback)(uint8_t message));

// -----------------------------------------------------------------------------
// Version
// -----------------------------------------------------------------------------

#define APP_NAME                "TTN MAP-TRACK"
#define APP_VERSION             "1.1.1"

// -----------------------------------------------------------------------------
// Configuration
// -----------------------------------------------------------------------------

// Select which T-Beam board is being used. Only uncomment one.
#define T_BEAM_V07  // AKA Rev0 (first board released)
//#define T_BEAM_V10  // AKA Rev1 (second board released)

// Select the payload format. Change on TTN as well. Only uncomment one.
#define PAYLOAD_USE_FULL
// #define PAYLOAD_USE_CAYENNE

// If using a single-channel gateway, uncomment this next option and set to your gateway's channel
//#define SINGLE_CHANNEL_GATEWAY  0

// If you are having difficulty sending messages to TTN after the first successful send,
// uncomment the next option and experiment with values (~ 1 - 5)
//#define CLOCK_ERROR             5

#define DEBUG_PORT              Serial      // Serial debug port
#define SERIAL_BAUD             115200      // Serial debug baud rate
#define SLEEP_BETWEEN_MESSAGES  0           // Do sleep between messages
#define SEND_INTERVAL           10000       // Sleep for these many millis
#define MESSAGE_TO_SLEEP_DELAY  5000        // Time after message before going to sleep
#define LOGO_DELAY              5000        // Time to show logo on first boot
#define LORAWAN_PORT            10          // Port the messages will be sent to
#define LORAWAN_CONFIRMED_EVERY 0           // Send confirmed message every these many messages (0 means never)
#define LORAWAN_SF              DR_SF10      // Spreading factor
#define LORAWAN_ADR             0           // Enable ADR
#define GPS_WAIT_FOR_LOCK       5000        // Wait 5s after every boot for GPS lock

// -----------------------------------------------------------------------------
// DEBUG
// -----------------------------------------------------------------------------

#ifdef DEBUG_PORT
#define DEBUG_MSG(...) DEBUG_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

// -----------------------------------------------------------------------------
// Custom messages
// -----------------------------------------------------------------------------

#define EV_QUEUED       100
#define EV_PENDING      101
#define EV_ACK          102
#define EV_RESPONSE     103

// -----------------------------------------------------------------------------
// General
// -----------------------------------------------------------------------------

#define I2C_SDA         4
#define I2C_SCL         15
#define LED_PIN         16

#if defined(T_BEAM_V07)
#define BUTTON_PIN      39
#elif defined(T_BEAM_V10)
#define BUTTON_PIN      38
#endif

// -----------------------------------------------------------------------------
// OLED
// -----------------------------------------------------------------------------

#define SSD1306_ADDRESS 0x3C

// -----------------------------------------------------------------------------
// GPS
// -----------------------------------------------------------------------------

#define GPS_SERIAL_NUM  2
#define GPS_BAUDRATE    9600
#define USE_GPS         1

#if defined(T_BEAM_V07)
#define GPS_RX_PIN      23
#define GPS_TX_PIN      19
#elif defined(T_BEAM_V10)
#define GPS_RX_PIN      34
#define GPS_TX_PIN      12
#endif

// -----------------------------------------------------------------------------
// LoRa SPI
// -----------------------------------------------------------------------------

#define SCK_GPIO        5
#define MISO_GPIO       19
#define MOSI_GPIO       27
#define NSS_GPIO        18
#define RESET_GPIO      14
#define DIO0_GPIO       26
#define DIO1_GPIO       33
#define DIO2_GPIO       32

// -----------------------------------------------------------------------------
// AXP192 (Rev1-specific options)
// -----------------------------------------------------------------------------

#define AXP192_SLAVE_ADDRESS  0x34
#define GPS_POWER_CTRL_CH     3
#define LORA_POWER_CTRL_CH    2
#define PMU_IRQ               35
