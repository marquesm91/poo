#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>
#include <string>

using namespace std;

class Coordenada
{
  double x;
  double y;
  double z;
  string name;
  static int counter;

public:
  Coordenada(double, double, double);
  Coordenada(const Coordenada &);
  ~Coordenada();

  Coordenada operator+ (const Coordenada&);
  Coordenada operator- (const Coordenada&);
  friend Coordenada operator* (const Coordenada&, const double&);
  friend Coordenada operator* (const double&, Coordenada&);
};

#endif