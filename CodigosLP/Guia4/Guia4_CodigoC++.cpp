//Ejercicio 1
#include <iostream>
#include <vector>
using namespace std;
class Autor{    //clase Autor
    string nombre;
    string nacionalidad;
    vector <string> librosEscritos={"Don Quijote de l mancha"};     //vector de los libros escritos por el autor
    public:
    Autor(string nombre,string nacionalidad,vector<string> librosEscritos){
        this->nombre=nombre;
        this->nacionalidad=nacionalidad;
        this->librosEscritos=librosEscritos;
    }
    vector<string> IngresarLibrosEscritos(){  //Metodo para ingresar los libros escritos por el autor
        string titulolibro;
        string opcion;
        while (true){
            cout<<"Ingrese la lista de libros escritos por el autor"<<endl;
            cin>>titulolibro;
            librosEscritos.push_back(titulolibro);
            cout<<"Seguir ingresando? S/N: ";
            cin>>opcion;
            if (opcion=="n" or opcion=="N"){
                break;
            }
        }
        return librosEscritos;
    }
    string getNombre(){return nombre;}
    string getNacionalidad(){return nacionalidad;}
    vector<string> getLibrosEscritos(){return librosEscritos;}
};
class Libros{   //clase libros
    string titulo;
    int ISBN;
    int añoPublicacion;
    int cantidad_ejemplares;
    Autor* autor;
    public:
        Libros(string titulo,int ISBN,int añoPublicacion,int cantidad_ejemplares){
            this->ISBN=ISBN;
            this->titulo=titulo;
            this->añoPublicacion=añoPublicacion;
            this->cantidad_ejemplares=cantidad_ejemplares;
        }
    
    string getTitulo(){return titulo;}  //getters
    int getISBN(){return ISBN;}
    int getañoPublicacion(){return añoPublicacion;}
    int getcantidad_ejemplares(){return cantidad_ejemplares;}


};
class Usuarios{
    string nombre;
    string direccion;
    int numero_telefono;
    vector<string> librosPrestados={"Don Quijote de la Mancha"}; //Vector de los libros prestados al usuario
    public:
    Usuarios(string nombre,string direccion,int numero,vector<string> librosPrestados){
        this->nombre=nombre;
        this->direccion=direccion;
        this->numero_telefono=numero;
        this->librosPrestados=librosPrestados;
    }
    vector<string> IngresarLibrosPedidos(){ //Ingresar libros prestados al usuario
        string opcion;
        string prestado;
        while (true){
            cout<<"Ingrese la lista de libros prestados"<<endl;
            cin>>prestado;
            librosPrestados.push_back(prestado);
            cout<<"Seguir ingresando? S/N: ";
            cin>>opcion;
            if (opcion=="n" or opcion=="N"){
                break;
            }
        }
        return librosPrestados;
    }
    //void DevolverLibro(){

