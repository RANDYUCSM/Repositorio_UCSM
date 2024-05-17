
#include <iostream>
#include <string>
using namespace std;

class Cliente {  // Clase base
protected:
    string nombre;
    string direccion;
    string numeroTarjeta;

public:
    Cliente(string _nombre, string _direccion, string _numeroTarjeta)
        : nombre(_nombre), direccion(_direccion), numeroTarjeta(_numeroTarjeta) {}

    virtual void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Numero de Tarjeta: " << numeroTarjeta << endl;
    }

    virtual void encriptarInfo() {
        cout << "Encriptando informacion " << endl;
    }
};
class ClienteSeguro : public Cliente {  // Clase derivada
private:
    string claveSegura;

public:
    ClienteSeguro(string _nombre, string _direccion, string _numeroTarjeta, string _claveSegura): Cliente(_nombre, _direccion, _numeroTarjeta), claveSegura(_claveSegura) {}

    void mostrarInfo() override {
        Cliente::mostrarInfo();
        cout << "Clave de Seguridad: " << claveSegura << endl;
    }

    void encriptarInfo() override {
        cout << "Encriptando informacion" << endl;
        string encriptada = numeroTarjeta;    //encriptacion
        for (char& c : encriptada) {
            if ((c)) {
                c = ((c - '0') + 3) % 10 + '0';
            }
        }
        cout << "Numero de Tarjeta encriptado: " << encriptada << endl;
    }

    void verificarAutenticidad() {
        // Para verificar la autenticidad
        cout << "Verificando autenticidad " << endl;
        if (claveSegura == "ma5643") {
            cout << "Autenticidad verificada con exito." << endl;
        } else {
            cout << "Clave de seguridad incorrecta." << endl;
        }
    }

    ~ClienteSeguro() {}
};

int main() {
    ClienteSeguro cliente("Maria suarez", "Calle 73", "1234 5678 9012 3456", "ma5643");
    cliente.mostrarInfo();
    cliente.encriptarInfo();
    cliente.verificarAutenticidad();

    return 0;
}
