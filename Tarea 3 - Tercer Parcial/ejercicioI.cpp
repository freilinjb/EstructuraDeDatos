
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <iomanip>

using namespace std;

struct nodo{
    string dato; 
    bool estado = true;
    struct nodo *sgte;
};


typedef struct nodo *Lista;

struct cola {
    nodo *delante;
    nodo *atras;
};

struct cola Cajas;

struct Producto {
    string nombre;
    int cantidad;
    Producto(const string nombre, const int cantidad) {
        this->nombre = nombre;
        this->cantidad = cantidad;
    }

    Producto(){}

    void imprimir() const {
        int width = 15;
            cout  << nombre<<  setw(width) << right << cantidad << endl;   
    }
};
list<Producto> productos;
int carritoSeleccionado = 0;
int cantidadProducto = 0;

Producto seleccionarProducto(const int opcion, const int cantidadProducto) {
    int cantidad = 0;
    Producto nombre;
    cin.clear();
    fflush(stdin);
    
    int width = 25;
    
    list<Producto>::const_iterator itr = productos.begin();
    
    while(itr != productos.end()){
        cin.clear();
        fflush(stdin);
        ++itr;
        cantidad++;

        if(cantidad == opcion) {
            nombre.nombre = itr->nombre;
            nombre.cantidad = cantidadProducto;
            cout <<"\n\t["<< cantidad+1 <<"] ";
            cout << "nombre: " <<nombre.nombre<<endl;
            break;
        }
    }

    return nombre;
}

void mosatrarProductos() {

    int cantidad = 0;

    cin.clear();
    fflush(stdin);
    
    int width = 25;
    cout << right << "Producto" << setw(width) << "Cantidad" << endl;   
    
    list<Producto>::const_iterator itr = productos.begin();
    
    while(itr != productos.end()){
        cin.clear();
        fflush(stdin);
        cout <<"["<< 1+cantidad <<"] ";
        itr->imprimir();
        ++itr;
        cantidad++;
    }
    cout << "Cantidad de registros: " << cantidad << endl;
}

void mosatrarProductosPorCliente(list<Producto> prod) {

    int cantidad = 0;

    cin.clear();
    fflush(stdin);
    
    int width = 25;
    cout << right << "Producto" << setw(width) << "Cantidad" << endl;   
    
    list<Producto>::const_iterator itr = prod.begin();
    
    while(itr != prod.end()){
        cin.clear();
        fflush(stdin);
        cout <<"["<< 1+cantidad <<"] ";

        itr->imprimir();
        ++itr;
        cantidad++;
    }
    cout << "Cantidad de registros: " << cantidad << endl;
}

struct clienteNodo {
    string nombre;
    string carrito;
    list<Producto> producto;
    string estado;
    struct clienteNodo *sgte;
};

typedef struct clienteNodo *Cliente;

int cantidadCarrito = 0;
int cantidadCliente = 0;

//VARIABLES GLOBALES
Lista lista=NULL;

Cliente cliente = NULL;

string seleccionarCarritoCliente(Lista carrito) {
    Lista temp = carrito;
    int opcion;
    int cantidad = 0;
    string cart;

    cout<<"\n[  LISTA DE CARRITOOS  ]"<<endl;
    int width = 15;

    cout <<right << "Carrito" << setw(width) << "Estado"  <<endl;    

    while(lista!=NULL){
        if(lista->estado) {
            cout <<setw(width-10)  << lista->dato << setw(width+5) <<(lista->estado ? "Disponible" : "Ocupado") <<endl;
        }
        lista=lista->sgte;
    }
    carritoSeleccionado++;
    return "#carrito"+to_string(carritoSeleccionado);
}

//NO SE ESTA USANDO


void listarCliente(Cliente cliente){

    int i=1;
    cout<<"[  LISTA DE CLIENTES  ]"<<endl;
    int width = 15;

    cout <<right << "CLIENTE" << setw(width) << "Estado"  <<endl;    
    cin.clear();
    while(cliente!=NULL){

        cout<< cliente->nombre << setw(width) <<cliente->estado <<endl;
        mosatrarProductosPorCliente(cliente->producto);
        cliente = cliente->sgte;

        i++;
    }

}


void encolarCaja(struct cola &q, string dato) {
    struct nodo *aux = new(struct nodo);

      aux->dato = dato;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;
}

