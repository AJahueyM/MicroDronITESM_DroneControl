#ifndef _PID_CONFIG_H
#define _PID_CONFIG_H
#include <stdbool.h>

/**
 * Simple PID configuration
 */
typedef struct {
    float p;
    float i;
    float d;
    bool clamped;
    float maxOutput;
    float minOutput;
    bool continuous;
    float maxInput;
    float minInput;
}PID_CONFIG;

#endif