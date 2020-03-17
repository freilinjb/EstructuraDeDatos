#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <limits>

#include <list>

using namespace std;

class Pila2
{

public:
    // void procesar();
    struct Nodo
    {
        string dato;
        Nodo *siguiente;
    } typedef *pila;

    void agregarPila(pila &p, string n)
    {
        pila nuevo_nodo = new (struct Nodo);

        nuevo_nodo->dato = n;
        nuevo_nodo->siguiente = p;
        p = nuevo_nodo;

        cout << "Elemento agregado a la pila: " << n << endl;
    }

    static void limpiarBuffer2()
    {
        fflush(stdin);
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    void limpiarBuffer()
    {
        fflush(stdin);
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }

    string sacarPila(pila &p)
    {
        string dato;
        pila aux;

        aux = p;
        dato = aux->dato;
        p = aux->siguiente;

        delete (aux);

        limpiarBuffer();

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
        limpiarBuffer();
    }

    void menu()
    {
        cout << "\n\t IMPLEMENTACION DE ESTUDIANTES EN PILAS EN C++\n\n";
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
                limpiarBuffer();

                getline(cin, dato);
                
                agregarPila(p, dato);
                cout << "\n\n\t\tEstudiante " << dato << " apilado...\n\n";
                break;

            case 2:
                
                x = sacarPila(p);
                cout << "\n\n\t\tEstudiante " << x << " desapilado...\n\n";
                limpiarBuffer();

                break;

            case 3:
                limpiarBuffer(); 

                cout << "\n\n MOSTRANDO PILA\n\n";
                if (p != NULL)
                    mostrarPila(p);
                else
                {
                    cout << "\n\n\tPila vacia..!" << endl;
                    limpiarBuffer();
                }
                break;

            case 4:
                limpiarBuffer();

                destruir_pila(p);
                cout << "\n\n\t\tPila eliminada...\n\n";
                break;
            }

            cout << endl
                 << endl;

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


class Cola : protected Pila2 { 
    public:
    Pila2 Pila;
    struct cola {
        string materia;
        Pila2::Nodo estudiante;
        Pila2::Nodo *delante;
        Pila2::Nodo *atras;


        cola(const string materia) {
            this->materia = materia;
        }

        cola(){}

        void encolar(cola &q,const string dato){
            Pila2::Nodo *aux = new Pila2::Nodo();

            aux->dato = dato;
            aux->siguiente = NULL;

            q.delante == NULL ? q.delante = aux : (q.atras)->siguiente = aux;

            q.atras = aux;
            q.materia = aux->dato;
        }

        string desencolar(cola &q) {
            string dato;
            Nodo *aux;

            aux = q.delante;
            dato = aux->dato;
            q.delante = (q.delante)->siguiente;
            delete(aux);

            return dato;
        }

        void mostrarCola(cola q) {
            Nodo *aux;
            aux = q.delante;

            while (aux != NULL)
            {
                cout << "[" << aux->dato << "]" <<endl;
                aux = aux->siguiente;
            }

            cout << "\n\n**[precione una tecla para continuear]**" << endl;
            limpiarBuffer2();
            getchar();
        }

        void vaciarCola(cola &q){
            Pila2::Nodo *aux;
            aux = q.delante;

            while (aux != NULL)
            {
                cout << "[" <<aux->dato << "]" <<endl;
                aux = aux->siguiente;
            }
            cout << "\n\n**[precione una tecla para continuar]**" <<endl;
            getchar();
        }
    };
};