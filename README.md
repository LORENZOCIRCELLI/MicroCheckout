# MicroCheckout – Sistema de Checkout Autônomo com Arduino + RFID

**MicroCheckout** é um sistema físico de ponto de venda (PDV) que simula o autoatendimento de um supermercado, funcionando **100% offline e sem computador**.  
O cliente adiciona/remoe produtos apenas passando tags RFID, vê o subtotal em tempo real no display LCD e finaliza a compra com um cartão RFID de pagamento.

Perfeito para feiras de ciências, projetos makers ou como base para um PDV real de baixo custo.

## Objetivo do Projeto

Criar um checkout simples, robusto e totalmente independente utilizando apenas componentes comuns de Arduino.

## Componentes Utilizados

| Componente                  | Função                                      |
|-----------------------------|---------------------------------------------|
| Arduino Uno / Nano          | Microcontrolador principal                  |
| Módulo RFID RC522           | Leitura de tags e cartão de pagamento       |
| Display LCD 16x2 com I2C    | Exibe subtotal e mensagens                  |
| 2x Botões push-button       | Modo remoção e Finalizar compra             |
| LED Verde + resistor        | Feedback de adição                          |
| LED Vermelho + resistor     | Feedback de remoção/erro                    |
| Buzzer ativo ou passivo     | Feedback sonoro                             |
| Bateria 12V + regulador     | Alimentação independente (opcional)         |

## Como Funciona

### Modo Adição (padrão)
- Passe a tag do produto → item adicionado
- LED verde pisca + beep curto
- Subtotal atualizado instantaneamente

### Modo Remoção
- Pressione **Botão 1** → entra no modo remoção
- Passe a tag → item removido
- LED vermelho pisca + beep curto

### Finalizar Compra
- Pressione **Botão 2** → exibe total e pede cartão
- Passe o cartão RFID especial → pagamento confirmado
  - Beep duplo + LED verde fixo
- Cartão errado → beep longo + LED vermelho

Após pagamento o carrinho é zerado automaticamente.

## Feedbacks

| Ação                    | LED           | Buzzer            | LCD                          |
|-------------------------|---------------|-------------------|------------------------------|
| Produto adicionado      | Verde pisca   | Beep curto        | Subtotal atualizado          |
| Produto removido        | Vermelho pisca| Beep curto        | Subtotal atualizado          |
| Tag desconhecida        | Vermelho      | Beep longo        | "Produto nao cadastrado"     |
| Pagamento OK            | Verde fixo    | Beep duplo        | "Obrigado! Volte sempre :)"  |
| Cartão errado           | Vermelho      | Beep longo        | "Cartao invalido"            |


## Principais funções:

- lerTagRFID()
- adicionarProduto()
- removerProduto()
- atualizarLCD()
- finalizarCompra()
- feedbackBuzzerLED()

## Possíveis Melhorias

 - Cadastro de produtos via serial ou cartão admin (sem recompilar)
 - Impressora térmica 58mm para cupom
 - Modo administrador com cartão especial
 - Salvar histórico de vendas na EEPROM ou cartão SD
 - Display OLED ou TFT com mais informações
 - Suporte a múltiplos cartões de pagamento
 - Interface web via ESP8266/ESP32 (versão avançada)

## Licença

Este projeto está licenciado sob a MIT License – veja o arquivo LICENSE para detalhes.