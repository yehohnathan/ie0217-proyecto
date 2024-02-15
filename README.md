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
## Diseño y resumen de las clases:

### class Banco
La clase banco es para crear un objeto que sea capaz de almacenar la información de todos los posibles clientes y que a traves de ella se puedan realizar las operaciones esperadas en un banco como la gestión de prestamos, cuentas, certificados de plazo, etc. Por lo que se puede afirmar que esta clase sirve para tratar de emitar la estructura real de un banco y por ello la necesidad de su creación, ya que permite gestionar a cada cliente de una forma más sencilla y óptima.

#### Intancias:
- `AtencionCliente.hpp` > `Cliente.hpp`
- `Informacion.hpp` > `Prestamo.hpp`
- `Cliente.hpp` > `CuentaBancaria.hpp` `Prestamo.hpp` `CDP.hpp` 
- `Prestamo.hpp` > `LecturaDatos.hpp`
- `CuentaBancaria.hpp` > `LecturaDatos.hpp`
- `CDP.hpp` > `LecturaDatos.hpp`

#### Atributos:
- *`map <int, Cliente>`* `clientes`: contenedor que almacena la información de los clientes, en este caso objetos de una clase llamada **Cliente**.

- *`map <int, CuentaBancaria>`* `cuentasBanco`: contenedor que almacena la información de todas las cuentas bancarias de todos los clientes del banco, en este caso objetos de una clase llamada **CuentaBancaria**.

- *`map <int, Prestamo>`* `prestamosBanco`: contenedor que almacena la información de todas los prestamos de todos los clientes del banco, en este caso objetos de una clase llamada **Prestamo**.

- *`vector <string>`* `transacciones`: almacena las transacciones realizadas por cada cliente, asignandole un identificador a cada una.

- *`AtencionCliente`* `ventanilla`: es un objeto de la clase **AtencionCliente** que sirve para gestionar los tramites del cliente. Muestra un menu para cada tipo de transacción utilizando los métodos de la clase **Cliente**.

- *`Informacion`* `informante`: es un objeto de la clase **Informacion** enfocado en mostrar los tipos de préstamos ofrecidos por el banco: personal, prendario, hipotecario y personalizado. Además, se encarga de gestionar las opciones y cálculos del préstamo personalizado para presentarlos al solicitante.


- *`int`* `fecha[3]`: almacena una fecha que servirá como referencia para solicitar reportes de tramites y requiran un lapso temporal. Es un array que almacena el día, mes y año en cada posición correspondiente.

#### Métodos:
- *`void`* `setFecha()`: solicita al usuario ingresar una fecha y almacena el contenido en **fecha[3]**. Este proceso incluye la verificación para asegurar que la entrada del usuario sea la esperada; en caso contrario, solicita nuevamente la fecha.

- *`void`* `mostrarMenu()`: presenta diversas opciones disponibles para los clientes al visitar el banco, que incluyen registrarse, consultar préstamos o solicitar atención al cliente para llevar a cabo varias transacciones. Si el usuario solicita registrarse, se invoca al método **crearCliente()**. En caso de consultar préstamos, se muestra el método **mostrarMenu()** del objeto **informante**. Si se requiere atención al cliente, se accede al método **atenderCliente()**.

- *`void`* `crearCliente()`: solicita al cliente ingresar su nombre en una variable de tipo string, la cual es procesada mediante el método **leerNombre** de la clase instanciada en el header llamada **LecturaDatos**. A continuación, se solicita al usuario ingresar su id en una variable entera, la cual es procesada por el método **leerEntero** de la misma clase instanciada en el header llamado **LecturaDatos**. Una vez obtenido un nombre y una id válidos, se verifica que la id ingresada no coincida con la de ninguna otra persona. En caso afirmativo, se procede a crear un objeto cliente con los datos proporcionados por la persona y se registra esta transacción en el vector de transacciones.

