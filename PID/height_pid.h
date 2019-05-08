#ifndef _HEIGHT_PID_H
#define _HEIGHT_PID_H
#include "base_pid.h"

/***
 * Uses BASE_PID to control the drone's height, HEIGHT_PID_UPDATE needs to be called so that
 * the PID loop can update its output, retrieved by using HEIGHT_PID_GET_OUTPUT
 *
 * HEIGHT_PID_START needs to be called before anything else so that it is setup properly
 */

void HEIGHT_PID_START(PID_CONFIG config);

void HEIGHT_PID_SETPOINT(float setpoint);

void HEIGHT_PID_UPDATE(float source, float time);

float HEIGHT_PID_GET_OUTPUT();

#endif