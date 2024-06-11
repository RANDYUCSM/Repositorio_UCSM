//Ejercicio 1
//En C++
#include <iostream>
#include <string>
using namespace std;

// Clase base Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    int anioFabricacion;
    double precio;

public:
    Vehiculo(string _marca, string _modelo, int _anioFabricacion, double _precio)
        : marca(_marca), modelo(_modelo), anioFabricacion(_anioFabricacion), precio(_precio) {}

    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio de Fabricacion: " << anioFabricacion << endl;
        cout << "Precio: S/." << precio << endl;
    }
};

// Clase derivada Automovil
class Automovil : public Vehiculo {
private:
    int numeroPuertas;
    string tipoCombustible;

public:
    Automovil(string _marca, string _modelo, int _anioFabricacion, double _precio, int _numeroPuertas, string _tipoCombustible)
        : Vehiculo(_marca, _modelo, _anioFabricacion, _precio), numeroPuertas(_numeroPuertas), tipoCombustible(_tipoCombustible) {}

    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << "Numero de Puertas: " << numeroPuertas << endl;
        cout << "Tipo de Combustible: " << tipoCombustible << endl;
    }
};

// Clase derivada Motocicleta
class Motocicleta : public Vehiculo {
private:
    int cilindro;

public:
    Motocicleta(string _marca, string _modelo, int _anioFabricacion, double _precio, int _cilindro)
        : Vehiculo(_marca, _modelo, _anioFabricacion, _precio), cilindro(_cilindro) {}

};

int main() {
    Automovil auto1("Toyota", "Corola", 2022, 25000.0, 4, "Gasolina");
    cout << "Informacion del Automovil:" << endl;
    auto1.mostrarInfo();
    cout << endl;

    Motocicleta moto1("Honda", "CBR60", 2021, 12000.0, 600);
    cout << "Informacion de la Motocicleta:" << endl;
    moto1.mostrarInfo();

    return 0;
}
//PYTHON
class Vehiculo:
    def __init__(self, marca, modelo, anio_fabricacion, precio):
        self.marca = marca
        self.modelo = modelo
        self.anio_fabricacion = anio_fabricacion
        self.precio = precio

    def mostrar_info(self):
        print(f"Marca: {self.marca}")
        print(f"Modelo: {self.modelo}")
        print(f"Año de Fabricación: {self.anio_fabricacion}")
        print(f"Precio: S/. {self.precio}")


class Automovil(Vehiculo):
    def __init__(self, marca, modelo, anio_fabricacion, precio, numero_puertas, tipo_combustible):
        super().__init__(marca, modelo, anio_fabricacion, precio)
        self.numero_puertas = numero_puertas
        self.tipo_combustible = tipo_combustible

    def mostrar_info(self):
        super().mostrar_info()
        print(f"Número de Puertas: {self.numero_puertas}")
        print(f"Tipo de Combustible: {self.tipo_combustible}")


class Motocicleta(Vehiculo):
    def __init__(self, marca, modelo, anio_fabricacion, precio, cilindro):
        super().__init__(marca, modelo, anio_fabricacion, precio)
        self.cilindro = cilindro

    def mostrar_info(self):
        super().mostrar_info()
        print(f"Cilindrada: {self.cilindro} cc")

auto1 = Automovil("Toyota", "Corolla", 2022, 25000.0, 4, "Gasolina")
print("Información del Automóvil:")
auto1.mostrar_info()
print()

moto1 = Motocicleta("Honda", "CBR60", 2021, 12000.0, 600)
print("Información de la Motocicleta:")
moto1.mostrar_info()
//JAVA
import java.util.ArrayList;
import java.util.List;

// Clase base Vehiculo
class Vehiculo {
    protected String marca;
    protected String modelo;
    protected int anioFabricacion;
    protected double precio;

    public Vehiculo(String marca, String modelo, int anioFabricacion, double precio) {
        this.marca = marca;
        this.modelo = modelo;
        this.anioFabricacion = anioFabricacion;
        this.precio = precio;
    }

    public void mostrarInfo() {
        System.out.println("Marca: " + marca);
        System.out.println("Modelo: " + modelo);
        System.out.println("Año de Fabricación: " + anioFabricacion);
        System.out.println("Precio: S/." + precio);
    }
}

// Clase derivada Automovil
class Automovil extends Vehiculo {
    private int numeroPuertas;
    private String tipoCombustible;

