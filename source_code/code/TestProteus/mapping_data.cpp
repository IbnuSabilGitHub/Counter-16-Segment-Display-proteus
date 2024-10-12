#include "header.h"

// Definisi array binarySegmentMap untuk 36 karakter
const KeyValue binarySegmentMap[] = {
  { '0', 0b0100010011111111 },
  { '1', 0b0000000000001100 },
  { '2', 0b1000100001110111 },
  { '3', 0b1000100000111111 },
  { '4', 0b1000100010001100 },
  { '5', 0b1001000010110011 },
  { '6', 0b1000100011111011 },
  { '7', 0b0000000000001111 },
  { '8', 0b1000100011111111 },
  { '9', 0b1000100010111111 },
  { 'A', 0b1000100011001111 },
  { 'B', 0b0010101000111111 },
  { 'C', 0b0000000011110011 },
  { 'D', 0b0010001000111111 },
  { 'E', 0b1000100011110011 },
  { 'F', 0b1000100011110011 },
  { 'G', 0b0000100011111011 },
  { 'H', 0b1000100011001100 },
  { 'I', 0b0010001000110011 },
  { 'J', 0b0000000001111100 },
  { 'K', 0b1001010011000000 },
  { 'L', 0b0000000011110000 },
  { 'M', 0b0000010111001100 },
  { 'N', 0b0001000111001100 },
  { 'O', 0b0000000011111111 },
  { 'P', 0b1000100011000111 },
  { 'Q', 0b0001000011111111 },
  { 'R', 0b1001100011000111 },
  { 'S', 0b1000100010111011 },
  { 'T', 0b0010001000000011 },
  { 'U', 0b0000000011111100 },
  { 'V', 0b0100010011000000 },
  { 'W', 0b0101000011001100 },
  { 'X', 0b0101010100000000 },
  { 'Y', 0b0010010100000000 },
  { 'Z', 0b0100010000110011 },

  // Tambahkan lebih banyak pasangan kunci-nilai sesuai kebutuhan
};

// Definisi array hexSegmentMapBinary untuk 36 karakter 1-9 dan A-Z
const KeyValue hexSegmentMap36[] = {
  { '0', 0x44FF },
  { '1', 0x000C },
  { '2', 0x8877 },
  { '3', 0x883F },
  { '4', 0x888C },
  { '5', 0x90B3 },
  { '6', 0x88FB },
  { '7', 0x000F },
  { '8', 0x88FF },
  { '9', 0x88BF },
  { 'A', 0x88CF },
  { 'B', 0x2A3F },
  { 'C', 0x00F3 },
  { 'D', 0x223F },
  { 'E', 0x88F3 },
  { 'F', 0x88F3 },
  { 'G', 0x08FB },
  { 'H', 0x88CC },
  { 'I', 0x2233 },
  { 'J', 0x007C },
  { 'K', 0x94C0 },
  { 'L', 0x00F0 },
  { 'M', 0x05CC },
  { 'N', 0x11CC },
  { 'O', 0x00FF },
  { 'P', 0x88C7 },
  { 'Q', 0x10FF },
  { 'R', 0x98C7 },
  { 'S', 0x88BB },
  { 'T', 0x2203 },
  { 'U', 0x00FC },
  { 'V', 0x44C0 },
  { 'W', 0x50CC },
  { 'X', 0x5500 },
  { 'Y', 0x2500 },
  { 'Z', 0x4433 },

};

// Definisi array hexSegmentMapBinary untuk 26 karakter A-Z3
const KeyValue hexSegmentMap26[] = {
  { '0', 0x44FF },
  { '1', 0x000C },
  { '2', 0x8877 },
  { '3', 0x883F },
  { '4', 0x888C },
  { '5', 0x90B3 },
  { '6', 0x88FB },
  { '7', 0x000F },
  { '8', 0x88FF },
  { '9', 0x88BF },
  { 'A', 0x88CF },
  { 'B', 0x2A3F },
  { 'C', 0x00F3 },
  { 'D', 0x223F },
  { 'E', 0x88F3 },
  { 'F', 0x88F3 },
  { 'G', 0x08FB },
  { 'H', 0x88CC },
  { 'I', 0x2233 },
  { 'J', 0x007C },
  { 'K', 0x94C0 },
  { 'L', 0x00F0 },
  { 'M', 0x05CC },
  { 'N', 0x11CC },
  { 'O', 0x00FF },
  { 'P', 0x88C7 },
  { 'Q', 0x10FF },
  { 'R', 0x98C7 },
  { 'S', 0x88BB },
  { 'T', 0x2203 },
  { 'U', 0x00FC },
  { 'V', 0x44C0 },
  { 'W', 0x50CC },
  { 'X', 0x5500 },
  { 'Y', 0x2500 },
  { 'Z', 0x4433 },

};


// Definisi SegmentMap
const SegmentMap segmentMaps = {
  binarySegmentMap,  // Menginisialisasi pointer ke binarySegmentMap
  hexSegmentMap36,   // Menginisialisasi pointer ke hexSegmentMap 36 
  hexSegmentMap26,   // Menginisialisasi pointer ke hexSegmentMap 26
};

// Mendapatkan ukuran dari masing-masing array
const int binarySegmentMapSize = sizeof(binarySegmentMap) / sizeof(binarySegmentMap[0]);
const int hexSegmentMap36Size = sizeof(hexSegmentMap36) / sizeof(hexSegmentMap36[0]);
const int hexSegmentMap26Size = sizeof(hexSegmentMap26) / sizeof(hexSegmentMap26[0]);