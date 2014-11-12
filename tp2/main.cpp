#include "Linha.h"
#include <fstream>

int main()
{
	Forma *lin = new Linha(cin);

	//ofstream f("teste.txt");
	lin->escreve(cout);
	
	Coord c(2,2,2);
	lin->pontoNaForma(c);

	//lin->move(c,0);
	//lin->pontoNaForma(c);

	delete lin;
}