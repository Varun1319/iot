

#include <SoftwareSerial.h>

#define PH_RX   4
#define PH_TX   5
#define PH_ANALOG A0

float acidVoltage    = 3.00;   // voltage for pH ~ 4 (example from notes)
float neutralVoltage = 2.50;   // voltage for pH ~ 7 (example from notes)

SoftwareSerial phSerial(PH_RX, PH_TX);

void setup() {
  Serial.begin(9600);
  phSerial.begin(9600);
  Serial.println("Starting PH Sensor Test (Analog + UART)");
}

void loop() {

  int sensorValue = analogRead(PH_ANALOG);
  float voltage = sensorValue * (5.0 / 1023.0);

  
  float slope = (7.0 - 4.0) / (neutralVoltage - acidVoltage);

  float pHvalue = 7.0 - slope * (voltage - neutralVoltage);

  Serial.print("Analog Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V | pH: ");
  Serial.println(pHvalue, 2);

  // --- UART (digital) read from pH module if available ---
  if (phSerial.available()) {
    String phData = phSerial.readStringUntil('\n');
    Serial.print("[UART] Raw Data: ");
    Serial.println(phData);
  } else {
    Serial.println("[UART] No data received");
  }

  Serial.println("----");
  delay(1000);
}
