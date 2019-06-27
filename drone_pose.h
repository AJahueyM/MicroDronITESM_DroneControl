#ifndef _DRONE_POSE_H
#define _DRONE_POSE_H

/**
 * Simple struct that holds the pose of the drone
 */
typedef struct {
	float yaw;
	float pitch;
	float roll;
	float thrust;
} DRONE_POSE;

#endif