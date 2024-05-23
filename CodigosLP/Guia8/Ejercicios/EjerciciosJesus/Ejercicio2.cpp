//Ejercicio 2
#include <iostream>
using namespace std;
class Reproductor{
    protected:
        virtual void reproducir()=0;
        virtual void pausar()=0;
        virtual void detener()=0;
};
class ReproductorMP3:public Reproductor{
    public:
    void reproducir(){
        cout<<"Reproduciendo audio..."<<endl;
    }
    void pausar(){
        cout<<"Pausado"<<endl;
    }
    void detener(){
        cout<<"(Detenido)"<<endl;
    }
};
int main(){
    int opc=0;
    ReproductorMP3 reproductor;
    while (opc!=4){
        cout<<"---------------"<<endl;
        cout<<"1.Reproducir\n2.Pausar\n3.Detener\n4.Salir"<<endl;
        cout<<"---------------"<<endl;
        cin>>opc;
        if (opc==1){
            reproductor.reproducir();
        }
        else if(opc==2){
            reproductor.pausar();
        }
        else if(opc==3){
            reproductor.detener();
        }
    }
    return 0;
}
