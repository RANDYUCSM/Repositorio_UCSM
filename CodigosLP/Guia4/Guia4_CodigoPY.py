#Ejercicio 1

#Ejercicio 2

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
