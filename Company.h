
#ifndef COMPANY_H
#define COMPANY_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Employee.h"
#include "Share.h"
// using namespace std;

class Company {
 public:
  int curNumEmployees;
  // Generic* companyRep;
  int maxEmployees;
  std::vector<Employee *> employeeList;
  // double shareValue;

  double taxRate;

 public:
  Company(double shareValue, double theTaxRate,
          std::vector<Employee *> listOfEmployees)
      : taxRate(theTaxRate), employeeList(listOfEmployees) {
    Share::shareValue = shareValue;
  };
  void assignShare(int employeeID, int maxShares, int curShareNum);
  void assignExecShare(int employeeID, int maxShares, int curShareNum);
  void buyBackShare(int employeeID, int curEmployeeShareNum);
  void changeTotalShareValue();
  void increaseTotalShareNum(int increase);
  double returnTotalShareValue();
  Employee *findEmployee(std::string username);
};

#endif