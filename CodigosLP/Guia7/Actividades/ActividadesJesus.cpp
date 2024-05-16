//Actividades
#include <iostream>
using namespace std;

class Cliente{
    protected:
    //Datos personales clientes
        string nombre;
        int edad;
    //Datos financieros
        string contraseña;
        string contraseña_encriptada;
        void EncriptarContraseña(){ //Metodo para encriptar
            for (int i=0;i<contraseña.length();i++){
                contraseña_encriptada+=to_string(contraseña[i]);
            }
        }
    public:
        Cliente(string n,int e,string c):nombre(n),edad(e),contraseña(c){}

};
class ClienteSeguro:protected Cliente{
    private:
    int DNI;
    public:
    ClienteSeguro(string n,int e,int d,string contra):Cliente(n,e,contra),DNI(d){}
    ~ClienteSeguro(){}; //Destructor
    void MostrarAtributos(){
        Cliente::EncriptarContraseña(); //Usando el metodo encriptar
        cout<<"Nombre:"<<nombre<<endl<<"Edad:"<<edad<<endl<<"DNI:"<<DNI<<endl<<"Contrasenia:"<<contraseña_encriptada<<endl;
    }
};
int main(){
    string nombre,contra;
    int edad,dni;
    cout<<"Ingrese su nombre:";
    cin>>nombre;
    cout<<"Ingrese su edad:";
    cin>>edad;
    cout<<"Ingrese su DNI:";
    cin>>dni;
    cout<<"Ingrese su contrasenia:";
    cin>>contra;
    ClienteSeguro seguro(nombre,edad,dni,contra);
    seguro.MostrarAtributos();

}
class ClienteSeguroPublic:public Cliente{};
class ClienteSeguroProtect:protected Cliente{};
class ClienteSeguroPrivate:private Cliente{};
