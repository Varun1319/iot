

int pushButton = 12;
int Relay = 8;

void setup() {
    // Set all pins as output
    Serial.begin(9600);
    pinMode(pushButton, INPUT);
    pinMode(Relay, OUTPUT);
}

void loop() {
    int buttonState = digitalRead(pushButton);

    if (buttonState == 1) {
        digitalWrite(Relay, HIGH);
    }
    else {
        digitalWrite(Relay, LOW);
    }

    Serial.println(buttonState);
    delay(100);
}
