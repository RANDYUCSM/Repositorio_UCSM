class Productos:
    def __init__(self,nombre,codigo,cant):
        self.__nombre=nombre
        self.__codigo=codigo
        self.__cantidad=cant
    def __del__(self):
        pass
    
    def getNombre(self):
        return self.__nombre
    def getCodigo(self):
        return self.__codigo
    def getCantidad(self):
        return self.__cantidad
    
    def setNombre(self,n):
        self.__nombre=n
    def setCodigo(self,c):
        self.__codigo=c
    def setCantidad(self,cant):
        self.__cantidad=cant

class Tienda:
    def __init__(self,prod):
        self.__producto=prod
    def __del__(self):
        pass
    def Mostrar(self):
        print("El producto es",self.__producto.getNombre(),"con codigo",self.__producto.getCodigo())
        print("Stock:",self.__producto.getCantidad())
    def IngresarProducto(self):
        nombre=input("Ingrese el nombre del producto ")
        codigo=int(input("Ingres el codigo del producto "))
        cantidad=int(input("Ingrese la cantidad que ingresa del producto "))
        self.__producto.setNombre(nombre)
        self.__producto.setCodigo(codigo)
        self.__producto.setCantidad(cantidad)
if __name__=="__main__":
    producto=Productos("Atun",132,42)
    tienda=Tienda(producto)
    while True:
        print("*********************")
        print("Ingrese una opcion: \n1.Ingresar productos\n2.Mostrar\n3.Salir")
        print("*********************")
        opcion=int(input())
        if opcion==1:
            tienda.IngresarProducto()
        elif opcion==2:
            tienda.Mostrar()
        elif opcion==3:
            break
        else:
            print("Opcion invalida")
    
    del producto
    del tienda
