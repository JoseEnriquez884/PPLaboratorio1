#include "Servicio.h"


//El top 3 de desperfectos más diagnosticados. (agregar 3 diagnósticos más)
void OrdenarDiagnosticos(eDiagnostico listaDeDiagnosticos[],int tamDiagnostico,eAuxiliar lista[])
{
	eDiagnostico aux;
	eAuxiliar auxiliar;
	for(int i=0;i<tamDiagnostico-1;i++)
	{
		for(int j=i+1;j<tamDiagnostico;j++)
		{
			if(lista[i].contador<lista[j].contador)
			{
				auxiliar=lista[i];
				lista[i]=lista[j];
				lista[j]=auxiliar;

				aux=listaDeDiagnosticos[i];
				listaDeDiagnosticos[i]=listaDeDiagnosticos[j];
				listaDeDiagnosticos[j]=aux;
			}
		}
	}
}
void MostrarTop3Diagnosticos(eDiagnostico listaDeDiagnosticos[],int tamDiagnostico,eAuxiliar lista[])
{
	for(int i=0;i<3;i++)
	{
		printf("%d %s : %d\n",listaDeDiagnosticos[i].idDiagnostico,listaDeDiagnosticos[i].descripcion,lista[i].contador);
	}
}
void ListarDesperfectosMasDiagnosticados(eServicio listaDeServicios[],int tamServicio,eMecanico listaDeMecanicos[],int tamMecanico,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico,eAuxiliar lista[])
{
	for(int i=0;i<tamDiagnostico;i++)
	{
		lista[i].contador=ContarServiciosPorDiagnostico(listaDeServicios, tamServicio, listaDeDiagnosticos[i].idDiagnostico);
	}
	OrdenarDiagnosticos(listaDeDiagnosticos, tamDiagnostico, lista);
	MostrarTop3Diagnosticos(listaDeDiagnosticos, tamDiagnostico, lista);
}
int ContarServiciosPorDiagnostico(eServicio listaDeServicios[],int tamServicio,int idDiagnostico)
{
	int contador;
	contador=0;

	for(int i=0;i<tamServicio;i++)
	{
		if(listaDeServicios[i].isEmpty==DIAGNOSTICADO && listaDeServicios[i].diagnostico==idDiagnostico)
		{
			contador++;
		}
	}
	return contador;
}
void InicializarArrayAuxiliarDiagnostico(eAuxiliar lista[],int tam,eDiagnostico listaDeDiagnosticos[])
{
	for(int i=0;i<tam;i++)
	{
		lista[i].contador=0;
		lista[i].id=listaDeDiagnosticos[i].idDiagnostico;
	}
}

int ContarServiciosDiagnosticados(eServicio listaDeServicios[],int tamServicio)
{
	int contador;
	contador=0;
	for(int i=0;i<tamServicio;i++)
	{
		if(listaDeServicios[i].isEmpty==DIAGNOSTICADO)
		{
			contador++;
		}
	}
	return contador;
}
void CalcularPorcentajeDeServiciosPorMecanico(eServicio listaDeServicios[],int tamServicio,eMecanico listaDeMecanicos[],int tamMecanico,eAuxiliar lista[])
{
	int contadorDeServicios;
	for(int i=0;i<tamMecanico;i++)
	{
		lista[i].contador=ContarServiciosPorMecanico(listaDeServicios, tamServicio, listaDeMecanicos[i].idMecanico);
		contadorDeServicios=ContarServiciosDiagnosticados(listaDeServicios, tamServicio);
		lista[i].porcentaje=(lista[i].contador*100)/contadorDeServicios;
		printf("%s : %.2f  \n",listaDeMecanicos[i].nombreDeMecanico,lista[i].porcentaje);
	}
}


