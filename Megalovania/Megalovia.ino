#define BUZZER 8

// Notas
#define NOTE_D4 294
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_F5 698
#define NOTE_G5 784

int melody[] = {

  // Intro
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4,
  NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_F4, NOTE_G4,

  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_A4,
  NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_F4, NOTE_G4,

  // continuación
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4,
  NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_F4, NOTE_G4,

  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_A4,
  NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_F4, NOTE_G4,

  // parte final de la intro
  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_D5,
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_A4,
  NOTE_G4, NOTE_F4
};

int durations[] = {

  8,8,4,4,
  8,8,8,8,
  4,4,

  8,8,4,4,
  8,8,8,8,
  4,4,

  8,8,4,4,
  8,8,8,8,
  4,4,

  8,8,4,4,
  8,8,8,8,
  4,4,

  4,4,4,4,
  4,4,4,4,
  4,4
};

void setup() {}

void loop() {

  int size = sizeof(melody) / sizeof(int);

  for (int i = 0; i < size; i++) {

    int duration = 1000 / durations[i];

    tone(BUZZER, melody[i], duration);

    delay(duration * 1.3);

    noTone(BUZZER);
  }

  delay(3000);
}