    public Automovil(String marca, String modelo, int anioFabricacion, double precio, int numeroPuertas, String tipoCombustible) {
        super(marca, modelo, anioFabricacion, precio);
        this.numeroPuertas = numeroPuertas;
        this.tipoCombustible = tipoCombustible;
    }

    @Override
    public void mostrarInfo() {
        super.mostrarInfo();
        System.out.println("Número de Puertas: " + numeroPuertas);
        System.out.println("Tipo de Combustible: " + tipoCombustible);
    }
}

// Clase derivada Motocicleta
class Motocicleta extends Vehiculo {
    private int cilindro;

    public Motocicleta(String marca, String modelo, int anioFabricacion, double precio, int cilindro) {
        super(marca, modelo, anioFabricacion, precio);
        this.cilindro = cilindro;
    }

    public void mostrarInfo() {
        super.mostrarInfo();
        System.out.println("Cilindrada: " + cilindro + " cc");
    }
}

public class Main {
    public static void main(String[] args) {
        List<Vehiculo> vehiculos = new ArrayList<>();

        Automovil auto1 = new Automovil("Toyota", "Corolla", 2022, 25000.0, 4, "Gasolina");
        vehiculos.add(auto1);

        Motocicleta moto1 = new Motocicleta("Honda", "CBR600", 2021, 12000.0, 600);
        vehiculos.add(moto1);

        for (Vehiculo vehiculo : vehiculos) {
            System.out.println("Información del Vehículo:");
            vehiculo.mostrarInfo();
            System.out.println();
        }
    }
}
//EJERCICIO 2
//C++
#include <iostream>
#include <string>

using namespace std;

class Persona {
protected:
    string email;

public:
    string nombre;
    int edad;
    int salario;

    Persona(string nombre, int edad, int salario, string email)
        : nombre(nombre), edad(edad), salario(salario), email(email) {}

    virtual ~Persona() {}

    virtual void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Salario: $" << salario << endl;
        cout << "Email: " << email << endl;
    }
};

class Empleado : public Persona {
public:
    Empleado(string nombre, int edad, double salario, string email)
        : Persona(nombre, edad, salario, email) {}

    void mostrarInformacion() override {
        cout << "Informacion del Empleado " << endl;
        Persona::mostrarInformacion();
    }
};

class Cliente : public Persona {
public:
    Cliente(string nombre, int edad, int salario, string email)
        : Persona(nombre, edad, salario, email) {}

    void mostrarInformacion() override {
        cout << " Informacion del Cliente " << endl;
        Persona::mostrarInformacion();
    }
};

int main() {
    Empleado empleado("Juan", 30, 3000, "juan@example.com");
    Cliente cliente("Maria", 25, 0, "maria@example.com");

    empleado.mostrarInformacion();
    cout << endl;
    cliente.mostrarInformacion();

    return 0;
}
//PYTHON
class Persona:
    def __init__(self, nombre, edad, salario, email):
        self.nombre = nombre
        self.edad = edad
        self.salario = salario
        self.email = email

    def mostrar_informacion(self):
        print(f"Nombre: {self.nombre}")
        print(f"Edad: {self.edad}")
        print(f"Salario: s/{self.salario}")
        print(f"Email: {self.email}")

class Empleado(Persona):
    def __init__(self, nombre, edad, salario, email):
        super().__init__(nombre, edad, salario, email)

    def mostrar_informacion(self):
        print("Informacion del Empleado")
        super().mostrar_informacion()

class Cliente(Persona):
    def __init__(self, nombre, edad, salario, email):
        super().__init__(nombre, edad, salario, email)

    def mostrar_informacion(self):
        print("Informacion del Cliente")
        super().mostrar_informacion()

def main():
    empleado = Empleado("Juan", 30, 3000, "juan@example.com")
    cliente = Cliente("Maria", 25, 0, "maria@example.com")

    empleado.mostrar_informacion()
    print()
    cliente.mostrar_informacion()

main()
//JAVA
public class Main {

    public static void main(String[] args) {
        Empleado empleado = new Empleado("Juan", 30, 3000, "juan@example.com");
        Cliente cliente = new Cliente("Maria", 25, 0, "maria@example.com");

        empleado.mostrarInformacion();
        System.out.println();
        cliente.mostrarInformacion();
    }
}

class Persona {
    protected String email;
    public String nombre;
    public int edad;
    public int salario;

