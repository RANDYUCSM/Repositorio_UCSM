//ACTIVIDAD3
#include <iostream>
using namespace std;
const double pi = 3.1416;

//POLIMORFISMO DE SUBTIPO
class Figura{
    public:
        //Metodo:
        virtual void calcularArea()=0;
};

//Clase_derivada1
class Circulo : public Figura{
    protected:
        double radio;
    public:
        //Constructor
        Circulo(double radio) : radio(radio){}
        //Metodo
        void calcularArea(){
            cout << "Area del circulo: " <<pi*(radio*radio)<<endl;
        }
};

//Clase_derivada2
class Rectangulo : public Figura{
    protected:
        double base;
        double altura;
    public:
        //Constructor
        Rectangulo(double base, double altura) : 
        base(base), altura(altura){}
        //Metodo
        void calcularArea(){
            cout << "Area del rectangulo: " <<base*altura<<endl;
        }
};

//Clase_derivada3
class Triangulo : public Figura{
    protected:
        double base;
        double altura;
    public:
        //Constructor
        Triangulo(double base, double altura) :
        base(base), altura(altura){}
        //Metodo
        void calcularArea(){
            cout << "Area del triangulo: " <<(base*altura)/2<<endl;
        }
};

int main(){

    //Objetos y arreglo
    Figura* figuras[3];
    Circulo circulo(3.5);
    Rectangulo rectangulo(4.5, 6.7);
    Triangulo triangulo(7.8, 9.1);

    //Arreglo:
    figuras[0] = &circulo;
    figuras[1] = &rectangulo;
    figuras[2] = &triangulo;

    //Recorrido del arreglo:
    for(int i = 0; i < 3; i++){figuras[i]->calcularArea();}

    /*
    Muestra:
    Area del circulo: 38.4846
    Area del rectangulo: 30.15
    Area del triangulo: 35.49
    */
}