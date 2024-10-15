#ifndef INTERN_H
#define INTERN_H

#include <iostream>

#include "Normal.h"

using namespace std;

// inheritance, this is the third layer
class Intern : public Normal {
 public:
  // default constructor
  Intern();

  // paramaterised constructor
  Intern(int id, std::string name, std::string username, std::string password)
      : Normal(id, name, username, password) {};
};

#endif  // INTERN_H