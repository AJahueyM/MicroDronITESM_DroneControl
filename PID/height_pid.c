#include <stdio.h>
#include "height_pid.h"
PID_CONFIG heightPIDConfig;
PID_STATUS heightPIDStatus;

float heightPIDErrorIntegral;
float heightPIDLastError;
float heightPIDTarget;

void HEIGHT_PID_START(PID_CONFIG config){
    heightPIDConfig = config;
    heightPIDStatus.error = 0;
    heightPIDStatus.errorIntegral = 0;
    heightPIDStatus.errorChange = 0;
    heightPIDLastError = 0;
    heightPIDErrorIntegral = 0;
    heightPIDTarget = 0;
}

void HEIGHT_PID_SETPOINT(float setpoint){
    heightPIDTarget = setpoint;
}

void HEIGHT_PID_UPDATE(float source) {
    float error = heightPIDTarget - source;
    heightPIDErrorIntegral += error;
    float derivativeError = error - heightPIDLastError;
    heightPIDStatus.error = error;
    heightPIDStatus.errorChange = derivativeError;
    heightPIDStatus.errorIntegral = heightPIDErrorIntegral;

    heightPIDLastError = error;
}

float HEIGHT_PID_GET_OUTPUT(){
    return BASE_PID_GET_OUTPUT(heightPIDStatus, heightPIDConfig);
}