import java.util.Scanner;

class Productos {
    private String nombre;
    private int codigo;
    private int cantidad;

    public Productos(String n, int c, int cant) {
        this.nombre = n;
        this.codigo = c;
        this.cantidad = cant;
    }

    public Productos(int c, int cant) {
        this.nombre = "Atun";
        this.codigo = c;
        this.cantidad = cant;
    }

    public String getNombre() {
        return nombre;
    }

    public int getCodigo() {
        return codigo;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setNombre(String n) {
        this.nombre = n;
    }

    public void setCodigo(int c) {
        this.codigo = c;
    }

    public void setCantidad(int cant) {
        this.cantidad = cant;
    }
}

class Tienda {
    private Productos producto;

    public Tienda(Productos p) {
        this.producto = p;
    }

    public void Mostrar() {
        System.out.println("El producto es " + producto.getNombre() + " con código " + producto.getCodigo());
        System.out.println("Stock: " + producto.getCantidad());
    }

    public void IngresarProducto() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese el nombre del producto:");
        String nombre = scanner.nextLine();
        System.out.println("Ingrese el código del producto:");
        int codigo = scanner.nextInt();
        System.out.println("Ingrese la cantidad que ingresa del producto:");
        int cantidad = scanner.nextInt();
        producto.setNombre(nombre);
        producto.setCodigo(codigo);
        producto.setCantidad(cantidad);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcion;
        Productos registro = new Productos("Atun", 123, 60);
        Productos registro1 = new Productos(123, 60);
        Tienda tienda = new Tienda(registro);
        Tienda tienda1 = new Tienda(registro1);

        while (true) {
            System.out.println("**********************");
            System.out.println("Ingrese una opción:");
            System.out.println("1. Ingresar productos");
            System.out.println("2. Mostrar");
            System.out.println("3. Salir");
            System.out.println("**********************");
            opcion = scanner.nextInt();

            if (opcion == 1) {
                tienda.IngresarProducto();
            } else if (opcion == 2) {
                tienda.Mostrar();
            } else if (opcion == 3) {
                break;
            } else {
                System.out.println("Opción inválida");
            }
        }

        scanner.close();
    }
}
