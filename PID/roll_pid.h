#ifndef _ROLL_PID_H
#define _ROLL_PID_H
#include "base_pid.h"

void ROLL_PID_START(PID_CONFIG config);

void ROLL_PID_SETPOINT(float setpoint);

void ROLL_PID_UPDATE(float source, float time);

void ROLL_PID_UPDATE_CONFIG(PID_CONFIG config);

float ROLL_PID_GET_OUTPUT();

#endif