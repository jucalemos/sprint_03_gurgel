const int sensorSolar = A0;
const int sensorDemanda = A1;

const int botao = 7;

const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;
const int ledAzul = 11;

const float limitePotencia = 10.0;
const float tarifa = 1.20;

bool sessaoAtiva = false;

unsigned long inicioSessao = 0;
unsigned long ultimoCalculo = 0;

float energiaTotal = 0;
float custoTotal = 0;

void setup() {

  pinMode(botao, INPUT_PULLUP);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  Serial.begin(9600);

  Serial.println("GURGEL - CHARGEGRID INTELLIGENCE");
  Serial.println("Pressione o botao para iniciar.");
}

void loop() {

  if (digitalRead(botao) == LOW) {

    sessaoAtiva = !sessaoAtiva;

    delay(300);

    if (sessaoAtiva) {

      inicioSessao = millis();
      ultimoCalculo = millis();

      energiaTotal = 0;
      custoTotal = 0;

      Serial.println();
      Serial.println("SESSAO INICIADA.");

    } else {

      Serial.println();
      Serial.println("SESSAO ENCERRADA.");

      Serial.print("Energia total: ");
      Serial.print(energiaTotal, 2);
      Serial.println(" kWh");

      Serial.print("Custo total: R$ ");
      Serial.println(custoTotal, 2);

      desligarLeds();
    }
  }

  if (sessaoAtiva) {

    int valorSolar = analogRead(sensorSolar);
    int valorDemanda = analogRead(sensorDemanda);

    float potenciaSolar = valorSolar * 12.0 / 1023.0;
    float demanda = valorDemanda * 15.0 / 1023.0;

    float potenciaLiberada;

    if (demanda > limitePotencia) {
      potenciaLiberada = limitePotencia;
    } else {
      potenciaLiberada = demanda;
    }

    float potenciaSolarUtilizada;

    if (potenciaSolar >= potenciaLiberada) {
      potenciaSolarUtilizada = potenciaLiberada;
    } else {
      potenciaSolarUtilizada = potenciaSolar;
    }

    float potenciaRede = potenciaLiberada - potenciaSolarUtilizada;

    unsigned long agora = millis();

    float tempoHoras = (agora - ultimoCalculo) / 3600000.0;

    energiaTotal = energiaTotal + (potenciaLiberada * tempoHoras);

    custoTotal = energiaTotal * tarifa;

    ultimoCalculo = agora;

    Serial.println("-----------------------------");

    Serial.print("Potencia solar: ");
    Serial.print(potenciaSolar, 1);
    Serial.println(" kW");

    Serial.print("Demanda: ");
    Serial.print(demanda, 1);
    Serial.println(" kW");

    Serial.print("Potencia liberada: ");
    Serial.print(potenciaLiberada, 1);
    Serial.println(" kW");

    Serial.print("Potencia da rede: ");
    Serial.print(potenciaRede, 1);
    Serial.println(" kW");

    Serial.print("Energia acumulada: ");
    Serial.print(energiaTotal, 2);
    Serial.println(" kWh");

    Serial.print("Custo acumulado: R$ ");
    Serial.println(custoTotal, 2);

    if (demanda > limitePotencia) {

      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledAzul, LOW);

      Serial.println("STATUS: SOBRECARGA");
      Serial.println("ACAO: POTENCIA LIMITADA.");

    } else if (potenciaSolar >= demanda && demanda > 0) {

      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);

      Serial.println("STATUS: ENERGIA SOLAR PRIORIZADA.");

    } else if (demanda >= 8.0) {

      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, LOW);

      Serial.println("STATUS: POTENCIA REDUZIDA.");

    } else {

      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, LOW);

      Serial.println("STATUS: CARREGAMENTO NORMAL.");
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
