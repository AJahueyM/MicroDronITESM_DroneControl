#include "drone_config.h"

const double DRONE_MASS = 0.06; // Kilograms
const double GRAVITY = -9.8; // m / s^2
const double DRONE_ARM_LENGTH = 0.058; // Meters
const double DRONE_KT = 0.000000045; // N/(rad^2/s^2)
const double DRONE_KQ = 0.00000000582; // Nm/(rad^2/s^2)
const double DRONE_IXX = 0.00007321; // Inertia XX, kgm^2
const double DRONE_IYY = 0.00007317; // Inertia YY, kgm^2
const double DRONE_IZZ = 0.00007317; // Inertia ZZ, kgm^2
//Asuming conversion from PWM output percent to angular speed is linear, it is not, but should be close enough
const double DRONE_PERCENT_PER_ANGULAR = 0.066; //PWM output percent per rad/s
const double DRONE_PERCENT_TO_ANGULAR_OFFSET = -58.8; //Offset for conversion between rad/s and PWM output percent

double DRONE_CONFIG_GET_PWMOUT_FROM_ANGULAR(double angularSpeed){
    return angularSpeed * DRONE_PERCENT_PER_ANGULAR + DRONE_PERCENT_TO_ANGULAR_OFFSET;
}

double DRONE_CONFIG_GET_ANGULAR_FROM_PWMOUT(double pwmOut){
    return (pwmOut - DRONE_PERCENT_TO_ANGULAR_OFFSET) / DRONE_PERCENT_PER_ANGULAR;
}

double DRONE_CONFIG_GET_THRUST_FROM_ANGULAR(double angularSpeed){
    return DRONE_KT * powf(angularSpeed, 2);
}

double DRONE_CONFIG_GET_ANGULAR_FROM_THRUST(double thrust){
    return  sqrtf(thrust / DRONE_KT);
}

double DRONE_GET_THRUST_FOR_HOVER(DRONE_POSE pose){
    return (-GRAVITY * DRONE_MASS)/(cosf(pose.roll) * cosf(pose.pitch));
}