void ListarServiciosPorLapsoDeTiempo(int mesInicial,int mesFinal,int anio,eServicio listaDeServicios[],int tamServicio,eMecanico listaDeMecanicos[],int tamMecanico,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico)
{
	int indiceMecanicos;
	int indiceDiagnosticos;
	int especialidadMecanico;


	printf("1. Electricista Automotriz\n");
	printf("2. Automotores Diesel\n");
	printf("3. Maquinaria Pesada\n");
	printf("4. Maquinaria Agrícola\n");
	printf("5. Motores Menores\n");
	Utn_PedirEntero(&especialidadMecanico, "ingrese especialidad: ", "error reingrese: ", 1, 10, 20);

	for(int i=0;i<tamServicio;i++)
	{
		if(listaDeServicios[i].fechaDeServicio.mes>=mesInicial && listaDeServicios[i].fechaDeServicio.mes<=mesFinal && listaDeServicios[i].fechaDeServicio.anio==anio)
		{
			indiceMecanicos=mecanico_BuscarPorId(listaDeMecanicos, tamMecanico, listaDeServicios[i].idMecanico);
			indiceDiagnosticos=diagnostico_BuscarPorId(listaDeDiagnosticos, tamDiagnostico, listaDeServicios[i].diagnostico);
			if(indiceMecanicos!=-1 && indiceDiagnosticos!=-1)
			{
				switch(especialidadMecanico)
				{
					case 1:
						if(strcmp(listaDeMecanicos[indiceMecanicos].especialidadDeMecanico,"Electricista Automotriz")==0)
						{
							servicio_ListarUnoDiagnosticadoConSuMecanico(listaDeServicios[i], listaDeMecanicos[indiceMecanicos], listaDeDiagnosticos[indiceDiagnosticos]);
						}
						break;
					case 2:
						if(strcmp(listaDeMecanicos[indiceMecanicos].especialidadDeMecanico,"Automotores Diesel")==0)
						{
							servicio_ListarUnoDiagnosticadoConSuMecanico(listaDeServicios[i], listaDeMecanicos[indiceMecanicos], listaDeDiagnosticos[indiceDiagnosticos]);
						}
						break;
					case 3:
						if(strcmp(listaDeMecanicos[indiceMecanicos].especialidadDeMecanico,"Maquinaria Pesada")==0)
						{
							servicio_ListarUnoDiagnosticadoConSuMecanico(listaDeServicios[i], listaDeMecanicos[indiceMecanicos], listaDeDiagnosticos[indiceDiagnosticos]);
						}
						break;
					case 4:
						if(strcmp(listaDeMecanicos[indiceMecanicos].especialidadDeMecanico,"Maquinaria Agrícola")==0)
						{
							servicio_ListarUnoDiagnosticadoConSuMecanico(listaDeServicios[i], listaDeMecanicos[indiceMecanicos], listaDeDiagnosticos[indiceDiagnosticos]);
						}
						break;
					case 5:
						if(strcmp(listaDeMecanicos[indiceMecanicos].especialidadDeMecanico,"Motores Menores")==0)
						{
							servicio_ListarUnoDiagnosticadoConSuMecanico(listaDeServicios[i], listaDeMecanicos[indiceMecanicos], listaDeDiagnosticos[indiceDiagnosticos]);
						}
						break;
				}
			}
		}
	}
}
void OrdenarServiciosPorEspecialidadDeMecanico(eServicio listaDeServicios[],int tamServicio,eMecanico listaDeMecanicos[],int tamMecanico)
{
	int indiceI;
	eServicio aux;
	int indiceJ;
	for(int i=0;i<tamServicio-1;i++)
	{
		for(int j=i+1;j<tamServicio;j++)
		{
			indiceI=mecanico_BuscarPorId(listaDeMecanicos, tamMecanico, listaDeServicios[i].idMecanico);
			indiceJ=mecanico_BuscarPorId(listaDeMecanicos, tamMecanico, listaDeServicios[j].idMecanico);
			if(indiceI!=-1 && indiceJ!=-1)
			{
				if(strcmp(listaDeMecanicos[indiceI].especialidadDeMecanico,listaDeMecanicos[indiceJ].especialidadDeMecanico)>0)
				{
					aux=listaDeServicios[i];
					listaDeServicios[i]=listaDeServicios[j];
					listaDeServicios[j]=aux;

				}
			}
		}
	}
}
void diagnostico_HardcodearDatos(eDiagnostico listaDeDiagnosticos[],int tamDiagnostico)
{
	eDiagnostico auxiliar[]={{1,"cambio de aceite"},
							 {2,"reparación de motor"},
							 {3,"suspensión"},
							 {4,"posible fuga"},
							 {5,"baja potencia"},
							 {6,"compresion baja"}};
	for(int i=0;i<tamDiagnostico;i++)
	{
		listaDeDiagnosticos[i]=auxiliar[i];
	}
}

