#pragma once
#include "Objetos.h" 

class CLlave:public CObjetos 
{
public:
	CLlave(int px);
	~CLlave();

	void Calcular_W_H(Bitmap ^bmp);
	void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp);
	void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp);

private:

};

CLlave::CLlave(int px):CObjetos()
{
	X=px;
	Y=380;
}
CLlave::~CLlave(){}

void CLlave::Calcular_W_H(Bitmap ^bmp)
{
	W= bmp->Width;
	H=bmp->Height;
}
void CLlave::Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	Calcular_W_H(bmp);
	Rectangle porcion=Rectangle(iW*W,iH*H,W,H);
	gr->DrawImage(bmp,X,Y,porcion,GraphicsUnit::Pixel);
}
void CLlave::Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	Mostrar(gr,bmp);
}