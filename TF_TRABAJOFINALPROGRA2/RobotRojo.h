#pragma once
#include "Objetos.h" //SE INGRESA LA LIBRERIA DE SU CLASE PADRE

class CRobotRojo:public CObjetos //SE HACE REFERENCIA A QUE ESTA CLASE ES UNA CLASE HIJO de la clase EXTRAS
{
public:
	CRobotRojo(int px);
	~CRobotRojo(void);
		
	void Calcular_W_H(Bitmap ^bmp);
	void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp);
	void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp);

private:

};

CRobotRojo::CRobotRojo(int px):CObjetos()
{
	Random r;
	Y=515;
	X=px;
	if(r.Next(2)==0)
		dx=2;
	else
		dx=-2;
}
CRobotRojo::~CRobotRojo(void){}

void CRobotRojo::Calcular_W_H(Bitmap ^bmp)
{
	W= bmp->Width/10;
	H= bmp->Height/2;
}
void CRobotRojo::Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp)
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
void CRobotRojo::Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	X+=dx;
	Mostrar(gr,bmp);
}