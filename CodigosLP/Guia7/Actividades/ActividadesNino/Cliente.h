#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;

class Cliente{
    //Atributos:
    protected:
        string nombre;
        string apellido;
        string correo;
        string tarjeta;

    public:
        //constructor
        Cliente(string nomb,string apell,string corr,string tarj):
                nombre(nomb),apellido(apell),correo(corr),tarjeta(tarj){}
        //Destructor
        ~Cliente(){}
    protected:
        //Metodos:
        virtual void encrypt()=0;
        virtual void decrypt()=0;

};
#endif