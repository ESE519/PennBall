/*
Michael Posner
ESE 519
Group 4
Final Project
DC Motor Control for Merry Go Round
*/

#include "merry_go_round.h"


#ifdef DEBUG
Serial pc(USBTX, USBRX); // tx, rx
#endif

Motor MGR(p22, p29, p30, 1); // Initialize the motor:  (pwm, fwd, rev, can brake)


//returns the sign of a number
static float sign (float num) {

    if(num < 0)
        return -1.0;
    else
        return 1.0;
}

/*
 * Start the Merry Go Round with the given speed 
 * in the given direction
 *
 * @param speed Float from 0 - 1 that specifies the duty cycle
 * @param dir Direction for the motor to spin
 */
void merry_spin(float speed, bool dir) {

    float res;

    if(dir)
        res = MGR.speed(speed);
    else
        res = MGR.speed(-1.0*speed);
    
    #ifdef DEBUG
    pc.printf("merry_spin:  Res: %f\r\n",res);
    #endif
    
    
    /* 
    if the result is zero, probably means that
    the new dir was opposite the old dir and 
    we didnt stop the motor first. this makes
    the motordriver library unhappy and it will
    return zero and stop the motor first.
    so just command it a second time.
    */
    
    if(abs(res) < 0.0001) { 
    
        wait_ms(250);
    
        #ifdef DEBUG
        pc.printf("merry_spin:  Change of direction, trying again... ");
        #endif
        
        if(dir)
            res = MGR.speed(speed);
        else
            res = MGR.speed(-1.0*speed);  
    
        #ifdef DEBUG
        pc.printf("merry_spin:  2nd res: %f\r\n",res);
        #endif
        
    }
    
}

/*
 * Stops the Merry Go Round.
 */
void merry_stop(void) {
    MGR.stop(0.7);
    
    #ifdef DEBUG
    pc.printf("merry_stop:  Merry Go Round stopped.\r\n");
    #endif
}



/*
 * Changes the speed and direction of the merry go round
 */
void merry_change(void) {
    
    float mstate = MGR.state();  //get current motor state
    
    if(abs(mstate - (-3)) < 0.0001) { //if motor state is -3, theres an error
        #ifdef DEBUG
        pc.printf("merry_change:  Merry Go Round was in error state\r\n");
        #endif
    }
    else if ( (abs(mstate - (-2)) < 0.0001) || (abs(mstate - 2) < 0.0001) ) {  
        //motor state is either 2 (coasting) or -2 (braking)
        MGR.speed(0.6);
        
        #ifdef DEBUG
        pc.printf("merry_change:  Merry Go Round was coasting or braking, changed to 0.6\r\n");
        #endif
    }
    else {  //motor state is between -1 and 1 (running)
        float res;
        
        if(abs(mstate) > 0.6) {
            res = MGR.speed(-1.0*sign(mstate)*(abs(mstate)-0.4));
            if (res < 0.0001) {
                wait_ms(250);
                res = MGR.speed(-1.0*sign(mstate)*(abs(mstate)-0.4));
            }
        }
        else
            res = MGR.speed(sign(mstate)*(abs(mstate) + 0.4));
    
    
        #ifdef DEBUG
        pc.printf("merry_change:  Merry Go Round speed changed to: %f\r\n",res);
        #endif
    }

}


/*
 * Test the Merry Go Round
 */
 /*
int main() {
    
    merry_spin(0.8,true);
    wait(1);
    merry_change();
    wait(1);
    merry_change();
    wait(1);
    merry_change();
    wait(1);
    merry_change();
    wait(2);
    merry_stop();

}
*/