- *`void`* `atenderCliente()`: solicita al usuario ingresar su identificación en una variable entera, la cual es procesada por el método **leerEntero** de la misma clase instanciada en el header llamado **LecturaDatos**. A continuación, se busca dentro del mapa de clientes un id similar. Si no se encuentra, se le informa al usuario que el id ingresado es válido y se vuelve al menú principal. En caso de que el id coincida con uno de los clientes registrados, se procede a mostrar el método **mostrarMenu()** del objeto "ventanilla" para gestionar los trámites del cliente.

- *`vector <string>`* `dividir()`: método enfocado en dividir un string en un contenedor de strings separando por un dicador, eso para colocar comas. 

- *`void`* `leerInfoClientes()`: abre el archivo "info_clientes.txt" en modo lectura. Luego, omite las dos primeras líneas del archivo que contienen encabezados. Después, lee cada línea del archivo y la procesa para obtener información sobre clientes, cuentas bancarias, préstamos y certificados a plazo. Dependiendo del tipo de información en cada línea, se crea un objeto correspondiente (Cliente, CuentaBancaria, Prestamo, CDP), utiliza el método **setDatos** dependiendo del objeto y se almacena en los maps (`clientes`, `cuentasBanco`, `prestamosBanco`, `certificadosBanco`). Además, se actualizan las cantidades de cuentas, préstamos y certificados del cliente correspondiente en el map `clientes`. Finalmente, se cierra el archivo.

- *`void`* `actualizarInfoClientes()`: abre el archivo "info_clientes.txt" en modo de escritura, truncando el archivo si ya existe o creándolo si no existe. Luego, escribe un encabezado en el archivo. Después, para cada cliente en el map `clientes`, genera información sobre el cliente utilizando el método `generarInfo` de la clase `Cliente`. La información generada incluye detalles sobre las cuentas bancarias, préstamos y certificados a plazo asociados con el cliente. Cada línea de información se escribe en el archivo. Finalmente, se cierra el archivo y se imprime un mensaje de confirmación.

- *`void`* `leerTransacciones()`: abre el archivo "registro_transacciones.txt" en modo lectura. Luego, omite las primeras tres líneas del archivo que contienen encabezados. Después, lee cada línea restante del archivo y la agrega al vector transacciones. Finalmente, cierra el archivo.

- *`void`* `actualizarTransacciones()`: abre el archivo "registro_transacciones.txt" en modo de escritura, truncando el archivo si ya existe o creándolo si no existe. Luego, escribe un encabezado y un título para cada columna en el archivo, que incluye "fecha", "id", "nombre" y "descripcion". Después, itera sobre cada transacción en el vector `transacciones` y escribe cada transacción en una línea separada en el archivo. Finalmente, cierra el archivo y muestra un mensaje indicando que se ha actualizado o generado el archivo correctamente.

- *`void`* `actualizarCertificados()`: actualiza los certificados de plazo (CDP) para todos los clientes del banco. Itera sobre cada certificado en el map `certificadosBanco` y utiliza el método `actualizarCDP` de la clase `CDP` para actualizar el estado del certificado basado en la fecha actual (`fecha`). Esto le da una funcionalidad adiconal al atributo **fecha[3]** indicandole al usuario si el CDP sigue vigente o se ha vencido.

### class AtencionCliente
Esta clase sirve para crear objetos, que funcionan como ventallas, para un banco en especifico y no guardan información de nigun tipo porque solo sirve para que los clientes puedan cambiar el estado actual de su economía (prestamos, cuentas o CDP).

#### Intancias a otras clases:
- `Cliente.hpp` > `CuentaBancaria.hpp` `Prestamo.hpp` `CDP.hpp` 
- `Prestamo.hpp` > `LecturaDatos.hpp`
- `CuentaBancaria.hpp` > `LecturaDatos.hpp`
- `CDP.hpp` > `LecturaDatos.hpp` 
- `Contantes.hpp`

