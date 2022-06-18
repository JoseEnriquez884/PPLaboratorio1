/*
 ============================================================================
 Name        : PrimerParcialLabo.c
 Author      : Enriquez Bishop Jose
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Servicio.h"

int main(void)
{
	setbuf(stdout,NULL);
	eMecanico listaDeMecanicos[TAM_MECANICOS];
	eServicio listaDeServicios[TAM_SERVICIOS];
	eDiagnostico listaDeDiagnosticos[TAM_DIAGNOSTICOS];
	eAuxiliar lista[TAM_MECANICOS];
	eAuxiliar lista2[TAM_DIAGNOSTICOS];
	int opcion;
	int opcionDeAlta;
	int opcionDeModificar;
	int opcionCancelarServicio;
	int opcionInformes;
	int opcionDiagnostico;
	float cotizacionesPorFechaYDiagnostico;
	int id;
	id=0;
	//servicio_HardcodearDatos(listaDeServicios, TAM_SERVICIOS);
	servicio_InicializarArray(listaDeServicios, TAM_SERVICIOS);
	servicio_HardcodearDatos2(listaDeServicios, TAM_SERVICIOS,12);
	mecanico_HardcodearDatos(listaDeMecanicos, TAM_MECANICOS);
	diagnostico_HardcodearDatos(listaDeDiagnosticos, TAM_DIAGNOSTICOS);
	//servicio_InicializarArray(listaDeServicios, TAM_SERVICIOS);
	inicializarAuxiliar(lista, TAM_MECANICOS, listaDeMecanicos);
	InicializarArrayAuxiliarDiagnostico(lista2, TAM_DIAGNOSTICOS, listaDeDiagnosticos);
	do
	{
		printf("1. Alta servicio\n");
		printf("2. Modificar servicio\n");
		printf("3. Cancelar servicio\n");
		printf("4. Diagnosticar\n");
		printf("5. Listar\n");
		printf("6. Salir\n");
		Utn_PedirEntero(&opcion, "ingrese opcion: ", "error reingrese: ", 1, 10, 20);
		switch(opcion)
		{
			case 1:
				opcionDeAlta=servicio_DarDeAlta(listaDeServicios, TAM_SERVICIOS, &id);
				switch(opcionDeAlta)
				{
					case -1:
						printf("\nNo hay espacio\n\n");
						break;
					case 0:
						printf("\nSe cancelo el alta del servicio\n\n");
						break;
					case 1:
						printf("\nSe dio de alta con exito\n\n");
						break;
				}
				break;
			case 2:
				opcionDeModificar=servicio_Modificar(listaDeServicios, TAM_SERVICIOS,listaDeMecanicos,TAM_MECANICOS,listaDeDiagnosticos,TAM_DIAGNOSTICOS);
				switch(opcionDeModificar)
				{
					case -2:
						printf("\nId de mecanico inexistente\n\n");
						break;
					case -1:
						printf("\nNo se encontro el id\n\n");
						break;
					case 0:
						printf("\nSe cancelo el la modificacion del servicio\n\n");
						break;
					case 1:
						printf("\nSe modifico con exito\n\n");
						break;
				}
				break;
			case 3:
				opcionCancelarServicio=servicio_CancelarServicio(listaDeServicios, TAM_SERVICIOS);
				switch(opcionCancelarServicio)
				{
					case -1:
						printf("\nNo se encontro el id\n\n");
						break;
					case 0:
						printf("\nSe interrumpio la cancelacion\n\n");
						break;
					case 1:
						printf("\nSe cancelo el servicio con exito\n\n");
						break;
				}
				break;
			case 4:
				opcionDiagnostico=Diagnosticar(listaDeServicios, TAM_SERVICIOS, listaDeMecanicos, TAM_MECANICOS,listaDeDiagnosticos,TAM_DIAGNOSTICOS);
				switch(opcionDiagnostico)
				{
					case -2:
						printf("\nId de diagnostico inexistente\n\n");
						break;
					case -1:
						printf("\nNo se encontro el id de mecanico\n\n");
						break;
					case 0:
						printf("\nNo se encontro el id de servicio\n\n");
						break;
					case 1:
						printf("\nSe diagnostico con exito\n\n");
						break;
				}
				break;
			case 5:
				do
				{
					printf("1.  Todos los mecánicos.\n");
					printf("2.  Todos los servicios\n");
					printf("3.  Todos los mecánicos a los cuales no se les haya asignado ningún servicio\n");
					printf("4.  Listado de servicios ordenados por fecha, desde el más antiguo hasta el más reciente.\n");
					printf("5.  Para una fecha determinada se necesita saber cuál fue la suma de cotizaciones en concepto de cambio de aceite.\n");
					printf("6.  Cotización promedio de cada uno de los mecánicos.\n");
					printf("7.  Determinar cuál/cuáles son los mecánicos que diagnosticaron más servicios\n");
					printf("8.  Listado de servicios ordenados por especialidad del mecánico alfabéticamente\n");
					printf("9.  Listado de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada\n");
					printf("10. Porcentaje de servicio diagnosticados que atiende cada mecánico en función del total de diagnósticos\n");
					printf("11. Top 3 diagnosticos\n");
					printf("12. Volver\n");
					Utn_PedirEntero(&opcionInformes, "ingrese opcion: ", "error reingrese: ", 1, 12, 20);
					switch(opcionInformes)
					{
						case 1:
							mecanico_MostrarTodos(listaDeMecanicos, TAM_MECANICOS);
							break;
						case 2:
							servicio_ListarDiagnosticadosConSuMecanico(listaDeServicios, TAM_SERVICIOS,listaDeMecanicos,TAM_MECANICOS,listaDeDiagnosticos,TAM_DIAGNOSTICOS);
							servicio_MostrarTodosSinDiagnosticar(listaDeServicios, TAM_SERVICIOS);
							break;
						case 3:
							printf("mecanicos que no tienen asignado ningun servicio: \n");
							ListarMecanicosSinServicios(listaDeServicios, TAM_SERVICIOS, listaDeMecanicos, TAM_MECANICOS);
							break;
						case 4:
							printf("listado de servicios ordenados por fecha\n");
							OrdenarServiciosPorFecha(listaDeServicios, TAM_SERVICIOS);
							servicio_ListarDiagnosticadosConSuMecanico(listaDeServicios, TAM_SERVICIOS,listaDeMecanicos,TAM_MECANICOS,listaDeDiagnosticos,TAM_DIAGNOSTICOS);
							servicio_MostrarTodosSinDiagnosticar(listaDeServicios, TAM_SERVICIOS);
							break;
						case 5:
							cotizacionesPorFechaYDiagnostico=BuscarCotizacionesPorFechaYDiagnostico(listaDeServicios, TAM_SERVICIOS,listaDeDiagnosticos,TAM_DIAGNOSTICOS,1);
							if(cotizacionesPorFechaYDiagnostico==-1)
							{
								printf("\nFecha no registrada\n\n");
							}else
							{
								if(cotizacionesPorFechaYDiagnostico==0)
								{
									printf("\nno hay cotizaciones en esa fecha\n\n");
								}else
								{
									printf("\ncotizaciones de la fecha ingresada en concepto de cambio de aceite: %.2f\n\n",cotizacionesPorFechaYDiagnostico);
								}
							}
							break;
						case 6:
							printf("\npromedio de cotizaciones por mecanico: \n\n");
							CalcularPromedioPorMecanico(listaDeMecanicos, TAM_MECANICOS, listaDeServicios, TAM_SERVICIOS);
							break;
						case 7:
							printf("\nmecanicos con mas diagnosticos: \n\n");
							CalcularMecanicoConMasDiagnosticos(lista,listaDeMecanicos, TAM_MECANICOS, listaDeServicios, TAM_SERVICIOS);
							break;
						case 8:
							OrdenarServiciosPorEspecialidadDeMecanico(listaDeServicios, TAM_SERVICIOS, listaDeMecanicos, TAM_MECANICOS);
							servicio_ListarDiagnosticadosConSuMecanico(listaDeServicios, TAM_SERVICIOS,listaDeMecanicos,TAM_MECANICOS,listaDeDiagnosticos,TAM_DIAGNOSTICOS);
							servicio_MostrarTodosSinDiagnosticar(listaDeServicios, TAM_SERVICIOS);
							break;
						case 9:
							ListarServiciosPorLapsoDeTiempo(3, 5, 2022, listaDeServicios, TAM_SERVICIOS, listaDeMecanicos, TAM_MECANICOS, listaDeDiagnosticos, TAM_DIAGNOSTICOS);
							break;
						case 10:
							CalcularPorcentajeDeServiciosPorMecanico(listaDeServicios, TAM_SERVICIOS, listaDeMecanicos, TAM_MECANICOS, lista);
							break;
						case 11:
							printf("top 3 de desperfectos mas diagnosticados: \n");
							ListarDesperfectosMasDiagnosticados(listaDeServicios, TAM_SERVICIOS, listaDeMecanicos, TAM_MECANICOS, listaDeDiagnosticos, TAM_DIAGNOSTICOS, lista2);
							break;
					}
				}while(opcionInformes!=12);
				break;
		}
	}while(opcion!=6);
	return EXIT_SUCCESS;
}
