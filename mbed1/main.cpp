#include <stdio.h>
#include <stdlib.h>    
#include <main.h>
#include "mbed.h"
#include <rtos.h>
#include <math.h>
//Pins for spi


// We also need a 3x PWM out
PwmOut   red(p21);
PwmOut  blue(p22);
PwmOut green(p23);

DigitalOut CS(p5);
RawSerial serial1(p28, p27);  //for targets
RawSerial serial2(p9, p10);  //for bumpers (from servo mbed)
SPI spi(p11, NC, p13);
DigitalOut CS5(p12);

InterruptIn ir(p18);
InterruptIn arc(p15);
//Currently the code tells the P to be displayed simultaniously on four different channels
int bonus;

void assertCS(){
    CS = OFF;
    Thread::wait(LED_wait);
}

void deAssertCS(){
    CS = ON;
    Thread::wait(LED_wait);
}

void ir_interrupt(){
    multiplier++;
    bonus=ON;
}

void arc_interrupt(){
    count+=50;
}

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

void colTurq(){
    red   = OFF;
    blue  = ON;
    green = ON;

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

void colPurp(){
    red   = ON;
    blue  = ON;
    green = OFF;
}

void colYellow(){
    red   = 0.5;
    blue  = OFF;
    green = 0.75;
}

void colWhite(){
    red   = ON;
    blue  = ON;
    green = ON;

}

// Should we have more than one MUL thing 
void tell_mul(){
    for(int i = 0; i < NUM_MUL_FLASHES; i++){
        assertCS();
        spi.write(FRAME_START);
        for(int led = 0; led < size_leds; led++){
            spi.write(l1[led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(u2[led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(m1[led]);
        }
         for(int led = 0; led < size_leds; led++){
            spi.write(numbers[multiplier][led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(x1[led]);
        }
        deAssertCS();
        Thread::wait(10);
        assertCS();

        spi.write(FRAME_START);
        
        for(int led = 0; led < size_leds; led++){
            spi.write(~l1[led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(~u2[led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(~m1[led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(~numbers[multiplier][led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(~x1[led]);
        }
        deAssertCS();
        Thread::wait(100);
    }
}

//Tells the boards with the v5 firmware how many boards will be in a row
void setup_boards(){
    spi.write('%');
    Thread::wait(SPI_wait*10);
    spi.write(NUM_BOARDS); 
}

// Initalize the SPI connection
//Someitmes this requires a bunch of resets
//Sometimes it works the first time
//You can try adding in some more waits and seeing if that helps
void initSPI(){
    spi.format(bitsPerFrame,mode);
    spi.frequency(maxSpeed);
    setup_boards();
}


// Write the current value of count out to the Scoreboards


// Recive scores over the serial port
// THREAD SAFE
void serialScoring(void const* args){
    while(1){
        char data = serial1.getc();
        //printf("Got Data: %c\r\n");
        if(data == 2){ // Emulates the target hits 
            count+=multiplier*1000;

        }
        else{
            for(int i = 0; i<10; i++){
              count+=multiplier*rand()%8;
              Thread::wait(125);        
            }
        }
        Thread::wait(100);
    }
}


// Recive scores from bumpers over the serial port
// THREAD SAFE
void serialBumperScoring(void const* args){
    while(1){
        char data = serial2.getc();
        //printf("Got bumper Data: %c\r\n");
        if(data == '1'){ // Emulates the target hits 
            count+=10;

        }
        
        Thread::wait(200);
    }
}

void display_score(int tenThousands, int thousands, int hundreds, int tens, int ones){

        assertCS();
        spi.write(FRAME_START);
        for(int led = 0; led < size_leds; led++){
            spi.write(numbers[ones][led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(numbers[tens][led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(numbers[hundreds][led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(numbers[thousands][led]);
        }
        for(int led = 0; led < size_leds; led++){
            spi.write(numbers[tenThousands][led]);
        }
        deAssertCS();
        Thread::wait(10);

}


void led_thread(void const* args){
    colTurq();
    printf("arrived\r\n");
    while(1){
    
       if     (count % 600 < 100) colWhite();
       else if(count % 600 < 200) colRed();
       else if(count % 600 < 300) colPurp();
       else if(count % 600 < 400) colGreen();
       else if(count % 600 < 500) colYellow();
       else if(count % 600 < 600) colBlue();
       Thread::wait(1000);
    }
}
void test(void const* args){
    while(1){
     count++;
     Thread::wait(5);
   }

}

void run_count(void const* args){
    while(1){
        int tenThousands = (int) (count/10000) %10;
        int thousands = (int) (count/1000) %10;
        int hundreds = (int) (count/100) %10;
        int tens = (int) (count/10) %10;
        int ones = count%10;
        display_score(tenThousands, thousands, hundreds, tens, ones);
        Thread::wait(SPI_wait*10);
        if(bonus) tell_mul();
       // printf("Count: %d\r\n",count);
    }
}

// This function tells the LED board to turn all the lights red
int main() {
    printf("Hello!\r\n");
    count = 0;
    bonus = 0;
    multiplier = 1;
    initSPI();
    red.period(0.001);
    ir.rise(&ir_interrupt);
    arc.rise(&arc_interrupt);
    Thread one(led_thread);
    Thread two(run_count);
    Thread ser(serialScoring);
    Thread serb(serialBumperScoring);
    //Thread three(test);
    while(1);  
}
