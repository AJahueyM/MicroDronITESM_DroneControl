#include <stdio.h>
#include "height_pid.h"
PID_CONFIG heightPIDConfig;
PID_STATUS heightPIDStatus;

float heightPIDErrorIntegral;
float heightPIDLastError;
float heightPIDTarget;
float lastTimeUpdate;

void HEIGHT_PID_START(PID_CONFIG config){
    heightPIDConfig = config;
    heightPIDStatus.error = 0.0f;
    heightPIDStatus.errorIntegral = 0.0f;
    heightPIDStatus.errorChange = 0.0f;
    heightPIDLastError = 0.0f;
    heightPIDErrorIntegral = 0.0f;
    heightPIDTarget = 0.0f;
    lastTimeUpdate = 0.0f;
}

void HEIGHT_PID_SETPOINT(float setpoint){
    heightPIDTarget = setpoint;
}

void HEIGHT_PID_UPDATE(float source, float time) {
    float timeStep = time - lastTimeUpdate;
    float error = heightPIDTarget - source;

    if(heightPIDConfig.continuous){
        double maxError = (heightPIDConfig.maxInput - heightPIDConfig.minInput) / 2.0;

        if(error > maxError){
            error -= heightPIDConfig.maxInput - heightPIDConfig.minInput;
        }
        if(error < -maxError){
            error += heightPIDConfig.maxInput - heightPIDConfig.minInput;
        }
    }

    heightPIDErrorIntegral += error;
    float derivativeError = (error - heightPIDLastError);
    heightPIDStatus.error = error;
    heightPIDStatus.errorChange = derivativeError;
    heightPIDStatus.errorIntegral = heightPIDErrorIntegral;

    heightPIDLastError = error;
    lastTimeUpdate = time;
}

void HEIGHT_PID_UPDATE_CONFIG(PID_CONFIG config){
        heightPIDConfig = config;
}

float HEIGHT_PID_GET_OUTPUT(){
    return BASE_PID_GET_OUTPUT(heightPIDStatus, heightPIDConfig);
}