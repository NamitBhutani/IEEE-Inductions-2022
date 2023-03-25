#define buzzer 2
#define led 9
#define ldr A5
long int setpoint;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop() {
  int lightRaw = analogRead(ldr);
  int light = map(lightRaw, 1023, 0, 10, 0);
  if (light < 5) {
    long int setpoint = Serial.parseInt();
    Serial.println(setpoint);
    int setpointmap = map(setpoint, 2, 336, 0, 255);

    if (setpoint < 88) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, LOW);
      delay(1000);
      digitalWrite(led, HIGH);
    } 
    else {
      digitalWrite(buzzer, LOW);
      analogWrite(led, -setpointmap);
    }
  } 
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }

}
