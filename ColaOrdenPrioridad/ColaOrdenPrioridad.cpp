

#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;


struct nodo
{
    string dato;
    int priori;        
    struct nodo *sgte;
};

struct cola
{
    nodo *delante;
    nodo *atras  ;
};

struct nodo *crearNodo( string dato, int prioridad)
{
    struct nodo *nuevoNodo = new(struct nodo);
    nuevoNodo->dato = dato;
    nuevoNodo->priori = prioridad;
    return nuevoNodo;
};

/*                        Encolar datos con prioridad      
------------------------------------------------------------------------*/

void limpiarBuffer() {
    fflush(stdin);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void encolar( struct cola &q, string dato, int prioridad )
{
     
     struct nodo *aux = crearNodo(dato, prioridad);
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   

     else
         (q.atras)->sgte = aux;

     q.atras = aux;        // puntero que siempre apunta al ultimo elemento 
}

void muestraCola( struct cola q )
{
     struct nodo *aux;
     int width = 10;
     
     aux = q.delante;
     
     cout << " dato  Prioridad " << endl;
     cout << " ------------------- " << endl;
          
     while( aux != NULL )
     {
            cout<<"    "<< aux->dato  << setw(width) << "     |     " << aux->priori << endl;
            aux = aux->sgte;
     }    
}

string desencolar(cola &q) {
    string dato;
    struct nodo *aux;

    aux = q.delante;
    dato = aux->dato;
    q.delante = (q.delante)->sgte;
    delete(aux);

    return dato;
}

/*         ( criterio de O. por Burbuja)    
------------------------------------------------------------------------*/
void ordenarPrioridad( struct cola &q )
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
                   if( aux1->priori > aux2->priori )
                   {
                       p_aux = aux1->priori;
                       c_aux = aux1->dato;
                       
                       aux1->priori = aux2->priori;
                       aux1->dato   = aux2->dato;
                       
                       aux2->priori = p_aux;
                       aux2->dato   = c_aux;
                   }
                   
                   aux2 = aux2->sgte;
            }
            
            aux1 = aux1->sgte;
     }
}

void insertar( struct cola &q, string c, int pr )
{
     /* Encolando caracteres */
     encolar( q, c, pr );
     
     /* Ordenando por prioridad */
     ordenarPrioridad( q ); 
}


void menu()
{
    cout<<"\n\t COLAS CON PRIORIDAD \n\n";
    cout<<" 1. ENCOLAR                           "<<endl;
    cout<<" 2. MOSTRAR COLA                           "<<endl;
    cout<<" 3. SALIR                             "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

int main()
{
    struct cola q;
    
    q.delante = NULL;
    q.atras   = NULL;

    string dato ;     
    int prioridad;      // prioridad del caracter
    int option;      
    
    do
    {
        menu();  cin>> option;

        switch(option)
        {
            case 1:

                 cout<< "\n Ingrese dato: ";
                 limpiarBuffer();
                 getline(cin, dato);
                 
                 cout<< "\n Ingrese prioridad: ";   
                 cin>> prioridad;
                 
                 insertar( q, dato, prioridad );
                 
                 cout<<"\n\n\t\tDato '" << dato << "' encolado...\n\n";
            break; 
                  
            case 2:

                 cout << "\n\n MOSTRANDO COLA DE PRIORIDAD\n\n";
                 
                 if(q.delante!=NULL)
                     muestraCola( q );
                 else   
                    cout<<"\n\n\tCola vacia...!"<<endl;
            break;
            
            default:
                    cout<<"\n\tOpcion incorecta..!"<<endl;
                    system("read");
                    exit(0);
         }

        cout<<endl<<endl;
        // system("read"); 
        //  system("clear");

    }while(option!=3);
    
    return 0;
}