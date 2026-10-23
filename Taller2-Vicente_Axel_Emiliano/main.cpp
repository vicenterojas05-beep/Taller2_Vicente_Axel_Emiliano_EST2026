#include <iostream>
#include <fstream>
#include <string>
#include "Paciente.h"
#include "Queue.h"
#include "Hospital.h"
#include "ArbolDecision.h"

using namespace std;

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void Leerarchivo(Queue* pacientes) {
    ifstream archivo("pacientes.txt");

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    
    // leemos el archivo linea por linea
    while (getline(archivo, linea)) {
        
        stringstream ss(linea); 
        
        // variables temporales para atrapar la info
        string id, nombre, edadStr, tempStr, presionStr, dolorStr;
        string tipoDolor, traumaStr, neuroStr, cirugiaStr, diasStr;

        // extraemos la infor hasta ';'
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, edadStr, ';');
        getline(ss, tempStr, ';');
        getline(ss, presionStr, ';');
        getline(ss, dolorStr, ';');
        getline(ss, tipoDolor, ';');
        getline(ss, traumaStr, ';');
        getline(ss, neuroStr, ';');
        getline(ss, cirugiaStr, ';');
        getline(ss, diasStr, ';'); // ell último podria no tener ';', getline lo maneja

        // vemos que la linea no estuviera vacia (para evitar crasheos si hay saltos de linea al final)
        if (id.empty()) continue;

        //convertimos los datos strings a ints o doubles
        int edad = stoi(edadStr);
        double temperatura = stod(tempStr);
        int presion = stoi(presionStr);
        int dolor = stoi(dolorStr);
        bool trauma = false;
        bool neuro = false;
        bool cirugia = false;
        int dias = stoi(diasStr);

        if(traumaStr=="1"){
            trauma = true;
        }
        if(neuroStr=="1"){
            neuro=true;
        }
        if(cirugiaStr=="1"){
            cirugia = true;
        }


        
        // instanciamos al paciente
        Paciente* p = new Paciente(nombre, edad, id, temperatura, presion, dolor, tipoDolor, trauma, neuro, cirugia, dias); 
        Nodo* n = new Nodo(p);
        pacientes->push(n);
    }

    archivo.close();
}

void menu(){

    cout<<"===  HOSPITAL MARMAJA  ==="<<endl;
    cout<<"1. Atender pacientes"<<endl;
    cout<<"2. Estado de los departamentos"<<endl;
    cout<<"3. Buscar paciente"<<endl;
    cout<<"4. Salir"<<endl;
}


int main(int argc, char** argv) {

	Queue* cola = new Queue();
    Hospital* hospital = new Hospital();
    ArbolDecision* arbol = new ArbolDecision();
	Leerarchivo(cola);

    int opcion = 0;

    do{

        menu();
        cout<<"Ingrese una opción: ";
        cin >> opcion;
        cout<<endl;
        cout<<endl;

        switch(opcion){

            case 1: {
                cout<<"=== ATENDIENDO PACIENTES ==="<<endl;
                
                Nodo* n = cola->front();
                string ruta = "";

                if(n!=nullptr){

                Paciente* p = n->getPaciente();
                //se hacen las preguntas para determinar el servicio del paciente
                string servicio_paciente= arbol->clasificarPaciente(p, ruta);
                //le actualizamos el servicio
                p->setServicio(servicio_paciente);
                

                //imprimimos como sale en el pdf
                hospital->ingresar_pacienteavl(p);
                cout << "ID: " << p->getId() << endl;
                cout << "Nombre: " << p->getNombre() << endl;

                cout<<"Ruta de decision: "<<ruta<<endl; 
                cout << "Servicio asignado: " << servicio_paciente<<endl;
                cout << "Paciente insertado en el AVL de " << servicio_paciente << "." << endl;
                cout << "---------------------------------" << endl;

                cola->pop(); 

                }
                
                break;
            }

            case 2: {

                cout<<"=== ESTADO DE LOS DEPARTAMENTOS/SERVICIOS ==="<<endl;
            
                break;

				
			

            
			}


            case 3:{
                cout<<"=== BUSCAR PACIENTE ==="<<endl;

                break;
            
            

            }

            case 4:{
                
                cout<<"Hasta luego :D"<<endl;
                delete hospital;
                delete cola;
                break;

            
            }

            
            

        }

        



    }while(opcion!=4);
    

	
	return 0;
}
