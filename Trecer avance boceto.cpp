// Trecer avance boceto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream> 

using namespace std;

int * idcontrato, * numoc, registros, * Numarticulo, busqueda;
string * proveedor, * juego, * carac, * genero, * descripcion, * lanzamiento, * consola, * clasificacion;
float * subtotal, * IVA, * total, * precio;

void alta();
void lista();
void modificar();
void archivos();
void Eliminar();


int main()
{
	int opcion;
	printf("\t BIENVENIDO A POWER FOX GAME STORE \n");
	printf(" 1.-Agregar articulo \n 2.-Lista \n 3.-Eliminar articulo \n 4.-Limpiar pantalla \n 5.-Modificar articulo \n 6.-Salir \n");
	printf("************************************\n");
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		alta();
		system("pause");
		return main();
		break;

	case 2:
		lista();
		system("pause");
		return main();
		break;

	case 3:
		Eliminar();
		system("pause");
		return main();
		break;

	case 4:
		system("cls");
		return main();
		break;

	case 5:
		modificar();
		system("pause");
		return main();
		break;

	case 6:
		archivos();
		exit(1);
		break;

	default:
		printf("ingrese la opc correcta \n");
		return main();
		break;
	}
}
void alta()
{
	printf("cuantos registros desea dar de alta \n");
	scanf_s("%d", &registros);
	idcontrato = new int[registros];
	numoc = new int[registros];
	Numarticulo = new int[registros];
	juego = new string[registros];
	clasificacion = new string[registros];
	genero = new string[registros];
	consola = new string[registros];
	lanzamiento = new string[registros];
	carac = new string[registros];
	descripcion = new string[registros];
	proveedor = new string[registros];
	precio = new float[registros];
	subtotal = new float[registros];
	IVA = new float[registros];
	total = new float[registros];

	for (int i = 0; i < registros; i++)
	{
		printf("ingrese el id contrato \n");
		scanf_s("%d", &idcontrato[i]);
		int n = 1;

		do
		{

			if (idcontrato[i] != idcontrato[i - n])
			{
				n = n + 1;
			}
			else
			{
				printf("el idcontrato ya existe ya existe \n");
				printf("ingrese el idcontrato \n");
				scanf_s("%d", &idcontrato[i]);
				n = n + 1;
			}

		} while (n < registros);

		printf("ingrese el numoc \n");
		scanf_s("%d", &numoc[i]);
		int n2 = 1;

		do
		{

			if (numoc[i] != numoc[i - n2])
			{
				n2 = n2 + 1;
			}
			else
			{
				printf("el numoc ya existe ya existe \n");
				printf("ingrese el numoc \n");
				scanf_s("%d", &numoc[i]);
				n2 = n2 + 1;
			}

		} while (n2 < registros);

		printf("ingrese el numero de compra \n");
		cin.ignore();
		scanf_s("%d", &Numarticulo[i]);
		int n3 = 1;

		do
		{

			if (Numarticulo[i] != Numarticulo[i - n3])
			{
				n3 = n3 + 1;
			}
			else
			{
				printf("El numero de articulo ya existe \n");
				printf("Ingrese el numero de articulo \n");
				scanf_s("%d", &Numarticulo[i]);
				n3 = n3 + 1;
			}

		} while (n3 < registros);
		printf("Ingrese el nombre del juego \n");
		cin.ignore();
		getline(cin, juego[i]);
		printf("Ingrese la clasificacion del juego \n");
		getline(cin, clasificacion[i]);
		printf("Ingrese el genero del juego \n");
		getline(cin, genero[i]);
		printf("Ingrese la plataforma del juego \n");
		getline(cin, consola[i]);
		printf("Ingrese el a%co de lanzamiento \n" , 164);
		getline(cin, lanzamiento[i]);
		printf("Ingrese las caracteristicas del juego \n");
		getline(cin, carac[i]);
		printf("Ingrese la descripcion del juego \n");
		getline(cin, descripcion[i]);
		printf("Ingrese el proovedor\n");
		getline(cin, proveedor[i]);
		printf("Ingrese el precio \n");
		scanf_s("%f", &precio[i]);
		printf("Ingrese el subtotal \n");
		scanf_s("%f", &subtotal[i]);
		printf("\t El IVA es de .16 \n");
		IVA[i] = precio[i] * .16;
		total[i] = subtotal[i] + IVA[i];
		printf("\t Precio con IVA: %f \n", IVA[i]);
		printf("\t TOTAL:%f \n", total[i]);

		if ((registros - 1) == i)
		{
			int desicion;
			printf("desea dar alta otra OC \n 1-.Si\n 2.-No\n");
			scanf_s("%d", &desicion);
			if (desicion == 1)
			{
				registros = registros + 1;
			}
		}
	}
}

