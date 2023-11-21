// EjercicioTiendaOnlineLibros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <locale>
#include <string>
#include <windows.h>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    float precio;
public:
    void setTitulo(string t) {
        titulo = t;
    }
    string getTitulo() {
        return titulo;
    }
    void setAutor(string a) {
        autor = a;
    }
    string getAutor() {
        return autor;
    }
    void setPrecio(float p) {
        precio = p;
    }
    float getPrecio() {
        return precio;
    }
};


int main()
{
    setlocale(LC_ALL, "spanish");

    Libro carrito[5];
    Libro catalogo[3];
    Libro* libro = new Libro;
    string numlibro;

    //libros
    catalogo[0].setTitulo("La Catedral del Mar");
    catalogo[0].setAutor("Ildefonso Falcones");
    catalogo[0].setPrecio(19.80);
    catalogo[1].setTitulo("La sombra del viento");
    catalogo[1].setAutor("Carlos Ruiz Zafón");
    catalogo[1].setPrecio(15.20);
    catalogo[2].setTitulo("Los Pilares de La Tierra");
    catalogo[2].setAutor("Ken Follet");
    catalogo[2].setPrecio(21.20);

    int j;
    int idcarrito = 0;
    float precioTotal=0;
    bool salida = false;
    int opcion;
    string texto = "1. Comprar Libro \n2. Ver Carrito \n3. Pago";
    /*for (Libro l : catalogo) {
        cout << l.getTitulo() << endl;
    }*/
    
    while (!salida) {
        cout << texto;
        cout << "\nIngrese opción: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "Seleccione un libro:\n";
            j = 0;
            //recorrer catalogo
            for (Libro l : catalogo) {
                j += 1;
                cout << j << "-" << l.getTitulo() << endl;
                cout << "  " << l.getAutor() << endl;
                cout << "  " << l.getPrecio() << endl;
            }
            cin.ignore();
            getline(cin, numlibro);
            //agregar libro a carrito
            carrito[idcarrito]= catalogo[stoi(numlibro)];
            idcarrito += 1;
            break;
        case 2:
            //recorrer carrito de compras
            for (int i = 0; i < idcarrito; i++) {
                cout << i + 1 << "-" << carrito[i].getTitulo() << endl;
                cout << "  " << carrito[i].getAutor() << endl;
                cout << "  " << carrito[i].getPrecio() << endl;
            }
            break;
        case 3:
            for (int i = 0; i < idcarrito; i++) {
                precioTotal += carrito[i].getPrecio();
            }
            //impresion de monto a pagar, subtotal, iva y total
            cout << "Precio a pagar: " << (precioTotal * 0.90)<< endl;
            cout << "IVA a pagar: " << (precioTotal * 0.10) << endl;
            cout << "Total a pagar: " << precioTotal << endl;
            salida = true;
            break;
        default:
            cout << "Opción incorrecta, vuelva a intentarlo...\n";
            salida = false;
          
            break;
        }
        system("pause");
        system("cls");
    }
    
    return 0;
}