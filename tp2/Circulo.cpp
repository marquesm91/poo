#include "Circulo.h"
#include <cmath>

Circulo::Circulo(istream &is, ostream &os)
{
  cout << "Criando " << tipo() << ":\n\n";
  cout << "Para que um " << tipo() << " exista, precisamos:\n\n";
  cout << "\t> Coordenadas do centro e um ponto no espaco\n";
  cout << "\t> Um plano que contem os dois pontos\n\n";
  cout << "Podemos definir a equacao geral do círculo sendo";
  cout << "\n\n\t\t(x-cx)^2 + (y-cy)^2 + (z-cz)^2 = r^2\n";
  cout << "Onde\n\n";
  cout << "\t> r \t  : raio do circulo\n";
  cout << "\t> (cx,cy,cz) : coordenadas do centro\n";
  cout << "\t> (x,y,z) : coordenadas de um ponto\n";
  cout << "\t> Os pontos devem estar contidos em um plano ax + by + cz + d = 0\n\n";
  cout << "Capturando os pontos necessarios.\n";
  le(is);
  cout << "\nDefinindo o raio do circulo pela equacao.\n\n";
  cout << tipo() << " criado com sucesso.\n";

  if (&os != &cout)
    escreve(os);
}

Circulo::~Circulo()
{
  cout << "Destruindo" << tipo() << "\n";
}

const string Circulo::tipo()
{
  return "Circulo";
}

bool Circulo::le(istream &is)
{
  try
  {


    string str;

    bool find_type = false;

    /* Search for Circulo */
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

    Coord *aux = new Coord[2];

    size_t begin;
    size_t end;
    int it;

    /* fill the two aux coordinates */
    for (int i = 0; i < 2; i++)
    {
      if (i == 0)
        cout << "Coordenadas para o centro = ";
      if (i == 1)
        cout << "Coordenadas para um ponto pertencente ao circulo = ";

      str.clear();

      getline(is, str);

      double point[3] = {0, 0 , 0};

      it = 0;
      end = 0;

      while (true)
      {
        begin = end;
        if ((end = str.find(" ", begin)) == string::npos)
        {
          point[it] = atof((str.substr(begin)).c_str());
          break;
        }
        else
          point[it] = atof((str.substr(begin, end)).c_str());

        end++;
        it++;
      }

      aux[i].set(point[0], point[1], point[2]);

      if (&is != &cin)
        cout << aux[i].print() << endl;
    }

    c = aux[0];

    r = sqrt(pow(aux[1].get<Coord::x>() - c.get<Coord::x>(), 2)
             + pow(aux[1].get<Coord::y>() - c.get<Coord::y>(), 2));

    delete[] aux;

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

void Circulo::escreve(ostream &os)
{
    os << tipo() << endl;
    os << c.print() << endl;
    os << r << endl;
}

void Circulo::desenha()
{
  cout << tipo() << " com os pontos c = " << c.print();
  cout << " e r = " << r << " sendo o centro e raio.\n";
}

bool Circulo::move()
{
  try
  {
    double x, y, z;
    Coord *new_c = new Coord();

    cout << "Digite as novas coordenadas para o centro = ";
    cin >> x >> y >> z;
    new_c->set(x, y, z);

    if (*new_c == c)
      throw Error(3);

    c = *new_c;

    delete[] new_c;

    cout << tipo() << " movida com sucesso.\n";
    desenha();

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Circulo::pontoNaForma(Coord &c1)
{
  try
  {
    if (c1.get<Coord::z>() != c.get<Coord::z>())
      throw Error(4);

    double x_cx = c1.get<Coord::x>() - c.get<Coord::x>();
    double y_cy = c1.get<Coord::y>() - c.get<Coord::y>();
    double p = sqrt(pow(x_cx, 2) + pow(y_cy, 2));

    return (p == r);
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Circulo::pontoNaForma(double x, double y, double z)
{
  Coord c1(x, y, z);
  return pontoNaForma(c1);
}