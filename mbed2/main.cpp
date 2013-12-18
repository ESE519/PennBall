#include "mbed.h"
#include "Servo.h"
// speaker sound effect demo using PWM hardware output

int note;
unsigned short i = 0;

#define DEFAULT_WRITE_LEGNTH 0.5
#define STALL_TIME_MS_3      10
#define HALFWAY              50
#define STEPS                25
#define RANDOM_RANGE         100
#define OFF                  0
#define INITIALIZATION_TIME  2

PwmOut speaker(p25);

Servo servoMerry(p21);
Servo servoSlider(p22);

int rSlider, rMerry;


InterruptIn b1(p5);
InterruptIn b2(p6);
InterruptIn b3(p7);
InterruptIn b4(p8);

RawSerial ser(p9, p10);  //to scoreboard


Ticker servo1;
Ticker servo2;

void bumperScore(void) {
    printf("Bumper score\r\n");
    ser.putc('1');
}



//Controls the merry go round
//Chooses a random number for the speed
void sMerry(){

    if(rMerry<=HALFWAY){
        for(int i=HALFWAY-STEPS; i<HALFWAY; i++){
             servoMerry = i/(double) RANDOM_RANGE;
             wait_ms(STALL_TIME_MS_3);
        }
    }
    else{
        for(int i=HALFWAY+STEPS; i>HALFWAY; i--){
             servoMerry = i/(double)  RANDOM_RANGE;
             wait_ms(STALL_TIME_MS_3);
        }
    }
    servoMerry.write(DEFAULT_WRITE_LEGNTH);
    rMerry = rand() % RANDOM_RANGE;
    servoMerry.write(rMerry/(double) RANDOM_RANGE);
    
    
 }
 
 
//Controls the moving target 
//Chooses a random number for the speed
void sSlider()
{
     
   for(int i=HALFWAY-STEPS; i<HALFWAY; i++){
          servoSlider = i/(double) RANDOM_RANGE;
          wait_ms(STALL_TIME_MS_3);
   }
    servoSlider.write(DEFAULT_WRITE_LEGNTH);
    rSlider = (rand() % (HALFWAY/2))+(HALFWAY/2);
    servoSlider.write(rSlider/(double) RANDOM_RANGE);
 }


int main()
{
    rMerry  = OFF;
    rSlider = OFF;
   
    
    b1.rise(&bumperScore);
    b2.rise(&bumperScore);
    b3.rise(&bumperScore);
    b4.rise(&bumperScore);
    
    servo1.attach(&sSlider,5);
    servo2.attach(&sMerry,2);
    srand(time(NULL));    
    wait(INITIALIZATION_TIME);
    while(1) {
        
        
        
        
        
        
    }
}