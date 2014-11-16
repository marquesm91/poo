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
  case 4: cout << "Ponto nao pertence a forma, pois esta fora dos limites.\n"; break;
  case 5: cout << "Ponto nao pertence a forma, pois nao esta sobre a forma.\n"; break;
  case 6: cout << "Forma nao esta presente no arquivo.\n"; break;
  }
}
