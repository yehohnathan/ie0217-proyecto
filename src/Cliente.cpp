#include "Cliente.hpp"
// Constantes de los prestamos
#include "Constantes.hpp"

// ---------------------------Métodos para setear datos, registrar transacciones y generar información --------------------------------- //

// Establecer datos e información del cliente
void Cliente::setDatos(int id_p, string nombre_p){
    id = id_p;              //< ID de la persona
    nombre = nombre_p;      //< Nombre de la persona
    cantidadCuentas = 0;    //< Número de cuentas
    cantidadPrestamos = 0;  //< Número de prestamos
    cantidadCDP = 0;        //< Cantidad de CDP
}

// Método para registrar una transacción
void Cliente::registrarTransaccion(int fecha[], vector <string>& transacciones, string nombre, int id, string descripcion){
    // Se crea un string con la información de la fecha de la transacción y el nombre y id del cliente que la realizó
    // También se agrega una descripción de la transacción
    string transaccion =  to_string(fecha[0]) + "/" + to_string(fecha[1])
    + "/" + to_string(fecha[2]) +"," + to_string(id) + "," + nombre + ","
    + descripcion;
    // Se agrega el string al vector con todas las transacciones
    transacciones.push_back(transaccion);
    // Se imprime un mensaje de que la transacción fue existosa
    cout << "Transaccion exitosa!" << endl;
}

// Método para generar información del cliente
vector <string> Cliente::generarInfo(map <int, CuentaBancaria>& cuentasBanco, map <int, Prestamo>& prestamosBanco, map <int, CDP>& certificadosBanco){
    // Se declara un vector string que contendrá la información
    vector <string> informacion;
    // Se guarda dentro los datos personales
    informacion.push_back("datos," + to_string(id) + "," + nombre);
    // Itera por las cuentas bancarias del cliente
    for(auto& par : cuentasBanco){
        // Si el id del propietario coincide
        if(par.second.idPropietario == id){
            // Guarda información de la cuenta
            informacion.push_back("cuenta," + to_string(id) + "," + to_string(par.second.numeroCuenta) + "," + par.second.tipoMoneda + "," + to_string(par.second.dineroAhorros));
        }
    }
    // Itera por los prestamos bancarios del cliente
    for(auto& par : prestamosBanco){
        // Itera por los prestamos bancarios del cliente
        if(par.second.idPropietario == id){
            // Guarda información del prestamo
            informacion.push_back("prestamo," + to_string(id) + "," + to_string(par.second.numeroPrestamo) + "," + par.second.tipo + "," + par.second.tipoMoneda + "," + to_string(par.second.montoTotal) 
            + "," + to_string(par.second.cuotasTotal) + "," + to_string(par.second.tasaInteres) + "," + to_string(par.second.cuotasPagadas));
        } 
    }
    // Itera por los centificados bancarios del cliente
    for(auto& par : certificadosBanco){
        // Itera por los certificados bancarios del cliente
        if(par.second.idPropietario == id){
            // Guarda información del CDP
            informacion.push_back("cdp," + to_string(id) + "," + to_string(par.second.numeroCDP) + "," + par.second.tipo + "," + par.second.tipoMoneda + "," + to_string(par.second.dineroCDP) + ","
            + to_string(par.second.fechaCreacion[0]) + "/" + to_string(par.second.fechaCreacion[1]) + "/" + to_string(par.second.fechaCreacion[2]) + ","
            + to_string(par.second.plazoMeses) + "," + to_string(par.second.tasaInteres));
        }
    }
    return informacion;
}

// ------------------------------------------Métodos de cuentas bancarias------------------------------------------ //

