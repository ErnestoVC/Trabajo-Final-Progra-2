#pragma once
#include "Llave.h"

using namespace System::Drawing;
using namespace System;

class CarrLlave
{
public:
	CarrLlave(void);
	~CarrLlave(void);

	void Insertar(int p, int x);
	void Eliminar();

	void Mover_Todos(Graphics ^gr, Bitmap ^bmp);

	CLlave* Retornar_Objeto(int indice);
	int Rotornar_Cantidad();

private:
	CLlave** arreglo;
	int cantidad;

};

CarrLlave::CarrLlave(void)
{
	arreglo=NULL;
	cantidad=0;
}

CarrLlave::~CarrLlave(void)
{
	if(arreglo!=NULL)
		for(int i=0;i<cantidad;i++)
			delete arreglo[i];
}

void CarrLlave::Insertar(int p, int x)
{
	if(cantidad<p)
	{
		Random r;
		CLlave** auxiliar=new CLlave*[cantidad+1];
			if (auxiliar!=NULL)
			{    for (int i=0;i<cantidad;i++)
					auxiliar[i]=arreglo[i];
			auxiliar[cantidad]=new CLlave(x);
			cantidad++;
			   if (arreglo!=NULL)
				   delete arreglo;
			   arreglo=auxiliar;
		}
	}
}

void CarrLlave::Eliminar()
{
	int Ecantidad=0;
		 for (int i=0;i<cantidad;i++)
			 Ecantidad+=arreglo[i]->getEliminar()? 1:0;
		 CLlave** auxiliar=new CLlave*[cantidad-Ecantidad];
		int h=0;
		 if (auxiliar!=NULL)
		{    for (int i=0;i<cantidad;i++)
			{    if (!arreglo[i]->getEliminar())
				 {	 auxiliar[h]=arreglo[i];
					 h++;
		         }
		     }
		  cantidad=cantidad-Ecantidad;
		   if (arreglo!=NULL)
			   delete arreglo;
		   arreglo=auxiliar;
		}
}

void CarrLlave::Mover_Todos(Graphics ^gr, Bitmap ^bmp)
{
	for (int i=0;i<cantidad;i++)
			arreglo[i]->Mover(gr,bmp);
		Eliminar();
}

CLlave* CarrLlave::Retornar_Objeto(int indice)
{
	return arreglo[indice];
}
	
int CarrLlave::Rotornar_Cantidad()
{
	return cantidad;
}