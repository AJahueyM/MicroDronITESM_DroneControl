#ifndef _ROLL_PID_H
#define _ROLL_PID_H
#include "base_pid.h"

void ROLL_PID_START(PID_CONFIG config);

void ROLL_PID_SETPOINT(float setpoint);

void ROLL_PID_UPDATE(float source);

int ROLL_PID_GET_OUTPUT();

#endif