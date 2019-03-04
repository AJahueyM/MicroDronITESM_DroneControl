#ifndef _BASE_PID_H
#define _BASE_PID_H
#include <stdbool.h>
#include <math.h>

typedef struct {
    float error;
    float errorIntegral;
    float errorChange;
}PID_STATUS;

typedef struct {
    float p;
    float i;
    float d;
    bool clampled;
    float max;
    float min;
}PID_CONFIG;

float BASE_PID_GET_OUTPUT(PID_STATUS status, PID_CONFIG config);

#endif