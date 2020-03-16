
#include <iostream>
using namespace std;
 
struct nodo{
    int nro;
    struct nodo *sgte;
};
 
typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de dato )
 
/*                        Apilar elemento      
------------------------------------------------------------------------*/
void push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  // apuntamos al nuevo nodo creado
     aux->nro = valor;
     
     aux->sgte = p ;
     p = aux ;
}
 
/*                Desapilar elemento(devuelve elemento)      
------------------------------------------------------------------------*/
int pop( ptrPila &p )
{
     int num ;
     ptrPila aux;
     
     aux = p ;
     num = aux->nro;   // asignamos el primer vamor de la pila
     
     p = aux->sgte ;
     delete(aux);
     
     return num;
}
 
/*                     Muestra elementos de la pila      
------------------------------------------------------------------------*/
void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista
     
     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro <<endl;
            aux = aux->sgte;
     }    
}
 
/*                Eliminar todos los elementos de la pila      
------------------------------------------------------------------------*/
void destruir_pila( ptrPila &p)
{
     ptrPila aux;
     
     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}
 
/*                        Menu de opciones    
------------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\t IMPLEMENTACION DE PILAS EN C++\n\n";
    cout<<" 1. APILAR                                "<<endl;
    cout<<" 2. DESAPILAR                             "<<endl;
    cout<<" 3. MOSTRAR PILA                          "<<endl;
    cout<<" 4. DESTRUIR PILA                         "<<endl;
    cout<<" 5. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
 
/*                        Funcion Principal        
------------------------------------------------------------------------*/
int main()
{
    ptrPila p = NULL;  // creando pila
    int dato;
    int op;
    int x ; // numero que devuelve la funcon pop
   
    system("color 0b");
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A APILAR: "; cin>> dato;
                 push( p, dato );
                 cout<<"\n\n\t\tNumero " << dato << " apilado...\n\n";
            break;
 
 
            case 2:
 
                 x = pop( p );
                 cout<<"\n\n\t\tNumero "<< x <<" desapilado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO PILA\n\n";
                 if(p!=NULL)
                    mostrar_pila( p );
                 else
                    cout<<"\n\n\tPila vacia..!"<<endl;
            break;
 
 
            case 4:
 
                 destruir_pila( p );
                 cout<<"\n\n\t\tPila eliminada...\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=5);
   
   
    return 0;
}