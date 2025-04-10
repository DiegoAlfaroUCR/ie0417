/**
 * @file main.cpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo principal que inicializa el programa de la parte 1.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#include "Operadora.hpp"

/** @fn
 * @brief Función principal, inicia el programa.
 * 
 * @return int 0, Código de salida exitosa del programa.
 */
int main(){
    /* Se crea objeto clase Operadora. */
    Operadora operadora;
    int tipoVariable;

    /* Manejo de erroes en caso de opciones inválidas. */
    try {
        /* Se pide tipo de variable a usar. */
        tipoVariable = operadora.imprimirMenu(); 
        }
    catch(const std::exception& e) {
        std::cerr << "\nERROR al escoger tipo de variable: "<< e.what() << '\n'; 
        }
    
    /* Dependiendo del tipo de variable se crean las matrices y se inicia el proceso. */
    switch (tipoVariable) {
    case 1:{
        OperacionesBasicas<int> matrizA, matrizB;
        operadora.iniciarProceso(matrizA, matrizB);
        break;
        }

    case 2:{
        OperacionesBasicas<float> matrizA, matrizB;
        operadora.iniciarProceso(matrizA, matrizB);
        break;
        }

    case 3:{
        /* Se imprime instruccion para digitar números complejos. */
        cout << endl
             << "##################################################" << endl
             << "Para ingresar numeros complejos seguir esta forma:" << endl
             << "(a,b) para un numero complejo a + bi"               << endl
             << "##################################################" << endl;
        OperacionCompleja matrizA, matrizB;
        operadora.iniciarProceso(matrizA, matrizB);
        break;
        }
    }
    return 0;
}