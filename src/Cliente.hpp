 /**
 * @file Cliente.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-07
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase Cliente.
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <bits/stdc++.h>
#include "CuentaBancaria.hpp"
#include "Prestamo.hpp"

/**
* @brief Clase que permite gestionar los datos y acciones de los clientes.
* 
* La clase Cliente tiene como métodos y atributos toda la información
* relacionada con el cliente y sus posibles acciones entre cuentas, préstamos y CDP.
* Además permite solicitar informes sobre su estado actual con la entidad bancaria.
*/
class Cliente {
    public:
        string nombre; // Nombre del cliente
        int id; // ID del cliente
        map <int, CuentaBancaria> cuentas; // Contenedor con las cuentas bancarias del cliente
        map <int, Prestamo> prestamos; // Contenedor con los préstamos del cliente
        
        /**
        * @brief Agrega una transacción al registro de transacciones.
        *
        * @param fecha Array que representa la fecha (ddmmaa) de la transacción.
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param nombre Nombre del cliente que realiza la transacción.
        * @param id ID del cliente que realiza la transacción.
        * @param descripcion Descripción de la acción realizada por el usuario.
        * 
        */
        void registrarTransaccion(int fecha[], vector <string>& transacciones, string nombre, int id, string descripcion);

        /**
        * @brief Establece los datos del cliente.
        *
        * @param nombre Nombre del cliente.
        * @param id ID del cliente.
        * 
        */
        void setDatos(string nombre_p, int id_p);

        /**
        * @brief Agrega una cuenta asociada al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * 
        */
        void agregarCuenta(int fecha[], vector <string>& transacciones);

        /**
        * @brief Agrega un préstamo asociado al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * 
        */
        void agregarPrestamo(int fecha[], vector <string>& transacciones);

        /**
        * @brief Permite retirar dinero de una cuenta bancaria.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * 
        */
        void retirarDinero(int fecha[], vector <string>& transacciones);

        /**
        * @brief Permite depositar dinero de una cuenta bancaria.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param clientes Contenedor con todos los clientes registrados.
        * 
        */
        void depositarDinero(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes);

        /**
        * @brief Permite transferir dinero de una cuenta bancaria a otra.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param clientes Contenedor con todos los clientes registrados.
        * 
        */
        void transferirDinero(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes);

        /**
        * @brief Permite pagar una cuota de un préstamo.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param clientes Contenedor con todos los clientes registrados.
        * 
        */
        void pagarPrestamo(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes);

        /**
        * @brief Imprime las cuentas bancarias asociadas al cliente.
        *
        */
        void mostrarCuentas();

        /**
        * @brief Imprime las cuentas bancarias asociadas al cliente.
        *
        */
        void mostrarPrestamos();

        /**
        * @brief Permite solicitar un informe de los préstamos asociados al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * 
        */
        void solicitarInformePrestamos(int fecha[], vector <string>& transacciones);

        /**
        * @brief Permite solicitar un informe de las cuentas bancarias asociadas al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * 
        */
        void solicitarInformeCuentas(int fecha[], vector <string>& transacciones);

        /**
        * @brief Agrega un certificado de depósito a plazo asociado al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * 
        */
        void solicitarCDP(int fechaCreacion[], vector <string>& transacciones);

        /**
        * @brief Permite generar la información del cliente en un vector.
        * @return Devuelve un vector de strings con toda la información del cliente: datos, cuentas, préstamos y CDP.
        * 
        */
        vector <string> generarInfo();
};

#endif // CLIENTE_HPP