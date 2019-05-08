#ifndef _ROLL_PID_H
#define _ROLL_PID_H
#include "base_pid.h"

/***
 * Uses BASE_PID to control the drone's roll, ROLL_PID_UPDATE needs to be called so that
 * the PID loop can update its output, retrieved by using ROLL_PID_GET_OUTPUT
 *
 * ROLL_PID_START needs to be called before anything else so that it is setup properly
 */

void ROLL_PID_START(PID_CONFIG config);

void ROLL_PID_SETPOINT(float setpoint);

void ROLL_PID_UPDATE(float source, float time);

void ROLL_PID_UPDATE_CONFIG(PID_CONFIG config);

float ROLL_PID_GET_OUTPUT();

#endif