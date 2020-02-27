struct PIDConstants {
  float kP, kI, kD;
};

struct PIDState {
  float prevError, integral, derivative;
};

int wait(int cycleLengthMs, int timer){
  int startTime = time1[timer];
  while(time1[timer] < cycleLengthMs){
    delay(1);
  }
  int timeWaited = time1[timer] - startTime;
  clearTimer(timer);
  return timeWaited;
}

float iterate(float error, struct PIDConstants *consts, struct PIDState *state){
  state->integral = state->integral + error;
  state->derivative = error - state->prevError;
  state->prevError = error;


  float voltage = consts->kP * error + consts->kI * state->integral + consts->kD * state->derivative;

  /*if(integral > 0 != error > 0){
      integral = 0;
  }*/

  return voltage;
}
