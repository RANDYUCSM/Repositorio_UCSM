#include <iostream>
#include <string>

using namespace std;

class Vehiculo{
    //Atributos:
    protected:
        string marca;
        string modelo;
        string año;
        float precio;
    
    public:
    //Constructor
        Vehiculo(string m,string mod,string a,float p){
            this->marca = m;
            this->modelo = mod;
            this->año = a;
            this->precio = p;
        }

        //Mostrar informacion:
        virtual void mostrarInf()=0;
};

class Automovil : protected Vehiculo{
    //Atributos:
    private:
        int num_puertas;
        string tipo_comb;
    public:
        //Constructor
        Automovil(string m,string mod,string a,float p,int n_p,string tipo):
        Vehiculo(m,mod,a,p){

            this->num_puertas = n_p;
            this->tipo_comb = tipo;
        
        }
        //Metodo mostrarInf
        void mostrarInf();
};

class Motocicleta : protected Vehiculo{
    //Atributos
    private:
        int cilindrada;
    public:
        Motocicleta(string m,string mod,string a,float p,int c):
        Vehiculo(m,mod,a,p){

            this->cilindrada = c;

        }
        //Metodo mostrarInf
        void mostrarInf();
};

//MostrarInf - automovil:
void Automovil :: mostrarInf(){
    cout<<"------------------------------"<<endl;
    cout<<"Marca: "<<this->marca<<endl;
    cout<<"Modelo: "<<this->modelo<<endl;
    cout<<"Año: "<<this->año<<endl;
    cout<<"Precio: "<<this->precio<<endl;
    cout<<"Numero de puertas: "<<this->num_puertas<<endl;
    cout<<"Tipo de combustible: "<<this->tipo_comb<<endl;
    cout<<"------------------------------"<<endl;
}

//MostrarInf - Motocicleta:
void Motocicleta :: mostrarInf(){
    cout<<"------------------------------"<<endl;
    cout<<"Marca: "<<this->marca<<endl;
    cout<<"Modelo: "<<this->modelo<<endl;
    cout<<"Año: "<<this->año<<endl;
    cout<<"Precio: "<<this->precio<<endl;
    cout<<"Cilindrada: "<<this->cilindrada<<endl;
    cout<<"------------------------------"<<endl;
}

int main() {
    // Objeto - Automovil
    Automovil auto1("Toyota", "Corolla", "2022", 25000.0, 4, "Gasolina");
    // Objeto . Motocicleta
    Motocicleta moto1("Honda", "CBR500R", "2021", 8000.0, 500);

    // Mostrar la información del automóvil
    cout << "Información del automóvil:" << endl;
    auto1.mostrarInf();
    
    // Mostrar la información de la motocicleta
    cout << "Información de la motocicleta:" << endl;
    moto1.mostrarInf();

    return 0;
}