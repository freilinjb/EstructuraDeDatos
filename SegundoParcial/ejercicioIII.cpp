#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>

#include <list>

#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iterator>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>

#define MAX 5
using namespace std;

struct nodo
{
    string campo;
    struct nodo *anterior, *siguiente;
};

// Pila hecha con apuntadores
class Pila
{
    struct nodo *inicio, *final;
    // indicePila:  -1 -> pila vacia     0 -> posicion del dato
    int indicePila;

public:
    Pila()
    {
        indicePila = -1;
        inicio = NULL;
        final = NULL;
    }; // constructor
    void limpiarBuffer();
    void mostrarDatos();
    int cuantosDatos();

    void entrarDato(string dato);
    void entradaString();
    bool palindromo(string dato);
    string sacarDato();
    ~Pila();
};

void Pila::limpiarBuffer()
{
    fflush(stdin);
    cin.clear(); // unset failbit
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Pila::mostrarDatos()
{
    cout << endl
         << "DATOS EN LA PILA" << endl;
    struct nodo *aux = inicio;
    int i = 0;
    while (aux != NULL)
    {
        cout << aux->campo << endl;
        i++;
        aux = aux->siguiente;
    }
    cout << endl;
}

bool Pila::palindromo(string dato)
{
    bool poli = false;
    string compara;

    for (int i = dato.length() - 1; i >= 0; i--)
    {
        compara += dato[i];
    }

    if (compara == dato)
    {
        poli = true;
        cout << "[ ES POLINDROMO ]" << endl;
    }
    else
    {
        cout << "[ NO POLINDROMO ]" << endl;
    }
    return poli;
}

void Pila::entradaString()
{
    string comparar;

    fflush(stdin);
    cin.ignore();
    cin.clear();

    string dato;
    cout << "Ingrese la cadena de texto: ";
    getline(cin, dato);

    comparar = dato;

    int temp = 0;

    entrarDato(dato);

    fflush(stdin);
    cin.ignore();
    cin.clear();
}

int Pila::cuantosDatos()
{
    return indicePila + 1;
}

void Pila::entrarDato(string dato)
{
    struct nodo *nuevo = new struct nodo;
    nuevo->campo = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    if (final != NULL)
    {
        final->siguiente = nuevo;
        nuevo->anterior = final;
    }
    else
        inicio = nuevo;
    final = nuevo;
    indicePila++;
}

string Pila::sacarDato()
{
    struct nodo *aux = final;
    cout << "valor ";
    string valor;
    if (aux != NULL)
    {
        valor = aux->campo;
        if (final != NULL)
            final = final->anterior;
        if (final != NULL)
            final->siguiente = NULL;
        else
            inicio = NULL;
        delete aux;
        indicePila--;
        return valor;
    }
    return "-1";
}

Pila::~Pila()
{
    struct nodo *aux = inicio;
    while (aux != NULL)
    {
        inicio = inicio->siguiente;
        delete aux;
        aux = inicio;
    }
}

Pila pila1;

void menuPila()
{
    cout << endl
         << endl;
    cout << "**************************************" << endl;
    cout << "1. Agregar dato" << endl;
    cout << "2. Sacar dato" << endl;
    cout << "3. Mostrar la cantidad" << endl;
    cout << "4. Mostrar datos de la pila" << endl;
    // cout << "5. Comparar polindromo" << endl;
    cout << "**************************************" << endl;
    // int opcion;
    // cout << "Seleccione una opcion: ";
    // cin >> opcion;
    // return opcion;
}

void procesarPila()
{
    string respuesta;
    int opcion;

    opcion = -1;
    menuPila();
    while (opcion != 0)
    {
        cout << "Seleccione una option: ";
        cin >> opcion;
        switch (opcion)
        {
        case 0:
            cout << "Gracias por usar nuestro software" << endl;
            break;
        case 1:
            pila1.entradaString();
            break;
        case 2:
            cout << "Dato obtenido:" << pila1.sacarDato() << endl;
            break;
        case 3:
            cout << "Hay " << pila1.cuantosDatos() << " en la pila" << endl;
            break;
        case 4:
            pila1.mostrarDatos();
            break;
        }
    }
}
void limpiarBuffer()
{
    fflush(stdin);
    cin.clear(); // unset failbit
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void encolar(Cola &q, string dato)
{

    pila1.entrarDato(dato);
    cout << "INGRESADO EN PILA" << endl;
    cout << "INGRESADO EN COLA" << endl;

    pila1.palindromo(dato);

    Nodo *aux = new Nodo();

    aux->dato = dato;
    aux->siguiente = NULL;

    if (q.delante == NULL)
        q.delante = aux; //Encola el primer elemento

    else
        (q.atras)->siguiente = aux; //Puntero que siempre apunta al ultimo elemento

    q.atras = aux;
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
    cout << "\n\n**[precione una tecla para continuar]**" << endl;
    getchar();
    getchar();
}

void mostrarColaDesacoplada(Cola q)
{
    Nodo *aux;
    aux = q.delante;

    while (aux != NULL)
    {
        cout << "inicio" << endl;

        for (int i = 0; i < aux->dato.length(); i++)
        {
            cout << "[" << aux->dato[i] << "]";
        }

        cout << "fin" << endl;

        aux = aux->siguiente;
    }
    cout << "\n\n**[precione una tecla para continuar]**" << endl;
    getchar();
    getchar();
}

void vaciaCola(Cola &q)
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

int leerArchivo()
{
    int nuevo[1210];
    int i;
    char peliculas[1210][50];
    ifstream infile("peliculas.txt");
    string line;
    vector<string> Nombres;
    char nombre[50];

    std::string linea;
    while (std::getline(infile, line))
    {
        std::stringstream stream(line);
        std::string valor;

        std::cout << " ";
        while (std::getline(stream, valor, '\n'))
        {

            Nombres.push_back(line);
        }
        std::cout << " ";
    }
    for (vector<string>::iterator it = Nombres.begin(); it < Nombres.end(); ++it)
    {
        cout << ("\n") << *it;
        pila1.palindromo(*it);
    }
}

void menuCola()
{
    cout << "\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
    cout << " 1. ENCOLAR                               " << endl;
    cout << " 2. DESENCOLAR                            " << endl;
    cout << " 3. MOSTRAR COLA                          " << endl;
    cout << " 4. VACIAR COLA                           " << endl;
    cout << " 5. SALIR                                 " << endl;
    cout << " 6. MOSTRAR DATOS EN PILA                 " << endl;
    cout << " 7. MOSTRAR MENU PILA                     " << endl;
    cout << " 8. MOSTRAR COLA DESACOPLADO              " << endl;
    cout << " 9. LEER ARCHIVO Y COMP POLINDROMO              " << endl;
}

int main(int argc, char const *argv[])
{
    struct Cola q;

    q.delante = NULL;
    q.atras = NULL;

    string dato; // numero a encolar
    int op;      // opcion del menu
    string x;    // numero que devuelve la funcon pop
    menuCola();
    do
    {
        cout << "\n INGRESE OPCION: ";
        cin >> op;

        switch (op)
        {
        case 1:

            cout << "\n DATO A ENCOLAR: ";
            limpiarBuffer();
            getline(cin, dato);
            encolar(q, dato);
            cout << "\tdato " << dato << " encolado...\n";
            break;

        case 2:

            x = desencolar(q);
            cout << "\tdato " << x << " desencolado...\n";
            break;

        case 3:

            cout << " MOSTRANDO COLA\n\n";
            if (q.delante != NULL)
                mostrarCola(q);
            else
                cout << "\tCola vacia...!" << endl;
            break;

        case 4:

            vaciaCola(q);
            cout << "\t\tHecho...\n";
            break;

        case 6:

            pila1.mostrarDatos();
            cout << "\t\tHecho...\n";
            break;
        case 7:
            procesarPila();
            cout << "\t\tHecho...\n";
            break;

        case 8:
            cout << " MOSTRANDO COLA\n";
            if (q.delante != NULL)
                mostrarColaDesacoplada(q);
            else
                cout << "\tCola vacia...!" << endl;
            break;

        case 9:
            leerArchivo();
            cout << "\t\tHecho...\n";
            break;
        }

        cout << endl
             << endl;
        // system("clear");

    } while (op != 5);

    return 0;

    cout << "hola mundo" << endl;
    return 0;
}