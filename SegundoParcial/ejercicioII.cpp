#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;


struct nodo
{
    int campo;
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

    void entrarDato(int dato);
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

void Pila::entrarDato(int dato)
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
    cout << "5. Comparar polindromo" << endl;
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
        case 5:
            pila1.palindromo();
            break;
        }
    }
}

struct Nodo {
    int dato;
    Nodo *siguiente;
};

struct Cola {
    Nodo *delante;
    Nodo *atras;
};

void encolar(Cola &q, int dato) {
    
    if(dato%2 ==0) {

        pila1.entrarDato(dato);
        cout << "numero par incertado en pila" << endl;
    }
    Nodo *aux = new Nodo();

    aux ->dato = dato;
    aux->siguiente = NULL;

    if(q.delante == NULL)
        q.delante = aux; //Encola el primer elemento

    else
        (q.atras)->siguiente = aux; //Puntero que siempre apunta al ultimo elemento

    q.atras = aux;
}

int desencolar(Cola &q) {
    int num;
    Nodo *aux;

    aux = q.delante;
    num = aux->dato;
    q.delante = (q.delante)->siguiente;
    delete(aux);

    return num;
}

void mostrarCola(Cola q){
    Nodo *aux;
    aux = q.delante;

    while (aux != NULL)
    {
        cout << "[" <<aux->dato << "]" << endl;
        aux = aux->siguiente;
    }
    cout << "\n\n**[precione una tecla para continuar]**" << endl;
    getchar();
    getchar();
}


void vaciaCola(Cola &q) {
    Nodo *aux;
    while (q.delante != NULL)
    {
        aux = q.delante;
        q.delante = aux->siguiente;
        delete(aux);
    }

    q.delante = NULL;
    q.atras = NULL;
}

void menuCola() {
    cout<<"\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
    cout<<" 1. ENCOLAR                               "<<endl;
    cout<<" 2. DESENCOLAR                            "<<endl;
    cout<<" 3. MOSTRAR COLA                          "<<endl;
    cout<<" 4. VACIAR COLA                           "<<endl;
    cout<<" 5. SALIR                                 "<<endl;
    cout<<" 6. MOSTRAR DATOS EN PILA                 "<<endl;
    cout<<" 7. MOSTRAR MENU PILA                     "<<endl;

}

int main(int argc, char const *argv[])
{
    struct Cola q;
   
    q.delante = NULL;
    q.atras   = NULL;
   
   
    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero que devuelve la funcon pop
    menuCola();
    do
    {
        cout<<"\n INGRESE OPCION: ";
        cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A ENCOLAR: "; cin>> dato;
                 encolar( q, dato );
                 cout<<"t\tNumero " << dato << " encolado...\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( q );
                 cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << " MOSTRANDO COLA\n\n";
                 if(q.delante!=NULL) mostrarCola( q );
                 else   cout<<"\tCola vacia...!"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( q );
                 cout<<"\t\tHecho...\n\n";
            break;

            case 6:
 
                 pila1.mostrarDatos();
                 cout<<"\t\tHecho...\n\n";
            break;
                case 7:
                procesarPila();
                 cout<<"\t\tHecho...\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        // system("clear");
 
    }while(op!=5);
   
   
    return 0;
    
    cout << "hola mundo" << endl;
    return 0;
}