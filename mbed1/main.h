
const int maxSpeed     = 100000;
const int bitsPerFrame = 8;
const int mode         = 0;
const int size_leds    = 64;
const int chain_size   = 2;

int count, multiplier;

#define OFF             0
#define ON              1
#define LED_wait        0.5
#define SPI_wait        10
#define NUM_BOARDS      5 
#define NUM_MUL_FLASHES 12
#define STALL_TIME_MS_1 40
#define STALL_TIME_MS_2 150
#define STALL_TIME_1 0.2
#define STALL_TIME_2 0.01
#define STALL_TIME_3 0.005
#define INCREMENT_1 0.1
#define INCREMENT_2 0.01

#define FRAME_START 0x26
#define RED     0xE0
#define GREEN   0x1C
#define BLUE    0x03
#define YELLOW  RED|GREEN
#define MAGENTA RED|BLUE
#define TEAL    BLUE|GREEN
#define WHITE   (RED|GREEN|BLUE)
#define ORANGE  11100100
#define BLACK   0x00

// ZERO
char zero[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,  
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};

//ONE
char one[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,   
    BLUE, BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, BLUE, RED,  RED,  BLUE, BLUE, BLUE,  
    BLUE, BLUE, BLUE, RED,  BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};

//TWO
char two[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE,  
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE,
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};

//THREE
char three[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE,  
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE,
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};    

//FOUR
char four[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,  
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE 
};

//FIVE
char five[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE,  
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};
    
//SIX    
char six[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE,  
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};

//SEVEN
char seven[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE,  
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE,
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE 
};

//EIGHT
char eight[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED, BLUE, BLUE,  RED,  BLUE, BLUE,  
    BLUE, BLUE, RED, BLUE, BLUE,  RED,  BLUE, BLUE,
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED, BLUE, BLUE,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED, BLUE, BLUE,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};

//NINE
char nine[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,  
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};


char* numbers[10] = {
    zero, one, two, three, four, 
    five, six, seven, eight, nine
};

char x1[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, RED,  BLUE, BLUE, BLUE, BLUE, RED,  BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,  
    BLUE, BLUE, BLUE, RED,  RED,  BLUE, BLUE, BLUE,
    BLUE, BLUE, BLUE, RED,  RED,  BLUE, BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, RED,  BLUE, BLUE, BLUE, BLUE, RED,  BLUE, 
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE 
};
char x2[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, RED, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, RED,  BLUE,  
    BLUE, BLUE, BLUE, RED,  BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE, BLUE, 
    BLUE, BLUE, BLUE, RED,  BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, BLUE, RED,  BLUE, 
    BLUE, RED,  BLUE, BLUE, BLUE, BLUE, BLUE, RED 
};
char m1[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, RED,  RED,  RED,  RED,  RED,  RED,  RED, 
    BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, RED,  
    BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, RED,
    BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, RED, 
    BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, RED, 
    BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, RED, 
    BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, RED 
};
char u2[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,  
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};
char l1[size_leds] = {
    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,    
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE,  
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE,
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, BLUE, BLUE, BLUE, RED,  BLUE, BLUE, 
    BLUE, BLUE, RED,  RED,  RED,  RED,  BLUE, BLUE 
};
// offset zero   nothing
// offset one      Ap + 1
// offset two      Ap + 2
// offset three    Ap + 3
// offset four     Ap + 4
// offset five     first 3 + 5 next 1 + 61 (diff 56)
// offset six      first 2 + 6 next 2 + 62 
// offset seven    first 1 + 7 next 3 + 63 
// offset eight    Ap + 64
// offset nine     Ap + 65 
// offset ten      Ap + 66
// offset eleven   Ap + 67 
// offset twelve   Ap + 68
// offset thirteen first 3  + 69 next 1 125 (diff 112)
// offset fourteen first 2  + 70 next 2 126
// offset fifteen  first 1  + 71 next 3 127
// offset fifteen  Ap + 128
// ...
    