#include "Linha.h"

Linha::Linha(istream &is, ostream &os)
{
  cout << "Criando " << tipo() << ":\n\n";
  cout << "Para que uma " << tipo() << " exista, precisamos:\n\n\t> Dois pontos\n\t";
  cout << "> Um ponto e um vetor diretor\n\n";
  cout << "Podemos definir a equacao geral da reta sendo\n\n\t\t(x,y,z) = (a,b,c) + t * (u,v,w)\n\n";
  cout << "Onde\n\n";
  cout << "\t> t \t  : instante de tempo\n";
  cout << "\t> (a,b,c) : coordenada do ponto inicial\n";
  cout << "\t> (x,y,z) : coordenada do ponto final\n";
  cout << "\t> (u,v,w) : coordenada do vetor diretor\n\n";
  cout << "Capturando os pontos inicial e final.\n";
  le(is);
  cout << "\nMontando o vetor diretor da reta. (v = pf - pi)\n\n";
  cout << tipo() << " criada com sucesso.\n";

  if(&os != &cout)
    escreve(os);
}

Linha::~Linha()
{
  cout << "Destruindo " << tipo() << "\n";
}

const string Linha::tipo()
{
  return "Linha";
}

bool Linha::le(istream &is)
{
  string str;
  size_t begin;
  size_t end;
  int it;
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
      return false;
  }

  for (int i = 0; i < max_coord; i++)
  {
    if (i == 0)
      cout << "Coordenadas para o ponto inicial = ";
    if (i == 1)
      cout << "Coordenadas para o ponto final = ";

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

    p[i].set(point[0], point[1], point[2]);

    if (&is != &cin)
      cout << p[i].print() << endl;
  }

  v.set(p[1], p[0]); /* Set vector diretor */

  return true;
}

void Linha::escreve(ostream &os)
{
  os << tipo() << endl;

  for (int i = 0; i < max_coord; i++)
    os << p[i].print() << endl;

  os << v.print() << endl;
}

bool Linha::move(const Coord &c1, const Coord &c2)
{
  try
  {
    Coord *aux = new Coord[2];

    aux[0].set(c1.get<Coord::x>(), c1.get<Coord::y>(), c1.get<Coord::z>());
    aux[1].set(c2.get<Coord::x>(), c2.get<Coord::y>(), c2.get<Coord::z>());

    if (aux[1] == aux[0])
      throw Error(3);

    p[0].set(c1.get<Coord::x>(), c1.get<Coord::y>(), c1.get<Coord::z>());
    p[1].set(c2.get<Coord::x>(), c2.get<Coord::y>(), c2.get<Coord::z>());
    v.set(p[1], p[0]);

    delete[] aux;

    cout << tipo() << " movida com sucesso.\n";
    return true;
  }
  catch (Error &e)
  {
    e.what();
    return false;
  }
}

void Linha::desenha()
{
  cout << tipo() << " com os pontos p0 = " << p[0].print();
  cout << " e p1 = " << p[1].print();
  cout << " podemos montar o vetor diretor = " << v.print();
  cout << " e \"desenhar\" a nossa linha.\n";
}


bool Linha::pontoNaForma(Coord &c)
{
  Coord t = (c - p[0]) / v;

  /* Boolean equation for multiply 't' */
  bool A_equals_B = (t.get<Coord::x>() == t.get<Coord::y>());
  bool B_equals_C = (t.get<Coord::y>() == t.get<Coord::z>());
  bool A_equals_B_equals_C = (A_equals_B && B_equals_C);

  /* Boolean equation for check limits */
  bool lim_x = ( c.get<Coord::x>() >= p[0].get<Coord::x>() && c.get<Coord::x>() <= p[1].get<Coord::x>());
  bool lim_y = ( c.get<Coord::y>() >= p[0].get<Coord::y>() && c.get<Coord::y>() <= p[1].get<Coord::y>());
  bool lim_z = ( c.get<Coord::z>() >= p[0].get<Coord::z>() && c.get<Coord::z>() <= p[1].get<Coord::z>());
  bool limits = lim_x && lim_y && lim_z;

  if (A_equals_B_equals_C == true && limits == true)
  {
    return true;
  }
  else if (A_equals_B_equals_C == false) /* t has no type t(1,1,1)*/
  {
    return false;
  }
  else if (limits == false) /* Off limits */
  {
    return false;
  }
}
