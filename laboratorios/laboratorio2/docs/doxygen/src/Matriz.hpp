/**
 * @file Matriz.hpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo header de clase Matriz.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#ifndef MATRIZ_HPP
#define MATRIZ_HPP

// Se definen las librerías que se emplean en el resto del código.
#include <iostream>     /* Entrada y salida en la terminal. */
#include <string>       /* Uso de strings, incluyendo declaración. */
#include <vector>       /* Uso de vectores incluyendo declaración, pushback, size, clear, etc. */
#include <iomanip>      /* Uso de setw() para espaciar correctamente información imprimida en terminal. */
#include <stdexcept>    /* Uso de excepciones como invalid_argument, domain_error, etc. */
using namespace std;

/**
 * @brief Clase base de matrices.
 * 
 * En esta clase se contienen las entradas del objeto matriz en contenido.
 * Se emplean métodos para asignar los valores de la matriz y para pedir la operacion a realizar en las matrices.
 * 
 * @tparam T tipo de variable usada (int, float o complex<float>).
 */
template <class T>
class Matriz {
    friend class Operadora;         /**< Clase amiga Operadora. */
    public:
        vector<vector<T>> contenido;    /**< Entradas de la matriz. */
    protected:
        /**
         * @brief Método para inicializar contenido de la matriz.
         * 
         * Se reciben las dimensiones y entradas de la matriz a partir de inputs en la terminal.
         * Esta información se guarda en contenido.
         * 
         */
        void crearMatriz();

        /**
         * @brief Método para indicar la operacion a realizar.
         * 
         * Se solicita la operacion (suma, resta, multiplicación o Salir) en forma de entero.
         * 
         * @return int Indicador de opcion escogida.
         */
        int pedirOperacion();
};

#include "Matriz.cpp"
#endif