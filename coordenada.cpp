#include "coordenada.h"

Coordenada operator- (const Coordenada& c1, const Coordenada& c2)
{
  return Coordenada(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
}

Coordenada operator+ (const Coordenada& c1, const Coordenada& c2)
{
  return Coordenada(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);
}

Coordenada operator* (const Coordenada&c1, const double& c)
{
  return Coordenada(c1.x * c, c1.x * c, c1.x * c);
}

Coordenada operator* (const double& c, Coordenada &c1)
{
  return c1 * c;
}

Coordenada::Coordenada()
{
  x = 0;
  y = 0;
  z = 0;
}

Coordenada::Coordenada(const Coordenada &c)
{
  x = c.x;
  y = c.y;
  z = c.z;
}

Coordenada::Coordenada(double xx = 0, double yy = 0, double zz = 0)
{
  x = xx;
  y = yy;
  z = zz;
}

inline void Coordenada::set(double xx = 0, double yy = 0, double zz = 0)
{
	x = xx;
	y = yy;
	z = zz;
}