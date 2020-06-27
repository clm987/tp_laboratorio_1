/*Contiene los prototipos de las funciones propias desarrolladas para la calculadora.
 *Autor: Carlos López.
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * \brief : recibe dos numeros float y devuelve la suma de ambos.
 * \param : a numero en formato float a ser sumado
 * \param : b numero en formato float a ser sumado
 * \return : el resultado de la suma.
 */
float sumar(float a , float b);

/**
 * \brief : recibe dos numeros float y devuelve la resta de ambos.
 * \param : a numero en formato float a ser restado
 * \param : b numero en formato float a ser restado
 * \return : el resultado de la resta.
 */
float restar(float a , float b);

/**
 * \brief : recibe dos numeros float y devuelve el producto de ambos.
 * \param : a numero en formato float a ser multiplicado
 * \param : b numero en formato float a ser multiplicado
 * \return : el resultado de la multiplicación.
 */
float multiplicar (float a , float b);

/**
 * \brief : recibe dos numeros float y devuelve la division de ambos
 * \param : a numero en formato float a ser dividido (dividendo)
 * \param : b numero en formato float por el cual se dividirá (divisor)
 * \return : el resultado de la division.
 */
float dividir(float a , float b);

/**
 * \brief : recibe un numero float y devuelve el factorial de dicho numero
 * \param : a numero en formato float cuyo factorial se calculará
 * \return : el factorial resultante.
 */
float calcularFactorial(float a);

/**
 * \brief : recibe datos en formato float y los muestra
 * \param : a numero en formato float resultado de la funcion sumar
 * \param : b numero en formato float resultado de la funcion restar
 * \param : c numero en formato float resultado de la funcion multiplicar
 * \param : d numero en formato float resultado de la funcion dividir
 * \param : e numero en formato float resultado de la funcion calcularFactorial parametro a
 * \param : f numero en formato float resultado de la funcion calcularFactorial parametro b
 * \param : g numero en formato float ingresado por el usuario para los calculos (1er operando)
 * \param : h numero en formato float ingresado por el usuario para los calculos (2do operando)
 * \return : esta funcion no retorna nada
 */
void mostrarResultados(float a, float b, float c, float d, float e, float f, float g, float h);

/**
 * \brief : recibe un puntero a float y valida que el dato contenido sea consistente con el declarado.
 * \param : *numero puntero a float a validar
 * \param : *mensaje puntero a char con el mensaje que se mostrará al usuario para iniciar
 * \param : *mensajeError puntero a char con el mensaje que se mostrará al usuario en caso de error
 * \param : reintentos entero de control que habilita la posibilidad de limitar los reintentos
 * \return : entero que informa si la validación resulto satisfactoria o no. Es 0 para validación OK.
 */
int getNumero(float* numero,	char* mensaje, char* mensajeError, int reintentos);

/**
 * \brief : recibe un puntero a char con un mensaje y lo muestra con el formato estadarizado.
 * \param : *mensajes puntero a char con el mensaje que se mostrará al usuario.
 * \return : esta funcion no retorna nada.
 */
void mostrarMensaje (char* mensajes);

/**
 * \brief : recibe un puntero a integer y valida que el dato contenido sea consistente con el declarado.
 * \param : *numero puntero a integer con el dato a validar
 * \param : *mensaje puntero a char con el mensaje que se mostrará al usuario para iniciar
 * \param : *mensajeError puntero a char con el mensaje que se mostrará al usuario en caso de error
 * \param : minimo entero que indica el limite inferir del rango de enteros aceptables
 * \param : maximo  entero que indica el limite superior del rango de enteros aceptables
 * \param : reintentos entero de control que habilita la posibilidad de limitar los reintentos
 * \return : entero que informa si la validación resulto satisfactoria o no. Es 0 para validación OK.
 */
int getOpcion(int* numero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


#endif /* CALCULOS_H_ */
