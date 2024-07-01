practica1: scheduler bloques
scheduler: scheduler.c datos.h
	gcc -o scheduler scheduler.c
	
#dividir bloques en 4 partes (1 por funcion)
main.o: main.c datos.h
	gcc -c main.c
genera.o: genera.c datos.h
	gcc -c genera.c
despachador.o: despachador.c datos.h
	gcc -c despachador.c
almacena.o: almacena.c datos.h
	gcc -c almacena.c
	
bloques: main.o despachador.o genera.o almacena.o datos.h
	gcc -o bloques main.o despachador.o genera.o almacena.o






