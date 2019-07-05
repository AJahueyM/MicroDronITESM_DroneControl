#include "pitch_pid.h"
PID_CONFIG pitchPIDConfig;
PID_STATUS pitchPIDStatus;

float pitchPIDErrorIntegral;
float pitchPIDLastError;
float pitchPIDTarget;
float lastTimeUpdate;

void PITCH_PID_START(PID_CONFIG config){
    pitchPIDConfig = config;
    pitchPIDStatus.error = 0.0f;
    pitchPIDStatus.errorIntegral = 0.0f;
    pitchPIDStatus.errorChange = 0.0f;
    pitchPIDLastError = 0.0f;
    pitchPIDErrorIntegral = 0.0f;
    pitchPIDTarget = 0.0f;
    lastTimeUpdate = 0.0f;
}

void PITCH_PID_SETPOINT(float setpoint){
    pitchPIDTarget = setpoint;
}

void PITCH_PID_UPDATE(float source, float time) {
    float timeStep = time - lastTimeUpdate;
    float error = pitchPIDTarget - source;

    if(pitchPIDConfig.continuous){
        double maxError = (pitchPIDConfig.maxInput - pitchPIDConfig.minInput) / 2.0;

        if(error > maxError){
            error -= pitchPIDConfig.maxInput - pitchPIDConfig.minInput;
        }
        if(error < -maxError){
            error += pitchPIDConfig.maxInput - pitchPIDConfig.minInput;
        }
    }
    pitchPIDErrorIntegral += error;
    float derivativeError = (error - pitchPIDLastError);
    pitchPIDStatus.error = error;
    pitchPIDStatus.errorChange = derivativeError;
    pitchPIDStatus.errorIntegral = pitchPIDErrorIntegral;

    pitchPIDLastError = error;
    lastTimeUpdate = time;
}

void PITCH_PID_UPDATE_CONFIG(PID_CONFIG config){
        pitchPIDConfig = config;
}


float PITCH_PID_GET_OUTPUT(){
    return BASE_PID_GET_OUTPUT(pitchPIDStatus, pitchPIDConfig);
}