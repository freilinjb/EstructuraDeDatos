

#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

struct nodo
{
    string palabra;
    struct nodo *sgte;
};

struct cola
{
    nodo *delante;
    nodo *atras  ;
};

struct nodo *crearNodo( string palabra)
{
    struct nodo *nuevoNodo = new(struct nodo);
    nuevoNodo->palabra = palabra;
    return nuevoNodo;
};


void limpiarBuffer() {
    fflush(stdin);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void encolar( struct cola &q,const string palabra)
{
     
     struct nodo *aux = crearNodo(palabra);
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   

     else
         (q.atras)->sgte = aux;

     q.atras = aux;        
}

void muestraCola( struct cola q )
{
     struct nodo *aux;
     int width = 10;
     
     aux = q.delante;
     
     cout << " ------------------- " << endl;
          
     while( aux != NULL )
     {
            cout<<"  "<< aux->palabra  << setw(width) << endl;
            aux = aux->sgte;
     }    
}

string desencolar(cola &q) {
    string dato;
    struct nodo *aux;

    aux = q.delante;
    dato = aux->palabra;
    q.delante = (q.delante)->sgte;
    delete(aux);

    return dato;
}

void ordenarPalabra( struct cola &q )
{
     struct nodo *aux1, *aux2;
     int p_aux;
     string c_aux;
     
     aux1 = q.delante;
     
     while( aux1->sgte != NULL)
     {
            aux2 = aux1->sgte;
            
            while( aux2 != NULL)
            {
                   if( aux1->palabra > aux2->palabra )
                   {
                       c_aux = aux1->palabra;
                       
                       aux1->palabra   = aux2->palabra;
                       
                       aux2->palabra   = c_aux;
                   }
                   
                   aux2 = aux2->sgte;
            }
            
            aux1 = aux1->sgte;
     }
}

void insertar( struct cola &q, const string palabra)
{
     encolar( q, palabra);
     
     ordenarPalabra(q); 
}

void menu()
{
    cout<<"\t COLAS CIRCULAR "<<endl;
    cout<<" 1. ENCOLAR       "<<endl;
    cout<<" 2. MOSTRAR COLA  "<<endl;
    cout<<" 3. SALIR         "<<endl;

}

int main()
{
    system("clear");

    struct cola q;
    
    q.delante = NULL;
    q.atras   = NULL;

    string palabra;
    int option;      
    
    menu();  

    do
    {
        cout<<"INGRESE OPCION: ";
        cin>> option;

        switch(option)
        {
            case 1:

                 cout<< "\nIngrese la palabra: ";
                 limpiarBuffer();
                 getline(cin, palabra);
                 
                 insertar( q, palabra );
                 
                 cout<<"\t\tDato '" << palabra << "' encolado..."<<endl;
            break; 
                  
            case 2:

                 cout << " MOSTRANDO COLA CIRCULAR"<<endl;
                 
                 if(q.delante!=NULL)
                     muestraCola( q );
                 else   
                    cout<<"\tCola vacia...!"<<endl;
            break;
            
            default:
                    cout<<"\tOpcion incorecta..!"<<endl;
                    system("read");
                    exit(0);
         }

        cout<<endl<<endl;

    }while(option!=3);
    
    return 0;
}