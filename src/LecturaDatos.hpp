/**
 * @file LecturaDatos.hpp
 * @author David Madrigal, Danny Solórzano, Yehohnathan Miranda
 * @version 0.1
 * @date 2024-02-14
 * @copyright Copyright (c) 2024
 * @brief Archivo que incluye funciones para leer entradas del usuario utilizando manejo de excepciones para entradas erróneas.
 */

// Se incluye la librería STL para poder utilizar todas las funciones y estructuras de datos que incluye. 
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solicita del usuario un número con decimales e imprime mensajes de error en caso de que el usuario ingrese una entrada que no sea un número decimal. 
 * @param variableDouble Corresponde a la variable que se desea leer. A esta variable se le asigna el valor de la lectura. 
 * @param mensaje Corresponde al mensaje que se muestra en pantalla cuando se solicita el valor del usuario. 
 */
void leerDouble(double& variableDouble, string mensaje);
/**
 * @brief Solicita del usuario un número entero positivo e imprime mensajes de error en caso de que el usuario ingrese una entrada que no sea un número entero positivo. 
 * @param variableEntero Corresponde a la variable que se desea leer. A esta variable se le asigna el valor de la lectura. 
 * @param mensaje Corresponde al mensaje que se muestra en pantalla cuando se solicita el valor del usuario. 
 */
void leerEntero(int& variableEntero, string mensaje);
/**
 * @brief Solicita del usuario el tipo de moneda: colones o dólares e imprime mensajes de error en caso de que el usuario ingrese una entrada invalida. 
 * @param tipoMoneda Corresponde al tipo de moneda que se desea leer. A esta variable se le asigna el valor de la lectura. 
 */
void leerMoneda(string& tipoMoneda);
/**
 * @brief Solicita el nombre del usuario e imprime mensajes de error en caso de que el usuario ingrese una entrada que no sea un string parecido a un nombre. 
 * @param nombre Corresponde al nombre del usuario que se desea leer. A esta variable se le asigna el valor de la lectura.
 */
void leerNombre(string& nombre);
