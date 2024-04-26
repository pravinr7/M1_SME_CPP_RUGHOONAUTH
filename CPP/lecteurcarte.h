#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H


#include <lcarte.h>
#include "generateur_save.h"
#include "timer.h"
#include "voyants.h"
#include "boutons.h"
#include "base_client.h"

class LecteurCarte
{
	public :
	LecteurCarte();
	void initialiser();
	void lire_carte();
	voyants voy;
	boutons bout;
	prise pri;
	timer tim;
	BaseClient bc;
	generateur_save sav ;
	int num1, num2;
	char enService;
	
};

#endif
