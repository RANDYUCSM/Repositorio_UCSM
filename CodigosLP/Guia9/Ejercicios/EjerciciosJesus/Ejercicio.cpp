//Ejercicio 1
#include <iostream>
using namespace std;
class Figuras{
    public:
    //Metodos virtuales puros
        virtual double CalcularArea()=0;
        virtual double CalcularPerimetro()=0;
        virtual void mostrarDetalles()=0;
        virtual ~Figuras(){}    //Destructor virtual
};
class Circulo:public Figuras{
    private:
        int radio;
    public:
        Circulo(int r):radio(r){}
        //Implementacion de los metodos virtuales de la clase base
        double CalcularArea(){
            return 3.1416 * (radio*radio);
        }
        double CalcularPerimetro(){
            return (2*3.1416)*radio;
        }
        void mostrarDetalles(){
            cout<<"CIRCULO"<<endl;
            cout<<"El area del circulo es:"<<Circulo::CalcularArea()<<endl;
            cout<<"El perimetro del circulo es:"<<Circulo::CalcularPerimetro()<<endl;
        }
};
class Rectangulo:public Figuras{
    private:
        int base;
        int altura;
    public:
        Rectangulo(int b,int a):base(b),altura(a){}
        double CalcularArea(){
            return base*altura;
        }
        double CalcularPerimetro(){
            return (2*base)+(2*altura);
        }
        void mostrarDetalles(){
            cout<<"RECTANGULO"<<endl;
            cout<<"El area del rectangulo es:"<<Rectangulo::CalcularArea()<<endl;
            cout<<"El perimetro del rectangulo es:"<<Rectangulo::CalcularPerimetro()<<endl;
        }
};
class Triangulo:public Figuras{
    private:
        int base;
        int altura;
        int l2,l3;
    public:
        Triangulo(int b,int a,int l2,int l3):base(b),altura(a),l2(l2),l3(l3){}
        double CalcularArea(){
            return (base*altura)/2;
        }
        double CalcularPerimetro(){
            return base+l2+l3;
        }
        void mostrarDetalles(){
            cout<<"TRIANGULO"<<endl;
            cout<<"El area del triangulo es:"<<Triangulo::CalcularArea()<<endl;
            cout<<"El perimetro del triangulo es:"<<Triangulo::CalcularPerimetro()<<endl;
        }
};
class Cuadrado:public Figuras{
    private:
        int lado;
    public:
        Cuadrado(int l):lado(l){}
        double CalcularArea(){
            return lado*lado;
        }
        double CalcularPerimetro(){
            return 4*lado;
        }
        void mostrarDetalles(){
            cout<<"CUADRADO"<<endl;
            cout<<"El area del cuadrado es:"<<Cuadrado::CalcularArea()<<endl;
            cout<<"El perimetro del cuadrado es:"<<Cuadrado::CalcularPerimetro()<<endl;
        }
};
int main(){
    int opc=0;
    while (opc!=5){
        cout<<"------------------"<<endl;
        cout<<"Elija una figura"<<endl;
        cout<<"1.Circulo\n2.Triangulo\n3.Cuadrado\n4.Rectangulo\n5.Salir"<<endl;
        cout<<"------------------"<<endl;
        cin>>opc;
        if (opc==1){
            int radio;
            cout<<"Ingrese el radio del circulo"<<endl;
            cin>>radio;
            Figuras *figura=new Circulo(radio); //Creacion dinamica de una referencia a un objeto
            figura->mostrarDetalles();
            delete figura;  //Se elimina el objeto
        }
        else if (opc==2){
            int l1,l2,l3,altura;
            cout<<"Ingrese la base triangulo"<<endl;
            cin>>l1;
            cout<<"Ingrese la altura triangulo"<<endl;
            cin>>altura;
            cout<<"Ingrese los lados laterales del triangulo"<<endl;
            cin>>l2>>l3;
            Figuras *figura=new Triangulo(l1,altura,l2,l3);     //Creacion dinamica de una referencia a un objeto
            figura->mostrarDetalles();
            delete figura;  //Se elimina el objeto
        }
        else if(opc==3){
            int lado;
            cout<<"Ingrese un lado del cuadrado"<<endl;
            cin>>lado;
            Figuras *figura=new Cuadrado(lado);     //Creacion dinamica de una referencia a un objeto
            figura->mostrarDetalles();
            delete figura;  //Se elimina el objeto
        }
        else if(opc==4){
            int base,altura;
            cout<<"Ingrese la base y altura del rectangulo"<<endl;
            cin>>base>>altura;
            Figuras *figura= new Rectangulo(base,altura);   //Creacion dinamica de una referencia a un objeto
            figura->mostrarDetalles();
            delete figura;  //Se elimina el objeto
        }
    }
    return 0;
}

//Ejercicio 2

