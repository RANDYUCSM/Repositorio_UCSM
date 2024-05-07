#include <iostream>
using namespace std;
class Alumno{
    public:
        string nombre;
        int edad;
        float promedio;
    
    Alumno(string n,int e,float p){
        this->nombre=n;
        this->edad=e;
        this->promedio=p;
    };
    float getPromedio(){
        return promedio;
    }
    bool operator<(const Alumno&);
    friend ostream& operator<<(ostream&,Alumno&);

};
bool Alumno::operator<(const Alumno& alumno){
    if (this->promedio<alumno.promedio){
        return true;
    }
    else{
        return false;
    }
}
ostream& operator<<(ostream& os,Alumno& alumno){
    os<<alumno.nombre<<","<<alumno.edad<<","<<alumno.promedio;
    return os;
}
class Grupo{
    public:
        int cantidad;
        Alumno alumno[3];
    
        Grupo(int c, Alumno alumnos[3]) : cantidad(c) {
        for (int i = 0; i < 3; i++) {
            this->alumno[i] = alumnos[i];
            }
        }
        friend ostream& operator<<(ostream&,Grupo&);

};
ostream& operator<<(ostream& os, const Grupo& grupo) {
        os << "Grupo con " << grupo.cantidad << " alumnos:" << std::endl;
        for (int i = 0; i < 3; i++) {
            os << "Alumno " << i+1 << ": " << grupo.alumno[i].nombre << " - Edad: " << grupo.alumno[i].edad <<endl;
        }
        return os;
}
