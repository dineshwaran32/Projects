#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

#define RST_PIN 9
#define SS_PIN 10

int voice1 = 8;
int voice2 = 7;
int voice3 = 6;


MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  Wire.begin();
  pinMode(voice1, OUTPUT);
  pinMode(voice2, OUTPUT);
  pinMode(voice3, OUTPUT);

  
  mfrc522.PCD_Init();
  Serial.println("RFID Ready!");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("UID tag :");
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  Serial.println(content.substring(1));
  if (content.substring(1) == "D3 A7 8E F5")
  {
    digitalWrite(voice1, LOW);
    digitalWrite(voice2, HIGH);
    digitalWrite(voice3, HIGH); 
  }
  else if (content.substring(1) == "40 74 D6 14")
  {
    digitalWrite(voice1, HIGH);
    digitalWrite(voice2, LOW);
    digitalWrite(voice3, HIGH);
  }
   else if (content.substring(1) == "30 CB CB 14")
  {
    digitalWrite(voice1, HIGH);
    digitalWrite(voice2, LOW);
    digitalWrite(voice3, HIGH);
  }
 else 
  {
    digitalWrite(voice1, HIGH);
    digitalWrite(voice2, HIGH);
    digitalWrite(voice3, HIGH);
  }


  delay(2000);
}
