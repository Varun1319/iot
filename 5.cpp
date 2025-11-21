

const int sensorPin = A0;
const int ledPin = 11;

int lightInit;
int lightVal;

void setup() {
    pinMode(ledPin, OUTPUT);
    lightInit = analogRead(sensorPin);
}

void loop() {
    lightVal = analogRead(sensorPin);

    if (lightVal - lightInit < 100) {
        digitalWrite(ledPin, LOW);
    }
    else {
        digitalWrite(ledPin, HIGH);
    }
}
