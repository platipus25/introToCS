#pragma config(StandardModel, "RVW CLAWBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "simple_encoder_movement.h"

task main()
{
  wait1Msec(500);

  resetMotorEncoder(leftMotor);
  resetMotorEncoder(rightMotor);

  /*
  while(getMotorEncoder(rightMotor) < 1800)
  {
    motor[rightMotor] = 63;
    motor[leftMotor] = 63;
  }

  motor[rightMotor] = 0;
  motor[leftMotor] = 0;*/
  int dist = 800;
  int speed = 100;

  for(int mult = 1; mult <= 4; mult++){
  	move(dist*mult, speed);
	  move(dist*mult, -speed);
	}
}
