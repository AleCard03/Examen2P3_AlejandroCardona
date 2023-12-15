#pragma once
#include <string>
#include <vector>
#include "Apunte.h"
#include <fstream>
using namespace std;

class Curso
{
	string Nombre;
	vector<Apunte*>apuntes;
public:
	Curso(string Nombre);
	void combinarDosApuntes();
	string getNombre();
	~Curso();
	void guardarCurso(ofstream &saveArchivo);
	vector<Apunte*> getApuntes();
	void deleteApunte(int selItem);
	void setApuntes(vector<Apunte*> newApuntes);
};

