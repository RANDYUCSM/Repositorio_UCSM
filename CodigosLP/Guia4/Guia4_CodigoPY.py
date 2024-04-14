#Ejercicio 1
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

#Ejercicio 2

class Proveedor:
    def __init__(self, nombre):
        self.nombre = nombre


class Cliente:
    def __init__(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.compras_realizadas = []
        self.pagos_realizados = []

    def agregar_compra(self, compra):
        self.compras_realizadas.append(compra)

    def agregar_pago(self, pago):
        self.pagos_realizados.append(pago)

    def mostrar_info_cliente(self):
        print("Nombre:", self.nombre)
        print("Compras Realizadas:")
        for compra in self.compras_realizadas:
            print("----Productos:", compra.prod_asoc.desc)
            print("----Cantidad:", compra.cantidad)
            print("----Precio unitario:", compra.prod_asoc.precio)
            print("----Fecha:", compra.venta_asoc.fecha)
        print("Pagos:")
        for pago in self.pagos_realizados:
            print(pago.monto)


class Producto:
    def __init__(self, codigo, desc, precio, prov_aso):
        self.codigo = codigo
        self.desc = desc
        self.precio = precio
        self.prov_aso = prov_aso


class Venta:
    def __init__(self, num_fact, fecha, cliente):
        self.num_fact = num_fact
        self.fecha = fecha
        self.cliente_asoc = cliente
        self.productos_vendidos = []

    def agregar_producto(self, producto):
        self.productos_vendidos.append(producto)

    def mostrar_info_venta(self):
        print("---------------------------------------------------------")
        print("Numero de factura:", self.num_fact)
        print("Fecha:", self.fecha)
        print("Cliente:", self.cliente_asoc.nombre)
        print("Descripcion:")
        for producto in self.productos_vendidos:
            print(producto.desc)
        print("---------------------------------------------------------")


class Compra:
    def __init__(self, cliente, producto, venta, cantidad):
        self.cliente_asoc = cliente
        self.prod_asoc = producto
        self.venta_asoc = venta
        self.cantidad = cantidad


class Pago:
    def __init__(self, cliente, monto, fecha_pago):
        self.cliente_aso = cliente
        self.monto = monto
        self.fecha_pago = fecha_pago


# Objetos
prov1 = Proveedor("Nombre_prov1")
prod1 = Producto(1234, "Pantalon", 100, prov1)
cli1 = Cliente("Mario", "Direc_prueba", 123456789)
venta1 = Venta("A123", "Fecha_prueba", cli1)
Comp1 = Compra(cli1, prod1, venta1, 2)
pago1 = Pago(cli1, 200, "Fecha_prueba")

# agregarCompra
cli1.agregar_compra(Comp1)
cli1.agregar_pago(pago1)
venta1.agregar_producto(prod1)

# Mostrar informacion
cli1.mostrar_info_cliente()
venta1.mostrar_info_venta()
//Ejercicio 3
class Profesor:
    def __init__(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.asignaturas = []

    def agregar_asignatura(self, asignatura):
        self.asignaturas.append(asignatura)


class Asignatura:
    def __init__(self, codigo, nombre, descripcion, profesor):
        self.codigo = codigo
        self.nombre = nombre
        self.descripcion = descripcion
        self.profesor = profesor
        self.estudiantes = []

    def agregar_estudiante(self, estudiante):
        self.estudiantes.append(estudiante)


class Estudiante:
    def __init__(self, nombre, direccion, matricula):
        self.nombre = nombre
        self.direccion = direccion
        self.matricula = matricula
        self.asignaturas = []


# Solicitar datos del profesor
nombre_profesor = input("Ingrese el nombre del profesor: ")
direccion_profesor = input("Ingrese la dirección del profesor: ")
telefono_profesor = input("Ingrese el teléfono del profesor: ")

# Crear objeto Profesor
profesor = Profesor(nombre_profesor, direccion_profesor, telefono_profesor)

# Solicitar datos de la asignatura
codigo_asignatura = input("Ingrese el código de la asignatura: ")
nombre_asignatura = input("Ingrese el nombre de la asignatura: ")
descripcion_asignatura = input("Ingrese la descripción de la asignatura: ")

# Crear objeto Asignatura y asociarlo al profesor
asignatura = Asignatura(codigo_asignatura, nombre_asignatura, descripcion_asignatura, profesor)
profesor.agregar_asignatura(asignatura)

# Solicitar datos del estudiante
nombre_estudiante = input("Ingrese el nombre del estudiante: ")
direccion_estudiante = input("Ingrese la dirección del estudiante: ")
matricula_estudiante = input("Ingrese la matrícula del estudiante: ")

# Crear objeto Estudiante
estudiante = Estudiante(nombre_estudiante, direccion_estudiante, matricula_estudiante)

# Agregar la asignatura al estudiante
estudiante.asignaturas.append(asignatura)
asignatura.agregar_estudiante(estudiante)

# Imprimir información
print("\nInformación del profesor:")
print("Nombre:", profesor.nombre)
print("Dirección:", profesor.direccion)
print("Teléfono:", profesor.telefono)

print("\nInformación de la asignatura:")
print("Código:", asignatura.codigo)
print("Nombre:", asignatura.nombre)
print("Descripción:", asignatura.descripcion)
print("Profesor:", asignatura.profesor.nombre)

print("\nInformación del estudiante:")
print("Nombre:", estudiante.nombre)
print("Dirección:", estudiante.direccion)
print("Matrícula:", estudiante.matricula)
print("Asignaturas matriculadas:", [asig.nombre for asig in estudiante.asignaturas])

