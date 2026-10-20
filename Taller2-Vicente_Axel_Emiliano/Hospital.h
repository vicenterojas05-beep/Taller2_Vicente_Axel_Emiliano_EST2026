
#include "Avl.h"
#include "Paciente.h"

class Hospital {
public:
    //los 8 arboles
    Avl* urgencias;
    Avl* medicina_general;
    Avl* cardiologia;
    Avl* neurologia;
    Avl* traumatologia;
    Avl* cirugia;
    Avl* pediatria;
    Avl* hospitalizacion;

    Hospital();
    ~Hospital();

    //funcion para enviar al paciente a su servicio
    void ingresar_pacienteavl(Paciente* p); 
};
