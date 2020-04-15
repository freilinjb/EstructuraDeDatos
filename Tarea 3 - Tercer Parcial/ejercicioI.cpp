
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct nodo{

    string dato; 
    bool estado = true;
    struct nodo *sgte;
};

typedef struct nodo *Lista;

void menu(void){

    cout<<"\t\t----------------------------------"<<endl;
    cout<<" 1. REGISTRAR CARRITO                          "<<endl;
    cout<<" 2. LISTAR CARRITOS                            "<<endl;
    cout<<" 3. ELIMINAR CARRITO                           "<<endl;
    cout<<" 3. SALIR                                       "<<endl;
}

void registrarCarrito(Lista &lista){

    Lista t,q = new(struct nodo);

    cout<<"\t\t[  REGISTRO DE CARRITO  ]\n";
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

void registrarCarrito(Lista &lista, const string dato){

    Lista t,q = new(struct nodo);

    q->dato = dato;

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

void listarCarrito(Lista q){

    int i=1;
    cout<<"[  LISTA DE CARRITOOS  ]"<<endl;
    int width = 15;

    cout <<right << "Carrito" << setw(width) << "Estado"  <<endl;    

    while(q!=NULL){

        cout <<setw(width-10)  << q->dato << setw(width+5) <<(q->estado ? "Disponible" : "Ocupado") <<endl;

        q=q->sgte;

        i++;
    }

}

void eliminarCarrito(Lista &lista){

    string cod;
    Lista q,t;
    q=lista;

    if(lista==NULL){

        cout<<"\tLISTA VACIA.....!!!!";

    }else{

        cout<<"\tELIMINAR UN CARRITOO";
        cout<<"\tINGRESE CELULAR:"; cin>>cod;

        while(q!=NULL){

            if(q->dato==cod){

                if(q==lista)
                    lista=lista->sgte;

                else
                    t->sgte=q->sgte;

                delete(q);

                cout<<"\tCARRITOO  ELIMINADO...!!!!!\n";

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

    for(int i = 0; i < 25; i++) {
        
        registrarCarrito(lista, "#"+to_string(i+1));
    }
    menu();

    int op;

    do{
            cout<<"\n Ingrese opcion : ";
            cin>>op;

            switch(op){

                case 1: registrarCarrito(lista);
                        break;

                case 2: listarCarrito(lista);
                        break;

                case 3: eliminarCarrito(lista);
                        break;

                case 4: return 0;


                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

            }
            cout<<endl;

        }while(op!=6);

    system("pause");

    return 0;
}