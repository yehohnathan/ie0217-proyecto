#include "AtencionCliente.hpp"


// Muestra el menú de opciones que el cliente tendrá disponible en la Atención al cliente
void AtencionCliente::mostrarMenu(int fecha[], Cliente& cliente, map <int, Cliente>& clientes, vector <string>& transacciones){
    // Recibe un mensaje de bienvenida con el respectivo nombre del cliente, y se le muestran las opciones
    cout << "\nHola " << cliente.nombre << ". Estas en la seccion de Atencion al Cliente." << endl;
    int opcion = 0; // Variable que solo admite número enteros
    while(opcion != 3){ // Loop que se repite siempre y cuando la opción no sea regresar al menu principal
        cout << "\n---Acciones que puede realizar---" << endl;
        cout << "1. Tramites de Cuentas Bancarias." << endl;
        cout << "2. Tramites de Prestamos." << endl;
        cout << "3. Regresar al menu principal." << endl;
        cout << "Ingrese una opcion: ";
        // El usuario ingresa un número
        cin >> opcion;
        switch (opcion){
        case 1:
            // Se dirige al método de gestionar cuentas
            gestionarCuentas(fecha, cliente, clientes, transacciones);
            // Rompe el swicth-case y se le vuelve a preguntar al cliente por opciones
            break;
        case 2:
            // Se dirige el método de gestionar prestamos
            gestionarPrestamos(fecha, cliente, clientes, transacciones);
            // Rompe el swicth-case y se le vuelve a preguntar al cliente por opciones
            break;
        case 3:
            // Sale del programa
            cout << "Regresando al menu principal..." << endl;
            break;
        default:
            // Mensaje de que la opción no es válida y le soliciona nuevamente que ingrese una opción
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
}

// Método para gestionar las cuentas del cliente
void AtencionCliente::gestionarCuentas(int fecha[], Cliente& cliente, map <int, Cliente>& clientes, vector <string>& transacciones){
    // Una vez se seleccionó la opción 1 en el método mostrarMenu() se muestra el nuevo menu
    int opcion = 0; // Variable que solo admite número enteros
    // La finalidad de este ciclo while es que el usuario pueda inrgesar a todos los métodos
    // de la clase cliente que tienen que ver con cuentas bancarias. Adicionalmente se considero
    // que en este espacio también se solicitara el CDP
    while(opcion != 7){ // Loop que se repite siempre y cuando la opción no sea regresar al menu principal 
        cout << "\n---Tramites de Cuentas Bancarias---" << endl;
        cout << "1. Agregar una cuenta a su nombre." << endl;
        cout << "2. Retirar dinero de ahorros de una de sus cuentas." << endl;
        cout << "3. Depositar dinero a una cuenta." << endl;
        cout << "4. Transferior dinero a una cuenta." << endl;
        cout << "5. Solicitar un Certificado de Deposito a Plazo." << endl;
        cout << "6. Solicitar informe de sus cuentas actuales." << endl;
        cout << "7. Regresar." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
        case 1:
            // Ingresa al método se agregar cuenta de la clase cliente (solo se puede hacer dos veces)
            cliente.agregarCuenta(fecha, transacciones);
            // Rompe el swicth-case y se le vuelve a preguntar al cliente por opciones
            break;
        case 2:
            // Ingresa al método para retirar dinero en alguna de las cuentas del cliente
            cliente.retirarDinero(fecha, transacciones);
            // Rompe el swicth-case y se le vuelve a preguntar al cliente por opciones
            break;
        case 3:
            // Ingresa al método para depositar dinero en alguna de las cuentas del cliente
            cliente.depositarDinero(fecha, transacciones, clientes);
            // Rompe el swicth-case y se le vuelve a preguntar al cliente por opciones
            break;
        case 4:
            // Ingresa al método para transferir dinero en alguna de las cuentas del cliente u otro cliente
            cliente.transferirDinero(fecha, transacciones, clientes);
            // Rompe el swicth-case y se le vuelve a preguntar al cliente por opciones
            break;
        case 5:
            // Solicita un certificadode largo plazo CDP
            cliente.solicitarCDP(fecha, transacciones);
            // Rompe el swicth-case y se le vuelve a preguntar al cliente por opciones
            break;
        case 6:
            // Se genera el informe de cuentas con el método de la clase Cliente
            cliente.solicitarInformeCuentas(fecha, transacciones);
            // Rompe el swicth-case y se le vuelve a preguntar al cliente por opciones
            break;
        case 7:
            // Se imprime un mensaje de que se está regresando
            cout << "Regresando..." << endl;
            // Sale del ciclo while
            break;
        default:
            // Mensaje de que la opción no es válida y le soliciona nuevamente que ingrese una opción
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
}

// Método para gestionar los préstamos de los clientes 
void AtencionCliente::gestionarPrestamos(int fecha[], Cliente& cliente, map <int, Cliente>& clientes, vector <string>& transacciones){
    // Se muestra un menú con las posibles acciones sobre préstamos
    int opcion = 0;
    // Se muestra el menú siempre que la opción ingresada no sea la de salir
    while(opcion != 4){
        cout << "\n---Tramites de Prestamos---" << endl;
        cout << "1. Solicitar un prestamo a su nombre." << endl;
        cout << "2. Pagar cuota de un prestamo." << endl;
        cout << "3. Solicitar informe de sus prestamos actuales." << endl;
        cout << "4. Regresar." << endl;   
        // Se lee la opción elegida por el usuario
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
        // Si quiere solicitar un préstamo
        case 1:
            // Se agrega el préstamo con el método de la clase Cliente
            cliente.agregarPrestamo(fecha, transacciones);
            // Se sale del switch
            break;
        // Si quiere pagar una cuota de un préstamo
        case 2:
            // Se paga la cuota del préstamo con el método de la clase Cliente
            cliente.pagarPrestamo(fecha, transacciones, clientes);
            // Se sale del switch
            break;
        // Si quiere solicitar un informe de sus préstamos
        case 3:
            // Se genera el informe con el método de la clase Cliente
            cliente.solicitarInformePrestamos(fecha, transacciones);
            // Se sale del switch
            break;
        // Si quiere regresar el menú anterior
        case 4:
            // Se imprime un mensaje de que se está regresando
            cout << "Regresando..." << endl;
            // Se sale del swtich
            break;
        // Si la opción ingresada no está entre las opciones brindadas
        default:
            // Se imprime un mensaje de error
            cout << "La opcion ingresada no es valida." << endl;
            // Se sale del switch
            break;
        }
    }
}