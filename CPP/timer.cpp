#include "timer.h"

timer::timer()
{
io = acces_memoire(&shmid);

if (io==NULL)
	cout<<"EREEUR"<<endl;
}

void timer::raz()
{
start_timer=io->timer_sec;
}

int timer::valeur()
{
return io->timer_sec- start_timer;
}
