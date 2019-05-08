#ifndef _PITCH_PID_H
#define _PITCH_PID_H
#include "base_pid.h"

/***
 * Uses BASE_PID to control the drone's pitch, PITCH_PID_UPDATE needs to be called so that
 * the PID loop can update its output, retrieved by using PITCH_PID_GET_OUTPUT
 *
 * PITCH_PID_START needs to be called before anything else so that it is setup properly
 */

void PITCH_PID_START(PID_CONFIG config);

void PITCH_PID_SETPOINT(float setpoint);

void PITCH_PID_UPDATE(float source, float time);

void PITCH_PID_UPDATE_CONFIG(PID_CONFIG config);

float PITCH_PID_GET_OUTPUT();

#endif