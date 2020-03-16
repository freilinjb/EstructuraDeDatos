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
    } typedef *pila;

public:
    // void procesar();

    void agregarPila(pila &p, string n)
    {
        pila nuevo_nodo = new (struct Nodo);

        nuevo_nodo->dato = n;
        nuevo_nodo->siguiente = p;
        p = nuevo_nodo;

        cout << "Elemento agregado a la pila: " << n << endl;
    }

    string sacarPila(pila &p)
    {
        string dato;
        pila aux;

        aux = p;
        dato = aux->dato;
        p = aux->siguiente;

        delete (aux);

        return dato;
    }

    void destruir_pila(pila &p)
    {
        pila aux;

        while (p != NULL)
        {
            aux = p;
            p = aux->siguiente;
            delete (aux);
        }
    }

    void mostrarPila(pila p)
    {
        pila aux;
        aux = p;

        while (aux != NULL)
        {
            cout << "[" << aux->dato << "]" << endl;
            aux = aux->siguiente;
        }
    }

    void menu()
    {
        cout << "\n\t IMPLEMENTACION DE PILAS EN C++\n\n";
        cout << " 1. APILAR                                " << endl;
        cout << " 2. DESAPILAR                             " << endl;
        cout << " 3. MOSTRAR PILA                          " << endl;
        cout << " 4. DESTRUIR PILA                         " << endl;
        cout << " 5. SALIR                                 " << endl;

        cout << "\n INGRESE OPCION: ";
    }

    int procesar()
    {
        pila p = NULL; // creando pila
        string dato;
        int op;
        string x; // numero que devuelve la funcon pop


        do
        {
            menu();
            cin >> op;

            switch (op)
            {
            case 1:

                cout << "\n Estudiante: ";
                getline(cin, dato);
                
                agregarPila(p, dato);
                cout << "\n\n\t\tNumero " << dato << " apilado...\n\n";
                break;

            case 2:

                x = sacarPila(p);
                cout << "\n\n\t\tNumero " << x << " desapilado...\n\n";
                break;

            case 3:

                cout << "\n\n MOSTRANDO PILA\n\n";
                if (p != NULL)
                    mostrarPila(p);
                else
                    cout << "\n\n\tPila vacia..!" << endl;
                break;

            case 4:

                destruir_pila(p);
                cout << "\n\n\t\tPila eliminada...\n\n";
                break;
            }

            cout << endl
                 << endl;
            system("pause");
            system("cls");

        } while (op != 5);

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Pila2 pila;
    pila.procesar();
    return 0;
}
