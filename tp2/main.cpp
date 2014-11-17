#include "ContainerForma.h"

int main()
{
  ContainerForma c;

  c.Carregar();
  c.Desenhar();
  c.Areas(1,1,1);
  c.Volumes(1,1,1);
  c.Mover(1,1,1);
  c.Salvar();
}