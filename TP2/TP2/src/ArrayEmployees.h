/*
 *NOMBRE:  ArrayEmployees.h
 *DESCRIPCION: BIBLIOTECA DE FUNCIONES PARA EL MANEJO DE LA ENTIDAD eEmployee
 *AUTOR: CARLOS LOPEZ
 */

#ifndef EEMPLOYEE_H_
#define EEMPLOYEE_H_

#define QTYEMPLOYEE 1000
#define EMPTY 0
#define NON_EMPTY 1

/**
 * \brief Estructura de datos eEmployee agrupa los datos del empleado
 */
typedef struct{
	char name[51];
	char lastName[64];
	float salary;
	int sector;
	int ideEmployee;
	int isEmpty;
}eEmployee;

/**
 * \brief : funcion para inicializar un array de eEmployee
 * \param eEmployeeArray : array de tipo eEmployee que será inicializado
 * \return : esta funcion no retorna nada.
 */
void initEmployees(eEmployee* eEmployeeArray,int arrayLength,int value);

/**
 * \brief : funcion para agregar o dar de alta un nuevo empleado.
 * \param eEmployeeArray : array de eEmployee en el que se cargaran los datos ingresados o generados.
 * \param arrayLenght: largo del array en el que se hará la carga de datos.
 * \return : devuelve un entero en caso que se necesite validar la ejecucion
 */
int addEmployees(eEmployee* eEmployeeArray, int arrayLength);

/**
 * \brief : funcion para buscar un elemento del array de eEmployee en funcion del campo id
 * \param eEmployeeArray : puntero a array de tipo eEmployee en el que se buscará el elemento
 * \param arrayLength : entero que define la longitud del array
 * \param id : entero que contiene el id unico del empleado a buscar
 * \return : devuelve un entero en caso que se necesite validar la ejecucion
 */
int findeEmployeeById(eEmployee* eEmployeeArray,int arrayLength, int id);

/**
 * \brief : Funcion para dar de baja un empleado
 * \param arraysEmployee:  puntero al array con la información de los empelados.
 * \param arraylength: entero que define la longitud del array
 * \return : devuelve un entero en caso que se necesite validar la ejecucion
 */
int removeEmployee(eEmployee* arrayeEmployee, int arraylength);

/**
 * \brief : Funcion que ordena el array de empleados por sector y apellido
 * \param arraysEmployee:  puntero al array con la información de los empelados.
 * \param arraylength: entero que define la longitud del array
 * \return : devuelve un entero en caso que se necesite validar la ejecucion
 */
int sortEmployees(eEmployee* arrayeEmployee,int arrayLength);

/**
 * \brief : Funcion que muestra la lista empleados del array de estructura en un formato predeterminado
 * \param eEmployeeArray : puntero a array de tipo eEmployee a mostrar por pantalla
 * \param fieldTitle1 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle2 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle3 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle4 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle5 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \return : devuelve un entero en caso que se necesite validar la ejecucion
 */
int printEmployees(eEmployee* arrayeEmployee, int arraylength, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4,char* fieldTitle5);

/**
 * \brief : funcion que busca en el array una posición disponible para cargar datos nuevos
 * \param eEmployeeArray : puntero al array a recorrer para buscar posiciones disponibles
 * \param arrayLength: entero que define la longitud del array recibido
 * \param value : valor del campo a evaluar. Esta definido por constantes: EMPTY 0 NON_EMPTY 1
 * \return :retorna un entero para evaluar ejecución.
 */

int findEmptyPlace(eEmployee* eEmployeeArray,int arrayLength, int value);

/**
 * \brief : funcion que genera el id único e incremental de la estructura eEmployee
 * \(): esta función no recibe parametros.
 * \return :retorna un entero que será utilizado para asignar como id.
 */
int generateIdeEmployee();
/**
 * \brief : Funcion que muestra un elemento del array de estructura en un formato predeterminado
 * \param eEmployeeArray : puntero a array de tipo eEmployee a mostrar por pantalla
 * \param fieldTitle1 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle2 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle3 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle4 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \param fieldTitle5 : puntero a char con el mensaje que se mostrará al usuario como titulo de campo
 * \return : esta funcion no retorna nada.
 */
void showeEmployee(eEmployee* eEmployeeArray, int index, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4,char* fieldTitle5);

/**
 * \brief : funcion que permite modificar los datos de un empleado.
 * \param eEmployeeArray :puntero al array a recorrer para ubicar el empleado que se modificará
 * \param arrayLength: entero que define la longitud del array recibido
 * \return : retorna un entero para evaluar ejecución.
 */
int modifyeEmployee(eEmployee* eEmployeeArray, int arraylength);

/**
 * \brief : funcion que ejecuta la baja logica de un empleado asignando el valor EMPTY al campo isEmpty de la estructura
 * \param eEmployeeArray :puntero al array a recorrer para ubicar el empleado
 * \param rrayLength: entero que define la longitud del array recibido
 * \param id: entero que representa el id del empleado a dar de baja
 * \return : retorna un entero para evaluar ejecución.
 */
int deleteeEmployeeById(eEmployee* eEmployeeArray,int arrayLength, int id);
/**
 * \brief : recibe un puntero a char con un mensaje de confirmación que será mostrado al usuario por pantalla
 * \param :recibe un puntero a char con el mensaje a mostrar al usuario
 * \return : retorna un char con la respuesta que introduce el usuario por teclado
 */
char getConfirmationeEmployee(char* message);

/**
 * \brief : valida si el array de tipo eEmployee se encuentra vacío
 * \param eEmployeeArray :puntero al array en el que se validará la existencia de al menos un elemento con el campo isEmpty cargado como NON_EMPTY
 * \param arrayLength: entero que define la longitud del array recibido
  * \return :  retorna un entero para evaluar ejecución.
 */
int checkIfEmptyeEmployee(eEmployee* eEmployeeArray,int arrayLength);

/**
 * \brief : calcula la suma de todos los salarios en las posiciones NON_EMPTY del array
 * \param eEmployeeArray :puntero al array a recorrer para ubicar el empleado
 * \param rrayLength: entero que define la longitud del array recibido
 * \return : retorna un float con el resultado de la suma de salarios
 */
float sumSalaries(eEmployee* eEmployeeArray,int arraylength);

/**
 * \brief : cuenta la cantidad de empleados activos o con la posicion isEmpty en NON_EMPTY
 * \param eEmployeeArray :puntero al array a recorrer para ubicar el empleado
 * \param rrayLength: entero que define la longitud del array recibido
 * \return : retorna un entero con el resultado del conteo
 */
int countEmployees(eEmployee* eEmployeeArray,int arraylength);

/**
 * \brief :determina la cantidad de empleados con salario por encima del promedio
 * \param eEmployeeArray :puntero al array a recorrer para ubicar el empleado
 * \param rrayLength: entero que define la longitud del array recibido
 * \return : retorna un entero con el resultado del conteo
 */
int salaryStatistics(eEmployee* eEmployeeArray,int arraylength, float average);


#endif /* EEMPLOYEE_H_ */
