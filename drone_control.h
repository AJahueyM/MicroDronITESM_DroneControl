#ifndef _DRONE_CTRL_H
#define _DRONE_CTRL_H
#include "PID/yaw_pid.h"
#include "PID/roll_pid.h"
#include "PID/pitch_pid.h"
#include "PID/height_pid.h"
#include "drone_pose.h"
#include "drone_motor_output.h"

void DRONE_CTRL_INITIALIZE();

void DRONE_CTRL_UPDATE(DRONE_POSE newPose);

void DRONE_CTRL_SET_TARGET_YAW(float yaw);

void DRONE_CTRL_SET_TARGET_ROLL(float roll);

void DRONE_CTRL_SET_TARGET_PITCH(float pitch);

void DRONE_CTRL_SET_TARGET_HEIGHT(float height);

void DRONE_CTRL_USE_MANUAL_THRUST(bool manualThrust);

void DRONE_CTRL_SET_MANUAL_THRUST(float thrust);

bool DRONE_CTRL_USING_MANUAL_THRUST();

DRONE_CTRL_MOTOR_OUTPUT DRONE_CTRL_GET_MOTOR_OUTPUT();

void DRONE_CTRL_SET_YAW_PID(PID_CONFIG yawPIDConfigUpdate);

PID_CONFIG DRONE_CTRL_GET_YAW_PID();

void DRONE_CTRL_SET_PITCH_PID(PID_CONFIG pitchPIDConfigUpdate);

PID_CONFIG DRONE_CTRL_GET_PITCH_PID();

void DRONE_CTRL_SET_ROLL_PID(PID_CONFIG rollPIDConfigUpdate);

PID_CONFIG DRONE_CTRL_GET_ROLL_PID();

void DRONE_CTRL_SET_HEIGHT_PID(PID_CONFIG heightPIDConfigUpdate);

PID_CONFIG DRONE_CTRL_GET_HEIGHT_PID();

void DRONE_CTRL_SET_K(float newK);

float DRONE_CTRL_GET_K();


#endif