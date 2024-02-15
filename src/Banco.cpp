#include "Banco.hpp"

// Método para establecer la fecha de la ejecución del programa. 
void Banco::setFecha(){
    while(1){
        // Se pide al usuario que ingresa la fecha en formato día mes año. 
        cout << "Ingrese la fecha de hoy (dd mm aaaa): ";
        // Se intenta leer cada parte de la fecha. 
        try{
            for(int i = 0; i < 3; i++){
                cin >> fecha[i];
            }
            // Si la lectura tiene algún problema es porque no se ingresó un número entero. 
            if(cin.fail()){
                // Se descarta la lectura errónea realizada. 
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // Se lanza una excepcion con un mensaje que indica que todas las entradas deben ser número enteros. 
                throw invalid_argument("Todas las entradas deben ser numeros. Intente de nuevo.");
            }
            // Si el día ingresado es mayor a 31 o el mes ingresado es mayor a 12 la fecha ingresada no existe. 
            if(fecha[0] <= 0 || fecha[0] > 31 || fecha[1] <= 0 || fecha[1] > 12){
                // Se lanza una excepción con un mensaje de que la fecha no es válida. 
                throw "La fecha ingresada no es valida. Intente de nuevo.";
            }
            // Si todo sale bien se sale del bloque while y deja de preguntar. 
            break;
        }
        // Se recibe la excepcion cuando la lectura tuvo un problema. 
        catch(const exception& e){
            // Se imprime el mensaje de argumento inválido. 
            cerr << e.what() << endl;
        }      
        // Se recibe la excepción cuando la fecha ingresada no existe en el calendario. 
        catch(const char* mensajeError){
            // Se imprime el mensaje de error. 
            cerr << mensajeError << endl;
        }    
    }
}

// Método para leer el archivo .txt con las transacciones de los usuarios. 
void Banco::leerTransacciones(){
    // Se abre el archivo en modo de lectura. 
    string nombreArchivo = "registro_transacciones.txt";
    ifstream archivo(nombreArchivo);
    string linea;
    // Se ignoran las primeras 3 líneas que son el encabezado. 
    getline(archivo,linea);
    getline(archivo,linea);
    getline(archivo,linea);
    // Para cada una de las líneas en el archivo. 
    while(getline(archivo,linea)){
        // Se agrega la línea al contenedor con todas las transacciones de los clientes. 
        transacciones.push_back(linea);
    }
    // Se cierra el archivo.
    archivo.close();
}

// Método para actualizar el archivo .txt con las transacciones de los clientes. 
void Banco::actualizarTransacciones(){
    // Se crea si no existe y se abre un archivo .txt de registro de transacciones. 
    string nombreArchivo = "registro_transacciones.txt";
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    // Se agrega un encabezado al archivo. 
    archivo << "Registro de transacciones realizadas por los usuarios" << endl;
    archivo << endl;
    // Se agrega un encabezado de la información de las transacciones con los títulos de cada columna. 
    archivo << "fecha,id,nombre,descripcion" << endl;
    // Pata cada línea del vector con todas las transacciones. 
    for (auto& transaccion : transacciones) {
        // Se escribe la línea en el archivo .txt. 
        archivo << transaccion << endl;
    }
    // Se cierra el archivo. 
    archivo.close();
    // Se imprime un mensaje que indica que se pudo generar o actualizar el archivo correctamente. 
    cout << "\nSe actualizo el archivo: " << nombreArchivo << endl;
    cout << endl;
}

// Método para dividir un string en un contenedor de strings separando con un separador indicado. 
vector <string> Banco::dividir(string linea, string separador){
    // Se crea un vector de strings para los elementos de la separación. 
    vector<string> valores;
    // Se establece la posición inicial a cero en el recorrido por el string.
    size_t pos = 0;
    // Se define una variable para guardar el elemento actual. 
    string valor;
    // Mientas no se encuentre el separador
    while ((pos = linea.find(separador)) != string::npos) {
        // Se leen los caracteres que generan el elemento actual hasta que se encuentra el separador. 
        valor = linea.substr(0, pos);
        // Se agrega el elemento al vector con todos los elementos. 
        valores.push_back(valor);
        // Se elimina el elemento y el separador que le sigue del string inicial. 
        linea.erase(0, pos + 1);
    }
    // Cuando llega al final se agrega todo lo que queda de la línea. 
    valores.push_back(linea);
    // Se agrega el valor al contenedor con todos los elementos. 
    return valores;
}

