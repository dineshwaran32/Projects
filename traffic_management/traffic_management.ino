#define t_pin1 2
#define e_pin1 3
#define t_pin2 4
#define e_pin2 5
#define t_pin3 6
#define e_pin3 7


const int greenLight1 = A0;
const int yellowLight1 = A1;
const int redLight1 = A2;


const int greenLight2 = 10;
const int yellowLight2 = 9;
const int redLight2 = 8;


const int greenLight3 = 13;
const int yellowLight3 = 12;
const int redLight3 = 11;



long duration1;
long duration2;
long duration3;
int dis1;
int dis2;
int dis3;

void setup() {
  pinMode(t_pin1, OUTPUT);
  pinMode(e_pin1, INPUT);
  pinMode(t_pin2, OUTPUT);
  pinMode(e_pin2, INPUT);
  pinMode(t_pin3, OUTPUT);
  pinMode(e_pin3, INPUT);

  pinMode(greenLight1, OUTPUT);
  pinMode(yellowLight1, OUTPUT);
  pinMode(redLight1, OUTPUT);
  pinMode(greenLight2, OUTPUT);
  pinMode(yellowLight2, OUTPUT);
  pinMode(redLight2, OUTPUT);
  pinMode(greenLight3, OUTPUT);
  pinMode(yellowLight3, OUTPUT);
  pinMode(redLight3, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(t_pin1, LOW);
  delayMicroseconds(2);
  digitalWrite(t_pin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(t_pin1, LOW);
  duration1 = pulseIn(e_pin1, HIGH);
  dis1 = (duration1 * 0.034) / 2;

  digitalWrite(t_pin2, LOW);
  delayMicroseconds(2);
  digitalWrite(t_pin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(t_pin2, LOW);
  duration2 = pulseIn(e_pin2, HIGH);
  dis2 = (duration2 * 0.034) / 2;

  digitalWrite(t_pin3, LOW);
  delayMicroseconds(2);
  digitalWrite(t_pin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(t_pin3, LOW);
  duration3 = pulseIn(e_pin3, HIGH);
  dis3 = (duration3 * 0.034) / 2;

  Serial.print("Distance 1: ");
  Serial.println(dis1);
  Serial.print("Distance 2: ");
  Serial.println(dis2);
  Serial.print("Distance 3: ");
  Serial.println(dis3);

  
  for (int i = 0; i < 3; i++) {
    if (dis1 < dis2 && dis1 < dis3) 
    {
      
      // Light sequence for traffic light 1
      digitalWrite(greenLight1, HIGH);
      digitalWrite(yellowLight1, LOW);
      digitalWrite(redLight1, LOW);

      if(dis2<dis3)
      {
        digitalWrite(greenLight2, LOW);
        digitalWrite(yellowLight2, HIGH);
        digitalWrite(redLight2, LOW);
      }
      else
      {
        digitalWrite(greenLight3, LOW);
        digitalWrite(yellowLight3, LOW);
        digitalWrite(redLight3, HIGH);
      }

      if(dis3<dis2)
      {
        digitalWrite(greenLight3, LOW);
        digitalWrite(yellowLight3, HIGH);
        digitalWrite(redLight3, LOW);
      }
      else
      {
        digitalWrite(greenLight2, LOW);
        digitalWrite(yellowLight2, LOW);
        digitalWrite(redLight2, HIGH);
      }
      delay(3000);
      dis1 = 0;
      
    } 
    else if(dis2 < dis1 && dis2 < dis3) 
    {
      
      // Light sequence for traffic light 2
      digitalWrite(greenLight2, HIGH);
      digitalWrite(yellowLight2, LOW);
      digitalWrite(redLight2, LOW);
      
      if(dis1 < dis3)
      {
        digitalWrite(greenLight1, LOW);
        digitalWrite(yellowLight1, HIGH);
        digitalWrite(redLight1, LOW);
      }
      else
      {
        digitalWrite(greenLight3, LOW);
        digitalWrite(yellowLight3, LOW);
        digitalWrite(redLight3, HIGH);
      }

      if(dis3 < dis1)
      {
        digitalWrite(greenLight3, LOW);
        digitalWrite(yellowLight3, HIGH);
        digitalWrite(redLight3, LOW);
      }
      else
      {
        digitalWrite(greenLight1, LOW);
        digitalWrite(yellowLight1, LOW);
        digitalWrite(redLight1, HIGH);
      }
      delay(3000);
      dis2 = 0;
    }
    else
    {
      digitalWrite(greenLight3, HIGH);
      digitalWrite(yellowLight3, LOW);
      digitalWrite(redLight3, LOW); 
      
      if(dis1 < dis2)
      {
        digitalWrite(greenLight1, LOW);
        digitalWrite(yellowLight1, HIGH);
        digitalWrite(redLight1, LOW);             
      }
      else
      {
        digitalWrite(greenLight2, LOW);
        digitalWrite(yellowLight2, LOW);
        digitalWrite(redLight2, HIGH);
      }

      if(dis2 < dis1)
      {
        digitalWrite(greenLight2, LOW);
        digitalWrite(yellowLight2, HIGH);
        digitalWrite(redLight2, LOW);             
      }
      else
      {
        digitalWrite(greenLight1, LOW);
        digitalWrite(yellowLight1, LOW);
        digitalWrite(redLight1, HIGH);
      }
      delay(3000);
    }
  }

  

  delay(5000);
}
