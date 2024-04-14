//Ejercicio 1

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Autor{    //clase Autor
    private String nombre;
    private String nacionalidad;
    private List<String> librosEscritos = new ArrayList<String>();

    public Autor(String nombre, String nacionalidad, List<String> librosEscritos) {
        this.nombre = nombre;
        this.nacionalidad = nacionalidad;
        this.librosEscritos = librosEscritos;
    }

    public void IngresarLibrosEscritos() {  //Metodo para ingresar los libros escritos por el autor
        Scanner scanner = new Scanner(System.in);
        String tituloLibro;
        String opcion;
        while (true) {
            System.out.println("Ingrese la lista de libros escritos por el autor");
            tituloLibro = scanner.nextLine();
            librosEscritos.add(tituloLibro);
            System.out.println("Seguir ingresando? S/N: ");
            opcion = scanner.nextLine();
            if (opcion.equalsIgnoreCase("n")) {
                break;
            }
        }
    }

    public String getNombre() {
        return nombre;
    }

    public String getNacionalidad() {
        return nacionalidad;
    }

    public List<String> getLibrosEscritos() {
        return librosEscritos;
    }
}

class Libro {   //clase libros
    private String titulo;
    private int ISBN;
    private int añoPublicacion;
    private int cantidadEjemplares;
    private Autor autor;

    public Libro(String titulo, int ISBN, int añoPublicacion, int cantidadEjemplares) {
        this.ISBN = ISBN;
        this.titulo = titulo;
        this.añoPublicacion = añoPublicacion;
        this.cantidadEjemplares = cantidadEjemplares;
    }

    public String getTitulo() {
        return titulo;
    }

    public int getISBN() {
        return ISBN;
    }

    public int getAñoPublicacion() {
        return añoPublicacion;
    }

    public int getCantidadEjemplares() {
        return cantidadEjemplares;
    }

    public void setAutor(Autor autor) {
        this.autor = autor;
    }

    public Autor getAutor() {
        return autor;
    }
}

class Usuario{
    private String nombre;
    private String direccion;
    private int numeroTelefono;
    private List<String> librosPrestados = new ArrayList<String>();

    public Usuario(String nombre, String direccion, int numeroTelefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.numeroTelefono = numeroTelefono;
    }

    public void IngresarLibrosPedidos() { //Ingresar libros prestados al usuario
        Scanner scanner = new Scanner(System.in);
        String prestado;
        String opcion;
        while (true) {
            System.out.println("Ingrese la lista de libros prestados");
            prestado = scanner.nextLine();
            librosPrestados.add(prestado);
            System.out.println("Seguir ingresando? S/N: ");
            opcion = scanner.nextLine();
            if (opcion.equalsIgnoreCase("n")) {
                break;
            }
        }
    }

    public String getNombre() {
        return nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public int getNumeroTelefono() {
        return numeroTelefono;
    }

    public List<String> getLibrosPrestados() {
        return librosPrestados;
    }
}

class Biblioteca{   //Clase biblioteca
    private Autor autor;
    private Libro libro;
    private Usuario usuario;

    public Biblioteca(Autor autor, Libro libro, Usuario usuario) {
        this.autor = autor;
        this.libro = libro;
        this.usuario = usuario;
    }

    public void MostrarDatosAutor() {   //Mostrar datos del autor
        System.out.println("Informacion del autor ");
        System.out.println("Nombre: " + autor.getNombre());
        System.out.println("Nacionalidad: " + autor.getNacionalidad());
        System.out.println("Libros escritos: ");
        for (String item : autor.getLibrosEscritos()) {
            System.out.print(item + ", ");
        }
    }

    public void MostrarDatosUsuarios() {    //Mostrar datos del usuario
        System.out.println("Informacion del usuario ");
        System.out.println("Nombre: " + usuario.getNombre());
        System.out.println("Direccion: " + usuario.getDireccion());
        System.out.println("Numero de telefono: ");
        System.out.println("Libros prestados: ");
        for (String item : usuario.getLibrosPrestados()) {
            System.out.print(item + ", ");
        }
    }

