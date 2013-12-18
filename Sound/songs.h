/*
Michael Posner
ESE 519 Final Project
Song definitions
*/


#ifndef SONGS_H
#define SONGS_H


#include "notes.h"

const unsigned short smkwtr[32] ={D4,D4,F4,F4,G4,G4,0,D4,0,F4,0,Ab4,G4,G4,0,0,
D4,D4,F4,F4,G4,G4,0,F4,0,D4,D4,D4,D4,0,0,0};      

const unsigned short happyBirthday[32] ={G4,G4,A4,G4,C4,B4,0,0,G4,G4,A4,G4,D4,C4,0,0,
G4,G4,G4,E4,C4,B4,A4,0,0,F4,F4,E4,C4,D4,C4,0}; 


//MARIO THEME -------------------------------------------
//each note is a quarter note, each line is one staff line of the music

float mario_duty = 0.25;
int mario_speed = 125;

const unsigned short marioThemeTreble[272] = 
{E5,E5,0,E5,0,C5,E5,C5,G5,0,0,0,G4,0,0,0,

C5,0,0,G4,0,0,E4,0,0,A4,0,B4,0,Bb4,A4,0,
G4,E5,G5,0,A5,0,F5,G5,0,E5,0,C5,D5,B4,0,0,
C5,0,0,G4,0,0,E4,0,0,A4,0,B4,0,Bb4,A4,0,
G4,E5,G5,0,A5,0,F5,G5,0,E5,0,C5,D5,B4,0,0,

0,0,G5,Gb5,F5,Ds5,0,E5,0,Gs4,A4,C5,0,A4,C5,D5,
0,0,G5,Gb5,F5,Ds5,0,E5,0,C6,0,C6,C6,0,0,0,
0,0,G5,Gb5,F5,Ds5,0,E5,0,Gs4,A4,C5,0,A4,C5,D5,
0,0,Eb5,0,0,D5,0,0,C5,0,0,0, 0,0,0,0,

0,0,G5,Gb5,F5,Ds5,0,E5,0,Gs4,A4,C5,0,A4,C5,D5,
0,0,G5,Gb5,F5,Ds5,0,E5,0,C6,0,C6,C6,0,0,0,
0,0,G5,Gb5,F5,Ds5,0,E5,0,Gs4,A4,C5,0,A4,C5,D5,
0,0,Eb5,0,0,D5,0,0,C5,0,0,0, 0,0,0,0,

C5,C5,0,C5,0,C5,D5,0,E5,C5,0,A4,G4,0,0,0,
C5,C5,0,C5,0,C5,D5,E5, 0,0,0,0, 0,0,0,0,
C5,C5,0,C5,0,C5,D5,0,E5,C5,0,A4,G4,0,0,0,
E5,E5,0,E5,0,C5,E5,C5,G5,0,0,0,0,0,0,0 };

const unsigned short marioThemeBass[256] = 
{D3,D3,0,D3,0,D3,D3,0,0,0,0,0,G3,0,0,0,

G3,0,0,E3,0,0,C3,0,0,F3,0,G3,0,Gb3,F3,0,
E3,C4,E4,0,F4,0,D4,E4,0,C4,0,A4,B4,G4,0,0,
G3,0,0,E3,0,0,C3,0,0,F3,0,G3,0,Gb3,F3,0,
E3,C4,E4,0,F4,0,D4,E4,0,C4,0,A4,B4,G4,0,0,

C3,0,0,G3,0,0,C4,0,F3,0,0,C4,C4,0,F3,0,
C3,0,0,E3,0,0,G3,C4,0,0,0,0,0,0,G3,0,
C3,0,0,G3,0,0,C4,0,F3,0,0,C4,C4,0,F3,0,
C3,0,Ab3,0,0,Bb3,0,0,C4,0,0,G3,G3,0,C3,0,

C3,0,0,G3,0,0,C4,0,F3,0,0,C4,C4,0,F3,0,
C3,0,0,E3,0,0,G3,C4,0,0,0,0,0,0,G3,0,
C3,0,0,G3,0,0,C4,0,F3,0,0,C4,C4,0,F3,0,
C3,0,Ab3,0,0,Bb3,0,0,C4,0,0,G3,G3,0,C3,0,

Ab2,0,0,Eb3,0,0,Ab3,0,G3,0,0,C3,0,0,G2,0,
Ab2,0,0,Eb3,0,0,Ab3,0,G3,0,0,C3,0,0,G2,0,
Ab2,0,0,Eb3,0,0,Ab3,0,G3,0,0,C3,0,0,G2,0 };


//AGE OF EMPIRES THEME -------------------------------------------
//each node is an eighth note, each line is 1 measure

float aoe_duty = 0.25;
int aoe_speed = 140;

