
#define threshold1 1
#define threshold2 0.95
#define threshold3 0.95
#define threshold4 0.95
#define threshold5 0.95

#define STICKY_TIME 2
#define ON  1
#define OFF 0
#define MAX_READINGS 10
#define AVG_THRESH   0.1

#define STALL_TIME_2 0.01
#define STALL_TIME_3 0.005

PwmOut     red(p21);
PwmOut     green(p22);
PwmOut     blue(p23);

AnalogIn pDiode1(p15);
AnalogIn pDiode2(p16);
AnalogIn pDiode3(p17);
AnalogIn pDiode4(p18);
AnalogIn pDiode5(p19);

DigitalOut rampDiode1(p5);
DigitalOut rampDiode2(p6);
DigitalOut rampDiode3(p7);
DigitalOut rampDiode4(p8);
DigitalOut rampDiode5(p9);

DigitalOut score(p28);

Ticker t1, t2, t3, t4, t5;

float rise_time = STALL_TIME_3;
float fall_time = STALL_TIME_2;
float wait_time = STALL_TIME_3;
 
double avg1 = 0;
double avg2 = 0;
double avg3 = 0;
double avg4 = 0;
double avg5 = 0;

int count = 0;
int steplightDiode = 1;
int ballPassFlag = 0;