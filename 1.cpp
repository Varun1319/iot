

void setup() {
    // put your setup code here, to run once:
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:

    digitalWrite(A2, HIGH);
    delay(1000);
    digitalWrite(A2, LOW);
    delay(1000);

    digitalWrite(A3, HIGH);
    delay(1000);
    digitalWrite(A3, LOW);
    delay(1000);

    digitalWrite(A4, HIGH);
    delay(1000);
    digitalWrite(A4, LOW);
    delay(1000);

    digitalWrite(A5, HIGH);
    delay(1000);
    digitalWrite(A5, LOW);
    delay(1000);

    digitalWrite(11, HIGH);
    delay(1000);
    digitalWrite(11, LOW);
    delay(1000);

    digitalWrite(A5, HIGH);
    delay(1000);
    digitalWrite(A5, LOW);
    delay(1000);

    digitalWrite(A4, HIGH);
    delay(1000);
    digitalWrite(A4, LOW);
    delay(1000);

    digitalWrite(A3, HIGH);
    delay(1000);
    digitalWrite(A3, LOW);
    delay(1000);
}
