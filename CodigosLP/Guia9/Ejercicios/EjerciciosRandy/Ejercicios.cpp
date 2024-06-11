//ejer 1
#include <iostream>
#include <string>
using namespace std;

class Forma {
public:
    virtual ~Forma() {}
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void mostrarInformacion() const = 0;
};

class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double area() const {
        return 3.14159 * radio * radio;
    }
    double perimetro() const  {
        return 2 * 3.14159 * radio;
    }
    void mostrarInformacion() const  {
        cout << "Circulo: " << endl;
        cout << "Radio: " << radio << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
    }
};

// Clase derivada Rectangulo
class Rectangulo : public Forma {
private:
    double largo, ancho;
public:
    Rectangulo(double l, double a) : largo(l), ancho(a) {}
    double area() const  {
        return largo * ancho;
    }
    double perimetro() const  {
        return 2 * (largo + ancho);
    }
    void mostrarInformacion() const  {
        cout << "Rectangulo: " << endl;
        cout << "Largo: " << largo << endl;
        cout << "Ancho: " << ancho << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
    }
};

// Clase derivada Triangulo
class Triangulo : public Forma {
private:
    double base, altura, lado1, lado2, lado3;
public:
    Triangulo(double b, double h, double l1, double l2, double l3) 
        : base(b), altura(h), lado1(l1), lado2(l2), lado3(l3) {}
    double area() const  {
        return (base * altura) / 2;
    }
    double perimetro() const  {
        return lado1 + lado2 + lado3;
    }
    void mostrarInformacion() const {
        cout << "Triangulo: " << endl;
        cout << "Base: " << base << endl;
        cout << "Altura: " << altura << endl;
        cout << "Lados: " << lado1 << ", " << lado2 << ", " << lado3 << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
    }
};

void menu() {
    Forma* formas[10];
    int contador = 0;
    int opcion;

    do {
        cout << "\nMenu " << endl;
        cout << "1. Circulo" << endl;
        cout << "2. Rectangulo" << endl;
        cout << "3. A Triangulo" << endl;
        cout << "4. Mostrar Informacion" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                double radio;
                cout << "Ingrese el radio del circulo: ";
                cin >> radio;
                formas[contador++] = new Circulo(radio);
                break;
            }
            case 2: {
                double largo, ancho;
                cout << "Ingrese el largo del rectangulo: ";
                cin >> largo;
                cout << "Ingrese el ancho del rectangulo: ";
                cin >> ancho;
                formas[contador++] = new Rectangulo(largo, ancho);
                break;
            }
            case 3: {
                double base, altura, lado1, lado2, lado3;
                cout << "Ingrese la base del triangulo: ";
                cin >> base;
                cout << "Ingrese la altura del triangulo: ";
                cin >> altura;
                cout << "Ingrese el lado 1 del triangulo: ";
                cin >> lado1;
                cout << "Ingrese el lado 2 del triangulo: ";
                cin >> lado2;
                cout << "Ingrese el lado 3 del triangulo: ";
                cin >> lado3;
                formas[contador++] = new Triangulo(base, altura, lado1, lado2, lado3);
                break;
            }
            case 4: {
                for(int i = 0; i < contador; ++i) {
                    formas[i]->mostrarInformacion();
                }
                break;
            }
            case 5: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida. Intente nuevamente." << endl;
            }
        }
    } while(opcion != 5);

    for(int i = 0; i < contador; ++i) {
        delete formas[i];
    }
}

int main() {
    menu();
    return 0;
}
//EJER 2
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual ~Animal() {}
    virtual void comer() const = 0;
    virtual void dormir() const = 0;
    virtual void moverse() const = 0;
    virtual void mostrarInformacion() const = 0;
};

class Mamifero : public Animal {
private:
    string nombre;
public:
    Mamifero(string n) : nombre(n) {}
    void comer() const override {
        cout << nombre << " está comiendo." << endl;
    }
    void dormir() const override {
        cout << nombre << " está durmiendo." << endl;
    }
    void moverse() const override {
        cout << nombre << " está corriendo." << endl;
    }
    void mostrarInformacion() const override {
        cout << "Mamífero: " << nombre << endl;
    }
};

class Ave : public Animal {
private:
    string nombre;
public:
    Ave(string n) : nombre(n) {}
    void comer() const override {
        cout << nombre << " está comiendo." << endl;
    }
    void dormir() const override {
        cout << nombre << " está durmiendo." << endl;
    }
    void moverse() const override {
        cout << nombre << " está volando." << endl;
    }
    void mostrarInformacion() const override {
        cout << "Ave: " << nombre << endl;
    }
};

class Reptil : public Animal {
private:
    string nombre;
public:
    Reptil(string n) : nombre(n) {}
    void comer() const override {
        cout << nombre << " está comiendo." << endl;
    }
    void dormir() const override {
        cout << nombre << " está durmiendo." << endl;
    }
    void moverse() const override {
        cout << nombre << " está reptando." << endl;
    }
    void mostrarInformacion() const override {
        cout << "Reptil: " << nombre << endl;
    }
};

