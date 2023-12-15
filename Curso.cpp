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
