#ifndef CEO_H
#define CEO_H

#include <iostream>

#include "Admin.h"

// using namespace std;

class CEO : public Admin {
 public:
  // default constructor
  CEO();

  // parametarised constructor
  CEO(int id, std::string name, std::string username, std::string password)
      : Admin(id, name, username, password) {
    payRate = 60;
    adminBonus = 5;
  };
};

#endif  // CEO_H