#pragma config(StandardModel, "RVW CLAWBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "PID.c"

struct PIDConstants drivetrainConsts;


struct PIDState drivetrainState;

int timeStepMs = 500;
float pos = 0;
float goal = 1000;
float voltage = 0;

task main()
{
	drivetrainConsts.kP = 1;
	drivetrainConsts.kI = 0.1;
	drivetrainConsts.kD = 0.01;
	datalogClear();

  int loopNum = 1;
  while(true){
  	pos = SensorValue[leftEncoder];
    float error = goal-pos;
    voltage = iterate(error, &drivetrainConsts, &drivetrainState);

    datalogDataGroupStart();
    datalogAddValue(1, loopNum);
    datalogAddValue(2, voltage);
    datalogAddValue(3, pos);
    datalogAddValue(4, error);
    datalogAddValue(5, drivetrainState.integral);
    datalogAddValue(6, drivetrainState.derivative);
    datalogDataGroupEnd()

    motor[leftMotor] = voltage;
   	motor[rightMotor] = voltage;


    wait(timeStepMs, timer1);
    loopNum++;
  }

}
