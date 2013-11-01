/*
Michael Posner
Sujith Pottem
Benjamin Kadish
ESE 519
Group 4
Final Project
*/

#include "moving_target.h"
#include "merry_go_round.h"


int main(void) {

    mt_start(1,0.8,true);
    wait(1);
    mt_change(1);
    wait(1);
    mt_change(1);
    wait(1);
    mt_change(1);
    wait(1);
    mt_change(1);
    wait(2);
    mt_stop(1);
    
}