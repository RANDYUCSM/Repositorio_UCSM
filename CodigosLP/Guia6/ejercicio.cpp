#include <iostream>
#include <vector>

using namespace std;

class Alumno {
public:
    string nombre;
    int edad;
    float promedio;

    Alumno(string n = "", int e = 0, float p = 0.0f) : nombre(n), edad(e), promedio(p) {}
};

class Grupo {
public:
    vector<Alumno> alumnos;
    int cantidad;

    Grupo(int c) : cantidad(c) {}

    void agregarAlumno() {
        if (alumnos.size() < cantidad) {
            string nombre;
            int edad;
            float promedio;

            cout << "Ingrese el nombre del alumno: ";
            cin >> nombre;
            cout << "Ingrese la edad del alumno: ";
            cin >> edad;
            cout << "Ingrese el promedio del alumno: ";
            cin >> promedio;

            alumnos.push_back(Alumno(nombre, edad, promedio));
        } else {
            cout << "No se puede agregar más alumnos. El grupo está lleno." << endl;
        }
    }

    float promedioGrupo() {
        float totalPromedios = 0.0f;
        for (const auto& alumno : alumnos) {
            totalPromedios += alumno.promedio;
        }
        return totalPromedios / alumnos.size();
    }

    Alumno mejorPromedio() {
        if (alumnos.empty()) {
            cerr << "No hay alumnos en el grupo." << endl;
            return Alumno();  // Retornar un alumno vacío si no hay alumnos en el grupo
        }

        Alumno mejor = alumnos[0];
        for (const auto& alumno : alumnos) {
            if (alumno.promedio > mejor.promedio) {
                mejor = alumno;
            }
        }
        return mejor;
    }
};

int main() {
    Grupo grupo(5);

    cout << "Por favor ingrese los datos de los 5 alumnos:" << endl;
    for (int i = 0; i < 5; ++i) {
        grupo.agregarAlumno();
    }

    cout << "\nObjeto Grupo:" << endl;
    for (const auto& alumno : grupo.alumnos) {
        cout << "Nombre: " << alumno.nombre << ", Edad: " << alumno.edad << ", Promedio: " << alumno.promedio << endl;
    }

    cout << "\nPromedio de los promedios del grupo: " << grupo.promedioGrupo() << endl;

    Alumno mejorPromedio = grupo.mejorPromedio();
    cout << "\nAlumno con el mejor promedio del grupo:" << endl;
    cout << "Nombre: " << mejorPromedio.nombre << ", Edad: " << mejorPromedio.edad << ", Promedio: " << mejorPromedio.promedio << endl;

    return 0;
}

