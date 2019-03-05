#include <stdio.h>
#include "base_pid.h"

float BASE_PID_GET_OUTPUT(PID_STATUS status, PID_CONFIG config){
    float output = status.error * config.p + status.errorIntegral * config.i + status.errorChange * config.d;
    
    if(config.clampled && (output > config.max || output < config.min) ){
        if(output > config.max){
            output = config.max;
        }else{
            output = config.min;
        }
    }

    return output;
}