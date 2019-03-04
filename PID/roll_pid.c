#include "roll_pid.h"
PID_CONFIG rollPIDConfig;
PID_STATUS rollPIDStatus;

float rollPIDErrorIntegral;
float rollPIDLastError;
float rollPIDTarget;

void ROLL_PID_START(PID_CONFIG config){
    rollPIDConfig = config;
    rollPIDStatus.error = 0;
    rollPIDStatus.errorIntegral = 0;
    rollPIDStatus.errorChange = 0;
    rollPIDLastError = 0;
    rollPIDErrorIntegral = 0;
    rollPIDTarget = 0;
}

void ROLL_PID_SETPOINT(float setpoint){
    rollPIDTarget = setpoint;
}

void ROLL_PID_UPDATE(float source) {
    float error = rollPIDTarget - source;
    rollPIDErrorIntegral += error;
    double derivativeError = error - rollPIDLastError;
    rollPIDStatus.error = error;
    rollPIDStatus.errorChange = derivativeError;
    rollPIDStatus.errorIntegral = rollPIDErrorIntegral;

    rollPIDLastError = error;
}

int ROLL_PID_GET_OUTPUT(){
    BASE_PID_GET_OUTPUT(rollPIDStatus, rollPIDConfig);
}