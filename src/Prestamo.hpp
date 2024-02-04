 /**
 * @file Prestamo.hpp
 * @author David Madrigal, Danny Solozarlo, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-03-2
 * @copyright Copyright (c) 2024
 * @brief Archivo que clos atributos y metodos de la clase Prestamo.
 */

#ifndef PRESTAMO_HPP
#define PRESTAMO_HPP

#include "LecturaDatos.hpp"

/**
* @brief Clase estable los datos del prestamo.
* 
* La clase Prestamo tiene como métodos y atributos toda la información.
* relacionada con un prestamo como el monto, cuotas, tasa de interés... etc.
* Además, tiene la capacidar de guardar la información sobre la cuotas
* de la deuda.
*/
class Prestamo {
    public:
        int numeroPrestamo;         //< Numero del Prestamo
        string tipoMoneda;          //< Tipo de moneada a usar
        double montoTotal;          //< Monto de la deuda
        int cuotasTotal;            //< Cuotas de la deuda
        double tasaInteres;         //< Tasa de interes
        double costoCuota;          //< Costo de la cuota
        int cuotasPagadas;          //< Cantidad de Cuotas pagadas
        double interesesPagados;    //< Intereses pagados
        double deudaPagada;         //< Deuda pagada
        vector <string> infoCuotas; //< Contendor con información de la cuotas

        /**
        * @brief Establece los datos de la clase.
        *
        * @param tipoMoneda_p Tipo de moneda del préstamo.
        * @param montoTotal_p Monto total del préstamo.
        * @param cuotasTotal_p Cuotas del préstamo.
        * @param tasaInteres_p Tasa de interés del préstamo.
        */
        void setDatos(string tipoMoneda_p, double montoTotal_p, int cuotasTotal_p, double tasaInteres_p);

        /**
         * @brief Imprime información del préstamo
         */
        void imprimirInfo();
        /**
         * @brief Paga la cuota de un préstamo
         * 
         */
        void pagarCuota();
        vector <string> generarReporteCuotas();
};

#endif // PRESTAMO_HPP