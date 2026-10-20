
#include <string>

using namespace std;

class NodoDecision {
public:
    string dato; // puede guardar una pregunta o un servicio
    NodoDecision* izquierdo; // cuando la respuesta es si
    NodoDecision* derecho;   // cuando la respuesta es no

    
    NodoDecision(string d);
};
