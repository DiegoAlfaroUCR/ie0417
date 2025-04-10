/**
 * @file Correo.hpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo header de clase Correo.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#ifndef CORREO_HPP
#define CORREO_HPP

#include <iostream>     /* Entrada y salida en la terminal. */
#include <string>       /* Uso de strings, incluyendo declaración. */
#include <regex>        /* Uso de expresiones regulares para verificar patrones en correo. */
#include <stdexcept>    /* Uso de excepciones como invalid_argument, domain_error, etc. */
using namespace std;

/**
 * @brief Clase para verificar un correo dado.
 * 
 * Posee expresiones expresion y arroba usadas para verificar patrones en strings dados. 
 * Se emplean en el método verificar.
 * 
 */
class Correo {
    private:
        /**
         * @brief Expresión regular que define los patrones aceptados de un correo.
         * 
         */
        const regex expresion = regex("^(?![\\.\\-\\_])[a-zA-Z0-9\\.\\-\\_]{0,14}[a-zA-Z0-9]@[a-zA-Z]+\\.[a-zA-Z]{2,4}$");

        const regex arroba = regex("@"); /**< Expresión regular para encontrar caracter @ en correo. */
    public:
        /**
         * @brief Método para verificar un correo ingresado.
         * 
         * Se solicita un correo por medio de la terminal y se compara con expresion.
         * 
         * @return true Si el correo coincide con patrón dado en expresion.
         * @return false Si el correo no coincide con patrón dado en expresion.
         */
        bool verificar();
};

#endif