#ifndef CUBO_H
#define CUBO_H

#include "Forma3D.h"
#include <iostream>
#include <string>
#include <cmath>

class Cubo : public Forma3D
{
public:
  Cubo();
  Cubo(istream &, ostream&);
  Cubo(const Coord &, double);
  ~Cubo();
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
