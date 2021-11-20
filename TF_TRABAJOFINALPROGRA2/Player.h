#pragma once
#include <stdio.h>
#include "Bala.h"
#include "Objetos.h"

enum Direccion {izquierda,derecha,ninguno,salto,nosalto}; 
using namespace System::Drawing;
using namespace System;

class CPlayer: public CObjetos
{
public:
	CPlayer(void);
	CPlayer(int px, int py);
	~CPlayer(void);

	
	void Calcular_W_H(Bitmap ^bmp); 
	void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp); 
	void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp, Direccion tecla);

	void Disparar();
	void Mover_Balas(System::Drawing::Graphics ^gr);
	void Eliminar_Balas();
	CBala* Retornar_Bala(int indice);
	int Retornar_Cantidad_Balas();
	void setPoder();
	bool getPoder();

private:

	//int X,Y,dx,dy;
	//int iW,iH,W,H;
	bool salto;
	bool poder;
	CBala** arreglo;
	int cont_balas;

};

CPlayer::CPlayer(void){}
CPlayer::~CPlayer(void){} 
CPlayer::CPlayer(int px, int py):CObjetos()
{
	
	X=px;
	Y=py;
	dx=dy=W=H=iW=iH=0;
	salto=false;
	poder=false;
	arreglo=NULL;
	cont_balas=0;
}

void CPlayer::Calcular_W_H(Bitmap ^bmp)
{
	W=bmp->Width/4; 
	H=bmp->Height/4;
}

void CPlayer::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Calcular_W_H(bmp); 

	iW++;
		if(iW>3) 
		{
			iW=0;
		}
	Rectangle zoom= Rectangle(X-W,Y-H,W*2,H*2);
	Rectangle porcion=Rectangle(iW*W,iH*H,W,H); 
	if(poder)
		gr->DrawImage(bmp,zoom,porcion,GraphicsUnit::Pixel);
	else
		gr->DrawImage(bmp,X,Y,porcion,GraphicsUnit::Pixel); 
}

void CPlayer::Mover(Graphics ^gr, Bitmap ^bmp, Direccion tecla)
{
	if (tecla==Direccion::derecha){dy=0; dx=15; iH=2;}
	if (tecla==Direccion::izquierda){dy=0; dx=-15; iH=1;}
	if (tecla==Direccion::ninguno){dy=0; dx=0; iH=0;}
	if (tecla==Direccion::salto){salto=false; dy=-30;}

	if(!(X+dx<0 || X+dx>730)) 
		X+=dx;
	if(Y+dy>=350)
	{
		Y=350;
		dy=0;
		salto=true;
	}
	if(salto==false)
	{
		Y+=dy;
		dy+=5;
	}

	Mostrar(gr,bmp);
}

void CPlayer::Disparar()
{
	int pdireccion;
	if(iH==1)
		pdireccion=-5;
	else
		pdireccion=5;
	CBala** auxiliar=new CBala*[cont_balas+1];
	if (auxiliar!=NULL)
	{    
		for (int i=0;i<cont_balas;i++)
			auxiliar[i]=arreglo[i];
		auxiliar[cont_balas]=new CBala(X,Y+(H/2)+4,pdireccion);
		cont_balas++;
		if (arreglo!=NULL)
			delete arreglo;
		arreglo=auxiliar;
	}
}

void CPlayer::Eliminar_Balas()
{
	int cantidad=0;
	for(int i=0;i<cont_balas;i++)
		cantidad+=arreglo[i]->Retonar_Eliminar()? 1:0;
	CBala** auxiliar=new CBala*[cont_balas-cantidad];
	int h=0;
	if (auxiliar!=NULL)
	{
		for (int i=0;i<cont_balas;i++)
			if (!arreglo[i]->Retonar_Eliminar())
			{
				auxiliar[h]=arreglo[i];
				h++;
		    }
	cont_balas=cont_balas-cantidad;
	if (arreglo!=NULL)
		delete arreglo;
	arreglo=auxiliar;
	}
}

void CPlayer::Mover_Balas(System::Drawing::Graphics ^gr)
{
	for (int i=0;i<cont_balas;i++)
		arreglo[i]->Mover(gr);
	Eliminar_Balas();
}
	
CBala* CPlayer::Retornar_Bala(int indice)
{
	return arreglo[indice];
}

int CPlayer::Retornar_Cantidad_Balas(){ return cont_balas;}

void CPlayer::setPoder()
{
	if(poder)
		poder=false;
	else
		poder=true;
}
bool CPlayer::getPoder(){return poder;}