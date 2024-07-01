/*
 * File: despachador.c
 *
 * Description: programa bloques
 *
 * Author:  Arahi Fernandez Monagas y Carlos Fernandez Cabrero
 * Version: 2022-03-02
 *
*/

#include <stdio.h>
#include "datos.h"


void despachador (struct dato el_dato) {
    fprintf (stdout, "ID: %d Estado: %c\n", el_dato.id_secuencial, el_dato.estado);
}