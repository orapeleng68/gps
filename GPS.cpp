#include <HardwareSerial.h>
#include <TinyGPS++.h>

// GPS module connected to Serial2 (RX = GPIO16, TX = GPIO17)
static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
HardwareSerial GPS_Serial(2);

void setup() {
  Serial.begin(115200);
  GPS_Serial.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);
}

void loop() {
  while (GPS_Serial.available()) {
    gps.encode(GPS_Serial.read());
  }
  
  if (gps.location.isUpdated()) {
    Serial.print("Latitude: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(" | Longitude: ");
    Serial.println(gps.location.lng(), 6);
  }
}
