#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Coord
{
public:
  enum xyz {x = 0, y, z};

  Coord();
  Coord(double, double, double);
  Coord(const Coord &);

  template<xyz C> void set(double v);
  template<xyz C> double get() const;
  void set(double xx, double yy, double zz);

  const string print();

  friend Coord operator+ (const Coord &, const Coord &);
  friend Coord operator- (const Coord &, const Coord &);
  friend Coord operator/ (const Coord &, const Coord &);
  friend Coord operator* (const Coord &, double);
  friend Coord operator* (double, Coord &);

private:
  double vec[z + 1];
};

#endif