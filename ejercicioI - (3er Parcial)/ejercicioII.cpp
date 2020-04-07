#include<iostream>
#include<cstdlib>
#include <cmath>

#define maxchar 50

using namespace std;

struct nodo{

    int numero; 
    struct nodo *sgte; // puntero al siguiente nodo
};

int cantidad = 0, primero, segundo;

typedef struct nodo *Lista;//definimos puntero de tipo nodo

/*----------------------------- MENU ------------------------------*/
void menu(void){

    cout<<"\n\t\t[     LISTA EN LAZADADE NUMEROS     ]\n";
    cout<<"\t\t----------------------------------\n\n";
    cout<<" 1. REGISTRAR NUMERO                         "<<endl;
    cout<<" 2. LISTAR NUMERO                            "<<endl;
    cout<<" 3. ELIMINAR NUMERO                          "<<endl;
    cout<<" 3. SALIR                                    "<<endl;

}


void registrar(Lista &lista, int dato){

    Lista t,q = new(struct nodo);
    q->numero = dato;

    q->sgte = NULL;

    if(lista==NULL){

        lista = q;

    } else {

        t = lista;

        while(t->sgte!=NULL){
            t = t->sgte;
        }

        t->sgte = q;
    }
}

void procesar(Lista &lista) {
    int dato;
    cout<<"\n\n\t\t[  REGISTRO  ]\n";
    cout<<"\t\t------------";

    cout<<"\n\tNumero:"; cin>>dato;
    if(cantidad == 0)
        primero = dato;
    else if(cantidad == 1) 
        segundo = dato;

    cantidad ++;
    registrar(lista, dato);

    if(cantidad == 2){
        registrar(lista,abs(primero - segundo));
        cantidad = 0;
    }


    cout << "cantidad: "<< cantidad << "\t primero: "<< primero << "\tSegundo: " << segundo<< endl;

}

void listar(Lista q){
    Lista aux;

    int i=1;
    cout<<"\n\n\t[  LISTA DE NUMEROS  ]";
    cout<<"\n\n\t-------------------------"<<endl;
    while(q!=NULL){
        // aux->numero = abs(q->numero - q->sgte->numero);
        // aux->sgte = q->sgte; 
        // q->sgte = aux;
        cout<<"\tNumero  : "<<q->numero<<endl;
        
        q=q->sgte;

        i++;
    }
}


void eliminar(Lista &lista){

    int cod;
    Lista q,t;
    q=lista;

    if(lista==NULL){

        cout<<"\tLISTA VACIA.....!!!!";

    }else{

        cout<<"\tELIMINAR DE NUMEROS";
        cout<<"\tINGRESE UN NUMERO:"; cin>>cod;

        while(q!=NULL){

            if(q->numero==cod){

                if(q==lista)
                    lista=lista->sgte;

                else
                    t->sgte=q->sgte;

                delete(q);

                cout<<"\tNUMERO  ELIMINADO...!!!!!\n";

                return;

            }else {

                t=q;
                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\tCODIGO INCORRECTO...!!\n";

    }
}

int main(void){

    int cantidad = 0;
    int primero;
    int segundo;
    Lista lista=NULL;

    int op;
    menu();

    do{
        cout<<"\n Ingrese opcion : ";

            cin>>op;

            switch(op){

                case 1:   
                        procesar(lista);
                        break;

                case 2: listar(lista);
                        break;

                case 3: eliminar(lista);
                        break;

                case 4: return 0;


                default: cout<<"INGRESE UNA OPCION VALIDA...\n"; break;

            }
            cout<<endl;

        }while(op!=6);


    return 0;
}