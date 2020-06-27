/*
 *NOMBRE:  ArrayEmployees.h
 *DESCRIPCION: BIBLIOTECA DE FUNCIONES PARA EL MANEJO DE LA ENTIDAD eEmployee
 *AUTOR: CARLOS LOPEZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "IOdata.h"
#include "ArrayEmployees.h"


void initEmployees(eEmployee* eEmployeeArray,int arrayLength,int value)
{
    int i;
    for(i = 0; i < arrayLength; i++)
    {
    	eEmployeeArray[i].isEmpty = value;
    	eEmployeeArray[i].sector = 0;
    	eEmployeeArray[i].salary = 0;
    	eEmployeeArray[i].ideEmployee = 0;
    }
}

int findEmptyPlace(eEmployee* eEmployeeArray,int arrayLength, int value)
{
    int i;
    int retCode = -1;
    for(i = 0; i < arrayLength; i++)
    {
    	if(eEmployeeArray[i].isEmpty == value)
    	{
    		retCode = i;
    	}
    }
    return retCode;
}

int addEmployees(eEmployee* eEmployeeArray, int arrayLength)
{
	int retCode = -1;
	int index = findEmptyPlace(eEmployeeArray, QTYEMPLOYEE,EMPTY);
	char menuDesectores[] =
							"\n\n ** SECTORES ***\
							\n\n 1-RRHH\
							\n\n 2-SISTEMAS\
							\n\n 3-FINANZAS\
							\n\n 4-OPERACIONES\
							\n\n Ingrese el numero de sector: ";
	char errorSectores[] = "Error. Debe ingresar un numero de sector valido";

	if(index == -1)
	{
		showMessage("\nNo hay lugares disponibles.");
	}
	else
	{
		getAlphaString(eEmployeeArray[index].name, "\nIngrese el nombre: ", "\n Error. El nombre solo debe contener letras.");
		getAlphaString(eEmployeeArray[index].lastName, "\nIngrese el apellido: ", "\n Error. El apellido solo debe contener letras.");
		getValidOption(&eEmployeeArray[index].sector,menuDesectores,errorSectores,1,4,3);
		getFloatNumber(&eEmployeeArray[index].salary,"Ingrese el salario: ", "\n Error. El salario solo puede contener numeros",3);
		eEmployeeArray[index].ideEmployee = generateIdeEmployee();
		eEmployeeArray[index].isEmpty = NON_EMPTY;
		showMessage("\nAlta dada con exito!!");
		showeEmployee(eEmployeeArray,index,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
		system("pause");
		retCode = 0;
	}

	return retCode;
}

void showeEmployee(eEmployee* eEmployeeArray, int index, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4,char* fieldTitle5)
{
	char pipe =' ';

	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle1);
	printf("%-40c|\n", pipe);
	printf("%-40s|\n", eEmployeeArray[index].name);
	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle2);
	printf("%-40c|\n", pipe);
	printf("%-40s|\n", eEmployeeArray[index].lastName);
	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle3);
	printf("%-40c|\n", pipe);
	printf("%-40d|\n", eEmployeeArray[index].sector);
	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle4);
	printf("%-40c|\n", pipe);
	printf("%-40.2f|\n",eEmployeeArray[index].salary);
	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle5);
	printf("%-40c|\n", pipe);
	printf("%-40d|\n", eEmployeeArray[index].ideEmployee);
	printf("****************************************|\n");


}

int generateIdeEmployee()
{
    static int id=1;

    return id++;
}

int findeEmployeeById(eEmployee* eEmployeeArray,int arrayLength, int id)
{
    int i;
    int retCode = -1;
    for(i = 0; i < arrayLength; i++)
    {
        if(eEmployeeArray[i].ideEmployee == id && eEmployeeArray[i].isEmpty == NON_EMPTY)
        {
        	retCode = i;
        }
    }
    return retCode;
}


int modifyeEmployee(eEmployee* eEmployeeArray, int arraylength)
{
	int retCode = -1;
	int index;
	int option;
	int id;
	int members;
	char menuDesectores[] =
								"\n\n ** INGRESE EL SECTOR ***\
								\n\n 1-RRHH\
								\n\n 2-SISTEMAS\
								\n\n 3-FINANZAS\
								\n\n 4-OPERACIONES ";
	char errorSectores[] = "Error. Debe ingresar un sector valido";
	char subMenu[] =
				"\n\n1 MODIFICAR NOMBRE\
				 \n\n2 MODIFICAR APELLIDO\
				 \n\n3 MODIFICAR SECTOR\
				 \n\n4 MODIFICAR SALARIO\
				 \n\n5 VOLVER AL MENU PRINCIPAL\
				 \n\n Ingrese una opcion: ";
	char mensajeError[] = "Error. Debe ingresar un opcion valida";
	members = printEmployees(eEmployeeArray,arraylength,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");

	if(members == -1)
	{
		showMessage("No hay miembros para modificar");
		system("pause");
	}else
	{

	getNaturalNumber(&id,"\nIngrese el id del empleado a modificar: ","\nError. El Id solo puede ser numerico",3);
	index = findeEmployeeById(eEmployeeArray,arraylength,id);

	while(index == -1)
	{
		showMessage("Debe ingresar ID valido. Intente nuevamente: ");
		printEmployees(eEmployeeArray,arraylength,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
		getNaturalNumber(&id,"\nIngrese el id a modificar: ","\nError. El Id solo puede ser numerico",3);
		index = findeEmployeeById(eEmployeeArray,arraylength,id);
	}
	showMessage("\nDATOS DEL EMPLEADO A MODIFICAR ");
	showeEmployee(eEmployeeArray,index,"NOMBRE A MODIFICAR", "APELLIDO A MODIFICAR","SECTOR A MODIFICAR","SALARIO A MODIFICAR", "ID");

	while(option != 5)
	{
	getValidOption(&option, subMenu,mensajeError,1,5,3);
		switch(option)
		{
		case 1:
			getAlphaString(eEmployeeArray[index].name, "\nIngrese el nuevo nombre: ", "\nError. El nombre solo debe contener letras.");
			showMessage("\n Los nuevos datos son: ");
			showeEmployee(eEmployeeArray,index,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
			fflush(stdin);
			system("pause");
		break;
		case 2:
			getAlphaString(eEmployeeArray[index].lastName, "\nIngrese el nuevo apellido: ", "\nError. El apellido solo debe contener letras.");
			showMessage("\n Los nuevos datos son: ");
			showeEmployee(eEmployeeArray,index,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
			fflush(stdin);
			system("pause");
		break;
		case 3:
			getValidOption(&eEmployeeArray[index].sector,menuDesectores,errorSectores,1,3,3);
			showMessage("\n Los nuevos datos son: ");
			showeEmployee(eEmployeeArray,index,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
			fflush(stdin);
			system("pause");
		break;
		case 4:
			getFloatNumber(&eEmployeeArray[index].salary,"Ingrese el nuevo salario", "Error. El salario solo puede contener numeros",3);
			showMessage("\n Los nuevos datos son: ");
			showeEmployee(eEmployeeArray,index,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
			fflush(stdin);
			system("pause");
		break;
		case 5:
		break;
		}
	}

	}

	return retCode;
}

int printEmployees(eEmployee* eEmployeeArray, int arraylength, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4,char* fieldTitle5)
{
	int retCode = -1;
	int i;
	int emptyPlaces = 0;

	for(i=0;i<arraylength;i++)
	{
		if(eEmployeeArray[i].isEmpty==EMPTY)
		{
			emptyPlaces ++;
			continue;
		}
		else
		{
		printf("%-20s|", fieldTitle1);
		printf("%-20s|", eEmployeeArray[i].name);
		printf("%-20s|", fieldTitle2);
		printf("%-20s|", eEmployeeArray[i].lastName);
		printf("%-8s|", fieldTitle3);
		printf("%-5d|", eEmployeeArray[i].sector);
		printf("%-10s|", fieldTitle4);
		printf("%-15.2f|", eEmployeeArray[i].salary);
		printf("%-5s|", fieldTitle5);
		printf("%-4d|", eEmployeeArray[i].ideEmployee);
		printf("\n");
		}
	}

	if(emptyPlaces < arraylength)
	{
		retCode = 0;
	}


	return retCode;
}

int removeEmployee(eEmployee* arrayeEmployee, int arrayLength)
{
	int retCode = -1;
	int id;
	int index;
	int members;
	char confirmation;

	members = printEmployees(arrayeEmployee,arrayLength,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
	if(members == -1)
	{
		showMessage("No hay empleados cargados aun");
		system("pause");
	}else
	{
	getNaturalNumber(&id,"Ingrese el id del empleado quiere dar de baja: ","Error. El Id solo puede ser numerico",3);
	index = findeEmployeeById(arrayeEmployee,arrayLength,id);

	while(index == -1)
		{
			showMessage("Debe ingresar ID valido. Intente nuevamente: ");
			printEmployees(arrayeEmployee,arrayLength,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
			getNaturalNumber(&id,"\nIngrese el id del empleado quiere dar de baja: ","\nError. El Id solo puede ser numerico",3);
			index = findeEmployeeById(arrayeEmployee,arrayLength,id);
		}
	system("cls");
	showMessage("MIEMBRO A SER DADO DE BAJA\n");
	showeEmployee(arrayeEmployee,index,"NOMBRE", "APELLIDO","SECTOR","SALARIO", "ID");
	confirmation = getConfirmationeEmployee("Ingrese 's' para confirmar la baja o 'n' para cancelar: ");
	system("pause");
	if(confirmation == 's')
	{
	deleteeEmployeeById(arrayeEmployee,arrayLength,id);
	}


	}
	return retCode;
}

int deleteeEmployeeById(eEmployee* eEmployeeArray,int arrayLength, int id)
{
    int i;
    int retCode = -1;

    for(i = 0; i < arrayLength; i++)
    {
        if(eEmployeeArray[i].ideEmployee == id && eEmployeeArray[i].isEmpty == NON_EMPTY)
        {
        	eEmployeeArray[i].isEmpty = EMPTY;

        	retCode = 0;
        }
    }
    return retCode;
}

char getConfirmationeEmployee(char* message)
{
	char retA = 'n';

    do {
        printf("%s", message);
        fflush(stdin);
        scanf("%c", &retA);
        retA = tolower(retA);

    } while (retA != 's' && retA != 'n');

	return retA;
}

int sortEmployees(eEmployee* arrayeEmployee,int arrayLength)
{
	int retCode = -1;
	int i;
	int flaggSort;
	char bufferApellido[64];
	char bufferNombre[64];
	float bufferSalary;
	int bufferSector;
	int bufferIdeEmployee;
	int bufferIsEmpty;
	int flexLimit;

	  if(arrayeEmployee!=NULL && arrayLength >= 0)
	  {	flexLimit = arrayLength -1;
	  	  do
	  	  {
	  		flaggSort = 0;

	  		for (i = 0; i < flexLimit;  i++)
			  {
				  if(arrayeEmployee[i].sector > arrayeEmployee[i+1].sector)
				  {
					  flaggSort = 1;

						  strcpy(bufferApellido,arrayeEmployee[i].lastName);
						  strcpy(bufferNombre,arrayeEmployee[i].name);
						  bufferSector = arrayeEmployee[i].sector;
						  bufferSalary = arrayeEmployee[i].salary;
						  bufferIdeEmployee = arrayeEmployee[i].ideEmployee;
						  bufferIsEmpty = arrayeEmployee[i].isEmpty;

						  strcpy(arrayeEmployee[i].lastName,arrayeEmployee[i+1].lastName);
						  strcpy(arrayeEmployee[i].name,arrayeEmployee[i+1].name);
						  arrayeEmployee[i].sector = arrayeEmployee[i+1].sector;
						  arrayeEmployee[i].salary = arrayeEmployee[i+1].salary;
						  arrayeEmployee[i].ideEmployee = arrayeEmployee[i+1].ideEmployee;
						  arrayeEmployee[i].isEmpty = arrayeEmployee[i+1].isEmpty;

						  strcpy(arrayeEmployee[i + 1].lastName,bufferApellido);
						  strcpy(arrayeEmployee[i + 1].name,bufferNombre);
						  arrayeEmployee[i + 1].sector = bufferSector;
						  arrayeEmployee[i + 1].salary = bufferSalary;
						  arrayeEmployee[i + 1].ideEmployee = bufferIdeEmployee;
						  arrayeEmployee[i + 1].isEmpty = bufferIsEmpty;

				  }else if((arrayeEmployee[i].sector == arrayeEmployee[i+1].sector)&&(strcmp(arrayeEmployee[i].lastName,arrayeEmployee[i+1].lastName)>0)  )
				  {
					  flaggSort = 1;

						  strcpy(bufferApellido,arrayeEmployee[i].lastName);
						  strcpy(bufferNombre,arrayeEmployee[i].name);
						  bufferSector = arrayeEmployee[i].sector;
						  bufferSalary = arrayeEmployee[i].salary;
						  bufferIdeEmployee = arrayeEmployee[i].ideEmployee;
						  bufferIsEmpty = arrayeEmployee[i].isEmpty;

						  strcpy(arrayeEmployee[i].lastName,arrayeEmployee[i+1].lastName);
						  strcpy(arrayeEmployee[i].name,arrayeEmployee[i+1].name);
						  arrayeEmployee[i].sector = arrayeEmployee[i+1].sector;
						  arrayeEmployee[i].salary = arrayeEmployee[i+1].salary;
						  arrayeEmployee[i].ideEmployee = arrayeEmployee[i+1].ideEmployee;
						  arrayeEmployee[i].isEmpty = arrayeEmployee[i+1].isEmpty;

						  strcpy(arrayeEmployee[i + 1].lastName,bufferApellido);
						  strcpy(arrayeEmployee[i + 1].name,bufferNombre);
						  arrayeEmployee[i + 1].sector = bufferSector;
						  arrayeEmployee[i + 1].salary = bufferSalary;
						  arrayeEmployee[i + 1].ideEmployee = bufferIdeEmployee;
						  arrayeEmployee[i + 1].isEmpty = bufferIsEmpty;
				  }

			  }
	  		flexLimit--;

	  	  }while(flaggSort);
	  	  retCode = 0;
	  }

	  return  retCode;
}

int checkIfEmptyeEmployee(eEmployee* eEmployeeArray,int arrayLength)
{
    int i;
    int retCode = -1;
    for(i = 0; i < arrayLength; i++)
    {
    	if(eEmployeeArray[i].isEmpty == NON_EMPTY)
    	{
    		retCode = 1;
    	}
    }
    return retCode;
}

float sumSalaries(eEmployee* eEmployeeArray,int arraylength)
{
    int i;
    float retCode = -1;
    float sum = 0;

    for(i = 0; i < arraylength; i++)
    {
    	if(eEmployeeArray[i].isEmpty == NON_EMPTY)
    	{
    		sum += eEmployeeArray[i].salary;
    		retCode = sum;
    	}
    }
    return retCode;
}

int countEmployees(eEmployee* eEmployeeArray,int arraylength)
{
    int i;
    int retCode = -1;
    int count = 0;

    for(i = 0; i < arraylength; i++)
    {
    	if(eEmployeeArray[i].isEmpty == NON_EMPTY)
    	{
    		count++;
    		retCode = count;
    	}
    }
    return retCode;
}

int salaryStatistics(eEmployee* eEmployeeArray,int arraylength, float average)
{
    int i;
    int retCode = -1;
    int count = 0;

    for(i = 0; i < arraylength; i++)
    {
    	if(eEmployeeArray[i].isEmpty == NON_EMPTY)
    	{
    		if(eEmployeeArray[i].salary > average)
    		{
    			count++;
    			retCode = count;
    		}

    	}
    }
    return retCode;
}
