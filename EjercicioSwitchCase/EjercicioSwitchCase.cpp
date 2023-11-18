// EjercicioSwitchCase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <locale>
#include <string>
#include <windows.h>
using namespace std;

class Usuario {
private:
    string nombre;
 public:
    void setNombre(string nm) {
        nombre = nm;
    }    
    string getNombre() {
        return nombre;
    }
    void Saludo(string nom) {
        cout << "Bienvenido " << nom <<"!!!" << endl;
    }
    void ErrorIngreso() {
        cout << "Error!!! Primero tienes que identificarte..." << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "spanish");

    Usuario* user = new Usuario;
    string nombre;

    bool salida = false;
    bool intento = false;
    //variable de entrada por teclado
    int opcion;
    string texto = "Opción 1 \nOpción 2 \nOpción 3";

    while (!salida) {
        cout << texto;
        cout << "\nIngrese opción: ";
        cin >> opcion;
        switch (opcion){
            case 1:
                cout << "Ingrese su nombre: \n";
                //std::getline(std::cin,nombre);
                //cin >> nombre;
                cin.ignore();
                getline(cin, nombre);
                user->setNombre(nombre);
                intento = true;
                break;
            case 2:
                if (intento) {
                    user->Saludo(user->getNombre());
                }
                else {
                    user->ErrorIngreso();
                }
                break;
            case 3:
                if (intento) {
                    cout << "Muchas gracias\n";
                    salida = true;
                }
                else {
                    user->ErrorIngreso();
                }                
                break;
            default:
                if (intento) {
                    cout << "Opción incorrecta, vuelva a intentarlo...\n";
                    salida = true;
                }
                else {
                    user->ErrorIngreso();
                }
                break;
        }
            system("pause");
            system("cls");
    }
    return 0;
}