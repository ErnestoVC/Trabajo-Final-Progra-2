
#pragma once
#include <time.h> 
#include "Juego.h"

namespace TF_TRABAJOFINALPROGRA2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			
			Yplayer=0;
			PoderPlayer=false;

			bmpPersonaje = gcnew Bitmap("personaje_.png"); 
			bmpFondo = gcnew Bitmap("fondo.png");
			bmpEnemigo1 = gcnew Bitmap("enemigo1.png");
			bmpEnemigo2 = gcnew Bitmap("enemigo2.png");
			bmpReparar = gcnew Bitmap("reparar.png");
			bmpRayo = gcnew Bitmap("rayo.png");
			bmpGover = gcnew Bitmap("gover.png");

			objGame = new CJuego();
			objGame->Crear_Fondo(-800,-167);
			objGame->Crear_Personaje(300,350);
			objGame->Crear_Enemigos();
			objGame->Crear_Objetos();

			hora_inicial_enem1 = time(NULL); 
			hora_inicial_enem2 = time(NULL);
			hora_inicial_disminucionEnergia = time(NULL);

			tecla_pulsada = Direccion::ninguno; 

			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			delete bmpPersonaje;
			delete bmpFondo;
			delete bmpEnemigo1;
			delete bmpEnemigo2;
			delete bmpReparar;
			delete bmpRayo;
			delete bmpGover;
			delete objGame;
		}

	private:
		int Yplayer;
		bool PoderPlayer;

		
		Bitmap ^bmpPersonaje;
		Bitmap ^bmpFondo;
		Bitmap ^bmpEnemigo1;
		Bitmap ^bmpEnemigo2;
		Bitmap ^bmpReparar;
		Bitmap ^bmpRayo;
		Bitmap ^bmpGover;

		
		CJuego* objGame;

		
		time_t hora_inicial_enem1;
		time_t hora_inicial_enem2;
		time_t hora_inicial_disminucionEnergia;

		
		Direccion tecla_pulsada;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 446);
			this->ControlBox = false;
			this->MaximumSize = System::Drawing::Size(800, 485);
			this->MinimumSize = System::Drawing::Size(800, 485);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
		
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		{
			 
				 Graphics ^gr=this->CreateGraphics();
				 BufferedGraphicsContext ^bgc = BufferedGraphicsManager::Current;
				 BufferedGraphics ^bg = bgc->Allocate(gr,this->ClientRectangle);

				 
				 timer1->Enabled=false;
				 Yplayer=objGame->Retornar_Player()->getY();
				 PoderPlayer=objGame->Retornar_Player()->getPoder();

				
				 time_t hora_crear_enem1=time(NULL);
				 time_t hora_crear_enem2=time(NULL);
				 time_t hora_Actual_disminucionEnergia=time(NULL);


				 if(difftime(hora_crear_enem1,hora_inicial_enem1)>0.6)
				 {
					 objGame->Insertar_Enemigos1();
					 hora_inicial_enem1=time(NULL);
				 }
				 if(difftime(hora_crear_enem2,hora_inicial_enem2)>0.8)
				 {
					 objGame->Insertar_Enemigos2();
					 hora_inicial_enem2=time(NULL);
				 }
				 if(difftime(hora_Actual_disminucionEnergia,hora_inicial_disminucionEnergia)>2)//El personaje pierde energia cada 2 segundos
				 {
					 if(objGame->getEnergia()>0)
						objGame->setEnergia();
					 hora_inicial_disminucionEnergia=time(NULL);
				 }

				 ///-------------------------------///


				 objGame->Mover(bg->Graphics,bmpFondo,bmpPersonaje,bmpEnemigo1,bmpEnemigo2,bmpReparar,bmpRayo,tecla_pulsada,bmpGover);



				 
				 bg->Render(gr); 
				 
				 timer1->Enabled=true;

				 tecla_pulsada=Direccion::nosalto;

				 
				 delete bg;
				 delete bgc;
				 delete gr;
		}


private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		{
				if (e->KeyCode==Keys::Escape) this->Close(); 
				if (e->KeyCode==Keys::Left) tecla_pulsada=Direccion::izquierda;
				if (e->KeyCode==Keys::Right) tecla_pulsada=Direccion::derecha;
				if(PoderPlayer==false)
					if (e->KeyCode==Keys::Space) objGame->Disparar();
				if (e->KeyCode==Keys::X) objGame->Retornar_Player()->setPoder();
				if(Yplayer==350)
				{
					if (e->KeyCode==Keys::Down) tecla_pulsada=Direccion::ninguno; 
					if (e->KeyCode==Keys::Up) tecla_pulsada=Direccion::salto;
				}
		}
};
}
