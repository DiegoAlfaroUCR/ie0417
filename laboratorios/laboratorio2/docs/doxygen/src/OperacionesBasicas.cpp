/**
 * @file OperacionesBasicas.cpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo fuente para métodos de clase OperacionesBasicas.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#include "OperacionesBasicas.hpp"

template <class T> /* Template para el tipo de OperacionesBasicas. */
template <class U> /* Template para el tipo de las matrices a validar. */
void OperacionesBasicas<T>::validar(const U& A, const U& B, const string& tipoOperacion){

    /* Se obtienen las dimensiones de cada matriz. */
    int filasA = A.contenido.size();
    int columnasA = A.contenido[0].size();
    int filasB = B.contenido.size();
    int columnasB = B.contenido[0].size();

    /* Se generan excepciones para suma/resta. 
       Dimensiones de ambas deben ser iguales.*/
    if(tipoOperacion == "Suma/Resta"){
        if((filasA != filasB) || (columnasA != columnasB)){
            throw domain_error("Dimensiones de las matrices no aptas para suma/resta.");
        }
    }

    /* Se generan excepciones para multiplicacion. 
       Sea A * B, cantidad de columnas de A debe ser igual
       cantidad de filas de B.*/
    if(tipoOperacion == "Multiplicacion"){
        if(columnasA != filasB){
            throw domain_error("Dimensiones de las matrices no aptas para multiplicacion.");
        }
    }
}

template <class T>
OperacionesBasicas<T> OperacionesBasicas<T>::operator+(const OperacionesBasicas<T> &otraMatriz){
    /* Se declara la matriz resultante de mismo tipo a las dadas. */
    OperacionesBasicas<T> resultado;

    /* Se obtienen las dimensiones de las matrices dadas. */
    int filas = this->contenido.size();
    int columnas = this->contenido[0].size();

    /* Se declara un vector de fila para resultado. */
    vector<T> vectorFila;

    /* Se recorre cada fila. */
    for (int fila = 0; fila < filas; fila++) {
        vectorFila.clear();

        /* Se recorre cada columna. */
        for (int columna = 0; columna < columnas; columna++){

            /* Se suman las entradas y se agrega en el vectorFila. */
            T entrada = this->contenido[fila][columna] + otraMatriz.contenido[fila][columna];
            vectorFila.push_back(entrada);
        }
        /* Se agrega la fila nueva a resultado. */
        resultado.contenido.push_back(vectorFila);
    }
    return resultado;
}

template <class T>
OperacionesBasicas<T> OperacionesBasicas<T>::operator-(const OperacionesBasicas<T> &otraMatriz){
    /* Se declara la matriz resultante de mismo tipo a las dadas. */
    OperacionesBasicas<T> resultado;

    /* Se obtienen las dimensiones de las matrices dadas. */
    int filas = this->contenido.size();
    int columnas = this->contenido[0].size();

    /* Se declara un vector de fila para resultado. */
    vector<T> vectorFila;

    /* Se recorre cada fila. */
    for (int fila = 0; fila < filas; fila++) {
        vectorFila.clear();

        /* Se recorre cada columna. */
        for (int columna = 0; columna < columnas; columna++){

            /* Se restan las entradas y se agrega en el vectorFila. */
            T entrada = this->contenido[fila][columna] - otraMatriz.contenido[fila][columna];
            vectorFila.push_back(entrada);
        }
        /* Se agrega la fila nueva a resultado. */
        resultado.contenido.push_back(vectorFila);
    }
    return resultado;
}

template <class T>
OperacionesBasicas<T> OperacionesBasicas<T>::operator*(const OperacionesBasicas<T> &otraMatriz){
    /* Se obtienen dimensiones relevantes. */
    int filas1 = this->contenido.size();
    int columnas1 = this->contenido[0].size();
    int columnas2 = otraMatriz.contenido[0].size();

    /* Se crea un objeto con contenido vacio y dimensiones filas1 x columnas2. */
    OperacionesBasicas<T> resultado;
    for(int i = 0; i < filas1; i++){
        vector<T> resultadoFila(columnas2);
        resultado.contenido.push_back(resultadoFila);
        }

    /* Se recorre por filas. */
    for (int fila = 0; fila < filas1; fila++) {

        /* Se recorre por columnas. */
        for (int columna = 0; columna < columnas2; columna++){
            resultado.contenido[fila][columna] = 0;     /* Se inicializa en 0. */

            /* Se itera cada entrada. */
            for (int contador = 0; contador < columnas1; contador++){
                
                /* Se suman los pares de entradas multiplicados. */
                resultado.contenido[fila][columna] += this->contenido[fila][contador] * otraMatriz.contenido[contador][columna];
            }
        }
    }
    return resultado;
}