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
//EJER 4 
#include <iostream>
#include <string>
using namespace std;

class Personaje {
public:
    static const int SALUD_GUERRERO = 150;
    static const int SALUD_MAGO = 100;
    static const int SALUD_ARQUERO = 120;

    string nombre;
    int salud;

    Personaje(const string& nombre, int salud) : nombre(nombre), salud(salud) {}

    virtual void atacar(Personaje& objetivo) = 0;
    virtual void defender() = 0;
    virtual void habilidadEspecial(Personaje& objetivo) = 0;

    void mostrarSalud() {
        cout << nombre << " tiene " << salud << " puntos de salud." << endl;
    }

    virtual ~Personaje() {}
};

class Guerrero : public Personaje {
public:
    Guerrero(const string& nombre) : Personaje(nombre, SALUD_GUERRERO) {}

    void atacar(Personaje& objetivo) override {
        cout << nombre << " ataca con su espada a " << objetivo.nombre << endl;
        objetivo.salud -= 20;
    }

    void defender() override {
        cout << nombre << " se defiende con su escudo." << endl;
    }

    void habilidadEspecial(Personaje& objetivo) override {
        cout << nombre << " usa su habilidad Warrior's Fury" << endl;
        objetivo.salud -= 50;
    }
};

class Mago : public Personaje {
public:
    Mago(const string& nombre) : Personaje(nombre, SALUD_MAGO) {}

    void atacar(Personaje& objetivo) override {
        cout << nombre << " lanza un hechizo a " << objetivo.nombre << endl;
        objetivo.salud -= 15;
    }

    void defender() override {
        cout << nombre << " crea un escudo magico." << endl;
    }

    void habilidadEspecial(Personaje& objetivo) override {
        cout << nombre << " usa su habilidad cutting water" << endl;
        objetivo.salud -= 60;
    }
};

class Arquero : public Personaje {
public:
    Arquero(const string& nombre) : Personaje(nombre, SALUD_ARQUERO) {}

    void atacar(Personaje& objetivo) override {
        cout << nombre << " dispara una flecha a " << objetivo.nombre << endl;
        objetivo.salud -= 18;
    }

    void defender() override {
        cout << nombre << " se oculta en las rocas." << endl;
    }

    void habilidadEspecial(Personaje& objetivo) override {
        cout << nombre << " usa su habilidad flecha de luz" << endl;
        objetivo.salud -= 40;
    }
};

int main() {
    Guerrero guerrero("WILLI");
    Mago mago("VEGETA ");
    Arquero arquero("Iruma");

    Personaje* personajes[] = { &guerrero, &mago, &arquero };

    personajes[0]->atacar(*personajes[1]);
    personajes[1]->defender();
    personajes[2]->habilidadEspecial(*personajes[0]);

    // Mostrar salud 
    for (auto* p : personajes) {
        p->mostrarSalud();
    }

    return 0;
}
//EJER5
#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS = 100;

class Producto {
protected:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(const string& nombre, double precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    virtual double calcularValorInventario() const = 0;
    virtual void aplicarDescuento(double porcentaje) = 0;

    virtual ~Producto() {}
};

class Electronico : public Producto {
public:
    Electronico(const string& nombre, double precio, int cantidad)
        : Producto(nombre, precio, cantidad) {}

    double calcularValorInventario() const override {
        return precio * cantidad;
    }

    void aplicarDescuento(double porcentaje) override {
        precio -= precio * porcentaje / 100;
    }
};

class Ropa : public Producto {
public:
    Ropa(const string& nombre, double precio, int cantidad)
        : Producto(nombre, precio, cantidad) {}

    double calcularValorInventario() const override {
        return precio * cantidad;
    }

    void aplicarDescuento(double porcentaje) override {
        precio -= precio * porcentaje / 100;
    }
};

class Alimento : public Producto {
public:
    Alimento(const string& nombre, double precio, int cantidad)
        : Producto(nombre, precio, cantidad) {}

    double calcularValorInventario() const override {
        return precio * cantidad;
    }

    void aplicarDescuento(double porcentaje) override {
        precio -= precio * porcentaje / 100;
    }
};

class GestionInventario {
private:
    Producto* productos[MAX_PRODUCTOS];
    int numProductos;

public:
    GestionInventario() : numProductos(0) {}

    void agregarProducto(Producto* producto) {
        if (numProductos < MAX_PRODUCTOS) {
            productos[numProductos++] = producto;
        } else {
            cout << "Error: El inventario está lleno." << endl;
        }
    }

    double calcularValorTotalInventario() const {
        double total = 0;
        for (int i = 0; i < numProductos; ++i) {
            total += productos[i]->calcularValorInventario();
        }
        return total;
    }

    void aplicarDescuentos(double porcentaje) {
        for (int i = 0; i < numProductos; ++i) {
            productos[i]->aplicarDescuento(porcentaje);
        }
    }

    ~GestionInventario() {
        for (int i = 0; i < numProductos; ++i) {
            delete productos[i];
        }
    }
};

void mostrarMenu() {
    cout << "1. Agregar producto" << endl;
    cout << "2. Calcular valor total del inventario" << endl;
    cout << "3. Aplicar descuento" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    GestionInventario inventario;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int tipoProducto;
                string nombre;
                double precio;
                int cantidad;

                cout << "Seleccione el tipo de producto (1. Electronico, 2. Ropa, 3. Alimento): ";
                cin >> tipoProducto;

                cout << "Ingrese el nombre del producto: ";
                cin >> nombre;
                cout << "Ingrese el precio del producto: ";
                cin >> precio;
                cout << "Ingrese la cantidad del producto: ";
                cin >> cantidad;

                if (tipoProducto == 1) {
                    inventario.agregarProducto(new Electronico(nombre, precio, cantidad));
                } else if (tipoProducto == 2) {
                    inventario.agregarProducto(new Ropa(nombre, precio, cantidad));
                } else if (tipoProducto == 3) {
                    inventario.agregarProducto(new Alimento(nombre, precio, cantidad));
                } else {
                    cout << "Tipo de producto no válido." << endl;
                }
                break;
            }
            case 2: {
                cout << "Valor total del inventario: $" << inventario.calcularValorTotalInventario() << endl;
                break;
            }
            case 3: {
                double porcentaje;
                cout << "Ingrese el porcentaje de descuento: ";
                cin >> porcentaje;
                inventario.aplicarDescuentos(porcentaje);
                cout << "Descuento aplicado." << endl;
                break;
            }
            case 4: {
                cout << "Saliendo..." << endl;
                break;
            }
            default: {
                cout << "Opción no válida." << endl;
                break;
            }
        }
    } while (opcion != 4);

    return 0;
}

