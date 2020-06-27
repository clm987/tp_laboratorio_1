/*
 ============================================================================
 Name        : Calculadora
 Author      : Carlos López
 Description : Calculadora TP1 Laboratorio 1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main(void) {

	float numero1;
	float numero2;
	int opcion;
	int flagg = 0;
	int flagg1 = 0;
	int flagg2 = 0;
	float suma;
	float resta;
	float division;
	float producto;
	float factorial1;
	float factorial2;
	setbuf(stdout,NULL);

do
{		system("color 0F");
		printf("*---------{ Bienvenido!}---------*\n");
		printf("*--------------------------------*\n");
		printf("*-------MENU DE OPCIONES --------*\n");
		if(flagg == 0)
		{
		printf("1. Ingresar 1er operando (A=x)\n");
		}
		else
		{
		printf("1. Ingresar 1er operando (A=%.2f)\n", numero1);
		}
		if(flagg1 == 0)
		{
		printf("2. Ingresar 2do operando (B=y)\n");
		}
		else
		{
		printf("2. Ingresar 2do operando (B=%.2f)\n", numero2);
		}
		printf("3. Calcular todas las operaciones\n");
		printf("\t -- Suma (A+B)\n");
		printf("\t -- Resta (A-B)\n");
		printf("\t -- Division (A/B)\n");
		printf("\t -- Multiplicacion (A*B)\n");
		printf("\t -- Factorial de A y de B\n");
		printf("4. Mostrar los resultados\n");
		printf("5. Salir\n");
		getOpcion(&opcion,"*-------Ingrese una opcion : ----*\n", "Opcion incorrecta debe ingresar 1,2,3,4 o 5.\n", 1, 5, 1000);

		switch(opcion)
		{
		case 1:
			system("CLS");
			getNumero(&numero1, "Ingrese el primer operando: \n","Error. Debe ingresar un numero \n", 1000);
			flagg = 1;
			system("CLS");
			break;
		case 2:
			system("CLS");
			getNumero(&numero2, "Ingrese el segundo operando: \n","Error. Debe ingresar un numero \n", 1000);
			flagg1 = 1;
			system("CLS");
			break;
		case 3:
			system("CLS");
			if (flagg == 1 && flagg1 == 1)
			{
				suma = sumar(numero1, numero2);
				resta = restar(numero1, numero2);
				producto = multiplicar(numero1, numero2);
				factorial1 = calcularFactorial(numero1);
				factorial2 = calcularFactorial(numero2);
				division = dividir(numero1, numero2);
					if(factorial1 == -1)
					{
						getNumero(&numero1, "No se puede calcular el factorial de un negativo .\nIngrese el primer operando nuevamente: \n","Error. Debe ingresar un numero \n", 1000);
					}
					else if (factorial2 == -1)
					{
						getNumero(&numero2, "No se puede calcular el factorial de un negativo .\nIngrese el segundo operando nuevamente: \n","Error. Debe ingresar un numero \n", 1000);
					}
					else if (dividir(numero1, numero2) == -1)
					{
					getNumero(&numero2, "No se puede dividir por cero.\nIngrese el segundo operando nuevamente: \n","Error. Debe ingresar un numero \n", 1000);
					system("CLS");
					}
					else
					{
					system("CLS");
					mostrarMensaje ("Los calculos se han realizado satisfactoriamente ");
					flagg2 = 1;
					}
			}
			else
			{
				mostrarMensaje ("Debe ingresar ambos operandos antes de realizar las operaciones");
			}
			break;
		case 4:
			system("CLS");
			if (flagg2 == 1)
			{
				mostrarResultados(suma, resta, division, producto, factorial1, factorial2, numero1, numero2);
			}
			else
			{
				system("CLS");
				mostrarMensaje ("Aun no se han calculado las operaciones.");
			}
			break;
		case 5:
			system("CLS");
			mostrarMensaje ("Cerrando la calculadora... ");
			system("pause");
			flagg = 0;
			break;
		}

}while (opcion != 5);

	return 0;
}

