#ifndef ERROR_H
#define ERROR_H

#include <iostream>

using std::cout;

class Error
{
  const int type;
public:
  Error(const int i);
  void what() const;
};

#endif