void lista()
{
	int opc2;
	printf(" 1.-Ver lista \n 2.-Por genero \n 3.-Clasificacion \n 4.-Limpiar pantalla \n 5.-Regresar al menu principal \n ");
	scanf_s("%d", &opc2);

	switch (opc2)
	{
	case 1:
		printf("Ingrese el numoc \n");
		scanf_s("%d", &busqueda);

		for (int i = 0; i < registros; i++)
		{
			if (busqueda == numoc[i])
			{
				printf("\t IDCONTRATO: %d \n", idcontrato[i]);
				printf("\t NUMOC: %d \n", numoc[i]);
				printf("\t NUMARTICULO: %d \n", Numarticulo[i]);
				printf("\t JUEGO: %s \n", juego[i].c_str());
				printf("CLASIFICACION: %s \n", clasificacion[i].c_str());
				printf("GENERO: %s \n", genero[i].c_str());
				printf("CONSOLA: %s \n", consola[i].c_str());
				printf("LANZAMIENTO: %s \n", lanzamiento[i].c_str());
				printf("CARACTERISTICAS: %s \n", carac[i].c_str());
				printf("DESCRIPCION: %s \n", descripcion[i].c_str());
				printf("PROVEEDOR: %s \n", proveedor[i].c_str());
				printf("PRECIO: %f \n", precio[i]);
				printf("SUBTOTAL: %f \n", subtotal[i]);
				printf("\t IVA: %f \n", IVA[i]);
				printf("\t TOTAL: %f \n", total[i]);
			}
			else
			{
				printf("El numoc no existe, ingrese el numoc \n ");
				scanf_s("%d", &numoc[i]);
				
			}
		}
		system("pause");
		return lista();
		break;

	case 2:
		printf("Ingrese el genero \n");
		scanf_s("%d", &busqueda);

		for (int i = 0; i < registros; i++)

		{
			if (genero[i] == genero[i])
			{
				printf("\t GENERO: %s \n", genero[i].c_str());
			}
			
		}

		system("pause");
		return lista();
		break;

	case 3:
		printf("ingrese la clasificacion \n");
		scanf_s("%d", &busqueda);

		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == clasificacion[i])
			{
				printf("\t CLASIFICACION: %s \n", clasificacion[i].c_str());
			}
				
		}


		system("pause");
		return lista();
		break;

	case 4:
		system("cls");
		return lista();
		break;


	case 5:
		break;
	}
}

void Eliminar()
{
	int eliminar;
	system("cls");

	printf("Ingrese el numoc \n");
	scanf_s("%d", &eliminar);

	for(int i = 0; i< registros; i++)
	{
	
		if(eliminar == numoc[i])
		{
			numoc[i] = 0;
		}
		printf("Articulo eliminado \n");
	}


}

void modificar()
{
	printf("Favor de ingresar el numoc \n");
	scanf_s("%d", &busqueda);

	for (int i = 0; i < registros; i++)
	{
		if (busqueda == numoc[i])
		{

			printf("ingrese el numero de compra \n");
			scanf_s("%d", &Numarticulo[i]);
			printf("Ingrese el nombre del juego \n");
			cin.ignore();
			getline(cin, juego[i]);
			printf("Ingrese la clasificacion del juego \n");
			getline(cin, clasificacion[i]);
			printf("Ingrese el genero del juego \n");
			getline(cin, genero[i]);
			printf("Ingrese la plataforma del juego \n");
			getline(cin, consola[i]);
			printf("Ingrese el a%co de lanzamiento \n", 164);
			getline(cin, lanzamiento[i]);
			printf("Ingrese las caracteristicas del juego \n");
			getline(cin, carac[i]);
			printf("Ingrese la descripcion del juego \n");
			getline(cin, descripcion[i]);
			printf("Ingrese el proovedor\n");
			getline(cin, proveedor[i]);
			printf("Ingrese el precio \n");
			scanf_s("%f", &precio[i]);
			printf("Ingrese el subtotal \n");
			scanf_s("%f", &subtotal[i]);
			printf("\t El IVA es de .16 \n");
			IVA[i] = precio[i] * .16;
			total[i] = subtotal[i] + IVA[i];
			printf("\t Precio con IVA: %f \n", IVA[i]);
			printf("\t TOTAL:%f \n", total[i]);
		}
		else
		{
			printf("El numoc no existe, favor de ingresar el numoc correcto \n ");
			return modificar();
		}
	}
}

void archivos()
	{
		ofstream archivo;
		string nombrearchivo;
		int texto;
		float decimal;
		string texto2;

		nombrearchivo = "LISTANUMOC";

		archivo.open(nombrearchivo.c_str(), ios::out);

		if (archivo.fail())
		{
			printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
			system("pause");
			exit(1);
		}


		archivo << "IDCONTRATO" << "\t";
		archivo << "NUMOC" << "\t";
		archivo << "PRECIO" << "\t";
		archivo << "SUBTOTAL" << "\t";
		archivo << "IVA" << "\t";
		archivo << "TOTAL" << "\n";



		for (int i = 0; i < registros; i++)
		{
			texto = idcontrato[i];
			archivo << texto << "\t" << "\t";
			texto = numoc[i];
			archivo << texto << "\t";
			decimal = subtotal[i];
			archivo << decimal << "\t";
			decimal = IVA[i];
			archivo << decimal << "\t";
			archivo << total[i] << "\n";
		}
		archivo.close();
	}
