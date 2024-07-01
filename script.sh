#lee los argumentos 
echo $#
if [ $# -lt 6 ] 
	then
	echo "argumentos no suficientes $#\n"
	exit
fi
for i in $*
	do
		if ! test -f $i 
		then
			echo "$i"
		fi 
	done
	
#makefile realizado
if ! make 
then
	echo "error en el make";
	exit
fi
echo " ";
echo "---Leyendo ficheroLectura y escribiendo la salida---"
		#el programa scheduler leera los datos del fichero los almacenara en inter y esos datos los leera bloque
		#escribiendolo en la salida
		./scheduler < ficheroLectura  | tee intermedio | ./bloques > ficheroSalida
		#muestra por pantalla los ficheros generados
		echo " ";
		echo "Datos correctos recuperados";
		cat intermedio
		echo " ";
		echo "Salida con datos validos";
		cat ficheroSalida



