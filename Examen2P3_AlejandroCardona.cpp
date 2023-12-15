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
    } while (opcion < 1 || opcion>4);
    return opcion;
}
void guardarArchivo() {

}

int main()
{
    bool continuar = true;
    while (continuar) {
        switch (menu()) {
        case 1:
            break;
        case 2: 
            break;
        case 3: 
            break;
        case 4:
            break;
        case 5 :
            continuar = false;
            guardarArchivo();
            break;
        }
    }
    
}
