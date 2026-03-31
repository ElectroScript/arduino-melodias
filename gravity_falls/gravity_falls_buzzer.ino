// ============================================================
//  Gravity Falls - Melodía Principal (solo)
//  Buzzer pasivo en Pin 8
//  Monitor Serial → "on" para reproducir, "off" para detener
// ============================================================

const int BUZZER_PIN = 8;

// 0 = pausa
const int melody[] = {
  698, 587, 440, 587, 698, 587, 440, 587, 698, 523,
  440, 523, 698, 523, 440, 523, 659, 554, 440, 554,
  659, 554, 440, 554, 659, 554, 440, 554, 659,   0,
  880,   0, 587,   0, 659,   0, 698,   0, 880,   0,
  783,   0, 880,   0, 523,   0, 587,   0, 659,   0,
  698,   0, 659,   0, 783,   0, 880,   0, 783,   0,
  698,   0, 698,   0, 698,   0, 698,   0, 880,   0,
  880,   0, 783,   0, 698,   0, 880,   0, 880,   0,
  880,   0, 783,   0, 880,   0, 783,   0, 698,   0,
  698,   0, 698,   0, 698,   0, 880,   0, 880,   0,
  783,   0, 698,   0, 880,   0, 880,   0, 880,   0,
 1108,   0,1108,   0,1108,   0, 698,   0, 698,   0,
  698,   0, 880,   0, 880,   0, 783,   0, 698,   0,
  932,   0, 932,   0, 932,   0, 783,   0,1046,   0,
  880,   0,1108,   0, 698, 587, 698, 880, 659, 554,
  880, 1108, 2349,
};

const int durations[] = {
  177, 177, 177, 177, 177, 177, 177, 177, 177, 177,
  177, 177, 177, 177, 177, 177, 177, 177, 177, 177,
  177, 177, 177, 177, 177, 177, 177, 177, 355,  19,
  355,  19,1067,  57, 355,  19,1424,  75, 533,  28,
  533,  28, 355,  19,1424,  75, 711, 413, 355,  19,
  711,  38, 711,  38, 711,  38, 711,  38, 711,  38,
  711, 413, 355,  19, 355,  19, 355,  19, 355,  19,
  355,  19, 355,  19, 355, 394, 355,  19, 355,  19,
  355,  19, 355,  19, 355,  19, 355,  19, 355, 394,
  355,  19, 355,  19, 355,  19, 355,  19, 355,  19,
  355,  19, 355, 394, 355,  19, 355,  19, 355, 394,
  355,  19, 355,  19, 355, 394, 355,  19, 355,  19,
  355,  19, 355,  19, 355,  19, 355,  19, 355, 394,
  355,  19, 355,  19, 355,  19, 711,  38, 711,  38,
  711,  38, 711,  38, 177, 177, 177, 177, 177, 177,
  177, 177, 1424,
};

const int NOTE_COUNT = sizeof(melody) / sizeof(melody[0]);

bool playing = false;
int noteIndex = 0;
unsigned long noteStartTime = 0;
bool noteStarted = false;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Gravity Falls - Buzzer listo.");
  Serial.println("Escribe 'on' para reproducir, 'off' para detener.");
}

void loop() {
  // Leer comandos del Monitor Serial
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toLowerCase();

    if (cmd == "on") {
      playing = true;
      noteIndex = 0;
      noteStartTime = millis();
      noteStarted = false;
      Serial.println(">> Reproduciendo Gravity Falls...");
    } else if (cmd == "off") {
      playing = false;
      noTone(BUZZER_PIN);
      noteStarted = false;
      Serial.println("|| Detenido.");
    }
  }

  if (!playing) return;

  unsigned long now = millis();

  // Iniciar nota al entrar por primera vez
  if (!noteStarted) {
    if (melody[noteIndex] > 0) {
      tone(BUZZER_PIN, melody[noteIndex]);
    } else {
      noTone(BUZZER_PIN);
    }
    noteStarted = true;
  }

  // Cuando termina la duración, pasar a la siguiente nota
  if (now - noteStartTime >= (unsigned long)durations[noteIndex]) {
    noTone(BUZZER_PIN);
    noteIndex++;

    if (noteIndex >= NOTE_COUNT) {
      noteIndex = 0;
      Serial.println("<< Reiniciando melodia...");
    }

    noteStartTime = now;
    noteStarted = false;
  }
}
