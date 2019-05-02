#include "roll_pid.h"
PID_CONFIG rollPIDConfig;
PID_STATUS rollPIDStatus;

float rollPIDErrorIntegral;
float rollPIDLastError;
float rollPIDTarget;
float lastTimeUpdate;

void ROLL_PID_START(PID_CONFIG config){
    rollPIDConfig = config;
    rollPIDStatus.error = 0.0f;
    rollPIDStatus.errorIntegral = 0.0f;
    rollPIDStatus.errorChange = 0.0f;
    rollPIDLastError = 0.0f;
    rollPIDErrorIntegral = 0.0f;
    rollPIDTarget = 0.0f;
    lastTimeUpdate = 0.0f;
    
}

void ROLL_PID_SETPOINT(float setpoint){
    rollPIDTarget = setpoint;
}

void ROLL_PID_UPDATE(float source, float time) {
    float timeStep = time - lastTimeUpdate;
    float error = rollPIDTarget - source;
    rollPIDErrorIntegral += error;
    float derivativeError = (error - rollPIDLastError);
    rollPIDStatus.error = error;
    rollPIDStatus.errorChange = derivativeError;
    rollPIDStatus.errorIntegral = rollPIDErrorIntegral;

    rollPIDLastError = error;
    lastTimeUpdate = time;
}

void ROLL_PID_UPDATE_CONFIG(PID_CONFIG config){
        rollPIDConfig = config;
}

float ROLL_PID_GET_OUTPUT(){
    return BASE_PID_GET_OUTPUT(rollPIDStatus, rollPIDConfig);
}