/*
 *Contiene el desarrollo de  las funciones propias creadas para la calculadora.
 *Autor: Carlos López.
 */


#include <stdio.h>
#include <stdlib.h>

float sumar(float a , float b)
{
	float retorno;
	retorno = a + b;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////
float restar(float a , float b)
{
	float retorno;
	retorno = a - b;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////
float multiplicar (float a , float b)
{
	float retorno;
	retorno = a * b;
	return retorno;
}

///////////////////////////////////////////////////////////////////////////////////////
float dividir(float a , float b)
{
	float retorno;
	if (b == 0)
	{
		retorno = -1;
	}
	else if(a == 0)
	{
		retorno = 0;
	}
	else
	{
		retorno = a / b;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////
float calcularFactorial(float a)
{
	int i = 1;
	float factorial = 1;

	if(a > 0)
	{
		for(i = 1 ; i <= a ; i++ )
		{
			factorial = factorial * i;
		}
	}else if(a < 0)
	{
		factorial = -1;
	}
	return factorial;
}
//////////////////////////////////////////////////////////////////////////////////////////

void mostrarResultados(float a, float b, float c, float d, float e, float f, float g, float h)
{	system("CLS");
	printf("                                                                 \n");
	printf("*---------------------------------------------------------------*\n");
	printf("\t a)El resultado de %.2f + %.2f es: %.2f \n" , g, h, a);
	printf("\t b)El resultado de %.2f - %.2f es: %.2f \n" , g, h,  b);
	printf("\t c)El resultado de %.2f / %.2f es: %.2f \n" , g, h,  c);
	printf("\t d)El resultado de %.2f * %.2f es: %.2f \n" , g, h,  d);

	if (e < 1000000)
		{
			printf("\t e)El resultado de %.2f(!) es: %.2f\n" , g, e);
		}
	else
		{
			printf("\t e)El resultado de %.2f(!) es: %E\n" , g, e);
		}
	if (f < 1000000)
		{
			printf("\t   El resultado de %.2f(!) es: %.2f\n" , h, f);
			printf("                                    \n");
		}
	else
		{
			printf("\t   El resultado de %.2f(!) es: %E\n" , h, f);
			printf("                                    \n");
		}
	printf("*---------------------------------------------------------------*\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////
int getNumero(float* numero, char* mensaje, char* mensajeError, int reintentos)
{
	 int ret;
	 float num;
	 while(reintentos>=0)
	 {
	   printf("%s",mensaje);
	   fflush(stdin);
		   if(scanf("%f",&num)==1)
		   {
			  break;
		   }
	   reintentos--;
	   printf("%s",mensajeError);
	   fflush(stdin);
	 }
	if(reintentos==0)
		{
		 ret=-1;
		}
	else
		{
		 ret=0;
		 *numero = num;
		}
	return ret;
}

///////////////////////////////////////////////////////////////////////////////////////
void mostrarMensaje (char* mensajes)
{
	printf("*                                                               *\n");
	printf("*---------------------------------------------------------------*\n");
	printf(" %s\n", mensajes);
	printf("*---------------------------------------------------------------*\n");
	printf("*                                                               *\n");
}

//////////////////////////////////////////////////////////////////////////////////////
int getOpcion(int* numero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	 int ret;
	 float num;
	 while(reintentos>=0)
	 {
	   printf("%s",mensaje);
	   fflush(stdin);
		   if(scanf("%f",&num)==1)
		   {
			   if(num<=maximo && num>=minimo)
			   	  {
				   break;
			   	  }
		   }
	   reintentos--;
	   printf("%s",mensajeError);
	   fflush(stdin);
	 }
	if(reintentos==0)
		{
		 ret=-1;
		}
	else
		{
		 ret=0;
		 *numero = num;
		}
	return ret;
}
