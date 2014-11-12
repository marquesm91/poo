#include "Linha.h"

Linha::Linha(istream &is)
{
  cout << "Constructor Linha\n";
  le(is);
  vec_dir = p[1] - p[0];
}

Linha::~Linha()
{
  cout << "destrutor Linha\n";
}

const string Linha::tipo()
{
  return "Linha";
}

void Linha::le(istream &is)
{
  size_t begin;
  size_t end;
  int it;

  for (int i = 0; i < max_coord; i++)
  {
    string str;

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
  }
}

void Linha::escreve(ostream &os)
{
  os << tipo() << endl;

  for (int i = 0; i < max_coord; i++)
    os << p[i].print() << endl;
}

bool Linha::move(const Coord &c, int value = 0)
{
  if (value > 1 && value < 0) /* if not 1 or 0 */
  {
    cout << tipo() << "so pode ser movida se params2 = 1 or 0\n";
    return false;
  }
  else
  {
    p[value].set(c.get<Coord::x>(), c.get<Coord::y>(), c.get<Coord::z>());
    vec_dir = p[1] - p[0];
    return true;
  }
}

bool Linha::move(const Coord &c1, const Coord &c2)
{
  p[1].set(c1.get<Coord::x>(), c1.get<Coord::y>(), c1.get<Coord::z>());
  p[0].set(c2.get<Coord::x>(), c2.get<Coord::y>(), c2.get<Coord::z>());

  vec_dir = p[1] - p[0];

  return true;
}

void Linha::desenha()
{
  cout << tipo() << "com os pontos p0 = " << p[0].print();
  cout << " e p1 = " << p[1].print() << endl;
  cout << "podemos montar o vetor diretor = " << vec_dir.print();
  cout << " e \"desenhar\" a nossa linha.\n";
}


bool Linha::pontoNaForma(Coord &c)
{
  cout << "p1 = p0 + t * vec_dir\n";

  cout << "p0 = " << p[0].print() << endl;
  cout << "p1 = " << p[1].print() << endl;
  cout << "vec_dir = " << vec_dir.print() << endl;
  cout << "c = " << c.print() << endl;

  Coord t = (c - p[0]) / vec_dir;
  cout << "t = " << t.print() << endl;

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
    double a = t.get<Coord::x>(); /* Could be y or z here (x = y = z) */
    cout << "\nPonto pertence a reta, pois esta na forma a" << vec_dir.print() << "\n";
    cout << "Onde a = " << a << "\n\n";
    return true;
  }
  else if (A_equals_B_equals_C == false)
  {
    cout << "\nPonto nao pertence a reta, pois esta na forma a" << t.print() << "\n";
    cout << "Onde nao existe uma constante \'a\' que seja multiplo de " << t.print() << "\n\n";
    return false;
  }
  else if (limits == false)
  {
    cout << "\nPonto nao pertence a reta, pois esta fora do intervalo dado pelos extremos\n\n";
    return false;
  }
}
