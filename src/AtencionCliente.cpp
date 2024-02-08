#include "AtencionCliente.hpp"

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