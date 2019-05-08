#include <stdio.h>
#include "drone_control.h"
PID_CONFIG yawPIDConfig;
PID_CONFIG rollPIDConfig;
PID_CONFIG pitchPIDConfig;
PID_CONFIG heightPIDConfig;

float k = 5000;
const float MAX_K = 5000;

bool usingManualThrust = false;
float currentManualThrust = 0;

void DRONE_CTRL_INITIALIZE(){
    yawPIDConfig.p = 0.02;
    yawPIDConfig.i = 0.0;
    yawPIDConfig.d = 0.5;
    yawPIDConfig.clampled = true;
    yawPIDConfig.max =  1.0;
    yawPIDConfig.min = 0.0;


    rollPIDConfig.p = 0.002;
    rollPIDConfig.i = 0.0;
    rollPIDConfig.d = 0.13;
    rollPIDConfig.clampled = false;


    pitchPIDConfig.p = 0.002;
    pitchPIDConfig.i = 0.0;
    pitchPIDConfig.d = 0.13;
    pitchPIDConfig.clampled = false;


    heightPIDConfig.p = 0.0;
    heightPIDConfig.i = 0.0;
    heightPIDConfig.d = 0.0;
    heightPIDConfig.clampled = false;


    YAW_PID_START(yawPIDConfig);
    ROLL_PID_START(rollPIDConfig);
    PITCH_PID_START(pitchPIDConfig);
    HEIGHT_PID_START(heightPIDConfig);

    YAW_PID_SETPOINT(0.0);
    ROLL_PID_SETPOINT(0.0);
    PITCH_PID_SETPOINT(0.0);
    HEIGHT_PID_SETPOINT(0.0);
}

void DRONE_CTRL_UPDATE(DRONE_POSE newPose, float time){
    YAW_PID_UPDATE(newPose.yaw, time);
    ROLL_PID_UPDATE(newPose.roll, time);
    PITCH_PID_UPDATE(newPose.pitch, time);
    HEIGHT_PID_UPDATE(newPose.zAccel, time);
}

void DRONE_CTRL_SET_TARGET_YAW(float yaw){
    YAW_PID_SETPOINT(yaw);
}

void DRONE_CTRL_SET_TARGET_ROLL(float roll){
    ROLL_PID_SETPOINT(roll);
}

void DRONE_CTRL_SET_TARGET_PITCH(float pitch){
    PITCH_PID_SETPOINT(pitch);
}

void DRONE_CTRL_SET_TARGET_HEIGHT(float height){
    HEIGHT_PID_SETPOINT(height);
}

void DRONE_CTRL_USE_MANUAL_THRUST(bool manualThrust){
    usingManualThrust = manualThrust;
}

void DRONE_CTRL_SET_MANUAL_THRUST(float thrust){
    currentManualThrust = thrust;
}

bool DRONE_CTRL_USING_MANUAL_THRUST(){
    return usingManualThrust;
}

DRONE_CTRL_MOTOR_OUTPUT DRONE_CTRL_GET_MOTOR_OUTPUT(){
    float yawRate = YAW_PID_GET_OUTPUT();
    float rollRate = ROLL_PID_GET_OUTPUT();
    float pitchRate = PITCH_PID_GET_OUTPUT();
    
    float thrust = usingManualThrust ? currentManualThrust : HEIGHT_PID_GET_OUTPUT();

    DRONE_CTRL_MOTOR_OUTPUT motorOutput;

    motorOutput.bottomLeft = (thrust - pitchRate + rollRate - yawRate) * k;
    motorOutput.bottomRight = (thrust - pitchRate - rollRate + yawRate) * k;
    motorOutput.topLeft =  (thrust + pitchRate + rollRate + yawRate) * k;
    motorOutput.topRight = (thrust + pitchRate - rollRate - yawRate) * k;
    
    motorOutput.bottomLeft = motorOutput.bottomLeft > 0 ? motorOutput.bottomLeft : 0;
    motorOutput.bottomRight = motorOutput.bottomRight > 0 ? motorOutput.bottomRight : 0;
    motorOutput.topLeft = motorOutput.topLeft > 0 ? motorOutput.topLeft : 0;
    motorOutput.topRight = motorOutput.topRight > 0 ? motorOutput.topRight : 0;

    motorOutput.bottomLeft = motorOutput.bottomLeft > k ? k : motorOutput.bottomLeft;
    motorOutput.bottomRight = motorOutput.bottomRight > k ? k : motorOutput.bottomRight;
    motorOutput.topLeft = motorOutput.topLeft > k ? k : motorOutput.topLeft;
    motorOutput.topRight = motorOutput.topRight > k ? k : motorOutput.topRight;
    
    return motorOutput;
}

void DRONE_CTRL_SET_YAW_PID(PID_CONFIG yawPIDConfigUpdate){
    yawPIDConfig = yawPIDConfigUpdate;
    YAW_PID_UPDATE_CONFIG(yawPIDConfig);
}

PID_CONFIG DRONE_CTRL_GET_YAW_PID(){
    return yawPIDConfig;
}

void DRONE_CTRL_SET_PITCH_PID(PID_CONFIG pitchPIDConfigUpdate){
    pitchPIDConfig = pitchPIDConfigUpdate;
    PITCH_PID_UPDATE_CONFIG(pitchPIDConfig);
}

PID_CONFIG DRONE_CTRL_GET_PITCH_PID(){
    return pitchPIDConfig;
}

void DRONE_CTRL_SET_ROLL_PID(PID_CONFIG rollPIDConfigUpdate){
    rollPIDConfig = rollPIDConfigUpdate;
    ROLL_PID_UPDATE_CONFIG(rollPIDConfig);
}

PID_CONFIG DRONE_CTRL_GET_ROLL_PID(){
    return rollPIDConfig;
}

void DRONE_CTRL_SET_HEIGHT_PID(PID_CONFIG heightPIDConfigUpdate){
    heightPIDConfig = heightPIDConfigUpdate;
    HEIGHT_PID_UPDATE_CONFIG(heightPIDConfig);
}

PID_CONFIG DRONE_CTRL_GET_HEIGHT_PID(){
    return heightPIDConfig;
}

void DRONE_CTRL_SET_K(float newK){
    k = newK;
    if(k > MAX_K){
        k = MAX_K;
    }
    
    if(k < 0){
        k = 0;
    }
}

float DRONE_CTRL_GET_K(){
    return k;
}