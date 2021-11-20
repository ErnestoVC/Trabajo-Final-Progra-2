#pragma once
#include "RobotGris.h"

using namespace System::Drawing;
using namespace System;

class CarrRobotGris
{
public:
	CarrRobotGris(void);
	~CarrRobotGris(void);

	void Insertar();
	void Eliminar();

	void Mover_Todos(Graphics ^gr, Bitmap ^bmp);

	CRobotGris* Retornar_Objeto(int indice);
	int Rotornar_Cantidad();

private:
	CRobotGris** arreglo;
	int cantidad;
};

CarrRobotGris::CarrRobotGris(void)
{
	arreglo=NULL;
	cantidad=0;
}

CarrRobotGris::~CarrRobotGris(void)
{
	if(arreglo!=NULL)
		for(int i=0;i<cantidad;i++)
			delete arreglo[i];
}

void CarrRobotGris::Insertar()
{
	if(cantidad<12)
	{
		Random r;
		CRobotGris** auxiliar=new CRobotGris*[cantidad+1];
			if (auxiliar!=NULL)
			{    for (int i=0;i<cantidad;i++)
					auxiliar[i]=arreglo[i];
			auxiliar[cantidad]=new CRobotGris(r.Next(50,700));
			cantidad++;
			   if (arreglo!=NULL)
				   delete arreglo;
			   arreglo=auxiliar;
		}
	}
}

void CarrRobotGris::Eliminar()
{
	int Ecantidad=0;
		 for (int i=0;i<cantidad;i++)
			 cantidad+=arreglo[i]->getEliminar()? 1:0;
		 CRobotGris** auxiliar=new CRobotGris*[cantidad-Ecantidad];
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

void CarrRobotGris::Mover_Todos(Graphics ^gr, Bitmap ^bmp)
{
	for (int i=0;i<cantidad;i++)
			arreglo[i]->Mover(gr,bmp);
		Eliminar();
}

CRobotGris* CarrRobotGris::Retornar_Objeto(int indice)
{
	return arreglo[indice];
}
	
int CarrRobotGris::Rotornar_Cantidad()
{
	return cantidad;
}