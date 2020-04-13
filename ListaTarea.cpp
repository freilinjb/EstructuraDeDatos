#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;

class Banco {
private:
    struct Sucursal{
        string sucursal;

        Sucursal(){

        }

        Sucursal(string sucursal){
            this->sucursal = sucursal;
        }
    }vSucursal;
    
    struct Hora{
        int horas;
        int minutos;
    };

    struct Fecha{
        int dia;
        int mes;
        int anio;
        Hora hora;

        void setFecha(){
            time_t t = time(NULL);
            tm* timePtr = localtime(&t);

            stringstream ss_year;
            ss_year << timePtr->tm_year+1900;
            string Year = ss_year.str();

            stringstream ss_month;
            ss_month << timePtr->tm_mon+1;
            string Month = ss_month.str();
            if(atoi(Month.c_str()) < 10)
                Month = "0"+Month;

            stringstream ss_day;
            ss_day << timePtr->tm_mday;
            string Day = ss_day.str();
            if(atoi(Day.c_str()) < 10)
                Day = "0"+Day;

            stringstream ss_hour;
            ss_hour << timePtr->tm_hour;
            string Hour = ss_hour.str();
            if(atoi(Hour.c_str()) < 10)
                Hour = "0"+Hour;

            stringstream ss_min;
            ss_min << timePtr->tm_min;
            string Min = ss_min.str();
            if(atoi(Min.c_str()) < 10)
                Min = "0"+Min;

            stringstream ss_sec;
            ss_sec << timePtr->tm_sec;
            string Sec = ss_sec.str();
            if(atoi(Sec.c_str()) < 10)
                Sec = "0"+Sec;


            anio = stoi(Year);
            mes = stoi(Month);
            dia = stoi(Day);
            hora.horas = stoi(Hour);
            hora.minutos = stoi(Min);


            // cout << "anio: " << anio << endl;
            // cout << "Month: " << mes << endl;
            // cout << "Day: " << dia << endl;
            // cout << "Hour: " << hora.horas << endl;
            // cout << "Min: " << hora.minutos << endl;

            // string Fecha = Year+Month+Day+"_"+Hour+Min+Sec;
        }

        Fecha(const int horas,const int minutos,const int dia, const int mes, const int anio){
            this->hora.horas = horas;
            this->hora.minutos = minutos;
            this->dia = dia;
            this->mes = mes;
            this->anio = anio;
        }

        Fecha(){
            setFecha();
        }

        string getHora() const {
            return  hora.horas+":"+hora.minutos;
        }

        string getFecha() const {
            return dia+"."+anio;
        }
    };

    struct Entidad{
        string nombre;
        string telefono;
        string correo;


        Entidad(const string nombre, const string telefono, const string correo){
            this->nombre = nombre;
            this->telefono = telefono;
            this->correo = correo;
        }

        Entidad(){

        }

        void imprimir() const {
            int width = 25;
            
            cout <<right << nombre << setw(width) << telefono  << setw(width) << right << correo<< setw(width) <<endl;
                    // cout << "("<<nombre << "," << apellido1 << ")\n";
            }
    }vEntidades[50];

    struct Cuenta
    {
        int numCuenta;
        string nombre;
        Entidad entidad;
        float saldo;

        Cuenta(const int numCuenta,const string nombre, const Entidad entidad, const float saldo){
            this->numCuenta = numCuenta;
            this->nombre = nombre;
            this->entidad = entidad;
            this->saldo = saldo;
        }
        Cuenta(){
            
        }

        void setEntidad(const Entidad &p){
            entidad = p;
        }
        void imprimir() const {
            int width = 25;
            cout <<right << numCuenta << setw(width) << nombre  << setw(width) << right << saldo << setw(width) << entidad.nombre <<endl;
            // cout << "("<<nombre << "," << apellido1 << ")\n";
            }
    }vCuentas[50];

    struct Movimiento
    {
        int numMovimiento;
        Cuenta cuenta;
        Fecha fecha;
        float debito;
        float credito;

        Movimiento(const Cuenta cuenta){
            this->cuenta = cuenta;
            this->debito = 0;
            this->credito = 0;
            this->numMovimiento = 5;
        }

        Movimiento(){

        }

        void Deposiatar(const float &debito){
            this->debito = debito;
            this->credito = 0;
        }

