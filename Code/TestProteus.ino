// Pin untuk koneksi shift register
const int dataPin = 2;   // Pin untuk Data Serial Input (DS)
const int latchPin = 3;  // Pin untuk Storage Clock (ST_CP)
const int clockPin = 4;  // Pin untuk Shift Clock (SH_CP)
const int displayPins[] = { 5, 6, 7, 8 };
uint16_t pattern = 0x0000;
// Mapping segmen 16-bit untuk karakter 1-9 dan A-Z
const uint16_t segmentMap[] = {
  0b0100010011111111,  // 0
  0b0000000000001100,  // 1
  0b1000100001110111,  // 2
  0b1000100000111111,  // 3
  0b1000100010001100,  // 4
  0b1001000010110011,  // 5
  0b1000100011111011,  // 6
  0b0000000000001111,  // 7
  0b1000100011111111,  // 8
  0b1000100010111111,  // 9
  0b1000100011001111,  // A
  0b0010001000111111,  // B
  0b0000000011110011,  // C
  0b0010001000111111,  // D
  0b1000100011110011,  // E
  0b1000100011110011,  // F
  0b0000100011111011,  // G
  0b1000100011001100,  // H
  0b0010001000110011,  // I
  0b0000000001111100,  // J
  0b1001010011000000,  // K
  0b0000000011110000,  // L
  0b0000010111001100,  // M
  0b0001000111001100,  // N
  0b0000000011111111,  // O
  0b1000100011000111,  // P
  0b0001000011111111,  // Q
  0b1001100011000111,  // R
  0b1000100010111011,  // S
  0b0010001000000011,  // T
  0b0000000011111100,  // U
  0b0100010011000000,  // V
  0b0101000011001100,  // W
  0b0101010100000000,  // X
  0b0010010100000000,  // Y
  0b0100010000110011   // Z


};

const char characters[] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
  'V', 'W', 'X', 'Y', 'Z'
};

char nama[4] = { 'I', 'B', 'N', 'U' };
uint16_t key[] = {};                   // Inisialisasi key untuk menyimpan kunci index
int currentIndex[4] = { 0, 0, 0, 0 };  // Variabel untuk melacak indeks karakter yang sedang ditampilkan
bool displayDone[4] = {false, false, false, false};  // Menyimpan status apakah setiap display sudah selesai

void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(displayPins[i], OUTPUT);
    key[i] += getKey(nama[i]);
  }


  //   uint16_t value = 0b1000100001110111; // Misal nilai 16-bit
  //   uint8_t firstByte = (value >> 8) & 0xFF; // Hasilnya: 0xAB
  //   uint8_t secondByte = value & 0xFF;         // Hasilnya: 0xCD
  //   Serial.println(firstByte);
  //   Serial.println(secondByte);
  //   // printBinary(secondByte);
  //   digitalWrite(latchPin, LOW);                        // Mulai pengiriman
  //   shiftOut(dataPin, clockPin, MSBFIRST, firstByte);   // Kirim byte pertama
  //   shiftOut(dataPin, clockPin, MSBFIRST, secondByte);  // Kirim byte kedua
  //   digitalWrite(latchPin, HIGH);
}

void loop() {
  // Cek jika semua display sudah selesai
  bool allDone = true;
  for (int i = 0; i < 4; i++) {
    if (!displayDone[i]) {
      allDone = false;  // Jika ada display yang belum selesai, set allDone menjadi false
      break;
    }
  }

  if (allDone) {
    // Semua display selesai, tampilkan huruf yang diinginkan tanpa perubahan
    for (int i = 0; i < 4; i++) {
      digitalWrite(displayPins[i], HIGH);   // Aktifkan display i
      shiftOutData(key[i]);                 // Tampilkan huruf sesuai key[i]
      delay(2);                             // Sedikit penundaan
      digitalWrite(displayPins[i], LOW);    // Nonaktifkan display i
    }
  } else {
    // Jika belum selesai, jalankan counter untuk setiap display
    for (int i = 0; i < 4; i++) {
      digitalWrite(displayPins[i], HIGH);    // Aktifkan display i
      counter_character(key[i], i);          // Hitung sampai mencapai huruf yang diinginkan
      delay(2);                              // Sedikit penundaan
      digitalWrite(displayPins[i], LOW);     // Nonaktifkan display i
    }
  }
}



// Fungsi untuk menghitung dari A-Z dan berhenti saat mencapai target
void counter_character(uint16_t targetCharacter, int displayIndex) {
  // Cek jika display ini belum selesai
  if (!displayDone[displayIndex]) {
    // Ambil data segmen dari indeks yang sedang dihitung
    uint16_t segmentData = segmentMap[currentIndex[displayIndex]];

    // Kirim data ke shift register
    shiftOutData(segmentData);

    // Jika karakter yang sedang ditampilkan sesuai dengan target, berhenti
    if (segmentData == targetCharacter) {
      displayDone[displayIndex] = true;  // Set display ini menjadi selesai
    } else {
      // Lanjutkan ke karakter berikutnya
      currentIndex[displayIndex]++;
      if (currentIndex[displayIndex] >= sizeof(segmentMap) / sizeof(segmentMap[0])) {
        currentIndex[displayIndex] = 0;  // Kembali ke awal jika mencapai akhir
      }
    }
    delay(200); // Penundaan untuk memberikan efek animasi
  }
}


uint16_t getKey(char character) {
  for (int i = 0; i < sizeof(characters) / sizeof(characters[0]); i++) {
    if (characters[i] == character) {
      return segmentMap[i];  // Kembalikan key(index) yg cocok
    }
  }
  return 0x0000;  // Kembalikan default (semua mati) jika karakter tidak ditemukan
}
// Void function menampilkan character di display melalui shift register
void shiftOutData(uint16_t segmentData) {
  uint8_t firstByte = (segmentData >> 8) & 0xFF;  // Ambil 8 bit pertama
  uint8_t secondByte = segmentData & 0xFF;        // Ambil 8 bit kedua
  digitalWrite(latchPin, LOW);                    // Mulai pengiriman
  shiftOut(dataPin, clockPin, MSBFIRST, firstByte);
  shiftOut(dataPin, clockPin, MSBFIRST, secondByte);  // Kirim byte kedua
  digitalWrite(latchPin, HIGH);                       // Mengunci output
}

void printBinary(uint16_t value) {
  for (int i = 16; i >= 0; i--) {
    Serial.print((value >> i) & 1);
  }
  Serial.println();
}
