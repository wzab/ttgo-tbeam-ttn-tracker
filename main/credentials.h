/*

Credentials file

*/

#pragma once

// Only one of these settings must be defined
#define USE_ABP
//#define USE_OTAA

#ifdef USE_ABP

    // LoRaWAN NwkSKey, network session key
    static const u1_t PROGMEM NWKSKEY[16] = { 0x13, 0x13, 0x1D, 0x28, 0x47, 0x7B, 0x9C, 0x61, 0x0E, 0x96, 0xC7, 0x12, 0xA2, 0xF3, 0x74, 0x2C };
    // LoRaWAN AppSKey, application session key
    static const u1_t PROGMEM APPSKEY[16] = { 0xE7, 0xE6, 0x09, 0x87, 0xCA, 0x34, 0x5F, 0xB2, 0xC7, 0xB2, 0x9A, 0x9A, 0x52, 0xA6, 0x73, 0x56 };
    // LoRaWAN end-device address (DevAddr)
    // This has to be unique for every node
    static const u4_t DEVADDR = 0x26011BD2;

#endif

#ifdef USE_OTAA

    // This EUI must be in little-endian format, so least-significant-byte
    // first. When copying an EUI from ttnctl output, this means to reverse
    // the bytes. For TTN issued EUIs the last bytes should be 0x00, 0x00,
    // 0x00.
    static const u1_t PROGMEM APPEUI[8]  = { 0x9E, 0xA9, 0x02, 0xD0, 0x7E, 0xD5, 0xB3, 0x70 };

    // This should also be in little endian format, see above.
    static const u1_t PROGMEM DEVEUI[8]  = { 0x00, 0x40, 0x7A, 0x96, 0x0C, 0x36, 0x33, 0x00 };

    // This key should be in big endian format (or, since it is not really a
    // number but a block of memory, endianness does not really apply). In
    // practice, a key taken from ttnctl can be copied as-is.
    // The key shown here is the semtech default key.
    static const u1_t PROGMEM APPKEY[16] = { 0x2A, 0x27, 0xA9, 0xAB, 0x7E, 0x3B, 0xB9, 0x69, 0x9F, 0x10, 0xCE, 0x28, 0x81, 0xA0, 0x96, 0x06 };

#endif
