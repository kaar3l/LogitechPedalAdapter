//Simple Logitech pedals adapter for Arduino Leonardo
//DB9           Arduino
//Pin1 - GND - GND
//Pin2 - Throttle - A2
//Pin3 - Brake - A1
//Pin4 - Clutch - A0
//Pin6 - 5V
//Pin9 - 5V
//
//DB9 connector plug facing away
//    -------------------------
//    |    \  1 2 3 4 5  /    |
//    |     \  6 7 8 9  /     |
//    -------------------------
//
#include "Joystick.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_MULTI_AXIS, 0, 0,
  false, false, false, false, false, false,
  false, false, true, true, true);

int AccelPin = A2;
int AccelValue = 0;
int BrakePin = A1;
int BrakeValue = 0;
int SteerPin = A0;
int SteerValue = 0;

void setup() {
  Joystick.begin();

  Joystick.setAcceleratorRange(0, 1023);
  Joystick.setBrakeRange(0, 1023);
  Joystick.setSteeringRange(0, 1023);
}

void loop() {
  AccelValue=analogRead(AccelPin);
  BrakeValue=analogRead(BrakePin);
  SteerValue=analogRead(SteerPin);

  Joystick.setAccelerator(AccelValue);
  Joystick.setBrake(BrakeValue);
  Joystick.setSteering(SteerValue);
}
