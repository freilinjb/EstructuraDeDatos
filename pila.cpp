#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int);//Prototipo
void sacarPila(Nodo *&, int &);//Prototipo

int main(int argc, char const *argv[])
{
    Nodo *pila = NULL;
    int dato;
    char z;

    while (true)
    {
        cout << "Digite un numero: ";
        cin>>dato;
        agregarPila(pila,dato);
        cout << "Desea ingresar otro elemento a la pila: (S/n): ";
        cin >> z;

        if(z == 'S' || z == 's')
        {
            cout << "Digite un numero: ";
            cin>>dato;
            agregarPila(pila,dato);
        }

        else if(z == 'N' || z == 'n')
            break;
    }
    

    cout << "Sacando los elementos de la pila: ";
    while(pila != NULL){
        sacarPila(pila,dato);
        if(pila != NULL){
            cout <<"["<< dato << "]"<<endl;
        }
        else {
            cout <<"["<< dato << "]";
        }
    }
    getchar();
    return 0;
}

void mostrarElemento(Nodo *&pila, int dato){
    cout << "Sacando los elementos de la pila: ";
    while(pila != NULL){
        sacarPila(pila,dato);
        if(pila != NULL){
            cout << dato << " , ";
        }
        else {
            cout << dato << ".";
        }
    }
}

void agregarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "Elemento agregado a la pila: " << n <<endl;
}

void sacarPila(Nodo *&pila, int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}