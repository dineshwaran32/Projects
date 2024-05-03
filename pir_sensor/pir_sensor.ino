 
int led = 5;                
int sensor = 2;              
int state = LOW;             
int val = 0;                 

void setup() {
  pinMode(led, OUTPUT);      
  pinMode(sensor, INPUT);    
  Serial.begin(9600);        
}

void loop(){
  val = digitalRead(sensor);  
  int value_ldr = analogRead(A0); // read LDR value
  Serial.println(val);
  Serial.print("value");
  Serial.println(value_ldr); 
  if ((15>value_ldr) &&(val == HIGH)) {           
    digitalWrite(led, HIGH);   
                 
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;      
    }
  } 
  else {
      digitalWrite(led, LOW); 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       
    }
  }
 delay(1000);
}
