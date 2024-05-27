#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Material{
    protected:
        string tipo;
        //Constructor
        Material(string tipo) : tipo(tipo){}
};

class Libro : protected Material{
    protected:
        string autor;
    public:
        string titulo;
        string año_pub;

        //Constructor
        Libro(string tip,string tit,string a,string a_pub):
        Material(tip), autor(a), titulo(tit), año_pub(a_pub){}
        //Metodos
        void mostrar_informacion();
};
//Definicion del metodo
void Libro :: mostrar_informacion(){
    cout << "Tipo de material: " << this->tipo << endl;
    cout << "Título: " << this->titulo << endl;
    cout << "Autor: " << this->autor << endl;
    cout << "Año de publicación: " << this->año_pub << endl;
}

class Biblioteca{
    protected:
        vector<class Libro*> Libros;
    public:
        string ubicacion;
        string nombre;
        //Constructor
        Biblioteca(string ubicacion,string nombre):
        ubicacion(ubicacion),nombre(nombre){}
        //Metodos
        void agregar_libro(Libro* libro);
        void mostrar_libros();
};
//Definicion del metodo
void Biblioteca :: agregar_libro(Libro* libro){
    Libros.push_back(libro);
}
void Biblioteca :: mostrar_libros(){
    cout << "Biblioteca: " << this->nombre << endl;
    for (int i =  0; i < Libros.size(); i++){
        cout << "Libro " << i+1 << ":" << endl;
        Libros[i]->mostrar_informacion();
        cout << endl;
    }
}

class Persona{
    private:
        string nombre;
        string direccion;
        int telefono;
    public:
        //Constructor
        Persona(string n,string d,int t):
        nombre(n),direccion(d),telefono(t){}
        //gets
        string get_nombre(){return this->nombre;}
        string get_direccion(){return this->direccion;}
        int get_telefono(){return this->telefono;}
};

class Prestamo{
    private:
        string fechai;
        string fechaf;
        Persona* persona;
        Libro* libro;
    public:
        //constructor
        Prestamo(string fi,string ff,Persona* pers,Libro* li):
        fechai(fi),fechaf(ff),persona(pers),libro(li){}
        //Metodos
        void mostrar_prestamo();
};
void Prestamo :: mostrar_prestamo(){
    cout << "Prestamo:" << endl;
    cout << "Fecha inicio: " << this->fechai << endl;
    cout << "Fecha fin: " << this->fechaf << endl;
    cout << "Persona: " << this->persona->get_nombre() << endl;
    cout << "Libro: " << this->libro->titulo << endl;
}

int main(){
    
    //Objetos
    Libro libro1("Ciencia", "El universo en una cáscara de nuez", "Stephen Hawking", "2001");
    Libro libro2("Literatura", "Cien años de soledad", "Gabriel García Márquez", "1967");
    Libro libro3("Tecnología", "Clean Code", "Robert C. Martin", "2008");

    Biblioteca biblioteca("Av.Ejemplo 123", "Biblioteca_ejemplo");
    biblioteca.agregar_libro(&libro1);
    biblioteca.agregar_libro(&libro2);
    biblioteca.agregar_libro(&libro3);

    Persona persona1("Juan Pérez", "Calle Ejemplo 123", 123456789);
    Persona persona2("Sofia Diaz", "Calle Ejemplo 456", 987654321);

    Prestamo prestamo1("2024-05-01", "2024-06-01", &persona1, &libro1);
    Prestamo prestamo2("2024-05-15", "2024-06-15", &persona2, &libro2);

    // Mostrar información de la biblioteca
    biblioteca.mostrar_libros();

    // Mostrar información de los préstamos
    prestamo1.mostrar_prestamo();
    cout << endl;
    prestamo2.mostrar_prestamo();

    return 0;
}
