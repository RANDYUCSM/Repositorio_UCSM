#include <iostream>
#include "TIENDA.h"
#include "PRODUCTOS.h"
using namespace std;

int main(){
    int opcion;
    Productos *registro=new Productos("Atun",123,60);   //Creacion del objeto
    Productos registro1(123,60);    //Creacion del objeto
    Tienda tienda(registro);
    Tienda tienda1(&registro1);
    while (true){
        cout<<"**********************"<<endl;
        cout<<"Ingrese una opcion: "<<endl<<"1.Ingresar productos"<<endl<<"2.Mostrar"<<endl<<"3.Salir"<<endl;
        cout<<"**********************"<<endl;
        cin>>opcion;
        if (opcion==1){
            tienda.IngresarProducto();
        }
        else if(opcion==2){
            tienda.Mostrar();
        }
        else if(opcion==3){
            break;
        }
        else{
            cout<<"Opcion invalida"<<endl;
        }

    }
    delete registro;    //Destructor explicito
    delete &registro1;    //Destructor explicito
    return 0;
}

