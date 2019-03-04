#include "pitch_pid.h"
PID_CONFIG pitchPIDConfig;
PID_STATUS pitchPIDStatus;

float pitchPIDErrorIntegral;
float pitchPIDLastError;
float pitchPIDTarget;

void PITCH_PID_START(PID_CONFIG config){
    pitchPIDConfig = config;
    pitchPIDStatus.error = 0;
    pitchPIDStatus.errorIntegral = 0;
    pitchPIDStatus.errorChange = 0;
    pitchPIDLastError = 0;
    pitchPIDErrorIntegral = 0;
    pitchPIDTarget = 0;
}

void PITCH_PID_SETPOINT(float setpoint){
    pitchPIDTarget = setpoint;
}

void PITCH_PID_UPDATE(float source) {
    float error = pitchPIDTarget - source;
    pitchPIDErrorIntegral += error;
    double derivativeError = error - pitchPIDLastError;
    pitchPIDStatus.error = error;
    pitchPIDStatus.errorChange = derivativeError;
    pitchPIDStatus.errorIntegral = pitchPIDErrorIntegral;

    pitchPIDLastError = error;
}

int PITCH_PID_GET_OUTPUT(){
    BASE_PID_GET_OUTPUT(pitchPIDStatus, pitchPIDConfig);
}