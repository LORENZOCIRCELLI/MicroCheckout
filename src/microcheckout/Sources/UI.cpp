#include "../Headers/UI.h"
#include "../../include/Config.h"  // acesso ao lcd

void telaInicial() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sistema de Caixa");
  lcd.setCursor(0,1);
  lcd.print("Aproxime o Cartao");
}

void telaModo(bool soma) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Modo:");
  lcd.setCursor(0,1);
  if (soma) lcd.print("Adicao");
  else lcd.print("Subtracao");
}

void telaProduto(String nome, float total) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(nome);
  lcd.setCursor(0,1);
  lcd.print("Total: $");
  lcd.print(total, 2);
}

void telaPagamento(float total) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pagamento");
  lcd.setCursor(0,1);
  lcd.print("Total: $");
  lcd.print(total, 2);
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Passar Cartao");
}

void telaPagamentoOk(float total) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pagamento OK!");
  lcd.setCursor(0,1);
  lcd.print("Total: $");
  lcd.print(total, 2);
  delay(2000);
}
