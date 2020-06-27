/*
 ============================================================================
 Name        : TP2.c
 Author      : CARLOS LOPEZ MORANTES
 Description : ABM DE EMPLEADOS Y REPORTE DE LISTADO E INDICADORES.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "IOdata.h"
#include "reports.h"

int main(void)
{

	eEmployee eEmployeeArray[QTYEMPLOYEE];
	initEmployees(eEmployeeArray, QTYEMPLOYEE,EMPTY);
	int option = 0;
	char menuDeOpciones[] =
						"\n\n1 ALTA DE EMPLEADO\
						 \n\n2 MODIFICACION EMPLEADO\
						 \n\n3 BAJA EMPLEADO\
						 \n\n4 MENU DE REPORTES\
						 \n\n5 SALIR\
						 \n\n Ingrese una opcion: ";
	char mensajeError[] = "Error. Debe ingresar un opcion valida";

				while(option != 5)
				{
					system("cls");
					getValidOption(&option, menuDeOpciones,mensajeError,1,6,3);

					switch (option)
					{
					case 1:
						addEmployees(eEmployeeArray,QTYEMPLOYEE);
						break;
					case 2:
						modifyeEmployee(eEmployeeArray,QTYEMPLOYEE);
						break;
					case 3:
						removeEmployee(eEmployeeArray,QTYEMPLOYEE);
						break;
					case 4:
						reportsOption(eEmployeeArray, QTYEMPLOYEE);
						break;
					case 5:
						break;
					}
				}


	return 0;
}
