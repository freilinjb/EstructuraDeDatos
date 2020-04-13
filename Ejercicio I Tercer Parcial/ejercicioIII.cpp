#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <limits>
#include <list>

using namespace std;

template<class T> struct Nodo{
	T elemento;
	Nodo* sgte;
	Nodo* anterior;

	Nodo(T e = 0, Nodo* s = nullptr, Nodo* a = nullptr) : elemento(e), sgte(s), anterior(a){}
};

template<class T> class ListaDME{
private:
	Nodo<T>* inicio;
	int n_elementos;

public:
	ListaDME(){
		inicio = nullptr;
		n_elementos = 0;
	}
	~ListaDME(){
		Limpiar();
	}

	void Limpiar(){
		Nodo<T>* aux;

		for (int i = 0; i < n_elementos; i++){
			aux = inicio;
			inicio = inicio->sgte;
			delete aux;
		}
		inicio = nullptr;
		n_elementos = 0;
	}

	bool Insertar_Ordenado(T nuevo){
		Nodo<T>* aux;

		if (n_elementos == 0){
			inicio = new Nodo<T>(nuevo, inicio);
			if (inicio->sgte != nullptr){
				inicio->sgte->anterior = inicio;
			}
			++n_elementos;
			return true;
		}
		aux = inicio;

		while (aux->sgte != nullptr){
			aux = aux->sgte;
		}
		aux->sgte = new Nodo<T>(nuevo);
		aux->sgte->anterior = aux;
		++n_elementos;
		return true;
	}

	bool Eliminar_al_final(){
		if (n_elementos < 0){
			return false;
		}

		Nodo<T>* aux = inicio;
		for (int i = 0; i < n_elementos - 1; i++){
			aux = aux->sgte;
		}
		aux->anterior->sgte = aux->sgte;
		delete aux;
		--n_elementos;

		return true;
	}

	bool Eliminar_elementos(int pi, int pf){
		int num = n_elementos;
		if (n_elementos < 0){
			return false;
		}
		Nodo<T>* aux1 = inicio;
		Nodo<T>* aux2;

		for (int i = 0; i < pi; i++){
			aux1 = aux1->sgte;
		}
		for (int j = pi - 1; j < pf; j++){
			aux1 = aux2;
			aux1 = aux1->sgte;
			delete aux2;
			--num;
		}
		aux1->anterior->sgte = aux1->sgte;
		if (aux1->sgte != nullptr) {
			aux1->sgte->anterior = aux1->anterior;
		}
		return true;
	}

	void Mostrar(){
		Nodo<T>* aux = inicio;
		int c = 0;

		cout << "[";
		while (aux){
			cout << aux->elemento;
			++c;
			if (c <= n_elementos - 1){
				cout << ", ";
			}
			aux = aux->sgte;
		}
		cout << "]" << endl;
	}

    void menuLDME(void){

        cout<<"\t\t[     LISTA DOBLEMENTE ENLAZADA NUMEROS     ]\n";
        cout<<"\t\t----------------------------------\n\n";
        cout<<" 1. REGISTRAR AL INICIO                         "<<endl;
        cout<<" X. REGISTRAR AL FINAL        (ELIMINADA)                 "<<endl;
        cout<<" 2. LISTAR NUMERO                            "<<endl;
        cout<<" 3. ELIMINAR NUMERO                          "<<endl;
        cout<<" 4. SALIR                                    "<<endl;

    }
};

ListaDME<int> lista_DME;


void procesarLDMEL(){

    int opt;
    int dato;

    lista_DME.menuLDME();


    do {
        cout << "selecciona una option: ";
        cin >> opt;

        switch (opt)
        {
        case 1: cout << "Ingrese un dato: ";
                cin >> dato;
                lista_DME.Insertar_Ordenado(dato);
            break;
        
        case 2: lista_DME.Mostrar();
            break;
        
        case 3: lista_DME.Eliminar_elementos(1,5);
            break;
        
        default: cout << "ESTA OPCION NO EXISTE" << endl;
            break;
        }
    }while(opt != 4);
}

struct nodo{


    int numero; 
    struct nodo *sgte;
};


typedef struct nodo *Lista;

void menuLista(void){

    cout<<"\t\t[     LISTA EN LAZADADE NUMEROS     ]\n";
    cout<<"\t\t----------------------------------\n\n";
    cout<<" 1. REGISTRAR NUMERO                         "<<endl;
    cout<<" 2. LISTAR NUMERO                            "<<endl;
    cout<<" 3. ELIMINAR NUMERO                          "<<endl;
    cout<<" 4. COPIAR LISTA A LISTA DOBLEMENTE ENLAZADA "<<endl;
    cout<<" 5. SALIR                                    "<<endl;

}


void agrergarNodo(Lista &lista) {
    Lista aux;

    if(lista != NULL && lista->sgte != NULL) {

        lista->sgte = aux;
    }

    else {
        cout<<"\tLISTA VACIA.....!!!!";
    }
}

void registrar(Lista &lista){

    Lista t,q = new(struct nodo);

    cout<<"\t\t[  REGISTRO  ]\n";
    cout<<"\t\t------------";
    cout<<"\tNumero:"; cin>>q->numero;
    cout<<endl;

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
    Lista aux;

    int i=1;
    cout<<"\t[  LISTA DE NUMEROS  ]";
    cout<<"\t-------------------------"<<endl;
    while(q!=NULL){


        // aux->numero = abs(q->numero - q->sgte->numero);
        // aux->sgte = q->sgte; 
        // q->sgte = aux;
        cout<<"\tNumero  : "<<q->numero<<endl;
        
        q=q->sgte;

        i++;
    }
}

void CopiarLista(Lista q, ListaDME<int>& listaD){
    Lista aux;

    int i=1;
    cout<<"\t[  LISTA DE NUMEROS  ]";
    cout<<"\t-------------------------"<<endl;
    while(q!=NULL){


        // aux->numero = abs(q->numero - q->sgte->numero);
        // aux->sgte = q->sgte; 
        // q->sgte = aux;
        cout<<"\tCopiado  : "<<q->numero<<endl;
        listaD.Insertar_Ordenado(q->numero);
        
        q=q->sgte;

        i++;
    }
    cout << "Nodos Copiados con EXITO";
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

void procesarLista(void){

    Lista lista=NULL;
    int op;
    menuLista();

    do{
            cout<<" Ingrese opcion : ";
            cin>>op;

            switch(op){

                case 1: registrar(lista);
                        break;

                case 2: listar(lista);
                        break;

                case 3: eliminar(lista);
                        break;

                case 4:  CopiarLista(lista,lista_DME);
                    break;


                default: cout<<"INGRESE UNA OPCION VALIDA...\n"; break;

            }
            cout<<endl;

        }while(op!=5);
}

int main() {
    system("clear");
    string stringMenu = "\n1) MENU LISTA ENLAZADA\n2) MENU LISTA LISTA DOBLEMENTE ENLAZADA\n3) SALIR\n";
    int opt;

    do {

        cout << stringMenu<<endl;
        cout <<"Ingrese una opcion: ";
        cin>>opt;

        switch (opt)
        {
        case 1: procesarLista();
            break;

        case 2: procesarLDMEL();
            break;
        
        default:
            break;
        }
    }while(opt != 3);
}
