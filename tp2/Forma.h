#ifndef FORMA_H
#define FORMA_H

#include "Coordenadas.h" /* Coordenadas contain Forma */
#include "Error.h"       /* Class for handle errors */
#include <iostream>

using namespace std;

class Forma
{
public:
  virtual ~Forma();
  virtual bool move() = 0;
  virtual void desenha() = 0;
  virtual const double area() const = 0;
  virtual const double volume() const = 0;
  virtual bool pontoNaForma(Coord &) = 0;
  virtual bool pontoNaForma(double x, double y, double z) = 0;
  virtual const string tipo() = 0;
  virtual bool le(istream &) = 0;
  virtual void escreve(ostream &) = 0;
  friend ostream &operator <<(ostream &, Forma &);
  friend istream &operator >>(istream &, Forma &);

protected:
  Forma();
};

#endif