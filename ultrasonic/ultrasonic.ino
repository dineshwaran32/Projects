const int t_pin = 9;
const int e_pin = 10;
long duration;
int dis_cm;

void setup() {
  // put your setup code here, to run once:
  pinMode(t_pin,OUTPUT);
  pinMode(e_pin,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(t_pin, LOW);
   delayMicroseconds(2);
   digitalWrite(t_pin, HIGH);
   delayMicroseconds(10);
   digitalWrite(t_pin, LOW);
   duration = pulseIn(e_pin,HIGH);
   dis_cm = (duration * 0.034) / 2;
   Serial.print("Distance (cm): ");
   Serial.println(dis_cm);
   delay(1000);
}
