#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Forma2D.h"
#include <iostream>
#include <string>
#include <cmath>

class Triangulo : public Forma2D
{
public:
  Triangulo(istream &, ostream &);
  Triangulo(const Coord &, const Coord &, const Coord &);
  ~Triangulo();
  const string tipo();
  bool le(istream &);
  void escreve(ostream &);
  void desenha();
  bool move();
  bool pontoNaForma(Coord &);
  bool pontoNaForma(double x, double y, double z);
  const double area() const;

private:
	Coord p[3]; /* points to define a triangle */
  const int max_coord = 3; /* number max of points to define a line */
};

#endif