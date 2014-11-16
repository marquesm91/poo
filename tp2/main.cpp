#include "Linha.h"
#include "Circulo.h"
#include <fstream>

void TestingLinha()
{
  ifstream in("in.txt");
  ofstream out("out.txt");

  if (!in.is_open())
    throw Error(0);

  Forma *lin = new Linha(cin, cout);

  Coord c(1, 1, 1);
  Coord c1(2, 2, 2);
  lin->move(c, c);
  lin->move(c1, c);
  lin->desenha();

  Coord c3(4, 5, 6);
  if (lin->pontoNaForma(c3))
    cout << "Ponto pertence a forma.\n";
  else
    throw Error(4);

  delete lin;
}

void TestingCircle()
{
	Forma *circ = new Circulo(cin, cout);

	delete circ;
}

int main()
{
  try
  {
    //TestingLinha();
    TestingCircle();
  }
  catch (Error &e)
  {
    e.what();
  }
}