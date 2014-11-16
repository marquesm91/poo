#ifndef FORMA2D_H
#define FORMA2D_H

#include "Forma.h"

class Forma2D : public Forma
{
public:
  virtual ~Forma2D();
  const double volume() const;
  
protected:
  Forma2D();
};

#endif