#### Métodos:
- *`void`* `mostrarMenu()`: muestra un menú de opciones para el cliente en la sección de Atención al Cliente. Saluda al cliente y muestra las opciones disponibles, como tramitar cuentas bancarias, préstamos o certificados de depósito a plazo. Luego, solicita al cliente que ingrese una opción y realiza la acción correspondiente según la opción seleccionada. Dependiendo de la opción se accede a al método **gestionarCuentas**, **gestionarPrestamos** o **gestionarCuertificados** o se regresa al menú principal.

- *`void`* `gestionarCuentas()`: muestra un menú de opciones que incluye agregar una cuenta, retirar dinero, depositar dinero, transferir dinero y solicitar un informe de sus cuentas actuales. Según la opción seleccionada por el cliente, se llama al método **agregarCuenta**, **retirarDinero**, **depositarDinero**, **solicitarInformeCuentas** o **solicitarInformeCuentas** correspondiente de la clase Cliente para realizar la acción deseada.

- *`void`* `gestionarPrestamos()`: muestra un menú de opciones que incluye solicitar un préstamo, pagar una cuota y solicitar un informe de sus préstamos actuales. Según la opción seleccionada por el cliente, se llama al método **agregarPrestamo**, **pagarPrestamo** o **solicitarInformePrestamos** correspondiente de la clase Cliente para realizar la acción deseada.

- *`void`* `gestionarCertificados()`: muestra un menú de opciones que incluye solicitar un certificado y solicitar un informe de sus certificados actuales. Según la opción seleccionada por el cliente, se llama al método **agregarCDP** o **solicitarInformeCDP** correspondiente de la clase Cliente para realizar la acción deseada.

### class Cliente
Si una persona desea registrarse o realizar alguna transacción en un banco, necesita de una serie de características que lo identifiquen ante el banco. Esto permite un manejo de los prestamos, dinero, cuentas de ahorros, transacciones y demás tramites seguros, claros y eficientes.

#### Intancias a otras clases:
- `Prestamo.hpp` > `LecturaDatos.hpp`
- `CuentaBancaria.hpp` > `LecturaDatos.hpp`
- `CDP.hpp` > `LecturaDatos.hpp`

#### Atributos:
- *`string`* `nombre`:  variable tipo string que contiene el nombre del cliente.
- *`int`* `id`: variable tipo entero que representaría la identificación del cliente.
- *`int`* `cantidadCuentas`: variable tipo entera que contiene la cantidad de cuentas del cliente. Necesario para asignar un id a cada cuenta y ser accedidas al contenedor que se encuentra en la clase Banco.

- *`int`* `cantidadPrestamos`: variable tipo entera que contiene la cantidad de prestamos del cliente. Necesario para asignar un id a cada prestamo y ser accedidas al contenedor que se encuentra en la clase Banco.
- *`int`* `cantidadCDP`: variable tipo entera que contiene la cantidad de CDP del cliente. Necesario para asignar un id a cada CDP y ser accedidas al contenedor que se encuentra en la clase Banco.

#### Métodos:
- *`void`* `setDatos()`: establece los datos de un cliente, como su ID, nombre, e inicializa la cantidad cuentas, préstamos y certificados de depósito (CDP) en 0.

- *`void`* `registrarTransaccion():` registra una transacción para el cliente, agregando la información de la transacción al vector `transacciones`, que contiene todas las transacciones registradas. Siempre se colocará la fecha de la transacción, el nombre del cliente y la descripción del cliente (agrego la cuenta numero..., retiro dinero de la propia cuenta..., etc).

- *`void`* `generarInfo():` genera información del cliente, incluyendo sus datos personales, cuentas bancarias, préstamos y certificados de depósito, pero por separado mediante condicionales para escoger el tipo de información a guardar. Estos datos son guardados e iterador en un vector creado llamando informacion.

