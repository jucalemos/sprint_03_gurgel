const int sensorSolar = A0;
const int sensorDemanda = A1;

const int botao = 7;

const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;
const int ledAzul = 11;

const float limitePotencia = 10.0;

bool sessaoAtiva = false;

void setup() {
  pinMode(botao, INPUT_PULLUP);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  Serial.begin(9600);

  Serial.println("================================");
  Serial.println("           GURGEL");
  Serial.println("   CHARGEGRID INTELLIGENCE");
  Serial.println("================================");
  Serial.println("Pressione o botao para iniciar.");
}

void loop() {

  if (digitalRead(botao) == LOW) {
    sessaoAtiva = !sessaoAtiva;

    delay(300);

    if (sessaoAtiva) {
      Serial.println();
      Serial.println("Sessao de carregamento iniciada.");
    } else {
      Serial.println();
      Serial.println("Sessao de carregamento encerrada.");
      desligarLeds();
    }
  }

  if (sessaoAtiva) {

    int valorSolar = analogRead(sensorSolar);
    int valorDemanda = analogRead(sensorDemanda);

    float energiaSolar = valorSolar * 12.0 / 1023.0;
    float demanda = valorDemanda * 15.0 / 1023.0;

    float potenciaLiberada;

    if (demanda > limitePotencia) {
      potenciaLiberada = limitePotencia;
    } else {
      potenciaLiberada = demanda;
    }

    float energiaSolarUtilizada;

    if (energiaSolar >= potenciaLiberada) {
      energiaSolarUtilizada = potenciaLiberada;
    } else {
      energiaSolarUtilizada = energiaSolar;
    }

    float energiaRede = potenciaLiberada - energiaSolarUtilizada;

    Serial.println();
    Serial.println("--------------------------------");

    Serial.print("Energia solar: ");
    Serial.print(energiaSolar, 1);
    Serial.println(" kW");

    Serial.print("Demanda solicitada: ");
    Serial.print(demanda, 1);
    Serial.println(" kW");

    Serial.print("Potencia liberada: ");
    Serial.print(potenciaLiberada, 1);
    Serial.println(" kW");

    Serial.print("Energia solar utilizada: ");
    Serial.print(energiaSolarUtilizada, 1);
    Serial.println(" kW");

    Serial.print("Energia da rede: ");
    Serial.print(energiaRede, 1);
    Serial.println(" kW");

    if (demanda > limitePotencia) {

      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledAzul, LOW);

      Serial.println("STATUS: SOBRECARGA");
      Serial.println("ACAO: Redistribuicao de potencia");

    } else if (energiaSolar >= demanda && demanda > 0) {

      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);

      Serial.println("STATUS: ENERGIA SOLAR PRIORIZADA");

    } else if (demanda >= 8.0) {

      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, LOW);

      Serial.println("STATUS: POTENCIA REDUZIDA");

    } else {

      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, LOW);

      Serial.println("STATUS: CARREGAMENTO NORMAL");
    }

    delay(1000);
  }
}

void desligarLeds() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAzul, LOW);
}
