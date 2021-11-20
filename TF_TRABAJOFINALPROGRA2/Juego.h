#pragma once
#include "Fondo.h"
#include "Player.h"
#include "arrEnemigo1.h"
#include "arrEnemigo2.h"
#include "arrLlave.h"
#include "arrRayo.h"

using namespace System;
using namespace System::Drawing;

class CJuego
{
public:
	CJuego(void);
	~CJuego(void);

	//DECLARAION DE METODOS
	void Crear_Fondo(int px, int py);
	void Crear_Personaje(int px, int py);
	void Disparar();
	void Crear_Enemigos();
	void Crear_Objetos();
	void Insertar_Enemigos1();
	void Insertar_Enemigos2();
	void Insertar_Objeto1(int x);
	void Insertar_Objeto2(int x);
	void Mover(Graphics ^gr, Bitmap ^Fondo, Bitmap ^Personaje, Bitmap ^Enemigo1, Bitmap ^Enemigo2, Bitmap ^Reparar, Bitmap ^Rayo, Direccion tecla_pulsada, Bitmap ^bmpGover);
	CPlayer* Retornar_Player();
	void Desplazamiento();

	bool Colision_Enemigo1(CBala* objbala, CEnemigo1* objEnemigo1);
	void Verificar_Colision_Enemigo1();
	bool Colision_Enemigo2(CBala* objbala, CEnemigo2* objEnemigo2);
	void Verificar_Colision_Enemigo2();
	bool Colision_Llave(CPlayer* objPersonaje, CLlave* objLlave);
	void Verificar_Colision_Llave();
	bool Colision_Rayo(CPlayer* objPersonaje, CRayo* objRayo);
	void Verificar_Colision_Rayo();
	bool Colision_Personaje_Enemigo1(CPlayer* objPersonaje, CEnemigo1* objEnemigo1);
	void Verificar_Colision_Personaje_Enemigo1();
	bool Colision_Personaje_Enemigo2(CPlayer* objPersonaje, CEnemigo2* objEnemigo2);
	void Verificar_Colision_Personaje_Enemigo2();

	void Estadisticas(Graphics ^gr);

	int getEnergia();
	void setEnergia();
	void setNivel();

private:
	//DECLARACION DE ATRIBUTOS
	CFondo* objFondo;
	CPlayer* objPlayer;
	CarrEnemigo1* objarrEnemigo1;
	CarrEnemigo2* objarrEnemigo2;
	CarrLlave* objarrLlave;
	CarrRayo* objarrRayo;
	int maxEne1, maxEne2, maxLve, maxRay;
	int vida, energia, puntaje, nivel;
	double auxVida;

};

CJuego::CJuego(void)
{ 
	
	objFondo=NULL;
	objPlayer=NULL;
	objarrEnemigo1=NULL;
	objarrEnemigo2=NULL;
	objarrLlave=NULL;
	objarrRayo=NULL;
	nivel=1;
	vida=5;
	auxVida=vida;
	puntaje=0;
	energia=10;
	maxEne1=maxEne2=maxLve=maxRay=0;

}
CJuego::~CJuego(void)
{

	if(objFondo!=NULL)
		delete objFondo;
	if(objPlayer!=NULL)
		delete objPlayer;
	if(objarrEnemigo1!=NULL)
		delete objarrEnemigo1;
	if(objarrEnemigo2!=NULL)
		delete objarrEnemigo2;
	if(objarrLlave!=NULL)
		delete objarrLlave;
	if(objarrRayo!=NULL)
		delete objarrRayo;
	
}

void CJuego::Crear_Fondo(int px, int py)
{
	if(objFondo==NULL)
	{
		objFondo = new CFondo(px,py);
	}
}
void CJuego::Crear_Personaje(int px, int py)
{
	if(objPlayer==NULL) 
	{
		objPlayer = new CPlayer(px,py);
	}
}

void CJuego::Disparar()
{
	if(objPlayer!=NULL)
		objPlayer->Disparar();
}

void CJuego::Crear_Enemigos()
{
	if(objarrEnemigo1==NULL)
		objarrEnemigo1 = new CarrEnemigo1();
	if(objarrEnemigo2==NULL)
		objarrEnemigo2 = new CarrEnemigo2();
}

void CJuego::Crear_Objetos()
{
	if(objarrLlave==NULL)
		objarrLlave = new CarrLlave();
	if(objarrRayo==NULL)
		objarrRayo = new CarrRayo();
}

