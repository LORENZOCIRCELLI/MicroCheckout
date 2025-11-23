#include "../Headers/Pagamento.h"
#include "../Headers/UI.h"
#include "../Headers/Buzzer.h"
#include "../../include/Config.h"
#include <Arduino.h>

#define UID_PAGAMENTO "E3 21 C9 11"

void resetarCaixa() {
  total = 0;
  historicoIndex = 0;
}

void processarPagamento() {
  telaPagamento(total);

  while (true) {
    if (!mfrc522.PICC_IsNewCardPresent()) continue;
    if (!mfrc522.PICC_ReadCardSerial()) continue;

    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      uid.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    uid.toUpperCase();

    if (uid.substring(1) == UID_PAGAMENTO) {
      telaPagamentoOk(total);
      beepOk();
      resetarCaixa();
      telaInicial();
      return;
    }
  }
}
