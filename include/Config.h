#ifndef CONFIG_H
#define CONFIG_H

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

#define BUZZER 8
#define LED_VERDE A0
#define LED_VERMELHO A1
#define BOTAO_MODO A2
#define BOTAO_PAGAMENTO A3

extern LiquidCrystal lcd;
extern MFRC522 mfrc522;

extern float total;
extern bool modoSoma;
extern float itemHistorico[10];
extern int historicoIndex;

#endif
