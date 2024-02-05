// Instancia del header correspondiente
#include "CuentaBancaria.hpp"

// Método que solo se utiliza una única vez para la creación de una cuenta bancaria
void CuentaBancaria::setDatos(string tipoMoneda_p){
    // El usuario selecciona el tipo de moneda de la cuenta, modificando el atributo
    // público
    tipoMoneda = tipoMoneda_p;
    // El saldo de la cuenta inicia siendo 0
    dineroAhorros = 0;
}

// Este método muestra la información de numeroCuenta (escogido en el momento que se va
// crear la cuenta), tipo de moneda y el saldo disponible (dineroAhorros).
void CuentaBancaria::imprimirInfo(){
    cout << "\n---Cuenta numero " << numeroCuenta << "---" << endl;
    cout << "Tipo de moneda: " << tipoMoneda << endl;
    cout << "Dinero de ahorros: " << dineroAhorros << endl;
}