#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
using namespace std;

char upper(char letra) { 

    int indice = -1; // Inicializar el índice con un valor que indique "no encontrado" 
    char Abecedario[2][27] = { 
        // mayus     
        {'A','B','C','D','E','F','G','H','I','J','K','L',
        'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, 

        // minus  
        {'a','b','c','d','e','f','g','h','i','j','k','l',
        'm','n','o','p','q','r','s','t','u','v','w','x','y','z'} 
    }; 

    for (int i = 0; i < 27; i++) { 
        if (Abecedario[1][i] == letra) { 
            indice = i; 
            break; 
        } 
    } 

    if (indice != -1) { 
        return Abecedario[0][indice]; 
    } else { 
        // La letra no se encontró en el arreglo 
        // Devolver la misma letra 
        return letra; 
    } 
}

char lower(char letra) { 
    int indice = -1; // Inicializar el índice con un valor que indique "no encontrado" 
    char Abecedario[2][27] = { 
        // mayus     
        {'A','B','C','D','E','F','G','H','I','J','K','L',
        'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, 

        // minus  
        {'a','b','c','d','e','f','g','h','i','j','k','l',
        'm','n','o','p','q','r','s','t','u','v','w','x','y','z'} 
    }; 

    for (int i = 0; i < 27; i++) { 
        if (Abecedario[0][i] == letra) { 
            indice = i; 
            break; 
        } 
    } 

    if (indice != -1) { 
        return Abecedario[1][indice]; 
    } else { 
        // La letra no se encontró en el arreglo 
        // Devolver la misma letra 
        return letra; 
    } 
} 

//Funcion lenght - saber la  longitud de una cadena
int lenght(string& str){
    int cont = 0;
    while(str[cont] != '\0'){ //"\0" --representa caracter nulo
        cont +=1;
    }
    return cont;
}

#endif