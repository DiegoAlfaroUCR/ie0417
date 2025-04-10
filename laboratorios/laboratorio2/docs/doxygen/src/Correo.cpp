/**
 * @file Correo.cpp
 * @author Diego Alfaro Segura (diego.alfarosegura@ucr.ac.cr)
 * @brief Archivo fuente de métodos de clase Correo.
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * Licenciado bajo CC BY-NC-ND 4.0
 */

#include "Correo.hpp"

bool Correo::verificar(){
    
    /* Se solicita el correo. */
    cout << "Introduzca la direccion de correo: ";
    string cadena;

    /* Se lee como string con espacios. */
    getline(cin>>ws, cadena);

    /* Manejo de excepciones en caso donde correo no contenga @. */
    try {
        const bool condicion = regex_search(cadena, arroba);
        if(!condicion){
            throw invalid_argument("Direccion dada no contiene @.");
        }
    }
    catch(const std::exception& e) {
        std::cerr << "\nERROR: "<< e.what() << '\n';
        exit(0);
    }
    
    /* regex_match retorna true si cadena hace 'match' con expresion, sino retorna false. */
    return (regex_match(cadena, expresion));
}