- *`void`* `agregarCuenta()`: permite al cliente agregar una nueva cuenta bancaria a su perfil. Antes de proceder, verifica si el cliente ya ha alcanzado el límite máximo de cuentas permitidas, lo cual se determina a través del atributo **cantidadCuentas**. En caso de que el cliente tenga el máximo de cuentas permitidas, se muestra un mensaje indicando que no es posible agregar más cuentas.

    Si el cliente puede crear otra cuenta, el método solicita al usuario el tipo de moneda utilizando el método **leerMoneda()** de la clase **LecturaDatos**. Luego, se asigna un número de cuenta basado en el id del cliente. A continuación, se instancia un objeto de la clase **CuentaBancaria** para representar la nueva cuenta y se almacena la información correspondiente. La nueva cuenta se agrega al map **cuentasBanco** dentro de la clase **Banco** para su gestión. Finalmente, se registra la transacción asociada a la creación de la cuenta utilizando el método **registrarTransaccion()**, asegurando que la acción quede registrada en el sistema bancario."

- *`void`* `retirarDinero()`: permite al cliente retirar dinero de una de sus cuentas bancarias. Verifica si el cliente tiene cuentas asociadas con **cantidadCuentas()**, muestra las cuentas disponibles con **mostrarCuentas()**, solicita el número de cuenta verificando con **leerEntero()** de la clase **LecturaDatos**, si el número es correcto accede al map **cuentasBanco** buscando por el id y modifica la cantidad de dinero con el método **retirar()** de la clase **CuentaBancaria**. Finalmente registrar la transacción con el método **registrarTransaccion()**.

- *`void`* `depositarDinero()`:permite al cliente depositar dinero en una cuenta propia o en la cuenta de otro cliente. Si el cliente desea depositarse a sí mismo, verifica si tiene cuentas. Si tiene cuentas, muestra sus cuentas, de lo contrario, solicita al cliente el número de cuenta a la que desea depositar. Continúa el proceso similar al método **retirarDinero()**, pero utilizando el método **depositar()** en vez de **retirar()** de la clase **CuentaBancaria**. Finalmente, registra la transacción utilizando **registrarTransaccion()**.

- *`void`* `transferirDinero()`: permite al cliente transferir dinero entre cuentas bancarias. Primero, verifica si el cliente tiene cuentas asociadas utilizando el atributo **cantidadCuentas**. Si no tiene cuentas, muestra un mensaje de error. Luego, muestra las cuentas del cliente utilizando el método **mostrarCuentas()**. Después, solicita al cliente el número de cuenta desde la cual desea transferir dinero y verifica su validez. A continuación, solicita al cliente el número de cuenta a la que desea transferir el dinero y verifica su validez. Posteriormente, realiza la transferencia utilizando el método **transferir()** de la clase **CuentaBancaria**. Finalmente, registra la transacción asociada a la transferencia utilizando el método **registrarTransaccion()**.

- *`void`* `mostrarCuentas()`: muestra la información de las cuentas bancarias asociadas al cliente. Itera a través del map **cuentasBanco** y, para cada cuenta, verifica si pertenece al cliente actual utilizando el atributo **idPropietario** de la clase **CuentaBancaria**. Si la cuenta pertenece al cliente, imprime la información de la cuenta utilizando el método **imprimirInfo()** de la clase **CuentaBancaria**.

- *`void`* `solicitarInformeCuentas()`: permite que un cliente solicite un informe de sus cuentas bancarias. Primero, verifica si el cliente tiene cuentas registradas utilizando el atributo **cantidadCuentas**. Si el cliente no tiene cuentas, muestra un mensaje de error. Luego, crea un archivo llamado "informe_cuentas.txt" y escribe en él encabezado del informe y los detalles de cada cuenta asociada al cliente. Finalmente, muestra un mensaje indicando que se genero un txt y mostrando su nombre, luego registra la transacción asociada a la solicitud del informe utilizando el método **registrarTransaccion()**.

