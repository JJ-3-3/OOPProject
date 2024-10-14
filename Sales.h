#ifndef SALES_H
#define SALES_H

#include <iostream>

#include "Employee.h"
#include "Normal.h"

using namespace std;

class Sales : public Normal
{
protected:
  string employeeName;
  int employeeID;
  float payRate;
  int commission;

public:
  Sales();
  Sales(string employeeName, int employeeID, float payRate);
  void calcCommission();
};

#endif // INTERN_H