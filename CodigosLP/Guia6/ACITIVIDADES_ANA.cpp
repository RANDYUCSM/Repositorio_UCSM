//ACTIVIDAD 1
#include <iostream>
using namespace std;

class Estudiante {
private:
  string nombre;
  int codigo;
  float nota1;
  float nota2;
  float nota3;
  float promedio;

public:
  Estudiante(string nombre, int codigo, float nota1, float nota2, float nota3) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->nota1 = nota1;
    this->nota2 = nota2;
    this->nota3 = nota3;
    this->promedio = (nota1 + nota2 + nota3) / 3;
  }

  Estudiante() {
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;
    cout << "Ingrese el código del estudiante: ";
    cin >> codigo;
    cout << "Ingrese la nota 1 del estudiante: ";
    cin >> nota1;
    cout << "Ingrese la nota 2 del estudiante: ";
    cin >> nota2;
    cout << "Ingrese la nota 3 del estudiante: ";
    cin >> nota3;
    this->promedio = (nota1 + nota2 + nota3) / 3;
  }

  void imprimir() {
    cout << "Nombre: " << nombre << endl;
    cout << "Código: " << codigo << endl;
    cout << "Nota 1: " << nota1 << endl;
    cout << "Nota 2: " << nota2 << endl;
    cout << "Nota 3: " << nota3 << endl;
    cout << "Promedio: " << promedio << endl;
  }
};

int main() {
  int numero;
  cout << "Ingrese el número de estudiantes que desea ingresar: ";
  cin >> numero;

  Estudiante estudiantes[numero];

  cout << "\nDatos de los estudiantes:" << endl;
  for (int i = 0; i < numero; i++) {
    cout << "\nEstudiante " << i + 1 << ":" << endl;
    estudiantes[i].imprimir();
  }

  return 0;
}

//ACTIVIDAD 2

#include <iostream>
#include <cmath>
using namespace std;

class Circulo {
private:
    double radio;
    double diametro;

public:
    Circulo(double r) : radio(r), diametro(2 * r) {}

    friend double calcularArea(const Circulo& c);

    void mostrarDatos() const {
        cout << "Radio: " << radio << ", Diámetro: " << diametro << endl;
    }
};

double calcularArea(const Circulo& c) {
    return return 3.1416 * c.radio * c.radio; // Área = π * r^2
}

int main() {
    double radio;
    cout << "Ingrese el radio del círculo: ";
    cin >> radio;

    Circulo c(radio);
    cout << "Datos del círculo:" << endl;
    c.mostrarDatos();
    cout << "Área del círculo: " << calcularArea(c) << endl;

    return 0;
}

//Actividad 1 mejorado
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
  string nombre;
  int codigo;
  float nota1;
  float nota2;
  float nota3;
  float promedio;

public:
  Estudiante(string nombre, int codigo, float nota1, float nota2, float nota3) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->nota1 = nota1;
    this->nota2 = nota2;
    this->nota3 = nota3;
    this->promedio = (nota1 + nota2 + nota3) / 3;
  }

  Estudiante() {
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;
    cout << "Ingrese el código del estudiante: ";
    cin >> codigo;
    cout << "Ingrese la nota 1 del estudiante: ";
    cin >> nota1;
    cout << "Ingrese la nota 2 del estudiante: ";
    cin >> nota2;
    cout << "Ingrese la nota 3 del estudiante: ";
    cin >> nota3;
    this->promedio = (nota1 + nota2 + nota3) / 3;
  }

  void imprimir() {
    cout << "Nombre: " << nombre << endl;
    cout << "Código: " << codigo << endl;
    cout << "Nota 1: " << nota1 << endl;
    cout << "Nota 2: " << nota2 << endl;
    cout << "Nota 3: " << nota3 << endl;
    cout << "Promedio: " << promedio << endl;
  }

  float obtenerPromedio() const {
    return promedio;
  }
};

int main() {
  int numero;
  cout << "Ingrese el número de estudiantes que desea ingresar: ";
  cin >> numero;

  Estudiante estudiantes[numero];

  // Ordenar los estudiantes por promedio utilizando el método de burbuja
  for (int i = 0; i < numero - 1; i++) {
    for (int j = 0; j < numero - i - 1; j++) {
      if (estudiantes[j].obtenerPromedio() < estudiantes[j + 1].obtenerPromedio()) {
        swap(estudiantes[j], estudiantes[j + 1]);
      }
    }
  }

  cout << "\nDatos de los estudiantes ordenados por promedio (de mayor a menor):" << endl;
  for (int i = 0; i < numero; i++) {
    cout << "\nEstudiante " << i + 1 << ":" << endl;
    estudiantes[i].imprimir();
  }

  return 0;
}

