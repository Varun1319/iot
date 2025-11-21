

int soil_pin = A1;

void setup() {
    pinMode(soil_pin, INPUT);
    Serial.begin(9600);
}

void loop() {
    int moisture_value = analogRead(soil_pin);

    Serial.print("Soil Moisture Value: ");
    Serial.println(moisture_value);

    delay(1000);
}
