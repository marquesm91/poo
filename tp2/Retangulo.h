#ifndef RETANGULO_H
#define RETANGULO_H

#include "Forma2D.h"
#include <iostream>
#include <string>
#include <cmath>

class Retangulo : public Forma2D
{
public:
  Retangulo();
  Retangulo(istream &, ostream &);
  Retangulo(const Coord &, const Coord &);
  ~Retangulo();
  const string tipo();
  bool le(istream &);
  void escreve(ostream &);
  void desenha();
  bool move();
  bool pontoNaForma(Coord &);
  bool pontoNaForma(double x, double y, double z);
  const double area() const;

private:
	Coord p[2];
	const int max_coord = 2;
};

#endif