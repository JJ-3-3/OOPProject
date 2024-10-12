#ifndef INTERN_H
#define INTERN_H

#include <iostream>

#include "Employee.h"
#include "Normal.h"

using namespace std;

class Intern : public Normal {
 protected:
  float payRate;
  string employeeName;
  int employeeID;

 public:
  Intern();
  Intern(string employeeName, int employeeID, float payRate);
};

#endif  // INTERN_H