void inicializarAuxiliar(eAuxiliar lista[],int tam,eMecanico listaDeMecanicos[])
{
	for(int i=0;i<tam;i++)
	{
		lista[i].id=listaDeMecanicos[i].idMecanico;
		lista[i].contador=0;
	}
}
void CalcularMecanicoConMasDiagnosticos(eAuxiliar lista[],eMecanico listaDeMecanicos[],int tamMecanicos,eServicio listaDeServicios[],int tamServicios)
{
	int maximo;
	int flag;
	flag=0;

	for(int i=0;i<tamMecanicos;i++)
	{
		lista[i].contador=ContarServiciosPorMecanico(listaDeServicios, tamServicios, listaDeMecanicos[i].idMecanico);
		if(flag==0 || lista[i].contador>maximo)
		{
			maximo=lista[i].contador;
			flag=1;
		}
	}
	MostrarMecanicosConMasServicios(lista,tamMecanicos,maximo,listaDeMecanicos);
}
void MostrarMecanicosConMasServicios(eAuxiliar lista[],int tam,int maximo,eMecanico listaDeMecanicos[])
{
	for(int i=0;i<tam;i++)
	{
		if(lista[i].contador==maximo)
		{
			mecanico_MostrarUno(listaDeMecanicos[i]);
		}
	}
}
int ContarServiciosPorMecanico(eServicio listaDeServicios[],int tamServicios,int idMecanico)
{
	int contador;
	contador=0;
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==DIAGNOSTICADO && listaDeServicios[i].idMecanico==idMecanico)
		{
			contador++;
		}
	}
	return contador;
}

void CalcularPromedioPorMecanico(eMecanico listaDeMecanicos[],int tamMecanicos,eServicio listaDeServicios[],int tamServicios)
{
	int contadoresDeServicios[tamMecanicos];
	float acumuladoresDeCotizaciones[tamMecanicos];
	float promedio;
	for(int i=0;i<tamMecanicos;i++)
	{
		contadoresDeServicios[i]=ContarServiciosPorMecanico(listaDeServicios, tamServicios, listaDeMecanicos[i].idMecanico);
		if(contadoresDeServicios[i]==0)
		{
			printf("el mecanico %s no diagnostico ningun servicio\n",listaDeMecanicos[i].nombreDeMecanico);
		}else
		{
			acumuladoresDeCotizaciones[i]=AcumularCotizacionPorMecanico(listaDeServicios, tamServicios, listaDeMecanicos[i].idMecanico);
			promedio=acumuladoresDeCotizaciones[i]/contadoresDeServicios[i];
			printf("%s : %.2f\n",listaDeMecanicos[i].nombreDeMecanico,promedio);
		}

	}

}
float AcumularCotizacionPorMecanico(eServicio listaDeServicios[],int tamServicios,int idMecanico)
{
	float acumuladorDeCotizaciones;
	acumuladorDeCotizaciones=0;
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==DIAGNOSTICADO && listaDeServicios[i].idMecanico==idMecanico)
		{
			acumuladorDeCotizaciones+=listaDeServicios[i].cotizacion;
		}
	}
	return acumuladorDeCotizaciones;
}



int servicio_BuscarPorFecha(eServicio listaDeServicios[],int tamServicios,eFecha fechaBuscada)
{
	int indice;
	indice=-1;
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==DIAGNOSTICADO &&
		   listaDeServicios[i].fechaDeServicio.dia == fechaBuscada.dia &&
		   listaDeServicios[i].fechaDeServicio.mes == fechaBuscada.mes &&
		   listaDeServicios[i].fechaDeServicio.anio==fechaBuscada.anio)
		{
			indice=i;
			break;
		}
	}
	return indice;
}

int CompararFecha(eFecha unaFecha,eFecha otraFecha)
{
	int retorno;
	retorno=-1;
	if(unaFecha.dia==otraFecha.dia &&
	   unaFecha.mes==otraFecha.mes &&
	   unaFecha.anio==otraFecha.anio)
	{
		retorno=0;
	}
	return retorno;
}

float BuscarCotizacionesPorFechaYDiagnostico(eServicio listaDeServicios[],int tamServicios,eDiagnostico listaDeDiagnosticos[], int tamDiagnostico,int idDiagnostico)
{
	eFecha auxFecha;
	float cotizaciones;
	cotizaciones=0;
	auxFecha=fecha_IngresarPorTeclado();

	for(int i=0;i<tamServicios;i++)
	{
		if(CompararFecha(listaDeServicios[i].fechaDeServicio,auxFecha)==0 && idDiagnostico==listaDeServicios[i].diagnostico)
		{
			cotizaciones+=listaDeServicios[i].cotizacion;
		}
	}
	return cotizaciones;
}

