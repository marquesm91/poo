#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma1D.h"
#include <iostream>
#include <string>
#include <cmath>

class Circulo : public Forma1D
{
public:
  Circulo();
  Circulo(istream &, ostream&);
  Circulo(const Coord &, double);
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