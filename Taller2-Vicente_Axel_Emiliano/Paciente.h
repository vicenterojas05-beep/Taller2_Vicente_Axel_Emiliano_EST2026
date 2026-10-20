#include "Persona.h"
#pragma once

class Paciente: public Persona{
	
	private:
		string id;
		string servicio;
		double temperatura;
		int presion;
		int dolor;
		string tipoDolor;
		bool trauma;
		bool sintomasNeuro;
		bool requiereCirugia;
		int diashospital;
		
	public:
		
		Paciente(string n, int e, string i, double t, int pr, int dol, string tipo, bool tr, bool sn, bool rq, int di);
		~Paciente() override;
		
		string getId();
		string getServicio();
		double getTemperatura();
		int getPresion();
		int getDolor();
		string getTipodolor();
		bool getTrauma();
		bool getSintomasneuro();
		bool getRequierecirugia();
		int getDiashospital();
		void mostrar_info();
		void setServicio(string s);
	
	
};
