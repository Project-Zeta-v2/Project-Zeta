#include <LobotServoController.h>
#include "config.h"
#include "functions.h"
//#include "serial_servo.h"

const int time = 3000;

void setup() {
  if (Debug != 1) {
    pinMode(13, OUTPUT);
  }
  if (Debug != 1) {
    digitalWrite(13, LOW);
  }
  else if (Debug == 1) {
    digitalWrite(13, HIGH);
  }

  Serial.begin(57600);
  Serial1.begin(9600);
  Serial2.begin(115200);

  delay(1000);

  reset_motors(3000);
  home(3000);
  delay(3000);

  IK_out ik = IK(0, 0, 23);
  int pos = degToPos(ik.m2, FR2);
  int pos1 = degToPos(ik.m1, FR1);
  int pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR3, pos2, time);

  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);

  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);

  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL3, pos2, time);
  delay(time);


  ik = IK(15, 0, 20);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR3, pos2, time);


  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);
  delay(time);

  ik = IK(15, 0, 30);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);
  delay(time);


}

void loop() {
  // put your main code here, to run repeatedly:
}
