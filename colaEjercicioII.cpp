#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

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
    Cola *estudiante;

    void imprimir() const {
        cout << "Hola mundo" << endl;
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
        itr->imprimir();
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
