#include "Banco.hpp"

// Método encargado de crear un cliente y agragarlo al "sistema"
void Banco::crearCliente(){
    // Inicializa una variable de tipo string que contendra el nombre
    string nombre;
    // Imprime un mensaje en consola
    cout << "Ingrese su nombre: ";
    // Asigna el dato ingresado a la variable nombre
    cin >> nombre;
    // Inicializa una variable de tipo int que contenfra el id
    int id;
    // Llama a la función leer entero para determinar si es un dato válido
    leerEntero(id, "Ingrese su id: ");
    // Comrpueba si el ID esta dentro del rango
    if(id > 999999999){
        // En caso de que no este, imprime una pequeña abvertencia
        cout << "El id debe ser un numero menor a 999999999." << endl;
        return;
    }
    // Comprueba si el id ingresado no estaba ya registrado en el contenedor
    if(clientes.find(id) != clientes.end()){
        // En caso de que este, imprime una pequeña abvertencia
        cout << "El id ingresado ya existe en el registro." << endl;
        return;
    }
    // Instancia un objeto de tipo cliente
    Cliente cliente;
    // llama al método establecer Datos
    cliente.setDatos(nombre,id);
    // Guarda la información del cliente en la posición 'id' del contenedor
    clientes[id] = cliente;
    cout << "Se ha registrado correctamente!" << endl;
    // Guarda información para las futuras transacciones
    string transaccion =  to_string(fecha[0]) + "/" + to_string(fecha[1]) + "/" + to_string(fecha[2]) + ","
    + nombre + "," + to_string(id) + "," + "se registro en el sistema";
    // La ingresa al contenedor con la información de las transacciones
    transacciones.push_back(transaccion);
}

// Método encargado de mostrar el menú de opciones
void Banco::mostrarMenu(){
    // Llamado al método para solicitar la fecha del sistema
    setFecha();
    // inicializa la variable que contendra la opción elegida
    int opcion = 0;
    // itera por la opción elegida por el usuario
    while(opcion != 4){
        // imprime un menú de opciones
        cout << "\n---Menu de opciones---" << endl;
        cout << "1. Atencion al Cliente." << endl;
        cout << "2. Informacion de Prestamos." << endl;
        cout << "3. Registrarse." << endl;
        cout << "4. Salir." << endl;
        // Válida la opción ingresada
        leerEntero(opcion, "Ingrese una opcion: ");
        // Evalua cual caso fue el solicitado
        switch (opcion){
        case 1:
            // Llama a atender cliente
            atenderCliente();
            break;
        case 2:
            // Llama a mostrar información
            informante.mostrarMenu();
            break;
        case 3:
            // Llama a crear cliente
            crearCliente();
            break;
        case 4:
            // Finaliza el programa
            cout << "Gracias por utilizar nuestro Banco." << endl;
            break;
        default:
            // Mensaje de error
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