    public void MostrarDatosLibro() {       //Mostrar datos del libro
        System.out.println("Informacion del libro ");
        System.out.println("Titulo: " + libro.getTitulo());
        System.out.println("ISBN: " + libro.getISBN());
        System.out.println("Año de publicacion: " + libro.getAñoPublicacion());
        System.out.println("Cantidad de elemplares: " + libro.getCantidadEjemplares());
    }
}

public class Main {
    public static void main(String[] args) {
        String opcion;
        Autor autor = new Autor("", "", new ArrayList<String>());
        autor.IngresarLibrosEscritos();
        Autor autor1 = new Autor("Jesus", "Peru", autor.getLibrosEscritos());
        Libro libro1 = new Libro("tituloo", 12342131, 2024, 13);
        Usuario usuario = new Usuario("", "", 923214131);
        usuario.IngresarLibrosPedidos();
        Usuario usuario1 = new Usuario("Jesus", "Jorge chavez", usuario.getLibrosPrestados());
        Biblioteca biblioteca = new Biblioteca(autor1, libro1, usuario1);
        biblioteca.MostrarDatosAutor();
        biblioteca.MostrarDatosLibro();
        biblioteca.MostrarDatosUsuarios();
    }
}

//Ejercicio 2
import java.util.ArrayList;
import java.util.List;

class Proveedor {
    private String nombre;

    public Proveedor(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }
}

class Cliente {
    private String nombre;
    private String direccion;
    private int telefono;
    private List<Compra> comprasRealizadas = new ArrayList<>();
    private List<Pago> pagosRealizados = new ArrayList<>();

    public Cliente(String nombre, String direccion, int telefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
    }

    public String getNombre() {
        return nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public int getTelefono() {
        return telefono;
    }

    public void agregarCompra(Compra compra) {
        comprasRealizadas.add(compra);
    }

    public void agregarPago(Pago pago) {
        pagosRealizados.add(pago);
    }

    public void mostrarInfoCliente() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Compras Realizadas: ");
        for (Compra compra : comprasRealizadas) {
            System.out.println("----Productos: " + compra.getProdAsoc().getDescripcion());
            System.out.println("----Cantidad: " + compra.getCantidad());
            System.out.println("----Precio unitario: " + compra.getProdAsoc().getPrecio());
            System.out.println("----Fecha: " + compra.getVentaAsoc().getFecha());
        }
        System.out.println("Pagos: ");
        for (Pago pago : pagosRealizados) {
            System.out.println(pago.getMonto());
        }
    }
}

class Producto {
    private int codigo;
    private String descripcion;
    private double precio;
    private Proveedor provAso;

    public Producto(int codigo, String descripcion, double precio, Proveedor provAso) {
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.precio = precio;
        this.provAso = provAso;
    }

    public int getCodigo() {
        return codigo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public double getPrecio() {
        return precio;
    }

    public Proveedor getProveedor() {
        return provAso;
    }
}

class Venta {
    private String numFact;
    private String fecha;
    private Cliente clienteAso;
    private List<Producto> productosVendidos = new ArrayList<>();

    public Venta(String numFact, String fecha, Cliente cliente) {
        this.numFact = numFact;
        this.fecha = fecha;
        this.clienteAso = cliente;
    }

    public String getNumFact() {
        return numFact;
    }

    public String getFecha() {
        return fecha;
    }

    public Cliente getCliente() {
        return clienteAso;
    }

    public void agregarProducto(Producto producto) {
        productosVendidos.add(producto);
    }

    public void mostrarInfoVenta() {
        System.out.println("---------------------------------------------------------");
        System.out.println("Numero de factura: " + numFact);
        System.out.println("Fecha: " + fecha);
        System.out.println("Cliente: " + clienteAso.getNombre());
        System.out.println("Descripcion: ");
        for (Producto producto : productosVendidos) {
            System.out.println(producto.getDescripcion());
        }
        System.out.println("---------------------------------------------------------");
    }
}

class Compra {
    private Cliente clienteAso;
    private Producto prodAso;
    private Venta ventaAso;
    private int cantidad;

    public Compra(Cliente cliente, Producto producto, Venta venta, int cantidad) {
        this.clienteAso = cliente;
        this.prodAso = producto;
        this.ventaAso = venta;
        this.cantidad = cantidad;
    }

    public Cliente getCliente() {
        return clienteAso;
    }

    public Producto getProdAsoc() {
        return prodAso;
    }

    public Venta getVentaAsoc() {
        return ventaAso;
    }

    public int getCantidad() {
        return cantidad;
    }
}

class Pago {
    private Cliente clienteAso;
    private double monto;
    private String fechaPago;

    public Pago(Cliente cliente, double monto, String fechaPago) {
        this.clienteAso = cliente;
        this.monto = monto;
        this.fechaPago = fechaPago;
    }

    public Cliente getCliente() {
        return clienteAso;
    }

    public double getMonto() {
        return monto;
    }

