# 🛒 MicroCheckout – Sistema de Checkout com ESP32 + Interface Web

**MicroCheckout** é um projeto que simula um sistema de ponto de venda (PDV), evoluindo do Arduino para **ESP32**, integrando hardware físico com uma **interface web** via API. Ele utiliza **ESP32**, **tela OLED**, **sensor RFID**, **buzzer** e **LEDs** para registrar e exibir transações de produtos, enquanto **toda a gestão (remoção, finalização, relatórios) é feita via web**.

---

## 🎯 Objetivo

Criar um sistema de checkout funcional com:

- Registro de produtos via **sensor RFID**  
- Exibição de informações críticas em **OLED** (hora, status, total)  
- Integração em tempo real com uma **interface web** via API  
- Feedback sonoro com **buzzer** e visual com **LEDs**  
- Toda a gestão das transações (remoção de itens, finalização da compra) feita **exclusivamente via interface web**

---

## 🧰 Componentes Utilizados

| Componente           | Função                                      |
|----------------------|--------------------------------------------|
| ESP32                | Microcontrolador principal                  |
| Sensor RFID          | Leitura de códigos de produtos             |
| Tela OLED 128x64     | Exibição de informações críticas           |
| Buzzer               | Feedback sonoro das transações             |
| LEDs (verde/vermelho)| Indicação de sucesso/erro                   |
| Protoboard e jumpers | Montagem física                             |

---

## 🛠 Funcionalidades Atuais

- Leitura de **produtos via RFID**  
- Exibição de **nome, preço, total e hora** na tela OLED  
- Integração com **API web** para envio de transações em tempo real  
- Feedback visual (LEDs) e sonoro (buzzer) para cada ação no ESP32  
- Todas as operações de **remoção de itens ou finalização de compra** são feitas via **interface web**

---

## 💡 Fluxo de Funcionamento

1. Inicie o ESP32 e conecte à rede Wi-Fi.  
2. Passe o **cartão RFID** do produto.  
3. O sistema identifica o produto e exibe **nome, preço e total** na OLED.  
4. A transação é enviada para a **interface web** via API.  
5. LEDs e buzzer indicam sucesso ou erro da operação.  
6. Na web, o usuário pode **remover produtos ou finalizar a compra**, que atualizará o total no ESP32 em tempo real.

---

## 📁 Estrutura do Código (ESP32)

```c
struct Produto {
  String rfid;
  const char* nome;
  float preco;
};

// Lista de produtos cadastrados
Produto produtos[] = {
  {"A1B2C3D4", "Sabonete", 3.50},
  {"E5F6G7H8", "Arroz 5kg", 22.90},
  {"I9J0K1L2", "Leite 1L", 4.20},
  // ... adicione mais produtos
};

// Funções principais
// - leituraRFID()
// - atualizarOLED()
// - enviarAPI()
// - feedbackBuzzerLED()
```

---

## 🌐 Integração Web

O ESP32 envia as transações para uma **API REST**, que gerencia os registros em tempo real.  
Na interface web, é possível:

- Visualizar o **total da compra**  
- **Remover itens** antes da finalização  
- **Finalizar a compra**, zerando o total no ESP32  
- Acompanhar histórico de transações e status do dispositivo

---

## 🔜 Próximos Passos

- Expandir a lista de produtos RFID  
- Implementar autenticação de dispositivo via API  
- Criar dashboard web responsivo em **React** ou **Vue**  
- Adicionar relatórios de vendas e estatísticas em tempo real  
- Otimizar feedback OLED e sonoro para maior clareza

---

## 🤝 Contribuição

Contribuições são bem-vindas!  
Sinta-se à vontade para abrir **issues** ou enviar **pull requests**.

---

## 📄 Licença

Este projeto está sob a licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.