    string getNombre(){return nombre;}      //getters
    string getDireccion(){return direccion;}
    int getNumero_telefono(){return numero_telefono;}
    vector<string> getLibrosPrestados(){return librosPrestados;}
};
class Biblioteca{   //Clase biblioteca
    Autor* autor;   //Punteros
    Libros* libros;
    Usuarios* usuario;
    public:
    Biblioteca(Autor* autor,Libros* libros,Usuarios* usuario){ //Metodo constructor
        this->autor=autor;
        this->libros=libros;
        this->usuario=usuario;
    }
    //void PrestarLibro(){
        
    
    void MostrarDatosAutor(){   //Mostrar datos del autor
        cout<<"Informacion del autor "<<endl;
        cout<<"Nombre: "<<autor->getNombre()<<endl;
        cout<<"Nacionalidad: "<<autor->getNacionalidad()<<endl;
        cout<<"Libros escritos: ";
        for (const auto& item:autor->getLibrosEscritos()){
            cout<<item<<",";
        }
    }
    void MostrarDatosUsuarios(){    //Mostrar datos del usuario
        cout<<"Informacion del usuario "<<endl;
        cout<<"Nombre: "<<usuario->getNombre()<<endl;
        cout<<"Direccion: "<<autor->getNacionalidad()<<endl;
        cout<<"Numero de telefono: "<<endl;
        cout<<"Libros prestados: ";
        for (const auto& item:usuario->getLibrosPrestados()){
            cout<<item<<",";
        }
    }
    void MostrardatosLibro(){       //Mostrar datos del libro
        cout<<"Informacion del libro "<<endl;
        cout<<"Titulo: "<<libros->getTitulo()<<endl;
        cout<<"ISBN: "<<libros->getISBN()<<endl;
        cout<<"Año de publicacion: "<<libros->getañoPublicacion()<<endl;
        cout<<"Cantidad de elemplares: "<<libros->getcantidad_ejemplares()<<endl;
    }

};
int main(){
    string opcion;
    Autor nombre;
    vector<string>librosEscritos=nombre.IngresarLibrosEscritos();
    Autor nombre1("Jesus","Peru",librosEscritos);
    Libros libro1("tituloo",12342131,2024,13);
    Usuarios usuario;
    vector<string>librosPedidos=usuario.IngresarLibrosPedidos();
    Usuarios usuario1("Jesus","Jorge chavez",923214131,librosPedidos);
    Biblioteca biblioteca(&nombre1,&libro1,&usuario1);
    biblioteca.MostrarDatosAutor();
    biblioteca.MostrardatosLibro();
    biblioteca.MostrarDatosUsuarios();
    return 0;
}

//Ejercicio 2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Proveedor{
    //Atributos:
    private:
        string nombre;
    
    public:
        //Constructor:
        Proveedor(string nombre){this->nombre = nombre;}
        //Get:
        string get_nombre(){return this->nombre;}
};


class Cliente{
    //Atributos
    private:
        string nombre;
        string direccion;
        int telefono;
        vector<class Compra*> Compras_realizadas;
        vector<class Pago*> Pagos_realizados;
        
    public:
        //Constructor:
        Cliente(string nombre,string direccion,int telefono){
            
            this->nombre = nombre;
            this->direccion = direccion;
            this->telefono = telefono;
            
        }
        //Gets:
        string get_nombre(){return this->nombre;}
        string get_direccion(){return this->direccion;}
        int get_telefono(){return this->telefono;}
        
        //Funciones:
        void agregarCompra(Compra* compra){
            Compras_realizadas.push_back(compra);
        }
        void agregarPago(Pago* pago){
            Pagos_realizados.push_back(pago);
        }
        
        void mostrar_inf_cliente();
};  

class Producto{
    //Atributos:
    private:
        int codigo;
        string desc;
        double precio;
        Proveedor* prov_aso;
    
    public:
        //Contructor:
        Producto(int codigo,string desc,double precio,Proveedor* prov_aso){
            
            this->codigo = codigo;
            this->desc = desc;
            this->precio = precio;
            this->prov_aso = prov_aso;
        }
        //gets:
        int get_codigo(){return this->codigo;}
        string get_descripcion(){return this->desc;}
        double get_precio(){return this->precio;}
        Proveedor* get_Proveedor(){return this->prov_aso;}

};

class Venta{
    //Atributos
    private:
        string num_fact;
        string fecha;
        Cliente* cliente_asoc;
        vector<Producto*> Productos_vend;
    
    public:
        //Contructor:
        Venta(string num_fact,string fecha,Cliente* cliente){
            this->num_fact = num_fact;
            this->fecha = fecha;
            this->cliente_asoc = cliente;
        }
        //gets:
        string get_num_fact(){return this->num_fact;}
        string get_fecha(){return this->fecha;}
        Cliente* get_cliente(){return this->cliente_asoc;}
        
        //Funciones:
        void agregarProducto(Producto* producto){
            Productos_vend.push_back(producto);
        }
        