// Método encargado de agregar la cuenta del cliente
void Cliente::agregarCuenta(int fecha[], vector <string>& transacciones, map <int, CuentaBancaria>& cuentasBanco){
    // Si la cantidad de cuentas es equivalente a dos
    if(cantidadCuentas == 2){
        cout << "Ya tiene 2 cuentas, no puede agregar mas." << endl;
        return;
    }
    string tipoMoneda;          //< Se declara el tipo moneda como un string
    leerMoneda(tipoMoneda);     //< Se lee tipo de moneda
    CuentaBancaria cuenta;      //< Se declara una cuenta bancaria
    // Convierte la información a entero
    int numeroCuenta = stoi(to_string(id) + to_string(cantidadCuentas + 1));
    // Lllama al metodo establecer datos de cuenta
    cuenta.setDatos(id, numeroCuenta, tipoMoneda, 0);
    // Guarda dentro del contenedor de cuentasBanco la nueva cuenta
    cuentasBanco[numeroCuenta] = cuenta;
    // Aumenta la cantidad de cuentas
    cantidadCuentas += 1;
    // Regitra la transacción
    registrarTransaccion(fecha, transacciones, "agrego la cuenta numero " + to_string(cuenta.numeroCuenta) + " a su nombre");
}

// Método para retirar dinero de una de las cuentas
void Cliente::retirarDinero(int fecha[], vector <string>& transacciones, map <int, CuentaBancaria>& cuentasBanco){
    // Si el cliente no tiene cuentas asociadas
    if(cantidadCuentas == 0){
        // Se imprime un mensaje de que no hay cuentas registradas
        cout << "No tiene cuentas registradas a su nombre." << endl;
        // Se detiene la ejecución del método
        return;
    }
    // Se imprimen todas las cuentas del usuario
    cout << "\n---Estas son sus cuentas---" << endl;
    mostrarCuentas(cuentasBanco);
    int numeroCuenta;
    // Se lee del usuario el número de la cuenta de la que desea retirar
    leerEntero(numeroCuenta, "Ingrese el numero de la cuenta de la que desea retirar: ");
     // Se encuentra esta cuenta en el contenedor de las cuentas
    auto it_cuenta = cuentasBanco.find(numeroCuenta);
    // Si no se encontró la cuenta
    if(it_cuenta == cuentasBanco.end() || it_cuenta->second.idPropietario != id){
        // Se imprime un mensaje que indica que la cuenta no se encontró
        cout << "El numero de cuenta ingresado no esta registrado a su nombre." << endl;
        // Se detiene la ejecución del método
        return;
    }
    // Se obtiene el dinero de la cuenta antes del retiro 
    double dineroAntes = it_cuenta->second.dineroAhorros;
    // Se intenta retirar dinero de la cuenta con el método de la clase CuentaBancaria
    it_cuenta->second.retirar();
    // Se obtiene el dinero después del retiro
    double dineroAhora = it_cuenta->second.dineroAhorros;   
    if(dineroAntes > dineroAhora){
        // Se registra la transacción con un mensaje adecuado
        registrarTransaccion(fecha, transacciones, "retiro dinero de la cuenta propia numero " + to_string(numeroCuenta));
    }
}

