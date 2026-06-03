#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// GPS Module Connections
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// GSM Module Connections
static const int GSM_RX = 8, GSM_TX = 7;
static const uint32_t GSMBaud = 9600;

// Create instances
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);
SoftwareSerial gsmSerial(GSM_RX, GSM_TX);

// Emergency Contact
String emergencyNumber = "+1234567890"; // Replace with actual number

// Emergency Trigger Pin (e.g., a button or sensor)
const int triggerPin = 2; 

void setup() {
  Serial.begin(9600);
  
  pinMode(triggerPin, INPUT_PULLUP); // Assuming button connects to GND

  // Initialize GPS Serial
  gpsSerial.begin(GPSBaud);
  Serial.println("GPS Module Initialized");

  // Initialize GSM Serial
  gsmSerial.begin(GSMBaud);
  Serial.println("GSM Module Initialized");
  delay(1000);
  
  // Setup GSM
  gsmSerial.println("AT");
  delay(1000);
  gsmSerial.println("AT+CMGF=1"); // Set SMS to Text Mode
  delay(1000);
}

void loop() {
  // Read GPS data
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  // Check for emergency trigger (LOW if button pressed using INPUT_PULLUP)
  if (digitalRead(triggerPin) == LOW) {
    Serial.println("Emergency Triggered!");
    sendEmergencySMS();
    delay(5000); // Debounce / prevent multiple SMS rapidly
  }
}

void sendEmergencySMS() {
  String locationLink = "https://maps.google.com/?q=";
  
  if (gps.location.isValid()) {
    locationLink += String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
  } else {
    locationLink = "Location unavailable. GPS searching...";
  }

  Serial.println("Sending SMS to: " + emergencyNumber);
  Serial.println("Message: " + locationLink);

  gsmSerial.println("AT+CMGS=\"" + emergencyNumber + "\"");
  delay(1000);
  
  gsmSerial.print("Emergency Alert!\n\nLocation:\n");
  gsmSerial.print(locationLink);
  delay(100);
  
  gsmSerial.write(26); // ASCII code for CTRL+Z to send SMS
  delay(3000);
  
  Serial.println("SMS Sent!");
}
