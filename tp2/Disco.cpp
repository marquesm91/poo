#include "Disco.h"

Disco::Disco(istream &is, ostream &os)
{
  cout << "[Criando " << tipo() << "]\n";
  cout << "Para que um " << tipo() << " exista, precisamos:\n\n";
  cout << "\t> Coordenadas do centro e um ponto no espaco\n";
  cout << "\t> Um plano que contem os dois pontos\n\n";
  cout << "Logo,\n\n";

  while (!le(is));

  cout << tipo() << " criado com sucesso.\n";

  if (&os != &cout)
    escreve(os);
}

Disco::Disco(const Coord &c1, double raio)
{
  c = c1;
  r = raio;
}

Disco::Disco()
{
  Coord c1(0, 0, 0);
  c = c1;
  r = 0;
}

Disco::~Disco() {}

const string Disco::tipo()
{
  return "Disco";
}

const double Disco::area() const
{
  return M_PI * r * r;
}

bool Disco::le(istream &is)
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

void Disco::escreve(ostream &os)
{
  os << tipo() << "\n";
  os << c.print() << "\n";
  os << r << "\n";
}

void Disco::desenha()
{
  cout << "[Desenhando " << tipo() << "]\n";
  cout << tipo() << " com o centro = " << c.print();
  cout << " e raio = " << r << "\n";
}

bool Disco::move()
{
  try
  {
    cout << "[Movendo " << tipo() << "]\n";

    double x, y, z;
    Coord *new_c = new Coord();

    cout << "Digite as novas coordenadas para o centro = ";
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

bool Disco::pontoNaForma(Coord &c1)
{
  try
  {
    cout << "[Verficicando se " << c1.print() << " pertence ao " << tipo() << "]\n";

    if (c1.get<Coord::z>() != c.get<Coord::z>())
      throw Error(5);

    double x_cx = c1.get<Coord::x>() - c.get<Coord::x>();
    double y_cy = c1.get<Coord::y>() - c.get<Coord::y>();
    double p = sqrt(pow(x_cx, 2) + pow(y_cy, 2));

    if (p > r)
      throw Error(9);

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Disco::pontoNaForma(double x, double y, double z)
{
  Coord c1(x, y, z);
  return pontoNaForma(c1);
}