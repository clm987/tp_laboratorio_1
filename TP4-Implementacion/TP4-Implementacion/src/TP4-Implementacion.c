/*
 ============================================================================
 Name        : TP4-Implementacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "IOdata.h"
#include "articulo.h"
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"


int main(void)
{

	setbuf(stdout, NULL);
		LinkedList* pArrayListArticulos;
		pArrayListArticulos = ll_newLinkedList();
		int option = 0;
		int retcode;
		char bufferNombreDeArchivo[20];
		char menuDeOpciones[] =
				"\n\n1 CARGAR ARCHIVO\
				 \n\n2 IMPRIMIR LA LISTA DE ARTICULOS\
				 \n\n3 MOSTRAR LISTA ORDENADA POR NOMBRE DE ARTICULO\
				 \n\n4 CALCULAR DESCUENTOS\
				 \n\n5 GUARDAR ARCHIVO CON DESCUENTOS FINALES\
				 \n\n6 MENU DE INFORMES\
			     \n\n7 SALIR\
				 \n\n Ingrese una opcion: ";
		char mensajeError[] = "Error. Debe ingresar un opcion valida";


		while(option != 7)
		{
		system("cls");
		getValidOption(&option, menuDeOpciones,mensajeError,1,7,3);
		switch (option)
		{
			case 1:
				getComplexString(bufferNombreDeArchivo, "\nIngrese el nomnbre y extension del archivo (.csv) del archivo: ", "Error. Intente nuevamente");
				controller_loadFromText(bufferNombreDeArchivo, pArrayListArticulos);
				break;
			case 2:
				controller_printArticulos(pArrayListArticulos);
				break;
			case 3:
				controller_SortList(pArrayListArticulos);
				break;
			case 4:
				retcode = controller_MappList(pArrayListArticulos);
				break;
			case 5:
				if(retcode == 0)
				{
					controller_saveAsText("mapeado.csv",pArrayListArticulos);
				}
				else
				{
					showMessage("No se han calculado los descuentos aun");
					system("pause");
				}
				break;
			case 6:
				controller_informes(pArrayListArticulos);
			break;
			case 7:
			break;
		}
	}



























	return 0;
}
