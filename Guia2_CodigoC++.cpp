#include <iostream>
using namespace std;

//ACTIVIDADES
//ACTIVIDAD 1.


//ACTIVIDAD 2.

//ACTIVIDAD 3.

//ACTIVIDAD 4.

    //1.-
/*
class Libro{
    string autor;
    string titulo;
    bool prestam;
    public:
    Libro(string a, string t){ //Public para recibir valores
        this->autor=a;
        this->titulo=t;
    }
        string getAutor(){
            return autor;
        }
        string getTitulo(){
            return titulo;
        }
        void setPrestam(bool p){
            prestam=p;
        }
        void del_prestam(){
            cout<<"Se devolvio el libro"<<endl;
            prestam=false;
        }
    
};
class Biblioteca{
    public:
    bool Presta_libro( Libro libro){
        cout<<"Se presto el libro "<<libro.getTitulo()<<" de "<<libro.getAutor()<<endl;
        libro.setPrestam(true);
        return true;
    }
};

int main(){
    Libro libro1("Miguel De Cervantes","Don Quijote de la Mancha");
    Biblioteca bl;
    bl.Presta_libro(libro1); //Envia un objeto
    libro1.del_prestam();

    return 0;
}

   //2.- 

class Producto{
    float precio;
    int cantidad;
    string nombre_prod;
    public:
    Producto(string n ,float p,int c){
        this->precio=p;
        this->cantidad=c;
        this->nombre_prod=n;
    }
    float getPrecio(){ return precio;}
    int getCantidad(){ return cantidad;}
    string getNombre_prod(){ return nombre_prod;}
    void precio_prod(float p){
        precio=p;
    }
    void cant_prod(int c){
        cantidad=c;
    }
};
class Factura{
    public:
    string P[1];
    void Agregar_pro(Producto prod){ //Recibe como parametro un objeto
        P[0]=prod.getNombre_prod();
    }
};

int main(){
    string n;
    float p;
    int c;
    cout<<"Ingrese el nombre del producto "<<endl;
    cin>>n;
    cout<<"Ingrese el precio del producto "<<endl;
    cin>>p;
    cout<<"Ingrese la cantidad del producto "<<endl;
    cin>>c;
    Producto prod(n,p,c);
    Factura fact;
    fact.Agregar_pro(prod);
    cout<<"La lista de productos es: ";
    for (int x=0;x<=0;x++){
        cout<<fact.P[0];
    }
    return 0;
}
*/
  //3.-

class Rueda{
    int size;
    public:
    Rueda(int s){
        this->size=s;
    }
    int getSize(){ return size;}
};
class Carro{
    Rueda rue1;  //Objetos como atributos
    Rueda rue2;
    Rueda rue3;
    Rueda rue4;
    public:
    Carro(int r1,int r2,int r3,int r4) : rue1(r1),rue2(r2),rue3(r3),rue4(r4) {
        Mover_carro();
        cout<<"Size de ruedas: "<<r1<<", "<<r2<<", "<<r3<<", "<<r4<<endl;
    } //Inicializacion de miembros objetos
    void Mover_carro(){
        cout<<"El carro se esta moviendo..."<<endl;
    }
    void Cambiar_ruedas(int ru1,int ru2,int ru3,int ru4){
        rue1=Rueda(ru1); //El valor enviado se queda en el objeto, es una INSTANCIA de clase
        rue2=Rueda(ru2);
        rue3=Rueda(ru3);
        rue4=Rueda(ru4);
        cout<<"Se cambiaron las ruedas "<<endl;
        cout<<"Size de ruedas: "<<rue1.getSize()<<", "<<rue2.getSize()<<", "<<rue3.getSize()<<", "<<rue4.getSize()<<endl;

    }
};
int main(){
    Carro car(15,15,15,15);
    car.Cambiar_ruedas(18,18,18,18);
    return 0;
}
