#include "Linha.h"
#include "Circulo.h"
#include "Triangulo.h"
#include "Retangulo.h"
#include "Disco.h"
#include "Esfera.h"
#include <fstream>

int main()
{
  string str;
  Forma *f;
  cout << "Forma : ";
  cin >> str;

  if (str == "Linha")
    f = new Linha(cin, cout);
  else if (str == "Circulo")
    f = new Circulo(cin, cout);
  else if (str == "Retangulo")
    f = new Retangulo(cin, cout);
  else if (str == "Triangulo")
    f = new Triangulo(cin, cout);
  else if (str == "Disco")
    f = new Disco(cin, cout);
  else if (str == "Esfera")
    f = new Esfera(cin, cout);
  //else if (str == "Cubo")
  //  f = new Cubo(cin, cout);

  cout << "Area = " << f->area() << "\n";
  cout << "Volume = " << f->volume() << "\n";

  while (!f->move());
  f->desenha();

  if (f->pontoNaForma(2, 2, 2))
    cout << "Ponto pertence a forma!\n";

  cout << "Area = " << f->area() << "\n";
  cout << "Volume = " << f->volume() << "\n";

  delete f;
}