// EjercicioWhile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <locale>
using namespace std;


int main()
{
    setlocale(LC_ALL, "spanish");
    srand(static_cast<unsigned int>(time(nullptr)));
    int numeroAdivinado = 101;
    int intentos = 0;
    // Generar el número secreto entre 1 y 100
    int numeroSecreto = rand() % 100 + 1;

    while (numeroSecreto != numeroAdivinado) {
        cout << "Adivine número secreto: ";
        cin >> numeroAdivinado;

        if (numeroAdivinado < numeroSecreto) {
            cout << "El número " << numeroAdivinado << " es menor al número secreto " << endl;
            intentos += 1;
        }
        else {
            if (numeroAdivinado > numeroSecreto) {
                cout << "El número " << numeroAdivinado << " es mayor al número secreto \n";
                intentos += 1;
            }
            else {
                cout << "Número adivinado, es " << numeroAdivinado << endl;
                cout << "Número de intentos " << intentos;
            }
        }
    }
    return 0;
}
