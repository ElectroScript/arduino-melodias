#include "pitches.h"
#define REST 0

// =========================================
// BLUE BIRD - Ikimono Gakari
// Naruto Shippuden OP 3
// Notas extraidas directamente del archivo MIDI
// Tonalidad: F# mayor | Tempo: ~148 BPM
// =========================================

const int BUZZER_PIN = 8;

int melody[] = {
  REST, NOTE_CS5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_GS5, NOTE_FS5, REST,
  NOTE_CS5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_CS6,
  REST, NOTE_CS5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_GS5, NOTE_FS5, REST,
  NOTE_FS5, NOTE_CS6, NOTE_B5, REST, NOTE_FS5, NOTE_CS6, NOTE_B5, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_FS5, NOTE_FS5, REST, NOTE_CS5, NOTE_FS5,
  NOTE_GS5, NOTE_A5, NOTE_CS5, NOTE_A5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_FS5,
  NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_D5, NOTE_E5,
  NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_A5,
  NOTE_GS5, NOTE_CS5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_CS5, NOTE_A5, NOTE_GS5,
  NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_CS5, NOTE_CS5,
  NOTE_CS5, NOTE_D5, NOTE_A5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5,
  REST, NOTE_CS5, NOTE_FS5, NOTE_GS5, NOTE_A5, REST, NOTE_A5, NOTE_GS5,
  NOTE_A5, NOTE_GS5, REST, NOTE_CS5, NOTE_GS5, NOTE_A5, NOTE_B5, REST,
  NOTE_B5, NOTE_A5, NOTE_GS5, NOTE_FS5, REST, NOTE_FS5, NOTE_A5, NOTE_B5,
  NOTE_CS6, NOTE_FS5, NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_CS6, NOTE_E6, NOTE_D6,
  NOTE_CS6, REST, NOTE_CS6, NOTE_GS5, NOTE_FS5, NOTE_CS6, NOTE_CS5, NOTE_FS5,
  NOTE_GS5, NOTE_A5, NOTE_GS5, NOTE_FS5, REST, NOTE_CS5, NOTE_FS5, NOTE_GS5,
  NOTE_A5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_CS6, REST, NOTE_CS5, NOTE_FS5,
  NOTE_GS5, NOTE_A5, NOTE_GS5, NOTE_FS5, REST, NOTE_FS5, NOTE_CS6, NOTE_B5,
  REST, NOTE_FS5, NOTE_CS6, NOTE_B5, REST, NOTE_E5, NOTE_E5, REST,
  NOTE_FS5, NOTE_FS5, REST, NOTE_CS5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_GS5,
  NOTE_FS5, REST, NOTE_CS5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_A5,
  NOTE_B5, NOTE_CS6, REST, NOTE_CS5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_GS5,
  NOTE_FS5, REST, NOTE_FS5, NOTE_CS6, NOTE_B5, REST, NOTE_FS5, NOTE_CS6,
  NOTE_B5, REST, NOTE_E5, NOTE_E5, REST, NOTE_FS5, NOTE_FS5, REST,
  NOTE_FS5, NOTE_CS6, NOTE_B5, REST, NOTE_FS5, NOTE_CS6, NOTE_B5, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_FS5, NOTE_FS5, REST, NOTE_FS5, NOTE_CS6,
  NOTE_B5, REST, NOTE_FS5, NOTE_CS6, NOTE_B5, REST, NOTE_E5, NOTE_E5,
  REST, NOTE_FS5, NOTE_FS5,
};

int durations[] = {
  16, 16, 16, 16, 4, 8, 4, 16,
  16, 16, 16, 4, 8, 16, 8, 8,
  16, 16, 16, 16, 4, 8, 4, 16,
  16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 4, 2, 16, 16,
  16, 16, 16, 16, 8, 16, 16, 8,
  16, 16, 8, 16, 16, 16, 16, 16,
  16, 8, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 8,
  16, 16, 8, 16, 16, 8, 16, 16,
  16, 8, 8, 16, 8, 8, 16, 8,
  16, 16, 16, 16, 4, 8, 8, 16,
  16, 16, 16, 16, 16, 16, 4, 8,
  8, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 8, 8, 4, 16, 8, 16,
  2, 4, 16, 16, 16, 16, 16, 16,
  16, 4, 8, 4, 16, 16, 16, 16,
  4, 8, 16, 8, 8, 16, 16, 16,
  16, 4, 8, 4, 16, 16, 16, 16,
  16, 16, 16, 16, 16, 8, 16, 16,
  16, 8, 16, 16, 16, 16, 4, 8,
  4, 16, 16, 16, 16, 4, 8, 16,
  8, 8, 16, 16, 16, 16, 4, 8,
  4, 16, 16, 16, 16, 16, 16, 16,
  16, 16, 8, 16, 16, 16, 8, 16,
  16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 8, 16, 16, 16,
  16, 16, 16, 16, 16, 16, 8, 16,
  16, 16, 4,
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  delay(1000);
  playMelody();
}

void loop() {
  delay(5000);
  playMelody();
}

void playMelody() {
  int notes = sizeof(melody) / sizeof(melody[0]);
  int tempo = 80;

  for (int i = 0; i < notes; i++) {
    int noteDuration = (60000 / tempo) * (4.0 / durations[i]);

    if (melody[i] == REST) {
      delay(noteDuration);
    } else {
      tone(BUZZER_PIN, melody[i], noteDuration * 0.88);
      delay(noteDuration);
      noTone(BUZZER_PIN);
    }
    delay(6);
  }
}
