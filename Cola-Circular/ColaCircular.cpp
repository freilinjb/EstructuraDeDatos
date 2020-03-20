#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <limits>


using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
}*primero, *ultimo;

void insertarNodo();

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


//primero = null ultimo = 45   nuevo = 45     45,67,89,12
//lista circular simple                  45-> primero

void insertarNodo(){
    nodo* nuevo = new nodo();
    cout << "Ingrese el dato: ";
    cin >> nuevo->dato;
    
    if(primero == NULL) {
        primero = nuevo;
        primero->siguiente = primero;
    }
}