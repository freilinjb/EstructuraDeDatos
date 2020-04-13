#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
            int nro;    //los datos seran de tipo entero
            struct nodo *sgte; //puntero
            };

// typedef struct nodo;//definimos a nodo como un tipo de variable
nodo *fin;//puntero que ira siempre al final de la lista
nodo *lista;//puntero que para nosotros apuntara a la cabeza de nuestra lista

void menu(); //declaramos las funciones a usar
void insertarInicio();
void insertarFinal();
void mostrar();
void buscarElemento();
void eliminarElemento();
void eliminarElementos();

/*                        Funcion Principal
---------------------------------------------------------------------*/

int main(void)
{
    lista = NULL;
    int op;     // opcion del menu

    do
    {
        menu();
        cin>>op;

        switch(op)
        {
            case 1:
                    insertarInicio();
                    break;

            case 2:
                    insertarFinal();
                    break;
            case 3:
                    cout<<"\n\n Lista Circular \n\n";
                    mostrar();
                    break;

            case 4:
                    buscarElemento();
                    break;

            case 5:
                    eliminarElemento();
                    break;
            case 6:
                    eliminarElementos();
                    break;

            default: cout<<"OPCION NO VALIDA...!!!";
                     break;


        }

        cout<<endl<<endl;

    }while(op!=7);

   return 0;
}

//////////////////////MOSTRAR MENU///////////////////////////////

void menu()
{
    cout<<"\n\t\tLISTA ENLAZADA CIRCULAR\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. REPORTAR LISTA                   "<<endl;
    cout<<" 4. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 5. ELIMINAR ELEMENTO 'V'            "<<endl;
    cout<<" 6. ELIMINAR ELEMENTOS CON VALOR 'V' "<<endl;
    cout<<" 7. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

//////////////////////INSERTAR AL INICIO//////////////////////////

void insertarInicio()
{
   nodo *nuevo;
   nuevo=new struct nodo;

   cout<<"\n***INSERTA AL INICIO*****\n";
   cout<<"\nINGRESE DATO:";
   cin>>nuevo->nro;
   nuevo->sgte=NULL;

   if(lista==NULL)
    {
        cout<<"PRIMER ELEMENTO..!!!";
        lista=nuevo;
        lista->sgte=lista;
        fin=nuevo;
      }
   else
     {
        nuevo->sgte = lista;
        lista = nuevo;
        fin->sgte = lista;
     }

}
//////////////////INSERTAR AL FINAL/////////////////////
void insertarFinal()
{
    nodo *nuevo;
    nuevo=new struct nodo;
    cout<<"***INSERTA AL INICIO*****\n";
    cout<<"INGRESE DATO:";
    cin>>nuevo->nro;
    nuevo->sgte=NULL;

     if(lista==NULL)
        {
             cout<<"PRIMER ELEMENTO..!!!";
             lista=nuevo;
             lista->sgte=lista;
             fin=nuevo;
        }
     else
        {
          fin->sgte = nuevo;
          nuevo->sgte = lista;
          fin = nuevo;
        }
}

void mostrar()
{   nodo *aux;
    aux=lista;
    int i=1;

    if(lista!=NULL)
     {
          do
          {    cout<<"  "<<aux->nro;
               aux = aux->sgte;
               i++;
          }while(aux!=lista);
      }
     else
         cout<<"\tLista vacia...!"<<endl;


}

void buscarElemento() //esta funcion muestra la posicion del primer dato coincidente
                      //encontrado en la lista
{
     nodo *aux;
     int i = 1, valor , flag = 0;

     cout<<"INGRESE ELEMENTO A BUSCAR:";
     cin>>valor;
     if(lista !=NULL)
     {
          aux = lista;

          do
          {
               if(aux->nro == valor)
               {
                   cout<<"Encontrado en posicion "<< i <<endl;
                   flag=1;
               }
               else
               {
                   aux = aux->sgte;
                   i++;
               }
          }while(aux!=lista);

          if(flag==0) cout<<"\tNumero no econtrado..!"<<endl;

     }
     else
         cout<<"\tLista vacia...!"<<endl;

}

void eliminarElemento()
{
    nodo *aux, *r, *q;
    int i = 1, flag = 0,valor;

    cout<<"INGRESE ELEMENTO A ELIMINAR: ";
    cin>>valor;

    if(lista !=NULL)
     {
          aux = lista;

          do
          {
               if(aux->nro == valor)
                {
                    if(aux==lista)//si es que el dato a eliminar es el primero
                    {   r=lista;
                        lista=lista->sgte;
                        aux=aux->sgte;
                        fin->sgte=lista;
                        r->sgte=NULL;
                        if(fin->sgte==NULL)
                        {
                            lista==NULL;
                            aux==NULL;
                            delete(r);
                            cout<<"ELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                        else
                        {
                            delete(r);
                            cout<<"ELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                    }
                   else
                    {
                        if(aux==fin)//si es que el dato a eliminar es al que apunta a fin
                            {
                            r=aux;
                            aux=aux->sgte;
                            q->sgte=aux;
                            fin=q;
                            r->sgte=NULL;
                            delete(r);
                            cout<<"ELEMENTO ELIMINADO...!!!\n";
                            return;
                            }
                        else
                        {
                            r=aux;
                            aux=aux->sgte;
                            q->sgte=aux;
                            r->sgte=NULL;
                            delete(r);
                            cout<<"ELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                  }
                  flag=1;
                }
                else
                {   q=aux;
                    aux = aux->sgte;
                    i++;
                }
          }while(aux!=lista);

          if(flag==0)
          cout<<"\tNumero no econtrado..!"<<endl;


    }
    else
      cout<<"LISTA VACIA...!!!!";


}
//////////////////////ELIMINAR REPETIDOS/////////////////////
void eliminarElementos()
{
     nodo *aux, *r, *q;
     int  flag = 0,valor;

     cout<<"DATO REPETIDO A ELIMINAR: ";
     cin>>valor;

     if(lista !=NULL)
        { aux=lista;

            while(aux->nro==valor)//si los primeros elementos son repetidos
                if(aux==lista)    //esta funcion borra a estos
                  {
                   r=lista;
                   aux=lista->sgte;
                   lista=lista->sgte;
                   fin->sgte=lista;
                   r->sgte=NULL;
                    if(fin->sgte==NULL)
                     {
                        lista==NULL;
                        aux==NULL;
                        delete(r);
                        flag=1;
                      }
                    else
                     {
                        delete(r);
                        flag=1;
                     }
                   }
          do
          {
               if(aux->nro == valor)
                {
                    while(aux==lista)
                    {
                         r=lista;
                         aux=lista->sgte;
                         lista=lista->sgte;
                         fin->sgte=lista;
                         r->sgte=NULL;
                        if(fin->sgte==NULL)
                        {
                            lista==NULL;
                            aux==NULL;
                            delete(r);
                        }
                      else
                        delete(r);

                    }

                   if(aux==fin)//para si el elemento a borrar es apuntado por *fin
                    {
                        r=aux;
                        aux=aux->sgte;
                        q->sgte=aux;
                        fin=q;
                        r->sgte=NULL;
                        delete(r);
                    }
                    else
                    {
                        r=aux;
                        aux=aux->sgte;
                        q->sgte=aux;
                        r->sgte=NULL;
                        delete(r);
                    }

                    flag=1;
               }
               else
               {   q=aux;
                   aux = aux->sgte;
               }
          }while(aux!=lista);

          if(flag==0)
            cout<<"\tNumero no econtrado..!"<<endl;
        }
          else
            cout<<"LISTA VACIA...!!!!";
}