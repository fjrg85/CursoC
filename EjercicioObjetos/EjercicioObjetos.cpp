// EjercicioObjetos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <locale>
#include <string>
#include <windows.h>
using namespace std;

class Alumno {
private:
    string nombre;
    float nota;
public:
    void setNombre(string nm) {
        nombre = nm;
    }
    void setNota(float nt) {
        nota = nt;
    }
    string getNombre() {
        return nombre;
    }
    float getNota() {
        return nota;
    }
};


int main()
{
    setlocale(LC_ALL, "spanish");
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);

    const int len = 5;
    float nota;
    string nombre;

    Alumno* alumno = new Alumno[len];

    for (int i = 0; i < len; i++) {
        cout << "Ingrese nombre Alumno " << i + 1 << " : ";
        cin >> nombre;
        cout << "Ingrese nota Alumno " << i + 1 << " : ";
        cin >> nota;

        alumno[i].setNombre(nombre);
        alumno[i].setNota(nota);
    }

    cout << endl;
    for (int i = 0; i < len; i++) {
        cout << "Nombre Alumno " << i + 1 << " : " << alumno[i].getNombre() << endl;
        cout << "Nota Alumno " << i + 1 << "   : " << alumno[i].getNota() << endl;
    }
    return 0;
}
