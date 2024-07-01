
/*
 * File: almacena.c
 *
 * Description: programa almacena
 *
 * Author:  Arahi Fernandez Monagas y Carlos Fernandez Cabrero
 * Version: 2022-03-02
 *
*/

#include <stdio.h>
#include "datos.h"
#include <fcntl.h>
#include <unistd.h>

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