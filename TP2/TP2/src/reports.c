/*
 *NOMBRE: reports.C
 *DESCRIPCION: BIBLIOTECA DE FUNCIONES PARA EL MANEJO DE REPORTES
 *AUTOR: CARLOS LOPEZ
 */

#include "reports.h"
#define QTYEMPLOYEE 1000
#define EMPTY 0
#define NON_EMPTY 1

#include "ArrayEmployees.h"
#include "reports.h"
#include "IOdata.h"

int sortAndShoweEmployee(eEmployee* arrayeEmployee, int arraylength)
{
	int retCode = -1;
	int members;

	members = checkIfEmptyeEmployee(arrayeEmployee,arraylength);
	if(members == -1)
		{
			showMessage("No hay miembros para ordenar");
			system("pause");
		}else
		{
			sortEmployees(arrayeEmployee,arraylength);
			printEmployees(arrayeEmployee,arraylength,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
			system("pause");
			retCode = 1;
		}
	return retCode;
}

int showSalariesAndStatistics(eEmployee* arrayeEmployee, int arraylength)
{
	int retCode =-1;
	float sumSalary = 0;
	float countEmployee = 0;
	float mediumSalary = 0;
	int countUpperMediumSalary = 0;
	int members;

	members = checkIfEmptyeEmployee(arrayeEmployee,arraylength);
		if(members == -1)
			{
				showMessage("No hay miembros cargados aun");
				system("pause");
			}else
			{

				sumSalary = sumSalaries(arrayeEmployee,arraylength);
				countEmployee = countEmployees(arrayeEmployee,arraylength);
				mediumSalary = divide(sumSalary , countEmployee);
				if(countEmployee > 1)
				{
				countUpperMediumSalary = salaryStatistics(arrayeEmployee,arraylength,mediumSalary);
				}else
				{
					countUpperMediumSalary = 0;
				}
				showStatistics("TOTAL SUMA SALARIOS","PROMEDIO DE SALARIOS","EMPLEADOS POR ENCIMA DEL PROMEDIO",sumSalary,mediumSalary,countUpperMediumSalary);
				system("pause");
			}
	return retCode;
}

void showStatistics(char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,float indicator1,float indicator2,int indicator3)
{
	showMessage("*** INDICADORES SALARIALES ***");
	printf("************************************************************\n");
	printf("%-40s|", fieldTitle1);
	printf("%-20.2f|\n", indicator1);
	printf("%-40s|", fieldTitle2);
	printf("%-20.2f|\n", indicator2);
	printf("%-40s|", fieldTitle3);
	printf("%-20d|\n", indicator3);
	printf("************************************************************\n");
	printf("\n");
}

void reportsOption(eEmployee* arrayeEmployee, int arraylength)
{
	char reportOptions[] =
								"\n\n ** MENU DE REPORTES ***\
								\n\n  1-LISTADO DE EMPLEADOS ORDENADOS POR APELLIDO Y SECTOR\
								\n\n  2-INDICADORES DE SALARIOS\
								\n\n  3-VOLVER AL MENU PRINCIPAL\
								\n\n Ingrese una opcion: ";
	char reportError[] = "Error. Debe ingresar una opcion valida";
	int option;
	int members;

	members = checkIfEmptyeEmployee(arrayeEmployee,arraylength);
				if(members == -1)
				{
					showMessage("No hay empleados cargados aun");
					system("pause");
				}else
				{
				while(option != 3)
				{
				system("cls");
				getValidOption(&option, reportOptions,reportError,1,3,3);
						switch(option)
						{
						case 1:
							showMessage("*** LISTADO DE EMPLEADOS ***");
							sortAndShoweEmployee(arrayeEmployee,arraylength);
							break;
						case 2:
							showSalariesAndStatistics(arrayeEmployee,arraylength);
							break;
						case 3:
							break;
						}
					}
				}
}

