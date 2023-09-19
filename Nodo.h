//
// Created by Miguel Villegas on 18/09/23.
//

#ifndef PRACTICA1_FINALIZADA_MIGUEL_VILLEGAS_NODO_H
#define PRACTICA1_FINALIZADA_MIGUEL_VILLEGAS_NODO_H

#include <string>
using namespace std;

class Nodo {
public:
    int data;
    string cient;
    string event;
    Nodo *next;
    Nodo *prev;

    Nodo(int data, string cient);

    void ponerEnlace(Nodo *sgte);

    Nodo *getEnlaceNodo() const;

    int getDataNodo() const;

    string getDataNodo2() const;

};


#endif //PRACTICA1_FINALIZADA_MIGUEL_VILLEGAS_NODO_H
