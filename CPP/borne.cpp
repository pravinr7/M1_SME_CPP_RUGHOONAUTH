#include <iostream>
#include "lecteurcarte.h"
#include "voyants.h"
#include "base_client.h" // Inclusion de base_client.h

using namespace std; // Utilisation du namespace std

void afficherMenu() {
    cout << "===== Interface d'accueil =====" << endl;
    cout << "1. Mode Charge" << endl;
    cout << "2. Gestion des clients" << endl;
    cout << "================================" << endl;
    cout << "Entrez votre choix : ";
}

int main()
{
    LecteurCarte lc;
    lc.initialiser();
    BaseClient bc; // Création d'un objet BaseClient
    
    while(1)
    {
        int choix;
        do {
            afficherMenu();
            cin >> choix;
            switch (choix) {
                case 1:
                    cout << "Vous avez choisi le mode Charge." << endl;
                    lc.lire_carte(); // Lire la carte
                    break;
                case 2:
                    cout << "Vous avez choisi la Gestion des clients." << endl;
                    // Gestion des clients
                    int choixGestion;
                    do {
                        cout << "1. Ajouter un client" << endl;
                        cout << "2. Supprimer un client" << endl;
                        cout << "3. Afficher les clients" << endl;
                        cout << "4. Retour au menu principal" << endl;
                        cout << "Entrez votre choix : ";
                        cin >> choixGestion;
                        int numeroCarte;
                        switch (choixGestion) {
                            case 1:
                                cout << "Entrez le numéro de carte à ajouter : ";
                                cin >> numeroCarte;
                                bc.ajouterClient(numeroCarte); // Appel de la fonction ajouterClient
                                break;
                            case 2:
                                cout << "Entrez le numéro de carte à supprimer : ";
                                cin >> numeroCarte;
                                bc.supprimerClient(numeroCarte); // Appel de la fonction supprimerClient
                                break;
                            case 3:
                                bc.afficherClients(); // Appel de la fonction afficherClients
                                break;
                            case 4:
                                break; // Retour au menu principal
                            default:
                                cout << "Choix invalide. Veuillez réessayer." << endl;
                        }
                    } while (choixGestion != 4);
                    break;
                default:
                    cout << "Choix invalide. Veuillez réessayer." << endl;
            }
        } while (choix != 1 && choix != 2);

    }
    
    return 0;
}


