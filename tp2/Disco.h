#ifndef DISCO_H
#define DISCO_H

#include "Forma2D.h"
#include <iostream>
#include <string>
#include <cmath>

class Disco : public Forma2D
{
public:
  Disco(istream &, ostream &);
  Disco(const Coord &, double);
  ~Disco();
  const string tipo();
  bool le(istream &);
  void escreve(ostream &);
  void desenha();
  bool move();
  bool pontoNaForma(Coord &);
  bool pontoNaForma(double x, double y, double z);
  const double area() const;

private:
	Coord c;
	double r;
};

#endif