/*
 * File: scheduler.c
 *
 * Description: lee un numero entre 0 y N-1 
 *
 * Author:  Arahi Fernandez Monagas y Carlos Fernandez Cabrero
 * Version: 2022-03-02
 *
*/

#include <stdio.h>
#include <string.h>
#include "datos.h"
#include <stdbool.h>


int main (void) {
    
    //variables
    int numero, control, error;
    int m_datos_validos = 0;
    
    //bucle infintio solo se sale cuando se ha alcanzado el maximo
    //de valores leidos
    while (true) {
        //entrada estandar del dato
        control = scanf ("%d", &numero);
        //limpiar el bufer
        while (getchar() != '\n') {}
        //en caso de que se haya podido leer correctamente el dato
        //control == 1
        if (control) {
            error = (numero < 0 || numero >= NUMERO);
            //en caso de que no cumpla la condicion de rango
            if (error) {
                //imprime mensaje de error y vuelve a pedir el numero
                fprintf (stderr, "Error, numero no valido\n");
            }
            //si el dato cumple el rango
            else {
                //sumamos la cantidad de datos validos
                m_datos_validos++;
                //imprime el dato leido
                fprintf (stdout, "%d\n", numero);
                //si el numero total de datos validos alcanza M
                //finaliza la ejecucion y se sale del bucle
                if (m_datos_validos == M) {
                    break;
                }
            }
        }
    }
    
    return 0;
}
