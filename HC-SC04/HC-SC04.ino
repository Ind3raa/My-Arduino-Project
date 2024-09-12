#define trigPIN 13
#define echoPIN 12
#define ledM 11
#define ledK 10
#define ledH 9

void setup() {
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
  pinMode(ledM, OUTPUT);
  pinMode(ledK, OUTPUT);
  pinMode(ledH, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN, LOW);

  long duration;
  duration = pulseIn(echoPIN, HIGH);

  float distance;
  distance = (duration * 0.0343)/2;
  Serial.println(distance);
  delay(1000);

  if (distance <= 10) {
    digitalWrite(ledH, HIGH);
    digitalWrite(ledK, HIGH);
    digitalWrite(ledM, HIGH);
  } else if (distance <= 30) {
    digitalWrite(ledH, HIGH);
    digitalWrite(ledK, HIGH);
    digitalWrite(ledM, LOW);
  } else if (distance <= 50) {
    digitalWrite(ledH, HIGH);
    digitalWrite(ledK, LOW);
    digitalWrite(ledM, LOW);
  } else {
    digitalWrite(ledH, LOW);
    digitalWrite(ledK, LOW);
    digitalWrite(ledM, LOW);
  }
}
