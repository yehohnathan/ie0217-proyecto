 /**
 * @file CDP.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-04
 * @copyright Copyright (c) 2024
 * @brief Contiene todo lo relacionado a los certificados a plazo (CDP). 
 */

#ifndef CDP_HPP
#define CDP_HPP

// Se incluyen las librerías a utilizar
#include <iostream>
#include <string>
using namespace std;

// Cuando la clase que permite leer datos y verificar que cumple con lo solicitado, este lista, se instanciará
// #include "LecturaDatos.hpp"

/**
* @brief Clase que permite gestionar los CDP del usuario.
* 
* La clase CDP tiene como métodos y atributos todo lo relacionado a CDP
* para que el cliente pueda solicitar CDP con los intereses y tiempos
* deseados.
*/
class CDP {
    public:
        int numeroCDP;          //< Identificación del CDP
        int idPropietario;      //< Identificación del propietario
        string tipo;            //< Especifica el tipo de CDP que solicito el cliente
        string tipoMoneda;      //< Tipo de moneda (dolares o colones) del CDP
        double dineroCDP;       //< Dinero (suma de cuotas) que tiene el cliente en su CDP

        int fechaCreacion[3];   //< Esta es la fecha que se introduce al inicio del programa, es la fecha de inicio.
        int fechaExpira[3];     //< Fecha de expiración del CDP, depende si es de pequeño, mediado o largo plazo
        
        int plazoMeses;         //< Define si el plazo es corto, mediado o largo  
        double tasaInteres;     //< Depende del plazo de intereses, 
        string estado;          //< Define si el CDP esta vigente o ya se vencio

        /**
         * @brief Establece las características del CDP como tipo de moneda, plazos, intereses y dinero.
         * 
         * @param idPropietario_p Identificación del cliente dueño del CDP
         * @param numeroCDP_p Indentificador del CDP
         * @param tipoMoneda_P Moneda del CDP (dolares y colones)  
         * @param dineroCDP_p Dinero del CDP
         * @param fechaCreacion_p Fecha de inicio del CDP
         * @param plazoMeses_p Plazo de meses del CDP (corto, mediano y largo)
         * @param tasaInteres_p Tasa de interes del CDP
         * @param tipo Tipo de CDP solicitado
         */
        void setDatos(int idPropietario_p, int numeroCDP_p, string tipoMoneda_p, double dineroCDP_p, int fechaCreacion_p[], int plazoMeses_p, double tasaInteres_p, string tipo_p);

        /**
         * @brief Actualiza la linea temporal del CDP para saber si ya llegó a su vencimiento
         * 
         * @param fecha Atributo para calcular la fecha actual del CDP
         */
        void actualizarCDP(int fecha[]);
};

#endif // CDP_HPP