#ifndef ESFERA_H
#define ESFERA_H

#include "Forma3D.h"
#include <iostream>
#include <string>
#include <cmath>

class Esfera : public Forma3D
{
public:
  Esfera();
  Esfera(istream &, ostream&);
  Esfera(const Coord &, double);
  ~Esfera();
  const string tipo();
  bool le(istream &);
  void escreve(ostream &);
  void desenha();
  bool move();
  bool pontoNaForma(Coord &);
  bool pontoNaForma(double x, double y, double z);
  const double area() const;
  const double volume() const;

private:
  Coord c;
  double r;
};

#endif
