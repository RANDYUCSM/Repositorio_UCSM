//Ejercicios 1
#include <iostream>
using namespace std;
class Vehiculo{
    protected:
        string marca;
        string modelo;
        int anio_fabricacion;
        float precio;
        Vehiculo(string m,string modelo,int anio,float p){ //Constructor de la clase base
            this->marca=m;
            this->modelo=modelo;
            this->anio_fabricacion=anio;
            this->precio=p;
        }
};
class Automovil: protected Vehiculo{
    private:
    int numero_puertas;
    string tipo_combustible;
    public:
    Automovil(string m,string modelo,int anio,float p,int np,string tc):Vehiculo(m,modelo,anio,p),numero_puertas(np),tipo_combustible(tc){} //Constructor de la clase derivada
    void MostrarAtributos(){ //Metodo para mostrar los atributos del automovil
        cout<<"Marca:"<<marca<<endl<<"Modelo:"<<modelo<<endl<<"Anio de fabricacion:"<<anio_fabricacion<<endl<<"Precio:"<<precio<<endl<<"Numero de puertas:"<<numero_puertas<<endl<<"Tipo de combustible:"<<tipo_combustible<<endl;
    }

};
class Motocicleta:protected Vehiculo{
    private:
        int cilindraje;
    public:
    Motocicleta(string m,string modelo,int af,float p,int c):Vehiculo(m,modelo,af,p),cilindraje(c){} //Constructor de la clase derivada
    void MostrarAtributos(){ //Metodo para mostrar los atributos de la motocicleta
        cout<<"Marca:"<<marca<<endl<<"Modelo:"<<modelo<<endl<<"Anio de fabricacion:"<<anio_fabricacion<<endl<<"Precio:"<<precio<<endl<<"Cilindraje:"<<cilindraje<<endl;
    }

};
int main(){
    cout<<"DATOS AUTO"<<endl;
    Automovil autos("Ferrari","LaFerrari",2013,1300000,2,"Shell V-Power");
    autos.MostrarAtributos();
    cout<<"DATOS MOTO"<<endl;
    Motocicleta moto("Italika","RT200",2023,36999,200);
    moto.MostrarAtributos();
}

//Ejercicio 2

