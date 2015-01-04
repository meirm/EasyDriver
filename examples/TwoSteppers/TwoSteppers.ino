
#define startButton 2
#define ledPin 13

#include <EasyDriver.h>

#define DEBUG 1
// Define two steppers and the pins they will use
int dirPinM1 = 3;
int stepPinM1 = 2;
int dirPinM2 = 7;
int stepPinM2 = 6;
int enaPinM1=14;
int enaPinM2=16;
#define WaitBetweenPulse 200


EasyStepper stepper1(stepPinM1, dirPinM1,enaPinM1);
EasyStepper stepper2(stepPinM2, dirPinM2,enaPinM2);

long MoveEachOne=1000;

void setup()

{  
 
}



void loop(){
  for (int i=0;i<MoveEachOne*2;i++){
      stepper1.halfstep();
      stepper2.halfstep();
      delay(WaitBetweenPulse);
  }
  stepper1.dir(1- stepper1.dir());
  stepper2.dir(1- stepper2.dir());
  
   stepper1.step(MoveEachOne,stepper1.dir(),WaitBetweenPulse);
   stepper1.step(MoveEachOne,stepper1.dir(),WaitBetweenPulse);
       
  stepper1.dir(1- stepper1.dir());
  stepper2.dir(1- stepper2.dir());
}





