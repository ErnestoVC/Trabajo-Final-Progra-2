#pragma once
#include <stdio.h>
#include "Player.h"
using namespace System::Drawing;
using namespace System;

class CFondo
{
public:
	CFondo(int px, int py);
	~CFondo(void);

	void Calcular_W_H(Bitmap ^bmp); 
	void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp); 
	void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp, CPlayer* nuevo); 

	void setX(int nuevo);
	void setY(int nuevo);
	int getX();
	int getY();
	int getW();
	int getH();
	void Set_Xplayer(CPlayer* objPlayer);
	
private:
	int X,Y,dx;
	int Xplayer;
	int W,H;

};

CFondo::CFondo(int px, int py){ X=px, Y=py; Xplayer=0;} 
CFondo::~CFondo(void){} 

void CFondo::Calcular_W_H(Bitmap ^bmp)
{
	W= bmp->Width; 
	H= bmp->Height; 
}
void CFondo::Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	Calcular_W_H(bmp); 
	gr->DrawImage(bmp,X,Y,W,H);
}
void CFondo::Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp, CPlayer* nuevo)
{
	
	Set_Xplayer(nuevo);

	if(Xplayer<30 && X+15<-250)
			X+=15;
		else
			if(Xplayer>700 && X-15>-1400)
				X-=15;
	Mostrar(gr,bmp);
}

void CFondo::setX(int nuevo){	X=nuevo;} 
void CFondo::setY(int nuevo){	Y=nuevo;} 
int CFondo::getX(){	return X;} 
int CFondo::getY(){	return Y;} 
int CFondo::getW(){	return W;} 
int CFondo::getH(){	return H;} 
void CFondo::Set_Xplayer(CPlayer* objPlayer)
{
	Xplayer = objPlayer->getX();
}