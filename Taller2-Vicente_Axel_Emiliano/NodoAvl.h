#include "Paciente.h"


class NodoAvl{

private:

NodoAvl* izq;
NodoAvl* der;
Paciente* paciente;
int altura;

public:

NodoAvl(Paciente* p);
~NodoAvl();

NodoAvl* getIzq();
NodoAvl* getDer();
Paciente* getPaciente();
int getAltura();

void setIzq(NodoAvl* i);
void setDer(NodoAvl* d);
void setAltura(int alt);
void setPaciente(Paciente* p);
};
