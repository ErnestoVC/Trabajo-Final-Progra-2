#pragma once
#include "Objetos.h" 
using namespace System;
using namespace System::Drawing;

class CEnemigo2:public CObjetos 
{
public:
	CEnemigo2(int px);
	~CEnemigo2();

	void Calcular_W_H(Bitmap ^bmp);
	void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp);
	void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp);

private:

};

CEnemigo2::CEnemigo2(int px):CObjetos()
{
	Random r;
	Y=350;
	X=px;
	if(r.Next(2)==0) 
		dx=6;
	else
		dx=-6;
}

CEnemigo2::~CEnemigo2(){}

void CEnemigo2::Calcular_W_H(Bitmap ^bmp)
{
	W= bmp->Width/10;
	H= bmp->Height/2;
}
void CEnemigo2::Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	if(X<-1500 || X>2500)
		eliminar=true;
	Calcular_W_H(bmp);
	if(dx>0)
		iH=0;
	else
		iH=1;
	iW++;
	if(iW>9)
	{
		iW=0;
	}
	Rectangle porcion=Rectangle(iW*W,iH*H,W,H);
	gr->DrawImage(bmp,X,Y,porcion,GraphicsUnit::Pixel);
}
void CEnemigo2::Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	X+=dx;
	Mostrar(gr,bmp);
}