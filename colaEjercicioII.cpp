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

        cout << "Digite el nombre del estudiante: ";
        getline(cin, n);
            
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
        cout << " 1. APILAR                               " << endl;
        cout << " 2. DESAPILAR                            " << endl;
        cout << " 3. MOSTRAR PILA                         " << endl;
        cout << " 4. VACIAR VACIAR                        " << endl;
        cout << " 5. SALIR                                " << endl;

        cout << "\n INGRESE OPCION: ";
    }

    int procesar()
    {
        Nodo *pila = NULL;
        string dato;
        char z;

        while (true)
        {
            agregarPila(pila, dato);
            cout << "Desea ingresar otro estudiante a la pila: (S/n): ";
            cin >> z;

            if (z == 'S' || z == 's')
            {
                cout << "Digite un estudiante: ";
                cin >> dato;
                agregarPila(pila, dato);
            }

            else if (z == 'N' || z == 'n')
                break;
        }

        cout << "Sacando los elementos de la pila: ";
        while (pila != NULL)
        {
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
    system("pause");
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
