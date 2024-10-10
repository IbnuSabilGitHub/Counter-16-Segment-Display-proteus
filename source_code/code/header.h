#ifndef MYVARIABLES_H
#define MYVARIABLES_H
#include <stdint.h>
// Buat struct untuk menyioan kunci dan nilai nya
struct KeyValue {
  char key;      // Kunci, misalnya huruf atau karakter
  uint16_t value;     // Nilai yang dipetakan
};

// Struktur SegmentMap yang berisi dua array
struct SegmentMap {
    const KeyValue* binary; // Pointer ke array binarySegmentMap
    const KeyValue* hex;    // Pointer ke array hexSegmentMapBinary
};

// Deklarasi array mappings dengan extern
extern const KeyValue binarySegmentMap[];
extern const KeyValue hexSegmentMapBinary[];

#endif
