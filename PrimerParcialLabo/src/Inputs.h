#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef INPUTS_H_
#define INPUTS_H_
char Utn_PedirCaracter(char mensaje[],char mensajeError[],char minimo,char maximo);
int Utn_PedirAlfaNumerico(char cadena[],char mensaje[],char mensajeError[],int reintentos);
int GetAlphaNum(char cadena[]);
int EsAlfaNumerico(char cadena[]);
/// @brief Verifica si una cadena esta compuesta solo por caracteres numericos
///
/// @param cadena que se va a verificar
/// @return 1 si es solo numeros y 0 en caso contrario
int EsNumerica(char cadena[]);
/// @brief Pide al usuario ingresar un numero entero y se lo devuelve
/// @param pNumeroIngresado puntero a entero que guarda el numero ingresado
/// @param texto Le muestra un mensaje al usuario pidiendole un numero entero
/// @param textoError Mensaje para avisar que algo salio mal
/// @param minimo numero entero minimo que puede ingresar el usuario
/// @param maximo numero entero maximo que puede ingresar el usuario
/// @param reintentos cantidad de veces que el usuario puede equivocarse al ingresar un numero
/// @return devuelve 0 en caso de error, y 1 en caso de que haya podido guardar un numero entero
int Utn_PedirEntero(int* pNumeroIngresado,char texto[],char textoError[],int minimo,int maximo,int reintentos);
/// @brief obtiene un numero entero
/// @param pNumeroEntero puntero a entero donde se guarda el entero si lo obtuvo
/// @return 1 si pudo obtener un entero, 0 si no pudo
int GetInt(int* pNumeroEntero);
/// @brief Verifica si una cadena esta compuesta solo por caracteres de un flotante
/// @param cadena que se va a verificar
/// @return 1 si es un flotante y 0 si no lo es
int EsFlotante(char cadena[]);
/// @brief Pide al usuario ingresar un numero entero y se lo devuelve
/// @param pNumeroIngresado puntero a flotante que guarda el numero ingresado
/// @param texto Le muestra un mensaje al usuario pidiendole un numero flotante
/// @param textoError Mensaje para avisar que algo salio mal
/// @param minimo numero flotante minimo que puede ingresar el usuario
/// @param maximo numero flotante maximo que puede ingresar el usuario
/// @param reintentos cantidad de veces que el usuario puede equivocarse al ingresar un numero
/// @return devuelve 0 en caso de error, y 1 en caso de que haya podido guardar un numero flotante
int Utn_PedirFlotante(float* pNumeroIngresado,char texto[],char textoError[],float minimo,float maximo,int reintentos);
/// @brief obtiene un numero flotante
/// @param pNumeroFlotante puntero a flotante donde se guarda el flotante si lo obtuvo
/// @return 1 si pudo obtener un flotante, 0 si no pudo
int GetFloat(float* pNumeroFlotante);
/// @brief obtiene una cadena de texto
/// @param cadena array de char donde se va a guardar la cadena en caso de obtenerla
/// @return 1 si pudo obtener la cadena y 0 si no
int GetString(char cadena[]);
/// @brief verificar si la cadena esta compuesta solo por caracteres de letras
/// @param cadena que se va a verificar
/// @return 1 si la cadena esta compuesta solo por letras y 0 si no
int EsSoloLetras(char cadena[]);
/// @brief Pide al usuario ingresar una cadena de texto y lo guarda
/// @param cadena donde se va a guardar la cadena de texto ingresada
/// @param mensaje Le muestra un mensaje al usuario pidiendole una cadena
/// @param mensajeError Mensaje para avisar que algo salio mal
/// @param reintentos cantidad de veces que el usuario puede equivocarse al ingresar un numero
/// @return devuelve 0 en caso de error, y 1 en caso de que haya podido guardar una cadena de texto
int Utn_PedirCadena(char cadena[],char mensaje[],char mensajeError[],int reintentos);

/// @brief Pide al usuario ingresar un caracter
/// @param texto Le muestra un mensaje al usuario pidiendole un caracter
/// @param textoError Mensaje para avisar que algo salio mal
/// @return devuelve el caracter ingresado
char GetRespuesta(char texto[],char textoError[]);



#endif /* INPUTS_H_ */
