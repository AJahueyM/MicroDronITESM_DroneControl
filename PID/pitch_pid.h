#ifndef _PITCH_PID_H
#define _PITCH_PID_H
#include "base_pid.h"

void PITCH_PID_START(PID_CONFIG config);

void PITCH_PID_SETPOINT(float setpoint);

void PITCH_PID_UPDATE(float source);

int PITCH_PID_GET_OUTPUT();

#endif