

// Pin definitions
const int trig_pin = 6;    // Trigger pin for ultrasonic
const int echo_pin = 7;    // Echo pin for ultrasonic
const int buzzer  = 9;     // Buzzer connected to pin 9

// Variables
long timing;
int distance;

void setup() {
    pinMode(echo_pin, INPUT);
    pinMode(trig_pin, OUTPUT);
    pinMode(buzzer, OUTPUT);

    digitalWrite(trig_pin, LOW);
    digitalWrite(buzzer, LOW);

    Serial.begin(9600);
}

void loop() {
    // Clear the trig pin
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);

    // Trigger the sensor
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);

    // Measure the echo response
    timing = pulseIn(echo_pin, HIGH);

    // Convert time into distance (in cm)
    distance = (timing * 0.034) / 2;

    // Print distance in cm and inches
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | ");
    Serial.print(distance / 2.54);
    Serial.println(" in");

    // Buzzer alert if object is closer than 5 cm
    if (distance <= 5) {
        tone(buzzer, 1000);     // Play buzzer at 1kHz
    } else {
        noTone(buzzer);         // Stop buzzer
    }

    delay(500);    // Small delay between readings
}
