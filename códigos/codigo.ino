#define TRIGGER_PIN 13     
#define ECHO_PIN 12        
#define BUTTON_PIN 14 
#define BUZER 23   
#define PIR 22

long duration;             
int distancia;             
int contador = 0;          

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN, OUTPUT);    
  pinMode(ECHO_PIN, INPUT);        
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  pinMode(BUZER, OUTPUT);
  pinMode(PIR, INPUT);

  Serial.println("Sistema de Monitoramento de Dispenser Iniciado");
}

void loop() {
  // Gera um pulso de 10 microssegundos no pino Trigger para iniciar a medição
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Lê a duração do pulso no pino Echo
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calcula a distância em centímetros
  distancia = duration * 0.034 / 2;

  digitalWrite(BUZER, LOW);
        

  if (distancia > 0 && distancia <= 20 && digitalRead(PIR) == HIGH) {  //detecta até 20 cm
    Serial.println("Pessoa detectada próxima ao dispenser");

    // Verifica se o botão foi pressionado para simular o uso do dispenser
    if (digitalRead(BUTTON_PIN) == LOW) { // LOW indica que o botão foi pressionado
      delay(50); // debounce 
      if (digitalRead(BUTTON_PIN) == LOW) {
        contador++; // Incrementa o contador de usos do dispenser
        Serial.print("Dispenser utilizado. Total de usos: ");
        Serial.println(contador);
        digitalWrite(BUZER, HIGH);
        
        while (digitalRead(BUTTON_PIN) == LOW);
      }
    }
  }

  delay(100);  // Aguarda um pouco antes da próxima verificação
}
