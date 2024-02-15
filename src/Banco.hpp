/**
 * @file Banco.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-14
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase Banco.
 */

#ifndef BANCO_HPP
#define BANCO_HPP
// Se incluyen las clases que se van a utilizar: AtencionCliente y Informacion. 
#include "AtencionCliente.hpp"
#include "Informacion.hpp"

/**
 * @brief Clase que permite gestionar las acciones del banco, como a tender clientes en la ventanilla y brindar información.
 * 
 * La clase Banco tiene como métodos y atributos todas las acciones que puede realizar el banco
 * tales como atender a los clientes, darles las opciones que pueden realizar con respecto a préstamos, cuentas o certificados a plazo.
 * Además, gestiona las opciones para poder solicitar información sobre los préstamos y controla el flujo general del programa.
 */
class Banco {
    public:
        map <int,Cliente> clientes; // Es el contenedor con todos los clientes registrados en el banco. 
        map <int, CuentaBancaria> cuentasBanco; // Es el contenedor con todas las cuentas bancarias de todos los clientes del banco.
        map <int, Prestamo> prestamosBanco; // Es el contenedor con todos los préstamos de todos los clientes del banco. 
        map <int, CDP> certificadosBanco; // Es el contenedor con todos los certificados a plazo de todos los clientes del banco. 

        vector <string> transacciones; // Es un contenedor con todos las transacciones realizadas por los usuarios en formato: fecha, id, nombre, descripción. 

        AtencionCliente ventanilla; // Objeto de la clase AtencionCliente que representa la ventanilla donde se atienden los clientes.
        Informacion informante; // Objeto de la clase Informacion que permite atender las consultas de los usuarios acerca de cada tipo de préstamo y sus cuotas a pagar. 

        int fecha[3]; // Representa la fecha del día que se ejecuta el programa. 

        /**
         * @brief Divide un string en un vector de strings utilizando un separador que se indica. 
         * @param linea Corresponde al string que se va a dividir en el vector de strings. 
         * @param separador Corresponde al separador que se va a utilizar para poder identificar los strings que forman el vector. 
         * @return Devuelve un vector de strings que representa todos los elementos del string línea separados por el separador indicado. 
         */
        vector <string> dividir(string linea, string separador); 
        /**
         * @brief Solicita y establece la fecha del día en que se ejecuta el programa. 
         */
        void setFecha();
        /**
         * @brief Lee un archivo .txt que contiene toda la información de los usuarios y la almacena nuevamente en los contenedores respectivos. 
         */
        void leerInfoClientes();
        /**
         * @brief Actualiza la información de los clientes guardada en el archivo .txt para que permanezca guardada al terminar la ejecución del programa. 
         */
        void actualizarInfoClientes();
        /**
         * @brief Lee un archivo .txt que contiene toda la información de las transacciones realizadas por los usuarios y la almacena nuevamente en el contenedor respectivo. 
         */
        void leerTransacciones();
        /**
         * @brief Actualiza la información de las transacciones de los usuarios guardada en el archivo .txt para que permanezca guardada al terminar la ejecución del programa. 
         */
        void actualizarTransacciones();
        /**
         * @brief Actualiza el estado, dinero generado y dinero total de todos los certificados a plazo de los clientes dependiendo de la fecha y su fecha de vencimiento. 
         */
        void actualizarCertificados();
        /**
         * @brief Solicita al usuario sus datos y lo agrega como un cliente al.contenedor respectivo. 
         */
        void crearCliente();
        /**
         * @brief Pregunta la fecha y utiliza un objeto de la clase AtencionCliente para gestionar todas las acciones que puede realizar el usuario. 
         */
        void atenderCliente();
        /**
         * @brief Muestra el menú de opciones de las acciones que pueden realizar los clientes ya sea en información o atención al cliente. 
         */
        void mostrarMenu();
};

#endif // BANCO_HPP
