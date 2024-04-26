#include "boutons.h"

boutons::boutons()
{
	io = acces_memoire(&shmid);
}

void boutons::boutons_initialiser()
{
	io-> bouton_charge=0;
	io-> bouton_stop=0;
}

int boutons::charge()
{
	int bouton;
	bouton = io->bouton_charge;
	return bouton;

}

int boutons::stop()
{
	int bouton;
	bouton = io->bouton_stop;
	return bouton;

}
