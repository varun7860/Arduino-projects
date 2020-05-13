#include <Stepper.h>
int StepsRequired;

const float STEPS_PER_REV =32;
const float GEAR_RED =64;
const float STEPS_PER_OUT_REV =STEPS_PER_REV*GEAR_RED;

Stepper steppermotor(STEPS_PER_REV,4,6,5,7);

void setup() 
{
 
}

void loop() 
{
  steppermotor.setSpeed(1);
  StepsRequired =4;
  steppermotor.step(StepsRequired);
  delay(2000);

  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotor.setSpeed(1000);   
  steppermotor.step(StepsRequired);
  delay(1000);

  StepsRequired  =  - STEPS_PER_OUT_REV / 2;   
  steppermotor.setSpeed(700);  
  steppermotor.step(StepsRequired);
  delay(2000);

}
