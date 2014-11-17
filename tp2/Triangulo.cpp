#include "Triangulo.h"

Triangulo::Triangulo(istream &is, ostream &os)
{
  cout << "[Criando " << tipo() << "]\n";
  cout << "Para que um " << tipo() << " exista, precisamos:\n\n";
  cout << "\t> Tres pontos para determinar as extremidades\n";
  cout << "Logo,\n\n";

  while (!le(is));

  cout << tipo() << " criado com sucesso.\n";

  if (&os != &cout)
    escreve(os);
}

Triangulo::Triangulo(const Coord &c1, const Coord &c2, const Coord &c3)
{
  p[0] = c1;
  p[1] = c2;
  p[2] = c3;
}

Triangulo::Triangulo()
{
  Coord zero(0, 0, 0);
  p[0] = zero;
  p[1] = zero;
  p[2] = zero;
}

Triangulo::~Triangulo() {}

const string Triangulo::tipo()
{
  return "Triangulo";
}

const double Triangulo::area() const
{
  double d1, d2, d3, s;

  /* Using Theorem of Heron */
  d1 = sqrt(pow(p[0].get<Coord::x>() - p[1].get<Coord::x>(), 2)
            + pow(p[0].get<Coord::y>() - p[1].get<Coord::y>(), 2)
            + pow(p[0].get<Coord::z>() - p[1].get<Coord::z>(), 2));

  d2 = sqrt(pow(p[0].get<Coord::x>() - p[2].get<Coord::x>(), 2)
            + pow(p[0].get<Coord::y>() - p[2].get<Coord::y>(), 2)
            + pow(p[0].get<Coord::z>() - p[2].get<Coord::z>(), 2));

  d3 = sqrt(pow(p[1].get<Coord::x>() - p[2].get<Coord::x>(), 2)
            + pow(p[1].get<Coord::y>() - p[2].get<Coord::y>(), 2)
            + pow(p[1].get<Coord::z>() - p[2].get<Coord::z>(), 2));

  s = (d1 + d2 + d3) / 2.0;

  return sqrt(s * (s - d1) * (s - d2) * (s - d3));
}

bool Triangulo::le(istream &is)
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
    Coord vec_dir2 = p[2] - p[0];

    Coord t2 = (p[2] - p[0]) / vec_dir2;
    Coord t1 = (p[1] - p[0]) / vec_dir1;

    bool equal_points = (p[0] == p[1] || p[0] == p[2] || p[1] == p[2]);
    bool colinear_points = (t2 == t1);

    if (equal_points == true)
      throw Error(3);
    else if (colinear_points == true)
      throw Error(7);

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

void Triangulo::escreve(ostream &os)
{
  os << tipo() << endl;

  for (int i = 0; i < max_coord; i++)
    os << p[i].print() << endl;
}

void Triangulo::desenha()
{
  cout << "[Desenhando " << tipo() << "]\n";
  cout << tipo() << " com pontos = " << p[0].print();
  cout << ", " << p[1].print();
  cout << " e " << p[2].print() << " definindo suas extremidades\n";
}

bool Triangulo::move()
{
  try
  {
    cout << "[Movendo " << tipo() << "]\n";
    double x, y, z;
    Coord *aux = new Coord[3];
    int it = 0;

    while (it < max_coord)
    {
      cout << "Digite as novas coordenadas para o ponto " << it + 1 << " = ";
      cin >> x >> y >> z;
      aux[it].set(x, y, z);
      it++;
    }

    Coord vec_dir1 = aux[1] - aux[0];
    Coord vec_dir2 = aux[2] - aux[0];

    Coord t2 = (aux[2] - aux[0]) / vec_dir2;
    Coord t1 = (aux[1] - aux[0]) / vec_dir1;

    bool equal_points = (aux[0] == aux[1] || aux[0] == aux[2] || aux[1] == aux[2]);
    bool colinear_points = (t2 == t1);

    if (equal_points == true)
      throw Error(3);
    else if (colinear_points == true)
      throw Error(7);

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

bool Triangulo::pontoNaForma(Coord &c1)
{
  try
  {
    cout << "[Verficicando se " << c1.print() << " pertence ao " << tipo() << "]\n";
    Triangulo *a, *b, *c;
    bool r;

    a = new Triangulo(p[0], p[1], c1);
    b = new Triangulo(p[0], p[3], c1);
    c = new Triangulo(p[2], p[3], c1);

    /* If a point is inside the triangle then the total area is equal to the 3 triangles's area */
    r = ((round(this->area() * 100000) / 100000) == (round((a->area() + b->area() + c->area()) * 100000) / 100000));

    delete a;
    delete b;
    delete c;

    if (r == false)
      throw Error(9);

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Triangulo::pontoNaForma(double x, double y, double z)
{
  Coord c1(x, y, z);
  return pontoNaForma(c1);
}