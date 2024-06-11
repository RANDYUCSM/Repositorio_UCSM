//ACTIVIDAD1
#include <iostream>
using namespace std;
//-------------DYNAMIC BINDING

//Clase base modificada
class Animal{
    public:
        virtual void hacerSonido(){cout<<"Sonido de Animal"<<endl;}
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

    /*Enlace Tardío:
    Se muestra el mensaje del metodo de la 
    clase derivada.*/
    animal->hacerSonido(); //Muestra->"GUAU..."

    return 0;
}