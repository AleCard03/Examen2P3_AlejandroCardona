#include "Apunte.h"

Apunte::Apunte(string Titulo, string Contenido, string Fecha)
{
	this->Titulo = Titulo;
	this->Contenido = Contenido;
	this->Fecha = Fecha;

}
Apunte* Apunte::operator+(Apunte nota) {

	this->Titulo = this->Titulo + " + " + nota.Titulo;
	this->Contenido += "\n" + nota.Contenido;
	cout << "Ingrese la fecha de la combinaci�n: ";
	cin >> this->Fecha;

	return this;
}

string Apunte::to_string()
{
	return "T�tulo: "+Titulo+"\nContenido: "+Contenido+"\nFecha: "+Fecha+"\n";
}

Apunte::~Apunte()
{
}
