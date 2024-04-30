//ARCHVIVO PRODUCTO
class Producto:
    def __init__(self, nombre, precio, cantidad):
        self.nombre = nombre
        self.precio = precio
        self.cantidad = cantidad

    def mostrarDetalles(self):
        print("Nombre:", self.nombre)
        print("Precio:", self.precio)
        print("Cantidad:", self.cantidad)
      //ARCHIVO TIENDA
  from Producto import Producto

class Tienda:
    def __init__(self):
        self.productos = []

    def agregarProducto(self, nombre, precio, cantidad):
        producto = Producto(nombre, precio, cantidad)
        self.productos.append(producto)

    def mostrarProductos(self):
        for i, producto in enumerate(self.productos, 1):
            print("Producto", i)
            producto.mostrarDetalles()
  //MAIN DEL PROGAMA
from Tienda import Tienda

def main():
    tienda = Tienda()

    while True:
        print("1. Agregar producto")
        print("2. Mostrar productos")
        print("3. Salir")
        opcion = input("Ingrese una opción: ")

        if opcion == "1":
            nombre = input("Ingrese el nombre del producto: ")
            precio = float(input("Ingrese el precio del producto: "))
            cantidad = int(input("Ingrese la cantidad del producto: "))
            tienda.agregarProducto(nombre, precio, cantidad)
        elif opcion == "2":
            tienda.mostrarProductos()
        elif opcion == "3":
            print("Saliendo del programa.")
            break
        else:
            print("Opción no válida.")

if __name__ == "__main__":
    main()

