//
// Created by Miguel Villegas on 18/09/23.
//

#ifndef PRACTICA1_FINALIZADA_MIGUEL_VILLEGAS_LISTADOBLEMENTEENLAZADA_H
#define PRACTICA1_FINALIZADA_MIGUEL_VILLEGAS_LISTADOBLEMENTEENLAZADA_H

#include "Nodo.h"
#include <string>

class ListaDoblementeEnlazada {
public:
    Nodo *head;
    ListaDoblementeEnlazada();

    void insert(int data, string cient);

    void insertarUltimo(int data ,string cient);

    void display();

    Nodo *getUltimo();

    void mostrarEventos();

    bool primo(int data);

    int calcularMCD(int data, int data2);

    bool sonCoprimos(int data, int data2);

    void contarEventosAB();

    void encontrarSingularidad();

    ~ListaDoblementeEnlazada();
};


#endif //PRACTICA1_FINALIZADA_MIGUEL_VILLEGAS_LISTADOBLEMENTEENLAZADA_H
