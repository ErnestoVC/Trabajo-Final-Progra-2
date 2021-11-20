#pragma once
#include "Rayo.h"

using namespace System::Drawing;
using namespace System;

class CarrRayo
{
public:
	CarrRayo(void);
	~CarrRayo(void);

	void Insertar(int p, int x);
	void Eliminar();

	void Mover_Todos(Graphics ^gr, Bitmap ^bmp);

	CRayo* Retornar_Objeto(int indice);
	int Rotornar_Cantidad();

private:
	CRayo** arreglo;
	int cantidad;

};

CarrRayo::CarrRayo(void)
{
	arreglo=NULL;
	cantidad=0;
}

CarrRayo::~CarrRayo(void)
{
	if(arreglo!=NULL)
		for(int i=0;i<cantidad;i++)
			delete arreglo[i];
}

void CarrRayo::Insertar(int p, int x)
{
	if(cantidad<p)
	{
		Random r;
		CRayo** auxiliar=new CRayo*[cantidad+1];
			if (auxiliar!=NULL)
			{    for (int i=0;i<cantidad;i++)
					auxiliar[i]=arreglo[i];
			auxiliar[cantidad]=new CRayo(x);
			cantidad++;
			   if (arreglo!=NULL)
				   delete arreglo;
			   arreglo=auxiliar;
		}
	}
}

void CarrRayo::Eliminar()
{
	int Ecantidad=0;
		 for (int i=0;i<cantidad;i++)
			 Ecantidad+=arreglo[i]->getEliminar()? 1:0;
		 CRayo** auxiliar=new CRayo*[cantidad-Ecantidad];
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

void CarrRayo::Mover_Todos(Graphics ^gr, Bitmap ^bmp)
{
	for (int i=0;i<cantidad;i++)
			arreglo[i]->Mover(gr,bmp);
		Eliminar();
}

CRayo* CarrRayo::Retornar_Objeto(int indice)
{
	return arreglo[indice];
}
	
int CarrRayo::Rotornar_Cantidad()
{
	return cantidad;
}