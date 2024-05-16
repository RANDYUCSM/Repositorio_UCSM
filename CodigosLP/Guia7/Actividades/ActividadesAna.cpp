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
