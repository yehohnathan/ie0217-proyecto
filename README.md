# ie0217-proyecto
Espacio destinado para la creación del proyecto de Estructuras Abstractas, la cual tiene como finalidad: la investigación, diseño e implementación de un sistema de gestión bancaria.


# Investigación: 
### ¿Qué es la tasa de interés y cómo se calcula?

La tasa de interés (también llamada tipo de interés) es el precio que una persona o institución debe pagar por solicitar un préstamo. Es decir, es el costo asignado por prestar o pedir prestado una determinada suma de dinero por un tiempo estipulado. Por lo general, la tasa de interés se expresa como un porcentaje anual [[1]](https://www.ceupe.com/blog/tasa-de-interes.html).

Para calcular la tasa de interés, es necesario calcular primero el "interés", que es la cantidad extra que solicita la entidad financiera por utilizar el dinero. El interés se calcula de la siguiente forma [[1]](https://www.ceupe.com/blog/tasa-de-interes.html):

    Interés = Valor_final – Capital

Una vez conocido el interés, la tasa se puede calcular de la siguiente manera [[1]](https://www.ceupe.com/blog/tasa-de-interes.html):

    Tasa_interés = Interés/(Capital*tiempo) 


### ¿Que son los préstamos personales, prendarios e hipotecarios?

- Prestamos personales: intereses más altos y plazos más cortos. El plazo de cuotas suele variar entre 12 y 60 meses, dependiendo del banco y del monto.
- Prestamos prendarios: el banco necesita que se le ingrese un bien mueble del mismo valor al prestamo a solicitar. Usualmente el prestamo equivale entre un 60 a 90% del bien mueble. El plazo de cuotas suele variar entre 24 y 60 meses, dependiendo del banco y del valor del bien mueble.
- Prestamos hipotecarios: similares a los presdarios, pero solicitan un bien inmueble. Se suele prestar un 80% si es para la compra de una casa, y un 60% si es para la remodelación de una casa. El plazo de cuotas suele variar entre 60 y 360 meses, dependiendo del banco y del valor del bien inmueble.

    | Tipo de préstamo | Tasa de interés anual mínima | Tasa de interés anual máxima |
    | ---------------- | ---------------------------- | ---------------------------- |
    | Personal         | 8%                           | 40%                          |
    | Prendario        | 15%                          | 30%                          |
    | Hipotecario      | 8%                           | 12%                          |


### ¿En qué consiste el certificado de Depósito a Plazo Fijo?

Es un depósito que se pacta a un periodo de tiempo, el cual es acordado entre el cliente y el banco. La tasa de interés se establece en base al monto del depósito y el plazo. Este tipo de depósitos no permite retiros, ni incrementos de saldos y para poder disponer del dinero el cliente debe esperar hasta la fecha de vencimiento del depósito [[2]](https://www.baccredomatic.com/sites/default/files/2023-05/ni_preguntas_frecuentes_sobre_certificados_de_deposito_a_plazo.pdf).

### Diferencia entre Certificado de Depósito y Cuentas de Ahorro.

El CDP es un depósito pactado a un plazo y no se puede retirar el dinero hasta llegada la fecha de vencimiento del plazo pactado. No permite retiros, ni depósitos y paga una tasa de interés más alta. La cuenta ahorro tiene una tasa de interés más baja, se pueden hacer retiros y depósitos en el momento que cliente lo necesite y el cliente puede llevarse todo el dinero cuando él lo decida [[2]](https://www.baccredomatic.com/sites/default/files/2023-05/ni_preguntas_frecuentes_sobre_certificados_de_deposito_a_plazo.pdf).

Un Certificado de Depósito a Plazo (CDP) es un instrumento financiero en el cual depositas una cantidad de dinero en una institución financiera a cambio de recibir un rendimiento (intereses) sobre ese dinero durante un período de tiempo específico, que puede variar desde unos pocos meses hasta varios años. Durante este período, el dinero generalmente no se puede retirar sin incurrir en penalidades, por lo que se considera una inversión de plazo fijo.

Las fórmulas básicas para calcular el rendimiento y el valor futuro de un Certificado de Depósito a Plazo son las siguientes:

**Formula para los intereses ganados**:

    I = P × i × t

Donde:

I: Intereses es el monto de intereses ganados.

P: Principal, es decir, la cantidad inicial depositada.

i: Tasa es la tasa de interés mensual (o anual) expresada en decimales.

t: Tiempo es el tiempo en meses o años dependiendo de cómo se exprese la tasa de interes.

**Formula para el Valor futuro (monto total al vencimiento)**:

    VF  = P + I

Donde:

VF es el valor futuro o el monto total al vencimiento del Certificado de Depósito a Plazo e I son los interes acumulados.

Aun así, la forma en que se calculan los intereses dependiendo de la institución financiera y las políticas locales.

### ¿Cómo calcular la cuota de un crédito?

Para calcular la cuota fija mensual, se utiliza la siguiente operación matemática:

    Cuota mensual = (P * i) / (1 - (1 + i) ^ (-n))

Donde:

•	P = Monto del préstamo

•	i = Tasa de interés mensual

•	n = Plazo del crédito en meses


### Diferencia entre interés simple y compuesto

El interés simple se calcula utilizando solamente el principal, ignorando el interés generado en los periodos de interés anteriores. En cambio, el interés compuesto se calcula sobre el principal más el monto total de interés acumulado en todos los periodos anteriores.


### ¿Qué es la amortización y cómo se calcula?

En economía, el término amortización hace referencia a la reducción del valor de un activo o un pasivo con el paso del tiempo. La amortización es, por tanto, una forma de cuantificar la pérdida de valor de un bien o de una deuda [[3]](https://www.bancosantander.es/glosario/amortizacion). La amortización se puede calcular de la siguiente forma:

    R = Ci/(1-(1+i)^-n)

Donde:

R: Cuota de amortización constante.

C: Monto principal o capital del préstamo.

i: Tasa de interés periódica (expresada de manera decimal).

n: Número total de periodos o pagos.


# Diseño:
## Posibles modulos a utilizar:

```cpp
module <fstream>    // Para gestionar archivos
module <string>     // Para crear variables que contengan cadenas de carácteres
module <maps>       // Para poder almacenar almacenar objetos en claves de forma ordenada
module <vector>     // Para guardar información de ciertos objetos
module <stdexcept>  // Para hacer uso de las excepciones
module <limits>     // Para borrar el contenido de "cin"
module <iosteam>    // Funciones básicas de la STL
```
## Definición y justificación de las clases:

### class Banco
La clase banco es para crear un objeto que sea capaz de almacenar la información de todos los posibles clientes y que a traves de ella se puedan realizar las operaciones esperadas en un banco como la gestión de prestamos, cuentas, certificados de plazo, etc. Por lo que se puede afirmar que esta clase sirve para tratar de emitar la estructura real de un banco y por ello la necesidad de su creación, ya que permite gestionar a cada cliente de una forma más sencilla y óptima.

#### Atributos:
- `clientes`: contener que almacena la información de los clientes, en este caso objetos de una clase llamada **Cliente**. Para ello se debería utilizar map para acceder a cada cliente de forma sencilla.
- `transacciones`: almacena las transacciones realizadas por cada cliente, asignandole un identificador a cada una. Se trabajaría con strings y se debería usar un vector para guarda la información de cada transacción, con el fin de se pueda generar al final un reporte de las transacciones.
- `ventanilla`: ventanilla sería un objeto de la clase **AtencionCliente** que serviría para agarrar información de uno o dos clientes y realizar gestiones en cuentas o prestamos.
- `fecha`: almacena una fecha que servirá como referencia para solicitar reportes de tramites y requiran un lapso temporal.

#### Métodos:
- `mostrarMenu()`: le muestra las opciones que una persona puede hacer al ir al banco, como registrarse, consultar prestamos o realizar diversas transacciones.
- `crearCliente()`: para crear un nuevo objeto de la clase Cliente, cuya información será guardada en el atributo clientes.
- `atenderCliente()`: registra la información de uno o dos clientes y utiliza los métodos del objeto ventanilla para realizar distintos trámites.
- `setFecha()`: para ingresar registrar la fecha.

### class AtencionCliente
Esta clase sirve para crear objetos, que funcionan como ventallas, para un banco en especifico y no guardan información de nigun tipo porque solo sirve para que los clientes puedan cambiar el estado actual de su economía (prestamos, cuentas o CDP).

#### Métodos:
- `mostrarMenu()`: muestra el menú de atención al cliente, para gestionar cuentas o prestamos.
- `gestionarCuentas()`: gestiona lo que quiere hacer un cliente con una cuenta. Se podrá crear una cuenta, depositar o retirnar dinero, etc.
- `gestionarPrestamos()`: gestiona lo que quiere hacer un cliente con un prestamo, en donde se podrán crear un nuevo prestamo, pagar una cuota, etc.
- `gestionarCDP()`: gestiona lo que quiere hacer un cliente con un certificado de plazo, solicitando su plazo de duración y monto inicial.
  
### class Cliente
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


### class CuentaBancaria
Al estar registrado un cliente a un banco, este debe tener la posibilidad de crear cuentas para poder almacenar su dinero. Esto es necesario si este ya recibe un salario, beca o simplemente desea mantener su dinero seguro con una identidad bancaria. En el enunciado se menciona que el cliente tiene la posibilidad de crear cuentas de ahorros, una en colones y otra en dolares.

Para reutilizar código es factible utilizar una clase que contenga todo lo esperado de una cuenta para sus atributos y los métodos para realizar acciones sobre la cuenta. De esta forma no importa si la cuenta esta en dolares o colones, debido a que las operaciones son similares (contando el tipo de cambio de la moneda si se hace una transferencia de colones a dolares o viseversa.)

#### Atributos:
- `numeroCuenta`: identificador de la cuenta bancaria, este puede ser un dato tipo entero de la misma forma que el id del cliente.
- `tipoMoneda`: para asignar si la cuenta es en dolares o colones, por lo que debería ser un string.
- `monto`: aquí se debe almacenar la cantidad de dinero que tenga el cliente en esta cuenta, inicialmente debería comenzar en cero cuando es creada y debería ser un double debido a que el dinero puede tener decimales.

#### Métodos:
- `setTipoMoneda`: para que cuando se creé la cuenta, el usuario pueda decidir si es en dolares o colones.
- `imprimirInfo`: aquí se mostraría el tipo de moneda, monto y su número de cuenta.
- `depositar`, `retirar`, `transferir`: para poder ingresar, retirar o transferir dinero, modificando el atributo monto.

### class Prestamo
Los prestamos pueden variar en personales, prendarios e hipotecarios, pero todos comparten carácterísticas como el tipo de moneda, cantidad de cuotas, intereses, pagos, etc. Para poder facilitar esto se crea un clase que permita la creación de un objeto que representa el tipo de prestamo y la información del mismo para el cliente.

El único inconveniente es que si bien los 3 prestamos mencionados, que son los que solicita el enunciado, comparten dichas características la forma de solicitarlos es distanta ya que un banco va a solicitar distintos tramites como solicitar un mueble o inmueble a cambio. Aunque en la reunicón con se nos comentó que no es necesario tener en cuenta esto y basta con el cambio de los interes dependiendo del tipo de prestamo.

#### Atributos
- `idPrestamo`: para que el prestamo pueda tener una identificación, esto es util cuando un tercero desea paghar una cuota. Lo que se podría utilizar como id es el id del cliente segundo de un **n** que representa el número de prestamo solicitado por el cliente.
- `tipoMoneda`: indicador para saber si el prestamo es en dolares o colones.
- `montoTotal`: indica el monto máximo
- `cuotasTotal`: indica la cantidad de cuotas totales que debe pagar el cliente, estas pueden ir disminuyendo conforme se paguen las cuotas.
- `tasaInteres`: taza de interes del prestamo, variable que varia dependiendo del tipo de prestamo que haya solicitado el cliente.
- `costoCuota`: número de cuotas pagadas por el cliente/
- `cuotasPagadas`: expresa la cantidad de cuotas pagadas por el cliente.
- `interesesPagados`: monto monetario que representa la cantidad de interes que ha ido pagando el cliente, esto es aparte al pago de la deuda como tal.
- `deudaPagada`: valor real del prestamo pagado por el cliente.
- `infoCuotas`: en un contener de toda la información de las cuotas pagadas por el cliente, inclutendo el pago de la deuda, el pago de lso intereses y número de cuota. Este podría ser un contener, ya que es necesario almacenar varios tipos de informació y en diferentes meses.

#### Métodos:
- `setDatos()`: para colocar los datos de la deuda como los intereses, monto total, tipo de moneda, etc.
- `imprimirInfo()`: para poder imprimir información de la deuda al cliente, en este caso la cantidad de cuotas que tendrá que pagar, el montó solicitado, valor de los intereses, etc.
- `pagarCuota()`: para pagar la cuota, rebajando el numero de cuotas totales, aumentando las cuotas pagadas y cambiando los montos de deuda pagada, etc.
- `generarReporteCuotas()`: genera un archivo .txt con información relevante de las cuotas (pagos) del prestamo.

### class CDP
Esto se puede considerar como el inverso de los prestamos (ahorro), en donde el cliente puede darle dinero al banco a cambio de recibir un interes (dinero) a su favor. El ciente tiene la posibilidad de solicitar varios certificados de plazo, que varian de corto, mediano a largo plazo y cada uno con un montó a ingresar por el cliente mensualmente y un beneficio.

#### Atributos:
- `tipoMoneda`: ingresar el tipo de moneda.
- `dineroCDP`: cantidad que se va a ingresar al banco mensualmente.
- `fechaCreacion`: para ingresar la fecha de creación del CDP, la cual esta relacionada con la fecha que solicita el banco antes de realizar cualquier transacción.
- `fechaExpira`: fecha de expiración del certificado, variable dependiendo del plazo del mismo.
- `plazoMeses`: cantidad de meses que depende del plazo del certificado.
- `tasaInteres`: taza de interes, que varia dependiendo del CDP, y son de benefició al cliente.
- `informacion`: muestra la información sobre la fecha de creación y expiración del CDP, además de sus intereses.

#### Métodos: 
- `setDatos()`: para ingresar los datos del CDP.
- `mostrarDatosCDP()`: para mostrar información de las posibles ganancias a causa de los interes del CDP que va a tener el cliente.


## Cronograma de actividades:

La siguiente tabla corresponde al cronograma de actividades a realizar.

| Clases a diseñar    | Métodos de Clases             | 2/2/2024 | 3/2/2024 | 4/2/2024 | 5/2/2024 | 6/2/2024 | 7/2/2024 | 8/2/2024 |
|---------------------|-------------------------------|----------|----------|----------|----------|----------|----------|----------|
| Banco               | mostrarMenú                   |          |          |          |          |          |          | David    |
|                     | crearCliente                  |          |          |          |          |          |          | David    |
|                     | atenderCliente                |          |          |          |          |          |          | Yeoh     |
|                     | setFecha                      |          |          |          |          |          |          | Yeoh     |
| AtencionCliente     | mostrarMenú                   |          |          |          |          |          | Yeoh     |          |
|                     | gestionarCuentas              |          |          |          |          |          | Yeoh     |          |
|                     | gestionarPrestamo             |          |          |          |          |          | Danny    |          |
|                     | gestionarCDP                  |          |          |          |          |          | Danny    |          |
| Cliente             | agregarCuentas                |          |          |          |          | David    |          |          |
|                     | mostrarCuentas                |          |          |          |          | David    |          |          |
|                     | agregarPrestamo               |          |          |          |          | David    |          |          |
|                     | mostrarPrestamos              |          |          |          |          | David    |          |          |
|                     | SolicitarPrestamos            |          |          |          |          | Danny    |          |          |
|                     | SolicitarInformeCuentas       |          |          |          |          | Danny    |          |          |
|                     | solicitarCDP                  |          |          |          |          | Danny    |          |          |
|                     | accionesDinero                |          |          |          |          | Danny    |          |          |
| CuentaBancaria      | setTipoMoneda                 |          |          |  Yeoh    |          |          |          |          |
|                     | imprimirInfo                  |          |          |  Yeoh    |          |          |          |          |
|                     | depositar, retirar, transferir|          |          |  Danny   |          |          |          |          |
| Prestamo            | setDatos                      |          |  David   |          |          |          |          |          |
|                     | imprimirInfo                  |          |  David   |          |          |          |          |          |
|                     | pagarCuota                    |          |  Danny   |          |          |          |          |          |
|                     | generarReporteCuotas          |          |  Danny   |          |          |          |          |          |
| CDP                 | setDatos                      |          |          |          |  David   |          |          |          |
|                     | mostrarDatosCDP               |          |          |          |  Yeoh    |          |          |          |
