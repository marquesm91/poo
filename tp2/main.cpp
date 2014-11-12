#include "Linha.h"
#include <fstream>

int main()
{
	Forma *lin = new Linha(cin);

	//ofstream f("teste.txt");
	lin->escreve(cout);
	
	Coord c(1,1,1);
	lin->pontoNaForma(c);

	delete lin;
}