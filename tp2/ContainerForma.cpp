#include "ContainerForma.h"
#include <fstream>

using namespace std;

ContainerForma::ContainerForma()
{
  f = new vector<Forma *>();
}

ContainerForma::~ContainerForma()
{
  f->clear();
}

// Função fabrica de f, analiza o arquivo, e partir dele, escolhe qual forma deve instanciar
void ContainerForma::Carregar()
{
  cout << "\n[Carregando formas de formas.txt]\n\n";
  string s;
  ifstream fp;

  fp.open("formas.txt");
  if (!fp.is_open())return;

  while (!fp.eof())
  {
    fp >> s;

    if (s == "Circulo") // se o arquivo contem um circulo
    {
      Forma *n = new Circulo(); // cria um circulo vazio
      fp >> *n; // ler o arquivo e salva no circulo
      f->push_back(n); // salva no map interno da classe, para ser usado depois
    }
    else if (s == "Cubo")
    {
      Forma *n = new Cubo();
      cout << "[Criando " << n->tipo() << "]\n";
      fp >> *n;
      f->push_back(n);
    }
    else if (s == "Disco")
    {
      Forma *n = new Disco();
      cout << "[Criando " << n->tipo() << "]\n";
      fp >> *n;
      f->push_back(n);
    }
    else if (s == "Esfera")
    {
      Forma *n = new Esfera();
      cout << "[Criando " << n->tipo() << "]\n";
      fp >> *n;
      f->push_back(n);
    }
    else if (s == "Linha")
    {
      Forma *n = new Linha();
      cout << "[Criando " << n->tipo() << "]\n";
      fp >> *n;
      f->push_back(n);
    }
    else if (s == "Retangulo")
    {
      Forma *n = new Retangulo();
      cout << "[Criando " << n->tipo() << "]\n";
      fp >> *n;
      f->push_back(n);
    }
    else if (s == "Triangulo")
    {
      Forma *n = new Triangulo();
      cout << "[Criando " << n->tipo() << "]\n";
      fp >> *n;
      f->push_back(n);
    }
  }
}

// desenha todas as f na tela
void ContainerForma::Desenhar()
{
  cout << "\n[Desenhando formas de formas.txt]\n\n";
  vector<Forma *>::iterator x;

  for (x = f->begin(); x != f->end(); x++) // percorre todas as f salvas
  {
    (*x)->desenha();
  }

}

// move as f que estao em determinadas posições
void ContainerForma::Mover(double x, double y, double z)
{
  cout << "\n[Movendo formas de formas.txt]\n\n";
  Coord c1(x,y,z);
 
  vector<Forma *>::iterator it;

  for (it = f->begin(); it != f->end(); it++) // percorre todas as f salvas
  {
    if((*it)->pontoNaForma(c1))
      while(!(*it)->move());
  }
}

// imprime na tela a area de f que possuem determinado ponto
void ContainerForma::Areas(double x, double y, double z)
{
  cout << "\n[Mostrando areas de formas.txt]\n\n";
  Coord c1(x,y,z);
 
  vector<Forma *>::iterator it;

  for (it = f->begin(); it != f->end(); it++) // percorre todas as f salvas
  {
    if((*it)->pontoNaForma(c1))
      cout << "Area = " << (*it)->area() << "\n";
  }
}

// imprime na tela o volume de f que possuem determinado ponto
void ContainerForma::Volumes(double x, double y, double z)
{
  cout << "\n[Mostrando volumes de formas.txt]\n\n";
  Coord c1(x,y,z);
 
  vector<Forma *>::iterator it;

  for (it = f->begin(); it != f->end(); it++) // percorre todas as f salvas
  {
    if((*it)->pontoNaForma(c1))
      cout << "Volume = " << (*it)->volume() << "\n";
  }
}

// salva as f em seus arquivos
void ContainerForma::Salvar()
{
  cout << "\n[Salvando formas em formas.txt]\n";
  vector<Forma *>::iterator it;
  ofstream fp("formas.txt");

  for (it = f->begin(); it != f->end(); it++) // percorre todas as f salvas
  {
      (*it)->escreve(fp);
  }
}
