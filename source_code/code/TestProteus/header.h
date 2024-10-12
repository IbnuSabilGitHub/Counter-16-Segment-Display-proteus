#ifndef HEADER_H
#define HEADER_H

#include <stdint.h> // Untuk uint16_t

// Struktur KeyValue
struct KeyValue {
    char key;      // Kunci, misalnya huruf atau karakter
    uint16_t value; // Nilai yang dipetakan
};

// Deklarasi array mappings dengan extern
extern const KeyValue binarySegmentMap[];
extern const KeyValue hexSegmentMap36[];
extern const KeyValue hexSegmentMap26[];

#endif // HEADER_H