    public Persona(String nombre, int edad, double salario, String email) {
        this.nombre = nombre;
        this.edad = edad;
        this.salario = salario;
        this.email = email;
    }

    public void mostrarInformacion() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Edad: " + edad);
        System.out.println("Salario: S/" + salario);
        System.out.println("Email: " + email);
    }
}

class Empleado extends Persona {

    public Empleado(String nombre, int edad, int salario, String email) {
        super(nombre, edad, salario, email);
    }

    public void mostrarInformacion() {
        System.out.println("Informacion del Empleado");
        super.mostrarInformacion();
    }
}

class Cliente extends Persona {

    public Cliente(String nombre, int edad, int salario, String email) {
        super(nombre, edad, salario, email);
    }

    public void mostrarInformacion() {
        System.out.println("Informacion del Cliente");
        super.mostrarInformacion();
    }
}
//EJERCICIO 3
//C++
#include <iostream>
#include <string>
using namespace std;

class Movil {
protected:
    string marca;
    string modelo;
    string sistemaOperativo;

public:
    Movil(string marca, string modelo, string sistemaOperativo)
        : marca(marca), modelo(modelo), sistemaOperativo(sistemaOperativo) {
        cout << "Constructor de Movil llamado" << endl;
    }

    virtual ~Movil() {
        cout << "Destructor de Movil llamado" << endl;
    }
};

class Telefono : public Movil {
public:
    Telefono(string marca, string modelo, string sistemaOperativo)
        : Movil(marca, modelo, sistemaOperativo) {
        cout << "Constructor de Telefono llamado" << endl;
    }

    ~Telefono() {
        cout << "Destructor de Telefono llamado" << endl;
    }
};

class Tablet : public Movil {
public:
    Tablet(string marca, string modelo, string sistemaOperativo)
        : Movil(marca, modelo, sistemaOperativo) {
        cout << "Constructor de Tablet llamado" << endl;
    }

    ~Tablet() {
        cout << "Destructor de Tablet llamado" << endl;
    }
};

int main() {
    Telefono telefono("Samsung", "Galaxy S21", "Android");
    cout << endl;
    Tablet tablet("Apple", "iPad ", "iOS");

    return 0;
}
//PYTHON
class Movil:
    def __init__(self, marca, modelo, sistema_operativo):
        self.marca = marca
        self.modelo = modelo
        self.sistema_operativo = sistema_operativo
        print("Constructor de Movil llamado")

    def __del__(self):
        print("Destructor de Movil llamado")

class Telefono(Movil):
    def __init__(self, marca, modelo, sistema_operativo):
        super().__init__(marca, modelo, sistema_operativo)
        print("Constructor de Telefono llamado")

    def __del__(self):
        print("Destructor de Telefono llamado")

class Tablet(Movil):
    def __init__(self, marca, modelo, sistema_operativo):
        super().__init__(marca, modelo, sistema_operativo)
        print("Constructor de Tablet llamado")

    def __del__(self):
        print("Destructor de Tablet llamado")

def main():
    telefono = Telefono("Samsung", "Galaxy S21", "Android")
    print()
    tablet = Tablet("Apple", "iPad", "iOS")
main()
//JAVA
class Movil {
    protected String marca;
    protected String modelo;
    protected String sistemaOperativo;

    public Movil(String marca, String modelo, String sistemaOperativo) {
        this.marca = marca;
        this.modelo = modelo;
        this.sistemaOperativo = sistemaOperativo;
        System.out.println("Constructor de Movil llamado");
    }

    protected void finalize() {
        System.out.println("Destructor de Movil llamado");
    }
}

class Telefono extends Movil {
    public Telefono(String marca, String modelo, String sistemaOperativo) {
        super(marca, modelo, sistemaOperativo);
        System.out.println("Constructor de Telefono llamado");
    }

    protected void finalize() {
        System.out.println("Destructor de Telefono llamado");
    }
}

class Tablet extends Movil {
    public Tablet(String marca, String modelo, String sistemaOperativo) {
        super(marca, modelo, sistemaOperativo);
        System.out.println("Constructor de Tablet llamado");
    }

    protected void finalize() {
        System.out.println("Destructor de Tablet llamado");
    }
}

public class Main {
    public static void main(String[] args) {
        Telefono telefono = new Telefono("Samsung", "Galaxy S21", "Android");
        System.out.println();
        Tablet tablet = new Tablet("Apple", "iPad", "iOS");
    }
}







