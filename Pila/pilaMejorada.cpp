#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct nodo
{
    char campo;
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

    void mostrarDatos();
    int cuantosDatos();

    void entrarDato(char dato);
    void entradaString();
    void palindromo();
    char sacarDato();
    ~Pila();
};

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

void Pila::palindromo()
{
    string dato;
    string compara;

    fflush(stdin);
    cin.ignore();
    cin.clear();

    cout << "Ingrese un dato: ";
    getline(cin, dato);

    for (int i = dato.length() - 1; i >= 0; i--)
    {
        compara += dato[i];
    }

    if (compara == dato)
    {
        cout << "[ Son pelendromos ]" << endl;
    }
    else
    {
        cout << "[ No son palendromos ]" << endl;
    }
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
    // for(int i = dato.length(); i >= 0; i--){
    //     entrarDato(dato[i]);

    //}

    for (int i = 0; i < dato.length(); i++)
    {
        entrarDato(dato[i]);
    }

    fflush(stdin);
    cin.ignore();
    cin.clear();
}

int Pila::cuantosDatos()
{
    return indicePila + 1;
}

void Pila::entrarDato(char dato)
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

char Pila::sacarDato()
{
    struct nodo *aux = final;
    cout << "valor ";
    char valor;
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
    return -1;
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

int menu()
{
    cout << endl
         << endl;
    cout << "**************************************" << endl;
    cout << "1. Agregar dato" << endl;
    cout << "2. Sacar dato" << endl;
    cout << "3. Mostrar la cantidad" << endl;
    cout << "4. Mostrar datos de la pila" << endl;
    cout << "5. Comparar polindromo" << endl;
    cout << "**************************************" << endl;
    // int opcion;
    // cout << "Seleccione una opcion: ";
    // cin >> opcion;
    // return opcion;
}

main()
{
    Pila pila1;
    string respuesta;
    int opcion;

    opcion = -1;
    menu();
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
        case 5:
            pila1.palindromo();
            break;
        }
    }
    return 0;
}