#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

struct Cola {
    Nodo *delante;
    Nodo *atras;
};

void encolar(Cola &q, int dato) {
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

void menu() {
    cout<<"\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
    cout<<" 1. ENCOLAR                               "<<endl;
    cout<<" 2. DESENCOLAR                            "<<endl;
    cout<<" 3. MOSTRAR COLA                          "<<endl;
    cout<<" 4. VACIAR COLA                           "<<endl;
    cout<<" 5. SALIR                                 "<<endl;

}

int main(int argc, char const *argv[])
{
    struct Cola q;
   
    q.delante = NULL;
    q.atras   = NULL;
   
   
    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero que devuelve la funcon pop
    menu();
    do
    {
        cout<<"\n INGRESE OPCION: ";
        cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A ENCOLAR: "; cin>> dato;
                 encolar( q, dato );
                 cout<<"\n\n\t\tNumero " << dato << " encolado...\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( q );
                 cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(q.delante!=NULL) mostrarCola( q );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( q );
                 cout<<"\n\n\t\tHecho...\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        // system("clear");
 
    }while(op!=5);
   
   
    return 0;
    
    cout << "hola mundo" << endl;
    return 0;
}