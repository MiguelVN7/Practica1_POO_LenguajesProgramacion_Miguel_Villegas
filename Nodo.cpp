//
// Created by Miguel Villegas on 18/09/23.
//

#include "Nodo.h"
#include <string>
using namespace std;

//Constructor de la clase Nodo
Nodo::Nodo(int data, string cient) {
    this->data = data;
    this->cient = cient;
    this->next = nullptr;
    this->prev = nullptr;
}

//Funcion para poner enlace, que tiene como parametro un puntero a un nodo y se le asigna ese valor al puntero next
void Nodo::ponerEnlace(Nodo *sgte) {
    next = sgte;
}

//Funcion para obtener el enlace del nodo next y retornarlo
Nodo *Nodo::getEnlaceNodo() const {
    return next;
}

//Funcion para obtener el valor de la variable data y retornarlo
int Nodo::getDataNodo( ) const
{
    return data;
}

//Funcion para obtener el valor de la variable cient y retornarlo
string Nodo::getDataNodo2( ) const
{
    return cient;
}

