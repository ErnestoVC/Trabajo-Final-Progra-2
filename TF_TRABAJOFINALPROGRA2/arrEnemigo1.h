#pragma once
#include "Enemigo1.h"

using namespace System::Drawing;
using namespace System;

class CarrEnemigo1
{
public:
	CarrEnemigo1(void);
	~CarrEnemigo1(void);

	void Insertar(int p);
	void Eliminar();

	void Mover_Todos(Graphics ^gr, Bitmap ^bmp);

	CEnemigo1* Retornar_Objeto(int indice);
	int Rotornar_Cantidad();

private:
	CEnemigo1** arreglo;
	int cantidad;

};

CarrEnemigo1::CarrEnemigo1(void)
{
	arreglo=NULL;
	cantidad=0;
}

CarrEnemigo1::~CarrEnemigo1(void)
{
	if(arreglo!=NULL)
		for(int i=0;i<cantidad;i++)
			delete arreglo[i];
}

void CarrEnemigo1::Insertar(int p)
{
	if(cantidad<p)
	{
		Random r;
		CEnemigo1** auxiliar=new CEnemigo1*[cantidad+1];
			if (auxiliar!=NULL)
			{    for (int i=0;i<cantidad;i++)
					auxiliar[i]=arreglo[i];
			auxiliar[cantidad]=new CEnemigo1(r.Next(50,700));
			cantidad++;
			   if (arreglo!=NULL)
				   delete arreglo;
			   arreglo=auxiliar;
		}
	}
}

void CarrEnemigo1::Eliminar()
{
	int Ecantidad=0;
		 for (int i=0;i<cantidad;i++)
			 Ecantidad+=arreglo[i]->getEliminar()? 1:0;
		 CEnemigo1** auxiliar=new CEnemigo1*[cantidad-Ecantidad];
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

void CarrEnemigo1::Mover_Todos(Graphics ^gr, Bitmap ^bmp)
{
	for (int i=0;i<cantidad;i++)
			arreglo[i]->Mover(gr,bmp);
		Eliminar();
}

CEnemigo1* CarrEnemigo1::Retornar_Objeto(int indice)
{
	return arreglo[indice];
}
	
int CarrEnemigo1::Rotornar_Cantidad()
{
	return cantidad;
}