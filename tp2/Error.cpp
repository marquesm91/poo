#include "Error.h"

Error::Error(const int i) : type(i){}

void Error::what() const
{
  switch (type)
  {
  case 0: cout << "Error: Nao foi possivel abrir o arquivo de leitura.\n"; break;
  case 1: cout << "Error: Nao foi possivel abrir o arquivo de escrita.\n"; break;
  case 2: cout << "Error: parametros invalidos.\n"; break;
  case 3: cout << "Error: pontos coincidem.\n"; break;
  case 7: cout << "Error: pontos sao colineares.\n"; break;
  case 8: cout << "Error: pontos precisam estar no mesmo plano z.\n"; break;
  case 4: cout << "Error: Ponto nao pertence a forma, pois esta fora dos limites.\n"; break;
  case 5: cout << "Error: Ponto nao pertence a forma, pois nao esta sobre a forma.\n"; break;
  case 9: cout << "Error: Ponto nao pertence a forma, pois nao esta dentro ou sobre a forma.\n"; break;
  case 6: cout << "Error: Forma nao esta presente no arquivo.\n"; break;
  }
}
