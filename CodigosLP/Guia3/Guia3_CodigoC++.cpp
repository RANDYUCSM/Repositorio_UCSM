
//Actividad 5:
class ITareas{ //Interfaz para la clase Tareas
    public:
    virtual void CrearTarea(string t)=0;    //Metodo virtual
};
class IAsignar{   //Interfaz para la clase Asignar
    public:
    virtual void AsignarTarea(string t)=0;  //Metodo virtual
};
class IEstablecerFechaLimite{   //Interfaz para la clase EstablecerFechaLimite
    public:
    virtual void EstablecerFechaLimite(int h, int m)=0;     //Metodo virtual
};
class ISeguimientoProgreso{     //Interfaz para la clase SeguimientoProgreso
    public:
    virtual void SeguimientoProgreso(string t)=0;   //Metodo virtual
};

class Tareas:public ITareas{    //Clase Tareas que implementa la interfaz ITareas
    public:
    void CrearTarea(string t){  //Metodo para crear una tarea
        cout<<"Se creo la tarea "<<t<<endl;
    }
};
class Asignar:public IAsignar{  //Clase Asignar que implementa la interfaz IAsignar
    public:
    void AsignarTarea(string t){    //Metodo para crear una asignar una tarea
        cout<<"Se asigno la tarea "<<t<<endl;
    }
};
class Establecer:public IEstablecerFechaLimite{     //Clase Establecer que implementa la interfaz IEstablecerFechaLimite
    public:
    void EstablecerFechaLimite(int h,int m){    //Metodo para establecer las horas y minutos 
        cout<<"Se establecio la fecha limite dentro de las "<<h<<":"<<m<<endl;
    }
};
class Seguimiento:public ISeguimientoProgreso{      //Clase Seguimiento que implementa la interfaz ISeguimientoProgreso
    int progreso=0;
    public:
    void SeguimientoProgreso(string t){     //Metodo para ver el progreso en %
        if (progreso<100){
            progreso+=5;
            cout<<"El progreso de la tarea "<<t<<" es de "<<progreso<<"%"<<endl;

        }
        else{
            cout<<"Se completó la tarea"<<endl;
        }
    }
};

class GestionarTareas{      //Esta clase depende de todas las interfaces creadas
    private:
    ITareas* tarea;     //Se crea atributos que son objetos de las interfaces que sirven como punteros
    IAsignar* asignar;
    IEstablecerFechaLimite* establecer;
    ISeguimientoProgreso* seguimiento;
    public:
    //Metodo constructor
    GestionarTareas(ITareas* tarea,IAsignar* asignar,IEstablecerFechaLimite* establecer,ISeguimientoProgreso* seguimiento) : tarea(tarea), asignar(asignar),establecer(establecer), seguimiento(seguimiento) {}
    void CrearTarea(string nombre){     //Metodo para llamar al metodo de la clase Tarea por medio de la interfaz ITarea
        tarea->CrearTarea(nombre);       //Lo mismo que decir objeto.(metodo)
    }
    void AsignarTarea(string nombre){   //Metodo para llamar al metodo de la clase Asignar por medio de la interfaz IAsignar
        asignar->AsignarTarea(nombre);
    }
    void EstablecerFechaLimite(int hora,int minutos){    //Metodo para llamar al metodo de la clase Establecer por medio de la interfaz IEstablecerFechaLimite
        establecer->EstablecerFechaLimite(hora,minutos);
    }
    void SeguimientoProgreso(string nombre){    //Metodo para llamar al metodo de la clase Seguimiento por medio de la interfaz ISeguimientoProgreso
        seguimiento->SeguimientoProgreso(nombre);   //Lo mismo que decir objeto.(metodo)
    }
};

int main(){
    int opcion=0;
    string nombre;
    int hora,minutos;
    Tareas tarea;   //Se crean objetos para enviar su direccion a la clase GestionarTareas
    Asignar asignar;
    Establecer establecer;
    Seguimiento seguimiento;
    GestionarTareas gestionar(&tarea,&asignar,&establecer,&seguimiento);    //Se envian las direcciones de memoria
    while (opcion!=5){  
        cout<<"______________________________"<<endl;   //Menu de interaccion
        cout<<"|     Que desea hacer?        |"<<endl;
        cout<<"|1.Crear una tarea            |"<<endl;
        cout<<"|2.Asignar tarea              |"<<endl;
        cout<<"|3.Establecer la fecha limite |"<<endl;
        cout<<"|4.Seguimiento del proceso    |"<<endl;
        cout<<"|5.Salir                      |"<<endl;
        cout<<"|_____________________________|"<<endl;
        cin>>opcion;
        while(opcion<1 or opcion>5){
            cout<<"Ingrese una opcion valida "<<endl;
            cin>>opcion;
        }
        if (opcion==1){
            cout<<"Ingrese el nombre de la tarea"<<endl;
            cin>>nombre;
            gestionar.CrearTarea(nombre);   //Se llama a los metodos de la clase GestionarTareas y se envia un nombre
        }
        else if(opcion==2){
            cout<<"Ingrese el nombre de la tarea"<<endl;
            cin>>nombre;
            gestionar.AsignarTarea(nombre);     //Se llama a los metodos de la clase GestionarTareas
        }
        else if(opcion==3){
            cout<<"Ingrese las horas y minutos"<<endl;
            cin>>hora;
            cin>>minutos;
            gestionar.EstablecerFechaLimite(hora,minutos);  //Se llama a los metodos de la clase GestionarTareas y se envia la hora y minutos 
        }
        else if(opcion==4){
            cout<<"Ingrese el nombre de la tarea"<<endl;
            cin>>nombre;
            gestionar.SeguimientoProgreso(nombre);  //Se llama a los metodos de la clase GestionarTareas
        }
    }
}
