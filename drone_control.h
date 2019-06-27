#ifndef _DRONE_CTRL_H
#define _DRONE_CTRL_H
#include "PID/yaw_pid.h"
#include "PID/roll_pid.h"
#include "PID/pitch_pid.h"
#include "PID/height_pid.h"
#include "drone_config.h"
#include "drone_pose.h"
#include "drone_motor_output.h"


/**
 * Control logic for a drone, uses the X configuration
 * Contains a PID implementation and allows for manual thrust control if no height reference is available
 * Uses a K value that represents the maximum output that can be sent to the motors.
 * Tested using Gazebo + ROS, with the package "rotors_simulator"
 *
 * By: Alberto Jahuey Moncada A01039835@itesm.mx
 */

/**
 * Initialize all variables needed for Drone Control, needs to be called before everything else
 */
void DRONE_CTRL_INITIALIZE();

/**
 * Update the PID loops and motor outputs given a new drone pose and current time in seconds
 * Time implementation not currently used, couldnt obtain a time reference, but it should be enabled if one is available
 * @param newPose
 * @param time
 */
void DRONE_CTRL_UPDATE(DRONE_POSE newPose, float time);

/**
 * Update the yaw PID Setpoint
 * @param yaw
 */
void DRONE_CTRL_SET_TARGET_YAW(float yaw);

/**
 * Update the roll PID Setpoint
 * @param yaw
 */
void DRONE_CTRL_SET_TARGET_ROLL(float roll);

/**
 * Update the pitch PID Setpoint
 * @param yaw
 */
void DRONE_CTRL_SET_TARGET_PITCH(float pitch);

/**
 * Update the target PID Setpoint
 * @param yaw
 */
void DRONE_CTRL_SET_TARGET_HEIGHT(float height);

/**
 * Configure drone control to either use the Height PID loop for thrust control or manual thrust control
 * @param manualThrust
 */
void DRONE_CTRL_USE_MANUAL_THRUST(bool manualThrust);

/**
 * Configure the current manual thrust if it is being used
 * @param thrust
 */
void DRONE_CTRL_SET_MANUAL_THRUST(float thrust);

/**
 * Check whether or not manual thrust is currently in use
 * @return
 */
bool DRONE_CTRL_USING_MANUAL_THRUST();

/**
 * Update current offset thrust if it is being used
 * @param offsetThrust
 */
void DRONE_CTRL_SET_OFFSET_THRUST(float offsetThrust);

/**
 * Retrieve the current motor output after it is updated by DRONE_CTRL_UPDATE
 * @return
 */
DRONE_CTRL_MOTOR_OUTPUT DRONE_CTRL_GET_MOTOR_OUTPUT();

/**
 * Update the current PID configuration for the yaw PID loop
 * @param yawPIDConfigUpdate
 */
void DRONE_CTRL_SET_YAW_PID(PID_CONFIG yawPIDConfigUpdate);

/***
 * Retrieve current yaw PID configuration
 * @return
 */
PID_CONFIG DRONE_CTRL_GET_YAW_PID();

/**
 * Update the current PID configuration for the pitch PID loop
 * @param pitchPIDConfigUpdate
 */
void DRONE_CTRL_SET_PITCH_PID(PID_CONFIG pitchPIDConfigUpdate);

/**
 * Retrieve current pitch PID configuration
 * @return
 */
PID_CONFIG DRONE_CTRL_GET_PITCH_PID();

/**
 * Update the current roll PID configuration
 * @param rollPIDConfigUpdate
 */
void DRONE_CTRL_SET_ROLL_PID(PID_CONFIG rollPIDConfigUpdate);

/**
 * Retrieve current roll PID configuration
 * @return
 */
PID_CONFIG DRONE_CTRL_GET_ROLL_PID();

/**
 * Update the current height PID configuration
 * @param heightPIDConfigUpdate
 */
void DRONE_CTRL_SET_HEIGHT_PID(PID_CONFIG heightPIDConfigUpdate);

/**
 * Retrieve current height PID configuration
 * @return
 */
PID_CONFIG DRONE_CTRL_GET_HEIGHT_PID();

/**
 * Update the current K value, this is the maximum motor output that can be used
 * @param newK
 */
void DRONE_CTRL_SET_K(float newK);


/**
 * Get the current K value, this is the maximum motor output that can be used
 * @return
 */
float DRONE_CTRL_GET_K();


#endif