#include "mbed.h"
#include "notes.h"
#include "songs.h"

// speaker sound effect demo using PWM hardware output

PwmOut speaker(p25);
DigitalOut red(p18);
DigitalOut blue(p19);
DigitalOut green(p20);

int state = 0;



void colorFunction()
{

     if(state == 0)
     {
        red = 0;       green = 0;        blue = 1;
     }
     else
     if(state == 1)
     {
        red = 0;       green = 1;        blue = 0;
     }
     else
     if(state == 2)
     {
        red = 0;       green = 1;        blue = 1;
     }
          else
     if(state == 3)
     {
        red = 1;       green = 0;        blue = 0;
     }
          else
     if(state == 4)
     {
        red = 1;       green = 0;        blue = 1;
     }
          else
     if(state == 5)
     {
        red = 1;       green = 1;        blue = 0;
     }
          else
     if(state == 6)
     {
        red = 1;       green = 1;        blue = 1;
     }
          else
     if(state == 7)
     {
        red = 0;       green = 0;        blue = 0;
     }
     
     state++;
     if(state == 8)
        state = 0;
 
}


void play(const unsigned short * song, int song_length, float duty, float speed) {

    for(int i = 0; i< song_length; i++){
        if(i==0) {
            speaker.period(1.0/song[i]); 
            speaker = duty;
        }
        else if(song[i] != song[i-1]) {  //to eliminate re-starting pwm for same note (sounds bad)
            speaker.period(1.0/song[i]); 
            
            if(song_length-i < 40){
                if((song_length - i)/40 > 0.6)
                    speaker = duty * (song_length-i)/30;
                else
                    speaker = duty * 0.6;  //fade out, but dont go silent
            }
            else
                speaker = duty;
        }
        
        wait_ms(speed);   
        colorFunction();  
    }
    
    speaker = 0;
    

}


int main()
{
    Ticker changeColors;
    red = 1;
    blue = 1;
    green = 1;
    
       
    wait(1);

    while(1) {
        
        play(marioThemeTreble,272,mario_duty,mario_speed);
        wait(2);
        
        play(ageOfEmpires,200,aoe_duty,aoe_speed);
        wait(2);
        
        play(wildPokemon,448,poke_duty,poke_speed);
        wait(2);
        
        play(superSmashBros,512,smash_duty,smash_speed);
        wait(2);
        
        wait(3);
    }
}