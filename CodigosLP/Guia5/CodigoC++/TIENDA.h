#ifndef tienda_h
#define tienda_h
#include <iostream>
#include "PRODUCTOS.h"
using namespace std;
class Tienda{
    private:
    Productos *producto;    //Referencia al objeto como atributo
    public:
    Tienda(Productos *p){this->producto=p;}; //Constructor explícito
    ~Tienda(){};    //Destructor explicito
    void Mostrar(){     //Metodo para mostrar la informacion
        cout<<"El producto es "<<producto->getNombre()<<" con codigo "<<producto->getCodigo()<<endl<<"stock: "<<producto->getCantidad()<<endl;
    }
    void IngresarProducto(){
        string nombre;
        int codigo;
        int cantidad;
        cout<<"Ingrese el nombre del producto"<<endl;
        cin>>nombre;
        cout<<"Ingrese el codigo del producto"<<endl;
        cin>>codigo;
        cout<<"Ingrese la cantidad que ingresa del producto"<<endl;
        cin>>cantidad;
        producto->setNombre(nombre);     //Llama al metodo setNombre de la clase Productos
        producto->setCodigo(codigo);
        producto->setCantidad(cantidad);
    }
};
#endif
