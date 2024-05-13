#include <iostream>
using namespace std;

class Pata_Madre;
class Cascarones;
class Patito_feo;
class Patos_hijos;
class Animales;
class Mujer;
class Marido_mujer;
class Cisne_Anciano;
class Cisnes;

class Pata_Madre{
    public:
    void Empollar(){
        cout<<"Pata Empollando huevos..."<<endl;
    }
    void Hablar(int text){
        if (text==1){
            cout<<"Pata:Seria ideal que hoy nacieran mis hijos"<<endl;
        }
        else if (text==2){
            cout<<"Pata:Pero que preciosos hijos mios"<<endl;
        }
        else if(text==3){
            cout<<"Pata:Mami?... Tu no puedes ser mi hijo!, vete de aqui impostor"<<endl;
        }
    }
    void Espantar(){
        cout<<"Pata madre espantanda"<<endl;
    }

};
class Cascarones{
    public:
    void Romperse(){
        cout<<"Cascarones rompiendose..."<<endl;
    }

};
class Patito_feo{
    public:
    const string nombre="patito feo";
    void Romper_cascaron(){
        cout<<"Patito feo rompiendo cascaron"<<endl;
    }
    void Hablar(int text){
        if (text==1){
            cout<<"Pf:Mami, mami!"<<endl;
        }
        else if(text==2){
            cout<<"Pf:sería posible quedarme aqui unos días? Necesito comida y un techo bajo el que vivir."<<endl;
        }
        else if(text==3){
            cout<<"Pf:Hola! Puedo darme un chapuzon en vuestra laguna? Llevo dias caminando y necesito refrescarme un poco."<<endl;
        }
        else if(text==4){
            cout<<"Pf:Uno de los vuestros? No entiendo…"<<endl;
        }
    }
    void Caminar(int text){
        if (text==1){
            cout<<"Patito feo caminando..."<<endl;
        }
        else if(text==2){
            cout<<"Patito feo deambulando..."<<endl;
        }
        else if(text==3){
            cout<<"Patito feo caminando...(Durante 15 dias)"<<endl;
        }
    }
    void Detener(int text){
        if (text==1){
            cout<<"Patito feo llego a una granja"<<endl;
        }
        else if(text==2){
            cout<<"Patito feo llego a una laguna de aguas cristalinas..."<<endl;
        }
    }
    void Pensar(int text){
        if (text==1){
            cout<<"Patito feo pensando: podria encontrar cobijo, aunque fuera durante una temporada."<<endl;
        }
        else if(text==2){
            cout<<"Patito feo pensando: Ya no era un pato gordo y chato, sino que en los ultimos dias se había transformado en un hermoso cisne negro de largo cuello y bello plumaje."<<endl;
        }
        else if(text==3){
            cout<<"Patito feo comprendio que nunca habia sido un patito feo, sino que había nacido cisne y ahora lucía en todo su esplendor."<<endl;
        }
        
    }
    void Escucha(){
        cout<<"Patito feo escuchando..."<<endl;
    }
    void Correr(){
        cout<<"Patito feo corriendo..."<<endl;
    }
    void Comer(){
        cout<<"Patito feo comiendo..."<<endl;
    }
    void Observar(){
        cout<<"Patito feo observo una familia de preciosos cisnes. Unos eran blancos, otros negros, pero todos esbeltos y majestuosos."<<endl;
    }
    void Inclinarse(){
        cout<<"Patito feo inclinandose a la orilla..."<<endl;
    }
    void Salta(){
        cout<<"Patito feo saltando de alegria..."<<endl;
    }
    void Sentir(){
        cout<<"Patito feo se sentia feliz"<<endl;
    }
    void Nadar(){
        cout<<"Patito feo se metio en la laguna y compartio el paseo con aquellos que le querian de verdad"<<endl;
    }

};
class Patos_hijos{
    public:
    void Burlarse(){
        cout<<"Patos hijos burlandose del patito feo"<<endl;
    }

};
class Animales{
    public:
    void Rechazar(Patito_feo &patito){
        cout<<"Animales rechazan al "<<patito.nombre<<endl;
    }
};
class Mujer{
    public:
    void Habla(){
        cout<<"Mujer:Has visto como ha engordado ese pato? Ya está bastante grande y lustroso. ¡Creo que ha llegado la hora de que nos lo comamos!"<<endl;
    }
    void Barriendo(){
        cout<<"Mujer barriendo..."<<endl;
    }
    void AceptaPropuesta(){
        cout<<"Mujer acepta propuesta"<<endl;
    }

};
class Marido{
    public:
    void Escucha(){
        cout<<"Marido escuchando..."<<endl;
    }

};
class Cisne_Anciano{
    public:
    void Hablar(int text){
        if (text==1){
            cout<<"CisneA:Claro que si! Aqui eres bienvenido. Eres uno de los nuestros!"<<endl;
        }
        else if(text==2){
            cout<<"CisneA:Si, uno de los nuestros. Acaso no conoces tu propio aspecto? Agachate y mírate en el agua. Hoy esta tan limpia que parece un espejo."<<endl;
        }

    }
};
class Cisnes{
    public:
    void Hablar(){
        cout<<"Cisnes:Unete a nosotros, A partir de ahora, te cuidaremos y seras uno mas de nuestro clan."<<endl;
    }
};
int main(){
    Pata_Madre pata;
    Cascarones cascaron;
    Patito_feo patitof;
    Patos_hijos patosh;
    Animales animales;
    Mujer mujer;
    Marido marido;
    Cisne_Anciano cisnea;
    Cisnes cisnes;
    pata.Empollar();
    pata.Hablar(1);
    cascaron.Romperse();
    pata.Hablar(2);
    patitof.Romper_cascaron();
    patitof.Hablar(1);
    pata.Espantar();
    pata.Hablar(3);
    patitof.Caminar(1);
    patosh.Burlarse();
    patitof.Caminar(2);
    animales.Rechazar(patitof);
    patitof.Detener(1);
    mujer.Barriendo();
    patitof.Pensar(1);
    patitof.Hablar(2);
    mujer.AceptaPropuesta();
    mujer.Habla();
    marido.Escucha();
    patitof.Escucha();
    patitof.Correr();
    patitof.Caminar(3);
    patitof.Comer();
    patitof.Detener(2);
    patitof.Observar();
    patitof.Hablar(3);
    cisnea.Hablar(1);
    patitof.Hablar(4);
    cisnea.Hablar(2);
    patitof.Inclinarse();
    patitof.Pensar(2);
    patitof.Salta();
    patitof.Pensar(3);
    cisnes.Hablar();
    patitof.Sentir();
    patitof.Nadar();

}
