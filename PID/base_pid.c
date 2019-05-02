#include <stdio.h>
#include "base_pid.h"


float BASE_PID_GET_OUTPUT(PID_STATUS status, PID_CONFIG config){
    float output = status.error * config.p + status.errorIntegral * config.i + status.errorChange * config.d;
    
    if(config.clampled){
        if(output > config.max){
            output = config.max;
        }else if(output < config.min){
            output = config.min;
        }
    }

    return output;
}