        void mostrar_inf_venta();
};

class Compra{
    //Atributos:
    private:
        Cliente* cliente_asoc;
        Producto* prod_asoc;
        Venta* venta_asoc;
        int cant_comprada;
        
    public:
        //Contructor:
        Compra(Cliente* cliente,Producto* producto,Venta* venta,int cantidad){
            
            this->cliente_asoc = cliente;
            this->prod_asoc = producto;
            this->venta_asoc = venta;
            this->cant_comprada = cantidad;
        }
        //gets:
        Cliente* get_cliente(){return this->cliente_asoc;}
        Producto* get_prod_asoc(){return this->prod_asoc;}
        Venta* get_venta_asoc(){return this->venta_asoc;}
        int get_cantidad(){return this->cant_comprada;}
};

class Pago{
    //Atributos:
    private:
        Cliente* cliente_aso;
        double monto;
        string fecha_pago;
    
    public:
        //Contructor:
        Pago(Cliente* cliente,double monto,string fecha_pago){
            
            this->cliente_aso = cliente;
            this->monto = monto;
            this->fecha_pago = fecha_pago;
            
        }
        //gets:
        Cliente* get_cliente(){return this->cliente_aso;}
        double get_monto(){return this->monto;}
        string get_fecha_pago(){return this->fecha_pago;}
};


//Implementacion de funciones:
void Cliente::mostrar_inf_cliente(){
    cout<<"Nombre: "<<this->nombre<<endl;
    cout<<"Compras Realizadas: "<<endl;
    //-------
    int long_comp = Compras_realizadas.size();
    for(int i=0;i<long_comp;i++){
        cout<<"----Productos: "<<Compras_realizadas[i]->get_prod_asoc()->get_descripcion()<<endl;
        cout<<"----Cantidad: "<<Compras_realizadas[i]->get_cantidad()<<endl;
        cout<<"----Precio unitario: "<<Compras_realizadas[i]->get_prod_asoc()->get_precio()<<endl;
        cout<<"----Fecha: "<<Compras_realizadas[i]->get_venta_asoc()->get_fecha()<<endl;
    }
    cout<<"Pagos: "<<endl;
    //-------
    int long_pag = Pagos_realizados.size();
    for(int i=0;i<long_pag;i++){
        cout<<Pagos_realizados[i]->get_monto()<<endl;
    }
}

void Venta::mostrar_inf_venta(){
    cout<<"---------------------------------------------------------";
    cout<<"\nNumero de factura: "<<this->num_fact<<endl;
    cout<<"Fecha: "<<this->fecha<<endl;
    cout<<"Cliente: "<<this->cliente_asoc->get_nombre()<<endl;
    cout<<"Descripcion: "<<endl;
    //-------
    int long_desc = Productos_vend.size();
    for(int i=0;i<long_desc;i++){
        cout<<Productos_vend[i]->get_descripcion()<<endl;
    }
    cout<<"---------------------------------------------------------"<<endl;
}

int main(){
    
    //Objetos:
    //-----------Proveedor:
    Proveedor prov1("Nombre_prov1");
    //-----------Producto:
    Producto prod1(1234,"Pantalon",100,&prov1);
    //-----------Cliente:
    Cliente cli1("Mario","Direc_prueba",123456789);
    //----------Venta:
    Venta venta1("A123","Fecha_prueba",&cli1);
    //----------Compra:
    Compra Comp1(&cli1,&prod1,&venta1,2);
    //----------Pago:
    Pago pago1(&cli1,200,"Fecha_prueba");
    
    
    //agregarCompra:
    cli1.agregarCompra(&Comp1);
    cli1.agregarPago(&pago1);
    venta1.agregarProducto(&prod1);
    
    //Mostrar informacion
    //---------------------Cliente
    cli1.mostrar_inf_cliente();
    venta1.mostrar_inf_venta();
    
    return 0;
}
//Ejercicio 3
