# ie0217-proyecto
Espacio destinado para la creación del proyecto de Estructuras Abstractas, la cual tiene como finalidad: la investigación, diseño e implementación de un sistema de gestión bancaria.


# Investigación: 

# Diseño:
## Modulos a utilizar:

```cpp
module <string>
module <maps>
module <vector>
module <exception>
module <limits>
```
## Definición y justificación de las clases:

### class Cliente:
Si una persona desea registrarse o realizar alguna transacción en un banco, necesita de una serie de características que lo identifiquen ante el banco. Esto permite un manejo de los prestamos, dinero, cuentas de ahorros, transacciones y demás tramites seguros, claros y eficientes.

#### Atributos:
- `nombre`:  variable tipo string que contiene el nombre del cliente.
- `id`: variable tipo entero que representaría la "cédula" del cliente.
- `cuentas`: variable que almacena la cuenta en dolares y colones del cliente.  Esta variable debería ser un map, debido que para facilitar el proceso se debería crear una clase llamada **CuentaBancaria** que contiene las carácteristicas esperadas de una cuenta (monto, moneda) y métodos (retiro de dinero, deposito de dinero, etc).
- `prestamos`: variable que almacena los prestamos del cliente. Esta variale también debería ser un map porque sería necesario crear una clase llamada **Prestamos** que contenga atributos (tipo de prestamo, moneda, taza de interes, etc) y métodos (pagar prestamo, reporte de cuotas, etc).

#### Métodos:
- `agregarCuenta`: el cliente debe ser capaz de agregar una cuenta en dolares o colones.
- `mostrarCuentas`: se deben poner mostrar las cuentas actuales del cliente.
- `agregarPrestamo`: el cliente debe ser capaz de endeudarse.
- `mostrarPrestamos`: se deben mostrar los prestamos actuales del cliente.
- `solicitarInformePrestanos`, `solicitarInformeCuentas`: el cliente debe ser capaz de poder el estado actual de su situación financiera.
- `solicitarCDP`: el cliente debería poder observar cuanta es la posible ganancia futura de mantener su dinero en las cuentas (todas las cuentas son de ahorro).
- `retirarDinero`, `depositarDinero`, `transferirDinero`, `pagarPrestamo`: el cliente debería ser capaz de realizar las operaciones bancarias esperadas sobre sus cuentas y prestamos.


### class CuentaBancaria:
Al estar registrado un cliente a un banco, este debe tener la posibilidad de crear cuentas para poder almacenar su dinero. Esto es necesario si este ya recibe un salario, beca o simplemente desea mantener su dinero seguro con una identidad bancaria. En el enunciado se menciona que el cliente tiene la posibilidad de crear cuentas de ahorros, una en colones y otra en dolares.

Para reutilizar código es factible utilizar una clase que contenga todo lo esperado de una cuenta para sus atributos y los métodos para realizar acciones sobre la cuenta. De esta forma no importa si la cuenta esta en dolares o colones, debido a que las operaciones son similares (contando el tipo de cambio de la moneda si se hace una transferencia de colones a dolares o viseversa.)

#### Atributos:
- `numeroCuenta`: identificador de la cuenta bancaria, este puede ser un dato tipo entero de la misma forma que el id del cliente.
- `tipoMoneda`: para asignar si la cuenta es en dolares o colones, por lo que debería ser un string.
- `monto`: aquí se debe almacenar la cantidad de dinero que tenga el cliente en esta cuenta, inicialmente debería comenzar en cero cuando es creada y debería ser un double debido a que el dinero puede tener decimales.
- `certificadosPlazo`: para que se puedan guardar los certificado de pósito (CDP) de largo, mediano o pequeño plazo del cliente. Considerando que el cliente podría solicitar varios tipos de CDP y estos pueden variar en sus características (taza de interes) es necesario crear un vector que los almacene, además se debería crear una clase llama **CDP** para facilitar la creación de los certificados, los cuales pueden variar de tipo.

#### Métodos:
- `setTipoMoneda`: para que cuando se creé la cuenta, el usuario pueda decidir si es en dolares o colones.
- `imprimirInfo`: aquí se mostraría el tipo de moneda, monto y su número de cuenta.
- `depositar`, `retirar`, `transferir`: para poder ingresar, retirar o transferir dinero, modificando el atributo monto.
- `agregarCDP`: para que el cliente creé el CDP dependiendo de las necesidades del mismo.


### class Prestamo:
Los prestamos pueden variar en personales, prendarios e hipotecarios, pero todos comparten carácterísticas como el tipo de moneda, cantidad de cuotas, intereses, pagos, etc. Para poder facilitar esto se crea un clase que permita la creación de un objeto que representa el tipo de prestamo y la información del mismo para el cliente.

El único inconveniente es que si bien los 3 prestamos mencionados, que son los que solicita el enunciado, comparten dichas características la forma de solicitarlos es distanta ya que un banco va a solicitar distintos tramites como solicitar un mueble o inmueble a cambio.