#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Share.h"
#include "Timesheet.h"
// using namespace std;

struct transactionDetail {
  float payAmount;
  time_t startDate;
  time_t endDate;
  int timesWorked;

  transactionDetail(float pay, time_t start, time_t end, int workedInt)
      : payAmount(pay), startDate(start), endDate(end), timesWorked(workedInt) {
        };
};

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
  std::vector<transactionDetail> payments;
  std::vector<Share*> shareList;
  // std::vector<std::vector<std::pair<int, int>, std::pair<int, int>>>
  //     weeklyHours;
  Timesheet employeeTimesheet;
  std::string username;
  std::string password;

 public:
  Employee(int id, std::string name, std::string username,
           std::string password);
  // double returnOverallShareValue();
  void addShare(Share* addedShare);
  // virtual
  float calculatePay();
  void printPayments();
  // virtual
  std::string getWorkTypeName();

  void setClockTimesForDay(int week, int day, int clockIn, int clockOut);
  void clock() { employeeTimesheet.clockIn(); };
  void clockOut(std::string worktype, double hourMult, int breakLength) {
    employeeTimesheet.clockOutSingle(worktype, hourMult, breakLength);
  };
  void printTimesheetEntries() { employeeTimesheet.printTimesheet(); };

  int get_id() { return employeeID; };
  std::string get_username() { return username; };
  std::string get_name() { return employeeName; };
  std::string get_password() { return password; };
  bool isAnAdmin() { return isAdmin; }

  void setPay(float pay);
};

#endif  // EMPLOYEE_H