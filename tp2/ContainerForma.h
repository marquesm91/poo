#ifndef CONTAINERFORMA_H
#define CONTAINERFORMA_H

#include <vector>
#include "Circulo.h"
#include "Cubo.h"
#include "Disco.h"
#include "Esfera.h"
#include "Linha.h"
#include "Retangulo.h"
#include "Triangulo.h"

class ContainerForma
{
public:
  ContainerForma();
  ~ContainerForma();
  void Carregar(); // função fabrica de formas
  void Desenhar(); // desenha todas as formas na tela
  void Mover(double, double, double); // move as formas que possuem o ponto passado por parametro
  void Areas(double, double, double); // imprime na tela as areas das formas que possuem o ponto passado por parametro
  void Volumes(double, double, double); // imprime na tela os volumes das formas que possuem o ponto passado por parametro
  void Salvar(); // salva todos as formas nos arquivos originais

private:
  vector<Forma *> *f; // armazena os endereços das formas, assim como as formas
};


#endif