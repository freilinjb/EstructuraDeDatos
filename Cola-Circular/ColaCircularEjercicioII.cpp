#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>

#include <stdlib.h>
#include <list>

#define MAX 5

using namespace std;

class ColaCircular
{
public:
    typedef struct
    {
        int final;
        int inicio;
        string vector[MAX];
        int cantidad;
        void imprimir() const {
            for (int i = 0; i < cantidad; i++)
            {
                cout << "[" << vector[i] << endl;
            }
        }
    } queue;


    list<queue> listaCola;


    int cantidad = 0;

    void Crear(queue &Cola)
    {
        Cola.final = -1;
        Cola.inicio = -1;
        cantidad = 0;
    }

    bool IsEmpty(queue Cola)
    {
        if (Cola.final == -1)
        {
            return true;
        }
        return false;
    }

    void crearCopia(const queue &Cola) {
        listaCola.push_back(Cola);
    }

void RecorrerCopias() {
        cout <<"\n"<<endl;

        int cantidad = 0;

        list<queue>::const_iterator itr = listaCola.begin();

        while(itr != listaCola.end()){
            if(cantidad == 0)
            cout <<"Cola circular #" << itr->cantidad << endl;
            itr->imprimir();
            ++itr;
            cantidad++;
        }
        cout << "\nCantidad de registros: " << cantidad << endl;
        system("pause");  
}

    int getElements(queue Cola)
    {
        if (IsEmpty(Cola))
        {
            return 0;
        }

        if (Cola.inicio < Cola.final)
        {
            return Cola.final - Cola.inicio + 1;
        }
        return MAX - Cola.inicio + Cola.final + 1;
    }

    bool IsFull(queue Cola)
    {
        if (getElements(Cola) == MAX)
        {
            return true;
        }
        return false;
    }

    void Add(queue &Cola, const string elemento)
    {
        if (!IsFull(Cola))
        {

            if (IsEmpty(Cola))
            {
                Cola.inicio++;
            }

            if (Cola.final == MAX - 1)
            {
                Cola.final = 0;
            }
            else
            {
                Cola.final++;
            }

            Cola.vector[Cola.final] = elemento;
            cout << "Add: <" << elemento << ">" << endl;
            // cout << "inicio: " << Cola.inicio << endl;
            // cout << "final: " << Cola.final << "\n"<< endl;
            cantidad++;
            Cola.cantidad++;

        }
        else
        {
            cout << "Esta llena, no pudo entrar <" << elemento << ">" << endl;
        }
    }


    void Borrar(queue &Cola)
    {
        if (!IsEmpty(Cola))
        {

            cout << "Se ha borrado " << Cola.vector[Cola.inicio] << endl;
            Cola.vector[Cola.inicio].clear();

            cantidad--;
            Cola.cantidad--;


            if (getElements(Cola) == 1)
            {
                Crear(Cola);
            }
            else
            {
                Cola.inicio++;
            }
        }
        else
        {
            cout << "Vacia no se puede borrar nada" << endl;
        }
    }

    void crearCola(queue &Cola) {
    }

    void Recorrer(queue Cola) {
        if (!IsEmpty(Cola))
        {
            int x;
            if (Cola.inicio <= Cola.final)
            {
                for (x = 0; x <= Cola.final; x++)
                {
                    if (Cola.vector[x].length() != 0)
                        cout << "Cola.vector[" << x << "]: " << Cola.vector[x] << "\tLongitud: " << Cola.vector[x].length() << endl;
                }
            }
            else
            {
                for (x = Cola.inicio; x < MAX; x++)
                {
                    cout << "Cola.vector[" << x << "]: " << Cola.vector[x] << endl;
                }
                for (x = 0; x <= Cola.final; x--)
                {
                    cout << "Cola.vector[" << x << "]: " << Cola.vector[x] << endl;
                }
            }
        }
        else
        {
            cout << "nada que ver" << endl;
        }
    }

    void limpiarBuffer() {
        fflush(stdin);
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ingresarDato() {
        limpiarBuffer();

        string dato;
        cout << "Ingrese un dato: ";
        getline(cin, dato);
        return dato;
    }

    void varciarColaCircular(queue &Cola) {

        for (int i = 0; i <= cantidad; i++)
        {
            Borrar(Cola);
            Cola.vector[i].clear();
        }
        cout << "cantidad: " << cantidad << endl;
    }

    void menuColaCircular() {
        cout << "\n\t IMPLEMENTACION DE COLAS CIRCULARES EN C++\n\n";
        cout << " 1. AÑADIR ELEMENTO A LA COLA                           " << endl;
        cout << " 2. MOSTRAR ELEMENTOS                         " << endl;
        cout << " 3. BORRAR                          " << endl;
        cout << " 4. MOSTRAR LISTA DE COLAS COPIADAS              " << endl;
        cout << " 5. VACIAR COLA CIRCULAR                      " << endl;
        cout << " 6. COPIAR COLA                         " << endl;
        cout << " 7. MOSTRAR MENU NUEVAMENTE                         " << endl;
        cout << " 8. SALIR                                     " << endl;
    }

    void procesarColaCircular() {
        int x;
        queue Cola;

        menuColaCircular();

        do
        {
            cout << "Seleccione una opcion: ";
            cin >> x;

            switch (x)
            {
            case 1:
                Add(Cola, ingresarDato());
                break;

            case 2:
                Recorrer(Cola);
                break;

            case 3:
                Borrar(Cola);
                break;

            case 4:
                RecorrerCopias();
                break;

            case 5:
                varciarColaCircular(Cola);
                varciarColaCircular(Cola);
                varciarColaCircular(Cola);
                cout << "Funcion borrar" << endl;
                break;

            case 6:
                system("clear");
                menuColaCircular();
                break;
            case 7:
                cout << "Cola copiada con " << cantidad << " elementos " << endl;
                crearCopia(Cola);
                break;
            default:
                cout << "Esta opcion no exite " << endl;
                break;
            }
        } while (x != 8);
    }

};

int main()
{
    ColaCircular c;
    c.procesarColaCircular();
    //asi se usan las funciones, ahora experimenta

    return 1;
}