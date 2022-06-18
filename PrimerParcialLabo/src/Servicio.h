#include <stdio.h>
#include "Inputs.h"


#define TAM_SERVICIOS 20
#define TAM_MECANICOS 5
#define TAM_DIAGNOSTICOS 6

//ESTADOS DE SERVICIO
#define LIBRE 0
#define NO_DIAGNOSTICADO 1
#define DIAGNOSTICADO 3

typedef struct
{
	int id;
	int contador;
	float porcentaje;
}eAuxiliar;
typedef struct
{
	int idDiagnostico;//PK
	char descripcion[51];
}eDiagnostico;
typedef struct
{
	int idMecanico;//PK
	char nombreDeMecanico[51];
	char especialidadDeMecanico[51];
}eMecanico;
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;
typedef struct
{
	int idServicio;//PK
	char nombreDeCliente[51];
	eFecha fechaDeServicio;
	int diagnostico;//FK
	float cotizacion;
	int idMecanico;//FK
	int isEmpty;
}eServicio;


/// @brief muestra un solo diagnostico
///
/// @param unDiagnostico
void diagnostico_MostrarUno(eDiagnostico unDiagnostico);
/// @brief muestra todos los diagnosticos
///
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
void diagnostico_MostrarTodos(eDiagnostico listaDeDiagnosticos[],int tamDiagnostico);
/// @brief hace una carga forzada de diagnosticos
///
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
void diagnostico_HardcodearDatos(eDiagnostico listaDeDiagnosticos[],int tamDiagnostico);
/// @brief busca un diagostico por su id
///
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
/// @param idDiagnosticoBuscado
/// @return -1 si no lo encontro, o el indice del diagnostico encontrado
int diagnostico_BuscarPorId(eDiagnostico listaDeDiagnosticos[],int tamDiagnostico,int idDiagnosticoBuscado);

/// @brief compara 2 fechas
///
/// @param unaFecha
/// @param otraFecha
/// @return -1 si sos distintas, 0 si son iguales
int CompararFecha(eFecha unaFecha,eFecha otraFecha);
/// @brief compara el orden de las fechas
///
/// @param primerFecha
/// @param segundaFecha
/// @return 0 si las 2 fechas son iguales
/// 		-1 si la primer fecha es menor que la segunda
/// 		1 si la primer fecha es mayor que la segunda
int InformarOrdenDeFecha(int primerFecha,int segundaFecha);
/// @brief pide al usuario que ingrese una fecha
///
/// @return la fecha ingresada
eFecha fecha_IngresarPorTeclado();

/// @brief busca un mecanico por su id
///
/// @param listaDeMecanicos
/// @param tamMecanicos
/// @param idABuscar
/// @return -1 si no lo encontro, o el indice del mecanico
int mecanico_BuscarPorId(eMecanico listaDeMecanicos[],int tamMecanicos,int idABuscar);
/// @brief muestra la lista de mecanicos
///
/// @param listaDeMecanicos
/// @param tamMecanicos
void mecanico_MostrarTodos(eMecanico listaDeMecanicos[],int tamMecanicos);
/// @brief muestra un mecanico
///
/// @param unMecanico
void mecanico_MostrarUno(eMecanico unMecanico);
/// @brief hace la carga forzada de algunos mecanicos
///
/// @param listaDeMecanicos
/// @param tamMecanicos
void mecanico_HardcodearDatos(eMecanico listaDeMecanicos[],int tamMecanicos);

