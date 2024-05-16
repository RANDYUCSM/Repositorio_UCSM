#include <iostream>
#include <string>

using namespace std;

//Clase Base
class Persona{
    //Atributos:
    public:
        string nombre;
        int edad;
        float salario;
    protected:
        string correo;
    public:
        //Constructor:
        Persona(string n,int e,float s,string c):
            nombre(n),edad(e),salario(s),correo(c){}
        //Mostrar Informacion:
        void mostrarInf();
};

//Clase Derivada_1
class Empleado : public Persona{
    //Constructor
    public:
        Empleado(string n,int e,float s,string c):Persona(n,e,s,c){}
};

//Clase Derivada_2
class Cliente : public Persona{
    //Constructor
    public:
        Cliente(string n,int e,float s,string c):Persona(n,e,s,c){}
};

//Metodo mostrar informacion:
void Persona :: mostrarInf(){
    cout<<"------------------------------"<<endl;
    cout<<"Nombre: "<<this->nombre<<endl;
    cout<<"Edad: "<<this->edad<<endl;
    cout<<"Salario: "<<this->salario<<endl;
    cout<<"Correo: "<<this->correo<<endl;
    cout<<"------------------------------"<<endl;
}

int main(){

    //Objetos
    Empleado empleado1("Luis",24,1200.50,"correo1_ejemplo@gmail.com");
    Cliente cliente1("Maria",36,2200.30,"correo2_ejemplo@gmail.com");

    //Informacion
    empleado1.mostrarInf();
    cliente1.mostrarInf();
    
    return 0;
}