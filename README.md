**Programa Scheduler**

El programa leerá un entero a través de la entrada estándar scanf. Para que no haya ningún problema se limpiará el búfer. 
Para llevar un control de la correcta lectura del dato, hemos aprovechado que la entrada scanf devuelve un entero en caso de leer el dato. 
Para ello si devuelve 1 el dato es leído correctamente y podremos continuar con la ejecución. 
En caso de que este dato sea válido el programa comprobara si ese dato se encuentra dentro del rango, si este está fuera del rango mostrará un mensaje de error con la salida stderr y volverá a pedir el dato. 
En el caso contrario imprimirá el dato leído y volverá a pedir el dato hasta que se llegue a una cantidad de M números validos leídos, saliéndose por tanto del bucle y finalizando el programa.

**Programa Bloques**

El programa bloques inicialmente se realizó en un solo modulo/programa, posteriormente como indicaba el enunciado creamos 4 ficheros más (1 por función).
Para la primera función genera, recibe de parámetro un array de datos por referencia, para cada estructura se rellenará con un id, la forma más sencilla de plantearlo fue creando una variable global a 0 (siendo este el primer id), la prioridad de cada uno a 10 como se indica y el estado ‘P’ .
Para la función despachador se le pasará un dato struct por valor e imprimirá el estado para un dato determinado que se indique.
La función almacena, recibirá por valor un array de estructuras. Se nos pedía la creación de 2 ficheros, uno de texto y otro binario. 
Para el fichero de texto usamos la llamada ANSI C con fopen para crear el fichero. 
Con el fin de llevar el control de que se creara correctamente si el fichero creado era igual a NULL significaba que no se había podido abrir o crear. 
Lo mismo para el fichero binario. 
Para escribir en ambos ficheros recorrimos con un bucle todos los elementos del array, para el de texto usamos fprintf mientras que para el binario fwrite, esto se debe a que fprintf va a escribir una cadena de texto mientras que fwrite se usa para escribir en formato binario.
Por último, la función principal main, llamará NUMERO DE VECES a genera para rellenar el array de estructura. Lo siguiente será la llamada a despachador, para esta el usuario deberá introducir M números validos y la función imprimirá por la salida estándar stdout el estado del id introducido por el usuario.
Finalmente se llamará a almacena para escribir en los dos ficheros los datos que contiene el array de estructuras rellenado anteriormente con genera.
