#include "Linha.h"

Linha::Linha(istream &is, ostream &os)
{
  cout << "[Criando " << tipo() << "]\n";
  cout << "Para que uma " << tipo() << " exista, precisamos:\n\n\t> Dois pontos\n\t";
  cout << "> Um ponto e um vetor diretor\n\n";
  cout << "Logo,\n\n";
    
  while (!le(is));
  
  cout << tipo() << " criada com sucesso.\n";

  if (&os != &cout)
    escreve(os);
}

Linha::Linha(const Coord &c1, const Coord &c2)
{
  p[0] = c1;
  p[1] = c2;
}

Linha::~Linha() {}

const string Linha::tipo()
{
  return "Linha";
}

bool Linha::le(istream &is)
{
  try
  {
    string str;
    bool find_type = false;

    /* Search for Linha */
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

    double x, y, z;

    for (int i = 0; i < max_coord; i++)
    {
      if (i == 0)
        cout << "Digite as coordenadas para o ponto inicial = ";
      if (i == 1)
        cout << "Digite as coordenadas para o ponto final = ";
      cin >> x >> y >> z;

      p[i].set(x, y, z);
    }

    cout << "Montando o vetor diretor da reta. (v = pf - pi)\n";
    v = p[1] - p[0]; /* Set vector diretor */

    if (&is != &cin)
    {
      cout << "ponto incial= " << p[0].print() << endl;
      cout << "ponto final = " << p[1].print() << endl;
      cout << "vetor diretor = " << v.print() << endl;
    }

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

void Linha::escreve(ostream &os)
{
  os << tipo() << endl;

  for (int i = 0; i < max_coord; i++)
    os << p[i].print() << endl;

  os << "\n";
}

void Linha::desenha()
{
  cout << "[Desenhando " << tipo() << "]\n";
  cout << tipo() << " com ponto inicial = " << p[0].print();
  cout << " , ponto final = " << p[1].print();
  cout << " e vetor diretor = " << v.print() << "\n";
}

bool Linha::move()
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

    if (aux[0] == aux[1])
      throw Error(3);

    for (int i = 0; i < max_coord; i++)
      p[i] = aux[i];

    v = p[1] -  p[0];

    delete[] aux;

    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Linha::pontoNaForma(Coord &c)
{
  try
  {
    cout << "[Verficicando se " << c.print() << " pertence a " << tipo() << "]\n";

    Coord t_real = (p[1] - p[0]) / v;
    Coord t = (c - p[0]) / v;

    /* Boolean equation for multiply 't' */
    bool t_equals = (t_real == t);

    /* Boolean equation for check limits */
    bool lim_x, lim_y, lim_z;

    if (p[0].get<Coord::x>() < p[1].get<Coord::x>())
      lim_x = (c.get<Coord::x>() >= p[0].get<Coord::x>() && c.get<Coord::x>() <= p[1].get<Coord::x>());
    else
      lim_x = (c.get<Coord::x>() >= p[1].get<Coord::x>() && c.get<Coord::x>() <= p[0].get<Coord::x>());

    if (p[0].get<Coord::y>() < p[1].get<Coord::y>())
      lim_y = (c.get<Coord::y>() >= p[0].get<Coord::y>() && c.get<Coord::y>() <= p[1].get<Coord::y>());
    else
      lim_y = (c.get<Coord::y>() >= p[1].get<Coord::y>() && c.get<Coord::y>() <= p[0].get<Coord::y>());

    if (p[0].get<Coord::z>() < p[1].get<Coord::z>())
      lim_z = (c.get<Coord::z>() >= p[0].get<Coord::z>() && c.get<Coord::z>() <= p[1].get<Coord::z>());
    else
      lim_z = (c.get<Coord::z>() >= p[1].get<Coord::z>() && c.get<Coord::z>() <= p[0].get<Coord::z>());

    if ((lim_x && lim_y && lim_z) == false) /* t has no type t(1,1,1)*/
      throw Error(4);
    else if (t_equals == false) /* Off limits */
      throw Error(5);
    else
      return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

bool Linha::pontoNaForma(double x, double y, double z)
{
  Coord c1(x, y, z);
  return pontoNaForma(c1);
}