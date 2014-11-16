#include "Esfera.h"

Esfera::Esfera(istream &is, ostream &os)
{
  cout << "[Criando " << tipo() << "]\n";
  cout << "Para que uma " << tipo() << " exista, precisamos:\n\n";
  cout << "\t> Coordenadas do centro e um ponto no espaco\n";
  cout << "\t> Coordenadas do centro e o valor do raio\n";
  cout << "Logo,\n\n";
    
  while (!le(is));
  
  cout << tipo() << " criado com sucesso.\n";

  if (&os != &cout)
    escreve(os);
}

Esfera::Esfera(const Coord &c1, double raio)
{
  c = c1;
  r = raio;
}

Esfera::~Esfera() {}

const string Esfera::tipo()
{
  return "Esfera";
}

const double Esfera::area() const
{
	return 4 * M_PI * r * r;
}

const double Esfera::volume() const
{
return (4 * M_PI * r * r * r) / 3.0;
}

bool Esfera::le(istream &is)
{
  try
  {
    string str;

    bool find_type = false;

    /* Search for Esfera */
    if (&is != &cin)
    {
      while (getline(is, str))
      {
        if (str == tipo())
        {
          find_type = true;
          break;
        }
      }

      if (find_type == false)
        throw Error(5);
    }

    double x, y, z, raio;

    cout << "Digite as coordenadas para o centro = ";
    cin >> x >> y >> z;
    c.set(x, y, z);

    cout << "Digite o valor do raio = ";
    cin >> raio;
    r = raio;

    if (&is != &cin)
    {
      cout << "centro do Esfera = " << c.print() << endl;
      cout << "raio do Esfera = " << r << endl;
    }

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

void Esfera::escreve(ostream &os)
{
  os << tipo() << "\n";
  os << c.print() << "\n";
  os << r << "\n";
  os << "\n";
}

void Esfera::desenha()
{
  cout << "[Desenhando " << tipo() << "]\n";
  cout << tipo() << " com o centro = " << c.print();
  cout << " e raio = " << r << "\n";
}

bool Esfera::move()
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

bool Esfera::pontoNaForma(Coord &c1)
{
  try
  {
    cout << "[Verficicando se " << c1.print() << " pertence a " << tipo() << "]\n";

    double x_cx = c1.get<Coord::x>() - c.get<Coord::x>();
    double y_cy = c1.get<Coord::y>() - c.get<Coord::y>();
    double z_cz = c1.get<Coord::z>() - c.get<Coord::z>();
    double p = sqrt(pow(x_cx, 2) + pow(y_cy, 2) + pow(z_cz, 2));

    if (p > r)
      throw Error(5);

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Esfera::pontoNaForma(double x, double y, double z)
{
  Coord c1(x, y, z);
  return pontoNaForma(c1);
}