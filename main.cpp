#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include <cstdlib> // Para las funciones rand() y srand()
#include <string>
using namespace std;

int generarData(){
    int random = rand() % 100 + 1;
    return random;
}

string generarCient(){
    int random2 = rand() % 2 + 1;
    string cienti;
    if (random2 == 1){
        cienti = "E";
    }
    else{
        cienti = "R";
    }
    return cienti;
}

bool primo(int data){
    bool resp = true;
    if (data == 1) {
        resp = false;
        return resp;
    }

    // Se comprueba si el número es divisible por algún otro número en el rango [2, numero-1]
    for (int i = 2; i * i <= data; i++) {
        if (data % i == 0) {
            resp = false;
            return resp;  // El número es divisible por i, por lo que no es primo
        }
    }

    resp = true;
    return resp;  // Si no se encontró ningún divisor, el número es primo
}

int main() {
    srand(time(0));
    ListaDoblementeEnlazada* puntero = new ListaDoblementeEnlazada();

    for (int i = 0; i < 22; i++) {
        int data = generarData();
        string cient = generarCient();
        puntero -> insert(data, cient);
    }

    puntero -> display();
    puntero -> mostrarEventos();
    puntero -> contarEventosAB();
    puntero -> encontrarSingularidad();

    delete puntero;

    return 0;

}