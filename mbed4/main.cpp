/*
Sujith Pottem
ESE 519
Group 4
Final Project
Servo Motor Control 
*/

#include "mbed.h"
#include "Servo.h"
#include <time.h>
#include <stdlib.h>
#include "rtos.h"
#include "notes.h"

#define NUM_LED_STATES  8
#define NUM_SPINS       10
#define SIZE_UP         16
#define STALL_TIME_MS_1 40
#define STALL_TIME_MS_2 150
#define ON              1
#define OFF             0
#define NUM_TARGETS     3
Queue<int,16> queue;


//Output to score and to sound
PwmOut sounds(p24);
RawSerial serial(p28,p27);
//Ramp
PwmOut     red(p21);
PwmOut     green(p22);
PwmOut     blue(p23);


//Need an interrupt in and a PWM out

// Three Sets of Targets 
InterruptIn target1(p15);
BusOut target1led(p16,p17,p18);

InterruptIn target2(p11);
BusOut target2led(p12,p13,p14);

InterruptIn target3(p5);
BusOut target3led(p8,p9,p10);
//Set up arrays
BusOut targets[NUM_TARGETS] = {target1led,target2led,target3led};
int flags[NUM_TARGETS] = {0};

InterruptIn bumper1(p29);
InterruptIn bumper2(p30);

int flag1,flag2,flag3,led,bingo;

int bump_flag;

const unsigned short coinSound[NUM_LED_STATES] = {C5,D5,E5,F5,G5,A5,B5,0};
const unsigned short going_up[SIZE_UP] = {C2,E2,G2,B2,D3,F3,A3,C4,
                                          E4,G4,B4,D5,F5,A5,C6,E6};


void targetInterrupt1(){
    flag1 = 1;
}
void targetInterrupt2(){
    flag2 = 1;
}
void targetInterrupt3(){
    flag3 =1;
}

void bumperInterrupt(){
    bump_flag = 1;
    //BumperOut = ON;
}


void changeLEDS(int r, int b, int g, int wait){
    red   = r;
    blue  = b;
    green = g;
    wait_ms(wait);
}

// This functions flashes the leds
// Really this should be made into an array
void flash(){
    int wait = STALL_TIME_MS_2;
    for(int i = 0; i<10; i++){
        changeLEDS(ON ,ON ,ON ,wait);
        changeLEDS(OFF,OFF,OFF,wait); 
        changeLEDS(ON ,OFF,OFF,wait);
        changeLEDS(OFF,OFF,OFF,wait);
        changeLEDS(OFF,ON ,OFF,wait);
        changeLEDS(OFF,OFF,OFF,wait);
        changeLEDS(OFF,OFF,ON ,wait);
        changeLEDS(OFF,OFF,OFF,wait);
        wait_ms(STALL_TIME_MS_1);  
    }
}


void thread(void const* args){
    const int target_num = *(const int*) args;
    while(1){
        //Check Flag
        if(flags[target_num]){
            //Report Score
            queue.put(&led);
            for(int i = 0; i<NUM_SPINS; i++){
                int num = rand()%NUM_LED_STATES;
                targets[target_num].write(num);
                sounds.period(1.0/coinSound[num]); 
                sounds = 0.25;              
                Thread::wait(100);
            }
            sounds.period(1.0/0.0); 
            sounds = 0.25;              
            //resetflag
            flags[target_num] = 0;
        }  
        Thread::wait(100);
    }

}
// What do we need?
// The target and the flag
void thread1(void const* args){
    // Get the LED
    printf("Hi!\r\n");
    while(1){
        //Check Flag
        if(flag1){
            //Report Score
            queue.put(&led);
            for(int i = 0; i<NUM_SPINS; i++){
                int num = rand()%NUM_LED_STATES;
                target1led.write(num);
                sounds.period(1.0/coinSound[num]); 
                sounds = 0.25;              
                Thread::wait(100);
            }
            sounds.period(1.0/0.0); 
            sounds = 0.25;              
            //resetflag
            flag1 = 0;
        }  
        Thread::wait(100);
    }
}
void thread2(void const* args){
    // Get the LED
    printf("Hi!\r\n");
    while(1){
        //Check Flag
        if(flag2){
            //Report Score
            queue.put(&led);
            for(int i = 0; i<NUM_SPINS; i++){
                int num = rand()%NUM_LED_STATES;
                target2led.write(num);
                sounds.period(1.0/coinSound[num]); 
                sounds = 0.25;  
                Thread::wait(100);
            }
            sounds.period(1.0/0.0); 
            sounds = 0.25;   
            //resetflag
            flag2 = 0;
        }  
        Thread::wait(100);
    }
}

void bonus(){
    queue.put(&bingo);
    }
void thread3(void const* args){
    // Get the LED
    printf("Hi!\r\n");
    while(1){
        //Check Flag
        if(flag3){
            //Report Score
            queue.put(&led);
            for(int i = 0; i<NUM_SPINS; i++){
                int num = rand()%NUM_LED_STATES;
                target3led.write(num);
                sounds.period(1.0/coinSound[num]); 
                sounds = 0.25;  
                Thread::wait(100);
            }
            sounds.period(1.0/0.0); 
            sounds = 0.25; 
            //resetflag
            flag3 = 0;
        }  
        Thread::wait(100);
    }
}
 
void sendScores(void const* args){
   while(1){
   osEvent evt = queue.get();
    if (evt.status == osEventMessage) {
        char toSend = *(char*)  evt.value.v;;//queue.get();
        printf("Sent: %d\r\n",toSend);
        serial.putc(toSend);
    }
     Thread::wait(10);
   }


}
// This main controls the following things
// 2 servos 
// limit siwtchess and led
int main() 
{   
    

   
    sounds = 0.25;
    sounds.period(1.0/0.0);
    led = 1;
    bingo = 2;
    Thread score(sendScores); 
    target1.rise(&targetInterrupt1);
    Thread t1(thread1); // Thread t1(thread1, 0);
    target2.rise(&targetInterrupt2);
    Thread t2(thread2); // Thread t1(thread1, 1);
    target3.rise(&targetInterrupt3);
    Thread t3(thread3); // Thread t1(thread1, @);
    target1led = 0; 
    srand(time(NULL));    
    wait(2);
    
    while(1){
       // if( target1led.read() == target2led.read() && target1led.read() == target3led.read()){
        //    bonus();  
        //}
        Thread::wait(100);
    }
}
