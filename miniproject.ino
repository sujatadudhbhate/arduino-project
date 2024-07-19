#define trig 9
#define echo 8
#include <Servo.h>
Servo myServo;


void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(4, INPUT);
  myServo.attach(5);
}

void loop() {

  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  long dur = pulseIn(echo, HIGH);
  int distance = dur * 0.034 / 2;

  Serial.print("distance");
  Serial.println(distance);
  delay(500);

  if (distance > 0 && distance < 20) {
    myServo.write(0);
  } else if (distance > 20 && distance < 60) {
    myServo.write(90);
  } else  // if(distance>60 && distance <100)
  {
    myServo.write(180);
  }
  /*else
  Serial.println("motion not detected");
   delay(2000);*/
}
// put your main code here, to run repeatedly:
