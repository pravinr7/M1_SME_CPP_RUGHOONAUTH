#include "base_client.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> lireNumerosClients() {
    vector<int> numeros;
    ifstream fichier("fichier_clients.txt");
    if (!fichier.is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier." << endl;
        return numeros;
    }
    int numero;
    while (fichier >> numero) {
        numeros.push_back(numero);
    }
    fichier.close();
    return numeros;
}

bool BaseClient::authentification(int numeroCarte) {
    vector<int> numeros = lireNumerosClients();
    for (int num : numeros) {
        if (num == numeroCarte) {
            //cout << "Vous êtes authentifiés." << endl;
            return true;
        }
    }
    cout << "Numéro de carte non trouvé." << endl;
    return false;
}

bool BaseClient::ajouterClient(int numeroCarte) {
    vector<int> numeros = lireNumerosClients();
    for (int num : numeros) {
        if (num == numeroCarte) {
            cout << "Le numéro de carte existe déjà." << endl;
            return false;
        }
    }
    ofstream fichier("fichier_clients.txt", ios::app);
    if (!fichier.is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier." << endl;
        return false;
    }
    fichier << numeroCarte << endl;
    fichier.close();
    cout << "Nouveau client ajouté avec succès." << endl;
    return true;
}

bool BaseClient::supprimerClient(int numeroCarte) {
    vector<int> numeros = lireNumerosClients();
    bool trouve = false;
    ofstream fichierTemp("fichier_clients_temp.txt");
    if (!fichierTemp.is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier temporaire." << endl;
        return false;
    }
    for (int num : numeros) {
        if (num != numeroCarte) {
            fichierTemp << num << endl;
        } else {
            trouve = true;
        }
    }
    fichierTemp.close();
    if (!trouve) {
        cout << "Numéro de carte non trouvé." << endl;
        remove("fichier_clients_temp.txt");
        return false;
    }
    remove("fichier_clients.txt");
    rename("fichier_clients_temp.txt", "fichier_clients.txt");
    cout << "Client supprimé avec succès." << endl;
    return true;
}

void BaseClient::afficherClients() {
    vector<int> numeros = lireNumerosClients();
    if (numeros.empty()) {
        cout << "Aucun client enregistré." << endl;
        return;
    }
    cout << "Numéros de carte des clients :" << endl;
    for (int num : numeros) {
        cout << num << endl;
    }
}