    public String getFechaPago() {
        return fechaPago;
    }
}

public class Main {
    public static void main(String[] args) {
        // Objetos
        // Proveedor
        Proveedor prov1 = new Proveedor("Nombre_prov1");
        // Producto
        Producto prod1 = new Producto(1234, "Pantalon", 100, prov1);
        // Cliente
        Cliente cli1 = new Cliente("Mario", "Direc_prueba", 123456789);
        // Venta
        Venta venta1 = new Venta("A123", "Fecha_prueba", cli1);
        // Compra
        Compra comp1 = new Compra(cli1, prod1, venta1, 2);
        // Pago
        Pago pago1 = new Pago(cli1, 200, "Fecha_prueba");

        // agregarCompra
        cli1.agregarCompra(comp1);
        cli1.agregarPago(pago1);
        venta1.agregarProducto(prod1);

        // Mostrar información
        // Cliente
        cli1.mostrarInfoCliente();
        venta1.mostrarInfoVenta();
    }
}

//Ejercicio 3

import java.util.ArrayList;
import java.util.Scanner;

class Profesor {
    private String nombre;
    private String direccion;
    private String telefono;
    private ArrayList<Asignatura> asignaturas;

    public Profesor(String nombre, String direccion, String telefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.asignaturas = new ArrayList<>();
    }

    public void agregarAsignatura(Asignatura asignatura) {
        asignaturas.add(asignatura);
    }

    // Getters y setters
}

class Asignatura {
    private String codigo;
    private String nombre;
    private String descripcion;
    private Profesor profesor;
    private ArrayList<Estudiante> estudiantes;

    public Asignatura(String codigo, String nombre, String descripcion, Profesor profesor) {
        this.codigo = codigo;
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.profesor = profesor;
        this.estudiantes = new ArrayList<>();
    }

    public void agregarEstudiante(Estudiante estudiante) {
        estudiantes.add(estudiante);
    }

    // Getters y setters
}

class Estudiante {
    private String nombre;
    private String direccion;
    private String matricula;

    public Estudiante(String nombre, String direccion, String matricula) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.matricula = matricula;
    }

    // Getters y setters
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ingresar datos del profesor
        System.out.println("Ingrese el nombre del profesor: ");
        String nombreProfesor = scanner.nextLine();
        System.out.println("Ingrese la dirección del profesor: ");
        String direccionProfesor = scanner.nextLine();
        System.out.println("Ingrese el teléfono del profesor: ");
        String telefonoProfesor = scanner.nextLine();

        // Crear objeto Profesor
        Profesor profesor = new Profesor(nombreProfesor, direccionProfesor, telefonoProfesor);

        // Ingresar datos de la asignatura
        System.out.println("Ingrese el código de la asignatura: ");
        String codigoAsignatura = scanner.nextLine();
        System.out.println("Ingrese el nombre de la asignatura: ");
        String nombreAsignatura = scanner.nextLine();
        System.out.println("Ingrese la descripción de la asignatura: ");
        String descripcionAsignatura = scanner.nextLine();

        // Crear objeto Asignatura y asociarlo al profesor
        Asignatura asignatura = new Asignatura(codigoAsignatura, nombreAsignatura, descripcionAsignatura, profesor);
        profesor.agregarAsignatura(asignatura);

        // Ingresar datos del estudiante
        System.out.println("Ingrese el nombre del estudiante: ");
        String nombreEstudiante = scanner.nextLine();
        System.out.println("Ingrese la dirección del estudiante: ");
        String direccionEstudiante = scanner.nextLine();
        System.out.println("Ingrese la matrícula del estudiante: ");
        String matriculaEstudiante = scanner.nextLine();

        // Crear objeto Estudiante
        Estudiante estudiante = new Estudiante(nombreEstudiante, direccionEstudiante, matriculaEstudiante);

        // Agregar la asignatura al estudiante
        estudiante.agregarAsignatura(asignatura);
        asignatura.agregarEstudiante(estudiante);

        // Imprimir información
        System.out.println("\nInformación del profesor:");
        System.out.println("Nombre: " + profesor.getNombre());
        System.out.println("Dirección: " + profesor.getDireccion());
        System.out.println("Teléfono: " + profesor.getTelefono());

        System.out.println("\nInformación de la asignatura:");
        System.out.println("Código: " + asignatura.getCodigo());
        System.out.println("Nombre: " + asignatura.getNombre());
        System.out.println("Descripción: " + asignatura.getDescripcion());
        System.out.println("Profesor: " + asignatura.getProfesor().getNombre());

        System.out.println("\nInformación del estudiante:");
        System.out.println("Nombre: " + estudiante.getNombre());
        System.out.println("Dirección: " + estudiante.getDireccion());
        System.out.println("Matrícula: " + estudiante.getMatricula());
    }
}

