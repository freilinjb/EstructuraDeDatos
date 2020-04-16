#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
#include <iomanip>

#define maxchar 50

using namespace std;

struct nodo{
    int codigo;     // campo codigo
    string nombre; // campo que almacena el nombre
    string estado;
    struct nodo *sgte;
};

struct cola {
    nodo *delante;
    nodo *atras;
};

typedef struct nodo *PLista,*Carrito,*Cliente,clienteDespachado;
//Instancias Globales
Cliente cliente=NULL;
Carrito carrito=NULL;
struct cola q;

int idCliente = 0, idCarrito = 0, idCaja = 0;
int carritoAsignado = 0;

void mostrar_clientes(Cliente q);

void menuCliente(void){

    cout<<"\t\t[    REGISTRO DE CLIENTE    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR CLIENTE                          "<<endl;
    cout<<" 2. ELIMINAR DATOS DE CLIENTE                  "<<endl;
    cout<<" 3. ACTUALIZAR CLIENTE                        "<<endl;
    cout<<" 4. MOSTRAR LISTADO                             "<<endl;
    cout<<" 5. TOMAR UN CARRITO                            "<<endl;
    cout<<" 6. SALIR                                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}

void menuCaja(void){

    cout<<"\t\t[    REGISTRO DE CAJA    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR (ENCOLAR) CAJA    "<<endl;
    cout<<" 2. ELIMINAR (DESENCOLAR) CAJA  "<<endl;
    cout<<" 3. MOSTRAR COLA                "<<endl;
    cout<<" 4. VACIAR COLA                 "<<endl;
    cout<<" 5. SALIR                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}

void menuCarrito(void){

    cout<<"\t\t[    REGISTRO DE CARRITO    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR CARRITO                          "<<endl;
    cout<<" 2. ELIMINAR DATOS DE CARRITO                  "<<endl;
    cout<<" 3. ACTUALIZAR CARRITO                        "<<endl;
    cout<<" 4. MOSTRAR LISTADO                             "<<endl;
    cout<<" 5. SALIR                                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}


/*-------------------- FUNCION REGISTRAR CLIENTE ------------------*/
void registrar_cliente(Cliente &lista){

    Cliente t,q = new(struct nodo);
    idCliente++;
    cout<<"\n\n\t\t[  REGISTRO  ]\n";
    cout<<"\n\tDATOS DEL CLIENTE ";
    q->codigo = idCliente;
    cin.ignore();cout<<"\n\tNOMBRES:"; getline(cin,q->nombre);

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

void registrar_carrito(Carrito &lista){

    Carrito t,q = new(struct nodo);
    idCarrito++;
    cout<<"\n\n\t\t[  REGISTRO  ]\n";
    q->codigo = idCarrito;
    q->nombre = "#" + to_string(idCarrito);
    q->estado = "Disponible";

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
    cout <<"Registro Carrito: [" << q->nombre << "]"<<endl;
}

/*----------------- CUNCION PARA ACTUALIZAR UN DATO---------------*/
void menu_actualizar(void){

    cout<<"\n\t\t[    ESPECIFIQUE CAMPO A ACTUALIZAR    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. NOMBRE                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}

/*------------------------ FUNCIONES ELIMINAR CLIENTE ---------------------*/
void eliminar_cliente(Cliente &lista){
    int cod;
    Cliente q,t;
    q=lista;

    cout<<"\n\n\n\tELIMINAR UN CLIENTE";
    cout<<"\n\n\tINGRESE CODIGO:"; cin>>cod;

    while(q!=NULL){

            if(q->codigo==cod){

                if(q==lista)
                    lista=lista->sgte;

                else
                    t->sgte=q->sgte;

                delete(q);

                cout<<"\n\n\tREGISTRO ELIMINADO...!!!!!\n";

                return;

            }else {

                t=q;
                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\n\tCODIGO INCORRECTO...!!\n";

}

void eliminar_carrito(Carrito &lista){
    int cod;
    Carrito q,t;
    q=lista;

    cout<<"\n\n\n\tELIMINAR UN CLIENTE";
    cout<<"\n\n\tINGRESE CODIGO:"; cin>>cod;

    while(q!=NULL){

            if(q->codigo==cod){

                if(q==lista)
                    lista=lista->sgte;

                else
                    t->sgte=q->sgte;

                delete(q);

                cout<<"\n\n\tREGISTRO ELIMINADO...!!!!!\n";

                return;

            }else {

                t=q;
                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\n\tCODIGO INCORRECTO...!!\n";
}

void seleccionar_carritoAcliente(Cliente listaCliente, Carrito listaCarrito) {
    int cod, x;
    Cliente c;
    Carrito k;

    bool disponible = false;
    c = listaCliente;
    k = listaCarrito;
    
    mostrar_clientes(cliente);

    cout << "seleccione el cod. del cliente: ";
    cin >> cod;

    //aumenta el carrito disponible
    int carritoDisponible = 1;

    while(k!=NULL){

        if((carritoDisponible < idCarrito) && k->estado == "Disponible") {

            if(k->codigo==cod) {
                cout<<"\n\tCARRITO ASIGNADO   ";
                cout<<"\n\t--------------------";
                cout<<"\n\n\tCODIGO   : "<<k->codigo<<"\tNOMBRES  : "<<k->nombre<<"\t"<<endl;

                k->estado = "Ocupado";
                carritoAsignado++;
                disponible = true;
                cout<<"\n\n\tREGISTRO ACTUALIZADO...!!!!!\n";

                break;
            } else {
            k=k->sgte;
            }
        }
        carritoDisponible++;
    }
    if(k==NULL)
        cout<<"\n\tCODIGO INCORRECTO...!!\n";

    if(disponible) {
        while(c!=NULL){
            if(c->codigo==idCliente){
                c->estado = "Comprando";
                return;
            }
            else {
                c=c->sgte;
            }
        }
    }
}


/*-------------------- FUNCIONES ACTUALIZAR -------------------*/
void actualizar_cliente(Cliente lista){

    int cod, x;
    Cliente q;
    q=lista;

    while(q!=NULL){

            if(q->codigo==cod){
                cout<<"\n\tDATOS DEL CLIENTE  ";
                cout<<"\n\t--------------------";
                cout<<"\n\n\tCODIGO   : "<<q->codigo<<endl;
                cout<<"\n\tNOMBRES  : "<<q->nombre<<endl;

                menu_actualizar();
                cin>>x;

                switch(x){

                    case 1: cout<<"\n\n\tINGRESE NOMBRES:";
                            cin.ignore(); getline(cin,q->nombre);
                            break;

                    default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

                }
                cout<<"\n\n\tREGISTRO ACTUALIZADO...!!!!!\n";

                return;

            }else {


                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\n\tCODIGO INCORRECTO...!!\n";
}

void actualizar_carrito(Carrito lista){

    int cod, x;
    Carrito q;
    q=lista;

    cout<<"\n\n\tINGRESE CODIGO:"; cin>>cod;

    while(q!=NULL){

            if(q->codigo==cod){
                cout<<"\n\tDATOS DEL CARRITO  ";
                cout<<"\n\t--------------------";
                cout<<"\n\n\tCODIGO   : "<<q->codigo<<endl;
                cout<<"\n\tNOMBRES  : "<<q->nombre<<endl;

                menu_actualizar();
                cin>>x;

                switch(x){

                    case 1: cout<<"\n\n\tINGRESE NOMBRES:";
                            cin.ignore(); getline(cin,q->nombre);
                            break;

                    default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

                }
                cout<<"\n\n\tREGISTRO ACTUALIZADO...!!!!!\n";

                return;

            }else {


                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\n\tCODIGO INCORRECTO...!!\n";
}

/*---------------------- FUNCIONES MOSTRAR -------------------*/
void mostrar_clientes(Cliente q){

    int i=1;

    cout<<"DATOS DE LOS CARRITOS "<<endl;
    cout<<"CODIGO \t    NOMBRE \t"<<"Estado"<<endl;
    

    while(q!=NULL){
        cout << q->codigo <<setw(20)<< q->nombre <<setw(20)<<q->estado<< endl;
        q=q->sgte;

        i++;
    }
}

void mostrar_carritos(Carrito q){
    int i=1;
    cout<<"DATOS DE LOS CARRITOS "<<endl;
    cout<<"CODIGO \t    NOMBRE \t"<<"ESTADO"<<endl;
    

    while(q!=NULL){
        cout << q->codigo <<setw(20)<< "carrito"+ q->nombre <<setw(20)<<q->estado<< endl;
        q=q->sgte;

        i++;
    }
}

/*--------------------- COLAS FUNCIONES ---------------------*/
void encolarCaja(struct cola &q, string dato) {
    struct nodo *aux = new(struct nodo);

      aux->nombre = dato;
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
     dato = aux->nombre;
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
            cout<<"   "<< aux->nombre <<endl;
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


/*------------------------- FUNCION PRINCIPAL -------------------*/
int procesarCliente(void){
    int opcion;

    do{
            menuCliente();
            cin>>opcion;

            switch(opcion){

                case 1: registrar_cliente(cliente);
                        break;

                case 2: if(cliente==NULL){
                            cout<<"\n\tNo Hay Clientes Registrados.....!!!!\n";
                        }else{
                            eliminar_cliente(cliente);
                        }
                        break;

                case 3: if(cliente==NULL){
                            cout<<"\n\tNo Hay Clientes Registrados.....!!!!\n";
                        }else{
                            actualizar_cliente(cliente);
                        }
                        break;

                case 4: if(cliente==NULL){
                            cout<<"\n\tNo Hay Clientes Registrados.....!!!!\n";
                        }else {
                            mostrar_clientes(cliente);
                        }
                        break;

                case 5: if(cliente==NULL){
                            cout<<"\n\tNo Hay Clientes Registrados.....!!!!\n";
                        } if(carrito == NULL) {
                            cout<<"\n\tNo Hay Carritos Registrados.....!!!!\n";

                        }else {
                            seleccionar_carritoAcliente(cliente, carrito);
                        }
                        break;

                case 6: return 0;

                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

            }

        }while(opcion!=6);

    return 0;
}
int procesarCarrito(void){

    int opcion;

    do{
            menuCarrito();
            cin>>opcion;

            switch(opcion){

                case 1: registrar_carrito(carrito);
                        break;

                case 2: if(cliente==NULL){
                            cout<<"\n\tNo Hay Carritos Registrados.....!!!!\n";
                        }else{
                            eliminar_carrito(carrito);
                        }
                        break;

                case 3: if(cliente==NULL){
                            cout<<"\n\tNo Hay Carritos Registrados.....!!!!\n";
                        }else{
                            actualizar_carrito(carrito);
                        }
                        break;

                case 4: if(carrito==NULL){
                            cout<<"\n\tNo Hay Carritos Registrados.....!!!!\n";
                        }else {
                            mostrar_carritos(carrito);
                        }
                        break;

                case 5: return 0;


                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

            }

        }while(opcion!=5);

    return 0;
}

void procesarCaja() {
    int op;

    do{
            menuCaja();
            cin>>op;

            switch(op){

                case 1: idCaja++;
                        encolarCaja( q, "Caja: #"+to_string(idCaja));
                        cout<<"\t\t" << "Caja: #"+to_string(idCaja) << " encolado..."<<endl;
                    break;

                case 2: cout<<"\t\tNumero "<< desencolarCaja( q ) <<" desencolado..."<<endl;
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

void procesarTodo() {
    string menu = "**********[MENU]**********\n1. [LISTA CARRITOS  ]\n2. [COLA DE CAJAS   ]\n3. [LISTA DE CLIENTES ]\n4. [LISTA DE PRODUCTOS ]\n5. [SALIR       ]\n";
    int opt;

    do{
        cout <<menu<< "Seleccione una opcion: ";
        cin >> opt;

        switch (opt)
        {
        case 1: 
            procesarCarrito();
            break;
        
        case 2:
            procesarCaja();
            break;

        case 3:
            procesarCliente();
            break;

        }
    }while (opt != 5);

    cout << "salio" <<endl;
}

int main(int argc, char const *argv[])
{

    for (int i = 0; i < 3; i++)
    {
        idCaja++;
        encolarCaja( q, "Caja: #"+to_string(idCaja));
    }
    
    for (int i = 0; i < 25; i++)
    {
        registrar_carrito(carrito);
    }

    system("clear");
    
    procesarTodo();
    
    return 0;
}
