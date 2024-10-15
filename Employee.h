#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

// #include "Company.h"
#include "Share.h"
#include "Timesheet.h"
// using namespace std;

class Company;

struct transactionDetail {
  float payAmount;
  time_t startDate;
  time_t endDate;
  int timesWorked;

  // details on the pay amount, start and end dats, and the number of times
  // worked in a week
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

  // std::vector<std::vector<std::pair<int, int>, std::pair<int, int>>>
  //  weeklyHours;
  Timesheet employeeTimesheet;
  std::string username;
  std::string password;

 public:
  // vector of all the shares
  std::vector<Share*> shareList;
  Employee(int id, std::string name, std::string username,
           std::string password);

  // double returnOverallShareValue();
  void addShare(Share* addedShare);

  // gets the total number of shares
  int totalShares() { return shareList.size(); }

  // prints the share summary
  void printShareSummary();

  // virtual
  virtual float calculatePay(Company* thecompany) = 0;
  void printPayments();
  // virtual
  std::string getWorkTypeName();

  // calculates the pay of the whole company for the week
  virtual bool calculateAllPay(Company* company) {
    std::cout << "\nCannot run that with your current permissions\n"
              << std::endl;
    return false;
  };

  // Sets the clock in and clock out times depending on the date and time
  void setClockTimesForDay(int week, int day, int clockIn, int clockOut);

  // gives the ability for an employee to clock in
  void clock() { employeeTimesheet.clockIn(); };

  // gives the ability for an employee to clock out
  void clockOut(std::string worktype, double hourMult, int breakLength) {
    employeeTimesheet.clockOutSingle(worktype, hourMult, breakLength);
  };

  // this allows for an employee to input their clock in and clock out times,
  // along with an hour multiplier and the duration of their break
  void clockFullEntry(time_t startTime, time_t endTime, std::string worktype,
                      double hourMult, int breakLength) {
    employeeTimesheet.addEntry(startTime, endTime, breakLength, worktype,
                               hourMult);
  };

  // prints the timesheet entries
  void printTimesheetEntries() { employeeTimesheet.printTimesheet(); };

  // gets the ID of the employee
  int get_id() { return employeeID; };

  // gets the username of the employee
  std::string get_username() { return username; };

  // gets the name of the employee
  std::string get_name() { return employeeName; };

  // gets the password of the employee
  std::string get_password() { return password; };

  // returns whether an employee is an admin or not
  bool isAnAdmin() { return isAdmin; }

  // sets the pay for an employee
  void setPay(float pay);

  // destructor for the list of employees
  ~Employee();
};

#endif  // EMPLOYEE_H