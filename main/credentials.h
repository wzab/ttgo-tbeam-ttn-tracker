/*

Credentials file

*/

#pragma once

// Only one of these settings must be defined
//#define USE_ABP
#define USE_ABP

#ifdef USE_ABP

    // LoRaWAN NwkSKey, network session key
    static const u1_t PROGMEM NWKSKEY[16] = { 0x6B, 0x5F, 0x6A, 0x00, 0xEA, 0xDA, 0xA9, 0x9A, 0x11, 0xB0, 0x8B, 0x5F, 0x85, 0x6D, 0x19, 0x1D };
    // LoRaWAN AppSKey, application session key
    static const u1_t PROGMEM APPSKEY[16] = { 0xDD, 0xCA, 0x39, 0x27, 0xB2, 0xCB, 0x75, 0xB9, 0x29, 0xE0, 0x02, 0xEE, 0xBB, 0x21, 0xE1, 0x2A };
    // LoRaWAN end-device address (DevAddr)
    // This has to be unique for every node
    static const u4_t DEVADDR = 0x26011F1D;

#endif

#ifdef USE_OTAA

    // This EUI must be in little-endian format, so least-significant-byte
    // first. When copying an EUI from ttnctl output, this means to reverse
    // the bytes. For TTN issued EUIs the last bytes should be 0x00, 0x00,
    // 0x00.
    static const u1_t PROGMEM APPEUI[8]  = { 0x9E, 0xA9, 0x02, 0xD0, 0x7E, 0xD5, 0xB3, 0x70 };

    // This should also be in little endian format, see above.
    static const u1_t PROGMEM DEVEUI[8]  = { 0x32, 0xE6, 0x3D, 0x21, 0x29, 0xBE, 0xC8, 0xE4 };

    // This key should be in big endian format (or, since it is not really a
    // number but a block of memory, endianness does not really apply). In
    // practice, a key taken from ttnctl can be copied as-is.
    // The key shown here is the semtech default key.
    static const u1_t PROGMEM APPKEY[16] = { 0xCE, 0xB6, 0xF3, 0x8C, 0xC6, 0x8B, 0x92, 0x45, 0xFD, 0x3C, 0xA2, 0x3E, 0x42, 0xD9, 0xFA, 0xF4 };

#endif
