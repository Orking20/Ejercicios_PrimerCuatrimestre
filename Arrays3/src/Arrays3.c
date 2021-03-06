/*
 ============================================================================
 Name        : Arrays4.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Solicitar al usuario 5 números, almacenar estos en un array de
 	 	 	   enteros, permitir listarlos por pantalla indicando el máximo, el
 	 	 	   mínimo y el promedio. Permitir Modificar el valor de cualquiera de
 	 	 	   los números cargados indicando el índice del mismo y su nuevo valor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "arrayBiblioteca.h"

#define LIMITE 5

int main(void)
{
	int array[LIMITE];
	int mayor;
	int minimo;
	float promedio;
	int valorNuevo;
	int opcionMenu;

	for(int i = 0; i < LIMITE; i++)
	{
		printf("Ingrese el número %d: ", i + 1);
		scanf("%d", &array[i]);
	}

	do
	{
		printf("\n1) Ver lista\n2) Ver máximo\n3) Ver mínimo\n4) Ver promedio\n5) Modificar valores\n6) Salir\n\n: ");
		__fpurge(stdin);
		scanf("%d", &opcionMenu);
		while(opcionMenu < 1 || opcionMenu > 6)
		{
			printf("\nError. Ingrese el número correspondiente con lo que desea hacer");
			printf("\n1) Ver lista\n2) Ver máximo\n3) Ver mínimo\n4) Ver promedio\n5) Modificar valores\n6) Salir\n\n: ");
			__fpurge(stdin);
			scanf("%d", &opcionMenu);
		}

		switch(opcionMenu)
		{
			case 1:
			{
				mostrarArray(array, LIMITE);
				break;
			}
			case 2:
			{
				numeroMaxArray(array, LIMITE, &mayor);
				printf("Número mayor: %d\n", mayor);
				break;
			}
			case 3:
			{
				numeroMinArray(array, LIMITE, &minimo);
				printf("Número menor: %d\n", minimo);
				break;
			}
			case 4:
			{
				promedioArray(array, LIMITE, &promedio);
				printf("Promedio: %0.2f\n", promedio);
				break;
			}
			case 5:
			{
				modificarValoresArray(array, LIMITE, &valorNuevo);
				break;
			}
		}
	}while(opcionMenu != 6);

	return EXIT_SUCCESS;
}
