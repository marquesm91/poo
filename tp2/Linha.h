#ifndef LINHA_H
#define LINHA_H

#include "Forma1D.h"

class Linha : public Forma1D
{
public:
  Linha(istream &);
  ~Linha();
  const string tipo();
  void le(istream &);
  void escreve(ostream &);
  void desenha();
  bool move(const Coord&, int);
  bool move(const Coord&, const Coord&);
  bool pontoNaForma(Coord &);

private:
  /* p1 = p0 + t * vec_dir */

	Coord p[2]; /* points to draw the vector director */
  Coord vec_dir; /* vector director */
  const int total_coord = 2; /* number max of points to define a line */
};

#endif