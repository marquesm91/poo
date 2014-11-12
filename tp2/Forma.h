#ifndef FORMA_H
#define FORMA_H

#include "Coordenadas.h" /* Coordenadas contain Forma*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Forma
{
public:
  virtual ~Forma();
  virtual void move() = 0;
  virtual void desenha(const Coord &, const Coord &) = 0;
  virtual double area() const = 0;
  virtual double volume() const = 0;
  virtual bool pontoNaForma(const Coord &) const = 0;
  virtual const string tipo() = 0;
  virtual void le(ostream &) const = 0;
  virtual void escreve(istream &) = 0;
  friend ostream &operator <<(ostream &, const Forma &);
  friend istream &operator >>(istream &, Forma &);

protected:
  Forma();
};

#endif