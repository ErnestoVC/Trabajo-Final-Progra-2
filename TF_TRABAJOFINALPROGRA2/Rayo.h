#pragma once
#include "Objetos.h" 


class CRayo:public CObjetos 
{
public:
	CRayo(int px);
	~CRayo();

	void Calcular_W_H(Bitmap ^bmp);
	void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp);
	void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp);

private:

};

CRayo::CRayo(int px):CObjetos()
{
	X=px;
	Y=380;
}
CRayo::~CRayo(){}

void CRayo::Calcular_W_H(Bitmap ^bmp)
{
	W= bmp->Width;
	H=bmp->Height;
}
void CRayo::Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	Calcular_W_H(bmp);
	Rectangle porcion=Rectangle(iW*W,iH*H,W,H);
	gr->DrawImage(bmp,X,Y,porcion,GraphicsUnit::Pixel);
}
void CRayo::Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp)
{
	Mostrar(gr,bmp);
}