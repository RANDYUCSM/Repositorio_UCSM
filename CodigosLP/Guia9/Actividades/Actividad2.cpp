//ACTIVIDAD2
#include <iostream>
using namespace std;

//POLIMORFISMO DE SOBRECARGA
class Calculadora{
    public:
        //Metodos:
        int sumar(int a,int b){return a+b;}
        double sumar(double a,double b){return a+b;}
        int sumar(int a,int b,int c){return a+b+c;}
};

int main(){
    //Objeto:
    Calculadora calculadora;

    //POLIMORFISMO DE SOBRECARGA
    //Muestra: 7
    cout<<"Suma: "<<calculadora.sumar(2,5)<<endl; 
    //Muestra: 7.5
    cout<<"Suma: "<<calculadora.sumar(2.5,5.0)<<endl;
    //Muestra 12
    cout<<"Suma: "<<calculadora.sumar(2,5,5)<<endl;
}