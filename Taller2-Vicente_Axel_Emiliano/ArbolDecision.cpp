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
string ArbolDecision::evaluarRecursivo(NodoDecision* nodo, Paciente* p) {
    if (nodo == nullptr) return "Error";

    // si no tiene hijos es una hoja (servicio)
    if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
        return nodo->dato; // retorna el nombre del servicio
    }

    // usamos ifs para preguntarle al nodo que pregunta tiene jejej
    if (nodo->dato == "Pregunta_Edad") {
        if (p->getEdad() < 15){
            return evaluarRecursivo(nodo->izquierdo, p);
        }
        else {
            return evaluarRecursivo(nodo->derecho, p);
        }
    }
    
    if (nodo->dato == "Pregunta_Cirugia") {
        if (p->getRequierecirugia() == 1){
            return evaluarRecursivo(nodo->izquierdo, p);
        } 
        else{
            return evaluarRecursivo(nodo->derecho, p);   
        } 
    }
    
    if (nodo->dato == "Pregunta_Trauma") {
        if (p->getTrauma() == 1) {
            return evaluarRecursivo(nodo->izquierdo, p);
        }
        else {
            return evaluarRecursivo(nodo->derecho, p);
        }
    }
    
    if (nodo->dato == "Pregunta_Neuro") {
        if (p->getSintomasneuro() == 1) {
            return evaluarRecursivo(nodo->izquierdo, p);
        }
        else {
            return evaluarRecursivo(nodo->derecho, p);
        }
    }
    
    if (nodo->dato == "Pregunta_Pecho") {
        if (p->getTipodolor() == "pecho") {
            return evaluarRecursivo(nodo->izquierdo, p);
        }
        else {
            return evaluarRecursivo(nodo->derecho, p);
        }
    }
    
    if (nodo->dato == "Pregunta_Urgencia") {
        if (p->getDolor() >= 8 || p->getTemperatura() >= 39.0) {
            return evaluarRecursivo(nodo->izquierdo, p);
        }
        else {
            return evaluarRecursivo(nodo->derecho, p);
        }
    }
    
    if (nodo->dato == "Pregunta_Dias") {
        if (p->getDiashospital() >= 1) {
            return evaluarRecursivo(nodo->izquierdo, p);
        }
        else {
            return evaluarRecursivo(nodo->derecho, p);
        }
    }

    return "Error";
}