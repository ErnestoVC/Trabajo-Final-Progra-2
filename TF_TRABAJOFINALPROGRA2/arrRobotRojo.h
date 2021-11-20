#pragma once
#include "RobotRojo.h"

using namespace System::Drawing;
using namespace System;

class CarrRobotRojo
{
public:
	CarrRobotRojo(void);
	~CarrRobotRojo(void);

	void Insertar();
	void Eliminar();

	void Mover_Todos(Graphics ^gr, Bitmap ^bmp);

	CRobotRojo* Retornar_Objeto(int indice);
	int Rotornar_Cantidad();

private:
	CRobotRojo** arreglo;
	int cantidad;

};

CarrRobotRojo::CarrRobotRojo(void)
{
	arreglo=NULL;
	cantidad=0;
}

CarrRobotRojo::~CarrRobotRojo(void)
{
	if(arreglo!=NULL)
		for(int i=0;i<cantidad;i++)
			delete arreglo[i];
}

void CarrRobotRojo::Insertar()
{
	if(cantidad<9)
	{
		Random r;
		CRobotRojo** auxiliar=new CRobotRojo*[cantidad+1];
			if (auxiliar!=NULL)
			{    for (int i=0;i<cantidad;i++)
					auxiliar[i]=arreglo[i];
			auxiliar[cantidad]=new CRobotRojo(r.Next(50,700));
			cantidad++;
			   if (arreglo!=NULL)
				   delete arreglo;
			   arreglo=auxiliar;
		}
	}
}

void CarrRobotRojo::Eliminar()
{
	int Ecantidad=0;
		 for (int i=0;i<cantidad;i++)
			 cantidad+=arreglo[i]->getEliminar()? 1:0;
		 CRobotRojo** auxiliar=new CRobotRojo*[cantidad-Ecantidad];
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

void CarrRobotRojo::Mover_Todos(Graphics ^gr, Bitmap ^bmp)
{
	for (int i=0;i<cantidad;i++)
			arreglo[i]->Mover(gr,bmp);
		Eliminar();
}

CRobotRojo* CarrRobotRojo::Retornar_Objeto(int indice)
{
	return arreglo[indice];
}
	
int CarrRobotRojo::Rotornar_Cantidad()
{
	return cantidad;
}