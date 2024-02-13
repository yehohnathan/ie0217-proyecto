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

void Cliente::agregarPrestamo(int fecha[], vector <string>& transacciones, map <int, Prestamo>& prestamosBanco){
    int cuotasTotal;
    double tasaInteres;
    string tipo;
    int opcion = 0;
    while(1){
        cout << "\n---Opciones de prestamos---" << endl;
        cout << "1. Prestamo personal" << endl;
        cout << "2. Prestamo prendario." << endl;
        cout << "3. Prestamo hipotecario." << endl;
        cout << "4. Regresar." << endl;
        leerEntero(opcion, "Ingrese un opcion: ");
        if(opcion == 1){
            cout << "\n---Prestamo personal---" << endl;
            cout << "Cantidad total de cuotas: " << CUOTASPERSONAL << endl;
            cout << "Tasa de interes: " << INTERESPERSONAL << endl;
            tipo = "personal";
            cuotasTotal = CUOTASPERSONAL;
            tasaInteres = INTERESPERSONAL;
            break;
        }
        else if(opcion == 2){
            cout << "\n---Prestamo prendario---" << endl;
            cout << "Cantidad total de cuotas: " << CUOTASPRENDARIO << endl;
            cout << "Tasa de interes: " << INTERESPRENDARIO << endl;
            tipo = "prendario";
            cuotasTotal = CUOTASPRENDARIO;
            tasaInteres = INTERESPRENDARIO;
            break;
        }
        else if(opcion == 3){
            cout << "\n---Prestamo hipotecario---" << endl;
            cout << "Cantidad total de cuotas: " << CUOTASHIPOTECARIO << endl;
            cout << "Tasa de interes: " << INTERESHIPOTECARIO << endl;
            tipo = "hipotecario";
            cuotasTotal = CUOTASHIPOTECARIO;
            tasaInteres = INTERESHIPOTECARIO;
            break;
        }
        else if(opcion == 4){
            cout << "\nRegresando..." << endl;
            return;
        }
        else{
            cout << "La opcion ingresada no es valida. Intente de nuevo." << endl;
        }
    }

    string tipoMoneda;
    leerMoneda(tipoMoneda);
    double montoTotal;
    leerDouble(montoTotal, "Ingrese el monto total del prestamo: ");
    Prestamo prestamo;
    int numeroPrestamo = stoi(to_string(id) + to_string(cantidadPrestamos + 1));
    prestamo.setDatos(id, numeroPrestamo, tipoMoneda, montoTotal, cuotasTotal, tasaInteres, 0,tipo);
    prestamosBanco[numeroPrestamo] = prestamo;
    cantidadPrestamos += 1;
    registrarTransaccion(fecha, transacciones, "agrego el prestamo numero " + to_string(prestamo.numeroPrestamo) + " a su nombre");
}

