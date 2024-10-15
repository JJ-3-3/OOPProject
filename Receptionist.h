#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <iostream>

#include "Normal.h"

using namespace std;

class Receptionist : public Normal {
 public:
  // default constructor
  Receptionist();

  // paramaterised constructor
  Receptionist(int id, std::string name, std::string username,
               std::string password)
      : Normal(id, name, username, password) {};
};

#endif  // RECEPTIONIST_H