string desencolarCaja( struct cola &q ) {
     string dato ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     dato = aux->dato;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return dato;
}

void muestraCola( struct cola q ) {
     struct nodo *aux;
     
     aux = q.delante;
    cout << "CAJA" << endl;
     while( aux != NULL )
     {
            cout<<"   "<< aux->dato <<endl;
            aux = aux->sgte;
     }    
}

void vaciarCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}

//NO SE ESTA USANDO
void registra(Lista &lista){

    Lista t,q = new(struct nodo);

    cout<<"\t\t[  REGISTRO DE CLIENTE  ]\n";
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
    cantidadCarrito++;
}
void registrarCarrito(){

    Lista t,q = new(struct nodo);

    cout<<"\t\t[  REGISTRO DE CARRITO  ]\n";
    cout<<"\t\t------------";
    string nombre = "#"+to_string(cantidadCarrito+1);
    q->dato = nombre;
    cout<< "Carrito registrado: " + nombre<< endl;
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
    cantidadCarrito++;
}

void registrarCarrito(const string dato){

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
    cantidadCarrito++;

}

void listarCarritos(Lista carrito){

    int i=1;
    int cantidad = 0;
    cout<<"[  LISTA DE CARRITOOS  ]"<<endl;
    int width = 15;

    cout <<right << "Carrito" << setw(width) << "Estado"  <<endl;    

    while(carrito!=NULL){
        cantidad++;
        cout<<"["<< cantidad <<"] ";
        cout <<setw(width-10)  << carrito->dato << setw(width+5)<<(carrito->estado ? "Disponible" : "Ocupado") <<endl;

        carrito=carrito->sgte;

        i++;
    }

}

void eliminarCarrito(){

    string cod;
    Lista q,t;
    q=lista;

    if(lista==NULL){

        cout<<"\tLISTA VACIA.....!!!!";

    }else{

        cout<<"\tELIMINAR UN CARRITOO";

        while(q!=NULL){
            cout<<"hola "<<endl;
            if(q->dato==cod){

                if(q==lista){
                    lista=lista->sgte;
                    lista->estado = false;
                }

                else{
                    t->sgte=q->sgte;
                    lista->estado = false;
                }

                t->sgte->estado = false;

                delete(q);

                cout<<"\tCARRITOO  ELIMINADO...!!!!!\n";

                return;

            }else {

                t=q;
                q=q->sgte;
        }

    }
    if(q==NULL)
        cout<<"\n\tESTA VACIO...!!\n";
    }
}

///MENU DE LA LISTA CLIENTES
void menuCliente() {
    cout<<"---------[LISTA DE CLIENTES]---------"<<endl;
    cout<<" 1. REGISTRAR CLIENTE                     "<<endl;
    cout<<" 2. LISTAR CLIENTES                       "<<endl;
    cout<<" 3. REALIZAR COMPRA                       "<<endl;
    cout<<" 3. IR A CAJA                             "<<endl;
    cout<<" 3. ELIMINAR CLIENTE                      "<<endl;
    cout<<" 4. SALIR                                 "<<endl;
}

///MENU DE LA LISTA CLIENTES
void menuCaja() {
    cout<<"---------[COLA DE CAJA]---------"<<endl;
    cout<<" 1. ENCOLAR CAJA                          "<<endl;
    cout<<" 2. DESENCOLAR CAJA                            "<<endl;
    cout<<" 3. MOSTRAR COLA                          "<<endl;
    cout<<" 4. VACIAR COLA                           "<<endl;
    cout<<" 5. SALIR                                 "<<endl;
}

///MENU DE LA LISTA CARRITOS
void menuCarrito() {
    cout<<"---------[LISTA DE CARRITOS]---------"<<endl;
    cout<<" 1. REGISTRAR CARRITO                     "<<endl;
    cout<<" 2. LISTAR CARRITOS                       "<<endl;
    cout<<" 3. ELIMINAR CARRITO                      "<<endl;
    cout<<" 4. SALIR                                 "<<endl;
}

