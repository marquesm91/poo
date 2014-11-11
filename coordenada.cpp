#include "coordenada.h"

int Coordenada::counter = 0;

Coordenada Coordenada::operator- (const Coordenada& c)
{
  return Coordenada(this->x - c.x, this->y - c.y, this->z - c.z);
}

Coordenada Coordenada::operator+ (const Coordenada& c)
{
  return Coordenada(this->x + c.x, this->y + c.y, this->z + c.z);
}

Coordenada operator* (const Coordenada&c1, const double& c)
{
  return Coordenada(c1.x * c, c1.x * c, c1.x * c);
}

Coordenada operator* (const double& c, Coordenada &c1)
{
  return c1 * c;
}

Coordenada::Coordenada(double xx = 0, double yy = 0, double zz = 0)
{
  x = xx;
  y = yy;
  z = zz;
  counter++;
  name = "c" + to_string(counter);
  std::cout << "Create " << name << "\n";
}

Coordenada::Coordenada(const Coordenada &c)
{
  x = c.x;
  y = c.y;
  z = c.z;
  name = "copy of " + c.name;
  std::cout << "Create " << name << "\n";
}

Coordenada::~Coordenada()
{
  std::cout << "Destroy " << name << "\n";
  std::cout << x << " " << y << " " << z << "\n";
  counter--;
}