#pragma once
#include "Objetos.h" //SE INGRESA LA LIBRERIA DE SU CLASE PADRE

using namespace System;
using namespace System::Drawing;

class CRobotGris:public CObjetos //SE HACE REFERENCIA A QUE ESTA CLASE ES UNA CLASE HIJO de la clase EXTRAS
{
public:
	CRobotGris(int px);
	~CRobotGris();

	void Calcular_W_H(Bitmap ^bmp);
	void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp);
	void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp);

private:

};

CRobotGris::CRobotGris(int px):CObjetos()
{
	Random r;
	Y=515;
	X=px;
	if(r.Next(2)==0) //elegie al azar si el enemigo se movera hacia la izquiera o la derecha
		dx=6;
	else
		dx=-6;
}

CRobotGris::~CRobotGris(){}

void CRobotGris::Calcular_W_H(Bitmap ^bmp)
{
	W= bmp->Width/10;
	H= bmp->Height/2;
}
void CRobotGris::Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
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
void CRobotGris::Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	X+=dx;
	Mostrar(gr,bmp);
}