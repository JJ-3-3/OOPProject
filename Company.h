
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

  int maxEmployees;

  // double shareValue;

  double taxRate;

 public:
  std::vector<Employee *> employeeList;
  Employee *companyRep;
  Company(double shareValue, double theTaxRate,
          std::vector<Employee *> listOfEmployees)
      : taxRate(theTaxRate), employeeList(listOfEmployees) {
    Share::shareValue = shareValue;
  };
  void assignShares(Employee *receivingEmp, int shareAmount);
  void assignExecShare(int employeeID, int maxShares, int curShareNum);
  void buyBackShare(Employee *targetEmp);
  void changeTotalShareValue();
  void increaseTotalShareNum(int increase);
  // double returnTotalShareValue();
  Employee *findEmployee(std::string username);
};

#endif