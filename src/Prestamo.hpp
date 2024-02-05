 /**
 * @file Prestamo.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-04
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase Prestamo.
 */

#ifndef PRESTAMO_HPP
#define PRESTAMO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

/**
* @brief Clase que permite gestionar los préstamos de los usuarios.
* 
* La clase Prestamo tiene como métodos y atributos toda la información
* relacionada con un préstamo, como el monto, cuotas, tasa de interés, etc.
* Además, guarda la información sobre las cuotas de la deuda.
*/
class Prestamo {
    public:
        int numeroPrestamo;         //< Número del préstamo
        string tipoMoneda;          //< Tipo de moneda en que se solicitó el prestamo
        double montoTotal;          //< Monto total de la deuda
        int cuotasTotal;            //< Cantidad total de cuotas de la deuda
        double tasaInteres;         //< Tasa de interés
        double costoCuota;          //< Costo de la cuota
        int cuotasPagadas;          //< Cantidad de cuotas pagadas
        double interesesPagados;    //< Intereses pagados
        double deudaPagada;         //< Deuda pagada
        vector <string> infoCuotas; //< Contendor con toda la información de las cuotas

        /**
        * @brief Establece los datos de un préstamo.
        *
        * @param tipoMoneda_p Tipo de moneda del préstamo.
        * @param montoTotal_p Monto total del préstamo.
        * @param cuotasTotal_p Cantidad total de cuotas del préstamo.
        * @param tasaInteres_p Tasa de interés del préstamo.
        */
        void setDatos(string tipoMoneda_p, double montoTotal_p, int cuotasTotal_p, double tasaInteres_p);

        /**
         * @brief Imprime la información relevante del préstamo.
         */
        void imprimirInfo();

        /**
         * @brief Paga una cuota de un préstamo.
         * 
         */
        void pagarCuota();
        /**
         * @brief Genera un reporte con toda la información sobre las cuotas del préstamo.
        */
        vector <string> generarReporteCuotas();
};

#endif // PRESTAMO_HPP