#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(8, 7); // RX, TX

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
  
  Serial.println("GSM Test Start.");
  Serial.println("Type AT commands in Serial Monitor.");
}

void loop() {
  if (gsmSerial.available()) {
    Serial.write(gsmSerial.read());
  }
  if (Serial.available()) {
    gsmSerial.write(Serial.read());
  }
}
