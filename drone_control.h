#ifndef _DRONE_CTRL_H
#define _DRONE_CTRL_H
#include "yaw_pid.h"
#include "roll_pid.h"
#include "pitch_pid.h"
#include "height_pid.h"
#include "drone_pose.h"

typedef struct{
    float bottomLeft;
    float bottomRight;
    float topRight;
    float topLeft;
} DRONE_CTRL_MOTOR_OUTPUT;

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



#endif