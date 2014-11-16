#ifndef FORMA1D_H
#define FORMA1D_H

#include "Forma.h"

class Forma1D : public Forma
{
public:
  virtual ~Forma1D();
  const double area() const;
  const double volume() const;

protected:
  Forma1D();
};

#endif