// Método para leer el archivo .txt con la información de los clientes. 
void Banco::leerInfoClientes(){
    // Se abre el archivo .txt en modo de lectura. 
    string nombreArchivo = "info_clientes.txt";
    ifstream archivo(nombreArchivo);
    string linea;
    // Se ignoran las primeras dos líneas que son el encabezado del archivo. 
    getline(archivo,linea);
    getline(archivo,linea);

    // Se lee cada línea del archivo hasta que ya no hayan líneas. 
    while(getline(archivo,linea)){
        // Si la línea esta vacía
        if(linea.empty()){
            // Se continua con la siguiente línea. 
            continue;
        }
        // Se divide la línea en los elementos que contiene separados por comas. 
        vector <string> elementosLinea = dividir(linea, ",");
        // Si el primer elemento es la palabra datos se refiere a los datos de un cliente. 
        if(elementosLinea[0] == "datos"){
            // Se crea un objeto de la clase Cliente. 
            Cliente cliente;
            // Se convierte a un int el segundo elemento que representa el ID del cliente. 
            int id = stoi(elementosLinea[1]);
            // Se asigna el tercer elemento como el nombre del cliente. 
            string nombre = elementosLinea[2];
            // Se setean los datos del cliente: el ID y el nombre. 
            cliente.setDatos(id,nombre);
            // Se agrega el cliente al contenedor con todos los clientes registrados en el Banco. 
            clientes[id] = cliente;
        }
        // Si el segundo elemento es la palabra cuenta se refiere a los datos de una cuenta bancaria. 
        else if(elementosLinea[0] == "cuenta"){
            // Se crea un objeto de la clase CuentaBancaria. 
            CuentaBancaria cuenta;
            // Se convierte a un int el segundo elemento de la línea que representa el ID del propietario. 
            int id = stoi(elementosLinea[1]);
            // Se convierte a un int el tercer elemento de la línea que representa el número de cuenta. 
            int numeroCuenta = stoi(elementosLinea[2]);
            // Se asigna el cuarto elemento de la línea como el tipo de moneda. 
            string tipoMoneda = elementosLinea[3];
            // Se convierte a un double el quinto elemento que representa el dinero en la cuenta. 
            double dineroAhorros = stod(elementosLinea[4]);
            // Se setean los datos con el ID del cliente, número de cuenta, tipo de moneda y dinero de ahorros correspondiente. 
            cuenta.setDatos(id,numeroCuenta,tipoMoneda,dineroAhorros);
            // Se agrega la cuenta al contenedor con todas las cuentas de los clientes del banco. 
            cuentasBanco[numeroCuenta] = cuenta;
            // Se busca el cliente por su ID en el contenedor de los clientes. 
            auto it_cliente = clientes.find(id);
            // Se agrega 1 a la cantidad de cuentas que tiene el cliente. 
            it_cliente->second.cantidadCuentas += 1;
        }
        // Si el primero elemento de la línea es la palabra prestamo se refiere a un prestamo de un cliente. 
        else if(elementosLinea[0] == "prestamo"){
            // Se crea un objeto de la clase Prestamo. 
            Prestamo prestamo;
            // Se convierte a int el segundo elemento que representa el ID del propietario del préstamo. 
            int id = stoi(elementosLinea[1]);
            // Se convierte a int el tercer elemento de la línea que representa el número del préstamo. 
            int numeroPrestamo = stoi(elementosLinea[2]);
            // Se asigna el cuarto elemento de la línea como el tipo de préstamo. 
            string tipo = elementosLinea[3];
            // Se asigna el quinto elemento de la línea como el tipo de moneda. 
            string tipoMoneda = elementosLinea[4];
            // Se convierte a double el sexto elemento que representa el monto total del préstamo. 
            double montoTotal = stod(elementosLinea[5]);
            // Se convierte a int el séptimo elemento de la línea que representa la cantidad total de cuotas. 
            int cuotasTotal = stoi(elementosLinea[6]);
            // Se convierte a double el octavo elemento de la línea que representa la tasa de interés. 
            double tasaInteres = stod(elementosLinea[7]);
            // Se convierte a int el noveno elemento que representa la cantidad de cuotas pagadas. 
            int cuotasPagadas = stoi(elementosLinea[8]);
            // Se setean los datos del préstamo: el ID del propietario, número, tipo moneda, monto, cuotas, interés, etc. 
            prestamo.setDatos(id,numeroPrestamo,tipoMoneda,montoTotal,cuotasTotal,tasaInteres,cuotasPagadas,tipo);
            // Se agrega el objeto prestamo al contenedor con los préstamos de todos los clientes. 
            prestamosBanco[numeroPrestamo] = prestamo;
            // Se busca el cliente por medio de su ID en el contenedor con todos los clientes. 
            auto it_cliente = clientes.find(id);
            // Se agrega 1 a la cantidad de préstamos que tiene el usuario. 
            it_cliente->second.cantidadPrestamos += 1;
        }
        // Si el primer elemento de la línea es la abreviatura cdp. 
        else if(elementosLinea[0] == "cdp"){
            // Se crea un objeto de la clase CDP. 
            CDP certificadoPlazo;
            // Se convierte a int el segundo elemento de la línea que representa el ID del propietario. 
            int id = stoi(elementosLinea[1]);
            // Se convierte a int el tercer elemento que representa el número de cdp. 
            int numeroCDP = stoi(elementosLinea[2]);
            // Se asigna el cuarto elemento de la línea como tipo de cdp. 
            string tipo = elementosLinea[3];
            // Se asigna el quinto elemento de la línea como el tipo de moneda del cdp. 
            string tipoMoneda = elementosLinea[4];
            // Se convierte a double el sexto elemento que representa el dinero invertido en el CDP. 
            double dineroCDP = stod(elementosLinea[5]);
            // Se crea un array que representa la fecha de la ejecución del programa. 
            int fechaCreacion[3];
            // Se divide el séptimo elemento que representa la fecha por medio de los símbolos /
            vector <string> fecha_string = dividir(elementosLinea[6], "/");
            // El primer elemento se convierte a int y se define como el día
            fechaCreacion[0] = stoi(fecha_string[0]);
            // El segundo elemento se convierte a int y se define como el mes
            fechaCreacion[1] = stoi(fecha_string[1]);
            // El tercer elemento se convierte a int y se define como el año
            fechaCreacion[2] = stoi(fecha_string[2]);

            // Se convierte a int el octavo elemento que representa el plazo en meses.
            int plazoMeses = stoi(elementosLinea[7]);
            // Se convierte a double el noveno elemento que representa la tasa de interés. 
            double tasaInteres = stod(elementosLinea[8]);

            // Se setean los datos de ID, número, tipo de moneda, etc en el objeto de la clase CDP. 
            certificadoPlazo.setDatos(id,numeroCDP,tipoMoneda,dineroCDP,fechaCreacion,plazoMeses,tasaInteres,tipo);
            // Se agrega el certificado al contenedor con los certificados a plazo de todos los clientes del banco. 
            certificadosBanco[numeroCDP] = certificadoPlazo;
            // Se busca el cliente por su ID en el contenedor de los clientes.
            auto it_cliente = clientes.find(id);
            // Se agrega 1 a la cantidad de certificados que tiene el cliente. 
            it_cliente->second.cantidadCDP += 1;
        }
        else{
            // Si el primer elemento de la línea no dice nada de lo anterior se considera defectuosa y se continua con la siguiente. 
            continue;
        }
    }
    // Se cierra el archivo. 
    archivo.close();
}

