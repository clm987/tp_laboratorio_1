/*
 * controller.h
 *
 *  Created on: 20 Jun 2020
 *      Author: Carlos
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"


int controller_loadFromText(char* path , LinkedList* pArrayListArticulos);
int controller_printArticulos(LinkedList* this);
int controller_saveAsText(char* path , LinkedList* pArrayListArticulos);
int controller_MappList(LinkedList* pArrayListArticulos);
int controller_SortList(LinkedList* pArrayListArticulos);
int controller_CountArticulo(LinkedList* pArrayListArticulos);
int controller_CountRubro(LinkedList* pArrayListArticulos);
int controller_informes(LinkedList* pArrayListArticulos);



#endif /* CONTROLLER_H_ */
