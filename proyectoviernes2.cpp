#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
//#include <ListasProyecto.h>
#include <vector>
#include <conio.h>
#include <string.h>
#include <limits>
#include <algorithm>
#include <regex>
#include <math.h>
#include <iomanip>

using namespace std;

//-------------------------------------------------------------------FUNCIONES DE MENUS------------------------------------------------------------------


void menuPrincipal(){

    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Principal.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Especies" << endl;
    cout << "2. Ambientes" << endl;
    cout << "3. Accesorios" << endl;
    cout << "0. Salir" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";

}

void menuEspecies(){

    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Especies.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Ver las especies y sus caracteristicas" << endl;
    cout << "2. Agregar especies" << endl;
    cout << "3. Eliminar especies" << endl;
    cout << "4. Modificar especies" << endl;
    cout << "0. Regresar" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";

}

void menuAmbientes(){

    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Ambientes.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Ver los ambientes" << endl;
    cout << "2. Agregar ambientes" << endl;
    cout << "3. Eliminar ambientes" << endl;
    cout << "4. Modificar ambientes" << endl;
    cout << "0. Regresar" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";

}

void menuAccesorios(){

    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Accesorios.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Ver los accesorios" << endl;
    cout << "2. Agregar accesorios" << endl;
    cout << "3. Eliminar accesorios" << endl;
    cout << "4. Modificar accesorios" << endl;
    cout << "0. Regresar" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";

}
//-------------------------------------------------------------------VALIDACIONES GNRALES------------------------------------------------------------------

