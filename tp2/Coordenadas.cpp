#include "Coordenadas.h"

Coord& Coord::operator= (const Coord &c2)
{
  if (this != &c2)
  {
    this->set<Coord::x>(c2.get<Coord::x>());
    this->set<Coord::y>(c2.get<Coord::y>());
    this->set<Coord::z>(c2.get<Coord::z>());
  }

  return *this;
}

bool Coord::operator== (const Coord &c2)
{
  int counter = 0;
  if(this->get<Coord::x>() == c2.get<Coord::x>())
    counter++;
  if(this->get<Coord::y>() == c2.get<Coord::y>())
    counter++;
  if(this->get<Coord::z>() == c2.get<Coord::z>())
    counter++;

  if(counter == 3)
    return true;
  else
    return false;
}

Coord operator+ (const Coord &c1, const Coord &c2)
{
  return Coord(c1.get<Coord::x>() + c2.get<Coord::x>(), c1.get<Coord::y>() + c2.get<Coord::y>(), c1.get<Coord::z>() + c2.get<Coord::z>());
}

Coord operator- (const Coord &c1, const Coord &c2)
{
  return Coord(c1.get<Coord::x>() - c2.get<Coord::x>(), c1.get<Coord::y>() - c2.get<Coord::y>(), c1.get<Coord::z>() - c2.get<Coord::z>());
}

Coord operator/ (const Coord &c1, const Coord &c2)
{
  double x, y, z;
  if (c1.get<Coord::x>() == 0)
    x = 0;
  else
    x = c1.get<Coord::x>() / c2.get<Coord::x>();

  if (c1.get<Coord::y>() == 0)
    y = 0;
  else
    y = c1.get<Coord::y>() / c2.get<Coord::y>();

  if (c1.get<Coord::z>() == 0)
    z = 0;
  else
    z = c1.get<Coord::z>() / c2.get<Coord::z>();

  return Coord(x, y, z);
}

Coord operator* (const Coord &c1, double c)
{
  return Coord(c1.get<Coord::x>() * c, c1.get<Coord::y>() * c, c1.get<Coord::z>() * c);
}

Coord operator* (double c, Coord &c1)
{
  return c1 * c;
}

Coord::Coord()
{
  set(0, 0, 0);
}

Coord::Coord(const Coord &c)
{
  vec[x] = c.get<x>();
  vec[y] = c.get<y>();
  vec[z] = c.get<z>();
}

Coord::Coord(double x = 0, double y = 0, double z = 0)
{
  set(x, y, z);
}

template<Coord::xyz C> void Coord::set(double v)
{
  vec[C] = v;
}

template<Coord::xyz C> double Coord::get() const
{
  return vec[C];
}

void Coord::set(double xx, double yy, double zz)
{
  set<x>(xx);
  set<y>(yy);
  set<z>(zz);
}

const string Coord::print()
{
  ostringstream str, xx, yy, zz;

  xx << get<x>();
  yy << get<y>();
  zz << get<z>();

  str << xx.str() << " " << yy.str() << " " << zz.str();

  return str.str();
}