        void Retirar(const float &credito){
            this->credito = credito;
            this->debito = 0;
        }

        void imprimir() const {
            int width = 15;
            // cout << left << "Num" << setw(width) << "fecha" << setw(width) << "debito" <<setw(width) << "credito" << endl;
            cout << right << numMovimiento << setw(width) << cuenta.nombre << setw(width) << debito <<setw(width) << credito << setw(width) << fecha.hora.horas<< ":"<<fecha.hora.minutos<< "" << "|" <<setw(width) << fecha.dia <<"/"<<fecha.mes<<"/"<<fecha.anio << endl;
        }
    }vMovimientos[50];

    int indexCuentas = 0;
    int indexMovimientos = 0;
    int indexEntidades = 0;
    int indexSucursal = 0;

    list <Cuenta> listaCuentas;
    Cuenta ctemp;

    list <Sucursal> listaSucursales;
    Sucursal sucursalTemp;

    list <Entidad> listaEntidad;
    Entidad entidadTemp;

    list <Movimiento> listaMovimientos;
    Movimiento movimientoTemp;

public:
    void prueba(){
       Entidad emt[3] = {
           {"BHD LEON","809-693-8955","soluciones@bhd.com"},
           {"PROGRESO","809-611-8555","mts@progreso.com"},  
           {"SANTA CRUZ","809-654-9655","ctr@santacruz.com"}};

        for(int i = 0; i < 3; i++){ 
            listaEntidad.push_back(emt[i]);
        }

        delete emt;
    }



    void llenarSucursal(){

            cin.clear();
            fflush(stdin);

            cout << "Nombrer: ";
            // getline(cin, sucursalTemp.nombre);


            listaSucursales.push_back(sucursalTemp);
    }

    void llenarCuenta(){

        int opcion;
        int cantidad = 0;

            cin.clear();
            fflush(stdin);

            cout << "Nombrer: ";
            getline(cin, ctemp.nombre); 

            cin.clear();
            fflush(stdin);

            cout << "Saldo: ";
            cin >> ctemp.saldo; 

            while (true)
            {
                mostrarEntidades();

                cin.clear();
                fflush(stdin);
                cout << "Seleccione una entidad opcion (-1 para crearla): ";
                cin >> opcion;
                
                for( auto item : listaEntidad ){
                    // std::cout << ite << std::endl
                    if(opcion-1 == cantidad)
                    {
                        ctemp.entidad = item;
                        break;
                    }
                    cantidad++;
                }
                    
                if(opcion == -1){
                    llenarEntidad();
                    break;
                }
                if(opcion > listaEntidad.size())
                {
                    cout << "Esta opcion no existe" << endl;
                    continue;
                }

                if (opcion == 0)
                    break;

                
                cout << "agregado" << endl;
                
            }
            
            listaCuentas.push_back(ctemp);
            cout << "El nombre es: [" << ctemp.nombre  <<"]"<< endl;
    }

    void llenarEntidad(){

        cout << "*****[ REGISTRO DE ENTIDAD ]**********" << endl;

        cin.clear();
        fflush(stdin);

        cout << "Nombre: ";
        getline(cin, entidadTemp.nombre);

        cout << "Telefono: ";
        getline(cin, entidadTemp.telefono);

        cout << "Correo: ";
        getline(cin, entidadTemp.correo);

        cout << entidadTemp.nombre << endl;

        cout << "*****[ FIN DEL REGISTRO ]************" << endl;

            listaEntidad.push_back(entidadTemp);

        mostrarEntidades();

    }


    void mostrarCuentas()
    {
        cout <<"\n"<<endl;

        cin.clear();
        fflush(stdin);

        int cantidad = 0;
        int width = 25;
            // cout << left << "Num" << setw(width) << "fecha" << setw(width) << "debito" <<setw(width) << "credito" << endl;
        cout << right << "MOVIMIENTO" << setw(width) << "CUENTA" << setw(width) << "DEBITO" <<setw(width) << "CREDITO" << setw(width) << "HORA"<< "" << "|" <<setw(width) << "FECHA" << endl;

        list<Cuenta>::const_iterator itr = listaCuentas.begin();
        while(itr != listaCuentas.end()){
                    cin.clear();
        fflush(stdin);
            cout <<"["<< 1+cantidad <<"] ";
            itr->imprimir();
            ++itr;
            cantidad++;
        }
        cout << "Cantidad de registros: " << cantidad << endl;
        system("pause");
    }

