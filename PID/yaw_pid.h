#ifndef _YAW_PID_H
#define _YAW_PID_H
#include "base_pid.h"

void YAW_PID_START(PID_CONFIG config);

void YAW_PID_SETPOINT(float setpoint);

void YAW_PID_UPDATE(float source);

int YAW_PID_GET_OUTPUT();

#endif