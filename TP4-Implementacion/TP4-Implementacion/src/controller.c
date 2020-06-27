/*
 * controller.c
 *
 *  Created on: 20 Jun 2020
 *      Author: Carlos
 */
#include "IOdata.h"
#include "parser.h"
#include "LinkedList.h"
#include "articulo.h"
#include "controller.h"
int controller_loadFromText(char* path , LinkedList* pArrayListArticulos)
{
	FILE* file;
	int retCode = -1;
	int length;

	if(pArrayListArticulos != NULL && path != NULL)
	{
		length = ll_len(pArrayListArticulos);
		if(length == 0)
		{
			file = fopen(path,"r");

			if(file == NULL)
			{
			 showMessage ("Ocurrio un error al abrir el archivo. Se cerrara la aplicacion");
			 system("pause");
			}

			if(!parser_eArticuloFromText(file , pArrayListArticulos))
			{
				retCode = 0;
			}

			fclose(file);

			if(retCode == 0)
			{
			showMessage("Base de articulos cargada con exito!");
			system("pause");
			}
		}
		else
		{
			showMessage("La base de articulos ya fue cargada previamente!");
		}
	}
    return retCode;
}

int controller_printArticulos(LinkedList* this)
{
	int retCode = -1;
	int length;
	int i;
    int bufferId;
    int rubroId;
    char bufferMedida[128];
    char bufferArticulo[128];
    char bufferRubroNombre[128];
    float bufferPrecio;
	eArticulo* auxP;
	auxP = articulo_new();

	if(this != NULL)
	{
		length = ll_len(this);

		if(length == 0)
		{
			showMessage("No hay articulos cargados aun");
			system("pause");
		}
		else
		{
				for(i=0; i<length; i++)
				{
					auxP = (eArticulo*)ll_get(this,i);
					if(auxP != NULL)
					{
						getArticulos(&bufferId,bufferMedida,bufferArticulo,&bufferPrecio,bufferRubroNombre,&rubroId,auxP);
						printf("%-5s %-10s %-40s %-10s %-30s %-5s\n", "ID","MEDIDA","ARTICULO","PRECIO","NOMBRE DEL RUBRO","ID DEL RUBRO");
						printf("\n%-5d  %-10s %-40s %-10.2f %-30s %-5d\n", bufferId,bufferMedida,bufferArticulo,bufferPrecio,bufferRubroNombre,rubroId);
						retCode = 0;
					}
				}
		}
	}

	if(retCode != 0 && length > 0)
	{
		showMessage("Ocurrió un error al mostrar los datos");
		system("pause");
	}
	system("pause");
	return retCode;
}

int controller_saveAsText(char* path , LinkedList* pArrayListArticulos)
{
		int retCode = -1;
	    int i;
	    int length;
	    int bufferId;
	    char bufferMedida[128];
	    char bufferArticulo[128];
	    char bufferRubroNombre[128];
	    float bufferPrecio;
	    int rubroId;


	    if(path!=NULL && pArrayListArticulos!=NULL)
	    {
	    	length = ll_len(pArrayListArticulos);

	        if(length == 0)
	        {
	        	showMessage("Aun no hay articulos cargados.");
	        	system("pause");
	        }
	        else
	        {
		        FILE* pFile;
		        eArticulo* auxP = NULL;
		        auxP = articulo_new();
		        pFile = fopen(path,"w");
					if(pFile!=NULL )
					{
						for(i=0; i<length; i++)
						{
							auxP = (eArticulo*)ll_get(pArrayListArticulos,i);
							getArticulos(&bufferId,bufferMedida,bufferArticulo,&bufferPrecio,bufferRubroNombre,&rubroId,auxP);
							if(auxP != NULL)
							{

								if(!getArticulos(&bufferId,bufferMedida,bufferArticulo,&bufferPrecio,bufferRubroNombre,&rubroId,auxP))
								{
									fprintf(pFile, "%d,%s,%s,%.2f,%s,%d\n",bufferId,bufferMedida,bufferArticulo,bufferPrecio,bufferRubroNombre,rubroId);
								}
								else
								{
									printf("Error\n");
								}
								retCode = 0;
							}
						}
					if(retCode == 0)
					{
						showMessage("ARCHIVO GUARDADO CON EXITO");
						system("pause");
					}
		fclose(pFile);
					}
	        }
		}

	    if(retCode == 0)
	    {
	    	showMessage("Archivo guardado con exito!");
	    }
	    return retCode;
}

