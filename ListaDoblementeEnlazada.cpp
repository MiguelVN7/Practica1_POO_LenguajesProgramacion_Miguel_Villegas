//
// Created by Miguel Villegas on 18/09/23.
//

#include "ListaDoblementeEnlazada.h"
#include <iostream>
#include "Nodo.h"
#include <string>
#include <math.h>
using namespace std;

// Constructor de la clase
ListaDoblementeEnlazada::ListaDoblementeEnlazada(){
    this -> head = nullptr;
}

// Funcion para insertar un nuevo nodo al principio de la lista
void ListaDoblementeEnlazada::insert(int data, string cient){
    Nodo *node = new Nodo(data, cient); // Crear un nuevo nodo
    node -> next = this -> head; // A ese nodo se le asigna el valor de head (que es el primer nodo de la lista y es null)
    if (this->head != nullptr) // Si la lista no está vacía
    {
        this->head -> prev = node; // El nodo anterior al head es el nuevo nodo creado
    }
    this -> head = node; // El nuevo nodo creado es el head
}

// Funcion para insertar un nuevo nodo al final de la lista
void ListaDoblementeEnlazada::insertarUltimo(int data, string cient) {
    Nodo *ultimo = this -> getUltimo(); // Se crea un nodo que obtiene el valor del último nodo de la lista (se obtiene con la función getUltimo)
    ultimo -> ponerEnlace(new Nodo(data, cient)); // Se crea un nuevo nodo y se le asigna el valor de data y cient
}

// Funcion para mostrar elementos de la lista doblemente enlazada
void ListaDoblementeEnlazada:: display()
{
    if (this -> head == nullptr) // Si la lista está vacía
    {
        cout << "La lista está vacía" << endl;
    }
    else
    {
        cout << " Los 22 eventos temporales que ocurrieron son:" << endl;
        Nodo *temp = this -> head; // Crear un nodo temporal que obtiene el valor de head (primer nodo de la lista)
        int cont = 0; // Contador para saber cuántos nodos hay en la lista

        while (temp != nullptr) // Ciclo para recorrer la lista
        {
            if (cont == 0) // Si estamos ante el primer nodo de la lista
            {
                cout << " |" << temp -> data << "|" << temp -> cient << "|";
            } else { // Si estamos ante cualquier otro nodo
                cout << " ->" << " |" << temp -> data << "|" << temp -> cient << "|";
            }

            temp = temp -> next; // El nodo temporal ahora es el siguiente nodo de la lista
            cont++;
        }
    }
}

// Funcion para obtener el último nodo de la lista
Nodo *ListaDoblementeEnlazada::getUltimo() {
    Nodo *n = head; // Crear un nodo que obtiene el valor de head (primer nodo de la lista)
    if (n == NULL) throw "Error, lista vacía"; // Si la lista está vacía, se lanza una excepción
    while (n->getEnlaceNodo() != NULL) n = n -> getEnlaceNodo(); // Mientras el nodo temporal no sea null, el nodo temporal es el siguiente nodo de la lista
    return n;
}

//Funcion para saber si un numero es primo
bool ListaDoblementeEnlazada::primo(int data) {
    bool resp = true;
    if (data == 1) { // Si el número es 1, no es primo
        resp = false;
        return resp;
    }

    for (int i = 2; i * i <= data; i++) { // Si el número es divisible por algún otro número en el rango [2, numero-1]
        if (data % i == 0) {
            resp = false;
            return resp;  // El número es divisible por i, por lo que no es primo
        }
    }

    resp = true;
    return resp;  // Si no se encontró ningún divisor, el número es primo
}

// Funcion para calcular el MCD de dos números (dato del nodo del evento A y del evento C)
int ListaDoblementeEnlazada::calcularMCD(int data, int data2) {
    while (data2 != 0) { // Mientras el segundo número sea diferente de 0
        int temp = data2; // Se crea una variable temporal que obtiene el valor del segundo número
        data2 = data % data2; // El segundo número es igual al residuo de la división del primer número entre el segundo número
        data = temp; // El primer número es igual al segundo número
    }
    return data;
}

bool ListaDoblementeEnlazada::sonCoprimos(int data, int data2) {
    int mcd = calcularMCD(data, data2);

    // Si el MCD es igual a 1, los números son coprimos
    return (mcd == 1);
}

