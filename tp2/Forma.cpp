#include "Forma.h"

ostream &operator <<(ostream &os, Forma &f)
{
  f.escreve(os);
  return os;
}

istream &operator >>(istream &is, Forma &f)
{
  f.le(is);
  return is;
}

Forma::Forma()
{
  cout << "Inside class Forma\n";
};

Forma::~Forma()
{
  cout << "Destrutor Forma\n";
};