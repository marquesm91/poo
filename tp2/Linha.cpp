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

  is.precision(8);

  for (int i = 0; i < total_coord; i++)
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

  for (int i = 0; i < total_coord; i++)
    os << setprecision(8) << p[i].print() << endl;
}

bool Linha::move(const Coord& c, int value = 0)
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

bool Linha::move(const Coord& c1, const Coord& c2)
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
  cout << "\nPONTO NA FORMA PARA RETA R^3\n\n";
  cout << "p1 = p0 + t * vec_dir\n";
  cout << "t = (p1 - p0)/vec_dir\n";
  cout << "t será a(1,1,1) onde a pertence aos reais\n";

  cout << "p0 = " << p[0].print() << endl;
  cout << "c = " << c.print() << endl;
  cout << "vec_dir = " << vec_dir.print() << endl;

  Coord t = (c - p[0]) / vec_dir;
  cout << "t = " << t.print() << endl;

  /* if A = B and B = C, A = C. Thus, A = B = C */
  bool A_equals_B = (t.get<Coord::x>() == t.get<Coord::y>());
  bool B_equals_C = (t.get<Coord::y>() == t.get<Coord::z>());
  /* operator AND (&&) because could be return true using EQUAL (==)
       if A_equals_B and B_equal_C are false. */
  bool A_equals_B_equals_C = (A_equals_B && B_equals_C);

  if (A_equals_B_equals_C == true)
  {
    double a = t.get<Coord::x>(); /* Could be y or z here (x = y = z) */
    cout << "\nPonto pertence a reta, pois esta na forma a(1,1,1)\n";
    cout << "Com a = " << a << "\n\n";
    return true;
  }
  else
  {
    cout << "\nPonto nao pertence a reta, pois nao esta na forma a(1,1,1)\n\n";
    return false;
  }
}