void procesarCaja() {
    system("clear");

    Cajas.delante = NULL;
    Cajas.atras   = NULL;
    string dato;  // numero a encolar
    string x ;    

    for(int i = 0; i < 3; i++) {
        
        encolarCaja(Cajas, "#"+to_string(i+1));
    }
   

    int op;

    do{
            menuCaja();
            cout<<"\n Ingrese opcion : ";
            cin>>op;

            switch(op){

                case 1: cout<< "\n NUMERO A ENCOLAR: "; cin>> dato;
                        encolarCaja( Cajas, dato );
                        cout<<"\t\tNumero " << dato << " encolado..."<<endl;
                    break;
        
        
                case 2: x = desencolarCaja( Cajas );
                        cout<<"\t\tNumero "<< x <<" desencolado..."<<endl;
                    break;
                        
        
                case 3: cout << "\n\n MOSTRANDO COLA\n\n";
                        if(Cajas.delante!=NULL) muestraCola( Cajas );
                        else   cout<<"\tCola vacia...!"<<endl;
                    break;
        
        
                case 4: vaciarCola( Cajas );
                        cout<<"\t\tHecho..."<<endl;
                    break;

                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
            }
            cout<<endl;

        }while(op!=5);
}

void procesarCarritos() {
    system("clear");

    string x ;    

    //CARRITO

   

    int op;

    do{
         menuCarrito();
        cout<<"\n Ingrese opcion : ";
        cin>>op;

        switch(op){
            case 1: registrarCarrito();
                    break;

            case 2: listarCarritos(lista);
                    break;

            case 3: eliminarCarrito();
                    break;

            case 4: cout << "[SALISTE DE LAS LISTAS]"<<endl;
        }
        cout<<endl;

    }while(op!=4);
}

void registraCliente(Cliente &cliente){

    Cliente t,q = new(struct clienteNodo);
    int codigoProducto;
    int cantidadProducto;
    cout<<"\t\t[  REGISTRO DE CARRITO  ]\n";
    cout << "Nombre del Cliente: ";
    cin.ignore();
    getline(cin,q->nombre);
    cout << "Lista de Productos"<< endl;

    mosatrarProductos();

    cout << "Seleccione los Productos por su codigo: (0 para SALIR)";
    
    do {
        cout<<"codigo Producto: ";
        cin >> codigoProducto;
        cout<<"Cantidad: ";
        cin >> cantidadProducto;


        q->producto.push_back(seleccionarProducto(codigoProducto,cantidadProducto));

        cout << "Continuar: 1\nSalir: 0 "<<endl;


    }while (codigoProducto != 0 || cantidadProducto != 0);

    q->carrito = seleccionarCarritoCliente(lista);
    // listarCarritos(lista);
}

void procesarCliente() {
    system("clear");

    string x ;    

    //CARRITO

    

    int op;

    do{
        menuCliente();
        cout<<"\n Ingrese opcion : ";
        cin>>op;

        switch(op){
            case 1: registraCliente(cliente);
                    break;

            case 2: listarCliente(cliente);
                    break;

            // case 3: eliminarCarrito();
            //         break;

            case 4: cout << "[SALISTE DE LAS LISTAS]"<<endl;
        }
        cout<<endl;

    }while(op!=4);
}
void procesarTodo() {
    string menu = "**********[MENU]**********\n1. [    LISTA CARRITOS  ]\n2. [    COLA DE CAJAS   ]\n3. [  LISTA DE CLIENTES ]\n4. [ LISTA DE PRODUCTOS ]\n5. [        SALIR       ]\n";
    int opt;

    do{
        cout <<menu<< "Seleccione una opcion: ";
        cin >> opt;

        switch (opt)
        {
        case 1: 
            procesarCarritos();
            break;
        
        case 2:
            procesarCaja();
            break;

        default:
            procesarCliente();
            break;

        case 4:
            mosatrarProductos();
            break;
        }
    }while (opt != 5);

    cout << "salio" <<endl;
}

int main(void){

    Producto p[10];
    p[0] = {"Pata de Lerdo",96};
    p[1] = {"Carne de Res",87};
    p[2] = {"Pollo Entero",10};
    p[3] = {"Pescado",81};
    p[4] = {"Arenque Rojo",13};
    p[5] = {"Leche Miled",41};
    p[6] = {"Azucar Blanca",56};
    p[7] = {"Papa Frita",98};
    p[8] = {"Arroz Blanco",45};
    p[9] = {"Arica de Maiz",50};

    for(int i = 0; i < 10; i++) {
        productos.push_front(p[i]);
    }

    for(int i = 0; i < 25; i++) {
        
        registrarCarrito("#"+to_string(i+1));
    }

    system("clear");
        struct cola q;
   
    q.delante = NULL;
    q.atras   = NULL;
    procesarTodo();
    
}