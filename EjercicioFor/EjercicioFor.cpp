// EjercicioFor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <locale>
#include <string>
#include <windows.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "spanish");
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);

    const int len = 5;
    float calificaciones[len], promedio, suma=0;

    for (int i = 0; i < len; i++) {
        cout << "Ingrese calificación Alumno " << i + 1 << " : ";
        cin >> calificaciones[i];
    }
    
    for (int i : calificaciones) {
        suma += i;
    }
    promedio = suma / len;

    cout << "Nota promedio es :" << promedio;
    return 0;
}