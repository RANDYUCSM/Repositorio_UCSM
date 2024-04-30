#ifndef productos_h
#define productos_h
#include <iostream>
using namespace std;
class Productos{
    private:
    string nombre;
    int codigo;
    int cantidad;
    public:
    Productos(string n,int c,int cant): nombre(n),codigo(c),cantidad(cant){} //Constructor que recibe 3 parametros
    Productos(int c,int cant){  //Constructor que recibe 2 parametros
        this->nombre="Atun";
        this->codigo=c;
        this->cantidad=cant;
    }
    ~Productos(){}  //Destructor explicito
    
    string getNombre(){ //getters
        return nombre;
    }
    int getCodigo(){
        return codigo;
    }
    int getCantidad(){
        return cantidad;
    }
    void setNombre(string n){nombre=n;} //setters
    void setCodigo(int c){codigo=c;}
    void setCantidad(int cant){cantidad=cant;}
};
#endif
