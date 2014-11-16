#include "Circulo.h"

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
  cout << "Capturando os pontos inicial e final.\n";
  le(is);
  cout << "\nMontando o vetor diretor da reta. (v = pf - pi)\n\n";
  cout << tipo() << " criado com sucesso.\n";

  if (&os != &cout)
    escreve(os);
}

Circulo::~Circulo()
{
  cout << "Destrutor Circulo\n";
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
    size_t begin;
    size_t end;
    int it;
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
        throw Error(6);
    }

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

      p[i].set(point[0], point[1], point[2]);

      if (&is != &cin)
        cout << p[i].print() << endl;
    }

    n.set(p[1], p[0]); /* Set vector diretor */

    return true;
  }
  catch(Error &e)
  {
  	e.what();
  	return false;
  }
}

void Circulo::escreve(ostream &os)
{
  // do something
}

void Circulo::desenha()
{

}
bool Circulo::move(const Coord &c1, const Coord &c2)
{

}
bool Circulo::pontoNaForma(Coord &c1)
{

}