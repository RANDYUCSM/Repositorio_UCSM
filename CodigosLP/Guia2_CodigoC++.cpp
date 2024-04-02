#include <iostream>
using namespace std;

//ACTIVIDADES
//ACTIVIDAD 1.
//libro a
//ACTIVIDAD 2.

//ACTIVIDAD 3.

//ACTIVIDAD 4.

    //1.-

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
    Carro(int r1,int r2,int r3,int r4) : rue1(r1),rue2(r2),rue3(r3),rue4(r4) { //Inicializacion de miembros objetos
        Mover_carro();
        cout<<"Size de ruedas: "<<r1<<", "<<r2<<", "<<r3<<", "<<r4<<endl;
    } 
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


  //4.-

class Tienda{
    public:
    string P1[5]={"arroz","lenteja","pallar","frejol","atun"};
    string C[6];

};
class Cliente{
    string producto;
    string opc;
    public:
    int suma;
    void Agregar_prod_compras(Tienda tienda){
        suma=0;
        opc="s";
        while ((opc!="N" and opc!="n") and suma<6){
            cout<<"Ingrese el producto al carrito"<<endl;
            for(int x=0;x<5;x++)
            {
                cout<<"--"<<tienda.P1[x]<<endl;
            }
            cin>>producto;
            bool encontrar=false;
            for(const auto& item:tienda.P1){
                if(item==producto){
                    tienda.C[suma]=producto;
                    suma+=1;
                    encontrar=true;
                    break;
                }
            }
            if(!encontrar){
                cout<<"El producto no se encuentra disponible "<<endl;

            }

            cout<<"Desea continuar ingresando? S/N"<<endl;
            cin>>opc;
        }
        
    }
    int getSuma(){
        return suma;
    }
    void Pagar_cuenta(int s){
        cout<<"El precio total es: "<<4.6*s<<endl;
        
    }

};
int main(){
    Cliente cli;
    Tienda tienda;
    cli.Agregar_prod_compras(tienda);
    cli.Pagar_cuenta(cli.getSuma());
    cout<<"Se pago la cuenta"<<endl;
}

//Ejercicio 1:
#include <chrono>
#include <thread>
#include<iostream>
using namespace std;

class Auto{
    public:
    int velocidadA=5;
    int velocidadPC;
    int contador=5;
    void setVelocidadPC(int vel){ velocidadPC=vel;}
    int getVelocidadA(){ return velocidadA;}
    int getVelocidadPC(){ return velocidadPC;}
    void aumentarVelocidad(){
        velocidadA+=5;
        contador-=1.5;
        cout<<"Avanzando..."<<endl;
        this_thread::sleep_for(chrono::seconds(contador));
        
    }
};
class Carrera{
    Auto autos;
    int distanciaC,distanciaPC;
    int dificultad;
    string opcionvel;
    public:
    void simularCarrera(){
        distanciaC=0;
        distanciaPC=0;
        if (dificultad==1){
            autos.setVelocidadPC(20);
            while (distanciaC<=100 and distanciaPC<=100){
                    distanciaC+=autos.getVelocidadA();
                    cout<<"Desea aumentar la velocidad? s/n"<<endl;
                    cin>>opcionvel;
                    if (opcionvel=="s" or opcionvel=="S"){
                        autos.aumentarVelocidad();
                    }
                    else{
                        cout<<"Avanzando..."<<endl;
                        this_thread::sleep_for(chrono::seconds(autos.contador));
                    }

                    distanciaPC+=autos.getVelocidadPC();
                    distanciaC+=autos.getVelocidadA();
                    if(distanciaC>=100){
                        cout<<"Ganaste!!"<<endl;
                        break;
                    }
                    else if(distanciaPC>=100){
                        cout<<"Gano la computadora"<<endl;
                        break;
                    }
                    cout<<"Tu carro esta "<<distanciaC<<"/100"<<endl;
                    cout<<"La computadora esta "<<distanciaPC<<"/100"<<endl;
                }
            }
        
        
        else if(dificultad==2){
            autos.setVelocidadPC(30);
            while (distanciaC<=100 and distanciaPC<=100){
                    distanciaC+=autos.getVelocidadA();
                    cout<<"Desea aumentar la velocidad? s/n"<<endl;
                    cin>>opcionvel;
                    if (opcionvel=="s" or opcionvel=="S"){
                        autos.aumentarVelocidad();
                    }
                    else{
                        cout<<"Avanzando..."<<endl;
                        this_thread::sleep_for(chrono::seconds(autos.contador));
                    }

                    distanciaPC+=autos.getVelocidadPC();
                    distanciaC+=autos.getVelocidadA();
                    if(distanciaC>=100){
                        cout<<"Ganaste!!"<<endl;
                        break;
                    }
                    else if(distanciaPC>=100){
                        cout<<"Gano la computadora"<<endl;
                        break;
                    }
                    cout<<"Tu carro esta "<<distanciaC<<"/100"<<endl;
                    cout<<"La computadora esta "<<distanciaPC<<"/100"<<endl;
                }
        }
        else if(dificultad==3){
            autos.setVelocidadPC(40);
            while (distanciaC<=100 and distanciaPC<=100){
                    distanciaC+=autos.getVelocidadA();
                    cout<<"Desea aumentar la velocidad? s/n"<<endl;
                    cin>>opcionvel;
                    if (opcionvel=="s" or opcionvel=="S"){
                        autos.aumentarVelocidad();
                    }
                    else{
                        cout<<"Avanzando..."<<endl;
                        this_thread::sleep_for(chrono::seconds(autos.contador));
                    }

                    distanciaPC+=autos.getVelocidadPC();
                    distanciaC+=autos.getVelocidadA();
                    if(distanciaC>=100){
                        cout<<"Ganaste!!"<<endl;
                        break;
                    }
                    else if(distanciaPC>=100){
                        cout<<"Gano la computadora"<<endl;
                        break;
                    }
                    cout<<"Tu carro esta "<<distanciaC<<"/100"<<endl;
                    cout<<"La computadora esta "<<distanciaPC<<"/100"<<endl;
                }
        }
    }
        
