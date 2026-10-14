#include <iostream>
#include <fstream>
#include <string>
#include "Paciente.h"
#include "Queue.h"
#include "Hospital.h"
#include "Stack.h"

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
    cout<<"2. Ver departamentos"<<endl;
    cout<<"3. Revisar el historial de atención"<<endl;
    cout<<"4. Salir"<<endl;
}








int main(int argc, char** argv) {
	Queue* cola = new Queue();
    Stack* historial = new Stack();
    Hospital* hospital = new Hospital();
	Leerarchivo(cola);

    int opcion = 0;

    do{

        menu();
        cout<<"Ingrese una opción: ";
        cin >> opcion;
        cout<<endl;
        cout<<endl;

        switch(opcion){

            case 1:{
            cout<<"=== Pacientes en espera ==="<<endl;
            cola->mostrar_espera();
            cout<<endl;
            int cantidad_atencion = 0;
            cout<<"Indique la cantidad de pacientes a atender: ";
            cin>>cantidad_atencion;
            cout<<endl;
            cout<<"=== ATENDIENDO PACIENTES ==="<<endl;
            for(int i = 0; i<cantidad_atencion;i++){
                Nodo* n = cola->front();//tomamos el nodo en el que se encuentra el paciente

                if(n==nullptr){
                    cout<<"Ya no hay pacientes en espera"<<endl;
                    break;
                }

                Paciente* p = n->getPaciente(); //obtenemos al paciente

                
                historial->push(p);
                hospital->ingresar_paciente(p); //ingresamos al paciente y no al nodo, esto para que no este el mismo nodo
                                                //en dos o  tres listas diferentes de nodos. 
                cout<<"ID: "<<p->getId()<<endl;
                cout<<"Nombre: "<<p->getNombre()<<endl;
                cout<<"Edad: "<<p->getEdad()<<endl;
                cout<<"Servicio: "<<p->getServicio()<<endl;
                cout<<endl;
                cout<<"Paciente enviado a "<<p->getServicio()<<endl;
                cola->pop(); //Eliminamos solo el nodo
                cout<<"============================================"<<endl;

            }



            
            break;

        }
            case 2: {
				
			

            cout<<"=== DEPARTAMENTOS/SERVICIOS ==="<<endl;
            cout<<endl;
            hospital->mostrar_servicios();
            cout<<endl;
            cout<<"Seleccionar opción: ";

            int elegir_servicio = 0;
            cin>> elegir_servicio;

            Lista* servicio_elegido = hospital->getServicio(elegir_servicio);
            if(servicio_elegido==nullptr){ //devuelve null si el numero ingresado fue mayor o menor a la cant de servicios
                break;
            }
            cout<<endl;
            cout<<"=== ESTADO "<<servicio_elegido->getServicio()<<endl;
            cout<<"Pacientes en el departamento de "<<servicio_elegido->getServicio()<<": "<<servicio_elegido->cantidad_pacientes()<<endl;
            servicio_elegido->mostrar();
            
            break;
			}

            case 3:{

            cout<<"== HISTORIAL DE ÚLTIMAS ATENCIONES DEL HOSPITAL =="<<endl;
            cout<<endl;
            if(historial->empty()){
                cout<<"<< Todavía no se atiende a ningun paciente >>"<<endl;
                break;
            }
            historial->mostrar_historial();
            cout<<endl;
            
            break;
            }

            case 4:

            cout<<"Hasta luego :D"<<endl;
            delete hospital;
            delete cola;
            delete historial;
            break;
            

        }

        



    }while(opcion!=4);
    

	
	return 0;
}
