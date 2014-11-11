#ifndef FORMA_H
#define FORMA_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "coordenada.h"

using namespace std;

typedef struct
{
  int x;
  int y;
  int z;
} coord;

class Forma
{
protected:
  Forma()
  {
    cout << "inside class forma\n";
  };
public:
  virtual ~Forma()
  {
    cout << "destrutor forma\n";
  };
  virtual void move() = 0;
  virtual void desenha(const coord &, const coord &) = 0;
  virtual double area() const = 0;
  virtual double volume() const = 0;
  virtual bool pontoNaForma(const coord &) const = 0;
  virtual const string tipo() = 0;
  virtual void le(ostream &) const = 0;
  virtual void escreve(istream &) = 0;
  friend ostream &operator <<(ostream &, const Forma &);
  friend istream &operator >>(istream &, Forma &);
};

class Forma1D : public Forma
{
protected:
  Forma1D()
  {
    cout << "inside class forma1D\n";
  };
public:
  virtual ~Forma1D()
  {
    cout << "destrutor forma1D\n";
  };
  double area() const
  {
    return 0;
  };
  double volume() const
  {
    return 0;
  };
};

class linhas : public Forma1D
{
  const int max_coord;
  Coord a;
  Coord b;
  coord c[2]; /* coordinates to draw a line */
public:
  linhas();
  ~linhas()
  {
    cout << "destrutor linhas\n";
  };
  const string tipo()
  {
    return "linha";
  };
  void le(ostream &) const;
  void escreve(istream &);
  void desenha(const coord &c1, const coord &c2)
  {
    cout << "Linha com extremos em c1 = (" << c1.x << "," << c1.y << "," << c1.z << ") ";
    cout << "e c2 = (" << c2.x << "," << c2.y << "," << c2.z << ")\n";
  };
  void move() {};
  bool pontoNaForma(const coord &c) const
  {
    return true;
  };
};

/*
class circulos : public Forma1D
{
  int circulo;
public:
  circulos(){ circulo = 0; cout << "construtor circulos\n"; };
  ~circulos(){ cout << "destrutor circulos\n"; };
  const string tipo(){ return "circulo"; };
  void le(ostream& os) const{ os << circulo; };
  void escreve(istream& is){ if (&is == &cin) is >> circulo; else while (!is.eof()) is >> circulo; };
};
*/

#endif