// Método para pagar una cuota de un préstamo
void Cliente::pagarPrestamo(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes){
    // Se pregunta si el pago es para sí mismo o para otra persona
    cout << "Hacia quien va dirigido el pago del prestamo?: " << endl;
    cout << "1. A mi persona." << endl;
    cout << "2. A otra persona." << endl;
    // Se lee la opción del usuario
    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    // Si el pago es para sí mismo
    if(opcion == 1){
        // Si el cliente no tiene préstamos asociados
        if(prestamos.size() == 0){
            // Se imprime un mensaje de error
            cout << "No tiene prestamos registrados a su nombre." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se imprimen los préstamos del cliente
        cout << "\n---Estos son sus prestamos---" << endl;
        mostrarPrestamos();
        // Se lee el número del préstamo del que se va a pagar la cuota
        int numeroPrestamoDestino;
        cout << "Ingrese el numero del prestamo que desea pagar: ";
        cin >> numeroPrestamoDestino;
        // Se busca el préstamo en el contenedor con los préstamos
        auto it_prestamoDestino = prestamos.find(numeroPrestamoDestino);
        // Si no se encuentra
        if(it_prestamoDestino == prestamos.end()){
            // Se imprime un mensaje de error
            cout << "El numero de prestamo ingresado no es valido." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se paga la cuota con el método de la clase Prestamo
        it_prestamoDestino->second.pagarCuota();
        // Se registra la transacción con la descripción adecuada
        registrarTransaccion(fecha, transacciones, nombre, id, "pago una cuota de un prestamo propio");
    }
    // Si el pago es para otra persona
    else if(opcion == 2){
        // Se lee el id de la persona a la que va dirigida el pago
        int idDestino;
        cout << "Ingrese el id de la persona a la que desea pagar el prestamo: ";
        cin >> idDestino;
        // Se busca el cliente en el contenedor con los clientes
        auto it_clienteDestino = clientes.find(idDestino);
        // Si no se encuentra
        if(it_clienteDestino == clientes.end()){
            // Se muestra un mensaje de error
            cout << "El id ingresado no existe en el registro." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Si el cliente destino no tiene préstamos asociados
        if(it_clienteDestino->second.prestamos.size() == 0){
            // Se imprime un mensaje de error
            cout << "El usuario ingresado no tiene prestamos registrados." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se imprimen los préstamos del cliente destino
        cout << "\n---Prestamos del cliente destino---" << endl;
        it_clienteDestino->second.mostrarPrestamos();
        // Se lee el número del préstamo que se desea pagar la cuota
        int numeroPrestamoDestino;
        cout << "Ingrese el numero del prestamo que desea pagar: ";
        cin >> numeroPrestamoDestino;
        // Se busca en el contenedor con los préstamos
        auto it_prestamoDestino = it_clienteDestino->second.prestamos.find(numeroPrestamoDestino);
        // Si no se encuentra
        if(it_prestamoDestino == it_clienteDestino->second.prestamos.end()){
            // Se imprime un mensaje de error
            cout << "El numero de prestamo ingresado no es valido." << endl;
            // Se detiene la ejecución del método
            return;
        }
        // Se paga la cuota con el método de la clase Prestamo
        it_prestamoDestino->second.pagarCuota();
        // Se registra la transacción con la descripción correcta
        registrarTransaccion(fecha, transacciones, nombre, id, "pago una cuota de un prestamo de otra persona");
    }
    // Si se ingresó una opción no válida
    else{
        // Se imprime un mensaje de error
        cout << "La opcion ingresada no es valida." << endl;
        // Se detiene la ejecución del programa
        return;
    }
}

void Cliente::mostrarPrestamos(){
    for(auto& par : prestamos){
        par.second.imprimirInfo();
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

void Cliente::agregarCDP(int fecha[], vector <string>& transacciones, map <int, CDP>& certificadosBanco){
    int plazoMeses;
    double tasaInteres;
    string tipo;
    int opcion = 0;
    while(1){
        cout << "\n---Opciones de Certificados de Deposito a Plazo---" << endl;
        cout << "1. Certificado a corto plazo." << endl;
        cout << "2. Certificado a mediano plazo." << endl;
        cout << "3. Certificado a largo plazo." << endl;
        cout << "4. Regresar." << endl;
        leerEntero(opcion, "Ingrese un opcion: ");
        if(opcion == 1){
            cout << "\n---Certificado a corto plazo---" << endl;
            cout << "Plazo en meses: " << PLAZOCORTO << endl;
            cout << "Tasa de interes: " << INTERESCORTO << endl;
            tipo = "corto";
            plazoMeses = PLAZOCORTO;
            tasaInteres = INTERESCORTO;
            break;
        }
        else if(opcion == 2){
            cout << "\n---Certificado a mediano plazo---" << endl;
            cout << "Plazo en meses: " << PLAZOMEDIANO << endl;
            cout << "Tasa de interes: " << INTERESMEDIANO << endl;
            tipo = "mediano";
            plazoMeses = PLAZOMEDIANO;
            tasaInteres = INTERESMEDIANO;
            break;
        }
        else if(opcion == 3){
            cout << "\n---Certificado a largo plazo---" << endl;
            cout << "Plazo en meses: " << PLAZOSLARGO << endl;
            cout << "Tasa de interes: " << INTERESLARGO << endl;
            tipo = "largo";
            plazoMeses = PLAZOSLARGO;
            tasaInteres = INTERESLARGO;
            break;
        }
        else if(opcion == 4){
            cout << "\nRegresando..." << endl; 
            return;
        }
        else{
            cout << "La opcion ingresada no es valida. Intente de nuevo." << endl;
        }
    }
    string tipoMoneda;
    leerMoneda(tipoMoneda);
    double dineroCDP;
    leerDouble(dineroCDP, "Ingrese el dinero que desea invertir en el certificado: ");
    CDP certificadoPlazo;
    int numeroCDP = stoi(to_string(id) + to_string(cantidadCDP + 1));
    certificadoPlazo.setDatos(id, numeroCDP, tipoMoneda, dineroCDP, fecha, plazoMeses, tasaInteres,tipo);
    certificadosBanco[numeroCDP] = certificadoPlazo;
    cantidadCDP +=1;
    registrarTransaccion(fecha, transacciones, "agrego el certificado a plazo numero " + to_string(certificadoPlazo.numeroCDP) + " a su nombre");
}

void Cliente::solicitarInformeCDP(int fecha[], vector <string>& transacciones, map <int, CDP>& certificadosBanco){
    if(cantidadCDP == 0){
        cout << "No tiene certificados a plazo registrados a su nombre." << endl;
        return;
    }
    string nombreArchivo = "informe_certificados_plazo.txt";
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    archivo << "Informe de certificados a plazo solicitado por el cliente" << endl;
    archivo << endl;
    archivo << "----------------------------Datos del cliente----------------------------" << endl;
    archivo << "id,nombre" << endl;
    archivo << to_string(id) + "," + nombre << endl;
    archivo << "----------------------------Certificados registrados----------------------------" << endl;
    for(auto& par : certificadosBanco){
        if(par.second.idPropietario == id){
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
    archivo.close();
    cout << "\nSe genero el archivo: " << nombreArchivo << endl;
    registrarTransaccion(fecha, transacciones, "solicito un informe de sus certificados a plazo");
}
