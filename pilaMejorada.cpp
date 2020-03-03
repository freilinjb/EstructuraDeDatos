#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct nodo {
    int campo;
    struct nodo *anterior, *siguiente;
};
 

 // Pila hecha con apuntadores
class Pila {
    struct nodo *inicio, *final;
    // indicePila:  -1 -> pila vacia     0 -> posicion del dato
    int indicePila;
public:
 Pila() { 
    indicePila = -1; 
    inicio = NULL;
    final = NULL; 
 }; // constructor
  // funciones analizadoras
 void mostrarDatos();
 int cuantosDatos();
  // funciones modificadoras
 void entrarDato(int dato);
 int sacarDato();
 ~Pila();
};

 // Esta función sale del cuerpo de la clase porque usa un ciclo. 
void Pila::mostrarDatos() {
    cout << endl << "DATOS EN LA PILA" << endl;
    struct nodo *aux = inicio;
    int i = 0;
    while (aux != NULL) {
    cout << "Dato No. " << i << " : " << aux->campo << endl;
    i ++;
    aux = aux->siguiente;
    }
    cout << endl;

    system("pause");
}

int Pila::cuantosDatos() {
    return indicePila + 1;
}

void Pila::entrarDato(int dato) {
    struct nodo *nuevo = new struct nodo;
    nuevo->campo = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    if (final != NULL) {
    final->siguiente = nuevo;
    nuevo ->anterior = final;
    } else
    inicio = nuevo;
    final = nuevo;
    indicePila ++;
}

int Pila::sacarDato() {
    struct nodo *aux = final;
    cout << "valor ";
    int valor;
    if (aux != NULL) {
    valor = aux->campo;
    if (final != NULL) 
        final = final->anterior;
    if (final != NULL) 
    final->siguiente = NULL;
    else 
    inicio = NULL;
    delete aux;
    indicePila --;
    return valor;
    } 
    return -1;
}

Pila::~Pila() {
    struct nodo *aux = inicio;
    while (aux != NULL) {
    inicio = inicio->siguiente;
    delete aux;
    aux = inicio;
    }
}

int menu() {
    cout << endl << endl;
    cout << "**************************************" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Agregar un entero" << endl;
    cout << "2. Sacar entero" << endl;
    cout << "3. Mostrar la cantidad" << endl;
    cout << "4. Mostrar datos de la pila" << endl;
    cout << "**************************************" << endl;
    int opcion;
    cin >> opcion;
    return opcion;
}

main () {
    Pila pila1;
    int respuesta,opcion;
    opcion = -1;
    while (opcion != 0) {
    opcion = menu();
    switch (opcion) {
        case 0:
        cout << "Gracias por usar nuestro software" << endl;
        break;
        case 1:
        cout << "indique valor a entrar:"; 
        cin >> respuesta;
        pila1.entrarDato(respuesta);
        break;
        case 2: 
        cout << "Dato obtenido:" << pila1.sacarDato() << endl;
        break;
        case 3: 
        cout << "Hay " << pila1.cuantosDatos() << " en la pila" << endl;
        break;
        case 4:
        pila1.mostrarDatos();
        }
    }
    return 0;
}