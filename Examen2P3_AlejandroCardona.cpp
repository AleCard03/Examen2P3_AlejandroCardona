#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <fstream>
#include "Curso.h"
#include "Apunte.h"

using namespace std;

vector<Curso*>cursos;

int menu() {
    int opcion = 0;
    do {
        cout << "---MENÚ---" << endl << "1. Opciones Cursos\n2. Opciones Apuntes\n3. Guardar Archivos\n4. Cargar Archivos\n5. Salir" << endl;
        cin >> opcion;
    } while (opcion < 1 || opcion>5);
    return opcion;
}
int menuCursos() {
    int opcion = 0;
    do {
        cout << "---SUBMENÚ---" << endl << "1. Crear Curso\n2. Listar Curso\n3. Eliminar Cursos\n4. Salir" << endl;
        cin >> opcion;
    } while (opcion < 1 || opcion>4);
    return opcion;
}
int menuApuntes() {
    int opcion = 0;
    do {
        cout << "---SUBMENÚ---" << endl << "1. Crear Apuntes\n2. Listar Apuntes\n3. Eliminar Apuntes\n4. Combinar Apuntes\n5. Salir" << endl;
        cin >> opcion;
    } while (opcion < 1 || opcion>5);
    return opcion;
}
void listarCurso();//prototipo de listarCurso
void crearApunte() {
    if (cursos.size() > 0) {
        int selItem = -1;
        listarCurso();
        do {
            cout << "Seleccione el índice del curso al que le desea agregar un apunte: ";
            cin >> selItem;
        } while (selItem<0 || selItem>cursos.size() - 1);
        string Titulo, Contenido, Fecha;
        cin.ignore();
        cout << "Ingrese el título del apunte: ";
        getline(cin, Titulo);
        cout << "Ingrese el contenido del apunte: ";
        getline(cin, Contenido);
        cout << "Ingrese la fecha del apunte: ";
        getline(cin, Fecha);
        vector<Apunte*> temp = cursos.at(selItem)->getApuntes();
        temp.push_back(new Apunte(Titulo, Contenido, Fecha));
        cursos.at(selItem)->setApuntes(temp);
        

    }
    else
        cout << "Considere agregar un curso primero." << endl;
}//selecciona un curso y le agrega un apunte
void listarApuntes() {
    if (cursos.size() > 0) {
        int selItem = -1;
        listarCurso();
        do {
            cout << "Seleccione el índice del curso del que desea listar sus apuntes: ";
            cin >> selItem;
        } while (selItem<0 || selItem>cursos.size() - 1);
        int index = 0;
        if (cursos.at(selItem)->getApuntes().size() > 0) {
            for (Apunte* a : cursos.at(selItem)->getApuntes()) {
                cout << index++ << ". " << a->to_string();
            }
        }
        else {
            cout << "Considere agregar mínimo un apunte al curso!" << endl;
        }
    }
    else
        cout << "Considere agregar un curso primero." << endl;
}//lista apuntes de un curso
void eliminarApunte() {
    if (cursos.size() > 0) {
        int selItem = -1;
        listarCurso();
        do {
            cout << "Seleccione el índice del curso del que desea listar sus apuntes: ";
            cin >> selItem;
        } while (selItem<0 || selItem>cursos.size() - 1);
        int index = 0;
        if (cursos.at(selItem)->getApuntes().size() > 0) {
            for (Apunte* a : cursos.at(selItem)->getApuntes()) {
                cout << index++ << ". " << a->to_string();
            }
            int selItem2 = -1;
            do {
                cout << "Seleccione el índice del apunte que desea eliminar: ";
                cin >> selItem2;
            } while (selItem2<0 || selItem2>cursos.size() - 1);

            cursos.at(selItem)->deleteApunte(selItem2);
        }
        else {
            cout << "Considere agregar por lo menos un apunte al curso!"<<endl;
        }
    }
    else {
        cout << "Considere agregar por lo menos un curso y un apunte a dicho curso!" << endl;
    }
}//elimmina apunte con metodo para eliminar de vector y borrar el indice
void combinarApunte() {
    if (cursos.size() > 0) {
        int selItem = -1;
        listarCurso();
        do {
            cout << "Seleccione el índice del curso del que desea listar sus apuntes: ";
            cin >> selItem;
        } while (selItem<0 || selItem>cursos.size() - 1);
        int index = 0;
        if (cursos.at(selItem)->getApuntes().size() > 1) {
            for (Apunte* a : cursos.at(selItem)->getApuntes()) {
                cout << index++ << ". " << a->to_string();
            }
            int selItem2 = -1;
            do {
                cout << "Seleccione el índice del apunte 1 que desea combinar: ";
                cin >> selItem2;
            } while (selItem2<0 || selItem2>cursos.at(selItem)->getApuntes().size() - 1);
            int selItem3 = -1;
            do {
                cout << "Seleccione el índice del apunte 2 que desea combinar: ";
                cin >> selItem3;
            } while (selItem3<0 || selItem3>cursos.at(selItem)->getApuntes().size() - 1);
            vector<Apunte*>temp = cursos.at(selItem)->getApuntes();
            Apunte* a = cursos.at(selItem)->getApuntes().at(selItem2);
            Apunte* b = cursos.at(selItem)->getApuntes().at(selItem3);
            Apunte* c = *a + b;
            temp.push_back(c);
            cursos.at(selItem)->setApuntes(temp);
            if (selItem2 > selItem3) {
                cursos.at(selItem)->deleteApunte(selItem2);
                cursos.at(selItem)->deleteApunte(selItem3);
            }
            else {
                cursos.at(selItem)->deleteApunte(selItem3);
                cursos.at(selItem)->deleteApunte(selItem2);
            }
        }
        else {
            cout << "Considere agregar mínimo un apunte al curso!" << endl;
        }
    }
    else
        cout << "Considere agregar un curso primero." << endl;
}//Hace uso de operador sobrecargado para combinar Apuntes y elimina los dos usados para combinar