void menu() {
    Animal* animales[10];
    int contador = 0;
    int opcion;

    do {
        cout << "Menú del Simulador de Animales\n" << endl;
        cout << "1. Agregar Mamífero" << endl;
        cout << "2. Agregar Ave" << endl;
        cout << "3. Agregar Reptil" << endl;
        cout << "4. Mostrar Información de los Animales" << endl;
        cout << "5. Hacer que Todos los Animales Coman" << endl;
        cout << "6. Hacer que Todos los Animales Duerman" << endl;
        cout << "7. Hacer que Todos los Animales se Muevan" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                string nombre;
                cout << "Ingrese el nombre del mamífero: ";
                cin >> nombre;
                animales[contador++] = new Mamifero(nombre);
                break;
            }
            case 2: {
                string nombre;
                cout << "Ingrese el nombre del ave: ";
                cin >> nombre;
                animales[contador++] = new Ave(nombre);
                break;
            }
            case 3: {
                string nombre;
                cout << "Ingrese el nombre del reptil: ";
                cin >> nombre;
                animales[contador++] = new Reptil(nombre);
                break;
            }
            case 4: {
                for(int i = 0; i < contador; ++i) {
                    animales[i]->mostrarInformacion();
                }
                break;
            }
            case 5: {
                for(int i = 0; i < contador; ++i) {
                    animales[i]->comer();
                }
                break;
            }
            case 6: {
                for(int i = 0; i < contador; ++i) {
                    animales[i]->dormir();
                }
                break;
            }
            case 7: {
                for(int i = 0; i < contador; ++i) {
                    animales[i]->moverse();
                }
                break;
            }
            case 8: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default: {
                cout << "Opción inválida. Por favor, intente nuevamente." << endl;
            }
        }
    } while(opcion != 8);

    for(int i = 0; i < contador; ++i) {
        delete animales[i];
    }
}

int main() {
    menu();
    return 0;
}
// EJER3
#include <iostream>
#include <string>
using namespace std;

// Clase base abstracta Empleado
class Empleado {
protected:
    string nombre;
    double salarioBase;
public:
    Empleado(string n, double salario) : nombre(n), salarioBase(salario) {}
    virtual ~Empleado() {}
    virtual double calcularPago() const = 0;
    virtual void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
    }
};

// Clase derivada Asalariado
class Asalariado : public Empleado {
public:
    Asalariado(string n, double salario) : Empleado(n, salario) {}
    double calcularPago() const override {
        return salarioBase;
    }
    void mostrarDatos() const override {
        Empleado::mostrarDatos();
        cout << "Tipo: Asalariado" << endl;
    }
};

// Clase derivada PorHora
class PorHora : public Empleado {
private:
    int horasTrabajadas;
    double tarifaPorHora;
public:
    PorHora(string n, double salarioPorHora, int horas) : Empleado(n, 0), tarifaPorHora(salarioPorHora), horasTrabajadas(horas) {}
    double calcularPago() const override {
        return tarifaPorHora * horasTrabajadas;
    }
    void mostrarDatos() const override {
        Empleado::mostrarDatos();
        cout << "Tipo: Por Hora" << endl;
    }
};

// Clase derivada Comisionista
class Comisionista : public Empleado {
private:
    double ventas;
    double porcentajeComision;
public:
    Comisionista(string n, double salarioBase, double ventasRealizadas, double porcentaje) : Empleado(n, salarioBase), ventas(ventasRealizadas), porcentajeComision(porcentaje) {}
    double calcularPago() const override {
        return salarioBase + (ventas * porcentajeComision / 100);
    }
    void mostrarDatos() const override {
        Empleado::mostrarDatos();
        cout << "Tipo: Comisionista" << endl;
    }
};

// Función para mostrar el menú y gestionar los empleados
void menu() {
    const int MAX_EMPLEADOS = 10;
    Empleado* empleados[MAX_EMPLEADOS];
    int contador = 0;
    int opcion;

    do {
        cout << "\nMenú de salarios\n" << endl;
        cout << "1. Agregar Empleado Asalariado" << endl;
        cout << "2. Agregar Empleado Por Hora" << endl;
        cout << "3. Agregar Empleado Comisionista" << endl;
        cout << "4. Mostrar Información de Empleados" << endl;
        cout << "5. Calcular Pago Total" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                string nombre;
                double salario;
                cout << "Ingrese el nombre del empleado: ";
                cin >> nombre;
                cout << "Ingrese el salario base: ";
                cin >> salario;
                empleados[contador++] = new Asalariado(nombre, salario);
                break;
            }
            case 2: {
                string nombre;
                double tarifa;
                int horas;
                cout << "Ingrese el nombre del empleado: ";
                cin >> nombre;
                cout << "Ingrese la tarifa por hora: ";
                cin >> tarifa;
                cout << "Ingrese las horas trabajadas: ";
                cin >> horas;
                empleados[contador++] = new PorHora(nombre, tarifa, horas);
                break;
            }
            case 3: {
                string nombre;
                double salarioBase, ventas, porcentaje;
                cout << "Ingrese el nombre del empleado: ";
                cin >> nombre;
                cout << "Ingrese el salario base: ";
                cin >> salarioBase;
                cout << "Ingrese las ventas realizadas: ";
                cin >> ventas;
                cout << "Ingrese el porcentaje de comisión (%): ";
                cin >> porcentaje;
                empleados[contador++] = new Comisionista(nombre, salarioBase, ventas, porcentaje);
                break;
            }
            case 4: {
                for(int i = 0; i < contador; ++i) {
                    empleados[i]->mostrarDatos();
                    cout << "Pago: $" << empleados[i]->calcularPago() << endl;
                    cout << endl;
                }
                break;
            }
            case 5: {
                double pagoTotal = 0;
                for(int i = 0; i < contador; ++i) {
                    pagoTotal += empleados[i]->calcularPago();
                }
                cout << "El pago total a los empleados es: $" << pagoTotal << endl;
                break;
            }
            case 6: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Intente nuevamente." << endl;
            }
        }
    } while(opcion != 6);

}

int main() {
    menu();
    return 0;
}


