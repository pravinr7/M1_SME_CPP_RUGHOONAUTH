#include "voyants.h"

voyants::voyants()
{
io = acces_memoire(&shmid);
}


void voyants::set_dispo(led couleur)
{
io->led_dispo=couleur;
}

void voyants::set_charge(led couleur)
{
io->led_charge=couleur;
}

void voyants::blink_charge()
{
int i;
for(i=0;i<8;i++)
{
	io->led_charge=VERT;
	usleep(500000);
	io->led_charge=OFF;
	usleep(500000);
}		
}

void voyants::blink_defaut()
{
int i;
for(i=0;i<8;i++)
{
	io->led_defaut=ROUGE;
	usleep(500000);
	io->led_defaut=OFF;
	usleep(500000);
}		
}

int voyants::dispo()
{
return io->led_dispo;
}

	



