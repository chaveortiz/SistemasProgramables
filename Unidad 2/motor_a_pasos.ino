#include <Stepper.h>

Stepper stepper(200, 8,9,10,11);
void setup() {
  stepper.setSpeed(60); 
}

void loop() {
  stepper.step(200);
  delay(1000);
   stepper.step(-200);
  delay(1000);
}

