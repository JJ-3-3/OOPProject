#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

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
  vector<Share*> shareList;

 public:
  Employee(int id, std::string name, vector<Share*> theShareList)
      : employeeID(id), employeeName(name), shareList(theShareList) {};
  double returnOverallShareValue() { return (*shareList[0]).shareValue; };
  void addShare(Share* addedShare) { shareList.push_back(addedShare); };
  virtual void calculatePay();
  void printPayments();
  virtual void getWorkTypeName();
};

#endif  // EMPLOYEE_H