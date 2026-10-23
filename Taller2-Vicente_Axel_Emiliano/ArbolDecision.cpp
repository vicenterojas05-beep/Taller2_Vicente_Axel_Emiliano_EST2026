#include "ArbolDecision.h"
#include <iostream>

ArbolDecision::ArbolDecision() {
    // nodos con las preguntas
    raiz = new NodoDecision("Pregunta_Edad");
    
    NodoDecision* nCirugia = new NodoDecision("Pregunta_Cirugia");
    NodoDecision* nTrauma = new NodoDecision("Pregunta_Trauma");
    NodoDecision* nNeuro = new NodoDecision("Pregunta_Neuro");
    NodoDecision* nDolorPecho = new NodoDecision("Pregunta_Pecho");
    NodoDecision* nFiebreDolor = new NodoDecision("Pregunta_Urgencia");
    NodoDecision* nDias = new NodoDecision("Pregunta_Dias");

    // todos los servicios serian hojas
    NodoDecision* sPediatria = new NodoDecision("Pediatria");
    NodoDecision* sCirugia = new NodoDecision("Cirugia");
    NodoDecision* sTraumatologia = new NodoDecision("Traumatologia");
    NodoDecision* sNeurologia = new NodoDecision("Neurologia");
    NodoDecision* sCardiologia = new NodoDecision("Cardiologia");
    NodoDecision* sUrgencias = new NodoDecision("Urgencias");
    NodoDecision* sHospitalizacion = new NodoDecision("Hospitalizacion");
    NodoDecision* sMedicinaGen = new NodoDecision("Medicina General");

    // izquierda si, derecha no
    raiz->izquierdo = sPediatria;
    raiz->derecho = nCirugia;

    nCirugia->izquierdo = sCirugia;
    nCirugia->derecho = nTrauma;

    nTrauma->izquierdo = sTraumatologia;
    nTrauma->derecho = nNeuro;

    nNeuro->izquierdo = sNeurologia;
    nNeuro->derecho = nDolorPecho;

    nDolorPecho->izquierdo = sCardiologia;
    nDolorPecho->derecho = nFiebreDolor;

    nFiebreDolor->izquierdo = sUrgencias;
    nFiebreDolor->derecho = nDias;

    nDias->izquierdo = sHospitalizacion;
    nDias->derecho = sMedicinaGen;
}



// aqui se evalua al paciente y se hacen las preguntas
string ArbolDecision::evaluarRecursivo(NodoDecision* nodo, Paciente* p, string& ruta) {
    if (nodo == nullptr) return "Error";

    // si no tiene hijos es una hoja (servicio)
    if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
        return nodo->dato; // retorna el nombre del servicio
    }

    // usamos ifs para preguntarle al nodo que pregunta tiene jejej
    if (nodo->dato == "Pregunta_Edad") {
        if (p->getEdad() < 15){
            ruta+="Edad < 15-->";
            return evaluarRecursivo(nodo->izquierdo, p, ruta);
        }
        else {

            ruta+="Edad >= 15 ---> ";
            return evaluarRecursivo(nodo->derecho, p, ruta);
        }
    }
    
    if (nodo->dato == "Pregunta_Cirugia") {
        if (p->getRequierecirugia() == 1){
            ruta+="Cirugia: SI --->";
            return evaluarRecursivo(nodo->izquierdo, p, ruta);
        } 
        else{

            ruta+="Cirugia: NO ---> ";
            return evaluarRecursivo(nodo->derecho, p, ruta);   
        } 
    }
    
    if (nodo->dato == "Pregunta_Trauma") {
        if (p->getTrauma() == 1) {
            ruta+="Trauma: SI ---> ";
            return evaluarRecursivo(nodo->izquierdo, p, ruta);
        }
        else {
            ruta+="Trauma: NO --->";

            return evaluarRecursivo(nodo->derecho, p, ruta);
        }
    }
    
    if (nodo->dato == "Pregunta_Neuro") {
        if (p->getSintomasneuro() == 1) {

            ruta+="Sintomas neurologicos: SI ---> ";
            return evaluarRecursivo(nodo->izquierdo, p, ruta);
        }
        else {
            ruta+="Sintomas neurologicos: NO ---> ";
            return evaluarRecursivo(nodo->derecho, p, ruta);
        }
    }
    
    if (nodo->dato == "Pregunta_Pecho") {
        if (p->getTipodolor() == "pecho") {
            ruta+="Dolor pecho: SI --->";
            return evaluarRecursivo(nodo->izquierdo, p, ruta);
        }
        else {
            ruta+="Dolor pecho: NO --->";
            return evaluarRecursivo(nodo->derecho, p, ruta);
        }
    }
    
    if (nodo->dato == "Pregunta_Urgencia") {
        if (p->getDolor() >= 8 || p->getTemperatura() >= 39.0) {
            ruta+="Urgencia: SI ---> ";
            return evaluarRecursivo(nodo->izquierdo, p, ruta);
        }
        else {
            ruta+="Urgencia: NO ---> ";
            return evaluarRecursivo(nodo->derecho, p, ruta);
        }
    }
    
    if (nodo->dato == "Pregunta_Dias") {
        if (p->getDiashospital() >= 1) {
            ruta+="Dias Hospital: "+to_string(p->getDiashospital());
            return evaluarRecursivo(nodo->izquierdo, p, ruta);
        }
        else {
            ruta+="Dias Hospital: 0";
            return evaluarRecursivo(nodo->derecho, p, ruta);
        }
    }

    return "Error";
}

string ArbolDecision::clasificarPaciente(Paciente* p, string& ruta){

    return evaluarRecursivo(raiz, p, ruta);
}