// Método para actualizar la información de los clientes.
void Banco::actualizarInfoClientes(){
    // Se abre el archivo en modo de escritura. Si no existe lo crea. 
    string nombreArchivo = "info_clientes.txt";
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    // Se agrega un encabezado para el archivo.
    archivo << "Informacion de los clientes" << endl;
    archivo << endl;
    // Para cada cliente en el contenedor con los clientes. 
    for (auto& par : clientes) {
        // Se genera la información del cliente con el método de la clase Cliente. 
        for(auto& linea : par.second.generarInfo(cuentasBanco, prestamosBanco, certificadosBanco)){
            // Se escribe cada línea en el archivo .txt. 
            archivo << linea << endl;
        }
        // Se escribe una linea en blanco. 
        archivo << endl;
    }
    // Se cierra el archivo. 
    archivo.close();
    // Se imprime un mensaje que indica que se actualizo o genero el archivo correctamente. 
    cout << "\nSe actualizo el archivo: " << nombreArchivo << endl;
}

// Método para crear un cliente 
void Banco::crearCliente(){
    // Se crea una variable para el nombre del cliente. 
    string nombre;
    // Se lee el nombre del cliente. 
    leerNombre(nombre);
    // Se crea y se lee una variable para el ID del cliente. 
    int id;
    leerEntero(id, "Ingrese su id: ");
    // Se busca el ID ingresado en el contenedor con los clientes. 
    if(clientes.find(id) != clientes.end()){
        // Si se encuentra es porque ya existe ese ID así que se imprime un mensaje de error. 
        cout << "El id ingresado ya existe en el registro." << endl;
        // Se termina la ejecución del método. 
        return;
    }
    // Se crea un objeto de la clase Cliente. 
    Cliente cliente;
    // Se setean los datos ingresados. 
    cliente.setDatos(id,nombre);
    // Se añade el cliente al contenedor con todos los clientes del banco. 
    clientes[id] = cliente;
    // Se imprime un mensaje de que se ha registrado exitosamente. 
    cout << "\nSe ha registrado correctamente!" << endl;
    // Se añade una transacción al contenedor con las transacciones que indica que se registro un cliente nuevo. 
    string transaccion =  to_string(fecha[0]) + "/" + to_string(fecha[1]) + "/" + to_string(fecha[2]) + ","
    + to_string(id)+ "," + nombre + "," + "se registro en el sistema";
    // Se agrega a las transacciones. 
    transacciones.push_back(transaccion);
}

