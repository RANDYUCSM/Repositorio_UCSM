//Ejercicio 1

//Ejercicio 2

//Ejercicio 3
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
