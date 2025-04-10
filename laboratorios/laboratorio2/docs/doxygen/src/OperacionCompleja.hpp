/**
 * @file OperacionCompleja.hpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo header de clase OperacionCompleja.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#ifndef OPERACIONES_COMPLEJAS_HPP
#define OPERACIONES_COMPLEJAS_HPP

#include "OperacionesBasicas.hpp"
#include <complex>      /* Uso de números complejos y métodos real() y imag(). */

/**
 * @brief Clase hija de Matriz para operaciones con complejos.
 * 
 * Hereda el contenido de clase Matriz y posee los métodos para realizar operaciones con complejos.
 * Además posee método para imprimir números complejos.
 * 
 */
class OperacionCompleja : public Matriz<complex<float>>{
    friend class Operadora;
    protected:
        /**
         * @brief Método para imprimir números complejos en forma 'a + bi'.
         * 
         * @param complejo Número complejo a imprimir.
         */
        void stringComplejo(complex<float> complejo);

        /**
         * @brief Método para sumar dos matrices.
         * 
         * Suma entrada por entrada 2 matrices y devuelve la matriz resultante.
         * Se sobrecarga el operador + para llamar este método.
         * 
         * @param otraMatriz Matriz a sumar con la matriz que llama el método.
         * @return OperacionCompleja Matriz resultante de la suma.
         */
        OperacionCompleja operator+ (const OperacionCompleja &otraMatriz);

        /**
         * @brief Método para restar dos matrices.
         * 
         * Resta entrada por entrada 2 matrices y devuelve la matriz resultante.
         * Se sobrecarga el operador - para llamar este método.
         * 
         * @param otraMatriz Matriz a restar a la matriz que llama el método.
         * @return OperacionCompleja Matriz resultante de la resta.
         */
        OperacionCompleja operator- (const OperacionCompleja &otraMatriz);

        /**
         * @brief Método para multiplicar dos matrices.
         * 
         * Realiza la multiplicación matricial de dos matrices dadas y devuelve la matriz resultante.
         * Se sobrecarga el operador * para llamar este método.
         * 
         * @param otraMatriz Matriz a multiplicar con la matriz que llama el método.
         * @return OperacionCompleja Matriz resultante de la multiplicación.
         */
        OperacionCompleja operator* (const OperacionCompleja &otraMatriz);

};

#include "OperacionCompleja.cpp"
#endif