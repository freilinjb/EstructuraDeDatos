/*

III) Escribir un programa en el que se generen 100 números aleatorios
 en el rango –25 .. +25 y se guarden en una cola implementada mediante un 
 array circular. Una vez creada la cola, el usuario puede pedir que se 
 forme otra cola con los números negativos que tiene la cola original.

*/

#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <random>

#include <stdlib.h> 

#define MAX 101

using namespace std;

typedef struct
{
    int final;
    int inicio;
    float vector[MAX];
} queue,circuloNegativo;

int cantidad = 0;
int cantidadNegativa = 0;


void CrearNegativo(circuloNegativo &Cola) {
    Cola.final = -1;
    Cola.inicio = -1;
}

void Crear(queue &Cola)
{
    Cola.final = -1;
    Cola.inicio = -1;
}

bool IsEmpty(queue Cola) {
    if (Cola.final == -1)
    {
        return true;
    } 
    return false;
}


bool IsEmptyNegativo(circuloNegativo Cola) {
    if (Cola.final == -1)
    {
        return true;
    } 
    return false;
}

int getElements(queue Cola) {
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

int getElementsNegativo(circuloNegativo Cola) {
    if (IsEmptyNegativo(Cola))
    {
        return 0;
    }

    if (Cola.inicio < Cola.final)
    {
        return Cola.final - Cola.inicio + 1;
    }
    return MAX - Cola.inicio + Cola.final + 1;
}


bool IsFull(queue Cola) {
    if (getElements(Cola) == MAX)
    {
        return true;
    }
    return false;
}

void Add(queue &Cola, float elemento) {
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
        // cout << "Add: <" << elemento << ">" << endl;
        // cout << "inicio: " << Cola.inicio << endl;
        // cout << "final: " << Cola.final << "\n"<< endl;
        cantidad++;
    }
    else
    {
        cout << "Esta llena, no pudo entrar <" << elemento << ">" << endl;
    }
}
bool IsFullNegativo(circuloNegativo Cola)
{
    if (getElementsNegativo(Cola) == MAX)
    {
        return true;
    }
    return false;
}

void AddNegativo(circuloNegativo &Cola, const float elemento) {
    if (!IsFullNegativo(Cola))
    { 

        if (IsEmptyNegativo(Cola))
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
        // cout << "Add: <" << elemento << ">" << endl;
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
void Borrar(queue &Cola) {
    if (!IsEmpty(Cola))
    {

        cout << "Se ha borrado " << Cola.vector[Cola.inicio] << endl; 
        Cola.vector[Cola.inicio] = 0.00;

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

void Recorrer(queue Cola) {
    if (!IsEmpty(Cola))
    {
        int x;
        if (Cola.inicio <= Cola.final)
        {
            for (x = 0; x <= Cola.final; x++)
            {
                cout << "Cola.vector[" << x << "]: " << Cola.vector[x] << endl;
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

void BorrarNegativo(circuloNegativo &Cola) {
    if (!IsEmptyNegativo(Cola))
    {

        cout << "Se ha borrado " << Cola.vector[Cola.inicio] << endl; 
        Cola.vector[Cola.inicio] = 0.00;

        cantidad--;

        if (getElementsNegativo(Cola) == 1)
        {
            CrearNegativo(Cola); 
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


void RecorrerNegativo(circuloNegativo Cola) {
    if (!IsEmptyNegativo(Cola))
    {
        int x;
        if (Cola.inicio <= Cola.final)
        {
            for (x = 0; x <= Cola.final; x++)
            {
                cout << "Cola.vector[" << x << "]: " << Cola.vector[x]  << endl;
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


void PasarDatos(queue &Cola,circuloNegativo &ColaNegativa) {
    if(!IsEmpty(Cola)) {
        int x;
        if (Cola.inicio <= Cola.final)
        {
            for (x = 0; x <= Cola.final; x++)
            {
                // cout << "Cola.vector[" << x << "]: " << Cola.vector[x]  << endl;
                if(Cola.vector[x] <= 0)
                    AddNegativo(ColaNegativa,Cola.vector[x]);
            }
        }
        else
        {
            for (x = Cola.inicio; x < MAX; x++)
            {
                if(Cola.vector[x] <= 0)
                    AddNegativo(ColaNegativa,Cola.vector[x]);

                // cout << "Cola.vector[" << x << "]: " << Cola.vector[x] << endl;
            }
            for (x = 0; x <= Cola.final; x--)
            {
                if(Cola.vector[x] <= 0)
                    AddNegativo(ColaNegativa,Cola.vector[x]);
                // cout << "Cola.vector[" << x << "]: " << Cola.vector[x] << endl;
            }
        }
    }
}

void limpiarBuffer() {
    fflush(stdin);
    cin.clear(); // unset failbit
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void varciarColaCircular(queue &Cola) {

    for (int i = 0; i <= cantidad; i++)
    {
        Borrar(Cola);
        Cola.vector[i] = 0.00;
    }
    cout << "cantidad: " << cantidad << endl;
}

void menuColaCircular() {
    cout << "\n\t IMPLEMENTACION DE COLAS CIRCULARES EN C++\n\n";
    cout << " 1. GENERAR 100 NUMERO ALEATORIOS ENTRE (-25 Y 25)" << endl;
    cout << " 2. MOSTRAR NUMEROS                         " << endl;
    cout << " 3. CREAR NUEVO CIRCULO CON NUMEROS NEGATIVOS   " << endl;
    cout << " 4. MOSTRAR ELEMENTO DEL NUEVO CIRCULO NEGATIVO" << endl;
    cout << " 5. VACIAR COLA CIRCULAR                      " << endl;
    cout << " 6. MOSTRAR EL MENU NUEVAMENTE                " << endl;
    cout << " 7. SALIR                                     " << endl;
}

void IngresarNumerosAleatorios(queue &Cola) {

    float num;
    
    for(int i = 1; i <= 100; i++) {

        num = 25 - rand() % (-25+1);
        num -= 25 - rand() % (-25+1);

        // num = -25 + rand() % (25+1 - 25); 

        if(i%10 == 0)   
            cout << "[" << num <<"]" << endl;

        else {
            cout << "[" << num <<"]";
        }

        Add(Cola, num);


        // if(num <= 0)
        //     cout << "es negativo: " << num << endl; 
    }
        cout << "**[NUMEROS GENERADOS COMPLETO]**" << endl;

}

void procesarColaCircular() {
    int x;
    queue Cola;
    circuloNegativo ColaNegotiva;

    menuColaCircular();

    do
    {
        cout << "Seleccione una opcion: ";
        cin >> x;

        switch (x)
        {
        case 1:
            IngresarNumerosAleatorios(Cola);
            break;

        case 2:
            Recorrer(Cola);
            break;

        case 3:
            PasarDatos(Cola,ColaNegotiva);
            break;

        case 4:
            RecorrerNegativo(ColaNegotiva);
            break;

        case 5:
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
    } while (x != 7);
}

int main()
{

    // procesarColaCircular();
    procesarColaCircular();
    //asi se usan las funciones, ahora experimenta

    //system("pause"); //descomentar si se cierra la pantalla al compilar
    return 1;
}