#ifndef LINHA_H
#define LINHA_H

#include "Forma1D.h"
#include <iostream>
#include <string>

class Linha : public Forma1D
{
public:
  Linha();
  Linha(istream &, ostream &);
  Linha(const Coord &, const Coord &);
  ~Linha();
  const string tipo();
  bool le(istream &);
  void escreve(ostream &);
  void desenha();
  bool move();
  bool pontoNaForma(Coord &);
  bool pontoNaForma(double x, double y, double z);

private:
	Coord p[2]; /* points to draw the vector director */
  Coord v; /* vector director */
  const int max_coord = 2; /* number max of points to define a line */
};

#endif