#include "Cubo.h"

Cubo::Cubo(istream &is, ostream &os)
{
  cout << "[Criando " << tipo() << "]\n";
  cout << "Para que um " << tipo() << " exista, precisamos:\n\n";
  cout << "\t> Um ponto central para o cubo (\"centro\")\n";
  cout << "\t> A distancia entre todas as extremidades (\"raio\")\n";
  cout << "Logo,\n\n";

  while (!le(is));

  cout << tipo() << " criado com sucesso.\n";

  if (&os != &cout)
    escreve(os);
}

Cubo::Cubo(const Coord &c1, double raio)
{
  c = c1;
  r = raio;
}

Cubo::Cubo()
{
  Coord c1(0, 0, 0);
  c = c1;
  r = 0;
}

Cubo::~Cubo() {}

const string Cubo::tipo()
{
  return "Cubo";
}

const double Cubo::area() const
{
  return 24  * r * r;
}

const double Cubo::volume() const
{
  return 8 * r * r * r;
}

bool Cubo::le(istream &is)
{
  try
  {
    double x, y, z, raio;
    is >> x >> y >> z;
    c.set(x, y, z);
    is >> raio;
    r = raio;

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

void Cubo::escreve(ostream &os)
{
  os << tipo() << "\n";
  os << c.print() << "\n";
  os << r << "\n";
}

void Cubo::desenha()
{
  cout << "[Desenhando " << tipo() << "]\n";
  cout << tipo() << " com o \"centro\" = " << c.print();
  cout << " e \"raio\" = " << r << "\n";
}

bool Cubo::move()
{
  try
  {
    cout << "[Movendo " << tipo() << "]\n";

    double x, y, z;
    Coord *new_c = new Coord();

    cout << "Digite as novas coordenadas para o \"centro\" = ";
    cin >> x >> y >> z;
    new_c->set(x, y, z);

    if (*new_c == c)
      throw Error(3);

    c = *new_c;

    delete[] new_c;

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Cubo::pontoNaForma(Coord &c1)
{
  try
  {
    cout << "[Verficicando se " << c1.print() << " pertence ao " << tipo() << "]\n";

    if ((c1.get<Coord::x>() < (c.get<Coord::x>() - r)) || (c1.get<Coord::x>() > (c.get<Coord::x>() + r)))
      throw Error(9);
    if ((c1.get<Coord::y>() < (c.get<Coord::y>() - r)) || (c1.get<Coord::y>() > (c.get<Coord::y>() + r)))
      throw Error(9);
    if ((c1.get<Coord::z>() < (c.get<Coord::z>() - r)) || (c1.get<Coord::z>() > (c.get<Coord::z>() + r)))
      throw Error(9);

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Cubo::pontoNaForma(double x, double y, double z)
{
  Coord c1(x, y, z);
  return pontoNaForma(c1);
}