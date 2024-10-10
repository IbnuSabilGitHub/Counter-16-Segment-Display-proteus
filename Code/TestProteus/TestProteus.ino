// #include "header.h"

// Pin untuk koneksi shift register
const int dataPin = 2;   // Pin untuk Data Serial Input (DS)
const int latchPin = 3;  // Pin untuk Storage Clock (ST_CP)
const int clockPin = 4;  // Pin untuk Shift Clock (SH_CP)

const int displayPins[] = { 5, 6, 7, 8 };
const int speedPin = A6;

// Mapping segmen 16-bit untuk karakter 1-9 dan A-Z
const uint16_t segmentMap[] = {
  0x44FF, // 0
  0x000C, // 1
  0x8877, // 2
  0x883F, // 3
  0x888C, // 4
  0x90B3, // 5
  0x88FB, // 6
  0x000F, // 7
  0x88FF, // 8
  0x88BF, // 9
  0x88CF, // A
  0x2A3F, // B
  0x00F3, // C
  0x223F, // D
  0x88F3, // E
  0x88F3, // F
  0x08FB, // G
  0x88CC, // H
  0x2233, // I
  0x007C, // J
  0x94C0, // K
  0x00F0, // L
  0x05CC, // M
  0x11CC, // N
  0x00FF, // O
  0x88C7, // P
  0x10FF, // Q
  0x98C7, // R
  0x88BB, // S
  0x2203, // T
  0x00FC, // U
  0x44C0, // V
  0x50CC, // W
  0x5500, // X
  0x2500, // Y
  0x4433  // Z
};

const char characters[] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
  'V', 'W', 'X', 'Y', 'Z'
};


char nama[4] = { 'I', 'B', 'N', 'U' };                                    // Nama yang ditampilkan
int key[4] = {};                                                          // Kunci untuk menyimpan indeks karakter
int counter = 0;                                                          // Variabel untuk menyimpan nilai counter
int displayCounter = 0;                                                   // Variabel untuk menyimpan nilai display
unsigned long lastUpdateTime = 0;                                         // Waktu update counter
const int updateInterval = 100;                                           // Interval update dalam ms
const int segmentMapLength = sizeof(characters) / sizeof(characters[0]);  // mengambil panjang arr
bool displayStatus[4] = { false, false, false, false };                   // Status display

void setup() {
  Serial.begin(9600);         // Serial begin untuk debug
  pinMode(speedPin, INPUT);   // Pin ini sebagai input
  pinMode(dataPin, OUTPUT);   // Pin data dari SR sebagai output
  pinMode(latchPin, OUTPUT);  // Pin latch dari SR sebagai output
  pinMode(clockPin, OUTPUT);  // Pin clock dari SR sebagai output

  // Set semua pin display sebagai output dan dapatkan kunci dari nama
  for (int i = 0; i < 4; i++) {
    pinMode(displayPins[i], OUTPUT);
    key[i] = getKey(nama[i]);
  }
}

void loop() {

  // Multiplexing display
  for (int display = 0; display < displayCounter + 1; display++) {
    for (int i = 0; i < displayCounter + 1; i++) {
      digitalWrite(displayPins[i], LOW);  // Matikan display setelah update
    }

    // operator ternary untuk menentukan nilai dari indexCharacter
    int indexCharacter = displayStatus[display] ? key[display] : counter;

    // Ambil data segment
    uint16_t segmentData = segmentMap[indexCharacter];
    shiftOutData(segmentData);  // Kirimkan data ke shift register

    // Tampilkan karakter saat ini
    TurnOnDigitPin(display);
    delay(5);  // Jeda singkat untuk multiplexing
  }

  // Update counter berdasarkan waktu
  if (millis() - lastUpdateTime > updateInterval) {
    lastUpdateTime = millis();  // Simpan waktu terakhir update
    counter++;                  // Increment counter untuk langkah berikutnya

    // Periksa apakah counter telah mencapai karakter yang ditentukan
    if (counter < segmentMapLength && segmentMap[counter] == segmentMap[key[displayCounter]]) {
      displayStatus[displayCounter] = true;  // Tandai display saat ini
      counter = 0;                           /// Reset counter ke nol

      // Tambahkan displayCounter jika belum mencapai batas
      if (displayCounter < 4) {
        displayCounter++;  // Tambah 1 nilai display (lanjut ke display selanjutnya)
      }
    }
  }
}

// Nyalakan satu persatu display untuk multiplexing
void TurnOnDigitPin(int digitPin) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(displayPins[i], (i == digitPin) ? HIGH : LOW);
  }
}

// Dapatkan kunci karakter
int getKey(char character) {
  for (int i = 0; i < sizeof(characters) / sizeof(characters[0]); i++) {
    if (characters[i] == character) {
      return i;  // Kembalikan kunci yang cocok
    }
  }
  return 0;  // Kembalikan default jika tidak ditemukan
}

// Kirim data ke shift register
void shiftOutData(uint16_t segmentData) {
  uint8_t firstByte = (segmentData >> 8) & 0xFF;  // Ambil 8 bit pertama
  uint8_t secondByte = segmentData & 0xFF;        // Ambil 8 bit kedua
  // Mulai pengiriman
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, firstByte);
  shiftOut(dataPin, clockPin, MSBFIRST, secondByte);  // Kirim byte kedua
  digitalWrite(latchPin, HIGH);                       // Mengunci output
}


void printCurrentCharacter(int display, char character) {
  Serial.print("Display ");
  Serial.print(display);
  Serial.print(": ");
  Serial.println(character);
}
