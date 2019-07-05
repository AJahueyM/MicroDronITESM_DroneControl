#include <stdio.h>
#include "base_pid.h"


float BASE_PID_GET_OUTPUT(PID_STATUS status, PID_CONFIG config){
    float output = status.error * config.p + status.errorIntegral * config.i + status.errorChange * config.d;
    
    if(config.clamped){
        if(output > config.maxOutput){
            output = config.maxOutput;
        }else if(output < config.minOutput){
            output = config.minOutput;
        }
    }

    return output;
}