// Método para depositar dinero a una cuenta 
void Cliente::depositarDinero(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes, map <int, CuentaBancaria>& cuentasBanco){
    // Se pregunta si el depósito va dirigido a sí mismo o a alguien más
    cout << "\n---Opciones de deposito---" << endl;
    cout << "1. A una cuenta propia." << endl;
    cout << "2. A una cuenta de otra persona." << endl;
    // Se lee la opción ingresada por el usuario
    int opcion;
    // se llama al método que válida
    leerEntero(opcion, "Ingrese una opcion: ");
    // Si el depósito es para sí mismo
    if(opcion == 1){
        // Se revisa si el usuario no tiene cuentas asociadas
        if(cantidadCuentas == 0){
            // En caso de que no se imprime un mensaje de error
            cout << "No tiene cuentas registradas a su nombre." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se imprimen las cuentas del usuario
        cout << "\n---Estas son sus cuentas---" << endl;
        // Muestra las cuentas
        mostrarCuentas(cuentasBanco);
        // Se lee del usuario el numero de la cuenta a la que desea depositar
        int numeroCuentaDestino;
        leerEntero(numeroCuentaDestino, "Ingrese el numero de cuenta a la que desea depositar: ");
        // Se busca la cuenta en el contenedor de las cuentas       
        auto it_cuentaDestino = cuentasBanco.find(numeroCuentaDestino);
        // Si no se encuentra
        if(it_cuentaDestino == cuentasBanco.end() || it_cuentaDestino->second.idPropietario != id){
            // Se imprime un mensaje de error
            cout << "El numero de cuenta ingresado no esta registrado a su nombre." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se realiza el depósito
        it_cuentaDestino->second.depositar();   
        // Se registra la transacción con la descripción adecuada
        registrarTransaccion(fecha, transacciones, "deposito dinero en la cuenta propia numero " + to_string(numeroCuentaDestino));
    }
    // Si el depósito es para alguien más
    else if(opcion == 2){
        // Se lee el id del cliente al que se desea depositar
        int numeroCuentaDestino;
        leerEntero(numeroCuentaDestino, "Ingrese el numero de cuenta a la que desea depositar: ");
        // Se busca el cliente en el contenedor con los clientes
        auto it_cuentaDestino = cuentasBanco.find(numeroCuentaDestino);
        // Si no se encuentra
        if(it_cuentaDestino == cuentasBanco.end()){
            // Se imprime un mensaje de error
            cout << "El numero de cuenta ingresado no existe en el registro." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se realiza el depósito
        it_cuentaDestino->second.depositar();   
        // Se registra la transacción con la descripción correcta
        registrarTransaccion(fecha, transacciones, "deposito dinero en la cuenta numero " + to_string(numeroCuentaDestino));
    }
    // En caso de que se ingrese una opción no válida
    else{
        // Se imprime un mensaje de error
        cout << "La opcion ingresada no es valida." << endl;
        // Se detiene la ejecución del método
        return;
    }
}

// Método para transferir dinero entre cuentas
void Cliente::transferirDinero(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes, map <int, CuentaBancaria>& cuentasBanco){
    // Si el cliente no tiene cuentas asociadas
    if(cantidadCuentas == 0){
        // Se imprime un mensaje de error
        cout << "No tiene cuentas registradas a su nombre." << endl;
        // Se detiene la ejecución del método
        return;
    }
    // Se imprimen las cuentas del cliente
    cout << "\n---Estas son sus cuentas---" << endl;
    mostrarCuentas(cuentasBanco);
    // Se lee el número de cuenta de la que sale el dinero
    int numeroCuentaSalida;
    leerEntero(numeroCuentaSalida, "Ingrese el numero de cuenta desde la que desea transferir: ");
    // Se busca la cuenta en el contenedor con las cuentas
    auto it_cuentaSalida = cuentasBanco.find(numeroCuentaSalida);
    // Si no se encuentra 
    if(it_cuentaSalida == cuentasBanco.end()){
        // Se imprime un mensaje de error
        cout << "El numero de cuenta ingresado no esta registrado a su nombre." << endl;
        // Se detiene la ejecución del método
        return;
    }
    // Se lee el id del cliente que tiene la cuenta que recibe el dinero
    int numeroCuentaDestino;
    leerEntero(numeroCuentaDestino, "Ingrese el numero de cuenta a la cuenta que desea transferir: ");
    // Se busca el cliente en el contenedor con los clientes
    auto it_cuentaDestino = cuentasBanco.find(numeroCuentaDestino);
    // Si no se encuentra
    if(it_cuentaDestino == cuentasBanco.end()){
        // Se imprime un mensaje de error
        cout << "El numero de cuenta ingresado no existe en el registro." << endl;
        // Se detiene la ejecución del método 
        return;
    }
    // Se obtiene el dinero antes de la transferencia
    double dineroAntes = it_cuentaSalida->second.dineroAhorros;
    // Se realiza la trasnferencia con el método de la clase CuentaBancaria
    it_cuentaSalida->second.transferir(it_cuentaDestino->second);
    // Se obtiene el dinero después de la transferencia
    double dineroAhora = it_cuentaSalida->second.dineroAhorros;
    // Si el dinero es menor es porque la transferencia se realizó con éxito
    if(dineroAntes > dineroAhora){
        // Se registra la transacción con el mensaje adecuado
        registrarTransaccion(fecha, transacciones, "transfirio dinero de la cuenta propia numero " + to_string(numeroCuentaSalida) + " a la cuenta numero " + to_string(numeroCuentaDestino));
    }
}

// Muentra la información de la cuenta
void Cliente::mostrarCuentas(map <int, CuentaBancaria>& cuentasBanco){
    // Itera por la cuenta
    for(auto& par : cuentasBanco){
        // Si coincide
        if(par.second.idPropietario == id){
            // Imprime la información
            par.second.imprimirInfo();
        }
    }
}

// Método para solicitar un informe de cuentas
void Cliente::solicitarInformeCuentas(int fecha[], vector <string>& transacciones){
    // Si el cliente no tiene cuentas asociadas a su nombre
    if(cuentas.size() == 0){
        // Se imprime un mensaje que indica que no hay cuentas para mostrar
        cout << "No tiene cuentas registradas a su nombre." << endl;
        // Se detiene la ejecución del método
        return;
    }
    // Se define el nombre del archivo
    string nombreArchivo = "informe_cuentas.txt";
    // Se abre el archivo, si no existe lo crea
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    // Se escribe un encabezado para el archivo
    archivo << "informe de cuentas solicitado por el usuario" << endl;
    archivo << endl;
    // Se agregan los datos del cliente
    archivo << "datos del cliente" << endl;
    archivo << "nombre,id" << endl;
    archivo << nombre + "," + to_string(id) << endl;
    // Se agrega un encabezado para las cuentas
    archivo << "cuentas registradas" << endl;
    // Se recorre el contenedor con las cuentas
    for(auto& par : cuentas){
        // Se agrega un encabezado para indicar el significado de los datos del reporte
        archivo << "numero de cuenta,tipo de moneda,dinero de ahorros,dinero CDP,plazo,interes,fecha creacion,fecha vencimiento" << endl;
        // Si hay un depósito a plazo se imprime la información de la cuenta junto con la del depósito a plazo
        if(par.second.depositosPlazo.size() == 1){
            archivo << to_string(par.second.numeroCuenta) + "," + par.second.tipoMoneda + "," + to_string(par.second.dineroAhorros) 
            + "," + par.second.depositosPlazo[0].informacion << endl;
        }
        // Si no hay depósitos a plazo se imprime solo la informacion de la cuenta seguida de guiones en la parte de los depósito a plazo
        else{
            archivo << to_string(par.second.numeroCuenta) + "," + par.second.tipoMoneda + "," + to_string(par.second.dineroAhorros) + ",-,-,-,-,-"<< endl;
        }
    }
    // Se cierra el archivo
    archivo.close();
    // Se imprime un mensaje de que se generó el archivo correctamente
    cout << "Se genero el archivo: " << nombreArchivo << endl;
    // Se registra la transacción con la descripción adecuada
    registrarTransaccion(fecha, transacciones, nombre, id, "solicito un informe de sus cuentas"); 
}

// ------------------------------------------Métodos de préstamos------------------------------------------ //

// Método que agrega un prestamo bancario
void Cliente::agregarPrestamo(int fecha[], vector <string>& transacciones, map <int, Prestamo>& prestamosBanco){
    int cuotasTotal;        //< Se establece el número de cuotas
    double tasaInteres;     //< Se establece la tasa de interés
    string tipo;            //< Se establece el tipo
    int opcion = 0;         //< Se establece la opción
    // Ciclo intedeterminado con las opciones
    while(1){
        cout << "\n---Opciones de prestamos---" << endl;
        cout << "1. Prestamo personal" << endl;
        cout << "2. Prestamo prendario." << endl;
        cout << "3. Prestamo hipotecario." << endl;
        cout << "4. Regresar." << endl;
        // Válida el valor ingresado por el usuario
        leerEntero(opcion, "Ingrese un opcion: ");
        // Si corresponde a la primera opción, utiliza la información de prestamo personal
        if(opcion == 1){
            cout << "\n---Prestamo personal---" << endl;
            cout << "Cantidad total de cuotas: " << CUOTASPERSONAL << endl;
            cout << "Tasa de interes: " << INTERESPERSONAL << endl;
            tipo = "personal";
            // Asigna las cuotas pertinentes
            cuotasTotal = CUOTASPERSONAL;
            // Asigna la tasa de interes pertinente
            tasaInteres = INTERESPERSONAL;
            // Rompe el ciclo
            break;
        }
        // Si corresponde a la segunda opción, utiliza la información de prestamo prendario
        else if(opcion == 2){
            cout << "\n---Prestamo prendario---" << endl;
            cout << "Cantidad total de cuotas: " << CUOTASPRENDARIO << endl;
            cout << "Tasa de interes: " << INTERESPRENDARIO << endl;
            tipo = "prendario";
            // Asigna las cuotas pertinentes
            cuotasTotal = CUOTASPRENDARIO;
            // Asigna la tasa de interes pertinente
            tasaInteres = INTERESPRENDARIO;
            // Rompe el ciclo
            break;
        }
        // Si corresponde a la tercera opción, utiliza la información de prestamo hipotecario
        else if(opcion == 3){
            cout << "\n---Prestamo hipotecario---" << endl;
            cout << "Cantidad total de cuotas: " << CUOTASHIPOTECARIO << endl;
            cout << "Tasa de interes: " << INTERESHIPOTECARIO << endl;
            tipo = "hipotecario";
            // Asigna las cuotas pertinentes
            cuotasTotal = CUOTASHIPOTECARIO;
            // Asigna la tasa de interes pertinente
            tasaInteres = INTERESHIPOTECARIO;
            // Rompe el ciclo
            break;
        }
        // Si corresponde a la cuarta opción, regresa al menú anterior
        else if(opcion == 4){
            cout << "\nRegresando..." << endl;
            return;
        }
        // En caso de ingresar un valor inválido lo indica
        else{
            cout << "La opcion ingresada no es valida. Intente de nuevo." << endl;
        }
    }
    // Se guarda la información general del prestamo
    string tipoMoneda;              //< Se inicializa el tipoMoneda
    leerMoneda(tipoMoneda);         //< Se establece el tipo de moneda
    double montoTotal;              //< Se inicializa el monto
    // Solicita el monto
    leerDouble(montoTotal, "Ingrese el monto total del prestamo: ");
    Prestamo prestamo;              //< Se declara un prestamo
    // Declara el ID junto con la cantidad de prestamos
    int numeroPrestamo = stoi(to_string(id) + to_string(cantidadPrestamos + 1));
    // Establece los datos
    prestamo.setDatos(id, numeroPrestamo, tipoMoneda, montoTotal, cuotasTotal, tasaInteres, 0,tipo);
    // Guarda el prestamos dentro del contenedor
    prestamosBanco[numeroPrestamo] = prestamo;
    // Aumenta la cantidad de prestamos
    cantidadPrestamos += 1;
    // Guarda información declara en esta función para tener registro de la misma
    registrarTransaccion(fecha, transacciones, "agrego el prestamo numero " + to_string(prestamo.numeroPrestamo) + " a su nombre");
}

// Método para pagar una cuota de un préstamo
void Cliente::pagarPrestamo(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes, map <int, Prestamo>& prestamosBanco){
    // Se pregunta si el pago es para sí mismo o para otra persona
    cout << "\n--- Opciones de pago del prestamo---" << endl;
    cout << "1. A un prestamo propio." << endl;
    cout << "2. A un prestamo de otra persona." << endl;
    // Se lee la opción del usuario
    int opcion;
    leerEntero(opcion, "Ingrese una opcion: ");
    // Si el pago es para sí mismo
    if(opcion == 1){
        // Si el cliente no tiene préstamos asociados
        if(cantidadPrestamos == 0){
            // Se imprime un mensaje de error
            cout << "No tiene prestamos registrados a su nombre." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se imprimen los préstamos del cliente
        cout << "\n---Estos son sus prestamos---" << endl;
        mostrarPrestamos(prestamosBanco);
        // Se lee el número del préstamo del que se va a pagar la cuota
        int numeroPrestamoDestino;
        leerEntero(numeroPrestamoDestino, "Ingrese el numero del prestamo que desea pagar: ");
        // Se busca el préstamo en el contenedor con los préstamos
        auto it_prestamoDestino = prestamosBanco.find(numeroPrestamoDestino);
        // Si no se encuentra
        if(it_prestamoDestino == prestamosBanco.end() || it_prestamoDestino->second.idPropietario != id){
            // Se imprime un mensaje de error
            cout << "El numero de prestamo ingresado no esta registrado a su nombre." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se paga la cuota con el método de la clase Prestamo
        it_prestamoDestino->second.pagarCuota();
        // Se registra la transacción con la descripción adecuada
        registrarTransaccion(fecha, transacciones, "pago una cuota del prestamo propio numero " + to_string(numeroPrestamoDestino));
    }
    // Si el pago es para otra persona
    else if(opcion == 2){
        // Se lee el id de la persona a la que va dirigida el pago
        int numeroPrestamoDestino;
        leerEntero(numeroPrestamoDestino, "Ingrese el numero del prestamo que desea pagar: ");
        // Se busca el cliente en el contenedor con los clientes
        auto it_prestamoDestino = prestamosBanco.find(numeroPrestamoDestino);
        // Si no se encuentra
        if(it_prestamoDestino == prestamosBanco.end()){
            // Se muestra un mensaje de error
            cout << "El numero de prestamo ingresado no esta registrado." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se hace un llamado a la función para pagar la cuota
        it_prestamoDestino->second.pagarCuota();
        // Se registra la transacción con la descripción correcta
        registrarTransaccion(fecha, transacciones, "pago una cuota del prestamo numero " + to_string(numeroPrestamoDestino));
    }
    // Si se ingresó una opción no válida
    else{
        // Se imprime un mensaje de error
        cout << "La opcion ingresada no es valida." << endl;
        // Se detiene la ejecución del programa
        return;
    }
}

// Método que muestra información de un prestamo
void Cliente::mostrarPrestamos(map <int, Prestamo>& prestamosBanco){
    // Itera dentro del contenedor en busca del prestamo
    for(auto& par : prestamosBanco){
        // Si el id coincide
        if(par.second.idPropietario == id){
            // Imprime la información
            par.second.imprimirInfo();
        }
    }
}

// Método para solicitar el informe de préstamos
void Cliente::solicitarInformePrestamos(int fecha[], vector <string>& transacciones, map <int, Prestamo>& prestamosBanco){
    // Si el cliente no tiene préstamos asociados
    if(cantidadPrestamos == 0){
        // Se imprime un mensaje de que no hay préstamos para mostrar
        cout << "No tiene prestamos registrados a su nombre." << endl;
        // Se termina la ejecución del método
        return;
    }
    // Se define el nombre del archivo
    string nombreArchivo = "informe_prestamos.txt";
    // Se abre el archivo y si no existe lo crea
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    // Se escribe un encabezado para el archivo
    archivo << "Informe de prestamos solicitado por el cliente" << endl;
    archivo << endl;
    // Se escriben los datos del cliente
    archivo << "----------------------------Datos del cliente----------------------------" << endl;
    archivo << "id,nombre" << endl;
    archivo << to_string(id) + "," + nombre << endl;
    // Se escribe un encabezado para los préstamos
    archivo << "----------------------------Prestamos registrados----------------------------" << endl;
    // Se recorre el contenedor de los préstamos
    for(auto& par : prestamosBanco){
        // En cazp de que el id coincida
        if(par.second.idPropietario == id){
            archivo << "----------------------------Prestamo numero " + to_string(par.second.numeroPrestamo) + "----------------------------" << endl;
            // Se agrega un encabezado para indicar el significado de los datos del reporte
            archivo << "numero de prestamo,tipo,tipo de moneda,monto total,cantidad cuotas,tasa interes,cuotas pagadas,intereses pagados,deuda pagada" << endl;
            // Para cada préstamo se escribe toda la información del préstamo
            archivo << to_string(par.second.numeroPrestamo) + "," + par.second.tipo + "," + par.second.tipoMoneda + "," + to_string(par.second.montoTotal) + "," 
            + to_string(par.second.cuotasTotal) + "," + to_string(par.second.tasaInteres) + "," + to_string(par.second.cuotasPagadas) + ","
            + to_string(par.second.interesesPagados) + "," + to_string(par.second.deudaPagada) << endl;
            // Se obtiene el reporte de cuotas del préstamo con el método de la clase Prestamo
            vector <string> reporte = par.second.generarInfoCuotas();
            // Para cada línea del reporte de cuotas
            for (string linea : reporte){
                // Se escribe la línea en el archivo
                archivo << linea << endl;
            }   
        }
        archivo << endl;
    }
    // Se cierra el archivo
    archivo.close();
    // Se imprime un mensaje de que se generó correctamente el archivo
    cout << "\nSe genero el archivo: " << nombreArchivo << endl;
    // Se registra la transacción con la descripción adecuada
    registrarTransaccion(fecha, transacciones, "solicito un informe de sus prestamos");
}


// ------------------------------------------Métodos de certificados a plazo------------------------------------------ //

// Método para agregar un Certificado de Depósito a Plazo (CDP) al cliente.
void Cliente::agregarCDP(int fecha[], vector<string>& transacciones, map<int, CDP>& certificadosBanco) {
    // Declaración de variables locales para almacenar información sobre el CDP.
    int plazoMeses;         //< Se inicializa el plazo de meses
    double tasaInteres;     //< Se inicializa la tasa de interés
    string tipo;            //< Se inicializa el tipo
    int opcion = 0;         //< Se inicializa la opción 

    // Bucle para permitir al cliente seleccionar el tipo de CDP que desea crear.
    while (true) {
        // Mostrar las opciones de CDP disponibles.
        cout << "\n---Opciones de Certificados de Deposito a Plazo---" << endl;
        cout << "1. Certificado a corto plazo." << endl;
        cout << "2. Certificado a mediano plazo." << endl;
        cout << "3. Certificado a largo plazo." << endl;
        cout << "4. Regresar." << endl;
        // Leer la opción del usuario.
        leerEntero(opcion, "Ingrese una opcion: ");

        // Procesar la opción del usuario.
        if (opcion == 1) {
            // Configurar un CDP de plazo corto.
            tipo = "corto";
            plazoMeses = PLAZOCORTO;
            tasaInteres = INTERESCORTO;
            break;
        } else if (opcion == 2) {
            // Configurar un CDP de plazo mediano.
            tipo = "mediano";
            plazoMeses = PLAZOMEDIANO;
            tasaInteres = INTERESMEDIANO;
            break;
        } else if (opcion == 3) {
            // Configurar un CDP de plazo largo.
            tipo = "largo";
            plazoMeses = PLAZOSLARGO;
            tasaInteres = INTERESLARGO;
            break;
        } else if (opcion == 4) {
            // El usuario desea regresar al menú principal.
            cout << "\nRegresando..." << endl; 
            return;
        } else {
            // La opción ingresada no es válida.
            cout << "La opcion ingresada no es valida. Intente de nuevo." << endl;
        }
    }

    // Leer la moneda del CDP.
    string tipoMoneda;
    leerMoneda(tipoMoneda);

    // Leer la cantidad de dinero a invertir en el CDP.
    double dineroCDP;
    leerDouble(dineroCDP, "Ingrese el dinero que desea invertir en el certificado: ");

    // Crear un nuevo objeto CDP.
    CDP certificadoPlazo;

    // Generar un número único para el CDP combinando el ID del cliente y un contador.
    int numeroCDP = stoi(to_string(id) + to_string(cantidadCDP + 1));

    // Establecer los datos del CDP.
    certificadoPlazo.setDatos(id, numeroCDP, tipoMoneda, dineroCDP, fecha, plazoMeses, tasaInteres, tipo);

    // Almacenar el CDP en el mapa de certificados del banco.
    certificadosBanco[numeroCDP] = certificadoPlazo;

    // Incrementar el contador de CDP del cliente.
    cantidadCDP += 1;

    // Registrar la transacción del cliente.
    registrarTransaccion(fecha, transacciones, "agrego el certificado a plazo numero " + to_string(certificadoPlazo.numeroCDP) + " a su nombre");
}


// Método para solicitar un informe de Certificados de Depósito a Plazo (CDP) del cliente.
void Cliente::solicitarInformeCDP(int fecha[], vector<string>& transacciones, map<int, CDP>& certificadosBanco) {
    // Verificar si el cliente tiene certificados de depósito a plazo registrados.
    if (cantidadCDP == 0) {
        cout << "No tiene certificados a plazo registrados a su nombre." << endl;
        return;
    }
    
    // Nombre del archivo para el informe.
    string nombreArchivo = "informe_certificados_plazo.txt";
    
    // Crear y abrir un archivo de texto para escribir el informe.
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    
    // Escribir el encabezado del informe.
    archivo << "Informe de certificados a plazo solicitado por el cliente" << endl;
    archivo << endl;
    archivo << "----------------------------Datos del cliente----------------------------" << endl;
    archivo << "id,nombre" << endl;
    archivo << to_string(id) + "," + nombre << endl;
    archivo << "----------------------------Certificados registrados----------------------------" << endl;

    // Iterar a través de los certificados de depósito a plazo del cliente.
    for (auto& par : certificadosBanco) {
        if (par.second.idPropietario == id) {  // Verificar si el certificado pertenece al cliente.
            // Escribir información del certificado en el archivo.
            archivo << "----------------------------Certificados numero " + to_string(par.second.numeroCDP) + "----------------------------" << endl;
            archivo << "numero de certificado,tipo,tipo de moneda,dinero invertido,dinero generado,dinero total,plazo en meses,tasa interes,fecha de creacion,fecha expiracion,estado" << endl;
            archivo << to_string(par.second.numeroCDP) + "," + par.second.tipo + "," + par.second.tipoMoneda + "," + to_string(par.second.dineroCDP)
            + "," + to_string(par.second.dineroGenerado) + "," + to_string(par.second.dineroTotal) 
            + "," + to_string(par.second.plazoMeses) + "," + to_string(par.second.tasaInteres) + ","
            + to_string(par.second.fechaCreacion[0]) + "/" + to_string(par.second.fechaCreacion[1]) + "/" + to_string(par.second.fechaCreacion[2]) + ","
            + to_string(par.second.fechaExpira[0]) + "/" + to_string(par.second.fechaExpira[1]) + "/" + to_string(par.second.fechaExpira[2]) + ","
            + par.second.estado << endl;
        }
        archivo << endl;
    }
    
    // Cerrar el archivo después de escribir el informe.
    archivo.close();
    
    // Informar al usuario que se ha generado el archivo.
    cout << "\nSe genero el archivo: " << nombreArchivo << endl;
    
    // Registrar la transacción del cliente.
    registrarTransaccion(fecha, transacciones, "solicito un informe de sus certificados a plazo");
}
