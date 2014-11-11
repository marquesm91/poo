#include "forma.h"
#include "coordenada.h"

int main()
{
	//Forma *l = new linhas();
	//cout << *l;
	//delete l;
	Forma *l = new linhas();
	Coordenada vetor_dir(1,-3,-5);
	Coordenada ponto_ini(0,0,0);
	// (x,y,z) = (0,0,0) + t(1,-3,-5)
	// x =  t
	// y = -3t
	// z = -5t
	// x = y/-3 = z/-5
	// 1 = 1/-3 = 1/-5 (F) Ponto (1,1,1) nao pertence a reta
	// 1 = -3/-3 = -5/-5 (V) Ponto (1,-3,-5) pertence a reta. Qualquer multiplo!
	Coordenada c1(1,1,1);
	Coordenada c2(-1,-1,-1);
	Coordenada c3(1,2,3);
	Coordenada c4(c2 - c3);
	Coordenada c5 = c1*10;
	Coordenada c6 = 10*c1;
	
}