void opcionesApuntes() {
    bool continuar = true;
    while (continuar) {
        switch (menuApuntes()) {
        case 1:
            crearApunte();
            break;
        case 2:
            listarApuntes();
            break;
        case 3:
            eliminarApunte();
            break;
        case 4:
            combinarApunte();
            break;
        case 5:
            continuar = false;
            break;
        }
    }
}
void crearCurso() {
    string nombre;
    cin.ignore();
    cout << "Ingrese el nombre del curso: ";
    getline(cin, nombre);
    Curso* c = new Curso(nombre);
    cursos.push_back(c);
}//Crea un curso y lo mete al vector
void listarCurso() {
    if (cursos.size() > 0) {
        int index = 0;
        for (Curso* c : cursos) {
            cout << index++<<". "<< c->getNombre() << endl;
        }
    }
    else {
        cout << "¡Considere agregar por lo mínimo un curso!" << endl;
    }
    
}//lista los cursos en el vector
void eliminarCurso() {
    if (cursos.size() > 0) {
        listarCurso();
        int selItem = -1;
        do {
            cout << "Ingrese el índice del curso a eliminar: ";
            cin >> selItem;
        } while (selItem<0 || selItem>cursos.at(selItem)->getApuntes().size() - 1);
        
        delete cursos.at(selItem);
        cursos.erase(cursos.begin() + selItem);
    }
    else {
        cout << "Considere agregar por lo menos un curso!";
    }
}//elimina un curso del vector
void opcionesCursos() {

    bool continuar = true;
    while (continuar) {
        switch (menuCursos()) {
        case 1:
            crearCurso();
            break;
        case 2:
            listarCurso();
            break;
        case 3:
            eliminarCurso();
            break;
        case 4:
            continuar = false;
        }
    }

}
void guardarArchivo() {
    if (cursos.size() > 0) {
        ofstream cleanArchivo("Apuntes.rjz", ios::out);
        cleanArchivo.close();
        ofstream saveArchivo("Apuntes.rjz", ios::out | ios::binary);
        int x = 0;
        for (Curso* c : cursos) {
            c->guardarCurso(saveArchivo);
        }
        saveArchivo.close();
    }
    else {
        cout << "Considere cargar un archivo o crear cursos!" << endl;
    }
}

void cerrarPrograma() {
    if(cursos.size()>0)
        guardarArchivo();
    for (Curso* c : cursos)
        delete c;
}

int main()
{
    setlocale(LC_ALL, "spanish");
    bool continuar = true;
    while (continuar) {
        switch (menu()) {
        case 1:
            opcionesCursos();
            break;
        case 2: 
            opcionesApuntes();
            break;
        case 3: 
            guardarArchivo();
            break;
        case 4:
            break;
        case 5 :
            continuar = false;
            cerrarPrograma();
            break;
        }
    }
    
}
