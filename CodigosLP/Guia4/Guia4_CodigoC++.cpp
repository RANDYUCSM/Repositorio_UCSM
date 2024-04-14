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

//Ejercicio 3
