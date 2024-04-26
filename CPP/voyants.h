#ifndef VOYANTS_H
#define VOYANTS_H

#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include <donnees_borne.h>
#include <memoire_borne.h>
using namespace std;

class voyants
{

entrees *io;
int shmid;

public :
voyants();
void set_dispo(led couleur);
void set_charge(led couleur);
void blink_charge();
void blink_defaut();
int dispo();


};



#endif
