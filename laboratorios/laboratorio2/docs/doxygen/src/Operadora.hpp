/**
 * @file Operadora.hpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo header de clase Operadora.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#ifndef OPERADORA_HPP
#define OPERADORA_HPP

#include "OperacionesBasicas.hpp"
#include "OperacionCompleja.hpp"

/**
 * @brief Clase para inicializar menu y programa.
 * 
 * Clase amiga de Matriz, OperacionesBasicas y OperacionCompleja.
 * Posee métodos para imprimir el menu inicial, crear clases/realizar operaciones e imprimir matrices.
 * 
 */
class Operadora{
    public:
        /**
         * @brief Método para imprimir menú inicial del programa.
         * 
         * @return int Indicador de tipo de variable elegida por usuario.
         */
        int imprimirMenu();

        /**
         * @brief Método para inicializar matrices y llamar las operaciones.
         * 
         * Se muestra un menú para crear las matrices, y realizar las operaciones deseadas en cada una.
         * 
         * @tparam T Clase de matrices dadas.
         * @param matrizA Matriz A por utilizar.
         * @param matrizB Matriz B por utilizar.
         */
        template <class T>
        void iniciarProceso(T matrizA, T matrizB);

    private:
        /**
         * @brief Método para imprimir contenidos de una matriz.
         * 
         * Se imprime los contenidos de la matriz dada en forma matricial.
         * Se hace sobrecarga de este método para el caso donde el tipo es números complejos.
         * 
         * @tparam T Clase de matriz dada.
         * @param matrizDada Matriz por imprimir.
         */
        template <class T>
        void mostrarMatriz(T matrizDada);
};

#include "Operadora.cpp"
#endif