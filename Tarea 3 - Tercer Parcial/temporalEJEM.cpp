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
    int dato;
    nodo *siguiente;
};

typedef struct nodo *PLista,*Carrito,*Cliente,clienteDespachado;
//Instancias Globales
Cliente cliente=NULL;
Carrito carrito=NULL;
int idCliente = 0, idCarrito;
int carritoAsignado = 0;

void mostrar_clientes(Cliente q);

void menuCliente(void){

    cout<<"\t\t[    REGISTRO DE CLIENTE    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR PACIENTE                          "<<endl;
    cout<<" 2. ELIMINAR DATOS DE PACIENTE                  "<<endl;
    cout<<" 3. ACTUALIZAR PACIENTES                        "<<endl;
    cout<<" 4. MOSTRAR LISTADO                             "<<endl;
    cout<<" 5. TOMAR UN CARRITO                            "<<endl;
    cout<<" 6. SALIR                                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}

void menuCaja(void){

    cout<<"\t\t[    REGISTRO DE CAJA    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR PACIENTE                          "<<endl;
    cout<<" 2. ELIMINAR DATOS DE PACIENTE                  "<<endl;
    cout<<" 3. ACTUALIZAR PACIENTES                        "<<endl;
    cout<<" 4. MOSTRAR LISTADO                             "<<endl;
    cout<<" 5. COPIAR DATOS DE UN PACIENTE A OTRO          "<<endl;
    cout<<" 6. SALIR                                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}

void menuCarrito(void){

    cout<<"\t\t[    REGISTRO DE CARRITO    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR CARRITO                          "<<endl;
    cout<<" 2. ELIMINAR DATOS DE PACIENTE                  "<<endl;
    cout<<" 3. ACTUALIZAR CARRITO                        "<<endl;
    cout<<" 4. MOSTRAR LISTADO                             "<<endl;
    cout<<" 4. MOSTRAR LISTADO                             "<<endl;
    cout<<" 5. SALIR                                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}
/*--------------------- FUNCION MENU PRINCIPAL --------------------*/



/*----------------- CUNCION PARA ACTUALIZAR UN DATO---------------*/
void menu_actualizar(void){

    cout<<"\n\t\t[    ESPECIFIQUE CAMPO A ACTUALIZAR    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. NOMBRES                       "<<endl;
    cout<<" 2. APELLIDOS                     "<<endl;
    cout<<" 3. DIRECCION                     "<<endl;
    cout<<" 4. TELEFONO                      "<<endl;
    cout<<" 5. SALIR                         "<<endl;

    cout<<"\n Ingrese opcion : ";
}


/*-------------------- FUNCION REGISTRAR PACIENTES ------------------*/
void registrar_cliente(Cliente &lista){

    Cliente t,q = new(struct nodo);
    idCliente++;
    cout<<"\n\n\t\t[  REGISTRO  ]\n";
    cout<<"\n\tDATOS DEL PACIENTE ";
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

/*------------------------ FUNCIONES ELIMINAR PACIENTE ---------------------*/
void eliminar_cliente(Cliente &lista){
    int cod;
    Cliente q,t;
    q=lista;

    cout<<"\n\n\n\tELIMINAR UN PACIENTE";
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

    cout << "seleccione el cod. del cliente";
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
                cout<<"\n\tDATOS DEL PACIENTE  ";
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

    cout<<"\n\n\n\tACTUALIZAR REGISTRO DE PACIENTE";
    cout<<"\n\n\tINGRESE CODIGO:"; cin>>cod;

    while(q!=NULL){

            if(q->codigo==cod){
                cout<<"\n\tDATOS DEL PACIENTE  ";
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
                            cout<<"\n\tNo Hay Pacientes Registrados.....!!!!\n";
                        }else{
                            eliminar_carrito(carrito);
                        }
                        break;

                case 3: if(cliente==NULL){
                            cout<<"\n\tNo Hay Pacientes Registrados.....!!!!\n";
                        }else{
                            actualizar_carrito(carrito);
                        }
                        break;

                case 4: if(carrito==NULL){
                            cout<<"\n\tNo Hay Pacientes Registrados.....!!!!\n";
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

void procesarTodo() {
    string menu = "**********[MENU]**********\n1. [LISTA CARRITOS  ]\n2. [COLA DE CAJAS   ]\n3. [LISTA DE CLIENTES ]\n4. [ LISTA DE PRODUCTOS ]\n5. [        SALIR       ]\n";
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
            procesarCliente();
            break;

        case 3:
            procesarCliente();
            break;


        case 4:
            menuCliente();
            break;
        }
    }while (opt != 5);

    cout << "salio" <<endl;
}

int main(int argc, char const *argv[])
{
    system("clear");
    procesarTodo();
    
    return 0;
}
