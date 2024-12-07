# Sistema de Monitoramento de Dispenser com ESP32

Este projeto utiliza um microcontrolador ESP32 para monitorar o uso de um dispenser com sensores de proximidade e movimento. O sistema detecta a presença de uma pessoa próxima ao dispenser usando um sensor ultrassônico (HC-SR04) e um sensor de movimento PIR. Quando uma pessoa se aproxima e o botão do dispenser é pressionado, o sistema incrementa um contador de uso e ativa um buzzer e acende um LED para indicar que o dispenser foi utilizado.

## Funcionalidade

- **Sensor Ultrassônico:** Utiliza o sensor HC-SR04 para medir a distância entre o dispenser e qualquer objeto próximo, detectando pessoas a uma distância de até 20 cm.
- **Sensor PIR:** Detecta movimento na área ao redor do dispenser.
- **Botão de Dispenser:** Simula o uso do dispenser. Quando pressionado, incrementa o contador de uso do dispenser.
- **Buzzer:** Acende o buzzer quando o dispenser é utilizado para fornecer feedback sonoro.
- **Contador de Usos:**  Incrementa e exibe o número de vezes que o dispenser foi utilizado.
- **LED:** Acende quando o dispenser é utilizado para fornecer um feedback visual.

## Componentes Necessários 

- ESP32 (ou outro microcontrolador compatível).
- Sensor Ultrassônico HC-SR04:
- Sensor PIR (detecção de movimento).
- Botão (para simular o uso do dispenser).
- Buzzer (para feedback sonoro).
- Fios de conexão e protoboard para montagem.
- Leds (para feedback visual).

## Pinagem

### Print do circuito: 
<div>
  <img align="center" height "200em" src="https://github.com/user-attachments/assets/a4a5a1e6-bae1-4862-b123-6b75949c0000" width="500"/>
<div>


- TRIGGER_PIN: Pino 13 (Envia o pulso para o sensor ultrassônico).
- ECHO_PIN: Pino 12 (Recebe o pulso refletido pelo sensor ultrassônico).
- BUTTON_PIN: Pino 14 (Botão de disparo do dispenser).
- BUZZER: Pino 23 (Buzzer de feedback).
- PIR: Pino 22 (Sensor de movimento).
- LED: Pino 23

## Como Funciona
1. O código utiliza o sensor ultrassônico HC-SR04 para medir a distância entre o sensor e um objeto. Quando a distância é menor ou igual a 20 cm e o sensor PIR detecta movimento, o sistema começa a monitorar o botão.
2. Quando o botão é pressionado, o sistema incrementa o contador de usos do dispenser e ativa o buzzer como confirmação de que o dispenser foi utilizado.
3. O número total de usos do dispenser é impresso no monitor serial.

## Instalação

1. Clone o repositório para o seu computador:

```cpp
git clone git@github.com:amandaabarbosa98/monitoramento-lavagem-de-m-os.git
```

2. Abra o arquivo codigo.ino no Arduino IDE.
3. Instale as bibliotecas necessárias:
- Caso não tenha a biblioteca para o ESP32 instalada, adicione o pacote de placas ESP32 ao Arduino IDE:
- Vá em Arquivo > Preferências e adicione o seguinte URL no campo "URLs adicionais para gerenciadores de placas":

```bash
https://dl.espressif.com/dl/package_esp32_index.json
```
- Depois, vá em Ferramentas > Placa > Gerenciador de Placas e instale o pacote esp32.

4. Configure o ESP32 no Arduino IDE:
- Vá em Ferramentas > Placa e selecione o modelo de sua placa ESP32.
- Selecione a porta correta no menu Ferramentas > Porta.

5. Carregue o código no seu ESP32:

- Clique no botão de upload no Arduino IDE para carregar o código no ESP32.

## Simulação

Link da simulação: https://wokwi.com/projects/416622300755868673

## Contribuições
Se você deseja contribuir para este projeto, sinta-se à vontade para criar um fork, fazer alterações e enviar um pull request com suas melhorias!
