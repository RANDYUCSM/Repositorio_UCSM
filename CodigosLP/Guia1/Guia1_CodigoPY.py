class Producto:
    def __init__(self, cantidad):
        self.cantidad = cantidad

class Pedido:
    def __init__(self):
        self.d2 = {}

    def ingresar_pedido(self, prod, cant, d1):
        if prod in d1:
            if d1[prod].cantidad >= cant:
                self.d2[prod] = cant
                print("Pedido registrado correctamente.")
            else:
                print("No hay suficiente stock para el producto.")
        else:
            print("El producto no está registrado en el inventario.")

    def mostrar_pedidos(self):
        print("Pedidos en curso:")
        for producto, cantidad in self.d2.items():
            print(producto, cantidad)

    def notificar_cliente(self, d1):
        if self.d2:
            for producto, cantidad in self.d2.items():
                d1[producto].cantidad -= cantidad
            self.d2.clear()
            print("El cliente ha sido notificado.")
        else:
            print("No hay pedidos en curso")
if __name__ == "__main__":
    d1 = {}

    while True:
        print("----------------------")
        print("1. Registrar productos\n2. Registro de pedidos\n3. Inventario\n4. Salir")
        print("----------------------")
        opcion = int(input("Ingrese su opción: "))

        if opcion == 1:
            nombre = input("Ingrese el nombre del producto: ")
            cantidad = int(input("Ingrese la cantidad disponible: "))
            producto = Producto(cantidad)
            d1[nombre] = producto
        
        elif opcion == 2:
            pedido = Pedido()
            while True:
                print("----------------------")
                print("1. Ingresar pedido\n2. Pedidos en curso\n3. Notificar al cliente\n4. Volver al menú principal")
                print("----------------------")
                opc = int(input("Ingrese su opción: "))
                if opc == 1:
                    prod = input("Ingrese el nombre del producto: ")
                    cant = int(input("Ingrese la cantidad del pedido: "))
                    pedido.ingresar_pedido(prod, cant, d1)
                elif opc == 2:
                    pedido.mostrar_pedidos()
                elif opc == 3:
                    pedido.notificar_cliente(d1)
                elif opc == 4:
                    break
        
        elif opcion == 3:
            print("Inventario:")
            for producto, obj_producto in d1.items():
                print(producto,":",obj_producto.cantidad)
        
        elif opcion == 4:
            break

