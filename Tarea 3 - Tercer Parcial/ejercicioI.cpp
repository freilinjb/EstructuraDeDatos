
#include<iostream>
#include <string>
#include<cstdlib>

using namespace std;

struct nodo{

    string dato; 
    struct nodo *sgte;
};

typedef struct Lista{
    int dato;
    nodo *nodo;
};

// typedef struct nodo *Lista;
bool sexo = true;

void menu(void){

    cout<<"\t\t----------------------------------\n\n";
    cout<<" 1. REGISTRAR ALUMN                          "<<endl;
    cout<<" 2. LISTAR ALUMNS                            "<<endl;
    cout<<" 3. ELIMINAR ALUMN                           "<<endl;
    cout<<" 3. SALIR                                       "<<endl;
}

void registrar(Lista &lista){

    Lista t,q;

    q.nodo->dato = "dsf"

    cout<<"\t\t[  REGISTRO DE ALUMNO  ]\n";
    cout<<"\t\t------------";
    cin.ignore();cout<<"\n\tNOMBRE:";
    getline(cin,q->dato);

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

void listar(Lista q){

    int i=1;
    cout<<"\t[  LISTA DE ALUMNOS  ]";
    cout<<"\t-------------------------"<<endl;
    while(q!=NULL){

        cout<<"\tNOMBRE: "<<q->nombre<<endl;
        q=q->sgte;

        i++;
    }

}

void eliminar(Lista &lista){

    string cod;
    Lista q,t;
    q=lista;

    if(lista==NULL){

        cout<<"\tLISTA VACIA.....!!!!";

    }else{

        cout<<"\tELIMINAR UN ALUMNO";
        cout<<"\tINGRESE CELULAR:"; cin>>cod;

        while(q!=NULL){

            if(q->nombre==cod){

                if(q==lista)
                    lista=lista->sgte;

                else
                    t->sgte=q->sgte;

                delete(q);

                cout<<"\tALUMNO  ELIMINADO...!!!!!\n";

                return;

            }else {

                t=q;
                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\n\tCODIGO INCORRECTO...!!\n";

    }
}

int main(void){

    system("clear");

    Lista lista=NULL;
    menu();

    int op;

    do{
            cout<<"\n Ingrese opcion : ";
            cin>>op;

            switch(op){

                case 1: registrar(lista);
                        break;

                case 2: listar(lista);
                        break;

                case 3: eliminar(lista);
                        break;

                case 4: return 0;


                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

            }
            cout<<endl;

        }while(op!=6);

    system("pause");

    return 0;
}