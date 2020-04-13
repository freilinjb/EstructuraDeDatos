#include<string>
#include<stdlib.h>


using namespace std;

struct Nodo{
			string dato;
			int prioridad;

			struct Nodo *sgte;
};

//ESTRUCTURA COLA

struct cola{
            Nodo *frente;
            Nodo *atras;
}q;
//CREAR NODO

     struct Nodo *crearNodo(string x, int pr){
        struct Nodo *n_nodo = new(struct Nodo);

        n_nodo -> dato = x;
        n_nodo -> prioridad = pr;

        return n_nodo;

     };

//ENCOLAR
void encolar( struct cola &q, string valor, int prioridad){

    struct Nodo *aux = crearNodo(valor, prioridad);
    aux -> sgte = NULL;

    if(q.frente = NULL){
    
        q.frente = aux;
    }else{
        (q.atras)->sgte=aux;
        q.atras = aux;
		
    }
}


//MOSTRAR COLA

void muestracola (struct cola q){

    struct Nodo *aux;
    
    aux=q.frente;


    cout<<"Nombre   Prioridad"<<endl;
    cout<<"------------------"<<endl;

    while(aux != NULL){

        cout<<" "<<aux->dato<<"     |  "<<aux->prioridad<<endl;

        aux = aux ->sgte;
    }

}

///ORDENAR PRIORIDAD

void ordenarPrioridad(struct cola &q){
    struct Nodo *aux1, *aux2;

    int pAux;
    string cAux;

    aux1=q.frente;

        while(aux1->sgte !=NULL){

            aux2= aux1->sgte;

            while(aux2 != NULL){
                if(aux1->prioridad > aux2->prioridad){
                    pAux= aux1->prioridad;
                    cAux= aux1->dato;

                    aux1-> prioridad = aux2 -> prioridad;
                    aux1-> dato      = aux2 -> dato;

                    aux2 ->prioridad = pAux;
                    aux2 ->dato      = cAux;
                }

                aux2 = aux2 -> sgte;
            }

            aux1 = aux1 ->sgte;
        }

}

//INSERTAR STRING


void insert(struct cola &q, string c, int pr){

    encolar(q,c,pr);
    ordenarPrioridad(q);

}

//MENU

void menu(){

    cout<<"\n\t COLAS CON PRIORIDAD \n\n";
    cout<<" 1. ENCOLAR                      "<<endl;
    cout<<" 2. MOSTRAR                      "<<endl;
    cout<<" 3. SALIR                        "<<endl;

    cout<<"\n INGRESE LA OPCION: ";

}


///MAIN

int main(){

    struct cola q;

    q.frente = NULL;
    q.atras  =NULL;


    string c;
    int pr,op,x;

    do{
        menu();
        cin>>op;

        switch(op){
        case 1:

            cout<<"igrese el nombre"<<endl;
            cin>>c;
            cout<<"ingrese prioridad"<<endl;
            cin>>pr;

            insert(q,c,pr);

            break
        case 2:
            cout<<"Mostrando Cola"<<endl;

            if(q.frente == NULL){

                cout<<"cola vacia"<<endl;

            }else{
                muestracola(q);
            }

        case 3:
             cout<<"Saliendo..."<<endl;
             break

        }

        system("pause");
        system("cls");


    }white(op!=3);


    return 0;
}