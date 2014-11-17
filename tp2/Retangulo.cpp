#include "Retangulo.h"

Retangulo::Retangulo(istream &is, ostream &os)
{
  cout << "[Criando " << tipo() << "]\n";
  cout << "Para que um " << tipo() << " exista, precisamos:\n\n";
  cout << "\t> Dois pontos para determinar as extremidades opostas\n";
  cout << "Logo,\n\n";

  while (!le(is));

  cout << tipo() << " criado com sucesso.\n";

  if (&os != &cout)
    escreve(os);
}

Retangulo::Retangulo(const Coord &c1, const Coord &c2)
{
  p[0] = c1;
  p[1] = c2;
}

Retangulo::Retangulo()
{
  Coord zero(0, 0, 0);
  p[0] = zero;
  p[1] = zero;
}

Retangulo::~Retangulo() {}

const string Retangulo::tipo()
{
  return "Retangulo";
}

const double Retangulo::area() const
{
  return abs(p[1].get<Coord::x>() - p[0].get<Coord::x>()) * abs(p[1].get<Coord::y>() - p[0].get<Coord::y>());
}

bool Retangulo::le(istream &is)
{
  try
  {
    double x, y, z;

    for (int i = 0; i < max_coord; i++)
    {
      is >> x >> y >> z;
      p[i].set(x, y, z);
    }

    Coord vec_dir1 = p[1] - p[0];

    bool equal_points = (p[0] == p[1]);
    bool colinear_points = ((p[0].get<Coord::x>() == p[1].get<Coord::x>())
                            || (p[0].get<Coord::y>() == p[1].get<Coord::y>()));

    if (equal_points == true)
      throw Error(3);
    else if (colinear_points == true)
      throw Error(7);
    else if (p[1].get<Coord::z>() != p[0].get<Coord::z>())
      throw Error(8);

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

void Retangulo::escreve(ostream &os)
{
  os << tipo() << endl;

  for (int i = 0; i < max_coord; i++)
    os << p[i].print() << endl;
}

void Retangulo::desenha()
{
  cout << "[Desenhando " << tipo() << "]\n";
  cout << tipo() << " com pontos = " << p[0].print();
  cout << " e " << p[1].print();
  cout << " definindo seus extremos opostos\n";
}

bool Retangulo::move()
{
  try
  {
    cout << "[Movendo " << tipo() << "]\n";
    double x, y, z;
    Coord *aux = new Coord[2];
    int it = 0;

    while (it < max_coord)
    {
      cout << "Digite as novas coordenadas para o ponto " << it + 1 << " = ";
      cin >> x >> y >> z;
      aux[it].set(x, y, z);
      it++;
    }

    Coord vec_dir1 = aux[1] - aux[0];

    bool equal_points = (aux[0] == aux[1]);
    bool colinear_points = ((aux[0].get<Coord::x>() == aux[1].get<Coord::x>())
                            || (aux[0].get<Coord::y>() == aux[1].get<Coord::y>()));

    if (equal_points == true)
      throw Error(3);
    else if (colinear_points == true)
      throw Error(7);
    else if (aux[1].get<Coord::z>() != aux[0].get<Coord::z>())
      throw Error(8);

    for (int i = 0; i < max_coord; i++)
      p[i] = aux[i];

    delete[] aux;

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Retangulo::pontoNaForma(Coord &c1)
{
  try
  {
    cout << "[Verficicando se " << c1.print() << " pertence ao " << tipo() << "]\n";
    if (p[1].get<Coord::z>() != c1.get<Coord::z>())
      throw Error(5);

    if (c1.get<Coord::x>() < min(p[0].get<Coord::x>(), p[1].get<Coord::x>()))
      throw Error(4);
    if (c1.get<Coord::x>() > max(p[0].get<Coord::x>(), p[1].get<Coord::x>()))
      throw Error(4);

    if (c1.get<Coord::y>() < min(p[0].get<Coord::y>(), p[1].get<Coord::y>()))
      throw Error(4);
    if (c1.get<Coord::y>() > max(p[0].get<Coord::y>(), p[1].get<Coord::y>()))
      throw Error(4);

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Retangulo::pontoNaForma(double x, double y, double z)
{
  Coord c1(x, y, z);
  return pontoNaForma(c1);
}