    void cambiarDificultad(){
        int d;
        cout<<"Ingrese el nivel de dificultad "<<endl;
        cout<<"1.Facil "<<endl;
        cout<<"2.Medio "<<endl;
        cout<<"3.Dificil "<<endl;
        cin>>d;
        dificultad=d;
    }
};
int main(){
    Carrera carrera;
    carrera.cambiarDificultad();
    carrera.simularCarrera();
    return 0;
}
//Ejercicio 2
class Inventario{
    string listaProductosDisponible[10]={"cebolla","papa","arroz","azucar"};
    string listaProductosAgotados[5]={"ajo","zanahoria","brocoli","atun","pollo"};
    string listaPedidos[4];
    int numproductosdisponibles=4;
    public:
    void AgregarProductos(){
        int cantidadProductos;
        string nuevo_producto;
        cout<<"Cuantos productos desea agregar?"<<endl;
        cin>>cantidadProductos;

        for(int x=numproductosdisponibles;x<numproductosdisponibles+cantidadProductos;x++){
            cout<<"Ingrese el nombre del producto"<<endl;
            cin>>nuevo_producto;;
            listaProductosDisponible[x]=nuevo_producto;
        }
        numproductosdisponibles+=cantidadProductos;
    }
    void EliminarProductos(string producto){
        for(int x=0;x<numproductosdisponibles;x++){
            if(listaProductosDisponible[x]==producto){
                for(int y=x;y<numproductosdisponibles-1;y++){
                    listaProductosDisponible[y]=listaProductosDisponible[y+1];
                }
                numproductosdisponibles--;
                cout<<"Producto "<<producto<<" eliminado"<<endl;
                return;
            }
        }
        cout<<"Producto no encontrado en la lista"<<endl;
    }
    void ActualizarProductosD(){
        cout<<"Los productos disponibles son: "<<endl;
        for(int x=0;x<numproductosdisponibles;x++){
            cout<<listaProductosDisponible[x]<<" ";
        }
        cout<<endl;
    }
    void ActualizarProductosA(){
        cout<<"Los productos agotados son "<<listaProductosAgotados;
        for(const auto&agotado:listaProductosDisponible){
            cout<<agotado<<" ";
            
        }
        cout<<endl;
    }
    void RealizarPedido(){
        string prod;
        int contador=0;
        cout<<"Ingrese los 4 productos disponibles a pedir"<<endl;
        while(contador<4){
            cin>>prod;
            for(const auto&item:listaProductosDisponible){
                if(item==prod){
                    listaPedidos[contador]=prod;
                    contador+=1;
                }
            }
        }
    }
    void FacturasCliente(){
        int suma=0;
        for (const auto&factura:listaPedidos){
            suma+=1;
        }
        cout<<"El precio total de los pedidos son S/"<<suma*8<<endl; 
    }

};

int main(){
    int opc=1;
    Inventario inventario;
    
    while(opc!=6){
        cout<<"Que operacion desea hacer"<<endl;
        cout<<"1.Agregar productos"<<endl;
        cout<<"2.Mostrar productos"<<endl;
        cout<<"3.Eliminar productos"<<endl;
        cout<<"4.Realizar pedido"<<endl;
        cout<<"5.Generar factura"<<endl;
        cout<<"6.Salir"<<endl;
        cin>>opc;
        if (opc==1){
            inventario.AgregarProductos();
        }
        else if(opc==2){
            inventario.ActualizarProductosD();

        }
        else if(opc==3){
            string eliminar;
            cout<<"Que producto desea eliminar?"<<endl;
            cin>>eliminar;
            inventario.EliminarProductos(eliminar);

        }
        else if(opc==4){
            inventario.RealizarPedido();
        }
        else if(opc==5){
            inventario.FacturasCliente();
        }
    }
    return 0;
}
