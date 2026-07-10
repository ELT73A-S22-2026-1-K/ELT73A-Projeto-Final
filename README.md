# Incubadora Inteligente com STM32 e Arduino

##  Descrição

Este projeto consiste em uma incubadora inteligente desenvolvida utilizando um microcontrolador *STM32* para realizar o controle de temperatura e um *Arduino Uno* responsável pela interface com um display LCD gráfico.

O sistema realiza a leitura da temperatura interna através de um *termistor NTC*, converte essa leitura utilizando o conversor analógico-digital (ADC) do STM32 e controla automaticamente um cooler por meio de um sinal PWM.

Além disso, o STM32 envia a temperatura atual e a temperatura de referência ao Arduino, que exibe essas informações em um display LCD.

---

##  Objetivos

- Monitorar a temperatura da incubadora.
- Controlar automaticamente a ventilação.
- Exibir informações em tempo real no display LCD.
- Aplicar conceitos de sistemas embarcados utilizando STM32.

---

# Componentes utilizados

- STM32 Black Pill
- Arduino Uno
- Display LCD gráfico ST7920 (128x64)
- Termistor NTC 10 kΩ
- Cooler 12 V
- MOSFET IRLZ44N
- Resistores
- Fonte de alimentação
- Protoboard e jumpers

---

# Funcionamento

O funcionamento do sistema ocorre na seguinte sequência:

1. O termistor mede a temperatura da incubadora.
2. O STM32 realiza a leitura da tensão utilizando o ADC.
3. O valor é convertido para temperatura em graus Celsius.
4. A temperatura medida é comparada com a temperatura de referência.
5. Caso necessário, o STM32 controla a velocidade do cooler utilizando PWM.
6. A temperatura atual e a temperatura desejada são enviadas ao Arduino.
7. O Arduino exibe essas informações no display LCD.

---

# Principais conceitos utilizados

## ADC (Conversor Analógico-Digital)

Responsável por converter a tensão analógica proveniente do termistor em um valor digital para processamento pelo STM32.

---

## PWM (Pulse Width Modulation)

Utilizado para controlar a velocidade do cooler, permitindo maior eficiência no controle da temperatura.

---

## Termistor NTC

Sensor cuja resistência varia de acordo com a temperatura.

A resistência medida é convertida para temperatura utilizando a equação Beta do termistor.

---

## Comunicação STM32 → Arduino

A comunicação entre os microcontroladores é realizada através de dois pinos digitais:

- Clock
- Dados

O STM32 envia bit a bit a temperatura atual e a temperatura desejada.

O Arduino recebe essas informações e reconstrói os valores para exibição no display.

---

# Estrutura do projeto


Projeto
│
├── STM32
│   └── Código responsável pelo controle da incubadora
│
├── Arduino
   └── Código responsável pelo display LCD



---

# Fluxograma


Termistor (NTC)
        │
        ▼
      ADC (STM32)
        │
        ▼
Conversão para °C
        │
        ▼
Comparação com temperatura desejada
        │
        ▼
Controle PWM
        │
        ▼
Cooler
        │
        ▼
Envio dos dados ao Arduino
        │
        ▼
Display LCD


---

# Tecnologias utilizadas

- Linguagem C
- STM32CubeIDE
- STM32 HAL
- Arduino IDE
- Biblioteca U8g2

---

# Autores

Gabriel Henrique
Cauã Ribaski
