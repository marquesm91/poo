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

public:
	Coordenada();
  Coordenada(double, double, double);
  Coordenada(const Coordenada &);

  void set(double, double, double);
  void set_x(double);
  void set_y(double);
  void set_z(double);

  friend Coordenada operator+ (const Coordenada&, const Coordenada&);
  friend Coordenada operator- (const Coordenada&, const Coordenada&);
  friend Coordenada operator* (const Coordenada&, const double&);
  friend Coordenada operator* (const double&, Coordenada&);
};


/*class Coord
{
public:
  enum xyz {x = 0, y, z};

  Coord() : vec{x, y, z} {}

  template<xyz C> void set(double v) { vec[C] = v; }
  template<xyz C> double get() const { return vec[C]; }

  void set(double xx, double yy, double zz)
  {
    set<Coord::x>(xx);
    set<Coord::y>(yy);
    set<Coord::z>(zz);
  }

private:
  double vec[z + 1];
};
*/
#endif