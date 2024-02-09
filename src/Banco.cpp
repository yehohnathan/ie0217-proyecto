void Banco::actualizarTransacciones(){
    string nombreArchivo = "registro_transacciones.txt";
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    archivo << "Registro de transacciones realizadas por los usuarios" << endl;
    archivo << endl;
    archivo << "fecha,nombre,id,descripcion" << endl;
    for (auto& transaccion : transacciones) {
        archivo << transaccion << endl;
    }
    archivo.close();
    cout << "Se actualizo el archivo de log: " << nombreArchivo << endl;
    cout << endl;
}

void Banco::atenderCliente(){
    int idCliente;
    leerEntero(idCliente, "Ingrese su id: ");
    auto it_cliente = clientes.find(idCliente);
    if(it_cliente == clientes.end()){
        cout << "El id ingresado no existe en el registro." << endl;
        return;
    }
    ventanilla.mostrarMenu(fecha, it_cliente->second, clientes, transacciones);
}

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