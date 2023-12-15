#pragma once
#include <string>
#include <iostream>
using namespace std;
class Apunte
{
	string Titulo, Contenido, Fecha;
public:
	Apunte(string Titulo, string Contenido, string Fecha);
	Apunte* operator+(Apunte nota2);
	string to_string();

	~Apunte();
};

