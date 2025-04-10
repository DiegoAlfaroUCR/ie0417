/**
 * @file OperacionesBasicas.hpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo header de clase OperacionesBasicas.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#ifndef OPERACIONES_BASICAS_HPP
#define OPERACIONES_BASICAS_HPP

#include "Matriz.hpp"

/**
 * @brief Clase hija de Matriz para operaciones básicas.
 * 
 * Hereda el contenido de clase Matriz y posee métodos para validar las operaciones a realizar, y los métodos para realizar dichas operaciones.
 * 
 * @tparam T tipo de variable usada (int, float o complex<float>). 
 */
template <class T>
class OperacionesBasicas: public Matriz<T> {
    friend class Operadora;  /**< Clase amiga Operadora. */
    protected:
        /**
         * @brief Método para validar operaciones según dimensiones de matrices.
         * 
         * El método recibe dos matrices de tipo U y un string con el tipo de operación.
         * Según el tipo de operacion verifica si las dimenciones de las matrices dadas son aptas para la operación.
         * Si la operación no es apta se genera una excepción.
         * 
         * @tparam U Clase de matrices dadas (OperacionesBasicas<int>, OperacionesBasicas<float> o OperacionCompleja).
         * @param A Primera matriz dada de clase U.
         * @param B Segunda matriz dada de clase U.
         * @param tipoOperacion String indicando operación a realizar ("Suma/Resta" o "Multiplicacion").
         */
        template <class U>
        void validar(const U& A, const U& B, const string& tipoOperacion);

        /**
         * @brief Método para sumar dos matrices.
         * 
         * Suma entrada por entrada 2 matrices y devuelve la matriz resultante.
         * Se sobrecarga el operador + para llamar este método.
         * 
         * @param otraMatriz Matriz a sumar con la matriz que llama el método.
         * @return OperacionesBasicas<T> Matriz resultante de la suma.
         */
        OperacionesBasicas<T> operator+ (const OperacionesBasicas<T> &otraMatriz);

        /**
         * @brief Método para restar dos matrices.
         * 
         * Resta entrada por entrada 2 matrices y devuelve la matriz resultante.
         * Se sobrecarga el operador - para llamar este método.
         * 
         * @param otraMatriz Matriz a restar a la matriz que llama el método.
         * @return OperacionesBasicas<T> Matriz resultante de la resta.
         */
        OperacionesBasicas<T> operator- (const OperacionesBasicas<T> &otraMatriz);

        /**
         * @brief Método para multiplicar dos matrices.
         * 
         * Realiza la multiplicación matricial de dos matrices dadas y devuelve la matriz resultante.
         * Se sobrecarga el operador * para llamar este método.
         * 
         * @param otraMatriz Matriz a multiplicar con la matriz que llama el método.
         * @return OperacionesBasicas<T> Matriz resultante de la multiplicación.
         */
        OperacionesBasicas<T> operator* (const OperacionesBasicas<T> &otraMatriz);
};

#include "OperacionesBasicas.cpp"
#endif