const unsigned short ageOfEmpires[200] = 
{A5,A5, A5,A5, A5,A5, A4,A4,
D5,D5, D5,D5, D5,F5, E5,D5,
E5,E5, E5,E5, E5,E5, A4,A4,
D5,D5, D5,D5, D5,F5, E5,D5,
G5,G5, G5,G5, G5,G5, A4,A4,
D5,D5, D5,D5, D5,F5, E5,D5,

E5,E5, E5,E5, E5,E5, E5,E5,
E5,E5, E5,E5, E5,F5, E5,C5,
D5,D5, D5,D5, D5,D5, D5,D5,
G5,G5, Fs5,G5, A5,Bb5, C5,C5,
G5,G5, Ds5,Ds5, D5,D5, G4,G4,
G5,G5, G5,A5, Bb5,C5, Bb5,Bb5,

A5,A5, Fs5,Fs5, G5,G5, G5,G5,
G5,D5, D5,F5, A5,Bb5, G5,Eb5,
D5,D5, Eb5,Eb5, D5,D5, G4,G4,
G5,G5, G5,A5, Bb5,C5, Bb5,Bb5,
A5,A5, Fs5,Fs5, G5,G5, E5,E5,
A5,A5, A5,A5, A5,C6, B5,A5,

B5,B5, B5,B5, B5,B5, E5,E5,
A5,A5, A5,A5, A5,C6, B5,A5,
D6,D6, D6,D6, D6,D6, E5,E5,
A5,A5, A5,A5, A5,C6, B5,A5,
B5,B5, B5,B5, B5,B5, B5,B5,
B5,B5, B5,B5, B5,C6, B5,G5,
A5,A5, A5,A5, A5,A5, A5,A5};



//POKEMON WILD BATTLE THEME -------------------------------------------
//each node is an eighth note, each line is 1 measure

float poke_duty = 0.25;
int poke_speed = 125;

const unsigned short wildPokemon[448] = 
{G5,G5, 0,G4, G4,0, G4,G4,
0,0, 0,0, G4,G4, 0,0,

0,0, 0,G4, G4,0, G4,G4,
0,0, 0,Fs4, Fs4,Fs4, Fs4,Fs4,
G4,G4, 0,G4, G4,0, G4,G4,
0,0, 0,0, G4,G4, 0,0,

0,0, 0,G4, G4,0, G4,G4,
0,0, 0,G4, G4,G4, G4,G4,
G4,G4, G4,Fs4, Fs4,Fs4, E4,E4,

G4,G4, G4,A4, A4,A4, G4,G4,
Ab5,Ab5, Ab5,Ab5, Ab5,Ab5, G5,G5,

Ab5,G5, 0,0, Db6,Db6, Db6,Db6,
C5,C5, C5,Bb4, Bb4,Bb4, Ab4,Ab4,

Db5,Db5, Db5,C5, C5,C5, Bb4,Bb4,
F5,F5, F5,E5, E5,E5, D5,D5,

Bb4,Bb4, C5,C5, D5,D5, F5,F5,
Ab5,Ab5, Ab5,Ab5, Ab5,Ab5, Ab5,Ab5,

Ab5,Ab5, Ab5,Ab5, Ab5,Ab5, Ab5,Ab5,
G5,G5, G5,G5, G5,G5, G5,G5,

G5,G5, G5,G5, G5,G5, G5,G5,
F4,F4, F4,F4, Bb4,Bb4, Bb4,Bb4,
D5,D5, D5,D5, F5,F5, F5,F5,

E5,E5, E5,E5, E5,E5, E5,E5,
E5,E5, E5,E5, E5,E5, E5,E5,
F4,F4, F4,F4, Bb4,Bb4, Bb4,Bb4,
D5,D5, D5,D5, F5,F5, F5,F5,

G5,G5, G5,G5, G5,G5, G5,G5,
C6,C6, C6,C6, C6,C6, C6,C6,
E5,E5, E5,E5, E5,0, E5,E5,
F5,E5, 0,0, 0,0, 0,0,

F5,F5, F5,F5, F5,0, F5,F5,
Ab5,G5, G5,G5, F5,F5, F5,F5,


G4,G4, G4,Fs4, Fs4,Fs4, E4,E4,

G4,G4, G4,A4, A4,A4, G4,G4,
Ab5,Ab5, Ab5,Ab5, Ab5,Ab5, G5,G5,

Ab5,G5, 0,0, Db6,Db6, Db6,Db6,
C5,C5, C5,Bb4, Bb4,Bb4, Ab4,Ab4,

Db5,Db5, Db5,C5, C5,C5, Bb4,Bb4,
F5,F5, F5,E5, E5,E5, D5,D5,

Bb4,Bb4, C5,C5, D5,D5, F5,F5,
Ab5,Ab5, Ab5,Ab5, Ab5,Ab5, Ab5,Ab5,

Ab5,Ab5, Ab5,Ab5, Ab5,Ab5, Ab5,Ab5,
G5,G5, G5,G5, G5,G5, G5,G5,

G5,G5, G5,G5, G5,G5, G5,G5,
F4,F4, F4,F4, Bb4,Bb4, Bb4,Bb4,
D5,D5, D5,D5, F5,F5, F5,F5,

E5,E5, E5,E5, E5,E5, E5,E5,
E5,E5, E5,E5, E5,E5, E5,E5,
F4,F4, F4,F4, Bb4,Bb4, Bb4,Bb4,
D5,D5, D5,D5, F5,F5, F5,F5,

G5,G5, G5,G5, G5,G5, G5,G5,
C6,C6, C6,C6, C6,C6, C6,C6,
E5,E5, E5,E5, E5,0, E5,E5,
F5,E5, 0,0, 0,0, 0,0,

F5,F5, F5,F5, F5,0, F5,F5,
Ab5,G5, G5,G5, F5,F5, F5,F5};



