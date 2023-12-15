#pragma once
#include <string>
#include <vector>
using namespace std;

class Curso
{
	string Nombre;
	vector<Apunte*>apuntes;
public:
	Curso(string Nombre);
	void combinarDosApuntes();
	~Curso();
};

