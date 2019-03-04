#include "yaw_pid.h"
PID_CONFIG yawPIDConfig;
PID_STATUS yawPIDStatus;

float yawPIDErrorIntegral;
float yawPIDLastError;
float yawPIDTarget;

void YAW_PID_START(PID_CONFIG config){
    yawPIDConfig = config;
    yawPIDStatus.error = 0;
    yawPIDStatus.errorIntegral = 0;
    yawPIDStatus.errorChange = 0;
    yawPIDLastError = 0;
    yawPIDErrorIntegral = 0;
    yawPIDTarget = 0;
}

void YAW_PID_SETPOINT(float setpoint){
    yawPIDTarget = setpoint;
}

void YAW_PID_UPDATE(float source) {
    float error = yawPIDTarget - source;
    yawPIDErrorIntegral += error;
    double derivativeError = error - yawPIDLastError;
    yawPIDStatus.error = error;
    yawPIDStatus.errorChange = derivativeError;
    yawPIDStatus.errorIntegral = yawPIDErrorIntegral;

    yawPIDLastError = error;
}

int YAW_PID_GET_OUTPUT(){
    BASE_PID_GET_OUTPUT(yawPIDStatus, yawPIDConfig);
}