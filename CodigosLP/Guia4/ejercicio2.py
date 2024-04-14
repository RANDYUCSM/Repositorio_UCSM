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

