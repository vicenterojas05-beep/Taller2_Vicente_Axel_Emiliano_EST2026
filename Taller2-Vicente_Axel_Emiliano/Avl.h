
#include "NodoAvl.h"
#include <string>
#include <iostream>

using namespace std;

class Avl {
private:
    NodoAvl* raiz;
    int maximo(int a, int b); //por si hay problemas al incluir la libreria alghorithm
    // para el balanceo
    int obtenerAltura(NodoAvl* nodo);
    int obtenerFactorBalance(NodoAvl* nodo);
    
    // rotaciones
    NodoAvl* rotacionDerecha(NodoAvl* y);
    NodoAvl* rotacionIzquierda(NodoAvl* x);

    
    NodoAvl* insertarRecursivo(NodoAvl* nodo, Paciente* p);
    NodoAvl* buscarRecursivo(NodoAvl* nodo, string id);
    NodoAvl* eliminarRecursivo(NodoAvl* nodo, string id); 
    
    // recorridos
    void inordenRecursivo(NodoAvl* nodo);
    void preordenRecursivo(NodoAvl* nodo);
    void postordenRecursivo(NodoAvl* nodo);

    // destruccion total jej 
    void destruirArbol(NodoAvl* nodo);

public:
    Avl();
    ~Avl();

    void insertar(Paciente* p);
    Paciente* buscar(string id);
    void eliminar(string id);
    
    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();
};

