#ifndef _DRONE_CONFIG_H
#define _DRONE_CONFIG_H
#include "drone_pose.h"
#include "math.h"

/**
 * Get PWM output percent from an angular speed in rad/s
 * param angularSpeed
 */
double DRONE_CONFIG_GET_PWMOUT_FROM_ANGULAR(double angularSpeed);

double DRONE_CONFIG_GET_ANGULAR_FROM_PWMOUT(double pwmOut);
double DRONE_CONFIG_GET_THRUST_FROM_ANGULAR(double angularSpeed);
double DRONE_CONFIG_GET_ANGULAR_FROM_THRUST(double thrust);
double DRONE_GET_THRUST_FOR_HOVER(DRONE_POSE pose);

#endif