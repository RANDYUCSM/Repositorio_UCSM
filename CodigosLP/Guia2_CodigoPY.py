#Ejercicio 1
import time

class Auto:
    def __init__(self):
        self.velocidadA = 5
        self.velocidadPC = 0
        self.contador = 5

    def setVelocidadPC(self, vel):
        self.velocidadPC = vel

    def getVelocidadA(self):
        return self.velocidadA

    def getVelocidadPC(self):
        return self.velocidadPC

    def aumentarVelocidad(self):
        self.velocidadA += 5
        self.contador -= 1.5
        print("Avanzando...")
        time.sleep(self.contador)

class Carrera:
    def __init__(self):
        self.autos = Auto()
        self.distanciaC = 0
        self.distanciaPC = 0
        self.dificultad = 0
        self.opcionvel = ""

    def simularCarrera(self):
        self.distanciaC = 0
        self.distanciaPC = 0

        if self.dificultad == 1:
            self.autos.setVelocidadPC(20)
        elif self.dificultad == 2:
            self.autos.setVelocidadPC(30)
        elif self.dificultad == 3:
            self.autos.setVelocidadPC(40)

        while self.distanciaC <= 100 and self.distanciaPC <= 100:
            self.distanciaC += self.autos.getVelocidadA()
            print("Desea aumentar la velocidad? s/n")
            self.opcionvel = input()
            if self.opcionvel.lower() == "s":
                self.autos.aumentarVelocidad()
            else:
                print("Avanzando...")
                time.sleep(self.autos.contador)

            self.distanciaPC += self.autos.getVelocidadPC()
            self.distanciaC += self.autos.getVelocidadA()

            if self.distanciaC >= 100:
                print("¡Ganaste!")
                break
            elif self.distanciaPC >= 100:
                print("¡Ganó la computadora!")
                break

            print("Tu carro está", self.distanciaC, "/100")
            print("La computadora está", self.distanciaPC, "/100")

    def cambiarDificultad(self):
        print("Ingrese el nivel de dificultad:")
        print("1. Fácil")
        print("2. Medio")
        print("3. Difícil")
        self.dificultad = int(input())

if __name__ == "__main__":
    carrera = Carrera()
    carrera.cambiarDificultad()
    carrera.simularCarrera()
#Ejercicio 2
class Inventario:
    def _init_(self):
        self.listaProductosDisponible = ["cebolla", "papa", "arroz", "azucar"]
        self.listaProductosAgotados = ["ajo", "zanahoria", "brocoli", "atun", "pollo"]
        self.listaPedidos = []
        self.numproductosdisponibles = 4

    def AgregarProductos(self):
        cantidadProductos = int(input("¿Cuántos productos desea agregar? "))
        for _ in range(cantidadProductos):
            nuevo_producto = input("Ingrese el nombre del producto: ")
            self.listaProductosDisponible.append(nuevo_producto)
        self.numproductosdisponibles += cantidadProductos

    def EliminarProductos(self, producto):
        if producto in self.listaProductosDisponible:
            self.listaProductosDisponible.remove(producto)
            self.numproductosdisponibles -= 1
            print(f"Producto {producto} eliminado.")
        else:
            print("Producto no encontrado en la lista.")

    def ActualizarProductosD(self):
        print("Los productos disponibles son:")
        for producto in self.listaProductosDisponible:
            print(producto, end=" ")
        print()

    def ActualizarProductosA(self):
        print("Los productos agotados son:", end=" ")
        for agotado in self.listaProductosAgotados:
            print(agotado, end=" ")
        print()

    def RealizarPedido(self):
        contador = 0
        print("Ingrese los 4 productos disponibles a pedir:")
        while contador < 4:
            prod = input()
            if prod in self.listaProductosDisponible:
                self.listaPedidos.append(prod)
                contador += 1

    def FacturasCliente(self):
        total = len(self.listaPedidos) * 8
        print(f"El precio total de los pedidos es S/{total}")

if _name_ == "_main_":
    inventario = Inventario()

    while True:
        print("¿Qué operación desea hacer?")
        print("1. Agregar productos")
        print("2. Mostrar productos disponibles")
        print("3. Eliminar productos")
        print("4. Realizar pedido")
        print("5. Generar factura")
        print("6. Salir")
        opc = int(input())

        if opc == 1:
            inventario.AgregarProductos()
        elif opc == 2:
            inventario.ActualizarProductosD()
        elif opc == 3:
            eliminar = input("¿Qué producto desea eliminar? ")
            inventario.EliminarProductos(eliminar)
        elif opc == 4:
            inventario.RealizarPedido()
        elif opc == 5:
            inventario.FacturasCliente()
        elif opc == 6:
            break

#Ejercicio 3
class Avion:
    def __init__(self, dest, duracion, tripulacion, combustible):
        self.destino = dest
        self.duracionMision = duracion
        self.tripulacionNecesaria = tripulacion
        self.combustibleActual = combustible

    def simularMision(self):
        if self.combustibleActual >= self.duracionMision * 10:
            print(f"La misión hacia {self.destino} ha sido completada con éxito.")
        else:
            print(f"El avión no tiene suficiente combustible para completar la misión hacia {self.destino}.")

if __name__ == "__main__":
    destino = input("Bienvenido al Programa de Simulación de Vuelo\nIngrese el destino de la misión: ")
    duracionMision = int(input("Ingrese la duración estimada de la misión en horas: "))
    tripulacionNecesaria = int(input("Ingrese la cantidad de tripulación necesaria para la misión: "))
    combustibleActual = int(input("Ingrese la cantidad de combustible actual del avión en litros: "))

    avion = Avion(destino, duracionMision, tripulacionNecesaria, combustibleActual)
    avion.simularMision()
