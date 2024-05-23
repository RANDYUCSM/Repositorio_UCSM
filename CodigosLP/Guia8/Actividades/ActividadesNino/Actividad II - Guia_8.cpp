#include <iostream>
using namespace std;

//Se declara a pi como constante
const double pi = 3.1416;

//Creacion de la clase completamente abstracta
class Forma{
    public:
        /*La clase completamente abstracta
        solo tiene metodos virtuales puros*/
        virtual void calcularPerimetro()=0;
        /*Destructor virtual para asegurar destrucción 
        adecuada de objetos derivados*/
        virtual ~Forma(){}
};

//Clase derivada_1
class Circulo : public Forma{
    protected:
        float radio;
    public:
        //Constructor
        Circulo(float r) : radio(r){}
        //Metodo para calcular perimetro - Circulo
        void calcularPerimetro();
};

//Definicion del metodo
void Circulo :: calcularPerimetro(){
    cout << "El perimetro del circulo es: " << 2*pi*radio << endl;
}

//Clase derivada_2
class Rectangulo : public Forma{
    protected:
        float base,altura;
    public:
        //Constructor
        Rectangulo(float b,float a) : base(b),altura(a){}
        //Metodo para calcular perimetro - Rectangulo
        void calcularPerimetro();
};

//Definicion del metodo
void Rectangulo :: calcularPerimetro(){
    cout << "El perimetro del rectangulo es: " << 2*(base+altura) << endl;
}

//Clase derivada_3
class Triangulo : public Forma{
    protected:
        float lado1,lado2,lado3;
    public:
        //Constructor
        Triangulo(float l1,float l2,float l3) : lado1(l1),lado2(l2),lado3(l3){}
        //Metodo para calcular perimetro - triangulo
        void calcularPerimetro();
};

//Definicion del metodo
void Triangulo :: calcularPerimetro(){
    cout << "El perimetro del triangulo es: " << lado1+lado2+lado3 << endl;
}

int main(){

    int opc;

    do{
        //Menu
        cout<<"\n*********************************"<<endl;
        cout<<"Seleccione una forma  geometrica: "<<endl;
        cout<<"1.-Circulo"<<endl;
        cout<<"2.-Rectangulo"<<endl;
        cout<<"3.-Triangulo"<<endl;
        cout<<"4.-Salir"<<endl;
        cout<<"\n*********************************"<<endl;

        cout<<"Opcion: "; cin>>opc;

        // Puntero a la clase base Forma, inicializado a nullptr
        Forma* forma = nullptr;

        /*nullptr: puntero nulo, la funcion de este es 
        indicar que el puntero no apunta a un objeto, lo
        que ayuda a evitar errores en este programa*/

        switch(opc){ //Permite realizar acciones segun la opcion

            case 1:
                float radio;
                cout << "Radio del circulo: "; cin >> radio;
                forma = new Circulo(radio); //se crea un objeto circulo
                break;
                
            case 2:
                float base,altura;
                cout << "Base del rectangulo: "; cin >> base;
                cout << "Altura del rectangulo: "; cin >> altura;
                forma = new Rectangulo(base,altura); //se crea un objeto rectangulo
                break;
            
            case 3:
                float lado1,lado2,lado3;
                cout << "Lado 1 del triangulo: "; cin >> lado1;
                cout << "Lado 2 del triangulo: "; cin >> lado2;
                cout << "Lado 3 del triangulo: "; cin >> lado3;
                forma = new Triangulo(lado1,lado2,lado3); //se crea un objeto triangulo
                break;
            
            case 4:
                cout <<"\nSaliendo...\n"; //Evitar que salga el mensaje "opcion no valida" 
                break;

            default:
                cout << "Opcion no valida";
                break;
        }

        /*Si forma es igual a nullptr es poque 
        no se crearon objetos por lo tanto la opcion
        que se escogio fue incorrecta o la opcion 4*/
        if(forma != nullptr){
            forma->calcularPerimetro();
            delete forma; //Eliminar memoria
        }
        
    }while(opc!=4); //Condicion para mantenerse en el bucle

    return 0;
}
