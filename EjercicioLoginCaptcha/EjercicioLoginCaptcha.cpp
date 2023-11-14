// EjercicioLoginCaptcha.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cstdlib>
#include <locale>
#include <string>
#include <windows.h>
using namespace std;

bool validaCaptcha(int entrada, int resultado) {
    if (entrada == resultado)
        return true;
    else
        return false;
}

int main()
{
    setlocale(LC_ALL, "spanish");

    //constantes para sumar (validación)
    int const numero1 = 5, const numero2 = 9;
    int intento = 0;
    //resultado de suma de constantes de validación
    int resultado = numero1 + numero2;

    //variable de entrada por teclado
    int entrada = -1;

    string texto = "Por favor, ingrese la suma de ";
    
    //bucle do-while para validar si el valor ingresado por teclado es igual que la suma de las constantes
    //en caso de ser iguales, se permite el acceso, de no serlos, se vuelve a solicitar la validación.
    while(entrada != resultado && intento < 3) {
        
        cout << texto << numero1 << " + " << numero2 << ": ";
        cin >> entrada;
        //comparamos el valor ingresado con la suma de constantes
        if (validaCaptcha(entrada, resultado)) {

            //mensaje de bienvenida
            cout << "Bienvenido!!!";
        }
        else {
            intento += 1;
            //mensaje de error en la validación
            cout << "Error, no puedes ingresar, favor intentar de nuevo..." << endl;
        }
    };
    if (intento == 3)
    {
        cout << "Número de intentos maximos ya realizado, intente más tarde..." << endl;
    }

    return 0;
}