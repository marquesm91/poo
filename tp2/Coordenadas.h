#ifndef COORDENADAS_H
#define COORDENADAS_H

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

  const string print();

  template<xyz C> void set(double v);
  template<xyz C> double get() const;
  void set(double xx, double yy, double zz);
  void set(const Coord&, const Coord&);

  friend Coord operator+ (const Coord &, const Coord &);
  friend Coord operator- (const Coord &, const Coord &);
  friend Coord operator/ (const Coord &, const Coord &);
  friend Coord operator* (const Coord &, double);
  friend Coord operator* (double, Coord &);
  Coord& operator= (const Coord &);
  bool operator== (const Coord&);

private:
  double vec[z + 1];
};

#endif