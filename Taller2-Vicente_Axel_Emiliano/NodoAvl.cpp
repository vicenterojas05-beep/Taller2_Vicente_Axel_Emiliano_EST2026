#include "NodoAvl.h"


NodoAvl::NodoAvl(Paciente* p){
    paciente = p;
    izq= nullptr;
    der=nullptr;
    altura=1;
}

NodoAvl::~NodoAvl(){
}

void NodoAvl::setDer(NodoAvl* d){
    der=d;
}
void NodoAvl::setIzq(NodoAvl* i){
    izq=i;
}

NodoAvl* NodoAvl::getDer(){
    return der;
}

NodoAvl* NodoAvl::getIzq(){
    return izq;
}

 void NodoAvl::setAltura(int alt){
    altura = alt;
}

int NodoAvl::getAltura(){
    return altura;
}

void NodoAvl::setPaciente(Paciente* p){
    paciente = p;
}


Paciente* NodoAvl::getPaciente(){
    return paciente;
}


