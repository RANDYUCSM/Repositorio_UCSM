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
