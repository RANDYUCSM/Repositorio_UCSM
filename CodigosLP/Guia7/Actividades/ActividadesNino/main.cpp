#include <iostream>
#include <string>

#include "Cliente.h"
#include "ClienteSeguro.h"
#include "Funciones.h"

using namespace std;

int main(){
    //Objeto
    ClienteSeguro cliente("Luis","Diaz","Ejemplo1@hotmail.com","1234-5678","HOLA.12");
    cliente.mostrar_inf();
    cliente.mostrar_inf_encr();
}