int obtenerEnteroPositiv() {
    while (true) {
        string entrada;
        cin >> entrada;
        bool esNumeroValido;
    
        esNumeroValido = true;
        for (char c : entrada) {
            if (!isdigit(c)) {
                esNumeroValido = false;
                break;
            }
        }

        if (esNumeroValido && stoi(entrada) >= 1) {
            return stoi(entrada);
        } else {
            //system("cls");
            cout << "----------------------   PELIGRO   ------------------" << endl;
            cout << "           El dato ingresado no es valido "  << endl;
            cout << "      Por favor, verifique el dato a introducir :     " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
}


int obtenerEnteroPositivo(string mensaje){
    int num;
    while (true){
        cout<<mensaje; cin>>num;
        if (cin.fail() || num<1){  //La funcion fail() retorna true si se genera un error con el cin
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "----------------------   PELIGRO   ------------------" << endl;
            cout << "           El dato ingresado no es valido "  << endl;
            cout << "      Por favor, verifique el dato a introducir :     " << endl;
        }
        else{
            break;
        }
    }
    return num;
}


//-------------------------------------------------------------------FUNCIONES DE ESPECIES------------------------------------------------------------------

struct especie{
    string nombre;
    int energia;
    int salud = 100;
    string ambiente;
    struct especie *prox;
};
typedef struct especie *especiePTR;

especiePTR listaEspecie = NULL;

especiePTR crearNodoEspecie(string nombre, int energia,  string ambiente){
    especiePTR p;
    p = new(struct especie);
    p->nombre = nombre;
    p->energia = energia;
    p->ambiente = ambiente;
    p->prox = NULL;
    return(p);
}

void RegistroListaEspecie(especiePTR &listaEspecie, string nombre, int energia, string ambiente){
    especiePTR p = crearNodoEspecie(nombre, energia, ambiente);
	if(listaEspecie == NULL){
		listaEspecie = p;
	}
	else {
		especiePTR t = listaEspecie;
		while(t->prox != NULL){
			t= t->prox;
		}
		t->prox = p;
	}
} 

void MostrarEspecies(especiePTR &listaEspecie){
    if(listaEspecie == NULL){
		cout << "Aun no ha creado ninguna especie" << endl;
	}
    else {
        especiePTR t = listaEspecie;
        cout << "       e s p e c i e s" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "ENERGIA" << left << setw(20) << setfill(' ') << "SALUD" << left << setw(20) << setfill(' ') << "AMBIENTE" << endl;
        cout << endl;
        while(t != NULL){
            cout << "Especie N" /*<< t->id <<*/ << endl;
            cout << left << setw(20) << setfill(' ') << t->nombre;
            cout << left << setw(20) << setfill(' ') << t->energia;
            cout << left << setw(20) << setfill(' ') << t->salud;
            cout << left << setw(20) << setfill(' ') << t->ambiente << endl;
            cout << endl;
            t = t->prox;
        }
        cout << "--------------------------------------------------------------------------" << endl;
        cout << endl;
    }
}

bool BuscarEspecie(especiePTR &listaEspecie, string nombre){
    especiePTR p = listaEspecie;
    while(p != NULL){
        if(p->nombre == nombre){
            return true;
        }
        p = p->prox;
    }
    return false;
}

void EliminarEspecie(especiePTR &listaEspecie, string nombre){
    especiePTR p, ant;
    p = listaEspecie;
    if(listaEspecie != NULL){
        while(p != NULL){
            if(p->nombre == nombre){
                if(p==listaEspecie){
                    listaEspecie = listaEspecie->prox;
                }else{
                    ant->prox = p->prox;
                }
                delete(p);
                return;
            }
            ant = p;
            p = p->prox;
        }
    }
}

//-------------------------------------------------------------------FUNCIONES DE AMBIENTES------------------------------------------------------------------

bool BuscarAmbiente(vector<string>& vector_ambientes, string ambiente){
    for (int i = 0; i < vector_ambientes.size(); i++){
        if (vector_ambientes[i] == ambiente) {
            return true;
        }
    }
    return false;
}

void MostrarAmbientes(vector<string>& vector_ambientes){
    cout << "       a m b i e n t e s" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    for (int l=0; l<vector_ambientes.size(); l++){
        cout << "Ambiente N" << l+1 << ": " << vector_ambientes[l] << endl;

    }
    cout << "--------------------------------------------------------------------------" << endl;
}

void AgregarAmbiente(vector<string>& vector_ambientes, string ambiente){
    if(!BuscarAmbiente(vector_ambientes, ambiente)){
        vector_ambientes.push_back(ambiente);
        cout << "El ambiente " << ambiente << " ha sido aniadido: " << endl;
        MostrarAmbientes(vector_ambientes);
    } else {
        cout << "El ambiente " << ambiente << " ya se encuentra registrado" << endl;
    }
}

void EliminarAmbiente(vector<string>& vector_ambientes, especiePTR &listaEspecie, string ambiente){
    bool found;
    especiePTR p = listaEspecie;
    string ambientemodif;
    bool eliminado;

    for (int i = 0; i < vector_ambientes.size(); i++) {
        if (vector_ambientes[i] == ambiente) {

            //TOMO EN CUENTA LAS ESPECIES YA REGISTRADAS CON EL AMBIENTE QUE ACABAMOS DE ELIIMINAR:

            while (p != NULL){
                if (p->ambiente == ambiente) {
                    system("cls");
                    cout << "----------------------   PELIGRO   ------------------" << endl;
                    cout << "        Este ambiente aun pertenece a una especie  "  << endl;
                    cout << "          Por favor, reubique la especie...     " << endl;
                    cout << "Nombre: " << p->nombre << endl;
                    cout << "Energia: " << p->energia << endl;
                    cout << "Salud: " << p->salud << endl; 
                    cout << "Ambiente que desea eliminar: " << p->ambiente << endl; 
                    cout << endl;
                    cout << "Ingrese el nuevo ambiente de la especie: "; getline(cin, ambientemodif);

                    system("cls");
                    if (BuscarAmbiente(vector_ambientes, ambiente)){
                        vector_ambientes.erase(vector_ambientes.begin() + i);
                        eliminado=true;
                    }
                    cout << "El ambiente " << ambiente << " ha sido eliminado" << endl;
                    if (!BuscarAmbiente(vector_ambientes, ambientemodif)){
                        
                        AgregarAmbiente(vector_ambientes, ambientemodif);
                    }
                    p->ambiente = ambientemodif;
                    
                }
                p = p->prox;
            }
            //
            if (!eliminado){ //Condicional para eliminar ambiente en el caso en que no esta en ninguna especie
                vector_ambientes.erase(vector_ambientes.begin() + i);
                cout << "El ambiente " << ambiente << " ha sido eliminado" << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "El ambiente " << ambiente << " no se encuentra registrado" << endl;
    }
}

void ModificarAmbiente(vector<string>& vector_ambientes, especiePTR &listaEspecie, string ambiente){ //(en el vector)
    string ambientenew;
    bool found;
    for (int l=0; l<vector_ambientes.size(); l++){
        if (vector_ambientes[l] == ambiente){
            while (true){  //Ciclo para evitar ambientes repetidos dentro del vector
                cout << "Ingrese el nuevo nombre del ambiente: "; getline(cin,ambientenew);
                if (BuscarAmbiente(vector_ambientes,ambientenew)){
                    cout << "El ambiente " << ambientenew << " ya se encuentra registrado" << endl;
                }
                else {
                    system("cls");
                    vector_ambientes[l] = ambientenew;
                    cout << "El ambiente '" << ambiente << "' ha sido modificado por '" << ambientenew << "'" << endl;
                    //buscar en lista p ambiente
                    especiePTR p = listaEspecie;
                    while (p != NULL) {
                        if (p->ambiente == ambiente ) {
                            p->ambiente = ambientenew;
                            cout << "El ambiente tambien ha sido modificado en la especie '" << p->nombre << "'." << endl;
                        }
                        p = p->prox;
                    }
                    break;
                }
            }
            found = true;
        }
    }
    if (!found){
        cout << "El ambiente " << ambiente << " no se encuentra registrado" << endl;
    }
}

//-------------------------------------------------------------------FUNCIONES DE ACCESORIOS------------------------------------------------------------------

struct accesorio{
    string nombre;
    string tipo;
    int valor;
    string tipo_valor;
    int energia;
    int contenedor;
    struct accesorio *prox;
};
typedef struct accesorio *accesorioPTR;

accesorioPTR listaAccesorio = NULL;

accesorioPTR crearNodoAccesorio(string nombre, string tipo, int valor, string tipo_valor, int energia, int contenedor){
    accesorioPTR p;
    p = new(struct accesorio);
    p->nombre = nombre;
    p->tipo = tipo;
    p->valor = valor;
    p->tipo_valor = tipo_valor;
    p->energia = energia;
    p->contenedor = contenedor;
    p->prox = NULL;
    return(p);
}

void RegistroListaAccesorio(accesorioPTR &listaAccesorio, string nombre, string tipo, int valor, string tipo_valor, int energia, int contenedor){
    accesorioPTR p = crearNodoAccesorio(nombre, tipo, valor, tipo_valor, energia, contenedor);
	if(listaAccesorio == NULL){
		listaAccesorio = p;
	}
	else {
		accesorioPTR t = listaAccesorio;
		while(t->prox != NULL){
			t= t->prox;
		}
		t->prox = p;
	}
} 

void MostrarAccesorios(accesorioPTR &listaAccesorio){
    if(listaAccesorio == NULL){
		cout << "Aun no ha creado ningun accesorio" << endl;
	}
    else {
        accesorioPTR t = listaAccesorio;
        cout << "    a c c e s o r i o s" << endl;
        cout << "       " << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "       " << endl;
        cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "TIPO" << left << setw(20) << setfill(' ') << "VALOR" << left << setw(20) << setfill(' ') << "TIPO VALOR" << left << setw(30) << setfill(' ') << "CONSUMO de MIDICLORIAS" << left << setw(30) << setfill(' ') << "VALOR INCIAL de PROTECCION" << endl;
        cout << endl;
        while(t != NULL){
            cout << left << setw(20) << setfill(' ') << t->nombre;
            cout << left << setw(20) << setfill(' ') << t->tipo;
            cout << left << setw(20) << setfill(' ') << t->valor;
            cout << left << setw(20) << setfill(' ') << t->tipo_valor;
            cout << left << setw(30) << setfill(' ') << t->energia;
            cout << left << setw(30) << setfill(' ') << t->contenedor << endl;
            cout << endl;
            t = t->prox;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
}

bool BuscarAccesorio(accesorioPTR &listaAccesorio, string nombre){
    accesorioPTR p = listaAccesorio;
    while(p != NULL){
        if(p->nombre == nombre){
            return true;
        }
        p = p->prox;
    }
    return false;
}

void EliminarAccesorio(accesorioPTR &listaAccesorio, string nombre){
    accesorioPTR p, ant;
    p = listaAccesorio;
    if(listaAccesorio != NULL){
        while(p != NULL){
            if(p->nombre == nombre){
                if(p==listaAccesorio){
                    listaAccesorio = listaAccesorio->prox;
                }else{
                    ant->prox = p->prox;
                }
                delete(p);
                return;
            }
            ant = p;
            p = p->prox;
        }
    }
}

//-----------------------------------------------------------FUNCION DE MODIFICACION GRAL DE ESPECIES------------------------------------------------------------------

void ModificarDatosEspecie(especiePTR &listaEspecie, vector<string> &vector_ambientes, string nombre){
    especiePTR p = listaEspecie;
    char opc;
    int energia;
    string ambiente;
    while (p !=NULL ){
        if ( p->nombre == nombre){
            do{
                cout << " Que desea modificar? " << endl;
                cout << " [1] Nombre " << endl;
                cout << " [2] Energia " << endl;
                cout << " [3] Ambiente " << endl;
                cout << " [0] Nada, quiero volver... " << endl;
                cout << "Elija una opcion: ";
                cin >> opc;

                switch (opc){

                    case '1':
                    cout << "Escriba el nuevo nombre de la especie: ";
                    cin.ignore(); getline(cin, nombre);
                    p->nombre = nombre;
                    system("PAUSE");
                    break;

                    case '2':
                    energia = obtenerEnteroPositivo("Ingrese la nueva cantidad de energia (mayor a 0): ");
                    p->energia = energia;
                    system("PAUSE");
                    break;

                    case '3':
                    cout << "Ingrese el nuevo ambiente de la especie: ";
                    cin.ignore();
                    getline(cin, ambiente);
                    if (!BuscarAmbiente(vector_ambientes, ambiente)){
                        AgregarAmbiente(vector_ambientes, ambiente);
                    }
                    p->ambiente = ambiente;
                    system("PAUSE");
                    break;
                    
                    default:
                    system("cls");
                    if (opc!='0'){
                        cout<<"Introduzca una opcion valida"<<endl;
                        system("PAUSE");
                    }
                }
            }while(opc!='0');
        }
        p=p->prox;
    }
}

//-------------------------------------------------------------------INICIO DEL MAIN---------------------------------------------------------------------------

int main(){
    //Variables especies
    int energia, valor, contenedor;
    string nombre, ambiente, tipo, tipo_valor;
    vector<string> vector_ambientes = {"Tierra", "Caluroso"};
    bool menuTipos=true; bool add_acc=true;

    char opcionMenuPrincipal, opcionMenuEspecies, opcionMenuAmbientes, opcionMenuAccesorios, opcionTipoAcc;

    do{
        menuPrincipal();
        cin >> opcionMenuPrincipal;
        switch(opcionMenuPrincipal){
            case '1':
            do{
                menuEspecies();
                cin >> opcionMenuEspecies;

                switch(opcionMenuEspecies){
                    case '1':
                    system("cls");
                    MostrarEspecies(listaEspecie);
                    system("PAUSE");
                    break;

                    case '2':
                    cin.ignore(); cout << "Ingrese el nombre de la especie: "; getline(cin,nombre);
                    if (BuscarEspecie(listaEspecie,nombre)){
                        cout << "Ya existe una especie con el nombre introducido" << endl;
                    } else{
                        energia = obtenerEnteroPositivo("Ingrese la energia (mayor a 0): ");
                        cin.ignore(); cout << "Ingrese el ambiente: "; getline(cin,ambiente);
                        
                        if (BuscarAmbiente(vector_ambientes, ambiente)){
                            RegistroListaEspecie(listaEspecie, nombre, energia, ambiente);
                            cout << "La especie " << nombre << " ha sido aniadida" << endl;
                        } else{
                            cout << "El ambiente introducido aun no ha sido registrado." << endl;
                        }
                    }
                    
                    system("PAUSE");
                    break;

                    case '3':
                    cout << "Ingrese el nombre de la especie que desea eliminar: "; 
                    cin >> nombre;
                    system("cls");
                    if(BuscarEspecie(listaEspecie, nombre)){
                        EliminarEspecie(listaEspecie, nombre);
                        cout << "La especie " << nombre << " ha sido eliminada" << endl;
                    }else{
                        cout << "Dicha especie no se encuentra en los registros..." << endl;
                    }
                    system("PAUSE");
                    break;

                    case '4':
                    cout << "Indique el nombre de la especie que desea modificar: "; cin >> nombre;
                    if (BuscarEspecie(listaEspecie,nombre)){
                        ModificarDatosEspecie(listaEspecie, vector_ambientes, nombre);
                        cout << "Los datos de la especie " << nombre << " han sido actualizados." << endl;
                    }else{
                        cout << "Dicha especie no se encuentra en los registros..." << endl;
                    }
                    system("PAUSE");
                    break;

                    default:
                    system("cls");
                    if (opcionMenuEspecies!='0'){
                        cout<<"Introduzca una opcion valida"<<endl;
                        system("PAUSE");
                    }
                    break;

                }
            } while(opcionMenuEspecies != '0');
            break;

            case '2':
            do{
                menuAmbientes();
                cin >> opcionMenuAmbientes;

                switch(opcionMenuAmbientes){
                    case '1':
                    MostrarAmbientes(vector_ambientes);
                    system ("PAUSE");
                    break;

                    case '2':
                    cin.ignore(); cout << "Ingrese el ambiente que desea agregar: "; getline(cin,ambiente);
                    AgregarAmbiente(vector_ambientes, ambiente);
                    system("PAUSE");
                    break;
                    
                    case '3':
                    cin.ignore(); cout << "Ingrese el ambiente que desea eliminar: "; getline(cin,ambiente);
                    EliminarAmbiente(vector_ambientes, listaEspecie, ambiente);
                    system("PAUSE");
                    break;

                    case '4':
                    cin.ignore(); cout << "Ingrese el ambiente que desea modificar: "; getline(cin,ambiente);
                    ModificarAmbiente(vector_ambientes, listaEspecie, ambiente);
                    system("PAUSE");
                    break;
                    
                    default:
                    system("cls");
                    if (opcionMenuAmbientes!='0'){
                        cout<<"Introduzca una opcion valida"<<endl;
                        system("PAUSE");
                    }
                    break;
                }
            }while(opcionMenuAmbientes != '0');
            break;

            case '3':
            do{
                menuAccesorios();
                cin >> opcionMenuAccesorios;

                switch(opcionMenuAccesorios){
                    case '1':
                        system("cls");
                        MostrarAccesorios(listaAccesorio);
                        system("PAUSE");
                        break;
                    case '2':
                        cin.ignore(); cout << "Ingrese el nombre del accesorio: "; getline(cin,nombre);
                        if (BuscarAccesorio(listaAccesorio,nombre)){
                            cout << "Ya existe un accesorio con el nombre introducido" << endl;
                        } else{
                            while (menuTipos){
                            cout << " Seleccione el tipo del accesorio" << endl;
                            cout << " [1] Ataque " << endl;
                            cout << " [2] Defensa " << endl;
                            cout << " [3] Supervivencia " << endl;
                            cout << " [4] Acondicionamiento " << endl;
                            cout << "Elija una opcion: ";
                            cin >> opcionTipoAcc;

                            switch (opcionTipoAcc)
                            {
                            case '1':
                                tipo="Ataque";
                                menuTipos=false;
                                break;
                            case '2':
                                tipo="Defensa";
                                menuTipos=false;
                                break;
                            case '3':
                                tipo="Supervivencia";
                                menuTipos=false;
                                break;
                            case '4':
                                tipo="Acondicionamiento";
                                menuTipos=false;
                                break;
                            
                            default:
                                cout<<"Introduzca una opcion valida"<<endl;
                                system("PAUSE");
                                break;
                            }
                            }
                            menuTipos=true;
                            energia = obtenerEnteroPositivo("Ingrese el valor de midiclorias que consume (mayor a 0): ");

                            if (tipo=="Ataque"){
                                valor=obtenerEnteroPositivo("Ingrese el porcentaje de danio que realiza (mayor a 0): ");
                                tipo_valor="0";
                                contenedor=0;
                            }
                            else if (tipo=="Defensa"){
                                valor=obtenerEnteroPositivo("Ingrese el porcentaje de disminucion de ataque (mayor a 0): ");
                                tipo_valor="0";
                                contenedor = obtenerEnteroPositivo("Ingrese el valor inicial de proteccion que otorga  (mayor a 0): ");
                            }
                            else if (tipo=="Supervivencia"){
                                valor=obtenerEnteroPositivo("Ingrese el porcentaje que puede recuperar (mayor a 0): ");
                                while (menuTipos){
                                    cout << " Seleccione el tipo de recurso que recupera" << endl;
                                    cout << " [1] Energia " << endl;
                                    cout << " [2] Salud " << endl;
                                    cout << "Elija una opcion: ";
                                    cin >> opcionTipoAcc;

                                    switch (opcionTipoAcc)
                                    {
                                    case '1':
                                        tipo_valor="Energia";
                                        menuTipos=false;
                                        break;
                                    case '2':
                                        tipo_valor="Salud";
                                        menuTipos=false;
                                        break;
                                    
                                    default:
                                        cout<<"Introduzca una opcion valida"<<endl;
                                        system("PAUSE");
                                        break;
                                    }
                                }
                                menuTipos=true;
                                contenedor=0;
                            }
                            else if (tipo=="Acondicionamiento"){
                                valor=0;
                                contenedor=0;
                                cin.ignore(); cout << "Ingrese el ambiente para el que esta diseniado: "; getline(cin,tipo_valor);
                                if (!(BuscarAmbiente(vector_ambientes, tipo_valor))){
                                    cout << "El ambiente introducido aun no ha sido registrado." << endl;
                                    add_acc=false;
                                }
                            }
                            //Condicioonal para crear el accesorio en caso de que se intente introducir un ambiente que no existe para el tipo acondicionamiento
                            if (add_acc){
                                RegistroListaAccesorio(listaAccesorio, nombre, tipo, valor, tipo_valor, energia, contenedor);
                                cout << "El accesorio " << nombre << " ha sido aniadido" << endl;
                            }
                            add_acc=true;
                        }
                        
                        system("PAUSE");
                        break;
                    case '3':
                        cout << "Ingrese el nombre del accesorio que desea eliminar: "; 
                        cin >> nombre;
                        system("cls");
                        if(BuscarAccesorio(listaAccesorio, nombre)){
                            EliminarAccesorio(listaAccesorio, nombre);
                            cout << "El accesorio " << nombre << " ha sido eliminado" << endl;
                        }else{
                            cout << "Dicho accesorio no se encuentra en los registros..." << endl;
                        }
                        system("PAUSE");
                        break;
                    case '4':
                        
                    default:
                        system("cls");
                        if (opcionMenuAccesorios!='0'){
                            cout<<"Introduzca una opcion valida"<<endl;
                            system("PAUSE");
                        }
                        break;
                }

            } while(opcionMenuAccesorios != '0');
            break;

            default:
                    system("cls");
                    if (opcionMenuPrincipal!='0'){
                        cout<<"Introduzca una opcion valida"<<endl;
                        system("PAUSE");
                    }
                    
                    break;
        }

    }while(opcionMenuPrincipal!='0');
    system("cls");
    cout<<"Ha salido con exito";
    return 0;
}