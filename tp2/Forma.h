#ifndef FORMA_H
#define FORMA_H

#include "Coordenadas.h" /* Coordenadas contain Forma*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Forma
{
public:
  virtual ~Forma();
  //virtual void move() = 0;
  //virtual void desenha(const Coord &, const Coord &) = 0;
  virtual double area() const = 0;
  virtual double volume() const = 0;
  virtual bool pontoNaForma(Coord &) = 0;
  virtual const string tipo() = 0;
  virtual void le(istream &) = 0;
  virtual void escreve(ostream &) = 0;
  friend ostream &operator <<(ostream &, Forma &);
  friend istream &operator >>(istream &, Forma &);

protected:
  Forma();
};

#endif