void CJuego::Insertar_Enemigos1()
{
	
	if(nivel==1) maxEne1=4;
	else if(nivel==2) maxEne1=6;
	else if(nivel==3) maxEne1=8;
	else if(nivel==4) maxEne1=10;
	if(objarrEnemigo1!=NULL)
		objarrEnemigo1->Insertar(maxEne1);
}
void CJuego::Insertar_Enemigos2()
{
	
	if(nivel==1) maxEne2=0;
	else if(nivel==2) maxEne2=4;
	else if(nivel==3) maxEne2=6;
	else if(nivel==4) maxEne2=8;
	if(objarrEnemigo2!=NULL)
		objarrEnemigo2->Insertar(maxEne2);
}
void CJuego::Insertar_Objeto1( int x)
{
	
	if(nivel==1) maxLve=1;
	else if(nivel==2) maxLve=2;
	else if(nivel==3) maxLve=3;
	else if(nivel==4) maxLve=5;
	objarrLlave->Insertar(maxLve,x);
}
void CJuego::Insertar_Objeto2( int x)
{
	
	if(nivel==1) maxRay=0;
	else if(nivel==2) maxRay=1;
	else if(nivel==3) maxRay=1;
	else if(nivel==4) maxRay=1;
	objarrRayo->Insertar(maxRay,x);
}

void CJuego::Mover(Graphics ^gr, Bitmap ^Fondo, Bitmap ^Personaje, Bitmap ^Enemigo1, Bitmap ^Enemigo2, Bitmap ^Reparar, Bitmap ^Rayo, Direccion tecla_pulsada, Bitmap ^bmpGover)
{
	Desplazamiento();
	if(objFondo!=NULL) 
		objFondo->Mover(gr,Fondo,objPlayer);
	if(objPlayer!=NULL) 
	{
		objPlayer->Mover(gr,Personaje,tecla_pulsada);
		objPlayer->Mover_Balas(gr);
		if(objarrEnemigo1!=NULL)Verificar_Colision_Enemigo1();
		if(objarrEnemigo2!=NULL)Verificar_Colision_Enemigo2();
		if(objarrLlave!=NULL)Verificar_Colision_Llave();
		if(objarrRayo!=NULL)Verificar_Colision_Rayo();
		if(objarrEnemigo1!=NULL)Verificar_Colision_Personaje_Enemigo1();
		if(objarrEnemigo2!=NULL)Verificar_Colision_Personaje_Enemigo2();
	}
	if(objarrEnemigo1!=NULL)
		objarrEnemigo1->Mover_Todos(gr,Enemigo1);
	if(objarrEnemigo2!=NULL)
		objarrEnemigo2->Mover_Todos(gr,Enemigo2);
	if(objarrLlave!=NULL)
		objarrLlave->Mover_Todos(gr,Reparar);
	if(objarrRayo!=NULL)
		objarrRayo->Mover_Todos(gr,Rayo);
	if(vida<1)
		{
			objPlayer->setX(200);
			objPlayer->setY(-200);
		Rectangle porcion=Rectangle(0,0,bmpGover->Width,bmpGover->Height);
		gr->DrawImage(bmpGover,-150,-50,porcion,GraphicsUnit::Pixel);
	}
	Estadisticas(gr);
	setNivel();
	if(energia==0)
		auxVida-=0.025;
}

CPlayer* CJuego::Retornar_Player(){ return objPlayer; }

void CJuego::Desplazamiento()
{
	int Xplayer=objPlayer->getX();
	int Xfondo=objFondo->getX();

	for(int i=0;i<objarrEnemigo1->Rotornar_Cantidad();i++)
	{
		if(Xplayer<30 && Xfondo+15<-250)
		 objarrEnemigo1->Retornar_Objeto(i)->setX(objarrEnemigo1->Retornar_Objeto(i)->getX()+15);
			
		else
			if(Xplayer>700 && Xfondo-15>-1400)
				objarrEnemigo1->Retornar_Objeto(i)->setX(objarrEnemigo1->Retornar_Objeto(i)->getX()-15);
	}

	for(int i=0;i<objarrEnemigo2->Rotornar_Cantidad();i++)
	{
		if(Xplayer<30 && Xfondo+15<-250)
		 objarrEnemigo2->Retornar_Objeto(i)->setX(objarrEnemigo2->Retornar_Objeto(i)->getX()+15);
			
		else
			if(Xplayer>700 && Xfondo-15>-1400)
				objarrEnemigo2->Retornar_Objeto(i)->setX(objarrEnemigo2->Retornar_Objeto(i)->getX()-15);
	}

	for(int i=0;i<objarrLlave->Rotornar_Cantidad();i++)
	{
		if(Xplayer<30 && Xfondo+15<-250)
		 objarrLlave->Retornar_Objeto(i)->setX(objarrLlave->Retornar_Objeto(i)->getX()+15);
			
		else
			if(Xplayer>700 && Xfondo-15>-1400)
				objarrLlave->Retornar_Objeto(i)->setX(objarrLlave->Retornar_Objeto(i)->getX()-15);
	}

	for(int i=0;i<objarrRayo->Rotornar_Cantidad();i++)
	{
		if(Xplayer<30 && Xfondo+15<-250)
		 objarrRayo->Retornar_Objeto(i)->setX(objarrRayo->Retornar_Objeto(i)->getX()+15);
			
		else
			if(Xplayer>700 && Xfondo-15>-1400)
				objarrRayo->Retornar_Objeto(i)->setX(objarrRayo->Retornar_Objeto(i)->getX()-15);
	}

}

