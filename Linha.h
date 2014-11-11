#ifndef LINHA_H
#define LINHA_H

#include "Forma1D.h"

class Linha : public Forma1D
{
public:
  Linha();
  ~Linha();
  //void le(ostream &) const;
  //void escreve(istream &);
  //void desenha(const Coord &c1, const Coord &c2);
  //void move();
  //bool pontoNaForma(const Coord &c) const;

private:
	Coord p; /* point to draw the vector director */
  Coord p0; /* initial point of line */
  Coord vec_dir; /* vector director */
};

#endif