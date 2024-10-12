#ifndef HEADER_H
#define HEADER_H

#include <stdint.h> // Untuk uint16_t

// Struktur KeyValue
struct KeyValue {
    char key;      // Kunci, misalnya huruf atau karakter
    uint16_t value; // Nilai yang dipetakan
};

// Struktur SegmentMap yang berisi dua array
struct SegmentMap {
    const KeyValue* binary; // Pointer ke array binarySegmentMap
    const KeyValue* hex36;    // Pointer ke array hexSegmentMap 36
    const KeyValue* hex26;    // Pointer ke array hexSegmentMap 26
};

// Deklarasi SegmentMap dengan extern
extern const SegmentMap segmentMaps;

// Ukuran array
extern const int binarySegmentMapSize;
extern const int hexSegmentMap36Size;
extern const int hexSegmentMap26Size;



#endif // HEADER_H