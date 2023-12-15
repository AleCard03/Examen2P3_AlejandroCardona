#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Apunte
{
	string Titulo, Contenido, Fecha;
public:
	Apunte(string Titulo, string Contenido, string Fecha);
	Apunte* operator+(const Apunte* nota2);
	string to_string();
	string getTitulo();
	string getContenido();
	string getFecha();
	void guardarApunte(fstream& saveArchivo);
	~Apunte();
};

