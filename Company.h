#ifndef COMPANY_H
#define COMPANY_H

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

#include "Employee.h"
#include "Share.h"
// using namespace std;

class Company {
 public:
  int curNumEmployees;

  int maxEmployees;

  // unnecessary variable
  //  double shareValue;

  double taxRate;
  int numTotalShares = Share::numTotalShares;

 public:
  std::vector<Employee *> employeeList;
  Employee *companyRep;
  Company(double shareValue, double theTaxRate,
          std::vector<Employee *> listOfEmployees)
      : taxRate(theTaxRate), employeeList(listOfEmployees) {
    shareValue = Share::shareValue;
  };
  void assignShares(Employee *receivingEmp, int shareAmount);
  void assignExecShare(int employeeID, int maxShares, int curShareNum);
  void buyBackShare(Employee *targetEmp);
  void changeTotalShareValue();  // randomised change to share value to
                                 // replicate stock market
  void increaseTotalShareNum(
      int increase);  // dilute share value while adding more shares
  // double returnTotalShareValue();
  Employee *findEmployee(std::string username);
};

// run separate thread to update share value every second

#endif  // COMPANY_H