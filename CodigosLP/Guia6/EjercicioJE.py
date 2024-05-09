class Alumno:
    def __init__(self, n, e, p):
        self.__nombre = n
        self.__edad = e
        self.__promedio = p
        
    def __str__(self):
        return f"Nombre: {self.__nombre}, edad: {self.__edad}, promedio: {self.__promedio}"
    def __lt__(self,other):
        return self.__promedio<other.__promedio
    def getPromedio(self):
        return self.__promedio
    def getNombre(self):
        return self.__nombre
    def getEdad(self):
        return self.__edad
class Grupo:
    __cantidad = 0
    __arrayalumnos = []
    def __init__(self,cant):
        Grupo.__arrayalumnos=[]
    def __str__(self):
        return f"Hay {self.__cantidad} alumnos"
    def Agregar_alumno(self,nombre,edad,prom):
        alumno=Alumno(nombre,edad,prom)
        Grupo.__arrayalumnos.append(alumno)
        Grupo.__cantidad += 1
    def Ordenar_por_promedio(self):
        Grupo.__arrayalumnos.sort(key=lambda x:x.getPromedio())
    def Promedio_grupo(self):
        conteo=0
        acumulador=0
        for x in range(len(Grupo.__arrayalumnos)):
            acumulador+=Grupo.__arrayalumnos[x].getPromedio()
            conteo=conteo+1
        print(f"El promedio total de los alumnos es: {acumulador/conteo}")
    def Mejor_promedio(self):
        mayor=0
        for x in Grupo.__arrayalumnos:
            if x._Alumno__promedio>mayor:
                mayor=x._Alumno__promedio
        for y in Grupo.__arrayalumnos:
            if y._Alumno__promedio==mayor:
                print("El mejor promedio es de",end=": ")
                return y
            
    

if __name__ == "__main__":
    grupo = Grupo(5)
    alumno1 = Alumno("Jesus", 20, 15)
    alumno2 = Alumno("Carlos", 19, 16)
    alumno3 = Alumno("Juan", 20, 17)
    alumno4 = Alumno("Matias", 19, 12)
    alumno5 = Alumno("Alberto", 19, 20)

    grupo.Agregar_alumno(alumno1._Alumno__nombre,alumno1.getEdad,alumno1._Alumno__promedio)
    grupo.Agregar_alumno(alumno2.getNombre,alumno2._Alumno__edad,alumno2._Alumno__promedio)
    grupo.Agregar_alumno(alumno3.getNombre,alumno3.getEdad,alumno3._Alumno__promedio)
    grupo.Agregar_alumno(alumno4.getNombre,alumno4.getEdad,alumno4._Alumno__promedio)
    grupo.Agregar_alumno(alumno5._Alumno__nombre,alumno5._Alumno__edad,alumno5._Alumno__promedio)
    print(grupo)
    grupo.Ordenar_por_promedio()
    print(grupo.Promedio_grupo())
    print(grupo.Mejor_promedio())
    
