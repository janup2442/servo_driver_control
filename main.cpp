#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600 
#define SERVO_FREQ 50 

void setup() {
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
}

void loop() {
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    for (uint8_t servonum = 0; servonum < 16; servonum++) {
      pwm.setPWM(servonum, 0, pulselen);
    }
  }

  delay(500);

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    for (uint8_t servonum = 0; servonum < 16; servonum++) {
      pwm.setPWM(servonum, 0, pulselen);
    }
  }

  delay(500);
}