//SUPER SMASH BROS THEME -------------------------------------------
//each node is a 16th note, each line is 1 measure

float smash_duty = 0.25;
float smash_speed = 80;

const unsigned short superSmashBros[512] = 
{B4,B4,Fs4,B4, Fs5,Fs5,Fs5,Fs5, 0,0,B4,B4, Fs5,Fs5,A5,A5,
Gs5,Gs5,E5,E5, B4,B4,B4,B4, B4,B4,B4,B4, 0,0,B4,Cs5,
D5,D5,D5,D5, D5,D5,D5,D5, 0,0,B4,B4, D5,D5,Fs5,Fs5,
E5,E5,E5,E5, E5,E5,E5,E5, E5,E5,E5,E5, E5,E5,E5,E5,

B4,B4,Fs4,B4, Fs5,Fs5,Fs5,Fs5, 0,0,B4,B4, Fs5,Fs5,A5,A5,
Gs5,Gs5,E5,E5, B4,B4,B4,B4, B4,B4,B4,B4, 0,0,B4,Cs5,
D5,D5,D5,D5, D5,D5,D5,D5, G3,G3,G3,D4, D4,B3,B3,B3,
Fs4,Fs4,Fs4,Fs4, Fs4,Fs4,Fs4,Fs4, Fs4,Fs4,Fs4,Fs4, Fs4,Fs4,Fs4,Fs4,

B3,B3,Fs3,B3, Fs4,Fs4,Fs4,Fs4, 0,0,B3,B3, Fs4,Fs4,A4,A4,
Gs4,Gs4,E4,E4, B3,B3,B3,B3, B3,B3,B3,B3, 0,0,B3,Cs4,
D4,D4,D4,D4, D4,D4,D4,D4, 0,0,B3,B3, D4,D4,Fs4,Fs4,
E4,E4,E4,E4, E4,E4,E4,E4, E4,E4,E4,E4, E4,E4,E4,E4,

B3,B3,Fs3,B3, Fs4,Fs4,Fs4,Fs4, 0,0,B3,B3, Fs4,Fs4,A4,A4,
Gs4,Gs4,E4,E4, B3,B3,B3,B3, B3,B3,B3,B3, 0,0,B3,Cs4,
D4,D4,D4,D4, D4,G4,A4,B4, C5,C5,C5,C5, 0,0,G5,A5,
B5,B5,B5,B5, B5,B5,D6,E6, Fs6,Fs6,Fs6,Fs6, Fs6,Fs6,Fs6,Fs6,

D5,D5,B4,D5, G5,G5,G5,G5, G5,G5,Fs5,Fs5, E5,E5,D5,D5,
D5,D5,D5,D5, Cs5,Cs5,Cs5,Cs5, Cs5,Cs5,Cs5,Cs5, A4,A4,A4,A4,
B4,B4,B4,B4, B4,B4,D5,D5, G5,G5,G5,Fs5, Fs5,E5,E5,E5,
A5,A5,A5,A5, A5,A5,A5,A5, A5,A5,A5,A5, A5,A5,A5,A5, 
As3,As3,D4,F4, As4,As4,As4,As4, As4,As4,A4,A4, G4,G4,F4,F4,

F4,F4,E4,E4, E4,E4,E4,E4, E4,E4,E4,E4, C4,C4,C4,C4,
F4,F4,F4,F4, F4,F4,F4,F4, F4,F4,F4,G4, G4,A4,A4,A4,
G4,G4,G4,G4, G4,G4,G4,G4, G4,G4,G4,G4, G4,G4,G4,G4,
B4,B4,G4,B4, G5,G5,G5,G5, G5,G5,Fs5,Fs5, E5,E5,D5,D5,
D5,D5,Cs5,Cs5, Cs5,Cs5,Cs5,Cs5, Cs5,Cs5,Cs5,Cs5, A4,A4,A4,A4,

B4,B4,G4,B4, G5,G5,G5,G5, G5,G5,Fs5,Fs5, E5,E5,D5,D5,
E5,E5,E5,E5, A5,B5,A5,B5, A5,B5,A5,B5, A5,B5,A5,B5,
G5,G5,D5,G5, D6,D6,D6,D6, D6,D6,C6,C6, As5,As5,A5,A5,

G5,G5,G5,G5, F5,F5,F5,F5, F5,F5,F5,F5, C5,C5,C5,C5,
D5,D5,D5,D5, D5,D5,D5,0, D5,D5,D5,Cs5, Cs5,D5,D5,D5,
E5,E5,E5,E5, E5,E5,E5,E5, E5,E5,E5,E5, E5,E5,E5,E5 };




const unsigned short coinSound[2] = {B5, E5};



#endif