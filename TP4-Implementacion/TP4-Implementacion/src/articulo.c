/*
 * articulo.c
 *
 *  Created on: 24 Jun 2020
 *      Author: Carlos
 */
#include <stdio.h>
#include <stdlib.h>
#include "IOdata.h"
#include "articulo.h"
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"
#define LENGTH 128

eArticulo* articulo_new()
{
	eArticulo* this = (eArticulo*) malloc(sizeof(eArticulo));
	if(this != NULL)
	{
		this->Id_Articulo = 0;
		strcpy(this->articulo,"");
		strcpy(this->medida,"");
		this->precio = 0;
		this->rubro.id_rubro = 0;
		strcpy(this->rubro.nombre_rubro,"");
	}
	return this;
}

eRubro* eRubro_new()
{
	eRubro* this = (eRubro*) malloc(sizeof(eRubro));
	if(this != NULL)
	{
		this->id_rubro = 0;
		strcpy(this->nombre_rubro,"");
	}
	return this;
}

void articulo_delete(eArticulo* this)
{
    free(this);
}

void rubro_delete(eRubro* this)
{
    free(this);
}

eArticulo* articulo_newParametros(char* idStr, char* articulo, char* medida, char* precio, char* rubro)
{
	eArticulo* this = NULL;
	this = articulo_new();

	if(this != NULL)
	{
		if(articulo_setId(this, idStr) ==0 &&
		   articulo_setNombreArticulo(this,articulo) == 0 &&
		   articulo_setMedida(this,medida) == 0 &&
		   articulo_setPrecio(this,atof(precio)) == 0 &&
		   articulo_setRubros(this, rubro) ==0 )
		{
			return this;
		}else
		{
			this = NULL;
		}
	}
return this;
}

///////////////////////////////////// SETTERS //////////////////////////////////////////

int articulo_setId(eArticulo* this,char* id)
{
	int retCode = -1;
	if(this != NULL && id != NULL)
	{
		retCode = 0;
		this->Id_Articulo = atoi(id);
	}
	return retCode;
}

int articulo_setNombreArticulo(eArticulo* this,char* nArticulo)
{
	int retCode = -1;
	if(this != NULL && nArticulo != NULL)
		{
				strncpy(this->articulo,nArticulo,LENGTH);
				retCode = 0;
		}
	return retCode;
}

int articulo_setMedida(eArticulo* this,char* medida)
{
	int retCode = -1;
	if(this != NULL && medida != NULL)
		{
				strncpy(this->medida,medida,LENGTH);
				retCode = 0;
		}
	return retCode;
}

int articulo_setPrecio(eArticulo* this, float precio)
{
	int retCode = -1;
	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retCode = 0;
	}
	return retCode;
}

int eRubro_setId(eRubro* this,char* rubro)
{
	int retCode = -1;
	if(this != NULL && rubro != NULL)
	{
		retCode = 0;
		this->id_rubro = atoi(rubro);
	}
	return retCode;
}


int articulo_setRubros(eArticulo* this, char* rubro)
{
	int retCode = -1;
	eRubro* thisRubro = NULL;
	thisRubro = eRubro_new();

	if(this != NULL && thisRubro != NULL && rubro != NULL)
	{
		if(eRubro_setId(thisRubro, rubro) == 0)
		{
			switch(atoi(rubro))
			{
			case 1:
				strcpy(thisRubro->nombre_rubro,"CUIDADO DE ROPA");
				this->rubro = *thisRubro;
				retCode = 0;
			break;
			case 2:
				strcpy(thisRubro->nombre_rubro,"LIMPIEZA Y DESINFECCION");
				this->rubro = *thisRubro;
				retCode = 0;
			break;
			case 3:
				strcpy(thisRubro->nombre_rubro,"CUIDADO PERSONAL E HIGIENE");
				this->rubro = *thisRubro;
				retCode = 0;
			break;
			case 4:
				strcpy(thisRubro->nombre_rubro,"CUIDADO DEL AUTOMOTOR");
				this->rubro = *thisRubro;
				retCode = 0;
			break;
			}
		}
	}

	return retCode;
}
///////////////////////////////////// GETTERS //////////////////////////////////////////

int articulo_getId(eArticulo* this,int* id)
{
    int retCode=-1;
    if(this!=NULL && id != NULL)
    {
        *id=this->Id_Articulo;
        retCode=0;
    }
    return retCode;
}

int articulo_getArticuloNombre(eArticulo* this,char* articuloNombre)
{
    int retCode=-1;
    if(this!=NULL && articuloNombre != NULL)
    {
        strcpy(articuloNombre,this->articulo);
        retCode=0;
    }
    return retCode;
}

