#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>

#include <stdlib.h> 

#define MAX 5

using namespace std;

typedef struct
{
    int final;
    int inicio;
    string vector[MAX];
} queue;

int cantidad = 0;

void Crear(queue &Cola)
{
    Cola.final = -1;
    Cola.inicio = -1;
}

bool IsEmpty(queue Cola)
{
    if (Cola.final == -1)
    {
        return true;
    } 
    return false;
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
    }
    else
    {
        cout << "Esta llena, no pudo entrar <" << elemento << ">" << endl;
    }
}

/*
*/
void Borrar(queue &Cola)
{
    if (!IsEmpty(Cola))
    {

        cout << "Se ha borrado " << Cola.vector[Cola.inicio] << endl; 
        Cola.vector[Cola.inicio].clear();

        cantidad--;

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


void Recorrer(queue Cola)
{
    if (!IsEmpty(Cola))
    {
        int x;
        if (Cola.inicio <= Cola.final)
        {
            for (x = 0; x <= Cola.final; x++)
            {
                if (Cola.vector[x].length() != 0)
                    cout << "Cola.vector[" << x << "]: " << Cola.vector[x] <<"\tLongitud: "<< Cola.vector[x].length() << endl;
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

void limpiarBuffer()
{
    fflush(stdin);
    cin.clear(); // unset failbit
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string ingresarDato()
{
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

void menuColaCircular()
{
    cout << "\n\t IMPLEMENTACION DE COLAS CIRCULARES EN C++\n\n";
    cout << " 1. AÑADIR ELEMENTO                           " << endl;
    cout << " 2. MOSTRAR ELEMENTOS                         " << endl;
    cout << " 3. BORRAR ELEMENTOS                          " << endl;
    cout << " 4. CANTIDAD DE ELEMENTOS                     " << endl;
    cout << " 5. VACIAR COLA CIRCULAR                      " << endl;
    cout << " 6. MOSTRAR EL MENU NUEVAMENTE                " << endl;
    cout << " 7. SALIR                                     " << endl;
}

void procesarColaCircular()
{
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
            cout << "Elementos insertados: [" << cantidad << "]" << endl;
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
        default:
            cout << "Esta opcion no exite " << endl;
            break;
        }
    } while (x != 6);
}

int main()
{

    procesarColaCircular();
    //asi se usan las funciones, ahora experimenta

    //system("pause"); //descomentar si se cierra la pantalla al compilar
    return 1;
}