int controller_SortList(LinkedList* pArrayListArticulos)
{
	int retCode = -1;
	int length;

	if(pArrayListArticulos != NULL)
	{
		length = ll_len(pArrayListArticulos);
		if(length == 0)
		{
			showMessage("No hay articulos cargados aun.");
			system("pause");
		}
		else
		{
			retCode = ll_sort(pArrayListArticulos,ordenarPorArticulo,1);
			if(retCode == 0)
			{
				showMessage("La lista ha sido ordenada con exito");
				system("pause");
			}
			else
			{
				showMessage("Ocurrio un error al ordenar la lista");
				system("pause");
			}
		}


	}
	return retCode;
}


int controller_MappList(LinkedList* pArrayListArticulos)
{
	int retCode = -1;
	int length;
	LinkedList* thisList;

	if(pArrayListArticulos != NULL)
	{
		length = ll_len(pArrayListArticulos);
		if(length == 0)
		{
			showMessage("No hay articulos cargados aun.");
			system("pause");
		}
		else
		{
			thisList = ll_map(pArrayListArticulos,calculoDeDescuentos);
			if(thisList != NULL)
			{
				retCode = 0;
				showMessage("Los descuentos fueron calculados con exito");
				system("pause");
			}
			else
			{
				showMessage("Ocurrio un error al modificar los precios");
				system("pause");
			}
		}
	}
	return retCode;
}

int controller_CountArticulo(LinkedList* pArrayListArticulos)
{
	int retCode = -1;
	int length;
	int cantArticulos;

	if(pArrayListArticulos != NULL)
	{
		length = ll_len(pArrayListArticulos);
		if(length == 0)
		{
			showMessage("No hay articulos cargados aun.");
			system("pause");
		}
		else
		{
			cantArticulos = ll_count(pArrayListArticulos,articulosPorMontoA);
			if(cantArticulos != -1)
			{
				printf("\nEL total de articulos de mas de 100 fue:  %d\n",cantArticulos);
				system("pause");
			}
			else
			{
				showMessage("Ocurrio un error al mostrar la cantidad de articulos");
				system("pause");
			}
		}
	}
	return retCode;
}

int controller_CountRubro(LinkedList* pArrayListArticulos)
{
	int retCode = -1;
	int length;
	int cantArticulos;

	if(pArrayListArticulos != NULL)
	{
		length = ll_len(pArrayListArticulos);
		if(length == 0)
		{
			showMessage("No hay articulos cargados aun.");
			system("pause");
		}
		else
		{
			cantArticulos = ll_count(pArrayListArticulos,articulosPorRubroA);
			if(cantArticulos != -1)
			{
				printf("\nEL total de articulos del Rubro 1 fue: %d\n",cantArticulos);
				system("pause");
			}
			else
			{
				showMessage("Ocurrio un error al mostrar la cantidad de articulos");
				system("pause");
			}
		}
	}
	return retCode;
}


int controller_informes(LinkedList* pArrayListArticulos)
{
	int retCode = -1;
	int length;
	char SubmenuDeInformes[] =
				"\n\n    *** MENU DE INFORMES ****                 \
				 \n\n1 CANTIDAD DE ARTICULOS CON PRECIO MAYOR A 100\
				 \n\n2 CANTIDAD DE ARTICULOS DEL RUBRO 1\
			     \n\n3 REGRESAR A LA PANTALLA ANTERIOR\
				 \n\n Ingrese una opcion: ";
	char mensajeError[] = "Error. Debe ingresar un opcion valida";
	int option;

	if(pArrayListArticulos != NULL)
		{
			length = ll_len(pArrayListArticulos);
			if(length == 0)
			{
				showMessage("No hay articulos cargados aun.");
				system("pause");
			}
			else
			{

				while(option != 3)
				{
				system("cls");
				getValidOption(&option, SubmenuDeInformes,mensajeError,1,3,3);

					switch(option)
					{
					case 1:
						controller_CountArticulo(pArrayListArticulos);
						retCode = 0;
						break;
					case 2:
						controller_CountRubro(pArrayListArticulos);
						retCode = 0;
						break;
					case 3:
						break;
					}
				}
			}
		}

	return retCode;
}



















