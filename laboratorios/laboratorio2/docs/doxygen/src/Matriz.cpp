/**
 * @file Matriz.cpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo fuente para métodos de clase Matriz.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#include "Matriz.hpp"

template <class T>
void Matriz<T>::crearMatriz(){
    /* Se solicitan las dimensiones. */
    cout << "Ingrese las dimensiones de la matriz: " << endl;

    cout << "Cantidad de filas: ";
    int filas; cin >> filas;

    /* Se revisa si las filas no son válidas. */
    if (!cin.good() || filas < 0){
        throw invalid_argument("Input de filas dado no es valido.");
    }

    cout << "Cantidad de columnas: ";
    int columnas; cin >> columnas;

    /* Se revisa si las columnas no son válidas. */
    if (!cin.good() || columnas < 0){
        throw invalid_argument("Input de columnas dado no es valido.");
    }

    /* Se crea un vector para cada fila. */
    vector<T> vectorFila; 
    for (int fila = 0; fila < filas; fila++) {  /* Se hace el proceso para cada fila. */
        /* Se vacía el vector. */
        vectorFila.clear();

        for (int columna = 0; columna < columnas; columna++) { /* Se hace el proceso para cada columna. */
            cout << "Entrada de fila " << fila + 1 << " columna " << columna + 1 << " : ";
            T entrada; cin >> entrada;

            /* Manejo de errores si las entradas no son válidas. */
            if (!cin.good()){
            throw invalid_argument("Tipo de entrada dada no es valido.");
            }
            
            /* Se agrega entrada al vectorFila. */
            vectorFila.push_back(entrada);
        }
        /* Se agrega vectorFila al contenido de la matriz. */
        contenido.push_back(vectorFila);
    }
}

template <class T>
int Matriz<T>::pedirOperacion(){
    /* Se muestra el menu. */
    cout << endl;
    cout << "-------Menu de Opciones-------" << endl;
    cout << "1. Sumar matrices definidas." << endl;
    cout << "2. Restar matrices definidas." << endl;
    cout << "3. Multiplicar matrices definidas." << endl;
    cout << "4. Salir del sistema." << endl;
    cout << "Digite una opcion: ";
    int opcion; cin >> opcion;

    /* Manejo de errores en caso donde no es entero. */
    if (!cin.good() || (opcion < 0) || (opcion > 4)){
        throw invalid_argument("Opcion dada no es valida");
    }

    /* Se cierra el programa si solicitado. */
    if (opcion == 4) {
        cout << endl << "Saliendo del sistema..." << endl;
        exit(0);
    }
    
    return opcion;
}