#ifndef ERROR_H
#define ERROR_H

#include <iostream>

using namespace std;

class Error
{
  const int type;
public:
  Error(const int i);
  void what() const;
};

#endif