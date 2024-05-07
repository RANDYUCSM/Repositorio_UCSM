//Actividad 1:
class Estudiante{
    private:
    string nombre;
    int edad;
    int promedio_nota;
    public:
    Estudiante(string n,int e,int p){
        this->nombre=n;
        this->edad=e;
        this->promedio_nota=p;
    }
    string getNombre(){
        return nombre;
    }
    int getNota(){
        return promedio_nota;
    }
};
int main(){
    int cantidad;
    Estudiante estudiante[2]={Estudiante("jesus",21,11),Estudiante("carlos",25,13)};
    if (estudiante[0].getNota()<estudiante[1].getNota()){
        Estudiante est=estudiante[0];
        estudiante[0]=estudiante[1];
        estudiante[1]=est;
    }
    cout<<estudiante[0].getNota()<<" "<<estudiante[1].getNota()<<endl;
    cin>>cantidad;
    Estudiante** estudiantedina=new Estudiante *[cantidad];
    for (int i=0;i<cantidad;i++){
        estudiantedina[i]=new Estudiante("jose",23,12);
    }
    for (int i=0;i<cantidad;i++){
        cout<<estudiantedina[i]->getNombre()<<endl;
    }
}

//Actividad 2:

