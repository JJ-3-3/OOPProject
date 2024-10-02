#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

#include "Share.cpp"
#include "Share.h"
using namespace std;

class Employee {
 protected:
  int employeeID;
  std::string employeeName;
  float payRate;
  bool isAdmin;
  int maxShares;
  int curShareNum;
  std::string workTypeName;
  bool canReceiveShares;
  int hoursPerWeek;
  vector<Employee> employeeList;

 public:
  int returnOverallShareValue();
  virtual void calculatePay();
  void printPayments();
  virtual void getWorkTypeName();
};

#endif  // EMPLOYEE_H