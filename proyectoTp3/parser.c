#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "IOdata.h"

//********************************************************************
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char bufferId[128];
	char bufferNombre[128];
	char bufferHorasTrabajadas[128];
	char bufferSalario[128];
	int cant = 0;
	int retCode = -1;
	Employee* pAuxEmployee = NULL;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSalario);

	while( !feof(pFile) )
	{
	cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSalario);
		if( cant < 4)
		{break;}

		pAuxEmployee = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSalario);

		if(pAuxEmployee != NULL)
		{
			if(!ll_add(pArrayListEmployee, pAuxEmployee))
			{
				retCode = 0;
			}else{
				printf("Hubo un error al cargar la lista");
			}
		}

	}
	employee_delete(pAuxEmployee);
    return retCode;
}

//*****************************************************************
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retCode = -1;
	int readCont = 0;

	Employee* pAuxEmployee = NULL;

		if(pFile != NULL && pArrayListEmployee != NULL)
		{
			do{
			pAuxEmployee = employee_new();
					if(pAuxEmployee != NULL)
					{
						readCont = fread(pAuxEmployee,(sizeof(Employee)),1,pFile);
							if( readCont < 1)
							{
										if(feof(pFile))
										{
											break;
										}
										else
										{
											showMessage ("Ocurrio un error al leer el archivo. Se cerrara la aplicacion");
										}
							}
								ll_add(pArrayListEmployee, pAuxEmployee);
					}
			}while(!feof(pFile));
		retCode = 0;
		fclose(pFile);
		employee_delete(pAuxEmployee);
		}
   return retCode;
}