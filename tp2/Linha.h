#ifndef LINHA_H
#define LINHA_H

#include "Forma1D.h"

class Linha : public Forma1D
{
public:
  Linha(istream &, ostream &);
  ~Linha();
  const string tipo();
  bool le(istream &);
  void escreve(ostream &);
  void desenha();
  bool move(const Coord &, const Coord &);
  bool pontoNaForma(Coord &);

private:
	Coord p[2]; /* points to draw the vector director */
  Coord v; /* vector director */
  const int max_coord = 2; /* number max of points to define a line */
};

#endif