//Ejercicio Jes

#include <iostream>
using namespace std;
class Productos{
    private:
    string nombre;
    int codigo;
    int cantidad;
    public:
    Productos(string n,int c,int cant): nombre(n),codigo(c),cantidad(cant){} //Constructor que recibe 3 parametros
    Productos(int c,int cant){  //Constructor que recibe 2 parametros
        this->nombre="Atun";
        this->codigo=c;
        this->cantidad=cant;
    }
    ~Productos(){}  //Destructor explicito
    
    string getNombre(){ //getters
        return nombre;
    }
    int getCodigo(){
        return codigo;
    }
    int getCantidad(){
        return cantidad;
    }
    void setNombre(string n){nombre=n;} //setters
    void setCodigo(int c){codigo=c;}
    void setCantidad(int cant){cantidad=cant;}
};

class Tienda{
    private:
    Productos *producto;    //Referencia al objeto como atributo
    public:
    Tienda(Productos *p){this->producto=p;}; //Constructor explícito
    ~Tienda(){};    //Destructor explicito
    void Mostrar(){     //Metodo para mostrar la informacion
        cout<<"El producto es "<<producto->getNombre()<<" con codigo "<<producto->getCodigo()<<endl<<"stock: "<<producto->getCantidad()<<endl;
    }
    void IngresarProducto(){
        string nombre;
        int codigo;
        int cantidad;
        cout<<"Ingrese el nombre del producto"<<endl;
        cin>>nombre;
        cout<<"Ingrese el codigo del producto"<<endl;
        cin>>codigo;
        cout<<"Ingrese la cantidad que ingresa del producto"<<endl;
        cin>>cantidad;
        producto->setNombre(nombre);     //Llama al metodo setNombre de la clase Productos
        producto->setCodigo(codigo);
        producto->setCantidad(cantidad);
    }
};
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
//Ejerc

