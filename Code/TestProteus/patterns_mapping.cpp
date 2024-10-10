#include "header.h"

// Definisi array binarySegmentMap
const KeyValue binarySegmentMap[] = {
  { "A", 0b1000100011001111 },  // A
  { "B", 0b0010101000111111 },  // B
  { "C", 0b0000000011110011 },  // C
  { "D", 0b0010001000111111 },  // D
  { "E", 0b1000100011110011 },  // E
  { "F", 0b1000100011110011 },  // F
  { "G", 0b0000100011111011 },  // G
  { "H", 0b1000100011001100 },  // H
  { "I", 0b0010001000110011 },  // I
  { "J", 0b0000000001111100 },  // J
  { "K", 0b1001010011000000 },  // K
  { "L", 0b0000000011110000 },  // L
  { "M", 0b0000010111001100 },  // M
  { "N", 0b0001000111001100 },  // N
  { "O", 0b0000000011111111 },  // O
  { "P", 0b1000100011000111 },  // P
  { "Q", 0b0001000011111111 },  // Q
  { "R", 0b1001100011000111 },  // R
  { "S", 0b1000100010111011 },  // S
  { "T", 0b0010001000000011 },  // T
  { "U", 0b0000000011111100 },  // U
  { "V", 0b0100010011000000 },  // V
  { "W", 0b0101000011001100 },  // W
  { "X", 0b0101010100000000 },  // X
  { "Y", 0b0010010100000000 },  // Y
  { "Z ", 0b0100010000110011 }  // Z
};

// Definisi array hexSegmentMapBinary
const KeyValue hexSegmentMapBinary[] = {
  { "0", 0x44FF },
  { "1", 0x000C },
  { "2", 0x8877 },
  { "3", 0x883F },
  { "4", 0x888C },
  { "5", 0x90B3 },
  { "6", 0x88FB },
  { "7", 0x000F },
  { "8", 0x88FF },
  { "9", 0x88BF },
  { "A", 0x88CF },
  { "B", 0x2A3F },
  { "C", 0x00F3 },
  { "D", 0x223F },
  { "E", 0x88F3 },
  { "F", 0x88F3 },
  { "G", 0x08FB },
  { "H", 0x88CC },
  { "I", 0x2233 },
  { "J", 0x007C },
  { "K", 0x94C0 },
  { "L", 0x00F0 },
  { "M", 0x05CC },
  { "N", 0x11CC },
  { "O", 0x00FF },
  { "P", 0x88C7 },
  { "Q", 0x10FF },
  { "R", 0x98C7 },
  { "S", 0x88BB },
  { "T", 0x2203 },
  { "U", 0x00FC },
  { "V", 0x44C0 },
  { "W", 0x50CC },
  { "X", 0x5500 },
  { "Y", 0x2500 },
  { "Z", 0x4433 }
};
const SegmentMap segmentMaps = {
  binarySegmentMap,    // Menginisialisasi pointer ke binarySegmentMap
  hexSegmentMapBinary  // Menginisialisasi pointer ke hexSegmentMapBinary
};