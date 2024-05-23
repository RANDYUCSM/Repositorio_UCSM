//Ejercicio 1
#include <iostream>
using namespace std;
class Figura{
    protected:
    virtual void dibujar()=0;
    virtual void calcularArea()=0;
};
class Circulo: public Figura{
    private:
        int radio;
    public:
        Circulo(int r):radio(r){} //Constructor por lista de inicializacion
        void calcularArea() override{
            cout<<"El area del circulo es:"<<3.1416*(radio*radio)<<endl;
        }
        void dibujar() override{
            cout<<"Dibujando circulo...(Intentando)"<<endl;
            for (int i=0;i<radio*2;i+=3){
                for (int y=0;y<=i;y++){
                    if (i>radio){
                        cout<<"*";
                    }    
                }
                cout<<""<<endl;
            }

            for (int i=radio*2;i>0;i-=3){
                for (int y=0;y<i;y++){
                    if (i>radio){
                        cout<<"*";
                    }
                }
                cout<<""<<endl;
            }
        }
};

class Rectangulo: public Figura{
    private:
        int base;
        int altura;
    public:
        Rectangulo(int b,int a):base(b),altura(a){}
        void calcularArea(){
            cout<<"El area del rectangulo es:"<<base*altura<<endl;
        }
        void dibujar(){
            for (int i=0;i<altura;i++){
                for (int y=0;y<base;y++){
                    cout<<"*";
                }
                cout<<""<<endl;
            }
        }
};

class Triangulo: public Figura{
    private:
        int base;
        int altura;
    public:
        Triangulo(int b,int a):base(b),altura(a){}
        void calcularArea(){
            cout<<"El area del triangulo es:"<<(base*altura)/2<<endl;
        }
        void dibujar(){
            for (int i=0;i<altura;i++){
                for (int y=0;y<i;y++){
                    cout<<"*";
                }
                cout<<""<<endl;
            }
        }
};
int main(){
    Rectangulo rectangulo(3,6);
    Triangulo triangulo(5,8);
    Circulo circulo(7);
    int opc=0;
    int b,a,r;
    while (opc!=4){
        cout<<"Seleccione la figura a mostrar"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1.Rectangulo\n2.Triangulo\n3.Circulo\n4.Salir"<<endl;
        cout<<"---------------"<<endl;
        cin>>opc;
        if (opc==1){
            cout<<"Ingrese la base y altura"<<endl;
            cin>>b>>a;
            Rectangulo *rectangulo=new Rectangulo(b,a);
            rectangulo->dibujar();
            rectangulo->calcularArea();
        }
        else if(opc==2){
            cout<<"Ingrese la base y altura"<<endl;
            cin>>b>>a;
            Triangulo *triangulo=new Triangulo(b,a);
            triangulo->dibujar();
            triangulo->calcularArea();
        }
        else if(opc==3){
            cout<<"Ingrese el radio"<<endl;
            cin>>r;
            Circulo *circulo=new Circulo(r);
            circulo->dibujar();
            circulo->calcularArea();
        }
    }

    return 0;
}
