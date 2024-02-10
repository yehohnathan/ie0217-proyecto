// Instancia del header correspondiente
#include "CuentaBancaria.hpp"

// Método que solo se utiliza una única vez para la creación de una cuenta bancaria
void CuentaBancaria::setDatos(int idPropietario_p, int numeroCuenta_p, string tipoMoneda_p, double dineroAhorros_p){
    // El usuario selecciona el tipo de moneda de la cuenta, modificando el atributo
    // público
    tipoMoneda = tipoMoneda_p;
    // El saldo de la cuenta, que puede ser lo que el cliente deseé
    dineroAhorros = dineroAhorros_p;
    // Identificadores de la cuenta y el cliente inicializados
    idPropietario = idPropietario_p;
    numeroCuenta = numeroCuenta_p;
}

// Este método muestra la información de numeroCuenta (escogido en el momento que se va
// crear la cuenta), tipo de moneda y el saldo disponible (dineroAhorros).
void CuentaBancaria::imprimirInfo(){
    cout << "\n---Cuenta numero " << numeroCuenta << "---" << endl;
    cout << "Tipo de moneda: " << tipoMoneda << endl;
    cout << "Dinero de ahorros: " << dineroAhorros << endl;
}

// Este método permite depositar dinero a una cuenta
void CuentaBancaria::depositar(){
    // Se define una variable que guardará el monto a depositar
    double montoDepositar;
    // Se recibe del usuario el monto a depositar y verifica el dato ingresado 
    // a partir de un método de LeerDatos
    leerDouble(montoDepositar, "Ingrese el monto que desea depositar: ");
    // Se agrega esa cantidad al dinero de ahorros de la cuenta
    dineroAhorros += montoDepositar;
}

// Este método permite retirar dinero de una cuenta
void CuentaBancaria::retirar(){
    // Se define una variable que guardará el monto a retirar
    double montoRetirar;
    // Se recibe del usuario el monto a retirar y verifica el dato ingresado 
    // a partir de un método de LeerDatos
    leerDouble(montoRetirar, "Ingrese el monto que desea retirar: ");
    // Se revisa si el monto a retirar es mayor que el dinero que hay en la cuenta
    if(montoRetirar > dineroAhorros){
        // En caso de que sea mayor se imprime un mensaje que indica que no hay fondos suficientes
        cout << "No hay suficiente dinero en la cuenta." << endl;
        // Se termina la ejecución del método
        return;
    }
    // Si todo sale bien se retira esa cantidad del dinero de ahorros de la cuenta
    dineroAhorros -= montoRetirar;
}

// Este método permite transferir dinero de una cuenta a otra
// Se recibe una referencia a otro objeto de la clase CuentaBancaria que es la cuenta destino
void CuentaBancaria::transferir(CuentaBancaria& cuentaDestino){
    // Se define una variable que guardará el monto a transferir
    double montoTransferir;
    // Se recibe del usuario el monto a transferir y verifica el dato ingresado 
    // a partir de un método de LeerDatos
    leerDouble(montoTransferir, "Ingrese el monto que desea transferir: ");
    // Se revisa si el monto a transferir es mayor que el dinero que hay en la cuenta de salida
    if(montoTransferir > dineroAhorros){
        // En caso de que sea mayor se imprime un mensaje que indica que no hay fondos suficientes
        cout << "No hay suficiente dinero en la cuenta de salida." << endl;
        // Se termina la ejecución del método
        return;
    }
    // Si todo sale bien se retira esa cantidad del dinero de ahorros de la cuenta de salida
    dineroAhorros -= montoTransferir;
    // Se agrega esa cantidad al dinero de ahorros de la cuenta destino
    cuentaDestino.dineroAhorros += montoTransferir;
}