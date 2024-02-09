 /**
 * @file CuentaBancaria.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-08
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase Banco.
 */

#ifndef BANCO_HPP
#define BANCO_HPP

#include "AtencionCliente.hpp"

/**
* @brief Clase que gestiona padre que gestiona el programa.
* 
* La clase Banco es la encargada de llevar el control del programa.
* Cuenta con atributos que son contenederos con información relacionada
* con los clientes y todas las transacciones que estos realizan. Sus
* 
*/
class Banco {
    public:
        map <int,Cliente> clientes;     //< Diccionario de clientes
        vector <string> transacciones;  //< Contenedor con las transacciones
        AtencionCliente ventanilla;     //< Objeto ventanilla
        int fecha[3];   
        /**
         * @brief Método que divide las lineas con separador
         * 
         * @param linea
         * @param separador
         *
         */                
        vector <string> dividir(string linea, string separador);
        /**
         * @brief Método que establece la fecha
         * 
         */   
        void setFecha();
        /**
         * @brief Método que la información de los clientes
         * 
         */   
        void leerInfoClientes();
                /**
         * @brief Método que lee las transacciones extra
         * 
         */   
        void leerTransacciones();
        /**
         * @brief Método que actualiza la información de los clientes
         * 
         */   
        void actualizarInfoClientes();
        /**
         * @brief Método que crea un cliente
         * 
         */          
        void crearCliente();
        /**
         * @brief Método utilizado para antender a un cliente
         * 
         */            
        void atenderCliente();
        /**
         * @brief Método utilizado para mostrar un menú con la información
         * 
         */    
        void mostrarMenu();
        /**
         * @brief Método que actualiza las transacciones
         * 
         */    
        void actualizarTransacciones();
};

#endif // BANCO_HPP