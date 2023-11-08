
#include <iostream>
//libreria para usar cin y cout
using namespace std;

int main()
{
    //constantes para sumar (validación)
    int const numero1 = 5, const numero2 = 9;

    //resultado de suma de constantes de validación
    int resultado = numero1 + numero2;

    //variable de entrada por teclado
    int entrada;

    //bucle do-while para validar si el valor ingresado por teclado es igual que la suma de las constantes
    //en caso de ser iguales, se permite el acceso, de no serlos, se vuelve a solicitar la validación.
    do {
        string texto = "Por favor, ingrese la suma de ";
        cout << texto << numero1 << " + " << numero2 << ": ";
        cin >> entrada;
        //comparamos el valor ingresado con la suma de constantes
        if (entrada == resultado) {

            //mensaje de bienvenida
            cout << "Bienvenido!!!";
        }
        else {

            //mensaje de error en la validación
            cout << "Error, no puedes ingresar, favor intentar de nuevo..." << endl;
        }
    } while (entrada != resultado);
    
    return 0;
}

