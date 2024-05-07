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
class Banco{
    public:
    static float interes;
    static void cambiar_interes(float i){
        interes=i;
    }
};
float Banco::interes=0.05;

class CuentaB{
    private:
    string nombre;
    float saldo;
    public:
    CuentaB(float s,string n){
        this->saldo=s;
        this->nombre=n;
    }
    void deposito(float d){
        saldo=saldo+d;
    }
    void retiro(float r){
        if (r<saldo){
            saldo-=r;
        }
        else{
            cout<<"Saldo insuficiente"<<endl;
        }
    }
    double calcular_interes(){
        double intereses;
        intereses=saldo*Banco::interes;
        return intereses;
    }

};

int main(){
    Banco banco;
    CuentaB cuenta(1500,"Jesus");
    cuenta.deposito(500);
    cuenta.retiro(3000);
    cout<<cuenta.calcular_interes()<<endl;
    banco.cambiar_interes(0.02);
    cout<<cuenta.calcular_interes()<<endl;
    return 0;
}
//Actividad 4:
class Vector{
    private:
    int x;
    int y;
    public:
    Vector(int,int);
    Vector& operator+(const Vector&);
    Vector& operator-(const Vector&);
    void mostrarAtributos(){
        cout<<"x vale: "<<x<<endl;
        cout<<"y vale: "<<y<<endl;
    }
};

Vector::Vector(int x,int y){
    this->x=x;
    this->y=y;
}

Vector& Vector::operator+(const Vector& v){
    this->x=this->x+v.x;
    this->y=this->y+v.y;
    return *this;
}
Vector& Vector::operator-(const Vector& v){
    this->x=this->x-v.x;
    this->y=this->y-v.y;
    return *this;
}
int main(){
    Vector vector1(3,4);
    Vector vector2(2,7);
    Vector vector3=vector1+vector2;
    vector3.mostrarAtributos();
}

