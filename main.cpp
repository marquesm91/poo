#include "forma.h"
#include "coordenada.h"

int main()
{
	//Forma *l = new linhas();
	//cout << *l;
	//delete l;

	Coordenada c1(1,1,1);
	Coordenada c2(-1,-1,-1);
	Coordenada c3(1,2,3);
	Coordenada c4(c2 - c3);
	Coordenada c5 = c1*10;
	Coordenada c6 = 10*c1;
	
}