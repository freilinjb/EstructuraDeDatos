#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <limits>

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

/*
struct Nodo
{
    string dato;
    Nodo *siguiente;
};

struct Cola
{
    Nodo *delante;
    Nodo *atras;
};

struct Materia
{
    string nombre;
    Cola estudiante;

    void mostrarCola() const
    {
        Nodo *aux;
        aux = estudiante.delante;

        while (aux != NULL)
        {
            cout << "[" << aux->dato << "]" << endl;
            aux = aux->siguiente;
        }
        cout << "\n\n**[precione una tecla para continuar]**" << endl;
        getchar();
        getchar();
    }

    Materia(const string nombre)
    {
        this->nombre = nombre;
    }
};

list<Materia> materias;

void encolar(Cola &q, string dato)
{
    Nodo *aux = new Nodo();

    aux->dato = dato;
    aux->siguiente = NULL;

    q.delante == NULL ? q.delante = aux : (q.atras)->siguiente = aux;

    q.atras = aux;
}

void encolarMaterias(Materia &m, string dato)
{
    Materia temp[8] = {
        {"Proyecto I"},
        {"Estructura de datos"},
        {"Base de Datos I"},
        {"Base de Datos II"},
        {"Calculo I"},
        {"Calculo II"},
        {"Calculo III"},
        {"Ingenieria Economica"}};

    for (int i = 0; i < 8; i++)
        materias.push_back(temp[i]);
}

void mostrarCuentas()
{
    cout << "\n"
         << endl;

    cin.clear();
    fflush(stdin);

    int cantidad = 0;
    int width = 25;
    // cout << left << "Num" << setw(width) << "fecha" << setw(width) << "debito" <<setw(width) << "credito" << endl;
    cout << right << "MOVIMIENTO" << setw(width) << "CUENTA" << setw(width) << "DEBITO" << setw(width) << "CREDITO" << setw(width) << "HORA"
         << ""
         << "|" << setw(width) << "FECHA" << endl;

    list<Materia>::const_iterator itr = materias.begin();
    while (itr != materias.end())
    {
        cin.clear();
        fflush(stdin);
        cout << "[" << 1 + cantidad << "] ";
        itr->mostrarCola();
        ++itr;
        cantidad++;
    }
    cout << "Cantidad de registros: " << cantidad << endl;
}

string desencolar(Cola &q)
{
    string dato;
    Nodo *aux;

    aux = q.delante;
    dato = aux->dato;

    q.delante = (q.delante)->siguiente;
    delete (aux);

    return dato;
}

void mostrarCola(Cola q)
{
    Nodo *aux;
    aux = q.delante;

    while (aux != NULL)
    {
        cout << "[" << aux->dato << "]" << endl;
        aux = aux->siguiente;
    }

    cout << "\n\n**[PRECIONE UNA TECLA PARA CONTINUAR]**" << endl;
    getchar();
    getchar();
}

void vaciarCola(Cola &q)
{
    Nodo *aux;

    while (q.delante != NULL)
    {
        aux = q.delante;
        q.delante = aux->siguiente;
        delete (aux);
    }

    q.delante = NULL;
    q.atras = NULL;
}

int main(int argc, char const *argv[])
{
    cout << "prueba de texto" << endl;
    return 0;
}
*/