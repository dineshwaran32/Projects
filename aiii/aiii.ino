const int redPin = 2;
const int greenPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  
    if (Serial.available() > 0) {
    char msg = Serial.read();
    if (msg == 'H'){
      digitalWrite(greenPin, HIGH);
    }
    else if (msg == 'O'){
      digitalWrite(greenPin, LOW);
    }
    else {
      for (int i = 0; i < 5; i++){
        digitalWrite(redPin, HIGH);
        delay(100);
        digitalWrite(redPin, LOW);
        delay(100);
      }
    }
  
}
}
