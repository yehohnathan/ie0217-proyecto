void Banco::crearCliente(){
    string nombre;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    int id;
    leerEntero(id, "Ingrese su id: ");
    if(id > 999999999){
        cout << "El id debe ser un numero menor a 999999999." << endl;
        return;
    }
    if(clientes.find(id) != clientes.end()){
        cout << "El id ingresado ya existe en el registro." << endl;
        return;
    }
    Cliente cliente;
    cliente.setDatos(nombre,id);
    clientes[id] = cliente;
    cout << "Se ha registrado correctamente!" << endl;
    string transaccion =  to_string(fecha[0]) + "/" + to_string(fecha[1]) + "/" + to_string(fecha[2]) + ","
    + nombre + "," + to_string(id) + "," + "se registro en el sistema";
    transacciones.push_back(transaccion);
}

void Banco::mostrarMenu(){
    setFecha();
    int opcion = 0;
    while(opcion != 4){
        cout << "\n---Menu de opciones---" << endl;
        cout << "1. Atencion al Cliente." << endl;
        cout << "2. Informacion de Prestamos." << endl;
        cout << "3. Registrarse." << endl;
        cout << "4. Salir." << endl;
        leerEntero(opcion, "Ingrese una opcion: ");
        switch (opcion){
        case 1:
            atenderCliente();
            break;
        case 2:
            informante.mostrarMenu();
            break;
        case 3:
            crearCliente();
            break;
        case 4:
            cout << "Gracias por utilizar nuestro Banco." << endl;
            break;
        default:
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
}


// Se ejecuta el método que permite la gestión de procesos mediante el objeto ventanilla
void Banco::atenderCliente(){
    // se instancia un variable que almacena el id del cliente
    int idCliente;
    cout << "Ingrese su id: ";
    // El usuario ingresa su id de cliente
    cin >> idCliente;
    auto it_cliente = clientes.find(idCliente); // Luego se pregunta si dentro del map hay un cliente con ese info de id
    if(it_cliente == clientes.end()){   // Si se llegó al final del map, significa que el id ingresado no pertenece a los clientes
        cout << "El id ingresado no existe en el registro." << endl;
        return; // Retorna la función, y hace regrese al menú
    }
    // Como el id si existió, entonces se utiliza el método mostrarMenu del objeto ventanilla.
    // En este se ingresa la info del cliente que ingreso el id, la info de todos los clientes, la fecha
    // y el vector de transacciones para que guarde la info de la transancción que se realizó
    ventanilla.mostrarMenu(fecha, it_cliente->second, clientes, transacciones);
}

// Método que debe ejecutarse al inicio del programa para garantizar el proceso del banco
void Banco::setFecha(){
    // Se crea un ciclo while que se repite hasta que se ingrese una fecha válida
    while(1){
        // Se le solicita la fecha al usuario
        cout << "Ingrese la fecha de hoy (dia mes año): ";
        try{
            // La fecha será guarda en un vector de tamaño 3. Se debería ingresar XX YY ZZZZ
            for(int i = 0; i < 3; i++){
                // Se van ingresando los datos al array fecha
                cin >> fecha[i];
            }
            // Luego se pregunta si se ingresó algo que no fuese un número entero
            if(cin.fail()){
                // Se limpia cin
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // Lanza un error para señalar que lo que se ingreso no fue correcto 
                throw invalid_argument("Todas las entradas deben ser numeros.");
            }
            // Se pregunta si lo ingresado esta en el formato correcto
            if(fecha[0] <= 0 || fecha[0] > 31 || fecha[1] <= 0 || fecha[1] > 12){
                throw "La fecha ingresada no es valida.";
            }
            break;
        }
        // Muestra el mensaje de error lanzado
        catch(const exception& e){
            cerr << e.what() << endl;
        }      
        catch(const char* mensajeError){
            cerr << mensajeError << endl;
        }    
    }
}