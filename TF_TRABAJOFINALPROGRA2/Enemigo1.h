#pragma once
#include "Objetos.h"

class CEnemigo1:public CObjetos 
{
public:
	CEnemigo1(int px);
	~CEnemigo1(void);
		
	void Calcular_W_H(Bitmap ^bmp);
	void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp);
	void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp);

private:

};

CEnemigo1::CEnemigo1(int px):CObjetos()
{
	Random r;
	Y=350;
	X=px;
	if(r.Next(2)==0)
		dx=2;
	else
		dx=-2;
}
CEnemigo1::~CEnemigo1(void){}

void CEnemigo1::Calcular_W_H(Bitmap ^bmp)
{
	W= bmp->Width/10;
	H= bmp->Height/2;
}
void CEnemigo1::Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp)
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
void CEnemigo1::Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	X+=dx;
	Mostrar(gr,bmp);
}