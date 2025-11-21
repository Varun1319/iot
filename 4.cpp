// Program to control a DC motor with Arduino using ultrasonic sensor

const int trigPin = 6;
const int echoPin = 7;
const int buzzer  = 9;

double timing = 0.0;
double distance = 0.0;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzer, OUTPUT);

    digitalWrite(trigPin, LOW);
    digitalWrite(buzzer, LOW);

    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    timing = pulseIn(echoPin, HIGH);
    distance = (timing * 0.034) / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | ");
    Serial.print(distance / 2.54);
    Serial.println(" in");

    if (distance <= 5) {
        tone(buzzer, 1000);
    } else {
        noTone(buzzer);
    }

    delay(100);
}
