#ifndef GENERIC_H
#define GENERIC_H

#include <iostream>

#include "Normal.h"

using namespace std;

class Generic : public Normal {
 public:
  // default constructor
  Generic();

  // paramaterised constructor
  Generic(int id, std::string name, std::string username, std::string password)
      : Normal(id, name, username, password) {
    payRate = 30;
  };
};

#endif  // GENERIC_H