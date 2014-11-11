#include "Forma.h"

ostream &operator <<(ostream &os, const Forma &f)
{
  f.le(os);
  return os;
}

istream &operator >>(istream &is, Forma &f)
{
  f.escreve(is);
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