    void mostrarEntidades()
    {
        // prueba();

        cout <<"\n"<<endl;

        cin.clear();
        fflush(stdin);

        int cantidad = 0;
        list<Entidad>::const_iterator itr = listaEntidad.begin();
        while(itr != listaEntidad.end()){
                    cin.clear();
        fflush(stdin);
            cout <<"["<< 1+cantidad <<"] ";
            itr->imprimir();
            ++itr;
            cantidad++;
        }
        cout << "Cantidad de regi   stros: " << cantidad << endl;
        system("pause");
    }

    void mostrarMovimientos()
    {
        // prueba();

        cout <<"\n"<<endl;

        cin.clear();
        fflush(stdin);

        int cantidad = 0;
        list<Movimiento>::const_iterator itr = listaMovimientos.begin();
        while(itr != listaMovimientos.end()){
        cin.clear();
        fflush(stdin);
            cout <<"["<< 1+cantidad <<"] ";
            itr->imprimir();
            ++itr;
            cantidad++;
        }
        cout << "Cantidad de regi   stros: " << cantidad << endl;
        system("pause");
    }

    void realizarMovimiento()
    {
        cout << "*****[ MOVIMIENTOS ]**********" << endl;
        int opcion;
        float dinero;
        int cantidad = 0;
        do
        {
            
            cin.clear();
            fflush(stdin);
            
            mostrarCuentas();
            cout << "Seleccione una cuenta: ";
            cin >> opcion;

            cin.clear();
            fflush(stdin);

            for( auto item : listaCuentas ){
            // std::cout << ite << std::endl
                if(opcion-1 == cantidad)
                {
                    ctemp = item;
                    break;
                }
                cantidad++;
            }

            cantidad = 0;

            cout << "Seleccione la operacion:";
            cout << "\n[1]: Retiro\n[2]: Deposito\n[0]: Salir:\nSeleccione: ";
            cin >> opcion;
            
            if(opcion == 1)
            {
                cout << "Dinero a retirar: ";
                cin >> dinero;

                movimientoTemp.cuenta = ctemp;
                movimientoTemp.Deposiatar(dinero);

                opcion = 0;

                listaMovimientos.push_back(movimientoTemp);
            }
            else
            {
                cout << "Dinero a depositar: ";
                cin >> dinero;

                movimientoTemp.cuenta = ctemp;
                movimientoTemp.Retirar(dinero);

                listaMovimientos.push_back(movimientoTemp);
                opcion = 0;
            }
            
        }while(opcion != 0);
    }


    int MenuPrincipal()
    {
         int choice;

            do{
            
            system("cls");
            cout << "MENU PRINCIPAL\n";
            cout << "Please make your selection\n";
            cout << "1 - Registrar una Entidad\n";
            cout << "2 - Registrar una Cuenta\n";
            cout << "3 - Crear una sucursal\n";
            cout << "4 - Mostrar Lista Entidades\n";
            cout << "5 - Mostrar Lista Cuentas\n";
            cout << "6 - Mostrar Movimientos\n";
            cout << "7 - Mostrar historial de Movimientos\n";
            cout << "8 - Realizar Retiros\n";
            cout << "Selection: ";
            
            cin >> choice;

                switch(choice) {
                case 1:
                    system("cls");
                    llenarEntidad();
                    break;
                case 2:
                    system("cls");
                    llenarCuenta();
                    break;
                case 3:
                    system("cls");
                    llenarSucursal();
                    break;
                case 4:
                    system("cls");
                    mostrarEntidades();
                    break;
                case 5:
                    system("cls");
                    mostrarCuentas();
                    break;
                case 6:
                    system("cls");
                    realizarMovimiento();
                    break;
                case 7:
                    system("cls");
                    mostrarMovimientos();
                    break;
                default:
                    cout << "La opcion ["<< choice <<"] no existe\n";
                    system("pause");
                    break;
                }
            } while(choice !=0);                            
            return EXIT_SUCCESS;
    }
};

int	main(int argc, char **argv)
{
    Banco p;
    // p.prueba();
    // p.llenarCuenta();
    p.MenuPrincipal();
    // cout << "Fecha del sistema: " << p.mostrarEntidades() << endl;
    return 0;
}