#ifndef SALES_H
#define SALES_H

#include <iostream>

#include "Normal.h"

using namespace std;

class Sales : public Normal {
 protected:
  int commission;

 public:
  Sales();
  Sales(int id, std::string name, std::string username, std::string password)
      : Normal(id, name, username, password) {}
  void calcCommission();
};

#endif  // SALES_H