// Funcion para mostrar los 3 eventos (tipo A, B y C) que ocurrieron
void ListaDoblementeEnlazada::mostrarEventos() {
    // Crear nodos temporales para recorrer la lista
    Nodo *temp = this -> head;
    Nodo *temp2 = this -> head;
    Nodo *temp3 = this -> head;
    Nodo *temp4 = this -> head;
    int comp = 0; // Variable para asegurarme que los nodos de eventos B y C no repitan el mismo del evento A
    int copr = 0; // Variable para asignarle el valor del dato del evento A y ver si es coprimo con el dato del evento C
    while (temp != nullptr) { // Ciclo para recorrer hasta que lleguemos al evento tipo A
        if (primo(temp -> data) && temp -> cient == "E") { // Si el dato del nodo es primo y el científico es E
            cout << "\n\n El dato del primer evento es: " << temp -> data << "; el científico es: " << temp -> cient << " y el evento es: A" << endl;
            comp = temp -> data;
            copr = temp -> data;
            temp2 = temp;
            break;
        }
        temp = temp -> next;
    }
    while (temp != nullptr) { // Ciclo para recorrer hasta que lleguemos al evento tipo B
        if (primo(temp -> data) && comp != temp -> data) { // Si el dato del nodo es primo y el dato del nodo es diferente al dato del evento A
            cout << " El dato del siguiente evento es: " << temp -> data << "; el científico es: " << temp -> cient << " y el evento es: B" << endl;
            comp = temp -> data;
            temp3 = temp;
            break;
        }
        temp = temp -> next;
    }
    while (temp != nullptr){ // Ciclo para recorrer hasta que lleguemos al evento tipo C
        if (sonCoprimos(temp -> data, copr) && comp != temp -> data){ // Si el dato del nodo es coprimo con el dato del evento A y el dato del nodo es diferente al dato del evento A y B
            cout << " El dato del último evento es: " << temp -> data << "; el científico es: " << temp -> cient << " y el evento es: C" << endl;
            temp4 = temp;
            break;
        }
        temp = temp -> next;
    }

    cout << "\n Los 3 eventos que ocurrieron son:" << endl;
    for (int i = 0; i < 3; i++){ // For que imprime los 3 eventos en orden en forma de lista
        if (i==0){
            cout << " |" << temp2 -> data << "|" << temp2 -> cient << "|" << "A|";
        } else if (i == 1){
            cout << " ->" << " |" << temp3 -> data << "|" << temp3 -> cient << "|B|";
        } else{
            cout << " ->" << " |" << temp4 -> data << "|" << temp4 -> cient << "|C|";
        }
    }
}

// Funcion para contar los eventos tipo A y B
void ListaDoblementeEnlazada::contarEventosAB() {
    // Crear nodos temporales para recorrer la lista
    Nodo *temp = this -> head;
    Nodo *temp2 = this -> head;
    int cont = 0; // Contador para los eventos tipo A
    int cont2 = 0; // Contador para los eventos tipo B
    while (temp != nullptr) { // Ciclo para recorrer la lista mientras el nodo temporal sea diferente de null
        if (primo(temp -> data) && temp -> cient == "E") { // Si el dato del nodo es primo y el científico es E
            cont++; // Se aumenta el contador de eventos tipo A
        }
        temp = temp -> next; // El nodo temporal ahora es el siguiente nodo de la lista
    }
    while (temp2 != nullptr) {
        if (primo(temp2 -> data) && temp2 -> cient == "R") { // Si el dato del nodo es primo y el científico es R
            cont2++; // Se aumenta el contador de eventos tipo B
        }
        temp2 = temp2 -> next; // El nodo temporal ahora es el siguiente nodo de la lista
    }
    cout << "\n\n El número de eventos de tipo A es: " << cont << endl;
    cout << " El número de eventos de tipo B es: " << cont2 << endl;
}

// Funcion para encontrar la singularidad
void ListaDoblementeEnlazada::encontrarSingularidad() {
    // Crear nodos temporales para recorrer la lista
    Nodo *temp = this -> head;
    Nodo *temp2 = this -> head;
    Nodo *temp3 = this -> head;
    Nodo *temp4 = this -> head;
    int comp = 0; // Variable para asegurarme que los nodos de eventos B y C no repitan el mismo del evento A
    int copr = 0; // Variable para asignarle el valor del dato del evento A y ver si es coprimo con el dato del evento C
    while (temp != nullptr) { // Ciclo para recorrer hasta que lleguemos al evento tipo A
        if (primo(temp -> data) && temp -> cient == "E") { // Si el dato del nodo es primo y el científico es E
            comp = temp -> data;
            copr = temp -> data;
            temp2 = temp;
            break;
        }
        temp = temp -> next;
    }
    while (temp != nullptr) { // Ciclo para recorrer hasta que lleguemos al evento tipo B
        if (primo(temp -> data) && comp != temp -> data) { // Si el dato del nodo es primo y el dato del nodo es diferente al dato del evento A
            comp = temp -> data;
            temp3 = temp;
            break;
        }
        temp = temp -> next;
    }
    while (temp != nullptr){ // Ciclo para recorrer hasta que lleguemos al evento tipo C
        if (sonCoprimos(temp -> data, copr) && comp != temp -> data){ // Si el dato del nodo es coprimo con el dato del evento A y el dato del nodo es diferente al dato del evento A y B
            temp4 = temp;
            break;
        }
        temp = temp -> next;
    }

    if (primo(temp4 -> data) && temp2 -> cient == "E"){ // Si el dato del evento C es primo y el científico del evento A es E
        cout << "\n Se produjo una singuladirdad en donde el científico: " << temp4 -> cient << ", le entregó información al científico: " << temp2 -> cient << endl;
    } else if (!primo(temp4 -> data)){ // Si el dato del evento C no es primo
        cout << "\n Se produjo una singularidad en donde el científico: " << temp4 -> cient << ", solo pudo observar el evento A" << endl;
    }
}

// Destructor de la clase
ListaDoblementeEnlazada::~ListaDoblementeEnlazada() {
    Nodo *current = head;
    while (current != nullptr) {
        Nodo *next = current -> next;
        delete current;
        current = next;
    }
}
