#include <Servo.h>
#define x_axe A1
#define y_axe A5
#define button A3
#define laser A7
Servo monServo;  
Servo monServo_2;
void setup() {
  pinMode(x_axe,INPUT);
  pinMode(y_axe,INPUT);
  pinMode(button,INPUT_PULLUP);
  pinMode(laser,OUTPUT);
  Serial.begin(9600);
  monServo.attach(23);
  monServo_2.attach(22);
}

void loop() {
  float y_numb = analogRead(y_axe);
  float x_numb = analogRead(x_axe);
  int laser_on = digitalRead(button);
  int x_pos = x_numb/5.68;
  int y_pos = y_numb/5.68;
  monServo.write(x_pos);
  monServo_2.write(y_pos);
  Serial.println(x_pos);
  Serial.println(y_pos);
  Serial.println(laser_on);
  delay(250);
  if (laser_on == 1) {
    digitalWrite(laser, LOW);
  }
  else {
    digitalWrite(laser, HIGH);
  }
}
