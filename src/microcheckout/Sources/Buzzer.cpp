#include "../Headers/Buzzer.h"
#include "../include/Config.h"
#include <Arduino.h>

void beepNormal() {
  tone(BUZZER, 1000);
  delay(500);
  noTone(BUZZER);
}

void beepOk() {
  tone(BUZZER, 1000);
  delay(1500);
  noTone(BUZZER);
}