bool CJuego::Colision_Enemigo1(CBala *objbala, CEnemigo1 *objEnemigo1)
{
	if (objbala->Retornar_X()>objEnemigo1->getX()+ objEnemigo1->getW()  ||
		objbala->Retornar_Y()>objEnemigo1->getY()+ objEnemigo1->getH()  ||
		objEnemigo1->getX()>objbala->Retornar_X()+ objbala->Retornar_W()  ||
		objEnemigo1->getY()>objbala->Retornar_Y()+ objbala->Retornar_H())
		return false;
	else
		return true;
	}

void CJuego::Verificar_Colision_Enemigo1()
{
	for (int i=0;i<objarrEnemigo1->Rotornar_Cantidad();i++)
	{
		for (int j=0; j<objPlayer->Retornar_Cantidad_Balas();j++)
		{
			if (objPlayer->Retornar_Bala(j)->Retonar_Eliminar()==false   && objarrEnemigo1->Retornar_Objeto(i)->getEliminar()==false)
				if (Colision_Enemigo1(objPlayer->Retornar_Bala(j), objarrEnemigo1->Retornar_Objeto(i)))
				{
					puntaje+=100; 
					objarrEnemigo1->Retornar_Objeto(i)->setEliminar(true); 
					objPlayer->Retornar_Bala(j)->Cambiar_Eliminar(true); 
					
					
					Random r;
					if(r.Next(2)==0)
					{
						if(r.Next(2)==0)
						{}
						else
						{Insertar_Objeto1(objarrEnemigo1->Retornar_Objeto(i)->getX());}
					}
					else
					{
						if(r.Next(2)==0)
						{}
						else
						{Insertar_Objeto2(objarrEnemigo1->Retornar_Objeto(i)->getX());}
					}
				}
		}
	}
	
}

bool CJuego::Colision_Enemigo2(CBala *objbala, CEnemigo2 *objEnemigo2)
{
	if (objbala->Retornar_X()>objEnemigo2->getX()+ objEnemigo2->getW()  ||
		objbala->Retornar_Y()>objEnemigo2->getY()+ objEnemigo2->getH()  ||
		objEnemigo2->getX()>objbala->Retornar_X()+ objbala->Retornar_W()  ||
		objEnemigo2->getY()>objbala->Retornar_Y()+ objbala->Retornar_H())
		return false;
	else
		return true;
	}

void CJuego::Verificar_Colision_Enemigo2()
{
	for (int i=0;i<objarrEnemigo2->Rotornar_Cantidad();i++)
	{
		for (int j=0; j<objPlayer->Retornar_Cantidad_Balas();j++)
		{
			if (objPlayer->Retornar_Bala(j)->Retonar_Eliminar()==false   && objarrEnemigo2->Retornar_Objeto(i)->getEliminar()==false)
				if (Colision_Enemigo2(objPlayer->Retornar_Bala(j), objarrEnemigo2->Retornar_Objeto(i)))
				{
					puntaje+=175; 
					objarrEnemigo2->Retornar_Objeto(i)->setEliminar(true); 
					objPlayer->Retornar_Bala(j)->Cambiar_Eliminar(true); 

					
					Random r;
					if(r.Next(2)==0)
					{
						if(r.Next(2)==0)
						{}
						else
						{Insertar_Objeto1(objarrEnemigo2->Retornar_Objeto(i)->getX());}
					}
					else
					{
						if(r.Next(2)==0)
						{}
						else
						{Insertar_Objeto2(objarrEnemigo2->Retornar_Objeto(i)->getX());}
					}
				}
		}
	}
	
}

bool CJuego::Colision_Llave(CPlayer *objPersonaje, CLlave *objLlave)
{
	if (objPersonaje->getX()>objLlave->getX()+ objLlave->getW()  ||
		objPersonaje->getY()>objLlave->getY()+ objLlave->getH()  ||
		objLlave->getX()>objPersonaje->getX()+ objPersonaje->getW()  ||
		objLlave->getY()>objPersonaje->getY()+ objPersonaje->getH())
		return false;
	else
		return true;
}

void CJuego::Verificar_Colision_Llave()
{
	for (int i=0;i<objarrLlave->Rotornar_Cantidad();i++)
	{
			if (objarrLlave->Retornar_Objeto(i)->getEliminar()==false)
				if (Colision_Llave(objPlayer, objarrLlave->Retornar_Objeto(i)))
				{
					auxVida+=1.00; 
					puntaje+=10; 
					objarrLlave->Retornar_Objeto(i)->setEliminar(true); 
				}
	}
}