/// @brief muestra los desperfectos mas diagnosticados
///
/// @param listaDeServicios
/// @param tamServicio
/// @param listaDeMecanicos
/// @param tamMecanico
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
/// @param lista
void ListarDesperfectosMasDiagnosticados(eServicio listaDeServicios[],int tamServicio,eMecanico listaDeMecanicos[],int tamMecanico,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico,eAuxiliar lista[]);
/// @brief calcula el porcentaje de servicios por mecanico
///
/// @param listaDeServicios
/// @param tamServicio
/// @param listaDeMecanicos
/// @param tamMecanico
/// @param lista
void CalcularPorcentajeDeServiciosPorMecanico(eServicio listaDeServicios[],int tamServicio,eMecanico listaDeMecanicos[],int tamMecanico,eAuxiliar lista[]);
/// @brief inicializa la lista auxiliar en paralelo con la de diagnosticos
///
/// @param lista
/// @param tam
/// @param listaDeDiagnosticos
void InicializarArrayAuxiliarDiagnostico(eAuxiliar lista[],int tam,eDiagnostico listaDeDiagnosticos[]);
/// @brief lista los servicios en un rango de tiempo determinado
///
/// @param mesInicial
/// @param mesFinal
/// @param anio
/// @param listaDeServicios
/// @param tamServicio
/// @param listaDeMecanicos
/// @param tamMecanico
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
void ListarServiciosPorLapsoDeTiempo(int mesInicial,int mesFinal,int anio,eServicio listaDeServicios[],int tamServicio,eMecanico listaDeMecanicos[],int tamMecanico,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico);
/// @brief ordena los servicios por la especialidad de mecanico
///
/// @param listaDeServicios
/// @param tamServicio
/// @param listaDeMecanicos
/// @param tamMecanico
void OrdenarServiciosPorEspecialidadDeMecanico(eServicio listaDeServicios[],int tamServicio,eMecanico listaDeMecanicos[],int tamMecanico);
/// @brief muestra los mecanicos que diagnosticaron mas servicios
///
/// @param lista
/// @param tam
/// @param maximo
/// @param listaDeMecanicos
void MostrarMecanicosConMasServicios(eAuxiliar lista[],int tam,int maximo,eMecanico listaDeMecanicos[]);
/// @brief inicializa la lista auxiliar
///
/// @param lista
/// @param tam
/// @param listaDeMecanicos
void inicializarAuxiliar(eAuxiliar lista[],int tam,eMecanico listaDeMecanicos[]);
/// @brief busca el o los mecanicos con mas servicios diagnosticados
///
/// @param lista
/// @param listaDeMecanicos
/// @param tamMecanicos
/// @param listaDeServicios
/// @param tamServicios
void CalcularMecanicoConMasDiagnosticos(eAuxiliar lista[],eMecanico listaDeMecanicos[],int tamMecanicos,eServicio listaDeServicios[],int tamServicios);
/// @brief calcula el promedio de cotizaciones por mecanico
///
/// @param listaDeMecanicos
/// @param tamMecanicos
/// @param listaDeServicios
/// @param tamServicios
void CalcularPromedioPorMecanico(eMecanico listaDeMecanicos[],int tamMecanicos,eServicio listaDeServicios[],int tamServicios);
/// @brief acumula las cotizaciones de una fecha y diagnostico determinado
///
/// @param listaDeServicios
/// @param tamServicios
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
/// @param idDiagnostico
/// @return cotizaciones acumuladas
float BuscarCotizacionesPorFechaYDiagnostico(eServicio listaDeServicios[],int tamServicios,eDiagnostico listaDeDiagnosticos[], int tamDiagnostico,int idDiagnostico);
/// @brief acumula cotizaciones por diagnostico
///
/// @param unServicio
/// @param tamServicios
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
/// @param idDiagnostico
/// @return cotizaciones por diagnostico
float SumarCotizacionesPorDiagnostico(eServicio unServicio,int tamServicios,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico,int idDiagnostico);
/// @brief muestra los mecanicos que no diagnosticaron ningun servicio
///
/// @param listaDeServicios
/// @param tamServicios
/// @param listaDeMecanicos
/// @param tamMecanicos
void ListarMecanicosSinServicios(eServicio listaDeServicios[],int tamServicios,eMecanico listaDeMecanicos[],int tamMecanicos);
/// @brief lista los servicios completos
///
/// @param listaDeServicios
/// @param tamServicios
/// @param listaDeMecanicos
/// @param tamMecanicos
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
void servicio_ListarDiagnosticadosConSuMecanico(eServicio listaDeServicios[],int tamServicios,eMecanico listaDeMecanicos[],int tamMecanicos,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico);
/// @brief muestra un servicio completo
///
/// @param unServicio
/// @param unMecanico
/// @param unDiagnostico
void servicio_ListarUnoDiagnosticadoConSuMecanico(eServicio unServicio,eMecanico unMecanico,eDiagnostico unDiagnostico);
/// @brief diagnostica un servicio
///
/// @param listaDeServicios
/// @param tamServicios
/// @param listaDeMecanicos
/// @param tamMecanicos
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
/// @return (-2)si no encontro el diagnostico, (-1) si no encontro el mecanico, (0) si no encontro el servicio, y (1) si diagnostico con exito
int Diagnosticar(eServicio listaDeServicios[],int tamServicios,eMecanico listaDeMecanicos[],int tamMecanicos,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico);
/// @brief modifica un servicio
///
/// @param listaDeServicios
/// @param tamServicios
/// @param listaDeMecanicos
/// @param tamMecanicos
/// @param listaDeDiagnosticos
/// @param tamDiagnostico
/// @return -1 si no encontro el id de servicio, 0 si cancelo la modificacion, 1 si modifico con exito
int servicio_Modificar(eServicio listaDeServicios[],int tamServicios,eMecanico listaDeMecanicos[],int tamMecanicos,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico);

