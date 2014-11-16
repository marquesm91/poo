#include "Error.h"

Error::Error(const int i) : type(i){}

void Error::what() const
{
  switch (type)
  {
  case 0: cout << "Nao foi possivel abrir o arquivo de leitura.\n"; break;
  case 1: cout << "Nao foi possivel abrir o arquivo de escrita.\n"; break;
  case 2: cout << "Falha ao mover, parametros invalidos.\n"; break;
  case 3: cout << "Falha ao mover, pontos coincidem.\n"; break;
  case 4: cout << "Ponto nao pertence a forma.\n"; break;
  }
}
