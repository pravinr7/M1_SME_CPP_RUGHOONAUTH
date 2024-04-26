#ifndef BASE_CLIENT_H
#define BASE_CLIENT_H

#include <iostream>

class BaseClient {
public:
    bool authentification(int numeroCarte);
    bool ajouterClient(int numeroCarte);
    bool supprimerClient(int numeroCarte);
    void afficherClients();
};

#endif // BASE_CLIENT_H


