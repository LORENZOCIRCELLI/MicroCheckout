#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

// Includes dos módulos
#include "Headers/UI.h"
#include "Headers/Buzzer.h"
#include "Headers/Pagamento.h"
#include "Headers/Produtos.h"
#include "../../include/Config.h"  // Configurações de pinos e variáveis globais

// Objetos globais
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Variáveis globais
float total = 0;
bool modoSoma = true;
float itemHistorico[10];
int historicoIndex = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  lcd.begin(16,2);
  telaInicial();  // mensagem inicial

  // Pinos
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BOTAO_MODO, INPUT_PULLUP);
  pinMode(BOTAO_PAGAMENTO, INPUT_PULLUP);
}

void loop() {
  static unsigned long ultimaLeitura = 0;

  // --- Botão modo (soma/subtração) ---
  if (digitalRead(BOTAO_MODO) == LOW && millis() - ultimaLeitura > 300) {
    ultimaLeitura = millis();
    modoSoma = !modoSoma;
    telaModo(modoSoma);
    delay(1000); // pausa visual
  }

  // --- Botão pagamento ---
  if (digitalRead(BOTAO_PAGAMENTO) == LOW && millis() - ultimaLeitura > 300) {
    ultimaLeitura = millis();
    processarPagamento();
  }

  // --- Verifica novo cartão RFID ---
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // --- Lê UID da tag ---
  String uidTag = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uidTag.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    uidTag.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  uidTag.toUpperCase();
  Serial.print("Tag detectada: "); Serial.println(uidTag);

  // --- Procura produto correspondente ---
  for (int i = 0; i < qtdProdutos; i++) {
    if (uidTag.substring(1) == produtos[i].uid) {
      // Mostra produto no LCD
      telaProduto(produtos[i].nome, total);

      if (modoSoma) {
        // Adiciona item
        if (historicoIndex < 10) {
          itemHistorico[historicoIndex++] = produtos[i].preco;
          total += produtos[i].preco;
          digitalWrite(LED_VERDE, HIGH); digitalWrite(LED_VERMELHO, LOW);
          delay(500);
          digitalWrite(LED_VERDE, LOW);
        }
      } else {
        // Remove item
        if (historicoIndex > 0 && total > 0) {
          historicoIndex--;
          total -= itemHistorico[historicoIndex];
          digitalWrite(LED_VERDE, LOW); digitalWrite(LED_VERMELHO, HIGH);
          delay(500);
          digitalWrite(LED_VERMELHO, LOW);
        }
      }

      beepNormal();   // bip curto
      telaInicial();  // volta para tela inicial
      break;          // sai do loop de produtos
    }
  }
}
