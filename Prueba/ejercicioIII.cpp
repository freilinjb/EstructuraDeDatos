#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>

#include <list>

using namespace std;

template<class T> struct Nodo{
	T elemento;
	Nodo* sgte;
	Nodo* anterior;

	Nodo(T e = 0, Nodo* s = nullptr, Nodo* a = nullptr) : elemento(e), sgte(s), anterior(a){}
};

template<class T> class Lista{
private:
	Nodo<T>* inicio;
	int n_elementos;

public:
	Lista(){
		inicio = nullptr;
		n_elementos = 0;
	}
	~Lista(){
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
};

int main(){
	Lista<int> listas;

	for (int i = 0; i < 10; i++){
		listas.Insertar_Ordenado(i + 1);
	}

	listas.Mostrar();
	cout << endl;

	cout << endl;
	// listas.Eliminar_elementos(3, 7);

	// cout << endl;
	listas.Mostrar();

	return 0;
}

// #include<iostream>
// #include<cstdlib>
// #include <cmath>

// #define maxchar 50

// using namespace std;

// struct nodo{


//     int numero; 
//     struct nodo *sgte;
// };


// typedef struct nodo *Lista;

// void menu(void){

//     cout<<"\n\t\t[     LISTA EN LAZADADE NUMEROS     ]\n";
//     cout<<"\t\t----------------------------------\n\n";
//     cout<<" 1. REGISTRAR NUMERO                         "<<endl;
//     cout<<" 2. LISTAR NUMERO                            "<<endl;
//     cout<<" 3. ELIMINAR NUMERO                          "<<endl;
//     cout<<" 3. SALIR                                    "<<endl;

// }


// void agrergarNodo(Lista &lista) {
//     Lista aux;

//     if(lista != NULL && lista->sgte != NULL) {

//         lista->sgte = aux;
//     }

//     else {
//         cout<<"\n\n\tLISTA VACIA.....!!!!";
//     }
// }

// void registrar(Lista &lista){

//     Lista t,q = new(struct nodo);

//     cout<<"\n\n\t\t[  REGISTRO  ]\n";
//     cout<<"\t\t------------";
//     cout<<"\n\tNumero:"; cin>>q->numero;
//     cout<<endl;

//     q->sgte = NULL;

//     if(lista==NULL){

//         lista = q;

//     } else {

//         t = lista;

//         while(t->sgte!=NULL){
//             t = t->sgte;
//         }

//         t->sgte = q;

//     }
// }

// void listar(Lista q){
//     Lista aux;

//     int i=1;
//     cout<<"\n\n\t[  LISTA DE NUMEROS  ]";
//     cout<<"\n\n\t-------------------------"<<endl;
//     while(q!=NULL){


//         // aux->numero = abs(q->numero - q->sgte->numero);
//         // aux->sgte = q->sgte; 
//         // q->sgte = aux;
//         cout<<"\tNumero  : "<<q->numero<<endl;
        
//         q=q->sgte;

//         i++;
//     }


// }


// void eliminar(Lista &lista){

//     int cod;
//     Lista q,t;
//     q=lista;

//     if(lista==NULL){

//         cout<<"\tLISTA VACIA.....!!!!";

//     }else{

//         cout<<"\tELIMINAR DE NUMEROS";
//         cout<<"\tINGRESE UN NUMERO:"; cin>>cod;

//         while(q!=NULL){

//             if(q->numero==cod){

//                 if(q==lista)
//                     lista=lista->sgte;

//                 else
//                     t->sgte=q->sgte;

//                 delete(q);

//                 cout<<"\tNUMERO  ELIMINADO...!!!!!\n";

//                 return;

//             }else {

//                 t=q;
//                 q=q->sgte;

//         }

//     }
//     if(q==NULL)
//         cout<<"\tCODIGO INCORRECTO...!!\n";

//     }
// }

// int main(void){

//     Lista lista=NULL;

//     int op;
//     menu();

//     do{
//             cout<<"\n Ingrese opcion : ";
//             cin>>op;

//             switch(op){

//                 case 1: registrar(lista);
//                         break;

//                 case 2: listar(lista);
//                         break;

//                 case 3: eliminar(lista);
//                         break;

//                 case 4: return 0;


//                 default: cout<<"INGRESE UNA OPCION VALIDA...\n"; break;

//             }
//             cout<<endl;

//         }while(op!=6);


//     return 0;
// }