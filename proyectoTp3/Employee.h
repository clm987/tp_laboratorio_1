#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define LENGTH 128
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva espacio en memoria para un empleado
 * Esta funcion no recibe parametros.
 * \return devuelve una estructura del tipo empleado inicializada en valores minimos
 *
 */
Employee* employee_new();

/** \brief Reserva y carga datos a una estructura a empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return devuelve una estructura del tipo empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Libera el espacio de una estructura empleado.
 * \param this Employee* recibe un empleado.
 * \return void no devuelve nada
 *
 */
void employee_delete(Employee* this);

/** \brief setea o carga el id en una estructura de tipo empleado
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int employee_setId(Employee* this,int id);

/** \brief setea o carga el id en una estructura de tipo empleado en modo texto
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int employee_setIdTxt(Employee* this,char* id);


/** \brief setea o carga el nombre en una estructura de tipo empleado
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief setea o carga la cantidad de horas trabajadas en una estructura de tipo empleado
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief setea o carga el sueldo en una estructura de tipo empleado
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el ID de una estructura de tipo empleado
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Obtiene el nombre de una estructura de tipo empleado
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Obtiene la cantidad de horas trabajadas de una estructura de tipo empleado
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Obtiene el sueldo de una estructura de tipo empleado
 *
 * \param Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Habilita la carga de un nuevo empleado a la lista de empleados
 * \param Employee* this recibe una estructura de tipo empleado
 * \param pArrayListEmployee LinkedList*
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int EmployeeAdd(Employee* this, LinkedList* pArrayListEmployee);

/** \brief Agrupa los getters de la estructura empleado
 *\param: puntero a int para el id de empleado
 *\param: puntero a char para el nombre de empleado
 *\param: puntero a int para las horas trabajadas
 *\param: puntero a int para el sueldo de empleado
 *\param: Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 */
int getEmployee(int* id, char* nombre, int* horasTrabajadas, int* sueldo, Employee* this);

/** \brief Imprime un elemento de tipo Employee
 *\param: Employee* this recibe una estructura de tipo empleado
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int printEmployee(Employee* this);

/** \brief Permite la busqueda de un elemento por su id en la lista de empleados
 * \param: Employee* this recibe una estructura de tipo empleado
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna el indice de dicho elemento
 *
 */
int searchId(int id, LinkedList* pArrayListEmployee);

/** \brief Genera de manera incremental el ID de un empleado
 * \param pArrayListEmployee LinkedList*
 * \return int id retorna el iD a asignar al nuevo empleado
 *
 */
int generateIdeEmployee(LinkedList* pArrayListEmployee);

/** \brief lista los empleados cargados en lotes de 100
 * param int length la longitud de la lista
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int listEmployees(LinkedList* pArrayListEmployee, int length);

/** \brief Permite comparar dos nombres de dos estructuras del mismo tipo
 * \param void genericField1 puntero de tipo void para cargar la estructura
 * \param void genericField2 puntero de tipo void para cargar la estructura
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int sortByName(void* genericField1, void* genericfield2);

/** \brief Habilita un menu de opciones para sortear la lista de empleados por nombre
 * \param int length la longitud de la lista
 * \param pArrayListEmployee LinkedList*
 * \return int entero para control de ejecucion 0 para OK
 *
 */
int sortEmployees(LinkedList* pArrayListEmployee, int len);


#endif // employee_H_INCLUDED
