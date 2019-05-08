#ifndef _PID_CONFIG_H
#define _PID_CONFIG_H

/**
 * Simple PID configuration
 */
typedef struct {
    float p;
    float i;
    float d;
    bool clampled;
    float max;
    float min;
}PID_CONFIG;

#endif