#include <iostream>
#include <vector>
using namespace std;

class Material{
    protected:
        vector <string> Libros;
        vector <string> Revistas;
        vector <string> DVDs;
    public:
        Material()
        virtual void mostrarDetalles()=0;
};
class Libros: Material{
    private:
        string titulo;
        string autor;
        int codigo;
    public:
        void mostrarDetalles(){
            cout<<"Titulo:"<<titulo<<endl;
            cout<<"Autor:"<<autor<<endl;
            cout<<"Codigo:"<<codigo<<endl;
        }
};
int main(){

    return 0;
}
