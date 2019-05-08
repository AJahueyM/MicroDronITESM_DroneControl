
#ifndef _DRONE_MOTOR_OUTPUT_H   
#define _DRONE_MOTOR_OUTPUT_H

/**
 * Simple struct that holds the output to be given to the drone's motors
 */
typedef struct{
    float bottomLeft;
    float bottomRight;
    float topRight;
    float topLeft;
} DRONE_CTRL_MOTOR_OUTPUT;

#endif 