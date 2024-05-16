#include <iostream>
#include <string>
using namespace std;

// Clase base "Cliente"
class Cliente {
protected:
    int DNI;
    string nombre;
    int edad;
    int numCuenta;
    
    // Método protegido para encriptar la información antes de ser almacenada
    void Encriptar() {
        // Encriptar numCuenta sumando 1 a cada dígito
        int temp = numCuenta;
        int encriptado = 0;
        int factor = 1;
        while (temp > 0) {
            int digito = temp % 10;
            digito = (digito + 1) % 10; // Sumamos 1 y nos aseguramos de no superar 9
            encriptado += digito * factor;
            factor *= 10;
            temp /= 10;
        }
        numCuenta = encriptado;
    }

public:
    Cliente(int dni, string nombre, int edad, int numCuenta)
        : DNI(dni), nombre(nombre), edad(edad), numCuenta(numCuenta) {
        Encriptar();
    }

    int getDNI() const {
        return DNI;
    }

    string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    int getNumeroCuenta() const {
        return numCuenta;
    }

    void setDNI(int dni) {
        DNI = dni;
    }

    void setNombre(string nombre) {
        this->nombre = nombre; // usamos el this para distinguir los atributos de la función con los métodos de la clase
    }

    void setEdad(int edad) {
        this->edad = edad;
    }

    void setNumeroCuenta(int numeroCuenta) {
        numCuenta = numeroCuenta;
        Encriptar();
    }

    virtual ~Cliente() { // destructor de la clase cliente (virtual porque la clase base tambien va a tener destructor)
    }
};

// Clase derivada "ClienteSeguro"
class ClienteSeguro : public Cliente {
public:
    ClienteSeguro(int dni, string nombre, int edad, int numCuenta)
        : Cliente(dni, nombre, edad, numCuenta) {}

    ~ClienteSeguro() { // destructor
    }

    void Verificar() const {
    }
};

// Clase base "Persona"
class Persona {
public:
    string nombre;
    int edad;
    string genero;

    Persona(string nombre, int edad, string genero) : nombre(nombre), edad(edad), genero(genero) {
    }

    void MostrarDatos() {
        cout << "Su nombre es: " << nombre << endl;
        cout << "Su edad es: " << edad << endl;
        cout << "Su genero es: " << genero << endl;
    }
};

// Clase derivada "Profesional"
class Profesional : public Persona { // herencia publica
    int codigo;

public:
    Profesional(int codigo, string nombre, int edad, string genero) : Persona(nombre, edad, genero), codigo(codigo) {
    }
};

int main() {
    string nombre;
    int edad;
    string genero;
    int codigo;

    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese edad: ";
    cin >> edad;
    cout << "Ingrese genero: ";
    cin >> genero;
    cout << "Ingrese codigo: ";
    cin >> codigo;

    Profesional arquitecto(codigo, nombre, edad, genero);
    arquitecto.MostrarDatos();

    return 0;
};

//herencia protegida ulti aparte


class Persona { 
protected: 

    string nombre; 
    int edad; 
    string genero; 

     

public: 

    Persona(string nombre, int edad, string genero) : nombre(nombre), edad(edad), genero(genero) { 

    } 

     

    void MostrarDatos() { 

        cout << "Su nombre es: " << nombre << endl; 
        cout << "Su edad es: " << edad << endl; 
        cout << "Su genero es: " << genero << endl; 

    } 
}; 

 

class Profesional : protected Persona {  //herencia protected 

private: 

    int codigo; 

public: 
    Profesional(int codigo, string nombre, int edad, string genero) : Persona(nombre, edad, genero), codigo(codigo) { 
    } 

}; 

 

int main() { 

    string nombre; 
    int edad; 
    string genero; 
    int codigo; 

    cout << "Ingrese nombre: "; 
    cin >> nombre; 
    cout << "Ingrese edad: "; 
    cin >> edad; 
    cout << "Ingrese genero: "; 
    cin >> genero; 
    cout << "Ingrese codigo: "; 
    cin >> codigo; 

     

    Profesional ingeniero(codigo, nombre, edad, genero); 
    return 0; 

};
//herencia privada
class Persona { 
private: 
    string nombre; 
    int edad; 
    string genero; 

     

public: 
    Persona(string nombre, int edad, string genero) : nombre(nombre), edad(edad), genero(genero) { 
    } 

     

    void MostrarDatos() { 
        cout << "Su nombre es: " << nombre << endl; 
        cout << "Su edad es: " << edad << endl; 
        cout << "Su genero es: " << genero << endl; 
    } 

}; 

 

class Profesional : private Persona { //herencia private 
private: 
    int codigo; 

public: 
    Profesional(int codigo, string nombre, int edad, string genero) : Persona(nombre, edad, genero), codigo(codigo) { 
    } 
    void Mostrar() { //este metodo es para que se pueda acceder a el metodo mostrar datos 
        MostrarDatos(); 

    } 

}; 

 

int main() { 

    string nombre; 
    int edad; 
    string genero; 
    int codigo; 
    cout << "Ingrese nombre: "; 
    cin >> nombre; 
    cout << "Ingrese edad: "; 
    cin >> edad; 
    cout << "Ingrese genero: "; 
    cin >> genero; 
    cout << "Ingrese codigo: "; 
    cin >> codigo; 

     

    Profesional arquitecto(codigo, nombre, edad, genero); 

    arquitecto.Mostrar(); 

    return 0; 

} 

 
