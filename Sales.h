#ifndef SALES_H
#define SALES_H

#include <iostream>

#include "Normal.h"

using namespace std;

class Sales : public Normal {
 protected:
  int commission;

 public:
  // default constructor
  Sales();

  // paramaterised constructor
  Sales(int id, std::string name, std::string username, std::string password)
      : Normal(id, name, username, password) {}

  // calculates commission based on the employee's sales
  void calcCommission();
};

#endif  // SALES_H