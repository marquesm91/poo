#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma1D.h"
#include <vector>

class Circulo : public Forma1D
{
public:
  Circulo(istream &, ostream&);
  ~Circulo();
  const string tipo();
  bool le(istream &);
  void escreve(ostream &);
  void desenha();
  bool move(const Coord &, const Coord &);
  bool pontoNaForma(Coord &);

private:
	Coord p[2];
	Coord n;
	double r;
};

#endif