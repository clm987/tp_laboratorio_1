/*
 *NOMBRE: reports.h
 *DESCRIPCION: BIBLIOTECA DE FUNCIONES PARA EL MANEJO DE REPORTES
 *AUTOR: CARLOS LOPEZ
 */

#ifndef REPORTS_H_
#define REPORTS_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "IOdata.h"


/**
 * \brief : centraliza las opciones de ordenar el array y mostrarlo ordenado en un solo reporte valiendose de las funciones especificas
 * \param eEmployeeArray :puntero al array de empleados
 * \param rrayLength: entero que define la longitud del array recibido
 * \return : retorna un entero en caso que se necesite controlar ejecución
 */
int sortAndShoweEmployee(eEmployee* eEmployeeArray, int arraylength);

/**
 * \brief : Funcion que muestra los indicadores estadisticos de salarios por pantalla
 * \param eEmployeeArray : puntero a array de tipo eEmployee a mostrar por pantalla
 * \param fieldTitle1 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle2 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle3 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param indicator1: float con el indicador estadistico a mostrar. En este caso se usa para la suma total de salarios
 * \param indicator2: float con el indicador estadistico a mostrar. En este caso se usa para el promedio de salarios
 * \param indicator3: entero con el indicador estadistico a mostrar. En este caso recibe la cuenta de empleados por encima del salario promedio
 * \return : esta funcion no retorna nada.
 */
void showStatistics(char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,float indicator1,float indicator2,int indicator3);

/**
 * \brief : centraliza las opciones de estadisticas salariales en un solo reporte valiendose de las funciones especificas
 * \param eEmployeeArray :puntero al array de empleados
 * \param rrayLength: entero que define la longitud del array recibido
 * \return : retorna un entero en caso que se necesite controlar ejecución
 */
int showSalariesAndStatistics(eEmployee* arrayeEmployee, int arraylength);

/**
 * \brief : Muestra y habilita el menu de reportes sobre empleados.
 * \param eEmployeeArray :puntero al array de empleados
 * \param rrayLength: entero que define la longitud del array recibido
 * \return : esta funcion no retorna nada.
 */
void reportsOption(eEmployee* arrayeEmployee, int arraylength);



#endif /* REPORTS_H_ */
