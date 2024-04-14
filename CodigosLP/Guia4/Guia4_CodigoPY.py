#Ejercicio 1

#Ejercicio 2
class Proveedor:
    def __init__(self, nombre):
        self.nombre = nombre

    def get_nombre(self):
        return self.nombre


class Cliente:
    def __init__(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.compras_realizadas = []
        self.pagos_realizados = []

    def get_nombre(self):
        return self.nombre

    def get_direccion(self):
        return self.direccion

    def get_telefono(self):
        return self.telefono

    def agregar_compra(self, compra):
        self.compras_realizadas.append(compra)

    def agregar_pago(self, pago):
        self.pagos_realizados.append(pago)

    def mostrar_info_cliente(self):
        print("Nombre:", self.nombre)
        print("Dirección:", self.direccion)
        print("Teléfono:", self.telefono)
        print("Compras Realizadas:")
        for compra in self.compras_realizadas:
            print("---- Producto:", compra.get_producto_asociado().get_descripcion())
            print("---- Cantidad:", compra.get_cantidad())
            print("---- Precio unitario:", compra.get_producto_asociado().get_precio())
            print("---- Fecha:", compra.get_venta_asociada().get_fecha())
        print("Pagos:")
        for pago in self.pagos_realizados:
            print(pago.get_monto())


class Producto:
    def __init__(self, codigo, descripcion, precio, proveedor):
        self.codigo = codigo
        self.descripcion = descripcion
        self.precio = precio
        self.proveedor_asociado = proveedor

    def get_codigo(self):
        return self.codigo

    def get_descripcion(self):
        return self.descripcion

    def get_precio(self):
        return self.precio

    def get_proveedor(self):
        return self.proveedor_asociado


class Venta:
    def __init__(self, num_factura, fecha, cliente):
        self.num_factura = num_factura
        self.fecha = fecha
        self.cliente_asociado = cliente
        self.productos_vendidos = []

    def get_num_factura(self):
        return self.num_factura

    def get_fecha(self):
        return self.fecha

    def get_cliente(self):
        return self.cliente_asociado

    def agregar_producto(self, producto):
        self.productos_vendidos.append(producto)

    def mostrar_info_venta(self):
        print("-----------------------------------------")
        print("Número de factura:", self.num_factura)
        print("Fecha:", self.fecha)
        print("Cliente:", self.cliente_asociado.get_nombre())
        print("Descripción:")
        for producto in self.productos_vendidos:
            print(producto.get_descripcion())
        print("-----------------------------------------")


class Compra:
    def __init__(self, cliente, producto, venta, cantidad):
        self.cliente_asociado = cliente
        self.producto_asociado = producto
        self.venta_asociada = venta
        self.cant_comprada = cantidad

    def get_cliente_asociado(self):
        return self.cliente_asociado

    def get_producto_asociado(self):
        return self.producto_asociado

    def get_venta_asociada(self):
        return self.venta_asociada

    def get_cantidad(self):
        return self.cant_comprada


class Pago:
    def __init__(self, cliente, monto, fecha_pago):
        self.cliente_asociado = cliente
        self.monto = monto
        self.fecha_pago = fecha_pago

    def get_cliente(self):
        return self.cliente_asociado

    def get_monto(self):
        return self.monto

    def get_fecha_pago(self):
        return self.fecha_pago


# Objetos
proveedor = Proveedor("Nombre_prov1")
producto = Producto(1234, "Pantalon", 100, proveedor)
cliente = Cliente("Mario", "Direc_prueba", 123456789)
venta = Venta("A123", "Fecha_prueba", cliente)
compra = Compra(cliente, producto, venta, 2)
pago = Pago(cliente, 200, "Fecha_prueba")

# Agregar compra y pago
cliente.agregar_compra(compra)
cliente.agregar_pago(pago)
venta.agregar_producto(producto)

# Mostrar información
cliente.mostrar_info_cliente()
venta.mostrar_info_venta()

#Ejercicio 3
import collections

class Autor:
    def __init__(self, nombre, nacionalidad, libros_escritos=["Don Quijote de l mancha"]):
        self.nombre = nombre
        self.nacionalidad = nacionalidad
        self.libros_escritos = libros_escritos

    def ingresar_libros_escritos(self):
        titulo_libro = input("Ingrese la lista de libros escritos por el autor: ")
        self.libros_escritos.append(titulo_libro)
        opcion = input("Seguir ingresando? (S/N): ")
        while opcion != "n" and opcion != "N":
            titulo_libro = input("Ingrese la lista de libros escritos por el autor: ")
            self.libros_escritos.append(titulo_libro)
            opcion = input("Seguir ingresando? (S/N): ")

    def get_nombre(self):
        return self.nombre

    def get_nacionalidad(self):
        return self.nacionalidad

    def get_libros_escritos(self):
        return self.libros_escritos

class Libros:
    def __init__(self, titulo, ISBN, año_publicacion, cantidad_ejemplares):
        self.titulo = titulo
        self.ISBN = ISBN
        self.año_publicacion = año_publicacion
        self.cantidad_ejemplares = cantidad_ejemplares
        self.autor = None

    def get_titulo(self):
        return self.titulo

    def get_ISBN(self):
        return self.ISBN

    def get_año_publicacion(self):
        return self.año_publicacion

    def get_cantidad_ejemplares(self):
        return self.cantidad_ejemplares

    def set_autor(self, autor):
        self.autor = autor

    def get_autor(self):
        return self.autor

class Usuarios:
    def __init__(self, nombre, direccion, numero_telefono, libros_prestados=["Don Quijote de la Mancha"]):
        self.nombre = nombre
        self.direccion = direccion
        self.numero_telefono = numero_telefono
        self.libros_prestados = libros_prestados

    def ingresar_libros_pedidos(self):
        prestado = input("Ingrese la lista de libros prestados: ")
        self.libros_prestados.append(prestado)
        opcion = input("Seguir ingresando? (S/N): ")
        while opcion != "n" and opcion != "N":
            prestado = input("Ingrese la lista de libros prestados: ")
            self.libros_prestados.append(prestado)
            opcion = input("Seguir ingresando? (S/N): ")

    def get_nombre(self):
        return self.nombre

    def get_direccion(self):
        return self.direccion

    def get_numero_telefono(self):
        return self.numero_telefono

    def get_libros_prestados(self):
        return self.libros_prestados

class Biblioteca:
    def __init__(self, autor, libro, usuario):
        self.autor = autor
        self.libro = libro
        self.usuario = usuario

    def mostrar_datos_autor(self):
        print("Informacion del autor ")
        print("Nombre: ", self.autor.get_nombre())
        print("Nacionalidad: ", self.autor.get_nacionalidad())
        print("Libros escritos: ", ", ".join(self.autor.get_libros_escritos()))

    def mostrar_datos_usuario(self):
        print("Informacion del usuario ")
        print("Nombre: ", self.usuario.get_nombre())
        print("Direccion: ", self.usuario.get_direccion())
        print("Numero de telefono: ", self.usuario.get_numero_telefono())
        print("Libros prestados: ", ", ".join(self.usuario.get_libros_prestados()))

    def mostrar_datos_libro(self):
        print("Informacion del libro ")
        print("Titulo: ", self.libro.get_titulo())
        print("ISBN: ", self.libro.get_ISBN())
        print("Año de publicacion: ", self.libro.get_año_publicacion())
        print("Cantidad de elemplares: ", self.libro.get_cantidad_ejemplares())

if __name__ == "__main__":
    nombre = Autor("", "")
    nombre.ingresar_libros_escritos()
    nombre1 = Autor("Jesus", "Peru", nombre.get_libros_escritos())
    libro1 = Libros("tituloo", 12342131, 2024, 13)
    usuario = Usuarios("", "", 923214131)
    usuario.ingresar_libros_pedidos()
    usuario1 = Usuarios("Jesus", "Jorge chavez", 923214131, usuario.get_libros_prestados())
    biblioteca = Biblioteca(nombre1, libro1, usuario1)
    biblioteca.mostrar_datos_autor()
    biblioteca.mostrar_datos_libro()
    biblioteca.mostrar_datos_usuario()
