#include <iostream>
#include <string>
#include "Funciones.h"
using namespace std;

string encriptar_password(string& passw){
    int valor = 2;
    string passw_encr;
    //Usar tabla ascii restar o sumar cantidades
    for(int i=0;i<lenght(passw);i++){
        if (i % 2 == 0){
            passw_encr += string(1,passw[i]+valor);
        }else{
            passw_encr += string(1,passw[i]-valor);
        }
        valor++;
    }
    
    return passw_encr;
}

string desencriptar_password(string& passw_e){
    int valor = 2;
    string passw;
    //Usar tabla ascii restar o sumar cantidades
    for(int i=0;i<lenght(passw_e);i++){
        if (i % 2 == 0){
            passw += passw_e[i]-valor;
        }else{
            passw += passw_e[i]+valor;
        }
        valor++;
    }
    
    return passw;
}

/*size_t string::length() const {
    // Contar el número de caracteres en la cadena
    size_t count = 0;
    while (data[count] != '\0') {  // El caracter nulo marca el final de la cadena
        ++count;
    }
    return count;
}*/



int main(){
    string password;
    password = "hola";
    string pass_enc;
    pass_enc = encriptar_password(password);

    cout<<"pass: "<<password<<" - pass_enc: "<<pass_enc<<endl;
    cout<<"pass_enc: "<<pass_enc<<" - pass_enc: "<<desencriptar_password(pass_enc)<<endl;
    return 0;
}