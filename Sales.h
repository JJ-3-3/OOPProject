#ifndef SALES_H
#define SALES_H

#include <iostream>

#include "Employee.h"
#include "Normal.h"

using namespace std;

class Sales : public Normal {
 protected:
  float payRate;
  string employeeName;
  int employeeID;

 public:
  Sales();
  Sales(string employeeName, int employeeID, float payRate);
};

#endif  // INTERN_H