#include "Inputs.h"

char Utn_PedirCaracter(char mensaje[],char mensajeError[],char minimo,char maximo)
{
	char caracterIngresado;
	printf("%s",mensaje);
	scanf("%c",&caracterIngresado);
	while(caracterIngresado<minimo || caracterIngresado>maximo)
	{
		printf("%s",mensajeError);
		scanf("%c",&caracterIngresado);
	}
	return caracterIngresado;
}
int Utn_PedirAlfaNumerico(char cadena[],char mensaje[],char mensajeError[],int reintentos)
{
	int retorno;
	char buffer[500];
	retorno=0;
	if(mensaje!=NULL && cadena!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(GetAlphaNum(buffer))
			{
				strcpy(cadena,buffer);
				retorno=1;
				break;
			}
			printf("%s\n",mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;

}
int GetAlphaNum(char cadena[])
{
	int retorno;
	char auxiliar[500];
	retorno=0;

	if(cadena!=NULL)
	{
		fflush(stdin);
		scanf("%[^\n]",auxiliar);
		if(EsAlfaNumerico(auxiliar))
		{
			strcpy(cadena,auxiliar);
			retorno=1;
		}
	}

	return retorno;
}
int EsAlfaNumerico(char cadena[])
{
	int i;
	int retorno;
	int longitud;
	longitud=strlen(cadena);
	retorno=1;

	if(cadena!=NULL)
	{
		for(i=0;i<longitud && cadena[i]!='\n';i++)
		{
			if(!isalnum(cadena[i]))
			{
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

int Utn_PedirCadena(char cadena[],char mensaje[],char mensajeError[],int reintentos)
{
	int retorno;
	char buffer[500];
	retorno=0;
	if(mensaje!=NULL && cadena!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(GetString(buffer))
			{
				strcpy(cadena,buffer);
				retorno=1;
				break;
			}
			printf("%s\n",mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;

}
int GetString(char cadena[])
{
	int retorno;
	char auxiliar[500];
	retorno=0;

	if(cadena!=NULL)
	{
		fflush(stdin);
		scanf("%[^\n]",auxiliar);
		if(EsSoloLetras(auxiliar))
		{
			strcpy(cadena,auxiliar);
			retorno=1;
		}
	}

	return retorno;
}
int EsSoloLetras(char cadena[])
{
	int i;
	int retorno;
	int longitud;
	longitud=strlen(cadena);
	retorno=1;

	if(cadena!=NULL)
	{
		for(i=0;i<longitud && cadena[i]!='\n';i++)
		{
			if(cadena[i]!=' ' && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
			{
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}
int Utn_PedirFlotante(float* pNumeroIngresado,char texto[],char textoError[],float minimo,float maximo,int reintentos)
{
	float flotanteIngresado;
	int retorno;
	retorno=0;
	if(pNumeroIngresado!=NULL && texto!=NULL && textoError!=NULL && minimo<maximo && maximo>minimo && reintentos>=0)
	{
		do
		{
			printf("%s",texto);
			if(GetFloat(&flotanteIngresado) && flotanteIngresado>=minimo && flotanteIngresado<=maximo)
			{
				*pNumeroIngresado=flotanteIngresado;
				retorno=1;
				break;
			}
			printf("%s\n",textoError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int GetFloat(float* pNumeroFlotante)
{
	int retorno;
	char auxiliar[500];
	retorno=0;

	if(pNumeroFlotante!=NULL)
	{
		fflush(stdin);
		scanf("%[^\n]",auxiliar);
		if(EsFlotante(auxiliar))
		{
			*pNumeroFlotante=atof(auxiliar);
			retorno=1;
		}
	}


	return retorno;
}

int EsFlotante(char cadena[])
{
	int retorno;
	int i;
	int longitud;
	int contadorPuntos;
	contadorPuntos=0;
	retorno=1;
	longitud=strlen(cadena);
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;i<longitud && cadena[i]!='\0';i++)
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				if(cadena[i]=='.' && contadorPuntos==0)
				{
					contadorPuntos++;
				}else
				{
					retorno=0;
					break;
				}
			}


		}
	}

	return retorno;
}
int GetInt(int* pNumeroEntero)
{
	int retorno;
	char auxiliar[500];
	retorno=0;

	if(pNumeroEntero!=NULL)
	{
		fflush(stdin);
		scanf("%[^\n]",auxiliar);
		if(EsNumerica(auxiliar))
		{
			*pNumeroEntero=atoi(auxiliar);
			retorno=1;
		}
	}


	return retorno;
}
int EsNumerica(char cadena[])
{
	int retorno;
	int longitud;
	int i;
	retorno=1;
	longitud=strlen(cadena);
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;i<longitud && cadena[i]!='\0';i++)
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int Utn_PedirEntero(int* pNumeroIngresado,char texto[],char textoError[],int minimo,int maximo,int reintentos)
{
	int enteroIngresado;
	int retorno;
	retorno=0;
	if(pNumeroIngresado!=NULL && texto!=NULL && textoError!=NULL && minimo<maximo && maximo>minimo && reintentos>=0)
	{
		do
		{
			printf("%s",texto);
			if(GetInt(&enteroIngresado) && enteroIngresado>=minimo && enteroIngresado<=maximo)
			{
				*pNumeroIngresado=enteroIngresado;
				retorno=1;
				break;
			}
			printf("%s\n",textoError);
			reintentos--;
		}while(reintentos>=0);
	}


	return retorno;
}
char GetRespuesta(char texto[],char textoError[])
{
	char caracterIngresado;

	printf("%s",texto);
	fflush(stdin);
	scanf("%c",&caracterIngresado);
	while(isalpha(caracterIngresado)==0 ||(caracterIngresado!='s' && caracterIngresado!='n'))
	{
		printf("%s",textoError);
		fflush(stdin);
		scanf("%c",&caracterIngresado);
	}


	return caracterIngresado;
}
