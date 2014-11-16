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
  bool move();
  bool pontoNaForma(Coord &);
  bool pontoNaForma(double x, double y, double z);

private:
	Coord c;
	double r;
};

#endif