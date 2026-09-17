int sensorSolar = A0;
int sensorDemanda = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int solar = analogRead(sensorSolar);
  int demanda = analogRead(sensorDemanda);

  Serial.print("Solar: ");
  Serial.print(solar);

  Serial.print(" | Demanda: ");
  Serial.println(demanda);

  delay(500);
}
