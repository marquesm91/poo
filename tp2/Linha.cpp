#include "Linha.h"

Linha::Linha()
{
  cout << "Constructor Linha\n";
}

Linha::~Linha()
{
  cout << "destrutor Linha\n";
}

/*void Linha::le(ostream &os) const
{
  os << "Linha coordinates:\n";
  for (int i = 0; i < max_coord; i++)
    os << "c" << i << " = (" << c[i].x << "," << c[i].y << "," << c[i].z << ")\n";
}

void Linha::escreve(istream &is)
{
  string input;

  if (&is == &std::cin)
  {

    for (int i = 0; i < max_coord; i++)
    {
      input.clear();
      is >> input;

      c[i].x = (input[0] - '0') % 48;
      c[i].y = (input[2] - '0') % 48;
      c[i].z = (input[4] - '0') % 48;
    }
  }
  else
  {
    is >> input;

  }

}

void Linha::desenha(const coord &c1, const coord &c2)
{
  cout << "Linha com extremos em c1 = (" << c1.x << "," << c1.y << "," << c1.z << ") ";
  cout << "e c2 = (" << c2.x << "," << c2.y << "," << c2.z << ")\n";
}*/