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

/**
* @brief Clase que permite gestionar los CDP del usuario.
* 
* La clase CDP tiene como métodos y atributos todo lo relacionado a CDP
* para que el cliente pueda solicitar CDP con los intereses y tiempos
* deseados.
*/
class CDP {
    public:
        string tipoMoneda;      //< Tipo de moneda (dolares o colones) del CDP
        double dineroCDP;       //< Dinero (suma de cuotas) que tiene el cliente en su CDP
        int fechaCreacion[3];   //< Esta es la fecha que se introduce al inicio del programa, es la fecha de inicio.
        int fechaExpira[3];     //< Fecha de expiración del CDP, depende si es de pequeño, mediado o largo plazo
        int plazoMeses;         //< Define si el plazo es corto, mediado o largo  
        double tasaInteres;     //< Depende del plazo de intereses, 
        string estado;          //< Define si el CDP esta vigente o ya se vencio
        string informacion;     //< Contiene la información en string de los atributos mostrados anteriormente menos tipoMoneda, dineroCDP
        
        /**
         * @brief Establece las características del CDP como tipo de moneda, plazos, intereses y dinero.
         * 
         * @param fechaCreacion_p   Fecha de inicio del CDP
         * @param tipoMoneda_P      Moneda del CDP (dolares y colones)  
         * @param plazoMeses_p      Plazo de meses del CDP (corto, mediano y largo)
         * @param dineroCDP         Dinero del CDP
         * @param tasaInteres       Tasa de interes del CDP
         */
        void setDatos(int fechaCreacion_p[], string tipoMoneda_P, int plazoMeses_p, double dineroCDP, double tasaInteres);

        /**
         * @brief Muestra datos simples como dineroCDP, tipo de moneda y taza de intereses.
         */
        void mostrarDatosCDP();

        /**
         * @brief Actualiza la linea temporal del CDP para saber si ya llegó a su vencimiento
         * 
         * @param fecha     Atributo para calcular la fecha actual del CDP
         */
        // void actualizarCDP(int fecha[]); //< Esto esta a prueba
};

#endif // CDP_HPP