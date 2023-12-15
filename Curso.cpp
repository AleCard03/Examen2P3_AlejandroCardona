#include "Curso.h"

Curso::Curso(string Nombre)
{
	this->Nombre = Nombre;
}

void Curso::combinarDosApuntes()
{
	
}

string Curso::getNombre()
{
	return this->Nombre;
	vector<Apunte*> apuntes;

}

Curso::~Curso()
{
	for (Apunte* a : apuntes)
		delete a;
}

vector<Apunte*> Curso::getApuntes()
{
	return this->apuntes;
}

void Curso::deleteApunte(int selItem) {
	delete this->apuntes.at(selItem);
	this->apuntes.erase(apuntes.begin() + selItem);
}

void Curso::setApuntes(vector<Apunte*> newApuntes)
{
	this->apuntes = newApuntes;
}
void Curso::guardarCurso(fstream& saveArchivo) {
	saveArchivo.write(reinterpret_cast<const char*>(apuntes.size()), sizeof(apuntes.size()));
	saveArchivo.write(reinterpret_cast<const char*>(&(this->Nombre)), sizeof(this->Nombre));
	for (Apunte* a : apuntes) {
		a->guardarApunte(saveArchivo);
		/*saveArchivo.write(reinterpret_cast<const char*>(&(a->getTitulo())), sizeof(a->getTitulo()));
		saveArchivo.write(reinterpret_cast<const char*>(&(a->getContenido())), sizeof(a->getContenido()));
		saveArchivo.write(reinterpret_cast<const char*>(&(a->getFecha())), sizeof(a->getFecha()));*/
	}
}
