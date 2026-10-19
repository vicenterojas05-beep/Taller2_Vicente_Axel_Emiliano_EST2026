#include "Avl.h"


    Avl::Avl(){
        raiz=nullptr;

    }
    Avl::~Avl(){
        destruirArbol(raiz);
    }

    int Avl::maximo(int a, int b){
        if(a>b){
            return a;
        }
        else{
            return b;
        }

    }
    int Avl::obtenerAltura(NodoAvl* nodo){
        if(nodo==nullptr){
            return 0;
        }

        return nodo->getAltura();
    }
    int Avl::obtenerFactorBalance(NodoAvl* nodo){
        if(nodo==nullptr){
            return 0;
        }
        
        return obtenerAltura(nodo->getIzq())-obtenerAltura(nodo->getDer());
    }
    

    //las 4 rotaciones
 
    NodoAvl* Avl::rotacionDerecha(NodoAvl* y){
        NodoAvl* x = y->getIzq();
        NodoAvl* T2 = x->getDer();

        // rotamos los punteros
        x->setDer(y);
        y->setIzq(T2);

        // actualizamos las alturas primero el de abajo y luego el de arriba x
        y->setAltura(maximo(obtenerAltura(y->getIzq()), obtenerAltura(y->getDer())) + 1);
        x->setAltura(maximo(obtenerAltura(x->getIzq()), obtenerAltura(x->getDer())) + 1);

        return x; // nueva raiz


    }
    NodoAvl* Avl::rotacionIzquierda(NodoAvl* x){
        NodoAvl* y = x->getDer();
        NodoAvl* T2 = y->getIzq();

        // rotamos los punteros
        y->setIzq(x);
        x->setDer(T2);

        // actualizamos las alturas
        x->setAltura(maximo(obtenerAltura(x->getIzq()), obtenerAltura(x->getDer())) + 1);
        y->setAltura(maximo(obtenerAltura(y->getIzq()), obtenerAltura(y->getDer())) + 1);

        return y;
    }


    //operaciones privadas y recursivas
    
    NodoAvl* Avl::insertarRecursivo(NodoAvl* nodo, Paciente* p){

        // caso base
    if (nodo == nullptr) {
        return new NodoAvl(p);
    }

    // comparamos los ids como strings
    if (p->getId() < nodo->getPaciente()->getId()) {
        nodo->setIzq(insertarRecursivo(nodo->getIzq(), p));
    } else if (p->getId() > nodo->getPaciente()->getId()) {
        nodo->setDer(insertarRecursivo(nodo->getDer(), p));
    } else {
        return nodo; // por si hay algun paciente duplicado
    }

    //actualizar altura
    nodo->setAltura(1 + maximo(obtenerAltura(nodo->getIzq()), obtenerAltura(nodo->getDer())));

    //obtener el factor de balance
    int balance = obtenerFactorBalance(nodo);

    //aplicar rotaciones por si el nodo se desbalanceo
    //caso Izquierda-izquierda
    if (balance > 1 && p->getId() < nodo->getIzq()->getPaciente()->getId()) {
        return rotacionDerecha(nodo);
    }
    //derecha-derecha
    if (balance < -1 && p->getId() > nodo->getDer()->getPaciente()->getId()) {
        return rotacionIzquierda(nodo);
    }
    //izquierda-derecha (doble)
    if (balance > 1 && p->getId() > nodo->getIzq()->getPaciente()->getId()) {
        nodo->setIzq(rotacionIzquierda(nodo->getIzq()));
        return rotacionDerecha(nodo);
    }
    //derecha-izquierda (doble)
    if (balance < -1 && p->getId() < nodo->getDer()->getPaciente()->getId()) {
        nodo->setDer(rotacionDerecha(nodo->getDer()));
        return rotacionIzquierda(nodo);
    }

    return nodo;

    }
    NodoAvl* Avl::buscarRecursivo(NodoAvl* nodo, string id){

        if (nodo == nullptr || nodo->getPaciente()->getId() == id) {
        return nodo;
        }

        if (nodo->getPaciente()->getId() < id) {
        return buscarRecursivo(nodo->getDer(), id);
        }

        return buscarRecursivo(nodo->getIzq(), id);

    }

    //funcion que ayuda en eliminarrecursivo
    NodoAvl* Avl::obtenerMinimo(NodoAvl* nodo) {
    NodoAvl* actual = nodo;
    while (actual->getIzq() != nullptr) {
        actual = actual->getIzq();
    }
    return actual;
}
    NodoAvl* Avl::eliminarRecursivo(NodoAvl* nodo, string id){

        if (nodo == nullptr){
            return nodo;
        }

    if (id < nodo->getPaciente()->getId()) {
        nodo->setIzq(eliminarRecursivo(nodo->getIzq(), id));
    } else if (id > nodo->getPaciente()->getId()) {
        nodo->setDer(eliminarRecursivo(nodo->getDer(), id));
    } else {
        //encontramos el nodo a eliminar
        if (nodo->getIzq() == nullptr || nodo->getDer() == nullptr) {
            NodoAvl* temp = nodo->getIzq() ? nodo->getIzq() : nodo->getDer();
            if (temp == nullptr) { // Hoja
                temp = nodo;
                nodo = nullptr;
            } else { //un hijo
                *nodo = *temp; 
            }
            delete temp->getPaciente();
            delete temp;
        } else {
            //dos hijos, buscamos al sucesor inorden
            NodoAvl* temp = obtenerMinimo(nodo->getDer());
            
            nodo->setPaciente(temp->getPaciente());
            nodo->setDer(eliminarRecursivo(nodo->getDer(), temp->getPaciente()->getId()));
        }
    }

    if (nodo == nullptr){
        return nodo;
    }
    nodo->setAltura(1 + maximo(obtenerAltura(nodo->getIzq()), obtenerAltura(nodo->getDer())));
    int balance = obtenerFactorBalance(nodo);

    //rebalanceo despues de eliminar
    if (balance > 1 && obtenerFactorBalance(nodo->getIzq()) >= 0){
        return rotacionDerecha(nodo);
    }
    if (balance > 1 && obtenerFactorBalance(nodo->getIzq()) < 0) {
        nodo->setIzq(rotacionIzquierda(nodo->getIzq()));
        return rotacionDerecha(nodo);
    }
    if (balance < -1 && obtenerFactorBalance(nodo->getDer()) <= 0){
        return rotacionIzquierda(nodo);
    }
    if (balance < -1 && obtenerFactorBalance(nodo->getDer()) > 0) {
        nodo->setDer(rotacionDerecha(nodo->getDer()));
        return rotacionIzquierda(nodo);
    }
    return nodo;
    } 
    
    
    void Avl::inordenRecursivo(NodoAvl* nodo){
        if (nodo != nullptr) {
        inordenRecursivo(nodo->getIzq());
        cout << nodo->getPaciente()->getNombre() << " (" << nodo->getPaciente()->getId() << ")" << endl;
        inordenRecursivo(nodo->getDer());
    }

    }
    void Avl::preordenRecursivo(NodoAvl* nodo){
        if (nodo != nullptr) {
        cout << nodo->getPaciente()->getNombre() << " (" << nodo->getPaciente()->getId() << ")" << endl;
        preordenRecursivo(nodo->getIzq());
        preordenRecursivo(nodo->getDer());
    }

    }
    void Avl::postordenRecursivo(NodoAvl* nodo){
        if (nodo != nullptr) {
        postordenRecursivo(nodo->getIzq());
        postordenRecursivo(nodo->getDer());
        cout << nodo->getPaciente()->getNombre() << " (" << nodo->getPaciente()->getId() << ")" << endl;
    }

    }

    
    void Avl::destruirArbol(NodoAvl* nodo){
        if (nodo != nullptr) {
        destruirArbol(nodo->getIzq());
        destruirArbol(nodo->getDer());
        delete nodo->getPaciente();
        delete nodo;

    }
}


    //metodos publicos pal main

void Avl::insertar(Paciente* p) {
    raiz = insertarRecursivo(raiz, p);
}

Paciente* Avl::buscar(string id) {
    NodoAvl* resultado = buscarRecursivo(raiz, id);
    if (resultado != nullptr) {
        return resultado->getPaciente();
    }
    return nullptr;
}

void Avl::eliminar(string id) {
    raiz = eliminarRecursivo(raiz, id);
}

void Avl::mostrarInorden() {
    inordenRecursivo(raiz);
}

void Avl::mostrarPreorden() {
    preordenRecursivo(raiz);
}

void Avl::mostrarPostorden() {
    postordenRecursivo(raiz);
}
    


