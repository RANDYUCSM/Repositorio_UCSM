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
class Circulo{
    private:
    int radio;
    float diametro;
    public:
    Circulo(float d);
    friend void areaCirculo(Circulo&);
};

Circulo::Circulo(float d){
    this->diametro=d;
    this->radio=d/2;
}

void areaCirculo(Circulo& c){
    cout<<"El area del circulo es: "<<3.14*c.radio*c.radio<<endl;
}

int main(){
    Circulo circulo1(10);
    areaCirculo(circulo1);
    Circulo circulo2(20);
    areaCirculo(circulo2);
    return 0;
}

//Actividad 3:

