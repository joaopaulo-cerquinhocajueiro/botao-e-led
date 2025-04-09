# Projeto: botao_e_led

Controle de LED via botão com lógica configurável. Consegue identificar como aciona?
![Visualização por IA](botão_e_led.png)
## 📋 Descrição

Este projeto foi desenvolvido para o Arduino Uno e permite acionar um LED com um botão, cuja lógica de acionamento pode ser modificada dinamicamente através de 4 chaves DIP switch.

O botão está conectado ao pino digital 4 com resistor de **pull-up interno**, e o LED está no pino 3. As chaves DIP switch estão conectadas aos pinos 5, 6, 7 e 8, e permitem ao usuário modificar o comportamento do LED de forma simples, sem reprogramar o microcontrolador.

A brincadeira é tentar identificar o funcionamento do sistema sem saber que configuração está sendo usada.

---

## ⚙️ Plataforma

- **Placa:** Arduino Uno (ATmega328P)
- **Framework:** Arduino
- **Ambiente de desenvolvimento:** PlatformIO

---

## 🔌 Conexões

| Componente    | Pino Arduino | Observações                        |
|---------------|--------------|------------------------------------|
| LED           | D3           | Saída digital com PWM                      |
| Botão         | D4           | Entrada digital com `INPUT_PULLUP` |
| DIP switch 1  | D5           | Entrada digital                    |
| DIP switch 2  | D6           | Entrada digital                    |
| DIP switch 3  | D7           | Entrada digital                    |
| DIP switch 4  | D8           | Entrada digital                    |

---

## 🚀 Como usar

1. Clone este repositório:
```bash
   git clone https://github.com/joaopaulo-cerquinhocajueiro/botao_e_led.git
   cd botao_e_led
```
2. Abra o projeto com o PlatformIO (VSCode) ou compile com o Arduino IDE.

3. Envie o código para um Arduino Uno.

4. Conecte o circuito conforme a tabela acima.

5. Ajuste as chaves do DIP switch e pressione o botão para ver diferentes comportamentos do LED.