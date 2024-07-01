/*
 * File: bloques.c
 *
 * Description: programa bloques
 *
 * Author:  Arahi Fernandez Monagas y Carlos Fernandez Cabrero
 * Version: 2022-03-02
 *
*/

#include <stdio.h>
#include "datos.h"
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

//variable global para el id secuencial
int id_sec = 0;

//declaracion de las funciones
void genera (struct dato *array_datos);

void despachador (struct dato el_dato);

void almacena (struct dato array_datos[]);

int main (void) {

    int numero;
    struct dato array_datos[NUMERO];


    for (int i = 0; i < NUMERO; i++) {
        genera (&array_datos[i]);
    }

    int control, error;
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
                despachador(array_datos[numero]);
                //si el numero total de datos validos alcanza M
                //finaliza la ejecucion y se sale del bucle
                if (m_datos_validos == M) {
                    break;
                }
            }
        }
    }

    almacena(array_datos);

    return 0;
}

void genera (struct dato *array_datos) {

    //se le asigna un id secuencial correspondiente
    //he determinado que sera el mismo de la posicion del array
    //para asignarlo he usado una variable global
    //que se incrementar segun se incrementa el bucle
    array_datos->id_secuencial = id_sec;
    //la prioridad debe ser 10
    array_datos->prioridad = 10;
    //escribir P en cada estado
    array_datos->estado = 'P';
    //inicialmente esta variable para incrementar el id la aumentaba en el main
    //pero al realizar la separacion de bloques por modulos como se trataba de una variable global
    //era mas comodo que aumentara al final de esta funcion y cada vez que se hace una llamada de genera
    //en el main va incrementando el id
    id_sec++;

}

void despachador (struct dato el_dato) {
    fprintf (stdout, "ID: %d Estado: %c\n", el_dato.id_secuencial, el_dato.estado);
}

void almacena (struct dato array_datos[]) {

    int id,priori;
    char status;
    //Creacion de un fichero de texto
    FILE *fichero = fopen("almacentext.txt", "w+");
    //Creacion de un fichero binario
    FILE *fichero_binario = fopen("almacenbin.bin","wb+");

    //en el caso de que sea null nos notificara un error
    if (fichero == NULL) {
        fprintf (stderr, "Error en la creacion del fichero\n");
    }
    if (fichero_binario == NULL) {
        fprintf (stderr, "Error en la creacion del fichero\n");
    }
    //si todo es correcto, se escribira en el archivo
    for (int i = 0; i < NUMERO; i++) {
        id = array_datos[i].id_secuencial;
        priori = array_datos[i].prioridad;
        status = array_datos[i].estado;
        fprintf(fichero,"%d %d %c\n", id, priori, status);
        //escritura fichero binario
        fwrite(&array_datos[i], sizeof(struct dato), NUMERO, fichero_binario);
    }

    fclose(fichero);
    fclose(fichero_binario);
}

