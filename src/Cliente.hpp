 /**
 * @file Cliente.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-14
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase Cliente.
 */


#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "CuentaBancaria.hpp"
#include "Prestamo.hpp"
#include "CDP.hpp"


/**
* @brief Clase que permite gestionar los datos y acciones de los clientes.
* 
* La clase Cliente tiene como métodos y atributos toda la información
* relacionada con el cliente y sus posibles acciones entre cuentas, préstamos y CDP.
* Además permite solicitar informes sobre su estado actual con la entidad bancaria.
*/
class Cliente {
    public:
        // Datos del cliente
        string nombre;          // Nombre del cliente
        int id;                 // ID del cliente
        int cantidadCuentas;    // Cantidad de cuentas
        int cantidadPrestamos;  // Cantidad de prestamos
        int cantidadCDP;        // Cantidad de CDP
        
        /*----- Métodos para setear datos, registrar transacciones y generar información -----*/
        
        /**
        * @brief Establece los datos del cliente.
        *
        * @param nombre Nombre del cliente.
        * @param id ID del cliente.
        * 
        */
        void setDatos(int id_p, string nombre_p);

        /**
        * @brief Agrega una transacción al registro de transacciones.
        *
        * @param fecha Array que representa la fecha (ddmmaa) de la transacción.
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param descripcion Descripción de la acción realizada por el usuario.
        * 
        */
        void registrarTransaccion(int fecha[], vector <string>& transacciones, string descripcion);
        
        /**
        * @brief Permite generar la información del cliente en un vector.
        * @param cuentasBanco Referencia al diccionario contenedor de las cuentas bancarias.
        * @param prestamosBanco Referencia al diccionario contenedor de las prestamos bancarios.
        * @param certificadosBanco Referencia al diccionario contenedor de las certificados
        * @return Devuelve un vector de strings con toda la información del cliente: datos, cuentas, préstamos y CDP.
        * 
        */
        vector <string> generarInfo(map <int, CuentaBancaria>& cuentasBanco, map <int, Prestamo>& prestamosBanco, map <int, CDP>& certificadosBanco);

        /*--------- Métodos de cuentas bancarias ---------*/

        /**
        * @brief Agrega una cuenta asociada al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param cuentasBanco Referencia al diccionario contenedor de las cuentas bancarias.
        * 
        */
        void agregarCuenta(int fecha[], vector <string>& transacciones, map <int, CuentaBancaria>& cuentasBanco);

        /**
        * @brief Permite retirar dinero de una cuenta bancaria.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param cuentasBanco Referencia al diccionario contenedor de las cuentas bancarias.
        * 
        */
        void retirarDinero(int fecha[], vector <string>& transacciones, map <int, CuentaBancaria>& cuentasBanco);

         /**
        * @brief Permite depositar dinero de una cuenta bancaria.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param clientes Contenedor con todos los clientes registrados.
        * @param cuentasBanco Referencia al diccionario contenedor de las cuentas bancarias.
        * 
        */
        void depositarDinero(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes, map <int, CuentaBancaria>& cuentasBanco);
        
        /**
        * @brief Permite transferir dinero de una cuenta bancaria a otra.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param clientes Contenedor con todos los clientes registrados.
        * @param cuentasBanco Referencia al diccionario contenedor de las cuentas bancarias.
        * 
        */
        void transferirDinero(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes, map <int, CuentaBancaria>& cuentasBanco);
        
        /**
        * @brief Imprime las cuentas bancarias asociadas al cliente.
        * @param cuentasBanco Referencia al diccionario contenedor de las cuentas bancarias.
        *
        */
        void mostrarCuentas(map <int, CuentaBancaria>& cuentasBanco);
        
        /**
        * @brief Permite solicitar un informe de las cuentas bancarias asociadas al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param cuentasBanco Referencia al diccionario contenedor de las cuentas bancarias.
        * 
        */
        void solicitarInformeCuentas(int fecha[], vector <string>& transacciones, map <int, CuentaBancaria>& cuentasBanco);

        /*--------- Métodos de prestamos ---------*/

        /**
        * @brief Agrega la información necesaria para un prestamo
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param prestamosBanco Referencia al diccionario contenedor de los prestamos Bancarios.
        * 
        */
        void agregarPrestamo(int fecha[], vector <string>& transacciones, map <int, Prestamo>& prestamosBanco);
        
        /**
        * @brief Pagar la información relacionada a un prestamo
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param clientes Contenedor con todos los clientes registrados.
        * @param prestamosBanco Referencia al diccionario contenedor de los prestamos Bancarios.
        * 
        */
        void pagarPrestamo(int fecha[], vector <string>& transacciones, map <int, Cliente>& clientes, map <int, Prestamo>& prestamosBanco);
        
        /**
        * @brief Muestra la información relacionada con el prestamo
        * @param prestamosBanco Referencia al diccionario contenedor de los prestamos Bancarios.
        * 
        */
        void mostrarPrestamos(map <int, Prestamo>& prestamosBanco);
        
        /**
        * @brief Permite solicitar un informe de las cuentas bancarias asociadas al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * 
        */
        void solicitarInformePrestamos(int fecha[], vector <string>& transacciones, map <int, Prestamo>& prestamosBanco);

        /*--------- Métodos de certificados ---------*/

        /**
        * @brief Agrega un certificado de depósito a plazo asociado al cliente.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * 
        */
        void agregarCDP(int fecha[], vector <string>& transacciones, map <int, CDP>& certificadosBanco);

        /**
        * @brief Agrega la información necesaria para un prestamo
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        * @param certificadosBanco Referencia al diccionario contenedor de los certificados bancarios.
        * 
        */
        void solicitarInformeCDP(int fecha[], vector <string>& transacciones, map <int, CDP>& certificadosBanco);
};

#endif // CLIENTE_HPP