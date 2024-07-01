/*
 * File: genera.c
 *
 * Description: programa bloques
 *
 * Author:  Arahi Fernandez Monagas y Carlos Fernandez Cabrero
 * Version: 2022-03-02
 *
*/

#include "datos.h"

//variable global para el id secuencial
int id_sec = 0;

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
    id_sec++;

}