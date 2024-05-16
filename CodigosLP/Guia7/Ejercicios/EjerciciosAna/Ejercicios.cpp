//ACTIVIDAD 1
#include <iostream>
#include <string>

using namespace std;

// Clase base "Vehículo"
class Vehiculo {
protected:
    string marca;
    string modelo;
    int añoFabricacion;
    int precio;

public:
    // Constructor
    Vehiculo(string marca, string modelo, int añoFabricacion, int precio): marca(marca), modelo(modelo), añoFabricacion(añoFabricacion), precio(precio) {}

    // Método para mostrar información del vehículo
    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año de fabricación: " << añoFabricacion << endl;
        cout << "Precio: $" << precio << endl;
    }
};

// Clase derivada AUTOMOVIL
class Automovil : public Vehiculo {
public:
    int numeroPuertas;
    string tipoCombustible;

    // Constructor AUTomovil
    Automovil(string marca, string modelo, int añoFabricacion, int precio, int numeroPuertas, string tipoCombustible)
        : Vehiculo(marca, modelo, añoFabricacion, precio),
          numeroPuertas(numeroPuertas), tipoCombustible(tipoCombustible) {}

    // Método 
    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << "Numero de puertas: " << numeroPuertas << endl;
        cout << "Tipo de combustible: " << tipoCombustible << endl;
    }
};

// Clase derivada MOTOCICLETA
class Motocicleta : public Vehiculo {
public:
    int cilindrada;

    // Constructor 
    Motocicleta(string marca, string modelo, int añoFabricacion, int precio,int cilindrada)
        : Vehiculo(marca, modelo, añoFabricacion, precio), cilindrada(cilindrada) {}

    // Método 
    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};

int main() {
    // objeto Automovil
    Automovil miAuto("Toyota", "Fortuner", 2024, 42500, 4, "Petroleo");
    cout << "Información del automóvil:" << endl;
    miAuto.mostrarInfo();
    cout << endl;

    // Objeto Motocicleta
    Motocicleta miMoto("Honda", "Terreno", 2021, 7000, 500);
    cout << "Información de la motocicleta:" << endl;
    miMoto.mostrarInfo();

    return 0;
}

//ACTIVIDAD 2
#include <iostream>
#include <string>

using namespace std;

class Persona {
private: 
    int edad;
    int salario;
    string correoElectronico;

public:
    string nombre;
    Persona(string nombre, int edad, int salario, string correoElectronico): nombre(nombre), edad(edad), salario(salario), correoElectronico(correoElectronico) {}

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Salario:" << salario << endl;
        cout << "Correo Electrónico: " << correoElectronico << endl;
    }
};

class Empleado : public Persona {
public:
    Empleado(string nombre, int edad, int salario, string correoElectronico): Persona(nombre, edad, salario, correoElectronico) {}

    void mostrarInformacion() {
        Persona::mostrarInformacion();
        cout << "Tipo: Empleado" << endl;
    }
};

class Cliente : public Persona {
public:
    Cliente(string nombre, int edad, int salario, string correoElectronico): Persona(nombre, edad, salario, correoElectronico) {}

    void mostrarInformacion() {
        Persona::mostrarInformacion();
        cout << "Tipo: Cliente" << endl;
    }
};

int main() {
    Empleado emp1("Ana", 40, 3000, "ana.bruno@ucsm.edu.pe");
    Cliente cli1("MIGUEL", 30, 0, "miguel.andia@ucsm.edu.pe");

    cout << "Información del Empleado:" << endl;
    emp1.mostrarInformacion();

    cout << "Información del Cliente:" << endl;
    cli1.mostrarInformacion();

    return 0;
};
//EJERICICIO 3
#include <iostream>
#include <string>

using namespace std;

class Movil {
protected:
    string marca;
    string modelo;
    string sistemaOperativo;

public:
    Movil(string marca, string modelo, string sistemaOperativo): marca(marca), modelo(modelo), sistemaOperativo(sistemaOperativo) {}// Constructor
    
    virtual ~Movil() {}// Destructor


    void imprimirDetalles() const { //imprimir
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Sistema Operativo: " << sistemaOperativo << endl;
    }
};

class Telefono : public Movil {
public:
    Telefono(string marca, string modelo, string sistemaOperativo): Movil(marca, modelo, sistemaOperativo) {} // Constructor específico para Teléfono

    ~Telefono() {}
};

class Tablet : public Movil {
public:
    Tablet(string marca, string modelo, string sistemaOperativo)
        : Movil(marca, modelo, sistemaOperativo) {}

    ~Tablet() {} //destructor 
};

int main() {
    string marcaTelefono, modeloTelefono, sistemaOperativoTelefono;
    cout << "Ingrese la marca del teléfono: ";
    cin >> marcaTelefono;
    cout << "Ingrese el modelo del teléfono: ";
    cin >> modeloTelefono;
    cout << "Ingrese el sistema operativo del teléfono: ";
    cin >> sistemaOperativoTelefono;

    
    Telefono miTelefono(marcaTelefono, modeloTelefono, sistemaOperativoTelefono);//creacion de objeto
    
    string marcaTablet, modeloTablet, sistemaOperativoTablet;
    cout << "Ingrese la marca de la tablet: ";
    cin >> marcaTablet;
    cout << "Ingrese el modelo de la tablet: ";
    cin >> modeloTablet;
    cout << "Ingrese el sistema operativo de la tablet: ";
    cin >> sistemaOperativoTablet;

    // Creacion de objeto de la clase Tablet con los datos ingresados 
    Tablet miTablet(marcaTablet, modeloTablet, sistemaOperativoTablet);

    cout << endl << "Detalles del Teléfono:" << endl;
    miTelefono.imprimirDetalles();

    cout << endl << "Detalles de la Tablet:" << endl;
    miTablet.imprimirDetalles();

    return 0;
}
