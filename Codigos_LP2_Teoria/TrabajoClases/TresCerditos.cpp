#include <iostream>
#include <string>

using namespace std;

class Casa{
    public:
        //Atributos
        string material;
        //Constructor
        Casa(string material){this->material = material;}
        //Metodos:
        void cae(){
            if(this->material != "Ladrillo"){
                cout<<"La casa de "<<this->material<<" se cae..."<<endl;
            }else{
                cout<<"La casa de "<<this->material<<" no se cae..."<<endl;
            }
        }
};
class Chimenea{
    public: 
        string material;
        Chimenea(string material){this->material = material;}
};

class Cerdo{
    public:
        string nombre;
        //Constructor
        Cerdo(string nombre){this->nombre = nombre;}
        //Metodos:
        void construye(Casa& casa){
            cout<<"El cerdito "<<this->nombre<<" esta construyendo la casa de "<<casa.material<<"..."<<endl;
        }
        void construye(Chimenea& chimenea){
            cout<<"El cerdito "<<this->nombre<<" esta construyendo la chimenea de "<<chimenea.material<<"..."<<endl;
        }
        void calienta(){
            cout<<"El cerdito pone a hervir la olla de agua..."<<endl;
        }
};

class Lobo{
    public:
        //Metodos:
        void soplar(Casa& casa){
            cout<<"El lobo sopla y sopla la casa de "<<casa.material<<"..."<<endl;
            if (casa.material == "Ladrillo"){
                casa.cae();
            }
        }
        void come(Cerdo& cerdo){
            cout<<"El lobo devora al cerdito "<<cerdo.nombre<<"..."<<endl;
        }
        void trepar(Chimenea& chimenea){
            cout<<"El lobo trepa por la chimenea de "<<chimenea.material<<"..."<<endl;
        }
        void caerDentro(){
            cout<<"El lobo cae dentro de la olla de agua..."<<endl;
        }
        void muere(){
            cout<<"El lobo muere..."<<endl;
        }
};

class Olla{
    public:
        void hierve(){
            cout<<"...Olla de agua hirviendo..."<<endl;
        }
};

int main(){

    //Objetos:
    Lobo lobo_malvado;
    Cerdo cerdito1("flautista");
    Cerdo cerdito2("Violinista");
    Cerdo cerdito3("Constructor");
    Casa C_Paja("Paja");
    Casa C_Madera("Madera");
    Casa C_Ladrillo("Ladrillo");
    Chimenea Chimenea("Ladrillo");
    Olla Olla_Agua;

    //Historia
    //---------------------------------
    cerdito1.construye(C_Paja);
    lobo_malvado.soplar(C_Paja);
    C_Paja.cae();
    lobo_malvado.come(cerdito1);
    //---------------------------------
    cerdito2.construye(C_Madera);
    lobo_malvado.soplar(C_Madera);
    C_Madera.cae();
    lobo_malvado.come(cerdito2);
    //---------------------------------
    cerdito3.construye(C_Ladrillo);
    cerdito3.construye(Chimenea);
    lobo_malvado.soplar(C_Ladrillo);
    cerdito3.calienta();
    Olla_Agua.hierve();
    lobo_malvado.trepar(Chimenea);
    lobo_malvado.caerDentro();
    lobo_malvado.muere();
    //---------------------------------
    return 0;
}
