#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <limits>


using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
}*primaro, *ultimo;