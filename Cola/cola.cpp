#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *frente, *siguiente;
};

bool cola_vacia(Nodo *frente) {
    return (frente == NULL) ? true : false;
}

void insertarDato(Nodo *&frente, Nodo *&siguiente, int dato){
    Nodo *nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if(cola_vacia(frente)){
        frente = nuevo;       
    }
    else{
        frente->siguiente = nuevo;
    }

    siguiente = nuevo;
}

int main(int argc, char const *argv[])
{
    Nodo *frente = NULL;
    Nodo *fin  = NULL;

    char dato;

    cout << "Digite un dato: ";
    cin>>dato;
    insertarDato(frente,fin,dato);
    cout <<"Dato insertado correctamente " << dato << endl;

    cout << "Digite un dato: ";
    cin>>dato;
    insertarDato(frente,fin,dato);

    cout <<"Dato insertado correctamente " << dato << endl;

    cout << "Digite un dato: ";
    cin>>dato;
    insertarDato(frente,fin,dato);
    cout <<"Dato insertado correctamente " << dato << endl;

    return 0;

}
