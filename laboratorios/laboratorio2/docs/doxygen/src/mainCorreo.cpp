/**
 * @file mainCorreo.cpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo principal que inicializa el programa de la parte 2.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#include "Correo.hpp"

/** @fn
 * @brief Función principal, inicia el programa.
 * 
 * @return int 0, Código de salida exitosa del programa.
 */
int main(){
    /* Se genera una instancia de la clase. */
    Correo instancia;

    /* Se llama al método. */
    if (instancia.verificar()) {

        /* Si se da el match se imprime que es válido. */
        cout << "Correo es valido." << endl;

    } else {

        /* Si no se da el match se imprime que no es válido. */
        cout << "Correo no es valido." << endl;
    }

    return 0;
}