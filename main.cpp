#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    
    cout << "Hola mundo" << endl;
    string nombre;

    getline(cin, nombre);

    cout << "Su nombre es: " << nombre << endl;
    return 0;
}
