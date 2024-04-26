#include "prise.h"

prise::prise()
{
io = acces_memoire(&shmid);
}

void prise::verouiller_trappe()
{
io->led_trappe=OFF;
}

void prise::deverouiller_trappe()
{
io->led_trappe=VERT;
}

void prise::set_prise(led couleur)
{
io->led_prise=couleur;
}
