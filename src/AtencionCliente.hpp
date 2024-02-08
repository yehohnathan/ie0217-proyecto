 /**
 * @file AtencionCliente.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-07
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase AtencionCliente.
 */

#ifndef ATENCIONCLIENTE_HPP
#define ATENCIONCLIENTE_HPP

#include "Cliente.hpp"

/**
* @brief Clase que permite gestionar las acciones de los clientes.
* 
* La clase Cliente tiene métodos para poder gestionar las acciones de los usuarios.
* Incluye varios menús que permiten al usuario moverse en el programa y realizar transacciones.
*/
class AtencionCliente {
    public:
        /**
        * @brief Muestra el menú de opciones.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param cliente Referencia al cliente que se está atendiendo en ese momento.
        * @param clientes Referencia al contenedor con todos los clientes de la entidad bancaria.
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        */
        void mostrarMenu(int fecha[], Cliente& cliente, map <int, Cliente>& clientes, vector <string>& transacciones);

        /**
        * @brief Permite gestionar las acciones relacionadas con las cuentas bancarias.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param cliente Referencia al cliente que se está atendiendo en ese momento.
        * @param clientes Referencia al contenedor con todos los clientes de la entidad bancaria.
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        */
        void gestionarCuentas(int fecha[], Cliente& cliente, map <int, Cliente>& clientes, vector <string>& transacciones);

        /**
        * @brief Permite gestionar las acciones relacionadas con los préstamos.
        *
        * @param fecha Array que representa la fecha (ddmmaa).
        * @param cliente Referencia al cliente que se está atendiendo en ese momento.
        * @param clientes Referencia al contenedor con todos los clientes de la entidad bancaria.
        * @param transacciones Referencia al contenedor de las transacciones de todos los clientes.
        */
        void gestionarPrestamos(int fecha[], Cliente& cliente, map <int, Cliente>& clientes, vector <string>& transacciones);
};

#endif // ATENCIONCLIENTE_HPP