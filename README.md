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

### Diferencia entre Certificado de Depósito y Cuentas de Ahorro.

El CDP es un depósito pactado a un plazo y no se puede retirar el dinero hasta llegada la fecha de vencimiento del plazo pactado. No permite retiros, ni depósitos y paga una tasa de interés más alta. La cuenta ahorro tiene una tasa de interés más baja, se pueden hacer retiros y depósitos en el momento que cliente lo necesite y el cliente puede llevarse todo el dinero cuando él lo decida [[2]](https://www.baccredomatic.com/sites/default/files/2023-05/ni_preguntas_frecuentes_sobre_certificados_de_deposito_a_plazo.pdf).

Claro, un Certificado de Depósito a Plazo (CDP) es un instrumento financiero en el cual depositas una cantidad de dinero en una institución financiera a cambio de recibir un rendimiento (intereses) sobre ese dinero durante un período de tiempo específico, que puede variar desde unos pocos meses hasta varios años. Durante este período, el dinero generalmente no se puede retirar sin incurrir en penalidades, por lo que se considera una inversión de plazo fijo.

Las fórmulas básicas para calcular el rendimiento y el valor futuro de un Certificado de Depósito a Plazo son las siguientes:

**Formula para los intereses ganados**:

    I = P × i × t

Donde:

I = Intereses es el monto de intereses ganados.

P = Principal, es decir, la cantidad inicial depositada.

i = Tasa es la tasa de interés mensual (o anual) expresada en decimales.

t = Tiempo es el tiempo en meses o años dependiendo de cómo se exprese la tasa de interes.

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