- *`void`* `agregarPrestamo()`: permite al cliente agregar un préstamo bancario. Primero, ofrece al cliente opciones de préstamos como personal, prendario o hipotecario. El cliente elige una opción y se establecen los parámetros del préstamo, como el número de cuotas, la tasa de interés y el tipo de préstamo. Luego, solicita al cliente el tipo de moneda y el monto total del préstamo verificando con los métodos **leerMoneda()** y **leerDouble()** de la clase **LecturaDatos**. Después tener toda la información, crea un objeto de la clase **Prestamo**, establece los datos del préstamo y lo guarda en el map **prestamosBanco**. Finalmente, registra la transacción asociada a la adición del préstamo utilizando el método **registrarTransaccion()**.

- *`void`* `pagarPrestamo()`: permite al cliente pagar una cuota de un préstamo. Primero, pregunta al cliente si el pago es para su propio préstamo o para el préstamo de otra persona. Si es para su propio préstamo, muestra los préstamos del cliente y solicita al cliente el número del préstamo que desea pagar. Verifica la existencia del préstamo y procede a pagar la cuota utilizando el método **pagarCuota()** de la clase **Prestamo**. Luego, registra la transacción asociada al pago de la cuota. Si el pago es para otro cliente, solicita al cliente el número del préstamo a pagar, verifica su existencia y procede de manera similar. Los números de cuenta son solicitados y verificados con el método **leerEntero()** de la clase **LecturaDatos**. Finalmente, registra la transacción asociada a la adición del préstamo utilizando el método **registrarTransaccion()**.

- *`void`* `mostrarPrestamos()`: muestra información sobre los préstamos asociados al cliente. Itera a través del map **prestamosBanco** y verifica si el id del propietario del préstamo coincide con el ID del cliente actual. Si hay coincidencia, imprime la información del préstamo utilizando el método **imprimirInfo()** de la **clase Prestamo**.

- *`void`* `solicitarInformePrestamos()`: permite al cliente solicitar un informe de sus préstamos. Primero, verifica si el cliente tiene préstamos asociados mediante al atributo **cantidadPrestamos**. Si no tiene préstamos, imprime un mensaje indicando que no hay préstamos registrados a su nombre. Procedea crear un archivo llamado "informe_prestamos.txt" y escribe en él los detalles de cada préstamo del cliente, incluyendo el número de préstamo, tipo, tipo de moneda, monto total, cantidad de cuotas, tasa de interés, cuotas pagadas, intereses pagados y deuda pagada. Además, obtiene un informe detallado de cuotas utilizando el método **generarInfoCuotas()** de la clase **Prestamo** y lo escribe en el archivo. Finalmente, cierra el archivo y registra la transacción con el **registrarTransaccion()**.

- *`void`* `agregarCDP()`: permite al cliente agregar un Certificado de Depósito a Plazo (CDP). Primero, presenta al cliente las opciones disponibles para los CDP, como corto, mediano o largo plazo. Luego, el cliente selecciona el tipo de CDP y proporciona la moneda y la cantidad de dinero a invertir en el certificado. El método crea un nuevo objeto CDP (certificadoPlazo), asigna un número único al CDP combinando el ID del cliente y un contador, establece los datos del CDP y lo almacena en el map **certificadosBanco**. Finalmente, registra la transacción del cliente y actualiza el contador de CDP del cliente.


### class CuentaBancaria
Al estar registrado un cliente a un banco, este debe tener la posibilidad de crear cuentas para poder almacenar su dinero. Esto es necesario si este ya recibe un salario, beca o simplemente desea mantener su dinero seguro con una identidad bancaria. En el enunciado se menciona que el cliente tiene la posibilidad de crear cuentas de ahorros, una en colones y otra en dolares.

Para reutilizar código es factible utilizar una clase que contenga todo lo esperado de una cuenta para sus atributos y los métodos para realizar acciones sobre la cuenta. De esta forma no importa si la cuenta esta en dolares o colones, debido a que las operaciones son similares (contando el tipo de cambio de la moneda si se hace una transferencia de colones a dolares o viseversa.)

#### Intancias a otras clases:
- `LecturaDatos.hpp`

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
