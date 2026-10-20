#include "Paciente.h"
#include <iostream>


Paciente::Paciente(string n, int e, string i, double t, int pr, int dol, string tipo, bool tr, bool sn, bool rq, int di) : Persona(n,e){
	
	this->id = i;
	this->temperatura = t;
	this->presion = pr;
	this->dolor = dol;
	this->tipoDolor = tipo;
	this->trauma = tr;
	this->sintomasNeuro = sn;
	this->requiereCirugia = rq;
	this->diashospital = di;
	
}

Paciente::~Paciente(){
}


string Paciente::getId(){
	return id;
}

string Paciente::getServicio(){
	return servicio;
}

void Paciente::mostrar_info(){
	cout<<"ID= "<<id<<"||"<<"NOMBRE= "<<getNombre()<<"||"<<"EDAD= "<<getEdad()<<"||"<<"SERVICIO= "<<getServicio()<<endl;
}

double Paciente::getTemperatura(){
	return temperatura;
}
int Paciente::getPresion(){
	return presion;
}
int Paciente::getDolor(){
	return dolor;
}
string Paciente::getTipodolor(){
	return tipoDolor;
}
bool Paciente::getTrauma(){
	return trauma;
}
bool Paciente::getSintomasneuro(){
	return sintomasNeuro;
}
bool Paciente::getRequierecirugia(){
	return requiereCirugia;
}
int Paciente::getDiashospital(){
	return diashospital;
}

void Paciente::setServicio(string s){

	servicio = s;
}

