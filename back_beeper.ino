const int LEDPIN = 4;
const int BUZZERPIN = 5;
const int TRIGPIN = 9;
const int ECHOPIN = 10;

double distance;
unsigned long duration;
int frequency;
int delaytime;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  duration = pulseIn(ECHOPIN, HIGH, 30000);
  if (duration == 0) {
    Serial.println("No echo received");
    return;
  }
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance / 100); // Convert to meters
  Serial.println(" m");

  frequency = 1000;
  delaytime = 1300;
  if (distance < 90 && distance >= 70) {
    frequency += 300;
    delaytime -= 300;
  } else if (distance < 70 && distance >= 50) {
    frequency += 500;
    delaytime -= 600;
  } else if (distance < 50 && distance >= 30) {
    frequency += 1000;
    delaytime -= 800;
  } else if (distance < 30 && distance >= 10) {
    frequency += 1500;
    delaytime -= 1000;
  } else if (distance <= 10) {
    frequency += 2000;
    delaytime = max(delaytime - 100, 100);
  }

  digitalWrite(LEDPIN, HIGH);
  tone(BUZZERPIN, frequency);
  delay(100);
  noTone(BUZZERPIN);
  digitalWrite(LEDPIN, LOW);

  delay(max(delaytime, 100));
}

 