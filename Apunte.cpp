#include "Apunte.h"

Apunte::Apunte(string Titulo, string Contenido, string Fecha)
{
	this->Titulo = Titulo;
	this->Contenido = Contenido;
	this->Fecha = Fecha;

}
Apunte* Apunte::operator+(const Apunte* nota) {

	string newTitulo = Titulo + " + " + nota->Titulo;
	string newContenido = Contenido+" + "+nota->Contenido;
	string newFecha;
	cout << "Ingrese la fecha de la combinación: ";
	cin >> newFecha;
	Apunte* a = new Apunte(newTitulo, newContenido, newFecha);
	return a;
}

string Apunte::to_string()
{
	return "Título: "+Titulo+"\nContenido: "+Contenido+"\nFecha: "+Fecha+"\n";
}

string Apunte::getTitulo()
{
	return this->Titulo;
}

string Apunte::getContenido()
{
	return this->Contenido;
}

string Apunte::getFecha()
{
	return this->Fecha;
}

void Apunte::guardarApunte(fstream& saveArchivo)
{
	saveArchivo.write(reinterpret_cast<const char*>(&(Titulo)), sizeof(Titulo));
	saveArchivo.write(reinterpret_cast<const char*>(&(Contenido)), sizeof(Contenido));
	saveArchivo.write(reinterpret_cast<const char*>(&(Fecha)), sizeof(Fecha));
}

Apunte::~Apunte()
{
}
