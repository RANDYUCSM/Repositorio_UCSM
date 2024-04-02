//Ejercicio 1
import java.util.Scanner;

class Auto {
    int velocidadA = 5;
    int velocidadPC;
    double contador = 5;

    void setVelocidadPC(int vel) {
        velocidadPC = vel;
    }

    int getVelocidadA() {
        return velocidadA;
    }

    int getVelocidadPC() {
        return velocidadPC;
    }

    void aumentarVelocidad() {
        velocidadA += 5;
        contador -= 1.5;
        System.out.println("Avanzando...");
        try {
            Thread.sleep((long) (contador * 1000));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Carrera {
    Auto autos = new Auto();
    int distanciaC, distanciaPC;
    int dificultad;
    String opcionvel;
    Scanner input = new Scanner(System.in);

    void simularCarrera() {
        distanciaC = 0;
        distanciaPC = 0;

        if (dificultad == 1) {
            autos.setVelocidadPC(20);
        } else if (dificultad == 2) {
            autos.setVelocidadPC(30);
        } else if (dificultad == 3) {
            autos.setVelocidadPC(40);
        }

        while (distanciaC <= 100 && distanciaPC <= 100) {
            distanciaC += autos.getVelocidadA();
            System.out.println("Desea aumentar la velocidad? s/n");
            opcionvel = input.next();
            if (opcionvel.equalsIgnoreCase("s")) {
                autos.aumentarVelocidad();
            } else {
                System.out.println("Avanzando...");
                try {
                    Thread.sleep((long) (autos.contador * 1000));
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            distanciaPC += autos.getVelocidadPC();
            distanciaC += autos.getVelocidadA();

            if (distanciaC >= 100) {
                System.out.println("¡Ganaste!");
                break;
            } else if (distanciaPC >= 100) {
                System.out.println("¡Ganó la computadora!");
                break;
            }

            System.out.println("Tu carro está " + distanciaC + "/100");
            System.out.println("La computadora está " + distanciaPC + "/100");
        }
    }

    void cambiarDificultad() {
        System.out.println("Ingrese el nivel de dificultad:");
        System.out.println("1. Fácil");
        System.out.println("2. Medio");
        System.out.println("3. Difícil");
        dificultad = input.nextInt();
    }
}

public class Main {
    public static void main(String[] args) {
        Carrera carrera = new Carrera();
        carrera.cambiarDificultad();
        carrera.simularCarrera();
    }
}

//Ejercicio 2
import java.util.ArrayList;
import java.util.Scanner;

public class Inventario {
    private String[] listaProductosDisponible = {"cebolla", "papa", "arroz", "azucar"};
    private String[] listaProductosAgotados = {"ajo", "zanahoria", "brocoli", "atun", "pollo"};
    private ArrayList<String> listaPedidos = new ArrayList<>();
    private int numproductosdisponibles = 4;

    public void AgregarProductos() {
        Scanner input = new Scanner(System.in);
        System.out.println("¿Cuántos productos desea agregar?");
        int cantidadProductos = input.nextInt();

        for (int i = 0; i < cantidadProductos; i++) {
            System.out.println("Ingrese el nombre del producto:");
            String nuevo_producto = input.next();
            listaProductosDisponible[numproductosdisponibles + i] = nuevo_producto;
        }
        numproductosdisponibles += cantidadProductos;
    }

    public void EliminarProductos(String producto) {
        for (int i = 0; i < numproductosdisponibles; i++) {
            if (listaProductosDisponible[i].equals(producto)) {
                for (int j = i; j < numproductosdisponibles - 1; j++) {
                    listaProductosDisponible[j] = listaProductosDisponible[j + 1];
                }
                numproductosdisponibles--;
                System.out.println("Producto " + producto + " eliminado");
                return;
            }
        }
        System.out.println("Producto no encontrado en la lista");
    }

    public void ActualizarProductosD() {
        System.out.println("Los productos disponibles son:");
        for (int i = 0; i < numproductosdisponibles; i++) {
            System.out.print(listaProductosDisponible[i] + " ");
        }
        System.out.println();
    }

    public void ActualizarProductosA() {
        System.out.print("Los productos agotados son: ");
        for (String agotado : listaProductosAgotados) {
            System.out.print(agotado + " ");
        }
        System.out.println();
    }

    public void RealizarPedido() {
        Scanner input = new Scanner(System.in);
        int contador = 0;
        System.out.println("Ingrese los 4 productos disponibles a pedir:");
        while (contador < 4) {
            String prod = input.next();
            for (String item : listaProductosDisponible) {
                if (item.equals(prod)) {
                    listaPedidos.add(prod);
                    contador++;
                }
            }
        }
    }

    public void FacturasCliente() {
        int suma = listaPedidos.size();
        System.out.println("El precio total de los pedidos es S/" + suma * 8);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Inventario inventario = new Inventario();
        int opc = 1;

        while (opc != 6) {
            System.out.println("¿Qué operación desea hacer?");
            System.out.println("1. Agregar productos");
            System.out.println("2. Mostrar productos");
            System.out.println("3. Eliminar productos");
            System.out.println("4. Realizar pedido");
            System.out.println("5. Generar factura");
            System.out.println("6. Salir");
            opc = input.nextInt();

            switch (opc) {
                case 1:
                    inventario.AgregarProductos();
                    break;
                case 2:
                    inventario.ActualizarProductosD();
                    break;
                case 3:
                    System.out.println("¿Qué producto desea eliminar?");
                    String eliminar = input.next();
                    inventario.EliminarProductos(eliminar);
                    break;
                case 4:
                    inventario.RealizarPedido();
                    break;
                case 5:
                    inventario.FacturasCliente();
                    break;
            }
        }
    }
}
//Ejercicio 3
import java.util.Scanner;

class Avion {
    private String destino;
    private int duracionMision; // en horas
    private int tripulacionNecesaria;
    private int combustibleActual; // en litros

    public Avion(String dest, int duracion, int tripulacion, int combustible) {
        destino = dest;
        duracionMision = duracion;
        tripulacionNecesaria = tripulacion;
        combustibleActual = combustible;
    }

    public void simularMision() {
        if (combustibleActual >= duracionMision * 10) {
            System.out.println("La misión hacia " + destino + " ha sido completada con éxito.");
        } else {
            System.out.println("El avión no tiene suficiente combustible para completar la misión hacia " + destino + ".");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Bienvenido al Programa de Simulación de Vuelo");
        System.out.print("Ingrese el destino de la misión: ");
        String destino = scanner.nextLine();

        System.out.print("Ingrese la duración estimada de la misión en horas: ");
        int duracionMision = scanner.nextInt();

        System.out.print("Ingrese la cantidad de tripulación necesaria para la misión: ");
        int tripulacionNecesaria = scanner.nextInt();

        System.out.print("Ingrese la cantidad de combustible actual del avión en litros: ");
        int combustibleActual = scanner.nextInt();

        Avion avion = new Avion(destino, duracionMision, tripulacionNecesaria, combustibleActual);
        avion.simularMision();

        scanner.close();
    }
}
