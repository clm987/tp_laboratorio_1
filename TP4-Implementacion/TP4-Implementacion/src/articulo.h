/*
 * articulo.h
 *
 *  Created on: 24 Jun 2020
 *      Author: Carlos
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_

typedef struct{
	int id_rubro;
	char nombre_rubro[30];
}eRubro;

typedef struct{
	int Id_Articulo;
	char articulo[128];
	char medida[128];
	float precio;
	eRubro rubro;
}eArticulo;

eArticulo* articulo_new();
eRubro* eRubro_new();
void articulo_delete(eArticulo* this);
void rubro_delete(eRubro* this);
eArticulo* articulo_newParametros(char* idStr, char* articulo, char* medida, char* precio, char* rubro);

int articulo_setId(eArticulo* this,char* id);
int articulo_setNombreArticulo(eArticulo* this,char* nArticulo);
int articulo_setMedida(eArticulo* this,char* medida);
int articulo_setPrecio(eArticulo* this, float precio);
int eRubro_setId(eRubro* this,char* rubro);
int articulo_setRubros(eArticulo* this, char* rubro);


int articulo_getId(eArticulo* this,int* id);
int articulo_getArticuloNombre(eArticulo* this,char* articuloNombre);
int articulo_getMedida(eArticulo* this,char* medida);
int  articulo_getPrecio(eArticulo* this,float* precio);
int  articulo_getRubro(eArticulo* this,int* idRubro, char* nombreRubro);
int getArticulos(int* id, char* bufferMedida,char* bufferArticulo, float* bufferPrecio, char* rubroNombre, int* idRubro, eArticulo* this);

int ordenarPorArticulo(void* genericField1, void* genericfield2);

int articulosPorMontoA(void* this);
int articulosPorRubroA(void* this);
//int ordenarPorPrecio(void* genericField1, void* genericfield2);

void calculoDeDescuentos(void* this);


#endif /* ARTICULO_H_ */
