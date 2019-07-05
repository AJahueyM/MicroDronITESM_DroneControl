#include "yaw_pid.h"
PID_CONFIG yawPIDConfig;
PID_STATUS yawPIDStatus;

float yawPIDErrorIntegral;
float yawPIDLastError;
float yawPIDTarget;
float lastTimeUpdate;

void YAW_PID_START(PID_CONFIG config){
    yawPIDConfig = config;
    yawPIDStatus.error = 0.0f;
    yawPIDStatus.errorIntegral = 0.0f;
    yawPIDStatus.errorChange = 0.0f;
    yawPIDLastError = 0.0f;
    yawPIDErrorIntegral = 0.0f;
    yawPIDTarget = 0.0f;
    lastTimeUpdate = 0.0f;
}

void YAW_PID_SETPOINT(float setpoint){
    yawPIDTarget = setpoint;
}

void YAW_PID_UPDATE(float source, float time) {
    float timeStep = time - lastTimeUpdate;
    
    float error = yawPIDTarget - source;

    if(yawPIDConfig.continuous){
        double maxError = (yawPIDConfig.maxInput - yawPIDConfig.minInput) / 2.0;

        if(error > maxError){
            error -= yawPIDConfig.maxInput - yawPIDConfig.minInput;
        }
        if(error < -maxError){
            error += yawPIDConfig.maxInput - yawPIDConfig.minInput;
        }
    }


    yawPIDErrorIntegral += error;
    float derivativeError = (error - yawPIDLastError);
    yawPIDStatus.error = error;
    yawPIDStatus.errorChange = derivativeError;
    yawPIDStatus.errorIntegral = yawPIDErrorIntegral;

    yawPIDLastError = error;
    lastTimeUpdate = time;
}

void YAW_PID_UPDATE_CONFIG(PID_CONFIG config){
        yawPIDConfig = config;
}

float YAW_PID_GET_OUTPUT(){
    return BASE_PID_GET_OUTPUT(yawPIDStatus, yawPIDConfig);
}