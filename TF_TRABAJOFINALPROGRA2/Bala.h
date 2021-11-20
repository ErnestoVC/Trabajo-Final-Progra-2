#pragma once
#include "Player.h"

using namespace System::Drawing;

 class CBala
{	
private:
	int X;
	int Y;
	int dx;
	int radio;
	bool eliminar;

public:
	CBala(void);
	~CBala(void);
	CBala(int pX, int pY, int pdireccion);

	void Mover(Graphics ^gr);
	void Mostrar(Graphics ^gr);
	
	int Retornar_X();
	int Retornar_Y();
	int Retornar_W();
	int Retornar_H();

	bool Retonar_Eliminar();
	void Cambiar_Eliminar(bool nuevo);

};


int CBala::Retornar_X()
{
	return X;
}
int CBala::Retornar_Y()
{
	return Y;
}
int CBala::Retornar_W()
{
	return radio;
}
int CBala::Retornar_H()
{
	return radio;
}

CBala::CBala(void){}
CBala::~CBala(void){}
CBala::CBala(int pX, int pY, int pdireccion){
		eliminar=false;
		X=pX;
		Y=pY;
		dx=pdireccion*10;
		radio=5;
	}

void CBala::Mover(System::Drawing::Graphics ^gr)
{
	if(X<0 || X>800)
		eliminar=true;
	X+=dx;
	Mostrar(gr);
}

void CBala::Mostrar(System::Drawing::Graphics ^gr)
{
	//gr->DrawEllipse(gcnew Pen(Color::Black),X,Y,radio,radio);
	gr->FillEllipse(Brushes::Red,X,Y,radio,radio);
}
	
bool CBala::Retonar_Eliminar()
{
	return eliminar;
}
	
void CBala::Cambiar_Eliminar(bool nuevo)
{
	eliminar=nuevo;
}