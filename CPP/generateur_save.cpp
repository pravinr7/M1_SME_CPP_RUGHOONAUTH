#include "generateur_save.h"

//definition des etats

#define etat0 0 
#define etat1 1 
#define etat2 2 
#define etat3 3 
#define etat4 4 
#define etat5 5
#define etat6 6  

// definition des transitions selon la machine à état vu en tD

#define T0_1 tension() ==9
#define T1_2 tension() ==6
#define T1_4 b.stop()
#define T2_3 tension() ==6
#define T2_4 b.stop()|| (tension() ==9)
#define T3_4 b.stop()|| (tension() ==9)
#define T5_6 tension() ==12

generateur_save::generateur_save()
{
io = acces_memoire(&shmid);
}

void generateur_save::generer_PWM(pwm mode)
{
io-> gene_pwm=mode;
sleep(1);
}

float generateur_save::tension()
{
return(io->gene_u);
}

void generateur_save:: ouvrir_AC()
{
io->contacteur_AC=0;
}

void generateur_save:: fermer_AC()
{
io->contacteur_AC=1;
}

void generateur_save::mef()
{
switch(etat)
	{
	//attend le branchement de la prise
	case etat0:
			if(T0_1)
			{	
				etat=etat1;
			}
			break;
	
	//prise branchee
	case etat1:
			if(T1_2)
			{	
				etat=etat2;
			}
			else
			{	
				if(T1_4)
				{	
				etat=etat4;
				}
			}
			break;
	
	//attente du vehicule	
	case etat2:
			if(T2_3)
			{	
				etat=etat3;
			}
			else
			{	
				if(T2_4)
				{	
				etat=etat4;
				}
			}
			break;

	//voiture en charge
	case etat3:
			if(T3_4)
			{	
				etat=etat4;
			}
			break;
	
	//voiture chargee
	case etat4:
			break;

	//attend le debranchement de la prise
	case etat5:
			if(T5_6)
			{	
				etat=etat6;
			}
			break;

	//voiture prete pour reprise
	case etat6:
			break;

	default : etat=etat0;

	}

switch(etat)
	{
		// attente branchement de la prise pour charger la voiture
		case etat0: 
					v.set_charge(ROUGE);
					p.deverouiller_trappe();
					generer_PWM(DC);
					break;
	
		// prise bien branchee
		case etat1: 
					p.set_prise(ROUGE);
					p.verouiller_trappe();
					generer_PWM(AC_1K);
					break;

		// attente de la voiture
		case etat2: 
					fermer_AC();
					generer_PWM(AC_CL);
					break;

		// batterie chargee
		case etat4: 
					ouvrir_AC();
					v.set_charge(VERT);
					generer_PWM(DC);
					fin=1;					
					break;

		// attente reprise de la voiture
		case etat5: 
					v.set_charge(OFF);
					p.deverouiller_trappe();
					break;
		
		// voiture prete pour etre reprise
		case etat6: 
					p.verouiller_trappe();
					v.set_dispo(VERT);
					p.set_prise(OFF);
					fin=1;	
					break;
	}

}

void generateur_save::charger()
{
etat=0;
fin=0;
while(!fin)
	{
		mef();
	}
}

void generateur_save::deconnecter()
{
etat=5;
fin=0;
while(!fin)
	{
		mef();
	}
}







