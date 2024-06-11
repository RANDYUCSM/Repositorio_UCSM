//ACTIVIDAD1
#include <iostream>
using namespace std;
//-------------STATIC BINDING

//Clase base:
class Animal{
    public:
        void hacerSonido(){cout<<"Sonido de Animal"<<endl;}
};

//Clase derivada:
class Perro : public Animal{
    public:
        void hacerSonido(){cout << "GUAU..."<<endl;}
};

int main(){
    //Objeto
    Perro perro;
    Animal* animal = &perro;

    /*Enlace Temprano:
    Se muestra el mensaje del metodo de la 
    clase base.*/
    animal->hacerSonido(); //Muestra->"Sonido de Animal"

    return 0;
}