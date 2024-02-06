 /**
 * @file CuentaBancaria.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-04
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye los atributos y métodos de la clase CuentaBancaria.
 */

#ifndef CDP_HPP
#define CDP_HPP

// Se incluyen las librerías a utilizar
#include <iostream>
#include <string>
using namespace std;

class CDP {
    public:
        string tipoMoneda;
        double dineroCDP;
        int fechaCreacion[3];
        int fechaExpira[3];
        int plazoMeses;
        double tasaInteres;
        string estado;
        string informacion;

        void setDatos(int fechaCreacion_p[], string tipoMoneda_P, int plazoMeses_p, double dineroCDP, double tasaInteres);
};

#endif // CDP_HPP