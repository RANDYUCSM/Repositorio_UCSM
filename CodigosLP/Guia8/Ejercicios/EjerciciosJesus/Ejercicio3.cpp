//Ejercicio 3
#include <iostream>
using namespace std;
class Empleado{
    public:
    string nombre;
        Empleado(string n):nombre(n){}
        virtual float calcularSalario(int h,float p){
            return (h*p)*26; //Devuelve el salario mensual
        }
};
class EmpleadoTiempoCompleto: public Empleado{
    public:
    EmpleadoTiempoCompleto(string n):Empleado(n){}
        float calcularSalario(int h,float p){
            return h*p;
        }
};
class EmpleadoTiempoMedio:public Empleado{
    public:
    EmpleadoTiempoMedio(string n):Empleado(n){}
        float calcularSalario(int h,float p){
            return h*p;
        }
};

int main(){
    Empleado empleado("Jesus");
    cout<<"El salario mensual de "<<empleado.nombre<<" es: "<<empleado.calcularSalario(8,4)<<endl;

    EmpleadoTiempoCompleto empleadotc("Jesus");
    cout<<"El salario del dia a tiempo completo de "<<empleadotc.nombre<<" es: "<<empleadotc.calcularSalario(8,4)<<endl;

    EmpleadoTiempoMedio empleadotm("Jesus");
    cout<<"El salario del dia a medio tiempo de "<<empleadotm.nombre<<" es: "<<empleadotm.calcularSalario(4,3)<<endl;

    return 0;
}
