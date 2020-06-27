/*
 * parser.c
 *
 *  Created on: 20 Jun 2020
 *      Author: Carlos
 */
//********************************************************************

#include "IOdata.h"
#include "articulo.h"
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"

int parser_eArticuloFromText(FILE* pFile , LinkedList* pArrayListArticulos)
{
	int retCode = -1;
	char bufferId[128];
	char bufferArticulo[128];
	char bufferMedida[128];
	char bufferPrecio[128];
	char bufferRubro[128];
	int cant = 0;
	int cont = 0;
	eArticulo* pAux = NULL;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferArticulo, bufferMedida, bufferPrecio,bufferRubro);
	while( !feof(pFile) )
	{
	cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferArticulo, bufferMedida, bufferPrecio,bufferRubro);

	if( cant != 5)
		{continue;}

	pAux = articulo_newParametros(bufferId, bufferArticulo, bufferMedida, bufferPrecio,bufferRubro);

		if(pAux != NULL)
		{
			if(!ll_add(pArrayListArticulos, pAux))
			{
				retCode = 0;
				cont++;
			}else{
				printf("Hubo un error al cargar la lista");
			}
		}

	}
	articulo_delete(pAux);
    return retCode;
}
