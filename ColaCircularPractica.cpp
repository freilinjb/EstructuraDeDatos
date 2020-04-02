#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>

#define MAX 5

using namespace std;

typedef struct {
    int final;
    int inicio;
    string vector[MAX];
}cola;

int cantidad = 0;

void crear(cola &cl) {
    cl.final = -1;
    cl.inicio = -1;
}

bool IsEmpty(cola cl) {
    return (cl.final == -1);
}

int getElement(cola cl) {
    if(IsEmpty(cl)) {
        return 0;
    }

    if(cl.inicio < cl.final) {
        return cl.final - cl.inicio + 1;
    }

    return MAX - cl.inicio + cl.final +1;
}

bool IsFull(cola cl) {
    return (getElement(cl) == MAX);
}

void Add(cola &cl, const string data) {
    if(!IsFull(cl)) {
        
    }
}

int main(int argc, char const *argv[])
{
    cout << "hola mundo" << endl;

    return 0;
}
