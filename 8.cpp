

const int mq2pin = A0;
const int smokeThreshold = 100;

void setup() {
    Serial.begin(9600);
    pinMode(mq2pin, INPUT);
}

void loop() {
    int sensorValue = analogRead(mq2pin);
    float voltage = sensorValue * (5.0 / 1023.0);

    Serial.print("Sensor Value: ");
    Serial.print(sensorValue);
    Serial.print(" | Voltage: ");
    Serial.print(voltage);

    if (sensorValue > smokeThreshold) {
        Serial.println(" | Smoke Detected!");
    } else {
        Serial.println(" | Clear!!");
    }

    delay(1000);
}
