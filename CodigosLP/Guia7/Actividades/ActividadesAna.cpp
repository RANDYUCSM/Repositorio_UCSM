#include <iostream> 
#include <string> 
using namespace std; 

class Cliente { 
protected: 
    int DNI; 
    string nombre; 
    int edad; 
    int numCuenta; 

    // Método para encriptar cada dígito del número de cuenta
    int Encriptar(int num) const { 
        string numastring = to_string(num); // Convertir número a cadena
        for (char& digito : numastring) { // Iterar sobre cada carácter de la cadena
            int valorDigito = digito - '0'; // Convertir carácter a dígito
            valorDigito = (valorDigito + 7) % 10; // Sumar 7 y tomar módulo 10
            digito = '0' + valorDigito; // Convertir dígito de vuelta a carácter
        }
        return stoi(numastring); // Convertir cadena de nuevo a número entero
    } 
    
public: 
    Cliente(int dni, string nombre, int edad, int numCuenta) : DNI(dni), nombre(nombre), edad(edad), numCuenta(numCuenta) { 
        this->numCuenta = Encriptar(this->numCuenta); // Encriptar número de cuenta
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
        this->nombre = nombre;  
    } 

    void setEdad(int edad) { 
        this->edad = edad; 
    } 

    void setNumeroCuenta(int numeroCuenta) { 
        numCuenta = Encriptar(numeroCuenta); // Encriptar número de cuenta al establecerlo
    } 

    virtual ~Cliente() { 
    } 
}; 

class ClienteSeguro : public Cliente { 
public: 
    ClienteSeguro(int dni, string nombre, int edad, int numCuenta) : Cliente(dni, nombre, edad, numCuenta) { 
    } 

    ~ClienteSeguro() {    
    } 

    void Verificar() const { 
        // Realizar verificación, si es necesario
    } 
}; 

int main() { 
    ClienteSeguro cliente(73378666, "Ana", 18, 12345); 
    cout << "DNI: " << cliente.getDNI() << endl; 
    cout << "Nombre: " << cliente.getNombre() << endl; 
    cout << "Edad: " << cliente.getEdad() << endl; 
    cout << "Numero de cuenta encriptado: " << cliente.getNumeroCuenta() << endl; 

    cliente.Verificar(); 

    return 0; 
}
//las otras acitvidades
#include <iostream> 
#include <string> 
using namespace std; 

 
class Cliente{ 
protected: 
    int DNI; 
    string nombre; 
    int edad; 
    int numCuenta; 
    // Método protegido para encriptar la información antes de ser almacenada 
    void Encriptar() const { 
        // Aquí iría la lógica de encriptación 

    } 
public: 
    Cliente(int dni, string nombre, int edad, int numCuenta): DNI(dni), nombre(nombre), edad(edad), numCuenta(numCuenta){ 
        Encriptar(); 
    } 
    int getDNI()const{   //devuelve valor de un atributo privado 
        return DNI; 
    } 

    string getNombre()const{ 
        return nombre; 
    } 

    int getEdad()const{ 
        return edad; 
    } 

    int getNumeroCuenta()const{ 
        return numCuenta; 
    } 
     

    void setDNI(int dni){ //establece valor de un atributo   
        DNI = dni; 
    } 

    void setNombre(string nombre){ 
        this->nombre = nombre;  //usamos el this para distinguir los atributos de la función con los métodos de la clase 
    } 

    void setEdad(int edad){ 
        this->edad = edad; 
    } 
    
    void setNumeroCuenta(int numeroCuenta){ 
        numCuenta = numeroCuenta; 
    } 

    virtual ~Cliente(){  //destructor de la clase cliente (virtual porque la clase base tambien va a tener destructor) 
    } 

}; 

class ClienteSeguro: public Cliente{ 
public: 

    ClienteSeguro(int dni, string nombre, int edad, int numCuenta): Cliente(dni, nombre, edad, numCuenta){} 

    ~ClienteSeguro(){    //destructor 

    } 
    void Verificar() const { 
    } 

}; 


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

 

class Profesional : public Persona { //herencia publica 
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

} 
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

 
