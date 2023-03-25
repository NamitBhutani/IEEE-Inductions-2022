short duration, cm;
char cmchar[5];
#define echoPin A0
#define trigPin A1

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    cm = msTocm(duration);
    sprintf(cmchar, "%d", cm);
    Serial.write(cmchar);
    Serial.println();
    delay(100);
  } 




int msTocm(long microseconds) {
  return microseconds / 29 / 2;
};
