/**
 * @file Informacion.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-14
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase Informacion.
 */

#ifndef INFORMACION_HPP
#define INFORMACION_HPP

// Se incluye la clase Prestamo
#include "Prestamo.hpp"

/**
 * @brief Clase que permite gestionar las solicitudes de información hechas por los usuarios.
 * 
 * La clase Informacion tiene como métodos y atributos toda la información
 * que un cliente podría solicitar relacionada con un préstamo. 
 * Permite generar tablas de cuotas para préstamos personales, hipotecarios, prendarios y personalizados. 
 */
class Informacion {
    public:
        /**
         * @brief Muestra el menú con las opciones de información que se puede solicitar sobre préstamos. 
         */
        void mostrarMenu();
        /**
         * @brief Genera un informe de cuotas en formato .txt con toda la información de las cuotas a pagar en el préstamo seleccionado. 
         * @param tipo Corresponde al tipo de préstamo: personal, prendario o hipotecario.
         * @param cuotasTotal Corresponde a la cantidad total de cuotas a pagar en el préstamo. 
         * @param tasaInteres Corresponde a la tasa de interés asociada al préstamo. 
         */
        void generarInformePredeterminado(string tipo, int cuotasTotal, double tasaInteres);
        /**
         * @brief Genera un informe de cuotas en formato .txt con toda la información de las cuotas a pagas en un préstamo con datos personalizados dados por el usuario. 
         */
        void generarInformePersonalizado();
};

#endif // INFORMACION_HPP
