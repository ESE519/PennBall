/*
Michael Posner
ESE 519
Group 4
Final Project
DC Motor Control for Moving Targets
*/

#ifndef MT_H
#define MT_H

#include "mbed.h"
#include "motordriver.h"

//#define DEBUG

/*
 * Start the moving target with the given speed 
 * in the given direction
 *
 * @param mtnum The motor to control (1 or 2)
 * @param speed Float from 0 - 1 that specifies the duty cycle
 * @param dir Direction for the motor to spin
 */
void mt_start(int mtnum, float speed, bool dir);

/*
 * Stops the given moving target.
 *
 * @param mtnum The motor to control (1 or 2)
 */
void mt_stop(int mtnum);

/*
 * Changes the speed and direction of the moving target
 *
 * @param mtnum The motor to control (1 or 2)
 */
void mt_change(int mtnum);


#endif