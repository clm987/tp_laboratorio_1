

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* que define la ruta o nombre del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* que define la ruta o nombre del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados. Permite al usuario crear un empleado nuevo
 *
 * \param path char* que define la ruta o nombre del archivo*
 * \param pArrayListEmployee LinkedList*
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado. Permite la edicion de los datos del empleado
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado, elimina un empleado de la lista.
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Muestra lotes de 100 empleados por vez, requiere presionar una tecla para continuar mostrando
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados de manera ascendente y descendente por nombre
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* que define la ruta o nombre del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* que define la ruta o nombre del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int para control de ejecucion 0 para OK
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


