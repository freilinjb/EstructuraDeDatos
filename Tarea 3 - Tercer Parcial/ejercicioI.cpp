
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
int cantidadProducto = 0;

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

//Variables blobales
struct cola q;

Producto seleccionarProducto(int opcion) {
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
            nombre.cantidad = itr->cantidad;
            cout <<"["<< 1+cantidad <<"] ";
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

//NO SE ESTA USANDO
void registraCliente(Cliente &cliente){

    Cliente t,q = new(struct clienteNodo);
    int codigoProducto;
    cout<<"\t\t[  REGISTRO DE CARRITO  ]\n";
    cout << "Nombre del Cliente: ";
    cin.ignore();
    getline(cin,q->nombre);
    cout << "Lista de Productos"<< endl;

    mosatrarProductos();

    cout << "Seleccione los Productos por su codigo: (0 para SALIR)";
    
    do {
        cin >> codigoProducto;
        q->producto.push_back(seleccionarProducto(codigoProducto));

    }while (codigoProducto != 0);
    

    q->sgte = NULL;

    if(cliente==NULL){
        cliente = q;
    } else {
        t = cliente;
        while(t->sgte!=NULL){
                t = t->sgte;
        }
        t->sgte = q;
    }
    cantidadCliente++;
}

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
void registrarCarrito(Lista &lista){

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
    cantidadCarrito++;

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
    
    string dato;  // numero a encolar
    string x ;    

    int op;

    do{
            menuCaja();

            cout<<"\n Ingrese opcion : ";
            cin>>op;

            switch(op){

                case 1: cout<< "\n NUMERO A ENCOLAR: "; cin>> dato;
                        encolarCaja( q, dato );
                        cout<<"\t\tNumero " << dato << " encolado..."<<endl;
                    break;
        
        
                case 2: x = desencolarCaja( q );
                        cout<<"\t\tNumero "<< x <<" desencolado..."<<endl;
                    break;
                        
        
                case 3: cout << "\n\n MOSTRANDO COLA\n\n";
                        if(q.delante!=NULL) muestraCola( q );
                        else   cout<<"\tCola vacia...!"<<endl;
                    break;
        
        
                case 4: vaciarCola( q );
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
    Lista lista=NULL;

    

    int op;

    do{
        menuCarrito();

        cout<<"\n Ingrese opcion : ";
        cin>>op;

        switch(op){
            case 1: registrarCarrito(lista);
                    break;

            case 2: listarCarrito(lista);
                    break;

            case 3: eliminarCarrito(lista);
                    break;

            case 4: cout << "[SALISTE DE LAS LISTAS]"<<endl;
        }
        cout<<endl;

    }while(op!=4);
}

void procesarCliente() {
    system("clear");

    q.delante = NULL;
    q.atras   = NULL;
    string x ;    

    //CARRITO
    Cliente cliente;
    cliente = NULL;

    

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

            // case 3: eliminarCarrito(cliente);
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


    for(int i = 0; i < 3; i++) {
        
        encolarCaja(q, "#"+to_string(i+1));
    }
   
    q.delante = NULL;
    q.atras   = NULL;
    procesarTodo();
    
    return 0;
}