bool CJuego::Colision_Rayo(CPlayer *objPersonaje, CRayo *objRayo)
{
	if (objPersonaje->getX()>objRayo->getX()+ objRayo->getW()  ||
		objPersonaje->getY()>objRayo->getY()+ objRayo->getH()  ||
		objRayo->getX()>objPersonaje->getX()+ objPersonaje->getW()  ||
		objRayo->getY()>objPersonaje->getY()+ objPersonaje->getH())
		return false;
	else
		return true;
}

void CJuego::Verificar_Colision_Rayo()
{
	for (int i=0;i<objarrRayo->Rotornar_Cantidad();i++)
	{
			if (objarrRayo->Retornar_Objeto(i)->getEliminar()==false)
				if (Colision_Rayo(objPlayer, objarrRayo->Retornar_Objeto(i)))
				{
					energia+=5; 
					puntaje+=10;
					objarrRayo->Retornar_Objeto(i)->setEliminar(true); 
				}
	}
}

bool CJuego::Colision_Personaje_Enemigo1(CPlayer *objPersonaje, CEnemigo1 *objEnemigo1)
{
	if (objPersonaje->getX()>objEnemigo1->getX()+ objEnemigo1->getW()  ||
		objPersonaje->getY()>objEnemigo1->getY()+ objEnemigo1->getH()  ||
		objEnemigo1->getX()>objPersonaje->getX()+ objPersonaje->getW()  ||
		objEnemigo1->getY()>objPersonaje->getY()+ objPersonaje->getH())
		return false;
	else
		return true;
}

void CJuego::Verificar_Colision_Personaje_Enemigo1()
{
	for (int i=0;i<objarrEnemigo1->Rotornar_Cantidad();i++)
	{
			if (objarrEnemigo1->Retornar_Objeto(i)->getEliminar()==false)
				if (Colision_Personaje_Enemigo1(objPlayer, objarrEnemigo1->Retornar_Objeto(i)))
				{
					if(objPlayer->getPoder()==true)
					{
						objarrEnemigo1->Retornar_Objeto(i)->setEliminar(true); 
						auxVida-=1.0; 
					}
					else
						auxVida-=0.1; 
				}
	}
}

bool CJuego::Colision_Personaje_Enemigo2(CPlayer *objPersonaje, CEnemigo2 *objEnemigo1)
{
	if (objPersonaje->getX()>objEnemigo1->getX()+ objEnemigo1->getW()  ||
		objPersonaje->getY()>objEnemigo1->getY()+ objEnemigo1->getH()  ||
		objEnemigo1->getX()>objPersonaje->getX()+ objPersonaje->getW()  ||
		objEnemigo1->getY()>objPersonaje->getY()+ objPersonaje->getH())
		return false;
	else
		return true;
}

void CJuego::Verificar_Colision_Personaje_Enemigo2()
{
	for (int i=0;i<objarrEnemigo2->Rotornar_Cantidad();i++)
	{
			if (objarrEnemigo2->Retornar_Objeto(i)->getEliminar()==false)
				if (Colision_Personaje_Enemigo2(objPlayer, objarrEnemigo2->Retornar_Objeto(i)))
				{
					if(objPlayer->getPoder()==true)
					{
						objarrEnemigo2->Retornar_Objeto(i)->setEliminar(true); 
						auxVida-=1.0; 
					}
					else
						auxVida-=0.1; 
				}
	}
}

void CJuego::Estadisticas(Graphics ^gr) 
{

	String ^Vida="Vida: "+Convert::ToString(vida);

	String ^Energia="Energia: "+Convert::ToString(energia);

	String ^Nivel="Nivel: "+Convert::ToString(nivel);

	String ^Score="Puntaje: "+Convert::ToString(puntaje);

	Font ^drawfont = gcnew Font("Arial",15);
	SolidBrush ^drawbrush = gcnew SolidBrush(Color::LightGreen);

	vida=auxVida;
	
	gr->DrawString(Score,drawfont,drawbrush,50,5);
	gr->DrawString(Vida,drawfont,drawbrush,250,5);
	gr->DrawString(Energia,drawfont,drawbrush,450,5);
	gr->DrawString(Nivel,drawfont,drawbrush,650,5);

}

int CJuego::getEnergia(){return energia;}
void CJuego::setEnergia(){ if(vida>0)energia--;} 
void CJuego::setNivel() 
{
	if(puntaje>1200 && nivel==1) nivel=2;
	else if(puntaje>2500 && nivel==2) nivel=3;
	else if(puntaje>5000 && nivel==3) nivel=4;
}