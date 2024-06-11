//ACTIVIDAD5
#include <iostream>
using namespace std;
const double pi = 3.1416;

//Clase abstracta pura
class FiguraGeometrica{
    public:
        //Metodos virtuales puros("metodo" = 0)
        virtual double calcularArea() = 0;
        virtual double calcularPerimetro() = 0;
};

//Clase_derivada1
class Circulo : public FiguraGeometrica{
    protected:
        double radio;
    public:
        //Constructor
        Circulo(double r) : radio(r){}
        //Metodos
        double calcularArea(){return pi *(radio * radio);}
        double calcularPerimetro(){return 2 * pi * radio;}
};

//Clase_derivada2
class Rectangulo : public FiguraGeometrica{
    protected:
        double base;
        double altura;
    public:
        //Constructor
        Rectangulo(double b, double a) : base(b), altura(a){}
        //Metodos
        double calcularArea(){return base * altura;}
        double calcularPerimetro(){return 2 * (base + altura);}
};

//Clase_derivada3
class Triangulo : public FiguraGeometrica{
    protected:
        double base;
        double altura;
    public:
    //Constructor
    Triangulo(double b, double a) : base(b), altura(a){}
    //Metodos
    double calcularArea(){return (base * altura) / 2;}
    double calcularPerimetro(){return 3 * base;}  
};

int main(){

    //Arreglo y objetos
    FiguraGeometrica* figuras[3];
    Circulo circulo(4.5);
    Rectangulo rectangulo(5.0, 3.0);
    Triangulo triangulo(3.0, 4.0);
    
    figuras[0] = &circulo;
    figuras[1] = &rectangulo;
    figuras[2] = &triangulo;

    //Recorrido del arreglo:
    for(int i = 0; i < 3; i++){
        cout << "\nFigura " << i+1 << endl;
        cout << "Area: " << figuras[i]->calcularArea() << endl;
        cout << "Perimetro: " << figuras[i]->calcularPerimetro()<<endl;
    }

    return 0;
}