#ifndef INTERN_H
#define INTERN_H

#include <iostream>

#include "Normal.h"

using namespace std;

class Intern : public Normal {
 public:
  Intern();
  Intern(int id, std::string name, std::string username, std::string password)
      : Normal(id, name, username, password) {};
};

#endif  // INTERN_H