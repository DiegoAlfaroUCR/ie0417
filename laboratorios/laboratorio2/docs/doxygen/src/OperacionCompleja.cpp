/**
 * @file OperacionCompleja.cpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo fuente para métodos de clase OperacionCompleja.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#include "OperacionCompleja.hpp"

void OperacionCompleja::stringComplejo(complex<float> complejo){
    /* Se obtienen las partes reales y complejas del número. */
    float parteReal = complejo.real();
    float parteImag = complejo.imag();;

    /* Se imprimen con forma "a + bi" con espaciado correcto. */
    cout << parteReal << " + " << parteImag
    << left << setw(5) << "i";
}

OperacionCompleja OperacionCompleja::operator+ (const OperacionCompleja &otraMatriz){
    /* Se declara la matriz resultante de mismo tipo a las dadas. */
    OperacionCompleja resultado;

    /* Se obtienen las dimensiones de las matrices dadas. */
    int filas = this->contenido.size();
    int columnas = this->contenido[0].size();

    /* Se declara un vector de fila para resultado. */
    vector<complex<float>> vectorFila;

    /* Se recorre cada fila. */
    for (int fila = 0; fila < filas; fila++) {
        vectorFila.clear();

        /* Se recorre cada columna. */
        for (int columna = 0; columna < columnas; columna++){

            /* Se suman las entradas y se agrega en el vectorFila. */
            complex<float> entrada = this->contenido[fila][columna] + otraMatriz.contenido[fila][columna];
            vectorFila.push_back(entrada);
        }
        /* Se agrega la fila nueva a resultado. */
        resultado.contenido.push_back(vectorFila);
    }
    return resultado;
}

OperacionCompleja OperacionCompleja::operator- (const OperacionCompleja &otraMatriz){
    /* Se declara la matriz resultante de mismo tipo a las dadas. */
    OperacionCompleja resultado;

    /* Se obtienen las dimensiones de las matrices dadas. */
    int filas = this->contenido.size();
    int columnas = this->contenido[0].size();

    /* Se declara un vector de fila para resultado. */
    vector<complex<float>> vectorFila;

    /* Se recorre cada fila. */
    for (int fila = 0; fila < filas; fila++) {
        vectorFila.clear();

        /* Se recorre cada columna. */
        for (int columna = 0; columna < columnas; columna++){

            /* Se restan las entradas y se agrega en el vectorFila. */
            complex<float> entrada = this->contenido[fila][columna] - otraMatriz.contenido[fila][columna];
            vectorFila.push_back(entrada);
        }
        /* Se agrega la fila nueva a resultado. */
        resultado.contenido.push_back(vectorFila);
    }
    return resultado;
}

OperacionCompleja OperacionCompleja::operator* (const OperacionCompleja &otraMatriz){
    /* Se obtienen dimensiones relevantes. */
    int filas1 = this->contenido.size();
    int columnas1 = this->contenido[0].size();
    int columnas2 = otraMatriz.contenido[0].size();

    /* Se crea un objeto con contenido vacio y dimensiones filas1 x columnas2. */
    OperacionCompleja resultado;
    for(int i = 0; i < filas1; i++){
        vector<complex<float>> resultadoFila(columnas2);
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