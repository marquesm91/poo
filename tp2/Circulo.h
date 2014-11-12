#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma1D.h"

class Circulo : public Forma1D
{
public:
  Circulo();
  ~Circulo();
  void le(ostream &os) const;
  void escreve(istream &is);

private:

};

#endif