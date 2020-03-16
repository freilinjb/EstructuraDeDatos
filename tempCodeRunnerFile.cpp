#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

class Pila2
{
protected:
    struct Nodo
    {
        string dato;
        Nodo *siguiente;
    };

public:
    // void procesar();

    void agregarPila(Nodo *&pila, string n)
    {
        Nodo *nuevo_nodo = new Nodo();
        nuevo_nodo->dato = n;
        nuevo_nodo->siguiente = pila;
        pila = nuevo_nodo;

        cout << "Elemento agregado a la pila: " << n << endl;
    }

    void sacarPila(Nodo *&pila, string &n)
    {
        Nodo *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        delete aux;
    }

    void mostrarPila(Nodo pila)
    {
        Nodo *aux;
        aux = pila.siguiente;

        while (aux != NULL)
        {
            cout << "[" << aux->dato << "]" << endl;
            aux = aux->siguiente;
        }
    }

    void menu(void)
    {
        cout << "\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
        cout << " 1. ENCOLAR                               " << endl;
        cout << " 2. DESENCOLAR                            " << endl;
        cout << " 3. MOSTRAR COLA                          " << endl;
        cout << " 4. VACIAR COLA                           " << endl;
        cout << " 5. SALIR                                 " << endl;

        cout << "\n INGRESE OPCION: ";
    }

    int procesar()
    {
        Nodo *pila = NULL;
        string dato;
        char z;

        while (true)
        {
            cout << "Digite un numero: ";
            cin >> dato;
            agregarPila(pila, dato);
            cout << "Desea ingresar otro elemento a la pila: (S/n): ";
            cin >> z;

            if (z == 'S' || z == 's')
            {
                cout << "Digite un numero: ";
                cin >> dato;
                agregarPila(pila, dato);
            }

            else if (z == 'N' || z == 'n')
                break;
        }

        cout << "Sacando los elementos de la pila: ";
        while (pila != NULL)
        {
            sacarPila(pila, dato);
            if (pila != NULL)
            {
                cout << "[" << dato << "]" << endl;
            }
            else
            {
                cout << "[" << dato << "]";
            }
        }
        getchar();
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Pila2 pila;
    pila.procesar();
    return 0;
}
