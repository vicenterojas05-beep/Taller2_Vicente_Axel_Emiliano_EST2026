#include "Hospital.h"





Hospital::Hospital(){
    urgencias = new Avl();
    medicina_general=new Avl();
    hospitalizacion=new Avl();
    pediatria=new Avl();
    traumatologia=new Avl();
    neurologia=new Avl();
    cardiologia=new Avl();
    cirugia=new Avl();

}


void Hospital::ingresar_pacienteavl(Paciente* p) {
    string destino = p->getServicio();

    //simplemente lee el string y llama a la funcion Avl insertar
    if (destino == "Urgencias") urgencias->insertar(p);
    else if (destino == "Medicina General") medicina_general->insertar(p);
    else if (destino == "Cardiologia") cardiologia->insertar(p);
    else if (destino == "Neurologia") neurologia->insertar(p);
    else if (destino == "Traumatologia") traumatologia->insertar(p);
    else if (destino == "Cirugia") cirugia->insertar(p);
    else if (destino == "Pediatria") pediatria->insertar(p);
    else if (destino == "Hospitalizacion") hospitalizacion->insertar(p);
    else {
        cout << "Error: Servicio desconocido." << endl;
    }
}
