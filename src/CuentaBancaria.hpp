 /**
 * @file CuentaBancaria.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-04
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase CuentaBancaria.
 */

#ifndef CUENTABANCARIA_HPP
#define CUENTABANCARIA_HPP

// Se incluyen las librerías a utilizar
#include <iostream>
#include <string>
using namespace std;

// Librería fundamental que permite la verificación de todos los datos ingresados por el usuario
#include "LecturaDatos.hpp"

/**
* @brief Clase encargada de gestionar las cuentas de ahorros del cliente.
* 
* La clase CuentaBancaria cuenta con los atributos numeroCuenta (identificación),
* tipoMoneda (dolares o colones) y dineroAhorros (saldo disponible) para simular
* una cuenta real. Cambiando el contenido de dineroAhorros cada vez que el cliente
* realice una transacción (retiro, deposito o transferencia)
*/
class CuentaBancaria {
    public:
        int numeroCuenta;       //< Identificador de la cuenta bancaria
        int idPropietario;      //< Identificador del prestamo según el cliente
        string tipoMoneda;      //< Tipo de moneda (dolares o colones) de la cuenta
        double dineroAhorros;   //< Saldo disponible del cliente en la cuenta
        
        /**
        * @brief Establece el tipo de moneda al momento de crear la cuenta de ahorros.
        *
        * @param idPropietario_p Identificador del cliente, dueño de la cuenta
        * @param numeroCuenta_p Identificador de la cuenta, a partir del idPropietario
        * @param tipoMoneda_p Tipo de moneda (dolares o colones) de la cuenta
        * @param dineroAhorros_p Cantidad de dinero que tiene la cuenta (inicialmente)
        */
        void setDatos(int idPropietario_p, int numeroCuenta_p, string tipoMoneda_p, double dineroAhorros_p);

        /**
         * @brief Muestra el número de cuenta, moneda y saldo disponible de la cuenta.
         */
        void imprimirInfo();

        /**
         * @brief Permite ingresar dinero a la cuenta, sumandole valor a dineroAhorros.
         */
        void depositar();

        /**
         * @brief Permite sacar dinero a la cuenta, restandole valor a dineroAhorros.
         */
        void retirar();

        /**
         * @brief Permite trasladar dinero a cuenta destino, restandole valor a dineroAhorros.
         * 
         * @param cuentaDestino Cuenta a la que se va a transferir el dinero
         */
        void transferir(CuentaBancaria& cuentaDestino);
};

#endif // CUENTABANCARIA_HPP