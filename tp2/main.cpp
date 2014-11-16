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
  lin->move();
  lin->move();
  lin->desenha();

  Coord c3(4, 5, 6);
  if (lin->pontoNaForma(c3))
    cout << "Ponto pertence a forma.\n";

  delete lin;
}

void TestingCircle()
{
  Forma *circ = new Circulo(cin, cout);

  Coord c1(4, 4, 0);	
  if (circ->pontoNaForma(4.0, 4.0, 0))
    cout << "Ponto pertence a forma.\n";

  circ->move();

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