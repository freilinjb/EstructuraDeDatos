

#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;


struct nodo
{
    string nombre;
    string lesion;
    int gravedad;        
    struct nodo *sgte;
};

struct cola
{
    nodo *delante;
    nodo *atras  ;
};

struct nodo *crearNodo( const string nombre,const string lesion,const int gravedad )
{
    struct nodo *nuevoNodo = new(struct nodo);
    nuevoNodo->nombre = nombre;
    nuevoNodo->lesion = lesion;
    nuevoNodo->gravedad = gravedad;
    return nuevoNodo;
};

/*                        Encolar datos con prioridad      
------------------------------------------------------------------------*/

void limpiarBuffer() {
    fflush(stdin);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void encolar( struct cola &q, const string nombre, const string lesion, int prioridad )
{
     
     struct nodo *aux = crearNodo(nombre, lesion, prioridad);
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
     int width = 15;
     
     aux = q.delante;
     
     cout << " dato  Gravedad " << endl;
     cout << " ------------------- " << endl;
          
     while( aux != NULL )
     {
            cout<<"    "<< aux->nombre<< setw(width) << aux->lesion << setw(width) << aux->gravedad << endl;
            aux = aux->sgte;
     }    
}

string desencolar(cola &q) {
    string nombre, lesion;
    int gravedad;
    struct nodo *aux;

    aux = q.delante;
    nombre = aux->nombre;
    lesion = aux->lesion;
    gravedad = aux->gravedad;
    q.delante = (q.delante)->sgte;
    delete(aux);

    return "Atendiendo a " + nombre +"\t"+ " lesion: " + lesion + "\t" + "nivel de gravedad: " + to_string(gravedad);
}

/*         ( criterio de O. por Burbuja)    
------------------------------------------------------------------------*/
void ordenarPrioridad( struct cola &q )
{
     struct nodo *aux1, *aux2;
     int p_aux;
     string nombre, lesion;
     
     aux1 = q.delante;
     
     while( aux1->sgte != NULL)
     {
            aux2 = aux1->sgte;
            
            while( aux2 != NULL)
            {
                   if( aux1->gravedad > aux2->gravedad )
                   {
                       p_aux = aux1->gravedad;
                       nombre = aux1->nombre;
                       lesion = aux1->lesion;
                       
                       aux1->gravedad = aux2->gravedad;
                       aux1->nombre   = aux2->nombre;
                       aux1->lesion   = aux2->lesion;
                       
                       aux2->gravedad = p_aux;
                       aux2->nombre   = nombre;
                       aux2->lesion   = lesion;
                   }
                   
                   aux2 = aux2->sgte;
            }
            
            aux1 = aux1->sgte;
     }
}

void insertar( struct cola &q, const string nombre, const string lesion, int prioridad )
{
     /* Encolando caracteres */
     encolar( q, nombre, lesion, prioridad );
     
     /* Ordenando por prioridad */
     ordenarPrioridad( q ); 
}


void menu()
{
    cout<<"\t COLAS CON GRAVEDAD\n";
    cout<<" 1. REGISTRAR PACIENTE                "<<endl;
    cout<<" 2. MOSTRAR COLA                      "<<endl;
    cout<<" 3. ATENDER PACIENTE                  "<<endl;
    cout<<" 4. SALIR                             "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

int main()
{
    struct cola q;
    
    q.delante = NULL;
    q.atras   = NULL;

    string nombre ;     
    string lesion ;     
    int gravedad;      // prioridad del caracter 
    int option;      
    
    do
    {
        menu();  cin>> option;

        switch(option)
        {
            case 1:
                 limpiarBuffer();
                 cout<< "\n Ingrese el nombre: ";
                 getline(cin, nombre);

                cout<< "Ingrese la descripcion de la lesion: ";
                 getline(cin, lesion);
                 
                 cout<< "Ingrese la gravedad: ";   
                 cin>> gravedad;
                 
                 insertar( q, nombre, lesion, gravedad );
                 
                 cout<<"\t\tDato '" << nombre <<"|"<<lesion<< "' encolado...\n\n";
            break; 
                  
            case 2:

                 cout << " MOSTRANDO COLA DE PRIORIDAD\n\n";
                 
                 if(q.delante!=NULL)
                     muestraCola( q );
                 else   
                    cout<<"\tCola vacia...!"<<endl;
            break;

            
            case 3:
                cout << "ATENDIENDO AL PACIENTE\n";
                 
                cout<<desencolar(q)<<endl;
            break;

            
            default:
                    cout<<"\tOpcion incorecta..!"<<endl;
                    system("read");
                    exit(0);
         }

        cout<<endl<<endl;
        // system("read"); 
        //  system("clear");

    }while(option!=4);
    
    return 0;
}