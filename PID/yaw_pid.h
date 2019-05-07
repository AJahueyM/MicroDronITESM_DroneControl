#ifndef _YAW_PID_H
#define _YAW_PID_H
#include "base_pid.h"

/***
 * Uses BASE_PID to control the drone's yaw, YAW_PID_UPDATE needs to be called so that
 * the PID loop can update its output, retrieved by using YAW_PID_GET_OUTPUT
 *
 * YAW_PID_START needs to be called before anything else so that it is setup properly
 */

void YAW_PID_START(PID_CONFIG config);

void YAW_PID_SETPOINT(float setpoint);

void YAW_PID_UPDATE(float source, float time);

void YAW_PID_UPDATE_CONFIG(PID_CONFIG config);

float YAW_PID_GET_OUTPUT();

#endif