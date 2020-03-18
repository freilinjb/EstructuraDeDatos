#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <limits>

#include <list>

using namespace std;

class Pila2
{

public:
    // void procesar();
    struct Nodo
    {
        string dato;
        Nodo *siguiente;
    } typedef *pila;

    Pila2()
    {
    }
    static void limpiarBuffer2()
    {
        fflush(stdin);
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

        void limpiarBuffer()
    {
        fflush(stdin);
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void agregarPila(pila &p, string n)
    {
        pila nuevo_nodo = new (struct Nodo);

        nuevo_nodo->dato = n;
        nuevo_nodo->siguiente = p;
        p = nuevo_nodo;

        cout << "Elemento agregado a la pila: " << n << endl;
    }

    void agregarPilaEntrada(pila &p)
    {
        string n;
        cout << "**[REGISTRO DE ESTUDIANTE]**" << endl;
        cout <<"Nombre: ";
        limpiarBuffer();

        getline(cin, n);

        pila nuevo_nodo = new (struct Nodo);

        nuevo_nodo->dato = n;
        nuevo_nodo->siguiente = p;
        p = nuevo_nodo;

        cout << "Elemento agregado a la pila: " << n << endl;
    }



    string sacarPila(pila &p)
    {
        string dato;
        pila aux;

        aux = p;
        dato = aux->dato;
        p = aux->siguiente;

        delete (aux);

        limpiarBuffer();

        return dato;
    }

    void destruir_pila(pila &p)
    {
        pila aux;

        while (p != NULL)
        {
            aux = p;
            p = aux->siguiente;
            delete (aux);
        }
    }

    void mostrarPila(pila p)
    {
        pila aux;
        aux = p;

        int cantidad = 0;

        while (aux != NULL)
        {
            cout << "[" << aux->dato << "]" << endl;
            aux = aux->siguiente;

            cantidad++;
        }
        cout << " Cantidad de estudiantes registrados: " << "[" << cantidad << "]" <<endl;

        limpiarBuffer();
    }

    void menu()
    {
        cout << "\n\t IMPLEMENTACION DE ESTUDIANTES EN PILAS EN C++\n\n";
        cout << " 1. APILAR                                " << endl;
        cout << " 2. DESAPILAR                             " << endl;
        cout << " 3. MOSTRAR PILA                          " << endl;
        cout << " 4. DESTRUIR PILA                         " << endl;
        cout << " 5. SALIR                                 " << endl;

        cout << "\n INGRESE OPCION: ";
    }

    int procesarPila()
    {
        pila p = NULL; // creando pila
        string dato;
        int op;
        string x; // numero que devuelve la funcon pop

        do
        {
            menu();
            cin >> op;

            switch (op)
            {
            case 1:

                cout << "\n Estudiante: ";
                limpiarBuffer();

                getline(cin, dato);

                agregarPila(p, dato);
                cout << "\n\n\t\tEstudiante " << dato << " apilado...\n\n";
                break;

            case 2:

                x = sacarPila(p);
                cout << "\n\n\t\tEstudiante " << x << " desapilado...\n\n";
                limpiarBuffer();

                break;

            case 3:
                limpiarBuffer();

                cout << "\n\n MOSTRANDO PILA\n\n";
                if (p != NULL)
                    mostrarPila(p);
                else
                {
                    cout << "\n\n\tPila vacia..!" << endl;
                    limpiarBuffer();
                }
                break;

            case 4:
                limpiarBuffer();

                destruir_pila(p);
                cout << "\n\n\t\tPila eliminada...\n\n";
                break;
            }

            cout << endl
                 << endl;

        } while (op != 5);

        return 0;
    }
};

class Cola : protected Pila2
{
public:
    Pila2 Pila;
    struct cola
    {
        string materia;
        Pila2::Nodo estudiante;
        Pila2::Nodo *delante;
        Pila2::Nodo *atras;

        cola(const string materia)
        {
            this->materia = materia;
        }

        cola() {}
    };

    void encolar(cola &q, const string dato)
    {
        Pila2::Nodo *aux = new Pila2::Nodo();

        aux->dato = dato;
        aux->siguiente = NULL;

        q.delante == NULL ? q.delante = aux : (q.atras)->siguiente = aux;

        q.atras = aux;
        q.materia = aux->dato;

        char x;
        while (true)
        {
            
            limpiarBuffer();
            cout << "Desea ingresar registrar estudiante(S/N): " << endl;
            cin >> x;

            if(x == 's' || x == 'S')
            {
                agregarPilaEntrada(q.estudiante.siguiente);
            }
            else if(x == 'n' || x == 'N'){
                cout << "**[Adios]**" << endl;
                break;
            }

            mostrarPila(q.estudiante.siguiente);
        }
    }

    string desencolar(cola &q)
    {
        string dato;
        Nodo *aux;

        aux = q.delante;
        dato = aux->dato;
        q.delante = (q.delante)->siguiente;
        delete (aux);

        return dato;
    }

    void mostrarCola(cola q)
    {
        Nodo *aux;
        aux = q.delante;

        while (aux != NULL)
        {
            cout << "[" << aux->dato << "]" << endl;
            aux = aux->siguiente;
        }

        cout << "\n\n**[precione una tecla para continuear]**" << endl;
        limpiarBuffer2();
        getchar();
    }

    void vaciarCola(cola &q)
    {
        Pila2::Nodo *aux;

        while (q.delante != NULL)
        {
            aux = q.delante;
            q.delante = aux->siguiente;
            delete (aux);
        }

        q.delante = NULL;
        q.atras = NULL;
    }

    void menuCola()
    {
        cout << "\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
        cout << " 1. ENCOLAR                               " << endl;
        cout << " 2. DESENCOLAR                            " << endl;
        cout << " 3. MOSTRAR COLA                          " << endl;
        cout << " 4. VACIAR COLA                           " << endl;
        cout << " 6. MOSTRAR PILA DE ESTUDIANTES           " << endl;
        cout << " 5. SALIR                                 " << endl;

        cout << "\n INGRESE OPCION: ";
    }

    void menuPrincipal()
    {
        cout << "1. Menu Mantenimiento Asignatura" << endl;
        cout << "2. Menu Mantenimiento Estudiante" << endl;
        cout << "SELECCIONE UNA OPCION: ";
    }
    void procesarCola()
    {
        struct cola q;

        q.delante = NULL;
        q.atras = NULL;

        string dato; // numero a encolar
        int op;      // opcion del menu
        string x;    // numero que devuelve la funcon pop

        do
        {
            menu();
            cin >> op;

            switch (op)
            {
            case 1:

                cout << "\n ASIGNATURA A ENCOLAR: ";
                cin >> dato;
                encolar(q, dato);
                cout << "\n\n\t\tAsignatura " << dato << " encolado...\n\n";
                break;

            case 2:

                x = desencolar(q);
                cout << "\n\n\t\tNumero " << x << " desencolado...\n\n";
                break;

            case 3:

                cout << "\n\n MOSTRANDO COLA\n\n";
                if (q.delante != NULL)
                    mostrarCola(q);
                else
                    cout << "\n\n\tCola vacia...!" << endl;
                break;

            case 4:

                vaciarCola(q);
                cout << "\n\n\t\tHecho...\n\n";
                break;
            }

            cout << endl
                 << endl;
            system("clear");

        } while (op != 5);

        cout << "hola mundo" << endl;
    }

    void procesarOpciones()
    {
        int x;
        while (x != 10)
        {
            menuPrincipal();

            cin >> x;
            if(x == 1) {
                procesarPila();
            }

            else if(x == 2) {
                procesarCola();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    // Pila2 pila;
    // pila.procesarPila();

    Cola cola;
    cola.procesarOpciones();
    return 0;
}

/*

struct Nodo
{
    string dato;
    Nodo *siguiente;
};

struct Cola
{
    Nodo *delante;
    Nodo *atras;
};

struct Materia
{
    string nombre;
    Cola estudiante;

    void mostrarCola() const
    {
        Nodo *aux;
        aux = estudiante.delante;

        while (aux != NULL)
        {
            cout << "[" << aux->dato << "]" << endl;
            aux = aux->siguiente;
        }
        cout << "\n\n**[precione una tecla para continuar]**" << endl;
        getchar();
        getchar();
    }

    Materia(const string nombre)
    {
        this->nombre = nombre;
    }
};

list<Materia> materias;

void encolar(Cola &q, string dato)
{
    Nodo *aux = new Nodo();

    aux->dato = dato;
    aux->siguiente = NULL;

    q.delante == NULL ? q.delante = aux : (q.atras)->siguiente = aux;

    q.atras = aux;
}

void encolarMaterias(Materia &m, string dato)
{
    Materia temp[8] = {
        {"Proyecto I"},
        {"Estructura de datos"},
        {"Base de Datos I"},
        {"Base de Datos II"},
        {"Calculo I"},
        {"Calculo II"},
        {"Calculo III"},
        {"Ingenieria Economica"}};

    for (int i = 0; i < 8; i++)
        materias.push_back(temp[i]);
}

void mostrarCuentas()
{
    cout << "\n"
         << endl;

    cin.clear();
    fflush(stdin);

    int cantidad = 0;
    int width = 25;
    cout << left << "Num" << setw(width) << "fecha" << setw(width) << "debito" << setw(width) << "credito" << endl;
    cout << right << "MOVIMIENTO" << setw(width) << "CUENTA" << setw(width) << "DEBITO" << setw(width) << "CREDITO" << setw(width) << "HORA"
         << ""
         << "|" << setw(width) << "FECHA" << endl;

    list<Materia>::const_iterator itr = materias.begin();
    while (itr != materias.end())
    {
        cin.clear();
        fflush(stdin);
        cout << "[" << 1 + cantidad << "] ";
        itr->mostrarCola();
        ++itr;
        cantidad++;
    }
    cout << "Cantidad de registros: " << cantidad << endl;
}

string desencolar(Cola &q)
{
    string dato;
    Nodo *aux;

    aux = q.delante;
    dato = aux->dato;

    q.delante = (q.delante)->siguiente;
    delete (aux);

    return dato;
}

void mostrarCola(Cola q)
{
    Nodo *aux;
    aux = q.delante;

    while (aux != NULL)
    {
        cout << "[" << aux->dato << "]" << endl;
        aux = aux->siguiente;
    }

    cout << "\n\n**[PRECIONE UNA TECLA PARA CONTINUAR]**" << endl;
    getchar();
    getchar();
}

void vaciarCola(Cola &q)
{
    Nodo *aux;

    while (q.delante != NULL)
    {
        aux = q.delante;
        q.delante = aux->siguiente;
        delete (aux);
    }

    q.delante = NULL;
    q.atras = NULL;
}

int main(int argc, char const *argv[])
{
    cout << "prueba de texto" << endl;
    return 0;
}
*/