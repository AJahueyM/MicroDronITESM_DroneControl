#include "drone_config.h"

double DRONE_CONFIG_GET_PWMOUT_FROM_ANGULAR(double angularSpeed){
    return angularSpeed * DRONE_PERCENT_PER_ANGULAR + DRONE_PERCENT_TO_ANGULAR_OFFSET;
}

double DRONE_CONFIG_GET_ANGULAR_FROM_PWMOUT(double pwmOut){
    return (pwmOut - DRONE_PERCENT_TO_ANGULAR_OFFSET) / DRONE_PERCENT_PER_ANGULAR;
}

double DRONE_CONFIG_GET_THRUST_FROM_ANGULAR(double angularSpeed){
    return DRONE_KT * pow(angularSpeed, 2);
}

double DRONE_CONFIG_GET_ANGULAR_FROM_THRUST(double thrust){
    return  sqrt(thrust / DRONE_KT);
}

double DRONE_GET_THRUST_FOR_HOVER(DRONE_POSE pose){
    return (-GRAVITY * DRONE_MASS)/(cos(pose.roll) * sin(pose.pitch));
}