float SumarCotizacionesPorDiagnostico(eServicio unServicio,int tamServicios,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico,int idDiagnostico)
{
	float resultado;
	resultado=0;
	for(int i=0;i<tamServicios;i++)
	{
		if(unServicio.isEmpty==DIAGNOSTICADO && diagnostico_BuscarPorId(listaDeDiagnosticos, tamDiagnostico, idDiagnostico)!=-1 && unServicio.diagnostico==idDiagnostico)
		{
			resultado+=unServicio.cotizacion;
			//break;
		}
	}

	return resultado;
}
int InformarOrdenDeFecha(int primerFecha,int segundaFecha)
{
	int retorno;
	retorno=0;
	if(primerFecha>segundaFecha)
	{
		retorno=1;
	}else
	{
		if(primerFecha<segundaFecha)
		{
			retorno=-1;
		}
	}
	return retorno;
}
void OrdenarServiciosPorFecha(eServicio listaDeServicios[],int tamServicios)
{
	eServicio auxiliar;
	for(int i=0;i<tamServicios-1;i++)
	{
		for(int j=i+1;j<tamServicios;j++)
		{
			if(InformarOrdenDeFecha(listaDeServicios[i].fechaDeServicio.anio,listaDeServicios[j].fechaDeServicio.anio)==-1 ||
			   (InformarOrdenDeFecha(listaDeServicios[i].fechaDeServicio.anio,listaDeServicios[j].fechaDeServicio.anio)==0 && InformarOrdenDeFecha(listaDeServicios[i].fechaDeServicio.mes, listaDeServicios[j].fechaDeServicio.mes)==-1) ||
			   (InformarOrdenDeFecha(listaDeServicios[i].fechaDeServicio.mes,listaDeServicios[j].fechaDeServicio.mes)==0 && InformarOrdenDeFecha(listaDeServicios[i].fechaDeServicio.dia, listaDeServicios[j].fechaDeServicio.dia)==-1))
			{
				auxiliar=listaDeServicios[i];
				listaDeServicios[i]=listaDeServicios[j];
				listaDeServicios[j]=auxiliar;
			}
		}
	}
}
int BuscarServicioPorIdMecanico(eServicio listaDeServicios[],int tamServicios,int idMecanicoBuscado)
{
	int retorno;
	retorno=-1;
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].idMecanico==idMecanicoBuscado)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}
void ListarMecanicosSinServicios(eServicio listaDeServicios[],int tamServicios,eMecanico listaDeMecanicos[],int tamMecanicos)
{
	int flag;
	for(int i=0;i<tamMecanicos;i++)
	{
		flag=0;
		if(BuscarServicioPorIdMecanico(listaDeServicios,tamServicios,listaDeMecanicos[i].idMecanico)!=-1)
		{
			flag=1;
		}
		if(flag==0)
		{
			mecanico_MostrarUno(listaDeMecanicos[i]);
		}
	}
}

