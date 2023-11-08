// Variables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.14;
    int numero1 = 15 , numero2 = 14;
    int resultado = numero1 + numero2;
    string texto = "El resultado de la suma es: ";
    cout << texto << resultado;

    int entrada;
    cout << "\nIntroduce un numero: ";
    cin >> entrada;
    int resultadoTotal = entrada + resultado;
    cout << "Tu numero es: " << resultadoTotal << endl;
    if (resultadoTotal < 40) {
        cout << "Introduce un numero mayor";
    }
    else {
        cout << "Genial";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
