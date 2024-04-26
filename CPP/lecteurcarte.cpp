#include "lecteurcarte.h"

LecteurCarte::LecteurCarte(){};

void LecteurCarte::initialiser()
{
	initialisations_ports();
	num1 =0;
	num2=0;
	enService=0;
}

void LecteurCarte::lire_carte()
{
	cout<<"Veuillez inserer votre carte svp !" <<endl;
	attente_insertion_carte();
	if(1)
	{
		num1= lecture_numero_carte(); // lecture du numero de la carte inseree
		cout<<"Votre numero de carte est"<<num1<<endl;
		
		if((bc.authentification(num1)) && voy.dispo()) //auth ok et  borne dispo
		{
			cout<<"Vous etes bien authentifies!"<<endl;
			
			enService=1;
			tim.raz();
			voy.blink_charge();
			
			
			do
			{
				if (bout.charge())
				{
					voy.set_dispo(OFF);
					cout<<"Veuillez retirer votre carte svp!"<<endl;
					attente_retrait_carte();
					sav.charger(); // chargement de batterie
					cout<<"Veuillez inserer votre carte svp !"<<endl;
					do
					{
						attente_insertion_carte();
						num2= lecture_numero_carte(); // relecture du numero de la carte inseree
						if(num1!=num2)
						{
							cout<<"Vous avez mal saisi votre numero de carte"<<endl;
						}
						sleep(1);
					}while(num1!=num2);
					
					sav.deconnecter();
					cout<<"Veuillez retirer votre carte svp"<<endl;
					attente_retrait_carte();
					if(bout.stop())
					{
						cout<<"*** Charge arreté maunuellement ***"<<endl;
					}
					enService=0;
					cout<<"*** Operation terminee ***"<<endl;
						
				}
			}while(tim.valeur()<10 && enService==1);
			
			if (enService==0)
			{
				cout<<"***Votre vehicule est chargé ! ***"<<endl;
			}
			
			else
			{
				cout<<"*** Temps ecoule ***"<<endl;
				cout<<"Veuillez retirer votre carte"<<endl;
				attente_retrait_carte();
			}
			
			//Renitialisation
			voy.set_dispo(VERT);
			tim.raz();
			bout.boutons_initialiser();
			enService=0;
		}// end auth ok client
		
		else //si auth fail
		{
			cout<<"Authenfication error"<<endl;
			voy.blink_defaut();
		}
	}//end if carte inseree
}
