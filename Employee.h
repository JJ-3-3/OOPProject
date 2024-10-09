#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>

#include "Share.h"
#include "Timesheet.h"
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
  std::array<std::array<std::pair<int, int>, 7>, 4> weeklyHours;

 public:
  Employee(int id, std::string name, vector<Share*> theShareList);
  double returnOverallShareValue();
  void addShare(Share* addedShare);
  // virtual
  float calculatePay();
  void printPayments();
  // virtual
  string getWorkTypeName();

  void setClockTimesForDay(int week, int day, int clockIn, int clockOut);

  void setPay(float pay);
};

#endif  // EMPLOYEE_H