int articulo_getMedida(eArticulo* this,char* medida)
{
    int retCode=-1;
    if(this!=NULL && medida != NULL)
    {
        strcpy(medida,this->medida);
        retCode=0;
    }
    return retCode;
}

int  articulo_getPrecio(eArticulo* this,float* precio)
{
    int retCode=-1;
    if(this!=NULL && precio != NULL)
    {
        *precio=this->precio;
        retCode=0;
    }
    return retCode;
}

int  articulo_getRubro(eArticulo* this,int* idRubro, char* nombreRubro)
{
    int retCode=-1;

    if(this!=NULL && idRubro != NULL && nombreRubro != NULL)
    {
        *idRubro= this->rubro.id_rubro;
        strcpy(nombreRubro,this->rubro.nombre_rubro);
        retCode=0;
    }
    return retCode;
}

int getArticulos(int* id, char* bufferMedida,char* bufferArticulo, float* bufferPrecio, char* rubroNombre, int* idRubro, eArticulo* this)
{
	int retCode = -1;

		if(id != NULL && bufferMedida != NULL && bufferArticulo != NULL && bufferPrecio != NULL &&  this != NULL)
		{
			if( articulo_getId(this,id) == 0 &&
				articulo_getArticuloNombre(this,bufferArticulo) == 0 &&
				articulo_getMedida(this,bufferMedida) ==0 &&
				articulo_getPrecio(this,bufferPrecio) == 0 &&
				articulo_getRubro(this,idRubro,rubroNombre) == 0)
			{
				retCode = 0;
			}
		}

	return retCode;
}

int ordenarPorArticulo(void* genericField1, void* genericfield2)
{
    int retCode = -2;
    eArticulo* pAux1 = NULL;
    eArticulo* pAux2 = NULL;
    char AuxName1[128];
    char AuxName2[128];

    	pAux1 = (eArticulo*)genericField1;
    	pAux2 = (eArticulo*)genericfield2;

    	articulo_getArticuloNombre(pAux1,AuxName1);
    	articulo_getArticuloNombre(pAux2,AuxName2);

        if(stricmp(AuxName1,AuxName2)>0)
        {
        	retCode = 1;
        }
        else if(stricmp(AuxName1,AuxName2)<0)
        {
        	retCode = -1;
        }
        else
        {
        	retCode = 0;
        }

    return retCode;
}

void calculoDeDescuentos(void* this)
{
	float precio;
	float descuento;
	int idRubro;
	char nombreRubro[35];

	if(this != NULL)
	{
	articulo_getPrecio(this,&precio);
	articulo_getRubro(this,&idRubro,nombreRubro);

		if(precio >= 0 && nombreRubro != NULL)
		{
			if(idRubro == 1)
			{
				if(precio > 120)
				{
					descuento = 0.20;
					precio = precio - (precio*descuento);
					articulo_setPrecio(this,precio);
				}

			}else if(idRubro == 2)
			{
				if(precio > 200)
				{
					descuento = 0.10;
					precio = precio - (precio*descuento);
					articulo_setPrecio(this,precio);
				}
			}
		}
	}

}

int articulosPorMontoA(void* this)
{
	int retCode = 0;
	float auxPrecio1;
	int countMonto = 0;

	if(this != NULL)
	{
		 articulo_getPrecio(this,&auxPrecio1);

		if(auxPrecio1 > 100)
		{
			countMonto = 1;
			retCode = countMonto;
		}
	}
	return retCode;
}

int articulosPorRubroA(void* this)
{
	int retCode = 0;
	int auxRubroId;
	char auxNombreRubro[128];
	int countMonto = 0;

	if(this != NULL)
	{
		 articulo_getRubro(this,&auxRubroId,auxNombreRubro);

		if(auxRubroId == 1)
		{
			countMonto = 1;
			retCode = countMonto;
		}
	}
	return retCode;
}

/*
int ordenarPorPrecio(void* genericField1, void* genericfield2)
{
    int retCode = 0;
    int auxPrecio1;
    int auxprecio2;
    eArticulo* pAux1;
    eArticulo* pAux2;

    if(genericField1 !=NULL && genericfield2 !=NULL)
    {
        pAux1 = (eArticulo*)genericField1;
        pAux2 = (eArticulo*)genericfield2;

        articulo_getPrecio(pAux1,&auxPrecio1);
    	articulo_getPrecio(pAux2,&auxprecio2);

        if(auxPrecio1 > auxprecio2)
        {
        	retCode = 1;
        }
        else if(auxPrecio1 < auxprecio2)
        {
        	retCode = -1;
        }
        else
        {
        	retCode = 0;
        }
    }

    return retCode;
}*/
