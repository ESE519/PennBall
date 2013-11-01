/*
Michael Posner
ESE 519
Group 4
Final Project
DC Motor Control for Merry Go Round
*/

#ifndef MERRY_H
#define MERRY_H

#include "mbed.h"
#include "motordriver.h"

//#define DEBUG


/*
 * Start the Merry Go Round with the given speed 
 * in the given direction
 *
 * @param speed Float from 0 - 1 that specifies the duty cycle
 * @param dir Direction for the motor to spin
 */
void merry_spin(float speed, bool dir);

/*
 * Stops the Merry Go Round.
 */
void merry_stop(void);

/*
 * Changes the speed and direction of the merry go round
 */
void merry_change(void);


#endif