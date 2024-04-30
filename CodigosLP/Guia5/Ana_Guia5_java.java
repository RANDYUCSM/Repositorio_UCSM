import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Tienda tienda = new Tienda();
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("1. Agregar producto");
            System.out.println("2. Mostrar productos");
            System.out.println("3. Salir");
            System.out.print("Ingrese una opción: ");
            opcion = scanner.nextInt();

            switch(opcion) {
                case 1: {
                    String nombre;
                    double precio;
                    int cantidad;

                    System.out.print("Ingrese el nombre del producto: ");
                    nombre = scanner.next();
                    System.out.print("Ingrese el precio del producto: ");
                    precio = scanner.nextDouble();
                    System.out.print("Ingrese la cantidad del producto: ");
                    cantidad = scanner.nextInt();

                    tienda.agregarProducto(nombre, precio, cantidad);
                    break;
                }
                case 2:
                    tienda.mostrarProductos();
                    break;
                case 3:
                    System.out.println("Saliendo del programa.");
                    break;
                default:
                    System.out.println("Opción no válida.");
            }
        } while (opcion != 3);

        scanner.close();
    }
}

class Tienda {
    private Producto[] productos;
    private int numProductos;

    public Tienda() {
        productos = new Producto[0];
        numProductos = 0;
    }

    public void agregarProducto(String nombre, double precio, int cantidad) {
        Producto[] nuevosProductos = new Producto[numProductos + 1];
        for (int i = 0; i < numProductos; i++) {
            nuevosProductos[i] = productos[i];
        }
        nuevosProductos[numProductos] = new Producto(nombre, precio, cantidad);
        numProductos++;
        productos = nuevosProductos;
    }

    public void mostrarProductos() {
        for (int i = 0; i < numProductos; i++) {
            System.out.println("Producto " + (i + 1) + ":");
            productos[i].mostrarDetalles();
            System.out.println();
        }
    }
}

class Producto {
    private String nombre;
    private double precio;
    private int cantidad;

    public Producto(String nombre, double precio, int cantidad) {
        this.nombre = nombre;
        this.precio = precio;
        this.cantidad = cantidad;
    }

    public void mostrarDetalles() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Precio: " + precio);
        System.out.println("Cantidad: " + cantidad);
    }
}
