#ifndef CLIENTESEGURO_H
#define CLIENTESEGURO_H

#include <iostream>
#include <string>
#include "cliente.h"
#include "Funciones.h"

using namespace std;

class ClienteSeguro : protected Cliente {
    // Atributos
private:
    string password;
public:
    // Constructor:
    ClienteSeguro(string nomb, string apell, string corr, string tarj, string pass);
    // Se llama el destructor de la clase cliente implicitamente
    ~ClienteSeguro() {}
    // Mostrar informacion - encriptada
    void mostrar_inf();
    void mostrar_inf_encr();
protected:
    /* Métodos para encriptar la 
    información y verificar la autenticidad del cliente */
    void encrypt();
    void decrypt();
};

// Constructor
ClienteSeguro::ClienteSeguro(string nomb, string apell, string corr, string tarj, string pass) : Cliente(nomb, apell, corr, tarj) {
    this->password = pass;
}

void ClienteSeguro::encrypt() {
    int valor = 1;
    string txt_encr;
    string tar_encr;
    for (size_t i = 0; i < this->password.length(); i++) {
        if (i % 2 == 0) {
            txt_encr += string(1, this->password[i] + valor);
            tar_encr += string(1, this->tarjeta[i] + valor);
        } else {
            txt_encr += string(1, this->password[i] - valor);
            tar_encr += string(1, this->tarjeta[i] - valor);
        }
        valor++;
    }
    this->password = txt_encr;
    this->tarjeta = tar_encr;
}

void ClienteSeguro::decrypt() {
    int valor = 1;
    string txt;

    for (size_t i = 0; i < this->password.length(); i++) {
        if (i % 2 == 0) {
            txt += string(1, this->password[i] - valor);
        } else {
            txt += string(1, this->password[i] + valor);
        }
        valor++;
    }
    this->password = txt;
}

void ClienteSeguro::mostrar_inf() {
    cout << "---------------------------------------------" << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Apellido: " << this->apellido << endl;
    cout << "Correo: " << this->correo << endl;
    cout << "Tarjeta: " << this->tarjeta << endl;
    cout << "Contraseña: " << this->password << endl;
    cout << "---------------------------------------------" << endl;
}

void ClienteSeguro::mostrar_inf_encr() {
    this->encrypt();
    cout << "---------------------------------------------" << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Apellido: " << this->apellido << endl;
    cout << "Correo: " << this->correo << endl;
    cout << "Tarjeta: " << this->tarjeta << endl;
    cout << "Contraseña: " << this->password << endl;
    cout << "---------------------------------------------" << endl;
}

#endif
