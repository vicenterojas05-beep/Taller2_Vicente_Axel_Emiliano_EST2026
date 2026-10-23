
#include "NodoDecision.h"
#include "Paciente.h"

class ArbolDecision {
private:
    NodoDecision* raiz;
    
    // funcion recursiva que recorre los punteros 
    string evaluarRecursivo(NodoDecision* nodo, Paciente* p, string& ruta);
    
    // funcion destructora
    void destruirArbol(NodoDecision* nodo);

public:
    ArbolDecision();
    ~ArbolDecision();

    // funcion que se llamara en el main proablemente 
    string clasificarPaciente(Paciente* p, string& ruta);
};
