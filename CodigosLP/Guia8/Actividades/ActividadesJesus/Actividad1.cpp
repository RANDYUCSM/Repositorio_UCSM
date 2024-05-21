#Actividad  4
#include <iostream>
using namespace std;

class Vehiculo{
    public:
        virtual void acelerar(){
            cout<<"Acelerando vechiculo..."<<endl;
        }
};
class Coche:public Vehiculo{
    public:
        void acelerar(){
            cout<<"Acelerando coche..."<<endl;
        }
        void encenderLuces(){
            cout<<"Luces del coche encendidas"<<endl;
        }


};
class Motocicleta:public Vehiculo{
    public:
        void acelerar(){
            cout<<"Acelerando motocicleta..."<<endl;
        }
};
int main(){
    Coche coche;
    coche.acelerar();
    coche.encenderLuces();
    Motocicleta moto;
    moto.acelerar();


    return 0;
}
