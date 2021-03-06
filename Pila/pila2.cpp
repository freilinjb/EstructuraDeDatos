#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void agregarPIla(Nodo *&, int);
void sacarPila(Nodo *&, int &);
void mostrarPila(Nodo *&);

int main(int argc, char const *argv[])
{
    Nodo *pila = NULL;
    int dato;
    char z;
    return 0;


}

void agregarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "Elemento agrergado a la pila; " << n << endl;
}

void sacarPIla(Nodo *&pila, int &n) {
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

void mostrarPila(Nodo *&pila) {
    cout << endl << "Datos en la Pila" << endl;
    Nodo *aux = pila;
    int i = 0;
    while (aux != NULL)
    {
        i++;
        aux = aux->siguiente;
    }
    cout << endl;
}