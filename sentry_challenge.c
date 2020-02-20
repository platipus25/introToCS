#pragma config(StandardModel, "RVW CLAWBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "simple_encoder_movement.h"

task main()
{
  wait1Msec(500);

  resetMotorEncoder(leftMotor);
  resetMotorEncoder(rightMotor);

  int dist = 2200;
  int speed = 100;
  int turn_speed = 100;
  int turn_dist = 260;

  while(true){
  	move(dist, speed);
  	turn(turn_dist, turn_speed);
	}





}