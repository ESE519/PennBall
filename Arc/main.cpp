#include "mbed.h"
#include  <stdlib.h>
#include "main.h"
 
// This code is used in conjunction with the "arc"
// The arc is a series of ir/photodiode pairs with RGB LEDS
// When the ball passes over the ir/photodiode pair
// It will create a voltage spike across the photodiode sneding the input
// Pin high. Once we have recorded a pass the lights underneath 
// respond by lighting up in some fashion 
 
void colRed(){
    red   = ON;
    blue  = OFF;
    green = OFF;
}

void colBlue(){
    red   = OFF;
    blue  = ON;
    green = OFF;
}


void colGreen(){
    red   = OFF;
    blue  = OFF;
    green = ON;
}


void colOrange(){
    red   = 0.25;
    blue  = OFF;
    green = 0.5;
}


void colYellow(){
    red   = 0.25;
    blue  = OFF;
    green = ON;
}
 
 
 // This function Averages MAX_READINGS number of readings and gets an average for that pair
void setupReadings(){
    avg1 = 0;
    avg2 = 0;
    avg3 = 0;
    avg4 = 0;
    avg5 = 0;
    
    rampDiode1 = ON;
    rampDiode2 = ON;
    rampDiode3 = ON;
    rampDiode4 = ON;
    rampDiode5 = ON;
    
    for(int reading = 0; reading <= MAX_READINGS; reading++){
        avg1 += pDiode1.read();
        avg2 += pDiode2.read();
        avg3 += pDiode3.read();
        avg4 += pDiode4.read();
        avg5 += pDiode5.read();
        wait(0.1);
    }
    avg1 = avg1/MAX_READINGS;
    avg2 = avg2/MAX_READINGS;
    avg3 = avg3/MAX_READINGS;
    avg4 = avg4/MAX_READINGS;
    avg5 = avg5/MAX_READINGS;
    
    rampDiode1 = 0;
    rampDiode2 = 0;
    rampDiode3 = 0;
    rampDiode4 = 0;
    rampDiode5 = 0;
    printf("Avergage 1 : %f\r\nAvergage 2 : %f\r\nAvergage 3 : %f\r\nAvergage 4 : %f\r\nAvergage 5 : %f\r\n",avg1,avg2,avg3,avg4,avg5);
} 

    
void diode1()
{
    rampDiode1 = OFF;
    ballPassFlag = 0;
    t1.detach();
}

void diode2()
{
    rampDiode2 = OFF;
    ballPassFlag = 0;
    score = 0;
    t2.detach();
}

void diode3()
{
    rampDiode3 = OFF;
    ballPassFlag = 0;
     score = 0;
    t3.detach();
}

void diode4()
{
    rampDiode4 = OFF;
    ballPassFlag = 0;
     score = 0;
    t4.detach();
}
void diode5()
{
    rampDiode5 = OFF;
    ballPassFlag = 0;
    t5.detach();
}

void allDiodesOff()
{
    rampDiode1 = OFF;
    rampDiode2 = OFF;
    rampDiode3 = OFF;
    rampDiode4 = OFF;
    rampDiode5 = OFF; 
}


int main ()
{
    red          = ON;
    blue = green = ON;
    setupReadings();
    while(1)
    {
      
        if(pDiode1.read() > avg1 +0.1)//threshold1)
        {
            rampDiode1 = ON;
            ballPassFlag = 1;
            t1.attach(&diode1, STICKY_TIME); 
        } 
        if(pDiode2.read() > avg2 +0.1)//threshold2)
        {
            rampDiode2 = ON;
            ballPassFlag = 1;
            t2.attach(&diode2, STICKY_TIME); 
        }
         if(pDiode3.read() > avg3 +0.1)//threshold3)
        {
            rampDiode3 = ON;
            ballPassFlag = 1;
            t3.attach(&diode3, STICKY_TIME);         
        }
        
        if(pDiode4.read() > avg4 +0.1)//threshold4)
        {
            rampDiode4 = ON;
            ballPassFlag = 1;
            t4.attach(&diode4, STICKY_TIME); 
        }
        if(pDiode5.read() > avg +0.1)//threshold5)
        {
            rampDiode5 = ON;
            ballPassFlag = 1;
            t5.attach(&diode5, STICKY_TIME); 
        }        
        wait(.1);
        count++;
        
        if(count%2==0)
        {
                if(!ballPassFlag)
                {
                    
                    switch(steplightDiode)
                    {
                        case 1: allDiodesOff();
                                rampDiode1 = ON;
                        break;
                        case 2: allDiodesOff();
                                score = 1;
                                rampDiode2 = ON;
                        break;
                        case 3: allDiodesOff();
                                score = 1;
                                rampDiode3 = ON;
                        break;
                        case 4: allDiodesOff();
                                score = 1;
                                rampDiode4 = ON;
                        break;
                        case 5: allDiodesOff();
                                rampDiode5 = ON;
                        break;
                        
                    }
                     steplightDiode++;
                     if(steplightDiode >5)
                        steplightDiode = 1;
                }
        }
       
        
    }
}
  // The following is an alternate way of uusing the ramp.
  /*     switch(rampDiode1 + rampDiode2 + rampDiode3 + rampDiode4 + rampDiode5) {
            case 1: colRed(); break;
            case 2: colOrange(); break;
            case 3: colYellow(); break;
            case 4: colGreen(); break;
            case 5: colBlue(); score = 1; wait(0.005); score=0; break;
        
        }
        */