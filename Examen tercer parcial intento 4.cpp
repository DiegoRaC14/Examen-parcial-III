#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *archivoEntrada = fopen("emails.csv", "r");
    FILE *archivoSalida = fopen("177195.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) //Checar si hay un error para abrir el archivo
	{
        perror("Error al abrir el archivo");
        return 1;
    }

    char buffer[1000]; // Leer y descartar la primera línea con los encabezados
    fgets(buffer, sizeof(buffer), archivoEntrada);

    // Variables para almacenar las sumas de cada columna
    double suma_columnas[3000] = {0}; // Usamos double para permitir decimales

    for (int fila = 1; fila <= 5173; fila++) 
	{
        
        fscanf(archivoEntrada, "%*[^,],");// Descartar las letras de la columna

        
        for (int columna = 1; columna <= 3000; columna++) 
		{
            int valor;
			
            if (fila >= 195 && fila <= 246) // Leer y sumar los valores de las columnas para las filas 195 a 245
			{
                fscanf(archivoEntrada, "%d,", &valor);
                // Sumar al total de la columna
                suma_columnas[columna -1] += valor;
            }
            else 
			{
                fscanf(archivoEntrada, "%*d,"); // Descartar el valor si no está en el rango
            }
        }

        // Moverse a la siguiente línea
        fgets(buffer, sizeof(buffer), archivoEntrada);
    }

    // Imprimir las sumas en el archivo de salida
    for (int columna = 1; columna <= 3000; columna++) 
	{
        fprintf(archivoSalida, "Suma Columna %d: %.2f\n", columna, suma_columnas[columna - 1]);
    }

    // Cerrar los archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    printf("Todo esta viento en popa.\n");

    return 0;
}


