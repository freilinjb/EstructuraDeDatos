#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
    int nro;    
    struct nodo *sgte;
};

nodo *fin;
nodo *lista;

void menu();
void insertarInicio(int);
void insertarFinal(int);
void mostrar();
void buscarElemento();
void eliminarElemento();
void eliminarElementos();
void procesarInsercion();
void procesarInicio(int);
void procesarFinal(int);
void insertarInicio2(int);
int sumatoria = 0;
bool verificar = true;

int main(void)
{
    lista = NULL;
    int op;     // opcion del menu
    menu();
    
    do
    {
        cout<<"\n INGRESE OPCION: ";
        cin>>op;

        switch(op)
        {
            case 1:
                    verificar = true;
                    procesarInsercion();
                    break;

            case 2:
                    verificar = false;
                    procesarInsercion();
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

            case 8:
                    procesarInsercion();
                    break;

            default: cout<<"OPCION NO VALIDA...!!!";
                     break;
        }

        cout<<endl<<endl;

    }while(op!=7);

   return 0;
}

void procesarInsercion() {    
    string valorString;
    long valorLong;

    cout<<"\n***INSERTA AL INICIO*****\n";
    cout<<"\nINGRESE DATO:";
    cin>>valorLong;

    valorString = to_string(valorLong);

    for(int i = 0; i < valorString.size(); i++) {
        char x = char(valorString[i]);
        sumatoria += (int)x - '0';
        
        if(verificar){
            insertarInicio((int)x - '0');
        } else {
            insertarFinal((int)x - '0');
            cout << "dato: " << (int)x - '0'<<endl;
        }
    }
}

void menu() {
    system("clear");
    cout<<"\n\t\tLISTA ENLAZADA CIRCULAR\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. MOSTRAR LISTA                    "<<endl;
    cout<<" 4. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 5. ELIMINAR             "<<endl;
    cout<<" 7. SALIR                            "<<endl;
}

void insertarInicio(int dato)
{
   nodo *nuevo;
   nuevo=new struct nodo;

   nuevo->nro = dato;
   nuevo->sgte=NULL;

   if(lista==NULL)
    {
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

void insertarFinal(int dato)
{
    nodo *nuevo;
    nuevo=new struct nodo;

    nuevo->nro = dato;
    nuevo->sgte=NULL;

     if(lista==NULL)
        {
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

void mostrar() {   
    nodo *aux;
    aux=lista;
    int i=1;

    if(lista!=NULL)
     {
          do
          {    cout<<aux->nro << " ";
               aux = aux->sgte;
               i++;
          }while(aux!=lista);

          cout <<"->NULL"<<endl;
      }
     else
         cout<<"\tLista vacia...!"<<endl;

    cout<<"Sumatoria: [" << sumatoria <<"]"<<endl;
}

void buscarElemento() {
     nodo *aux;
     int i = 1 , flag = 0,valor;

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

void eliminarElemento(){
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