void servicio_ListarDiagnosticadosConSuMecanico(eServicio listaDeServicios[],int tamServicios,eMecanico listaDeMecanicos[],int tamMecanicos,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico)
{
	int indiceMecanicos;
	int indiceDiagnosticos;

	for(int i=0;i<tamServicios;i++)
	{
		indiceMecanicos=mecanico_BuscarPorId(listaDeMecanicos, tamMecanicos, listaDeServicios[i].idMecanico);
		indiceDiagnosticos=diagnostico_BuscarPorId(listaDeDiagnosticos, tamDiagnostico, listaDeServicios[i].diagnostico);
		if(listaDeServicios[i].isEmpty==DIAGNOSTICADO && indiceMecanicos!=-1 && indiceDiagnosticos!=-1)
		{
			servicio_ListarUnoDiagnosticadoConSuMecanico(listaDeServicios[i],listaDeMecanicos[indiceMecanicos],listaDeDiagnosticos[indiceDiagnosticos]);
		}
	}
}
void servicio_ListarUnoDiagnosticadoConSuMecanico(eServicio unServicio,eMecanico unMecanico,eDiagnostico unDiagnostico)
{
	printf("%-3d %-11s %d/%d/%d\t %-20s %15.2f %15s %15s\n",unServicio.idServicio,
								 unServicio.nombreDeCliente,
								 unServicio.fechaDeServicio.dia,
								 unServicio.fechaDeServicio.mes,
								 unServicio.fechaDeServicio.anio,
								 unDiagnostico.descripcion,
								 unServicio.cotizacion,
								 unMecanico.nombreDeMecanico,unMecanico.especialidadDeMecanico);

}
int servicio_BuscarPorIdYEstado(eServicio listaDeServicios[],int tamServicios,int idServicio,int estado)
{
	int retorno;
	retorno=-1;
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==estado && listaDeServicios[i].idServicio==idServicio)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}
void servicio_ListarTodosDiagnosticados(eServicio listaDeServicios[],int tamServicios)
{
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==DIAGNOSTICADO)
		{
			servicio_ListarUnoDiagnosticado(listaDeServicios[i]);
		}
	}
}
void servicio_ListarUnoDiagnosticado(eServicio unServicio)
{
	printf("%-3d %-11s %d/%d/%d\t",unServicio.idServicio,
								 unServicio.nombreDeCliente,
								 unServicio.fechaDeServicio.dia,
								 unServicio.fechaDeServicio.mes,
								 unServicio.fechaDeServicio.anio);
	if(unServicio.diagnostico==1)
	{
		printf("Cambio de aceite\t");
	}else
	{
		if(unServicio.diagnostico==2)
		{
			printf("Reparacion de motor\t");
		}else
		{
			if(unServicio.diagnostico==3)
			{
				printf("Suspension\t\t");
			}
		}
	}
	printf("%25.2f %4d\n",unServicio.cotizacion,unServicio.idMecanico);


}

