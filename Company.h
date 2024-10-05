
#ifndef COMPANY_H
#define COMPANY_H

#include <vector>

#include "Employee.h"
// using namespace std;

class Company {
 public:
  int curNumEmployees;
  // Generic* companyRep;
  int maxEmployees;
  std::vector<Employee *> employeeList;
  double shareValue;

  double taxRate;

 public:
  Company(double shareValue, double theTaxRate,
          std::vector<Employee *> listOfEmployees)
      : shareValue(shareValue),
        taxRate(theTaxRate),
        employeeList(listOfEmployees) {};
  void assignShare(int employeeID, int maxShares, int curShareNum);
  void assignExecShare(int employeeID, int maxShares, int curShareNum);
  void buyBackShare(int employeeID, int curEmployeeShareNum);
  void increaseTotalShareNum(int increase, int value);
  double returnTotalShareValue();
};

#endif