//EJERCICIO 1

#ifndef TIENDA_H
#define TIENDA_H

#include "Producto.h"  // Incluir la definición de la clase Producto

class Tienda {
    Producto* productos;
    int numProductos;

public:
    // Constructor
    Tienda();

    // Destructor
    ~Tienda();

    // Método para agregar un producto a la tienda
    void agregarProducto(std::string nombre, double precio, int cantidad);
};

#endif
//EJERCICIO 2
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>

using namespace std;

class Producto {
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor
    Producto(string nombre, double precio, int cantidad) : nombre(nombre), precio(precio), cantidad(cantidad) {}

    // Método para mostrar los detalles del producto
    void mostrarDetalles() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
};

#endif

//EJERCICIO 4
#include "Tienda.h"
#include "Producto.h"
#include <iostream>

using namespace std;

int main() {
    Tienda tienda;
    int opcion;

    do {
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                string nombre;
                double precio;
                int cantidad;

                cout << "Ingrese el nombre del producto: ";
                cin >> nombre;
                cout << "Ingrese el precio del producto: ";
                cin >> precio;
                cout << "Ingrese la cantidad del producto: ";
                cin >> cantidad;

                tienda.agregarProducto(nombre, precio, cantidad);
                break;
            }
            case 2:
                tienda.mostrarProductos();
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 3);

    return 0;
}



