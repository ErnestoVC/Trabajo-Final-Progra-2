#pragma once
#include <stdio.h> // con esta libreria utilizamos NULL
#include <time.h> // con esta libreria podemos utilizar la funcion time(NULL) que nos devuelve el valor de la hora en segundos
#include <stdlib.h> // con esta libreria podemos usar las funciones srand y rand para obtener numeros al azar dentro de un rango

using namespace System;
using namespace System::Drawing;

//ESTA ES LA CLASE PADRE Y SUS CLASES HIJOS SON "enemigo1, enemigo2, Llave, Rayo"
//SE UTILIZA HERENCIA

class CObjetos
{
protected:
	//DECLARACION DE LOS ATRIBUTOS DE ESTA CLASE
	int X,Y,dx,dy;
	int iH,iW,H,W;
	bool eliminar;

public:
	CObjetos();
	~CObjetos();
	
	//DECARACION DE LOS METODOS DE ESTA CLASE
	void setX(int nuevo); 
	void setY(int nuevo); 
	int getX(); 
	int getY(); 
	int getW(); 
	int getH(); 
	bool getEliminar();
	void setEliminar(bool nuevo);
	virtual void Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp);
	virtual void Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp);
	virtual void Calcular_W_H(System::Drawing::Bitmap ^bmp);

};

CObjetos::CObjetos()
{
	//INICIALIZAMOS ATRIBUTOS
	X= rand()%770; //OBTIENE UN NUMERO AL AZAR DE 0 HASTA 769
	Y=0;
	dy=dx=0;
	iH=iW=W=H=0;
	eliminar=false;
}
CObjetos::~CObjetos(){} //DESTRUCTOR DE LA CLASE

void CObjetos::setX(int nuevo){	X=nuevo;} //MODIFICA LA VARIABLE X
void CObjetos::setY(int nuevo){	Y=nuevo;} //MODIFICA LA VARIABLE Y
int CObjetos::getX(){	return X;} //DEVUELVE LA VARIABLE X
int CObjetos::getY(){	return Y;} //DEVUELVE LA VARIABLE Y
int CObjetos::getW(){	return W;} //DEVUELVE LA VARIABLE W
int CObjetos::getH(){	return H;} //DEVUELVE LA VARIABLE H
bool CObjetos::getEliminar(){ return eliminar; }
void CObjetos::setEliminar(bool nuevo){ eliminar=nuevo; }
void CObjetos::Mover(Graphics ^gr, System::Drawing::Bitmap ^bmp){}
void CObjetos::Mostrar(Graphics ^gr, System::Drawing::Bitmap ^bmp){}
void CObjetos::Calcular_W_H(System::Drawing::Bitmap ^bmp){}