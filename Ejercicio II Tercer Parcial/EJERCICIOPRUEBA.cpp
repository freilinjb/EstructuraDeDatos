#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>

using namespace::std;

struct nodo{
	string dato;
	nodo* siguiente;
} *primero, *ultimo;


void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarLista();
void limpiarBuffer();
void ordenarPalabra();


int main(){
	
	int opcion_menu=0;
	do
	{
		cout << "\n|       LISTA CIRCULAR SIMPLE       |\n";
		cout << "\n| 1. Insertar      | 4. Eliminar      |";
		cout << "\n| 2. Buscar        | 5. Desplegar     |";
		cout << "\n| 3. Modificar     | 6. Salir         |";
		cout << "\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
			insertarNodo();
			break;
		case 2:
			cout << "\n\n BUSCAR UN NODO EN LA LISTA \n\n";
			buscarNodo();
			break;
		case 3:
			cout << "\n\n MODIFICAR UN NODO DE LA LISTA \n\n";
			modificarNodo();
			break;
		case 4:
			cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
			eliminarNodo();
			break;
		case 5: 
			cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
			desplegarLista();
			break;
		case 6:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 6);
	
	return 0;
}

void ordenarPalabra()
{
     struct nodo *aux1, *aux2;
     int p_aux;
     string c_aux;
     
     aux1 = primero->siguiente;
     
     while( aux1->siguiente != NULL)
     {
            aux2 = aux1->siguiente;
            
            while( aux2 != NULL)
            {
                   if( aux1->dato > aux2->dato )
                   {
                       c_aux = aux1->dato;
                       
                       aux1->dato   = aux2->dato;
                       
                       aux2->dato   = c_aux;
                   }
                   
                   aux2 = aux2->siguiente;
            }
            
            aux1 = aux1->siguiente;
     }
}

void limpiarBuffer() {
    fflush(stdin);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}	
 
void insertarNodo(){
	nodo* nuevo = new nodo();
    cin.ignore();
	cout << " Ingrese el dato: ";
    getline(cin, nuevo->dato);
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";

    // ordenarPalabra();
}

void buscarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	string busqueda = "0";
	cout << "\n Dato a Buscar: ";
	cin >> busqueda;
	if(primero!=NULL){
		do{
			
			if(actual->dato == busqueda){
				cout << "\n El nodo con el dato ( " << busqueda << " ) Encontrado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	string nodoBuscado = 0;
	cout << "\n Ingrese el dato del nodo a Buscar para Modificar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->dato == nodoBuscado){
				cout << "\n El nodo con el dato ( " << nodoBuscado << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cin >> actual->dato;
				cout << "\n Nodo Modificado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	string nodoBuscado = 0;
	cout << "\n Ingrese el dato del nodo a Buscar para Eliminar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->dato == nodoBuscado){
				cout << "\n El nodo con el dato ( " << nodoBuscado << " ) Encontrado";
				
				if(actual==primero){
					primero = primero->siguiente;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					anterior->siguiente = primero;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				
				cout << "\n Nodo Eliminado\n\n";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void desplegarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->dato;
			actual = actual->siguiente;
		}while(actual!=primero);
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}
