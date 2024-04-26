#include "base_client.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Fonction pour lire les numéros de carte à partir du fichier fichier_clients.txt
vector<int> lireNumerosClients() {
    vector<int> numeros; // Vecteur pour stocker les numéros de carte
    ifstream fichier("fichier_clients.txt"); // Ouvre le fichier en mode lecture
    if (!fichier.is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier." << endl;
        return numeros;
    }
    int numero;
    while (fichier >> numero) { // Lit chaque numéro de carte dans le fichier
        numeros.push_back(numero); // Ajoute le numéro de carte au vecteur
    }
    fichier.close();
    return numeros;
}

// Fonction pour authentifier un numéro de carte
bool BaseClient::authentification(int numeroCarte) {
    vector<int> numeros = lireNumerosClients(); // Récupère les numéros de carte
    for (int num : numeros) {
        if (num == numeroCarte) { // Vérifie si le numéro de carte correspond
            cout << "Vous êtes authentifiés." << endl;
            return true;
        }
    }
    cout << "Numéro de carte non trouvé." << endl;
    return false;
}

// Fonction pour ajouter un nouveau client
bool BaseClient::ajouterClient(int numeroCarte) {
    vector<int> numeros = lireNumerosClients();
    for (int num : numeros) {
        if (num == numeroCarte) {
            cout << "Le numéro de carte existe déjà." << endl;
            return false;
        }
    }
    ofstream fichier("fichier_clients.txt", ios::app); // Ouvre le fichier en mode ajout
    if (!fichier.is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier." << endl;
        return false;
    }
    fichier << numeroCarte << endl; // Ajoute le nouveau numéro de carte au fichier
    fichier.close();
    cout << "Nouveau client ajouté avec succès." << endl;
    return true;
}

// Fonction pour supprimer un client existant
bool BaseClient::supprimerClient(int numeroCarte) {
    vector<int> numeros = lireNumerosClients();
    bool trouve = false;  // Variable pour indiquer si le numéro de carte est trouvé
    ofstream fichierTemp("fichier_clients_temp.txt"); // Ouvre un fichier temporaire
    if (!fichierTemp.is_open()) { // Vérifie si le fichier temporaire est ouvert avec succès
        cerr << "Erreur: Impossible d'ouvrir le fichier temporaire." << endl;
        return false;
    }
    for (int num : numeros) { // Parcourt tous les numéros de carte
        if (num != numeroCarte) { // Vérifie si le numéro de carte est différent de celui à supprimer
            fichierTemp << num << endl; // Ajoute le numéro de carte au fichier temporaire
        } else {
            trouve = true; // Indique que le numéro de carte à supprimer a été trouvé
        }
    }
    fichierTemp.close(); // Ferme le fichier temporaire
    if (!trouve) { // Vérifie si le numéro de carte à supprimer a été trouvé
        cout << "Numéro de carte non trouvé." << endl;
        remove("fichier_clients_temp.txt"); // Supprime le fichier temporaire
        return false;
    }
    remove("fichier_clients.txt"); // Supprime le fichier original
    rename("fichier_clients_temp.txt", "fichier_clients.txt"); // Renomme le fichier temporaire
    cout << "Client supprimé avec succès." << endl;
    return true;
}

// Fonction pour afficher tous les clients enregistrés
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


