#ifndef _BASE_PID_H
#define _BASE_PID_H
#include <stdbool.h>
#include <math.h>
#include "pid_config.h"

/**
 * Holds the PID system status
 *
 */
typedef struct {
    float error;
    float errorIntegral;
    float errorChange;
}PID_STATUS;

/***
 * PID Implementation, returns the output given a configuration and status
 * @param status
 * @param config
 * @return
 */
float BASE_PID_GET_OUTPUT(PID_STATUS status, PID_CONFIG config);

#endif