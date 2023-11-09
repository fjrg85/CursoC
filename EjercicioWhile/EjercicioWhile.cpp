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
    // Generar el n�mero secreto entre 1 y 100
    int numeroSecreto = rand() % 100 + 1;

    while (numeroSecreto != numeroAdivinado) {
        cout << "Adivine n�mero secreto: ";
        cin >> numeroAdivinado;

        if (numeroAdivinado < numeroSecreto) {
            cout << "El n�mero " << numeroAdivinado << " es menor al n�mero secreto " << endl;
            intentos += 1;
        }
        else {
            if (numeroAdivinado > numeroSecreto) {
                cout << "El n�mero " << numeroAdivinado << " es mayor al n�mero secreto \n";
                intentos += 1;
            }
            else {
                cout << "N�mero adivinado, es " << numeroAdivinado << endl;
                cout << "N�mero de intentos " << intentos;
            }
        }
    }
    return 0;
}
