//PRIMERA ACTIVIDAD
#include <iostream>
#include <cmath>
using namespace std;

// Clase abstracta Figura
class Figura {
public:
    virtual double calcularArea() = 0;
    virtual ~Figura() {}
};

// Clases derivadas
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() override {
        return M_PI * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return base * altura;
    }
};

class Triangulo : public Figura {
private:
    double base;
    double altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return 0.5 * base * altura;
    }
};

class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double calcularArea() override {
        return lado * lado;
    }
};

class Pentagono : public Figura {
private:
    double lado;
    double apotema;
public:
    Pentagono(double l, double a) : lado(l), apotema(a) {}
    double calcularArea() override {
        return (0.25 * sqrt(25 + 10 * sqrt(5)) * lado * apotema);
    }
};

class Cilindro : public Figura {
private:
    double radio;
    double altura;
public:
    Cilindro(double r, double h) : radio(r), altura(h) {}
    double calcularArea() override {
        double areaBase = M_PI * radio * radio;
        double areaLateral = 2 * M_PI * radio * altura;
        double areaTotal = 2 * areaBase + areaLateral;
        return areaTotal;
    }
};

class Cono : public Figura {
private:
    double radio;
    double altura;
    double generatriz;
public:
    Cono(double r, double h, double g) : radio(r), altura(h), generatriz(g) {}
    double calcularArea() override {
        double areaBase = M_PI * radio * radio;
        double areaLateral = M_PI * radio * generatriz;
        double areaTotal = areaBase + areaLateral;
        return areaTotal;
    }
};

class Trapezoide : public Figura {
private:
    double baseMayor;
    double baseMenor;
    double altura;
    double lado1;
    double lado2;
public:
    Trapezoide(double bMayor, double bMenor, double h, double l1, double l2)
        : baseMayor(bMayor), baseMenor(bMenor), altura(h), lado1(l1), lado2(l2) {}

    double calcularArea() override {
        double area = ((baseMayor + baseMenor) * altura) / 2;
        return area;
    }
};

int main() {
    int opcion;
    double area;
    Figura* figura = nullptr;

    cout << "Elija una figura:" << endl;
    cout << "1. Círculo" << endl;
    cout << "2. Rectángulo" << endl;
    cout << "3. Triángulo" << endl;
    cout << "4. Cuadrado" << endl;
    cout << "5. Pentágono" << endl;
    cout << "6. Cilindro" << endl;
    cout << "7. Cono" << endl;
    cout << "8. Trapezoide" << endl;
    cout << "Ingrese el número correspondiente: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del círculo: ";
            cin >> radio;
            figura = new Circulo(radio);
            break;
        }
        case 2: {
            double base, altura;
            cout << "Ingrese la base del rectángulo: ";
            cin >> base;
            cout << "Ingrese la altura del rectángulo: ";
            cin >> altura;
            figura = new Rectangulo(base, altura);
            break;
        }
        case 3: {
            double base, altura;
            cout << "Ingrese la base del triángulo: ";
            cin >> base;
            cout << "Ingrese la altura del triángulo: ";
            cin >> altura;
            figura = new Triangulo(base, altura);
            break;
        }
        case 4: {
            double lado;
            cout << "Ingrese el lado del cuadrado: ";
            cin >> lado;
            figura = new Cuadrado(lado);
            break;
        }
        case 5: {
            double lado, apotema;
            cout << "Ingrese el lado del pentágono: ";
            cin >> lado;
            cout << "Ingrese la apotema del pentágono: ";
            cin >> apotema;
            figura = new Pentagono(lado, apotema);
            break;
        }
        case 6: {
            double radio, altura;
            cout << "Ingrese el radio del cilindro: ";
            cin >> radio;
            cout << "Ingrese la altura del cilindro: ";
            cin >> altura;
            figura = new Cilindro(radio, altura);
            break;
        }
        case 7: {
            double radio, altura, generatriz;
            cout << "Ingrese el radio del cono: ";
            cin >> radio;
            cout << "Ingrese la altura del cono: ";
            cin >> altura;
            cout << "Ingrese la generatriz del cono: ";
            cin >> generatriz;
            figura = new Cono(radio, altura, generatriz);
            break;
        }
        case 8: {
            double baseMayor, baseMenor, altura, lado1, lado2;
            cout << "Ingrese la base mayor del trapezoide: ";
            cin >> baseMayor;
            cout << "Ingrese la base menor del trapezoide: ";
            cin >> baseMenor;
            cout << "Ingrese la altura del trapezoide: ";
            cin >> altura;
            cout << "Ingrese el lado 1 del trapezoide: ";
            cin >> lado1;
            cout << "Ingrese el lado 2 del trapezoide: ";
            cin >> lado2;
            figura = new Trapezoide(baseMayor, baseMenor, altura, lado1, lado2);
            break;
        }
        default: {
            cout << "Opción inválida" << endl;
            return 0;
        }
    }

    area = figura->calcularArea();
    cout << "El área de la figura es: " << area << endl;
    delete figura;
    return 0;
}

