/*
Michael Posner
ESE 519
Group 4
Final Project
DC Motor Control for Moving Targets
*/

#include "moving_target.h"


#ifdef DEBUG
Serial pc(USBTX, USBRX); // tx, rx
#endif

Motor MT1(p22, p29, p30, 1); // Initialize the motor:  (pwm, fwd, rev, can brake)
Motor MT2(p22, p29, p30, 1); // Initialize the motor:  (pwm, fwd, rev, can brake)


//returns the sign of a number
static float sign (float num) {

    if(num < 0)
        return -1.0;
    else
        return 1.0;
}

/*
 * Start the moving target with the given speed 
 * in the given direction
 *
 * @param mtnum The motor to control (1 or 2)
 * @param speed Float from 0 - 1 that specifies the duty cycle
 * @param dir Direction for the motor to spin
 */
void mt_start(int mtnum, float speed, bool dir) {

    float res;

    if(dir) {
        if(mtnum == 1)
            res = MT1.speed(speed);
        else
            res = MT2.speed(speed);
    }
    else {
        if(mtnum == 1)
            res = MT1.speed(-1.0*speed);
        else
            res = MT2.speed(-1.0*speed);
    }
    
    #ifdef DEBUG
    pc.printf("mt_start:  motor: %d, res: %f\r\n",mtnum,res);
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
        pc.printf("mt_start:  motor: %d, Change of direction, trying again... ",mtnum);
        #endif
        
        if(dir) {
            if(mtnum == 1)
                res = MT1.speed(speed);
            else
                res = MT2.speed(speed);
        }
        else {
            if(mtnum == 1)
                res = MT1.speed(-1.0*speed);
            else
                res = MT2.speed(-1.0*speed);
        }
        
        #ifdef DEBUG
        pc.printf("mt_start:  motor: %d, 2nd res: %f\r\n",mtnum,res);
        #endif
        
    }
    
}

/*
 * Stops the given moving target.
 *
 * @param mtnum The motor to control (1 or 2)
 */
void mt_stop(int mtnum) {

    if(mtnum == 1)
        MT1.stop(0.7);
    else
        MT2.stop(0.7);
    
    #ifdef DEBUG
    pc.printf("mt_stop:  motor %d stopped.\r\n",mtnum);
    #endif
}



/*
 * Changes the speed and direction of the moving target
 *
 * @param mtnum The motor to control (1 or 2)
 */
void mt_change(int mtnum) {
    
    float mstate;
    
    //get current motor state
    if(mtnum == 1)
        mstate = MT1.state();
    else
        mstate = MT2.state();
        
        
    
    if(abs(mstate - (-3)) < 0.0001) { //if motor state is -3, theres an error
        #ifdef DEBUG
        pc.printf("mt_change:  motor %d was in error state\r\n",mtnum);
        #endif
    }
    else if ( (abs(mstate - (-2)) < 0.0001) || (abs(mstate - 2) < 0.0001) ) {  
        //motor state is either 2 (coasting) or -2 (braking)
        if(mtnum == 1)
            MT1.speed(0.6);
        else
            MT2.speed(0.6);
            
            
        #ifdef DEBUG
        pc.printf("mt_change:  motor %d was coasting or braking, changed to 0.6\r\n",mtnum);
        #endif
    }
    else {  //motor state is between -1 and 1 (running)
        float res;
        
        if(abs(mstate) > 0.5) {
        
            if(mtnum == 1)
                res = MT1.speed(-1.0*sign(mstate)*(abs(mstate)-0.3));
            else
                res = MT2.speed(-1.0*sign(mstate)*(abs(mstate)-0.3));
                
            if (res < 0.0001) {
                wait_ms(250);
                
                if(mtnum == 1)
                    res = MT1.speed(-1.0*sign(mstate)*(abs(mstate)-0.3));
                else
                    res = MT2.speed(-1.0*sign(mstate)*(abs(mstate)-0.3));
             
            }
        }
        else {
        
            if(mtnum == 1)
                res = MT1.speed(sign(mstate)*(abs(mstate) + 0.3));
            else
                res = MT2.speed(sign(mstate)*(abs(mstate) + 0.3));
                
        }    
    
        #ifdef DEBUG
        pc.printf("mt_change:  motor %d speed changed to: %f\r\n",mtnum,res);
        #endif
    }

}


/*
 * Test
 */
/*
int main() {
    
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
*/