int mecanico_BuscarPorId(eMecanico listaDeMecanicos[],int tamMecanicos,int idABuscar)
{
	int indice;
	indice=-1;
	for(int i=0;i<tamMecanicos;i++)
	{
		if(listaDeMecanicos[i].idMecanico==idABuscar)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
void diagnostico_MostrarTodos(eDiagnostico listaDeDiagnosticos[],int tamDiagnostico)
{
	for(int i=0;i<tamDiagnostico;i++)
	{
		diagnostico_MostrarUno(listaDeDiagnosticos[i]);
	}
}
void diagnostico_MostrarUno(eDiagnostico unDiagnostico)
{
	printf("%-2d %-17s\n",unDiagnostico.idDiagnostico,unDiagnostico.descripcion);
}
int diagnostico_BuscarPorId(eDiagnostico listaDeDiagnosticos[],int tamDiagnostico,int idDiagnosticoBuscado)
{
	int retorno;
	retorno=-1;
	for(int i=0;i<tamDiagnostico;i++)
	{
		if(listaDeDiagnosticos[i].idDiagnostico==idDiagnosticoBuscado)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}
int Diagnosticar(eServicio listaDeServicios[],int tamServicios,eMecanico listaDeMecanicos[],int tamMecanicos,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico)
{
	int retorno;
	int idServicioIngresado;
	int idMecanicoIngresado;
	int indiceDeServicio;
	int indiceDeMecanico;
	retorno=-1;
	mecanico_MostrarTodos(listaDeMecanicos, tamMecanicos);
	Utn_PedirEntero(&idMecanicoIngresado, "ingrese id de un mecanico: ", "error reingrese: ", 1, 5000, 20);
	indiceDeMecanico=mecanico_BuscarPorId(listaDeMecanicos,tamMecanicos,idMecanicoIngresado);//PROGRAMAR
	if(indiceDeMecanico!=-1)
	{
		retorno=0;
		servicio_MostrarTodosSinDiagnosticar(listaDeServicios, tamServicios);
		Utn_PedirEntero(&idServicioIngresado, "ingrese id de servicio: ", "error reingrese: ", 1, 5000, 20);
		indiceDeServicio=servicio_BuscarPorIdYEstado(listaDeServicios,tamServicios,idServicioIngresado,NO_DIAGNOSTICADO);//PROGRAMAR
		if(indiceDeServicio!=-1)
		{
			diagnostico_MostrarTodos(listaDeDiagnosticos, tamDiagnostico);
			Utn_PedirEntero(&listaDeServicios[indiceDeServicio].diagnostico, "ingrese diagnostico: ", "error reingrese: ", -1000, 3000, 20);
			if(diagnostico_BuscarPorId(listaDeDiagnosticos,tamDiagnostico,listaDeServicios[indiceDeServicio].diagnostico)!=-1)
			{
				Utn_PedirFlotante(&listaDeServicios[indiceDeServicio].cotizacion, "ingrese cotizacion: ", "error reingrese: ", 1, 100000, 20);
				listaDeServicios[indiceDeServicio].idMecanico=idMecanicoIngresado;
				listaDeServicios[indiceDeServicio].isEmpty=DIAGNOSTICADO;
				retorno=1;
			}else
			{
				retorno=-2;
			}
		}
	}
	return retorno;
}
void mecanico_MostrarTodos(eMecanico listaDeMecanicos[],int tamMecanicos)
{
	for(int i=0;i<tamMecanicos;i++)
	{
		mecanico_MostrarUno(listaDeMecanicos[i]);
	}
}
void mecanico_MostrarUno(eMecanico unMecanico)
{
	printf("%-3d %-15s %25s\n",unMecanico.idMecanico,unMecanico.nombreDeMecanico,unMecanico.especialidadDeMecanico);
}
void mecanico_HardcodearDatos(eMecanico listaDeMecanicos[],int tamMecanicos)
{
	eMecanico listaAux[]={{1,"Raul","Electricista Automotriz"},
						  {2,"Ramon","Automotores Diesel"},
						  {3,"Claudia","Maquinaria Pesada"},
						  {4,"Guido","Maquinaria Agrícola"},
						  {5,"Pablo","Motores Menores"}};
	for(int i=0;i<tamMecanicos;i++)
	{
		listaDeMecanicos[i]=listaAux[i];
	}
}
void servicio_HardcodearDatos2(eServicio listaDeServicios[],int tamServicios,int limite)
{
	if(limite<=tamServicios)
	{
		eServicio listaAux[]={
		{1,"Rodrigo",   {11,3,2022}, 1, 1300.9,    2,      DIAGNOSTICADO},
		{2,"Francisco", {20,3,2022}, 2, 2300.9,    1,      DIAGNOSTICADO},
		{3,"Florencia", {15,4,2021}, 3, 3300.9,    2,      DIAGNOSTICADO},
		{4,"Romina",    {25,4,2022}, 1, 100,       5,      DIAGNOSTICADO},
		{5,"Cecilia",   {20,3,2020}, 2, 2300.9,    5,      DIAGNOSTICADO},
		{6,"Fernando",  {16,7,2020}, 3, 5300.9,    1,      DIAGNOSTICADO},
		{7,"Tomas",     {20,5,2022}, 3, 6300.9,    4,      DIAGNOSTICADO},
		{8,"Sergio",    {10,10,2021}, 2, 1300.9,   4,      DIAGNOSTICADO},
		{9,"Augustin",  {25,6,2022}, 4, 100,       4,      DIAGNOSTICADO},
		{10,"Federico", {25,11,2021}, 5, 100,      3,      DIAGNOSTICADO},
		{11,"Federico", {25,11,2021}, 4, 100,      3,      DIAGNOSTICADO},
		{12,"Federico", {25,11,2021}, 6, 100,      3,      DIAGNOSTICADO}};
		for(int i=0;i<limite;i++)
		{
			listaDeServicios[i]=listaAux[i];
		}
	}

}
void servicio_HardcodearDatos(eServicio listaDeServicios[],int tamServicios)
{
	int ids[]={1,2,3,4,5,6,7,8,9,10};
	char nombres[][50]={"Rodrigo","Francisco","Florencia","Romina","Cecilia","Fernando","Tomas","Sergio","Augustin","Federico"};
	eFecha fechas[]={{11,2,2021},{20,3,2020},{15,4,2021},{30,3,2020},{20,3,2020},{16,7,2020},{20,3,2020},{10,10,2021},{25,11,2021},{28,1,2020}};
	int isEmpty[]={NO_DIAGNOSTICADO,NO_DIAGNOSTICADO,NO_DIAGNOSTICADO,NO_DIAGNOSTICADO,NO_DIAGNOSTICADO,NO_DIAGNOSTICADO,NO_DIAGNOSTICADO,NO_DIAGNOSTICADO,NO_DIAGNOSTICADO,NO_DIAGNOSTICADO};

	for(int i=0;i<tamServicios;i++)
	{
		listaDeServicios[i].idServicio=ids[i];
		strcpy(listaDeServicios[i].nombreDeCliente,nombres[i]);
		listaDeServicios[i].fechaDeServicio=fechas[i];
		listaDeServicios[i].isEmpty=isEmpty[i];
	}
}
void servicio_MostrarTodosSinDiagnosticar(eServicio listaDeServicios[],int tamServicios)
{
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==NO_DIAGNOSTICADO)
		{
			servicio_MostrarUnoSinDiagnosticar(listaDeServicios[i]);
		}
	}
}
void servicio_MostrarUnoSinDiagnosticar(eServicio unServicio)
{
	printf("%-3d %-11s %d/%d/%d\t",unServicio.idServicio,
							 unServicio.nombreDeCliente,
							 unServicio.fechaDeServicio.dia,
							 unServicio.fechaDeServicio.mes,
							 unServicio.fechaDeServicio.anio);
	printf("Sin diagnosticar\n");
	/*if(unServicio.diagnostico==1)
	{
		printf("Cambio de aceite\t");
	}else
	{
		if(unServicio.diagnostico==2)
		{
			printf("Reparacion de motor\t");
		}else
		{
			if(unServicio.diagnostico==3)
			{
				printf("Suspension\t\t");
			}
		}
	}
	printf("%25.2f %4d\n",unServicio.cotizacion,unServicio.idMecanico);*/
}
int servicio_CancelarServicio(eServicio listaDeServicios[],int tamServicios)
{
	int retorno;
	int idIngresado;
	int indice;
	int confirmacion;
	retorno=-1;
	//mostrar servicios
	Utn_PedirEntero(&idIngresado, "ingrese id que desea eliminar: ", "error reingrese: ", -1000, 5000, 20);
	indice=servicio_BuscarPorId(listaDeServicios, tamServicios, idIngresado);
	if(indice!=-1)
	{
		printf("esta seguro de dar de cancelar este servicio?\n");
		//mostrar el servicio
		printf("1. SI\n2. NO\n");
		Utn_PedirEntero(&confirmacion, "ingrese opcion: ", "error reingrese: ", 1, 2, 20);
		switch(confirmacion)
		{
			case 1:
				listaDeServicios[indice].isEmpty=LIBRE;
				retorno=1;
				break;
			case 2:
				retorno=0;
				break;
		}
	}
	return retorno;
}
int servicio_BuscarPorIdDiagnosticado(eServicio listaDeServicios[],int tamServicios,int idBuscado)
{
	int indice;
	indice=-1;
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==DIAGNOSTICADO && listaDeServicios[i].idServicio==idBuscado)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
int servicio_BuscarPorId(eServicio listaDeServicios[],int tamServicios,int idBuscado)
{
	int indice;
	indice=-1;
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==NO_DIAGNOSTICADO && listaDeServicios[i].idServicio==idBuscado)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
int servicio_Modificar(eServicio listaDeServicios[],int tamServicios,eMecanico listaDeMecanicos[],int tamMecanicos,eDiagnostico listaDeDiagnosticos[],int tamDiagnostico)
{
	int retorno;
	int opcionDeConfirmacion;
	eServicio servicioAuxiliar;
	int opcion;
	int idIngresado;
	int indice;
	retorno=-1;
	servicio_ListarDiagnosticadosConSuMecanico(listaDeServicios, tamServicios, listaDeMecanicos, tamMecanicos,listaDeDiagnosticos,tamDiagnostico);
	Utn_PedirEntero(&idIngresado, "ingrese id del servicio que desea modificar: ", "error reingrese: ", -1000, 9000, 20);
	indice=servicio_BuscarPorIdDiagnosticado(listaDeServicios, tamServicios, idIngresado);
	if(indice!=-1)
	{
		printf("1. Nombre de cliente\n2. Fecha de servicio\n3. Mecanico\n");
		Utn_PedirEntero(&opcion, "ingrese opcion: ", "error reingrese: ", 1, 3, 20);
		switch(opcion)
		{
			case 1:
				Utn_PedirCadena(servicioAuxiliar.nombreDeCliente, "ingrese nuevo nombre: ", "error, reingrese: ", 20);
				printf("1. SI\n2. NO\n");
				Utn_PedirEntero(&opcionDeConfirmacion, "esta seguro de modificar el nombre?: ", "error reingrese: ", 1, 2, 20);
				switch(opcionDeConfirmacion)
				{
					case 1:
						strcpy(listaDeServicios[indice].nombreDeCliente,servicioAuxiliar.nombreDeCliente);
						retorno=1;
						break;
					case 2:
						retorno=0;
						break;
				}
				break;
			case 2:
				servicioAuxiliar.fechaDeServicio=fecha_IngresarPorTeclado();
				printf("1. SI\n2. NO\n");
				Utn_PedirEntero(&opcionDeConfirmacion, "esta seguro de modificar la fecha?: ", "error reingrese: ", 1, 2, 20);
				switch(opcionDeConfirmacion)
				{
					case 1:
						listaDeServicios[indice].fechaDeServicio=servicioAuxiliar.fechaDeServicio;
						retorno=1;
						break;
					case 2:
						retorno=0;
						break;
				}
				break;
			case 3:
				//mostrar mecanicos
				mecanico_MostrarTodos(listaDeMecanicos, tamMecanicos);
				Utn_PedirEntero(&servicioAuxiliar.idMecanico, "ingrese nuevo mecanico por su id: ", "error reingrese: ", -1000, 5000, 20);
				//verificar que el id ingresado sea de un mecanico existente
				if(mecanico_BuscarPorId(listaDeMecanicos, tamMecanicos, servicioAuxiliar.idMecanico)!=-1)
				{
					printf("1. SI\n2. NO\n");
					Utn_PedirEntero(&opcionDeConfirmacion, "esta seguro de modificar el mecanico?: ", "error reingrese: ", 1, 2, 20);
					switch(opcionDeConfirmacion)
					{
					case 1:
						listaDeServicios[indice].idMecanico=servicioAuxiliar.idMecanico;
						retorno=1;
						break;
					case 2:
						retorno=0;
						break;
					}
				}else
				{
					retorno=-2;
				}
				break;
		}
	}
	return retorno;
}
int servicio_DarDeAlta(eServicio listaDeServicios[],int tamServicios,int* id)
{
	int indice;
	int retorno;
	int confirmacion;
	eServicio auxServicio;
	retorno=-1;
	indice=servicio_BuscarLibre(listaDeServicios, tamServicios);
	if(indice!=-1)
	{
		auxServicio=servicio_IngresarPorTeclado(id);
		printf("esta seguro de dar de alta este producto?\n");
		servicio_MostrarUnoSinDiagnosticar(auxServicio);
		printf("1. SI\n2. NO\n");
		Utn_PedirEntero(&confirmacion, "ingrese opcion: ", "error reingrese: ", 1, 2, 20);
		switch(confirmacion)
		{
			case 1:
				listaDeServicios[indice]=auxServicio;
				retorno=1;
				break;
			case 2:
				retorno=0;
				break;
		}
	}
	return retorno;
}
eFecha fecha_IngresarPorTeclado()
{
	eFecha auxiliar;
	Utn_PedirEntero(&auxiliar.dia, "ingrese dia: ", "error reingrese: ", 1, 31, 20);
	Utn_PedirEntero(&auxiliar.mes, "ingrese mes: ", "error reingrese: ", 1, 12, 20);
	Utn_PedirEntero(&auxiliar.anio, "ingrese anio: ", "error reingrese: ",  2015, 2022, 20);
	return auxiliar;
}
eServicio servicio_IngresarPorTeclado(int* idServicio)
{
	eServicio aux;
	Utn_PedirCadena(aux.nombreDeCliente, "ingrese nombre del cliente: ", "error reingrese: ", 20);
	aux.fechaDeServicio=fecha_IngresarPorTeclado();
	aux.isEmpty=NO_DIAGNOSTICADO;
	*idServicio=*idServicio+1;
	aux.idServicio=*idServicio;
	return aux;
}
int servicio_BuscarLibre(eServicio listaDeServicios[],int tamServicios)
{
	int indice;
	indice=-1;
	for(int i=0;i<tamServicios;i++)
	{
		if(listaDeServicios[i].isEmpty==LIBRE)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
void servicio_InicializarArray(eServicio listaDeServicios[],int tamServicio)
{
	for(int i=0;i<tamServicio;i++)
	{
		listaDeServicios[i].isEmpty=LIBRE;
	}
}
