#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include <memoire_borne.h>
#include <donnees_borne.h>

using namespace std;

class timer
{

entrees *io;
int shmid;
int start_timer;

public:

timer();
void raz();
int valeur();
};
#endif
