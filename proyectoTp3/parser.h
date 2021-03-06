/*
 * parser.h
 *
 *  Created on: 10 Jun 2020
 *      Author: Carlos
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* contiene la ruta del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* contiene la ruta del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
