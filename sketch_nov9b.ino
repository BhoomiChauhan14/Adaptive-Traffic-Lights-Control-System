int red = 8;      // red LED connected to pin 8
int yellow = 10;  // yellow LED connected to pin 10
int green = 12;   // green LED connected to pin 12
char signal;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    signal = Serial.read();

    if (signal == 'R') {
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
    }
    else if (signal == 'Y') {
      digitalWrite(yellow, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
    }
    else if (signal == 'G') {
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
    }
    else if (signal == 'X') {  // all OFF
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
    }
  }
}


