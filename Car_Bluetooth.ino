//    Bluetooth controled car code
#include <SoftwareSerial.h>

char t;
// SoftwareSerial bluetooth(2, 3); // RX, TX

// #define ENA 5   // Motor A enable pin
// #define ENB 6  // Motor B enable pin

void setup() {

  Serial.begin(9600);
  pinMode(4, OUTPUT);  //  left backward
  pinMode(5, OUTPUT);  //  left forward
  pinMode(6, OUTPUT);  //  right forward
  pinMode(8, OUTPUT);  //  right backward

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }


 

  // if (Serial.available() > 0) {
  //   int speed = bluetooth.read();
  //   Serial.println(bluetooth.read());
  //   analogWrite(ENA, speed);
  //   analogWrite(ENB, speed);
  // }



if (t == 'F') {  //move  forward(all motors rotate in forward direction)
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
}

else if (t == 'G') {  //move reverse (all  motors rotate in reverse direction)
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, HIGH);
}

else if (t == 'L') {  //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
}

else if (t == 'R') {  //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, HIGH);
}

else if (t == 'W') {  //turn led on or off)
  digitalWrite(9, HIGH);
} else if (t == 'w') {
  digitalWrite(9, LOW);
}

else if (t == 'S') {  //STOP (all motors stop)
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
}
delay(100);
}