/// @brief cuenta los servicios por diagnostico
///
/// @param listaDeServicios
/// @param tamServicio
/// @param idDiagnostico
/// @return contador
int ContarServiciosPorDiagnostico(eServicio listaDeServicios[],int tamServicio,int idDiagnostico);
/// @brief suma los precios de los servicios por mecanico
///
/// @param listaDeServicios
/// @param tamServicios
/// @param idMecanico
/// @return precios acumulados
float AcumularCotizacionPorMecanico(eServicio listaDeServicios[],int tamServicios,int idMecanico);
/// @brief cuenta los servicios por mecanico
///
/// @param listaDeServicios
/// @param tamServicios
/// @param idMecanico
/// @return contador
int ContarServiciosPorMecanico(eServicio listaDeServicios[],int tamServicios,int idMecanico);
/// @brief hace la carga forzada de servicios
///
/// @param listaDeServicios
/// @param tamServicios
/// @param limite
void servicio_HardcodearDatos2(eServicio listaDeServicios[],int tamServicios,int limite);
/// @brief ordena los servicios por fecha
///
/// @param listaDeServicios
/// @param tamServicios
void OrdenarServiciosPorFecha(eServicio listaDeServicios[],int tamServicios);
/// @brief muestra los servicios diagnosticados
///
/// @param listaDeServicios
/// @param tamServicios
void servicio_ListarTodosDiagnosticados(eServicio listaDeServicios[],int tamServicios);
/// @brief muestra un servicio diagnosticado
///
/// @param unServicio
void servicio_ListarUnoDiagnosticado(eServicio unServicio);
/// @brief muestra un servicio sin diagnosticar
///
/// @param unServicio
void servicio_MostrarUnoSinDiagnosticar(eServicio unServicio);
/// @brief muestra los servicios sin diagnosticar
///
/// @param listaDeServicios
/// @param tamServicios
void servicio_MostrarTodosSinDiagnosticar(eServicio listaDeServicios[],int tamServicios);
/// @brief hardcodea servicios sin diagnosticar
///
/// @param listaDeServicios
/// @param tamServicios
void servicio_HardcodearDatos(eServicio listaDeServicios[],int tamServicios);
/// @brief cancela de forma logica un servicio
///
/// @param listaDeServicios
/// @param tamServicios
/// @return -1 si no encontro el id de servicio, 0 si se arrepintio de cancelar, 1 si cancelo con exito
int servicio_CancelarServicio(eServicio listaDeServicios[],int tamServicios);
/// @brief busca un servicio por su id
///
/// @param listaDeServicios
/// @param tamServicios
/// @param idBuscado
/// @return -1 si no lo encontro o el indice del servicio
int servicio_BuscarPorId(eServicio listaDeServicios[],int tamServicios,int idBuscado);
/// @brief busca un servicio diagnosticado
///
/// @param listaDeServicios
/// @param tamServicios
/// @param idBuscado
/// @return -1 si no lo encontro o el indice del servicio
int servicio_BuscarPorIdDiagnosticado(eServicio listaDeServicios[],int tamServicios,int idBuscado);
/// @brief da de alta un servicio
///
/// @param listaDeServicios
/// @param tamServicios
/// @param id
/// @return -1 si no encontro espacio, 0 si cancelo el alta, 1 si dio de alta con exito
int servicio_DarDeAlta(eServicio listaDeServicios[],int tamServicios,int* id);
/// @brief pide al usuario que ingrese un servicio
///
/// @param idServicio
/// @return el servicio ingresado
eServicio servicio_IngresarPorTeclado(int* idServicio);
/// @brief busca una posicion libre para un servicio
///
/// @param listaDeServicios
/// @param tamServicios
/// @return -1 si no encontro espacio, o el indice si encontro lugar
int servicio_BuscarLibre(eServicio listaDeServicios[],int tamServicios);
/// @brief inicializa el array de servicios
///
/// @param listaDeServicios
/// @param tamServicio
void servicio_InicializarArray(eServicio listaDeServicios[],int tamServicio);








