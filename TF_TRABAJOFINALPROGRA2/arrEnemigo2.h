#pragma once
#include "Enemigo2.h"

using namespace System::Drawing;
using namespace System;

class CarrEnemigo2
{
public:
	CarrEnemigo2(void);
	~CarrEnemigo2(void);

	void Insertar(int p);
	void Eliminar();

	void Mover_Todos(Graphics ^gr, Bitmap ^bmp);

	CEnemigo2* Retornar_Objeto(int indice);
	int Rotornar_Cantidad();

private:
	CEnemigo2** arreglo;
	int cantidad;
};

CarrEnemigo2::CarrEnemigo2(void)
{
	arreglo=NULL;
	cantidad=0;
}

CarrEnemigo2::~CarrEnemigo2(void)
{
	if(arreglo!=NULL)
		for(int i=0;i<cantidad;i++)
			delete arreglo[i];
}

void CarrEnemigo2::Insertar(int p)
{
	if(cantidad<p)
	{
		Random r;
		CEnemigo2** auxiliar=new CEnemigo2*[cantidad+1];
			if (auxiliar!=NULL)
			{    for (int i=0;i<cantidad;i++)
					auxiliar[i]=arreglo[i];
			auxiliar[cantidad]=new CEnemigo2(r.Next(50,700));
			cantidad++;
			   if (arreglo!=NULL)
				   delete arreglo;
			   arreglo=auxiliar;
		}
	}
}

void CarrEnemigo2::Eliminar()
{
	int Ecantidad=0;
		 for (int i=0;i<cantidad;i++)
			 Ecantidad+=arreglo[i]->getEliminar()? 1:0;
		 CEnemigo2** auxiliar=new CEnemigo2*[cantidad-Ecantidad];
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

void CarrEnemigo2::Mover_Todos(Graphics ^gr, Bitmap ^bmp)
{
	for (int i=0;i<cantidad;i++)
			arreglo[i]->Mover(gr,bmp);
		Eliminar();
}

CEnemigo2* CarrEnemigo2::Retornar_Objeto(int indice)
{
	return arreglo[indice];
}
	
int CarrEnemigo2::Rotornar_Cantidad()
{
	return cantidad;
}