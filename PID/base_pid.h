#ifndef _BASE_PID_H
#define _BASE_PID_H
#include <stdbool.h>
#include <math.h>
#include "pid_config.h"

typedef struct {
    float error;
    float errorIntegral;
    float errorChange;
}PID_STATUS;



float BASE_PID_GET_OUTPUT(PID_STATUS status, PID_CONFIG config);

#endif