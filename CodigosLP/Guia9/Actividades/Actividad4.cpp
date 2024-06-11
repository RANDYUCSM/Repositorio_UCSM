//ACTIVIDAD4
#include <iostream>
using namespace std;

//Clase Base
class Animal{
    public:
        virtual void hacerSonido(){cout<<"Sonido de Animal"<<endl;}
};

//Clase_derivada1
class Perro : public Animal{
    public:
        void hacerSonido(){cout<<"GUAU..."<<endl;}
};
//Clase_derivada2
class Gato : public Animal{
    public:
        void hacerSonido(){cout<<"MIAU..."<<endl;}
};
//Clase_derivada3
class Vaca : public Animal{
    public:
        virtual void hacerSonido(){cout<<"MUUU..."<<endl;}
};

int main(){

    //Arreglo y objetos
    Animal* animal[3];

    Perro perro;
    Gato gato;
    Vaca vaca;

    animal[0] = &perro;
    animal[1] = &gato;
    animal[2] = &vaca;

    //Recorrido del arreglo:
    for(int i = 0; i < 3; i++){animal[i]->hacerSonido();}
    return 0;
}