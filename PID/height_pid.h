#ifndef _HEIGHT_PID_H
#define _HEIGHT_PID_H
#include "base_pid.h"

void HEIGHT_PID_START(PID_CONFIG config);

void HEIGHT_PID_SETPOINT(float setpoint);

void HEIGHT_PID_UPDATE(float source, float time);

float HEIGHT_PID_GET_OUTPUT();

#endif