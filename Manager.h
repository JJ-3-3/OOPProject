#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>

#include "Admin.h"

// using namespace std;

class Manager : public Admin {
 protected:
  float payRate;
  std::string employeeName;
  int employeeID;

 public:
  void generateReport(std::string reportType);
  void calculateAllPay();
  Manager(float pay, std::string name, int id);
  Manager();
};

#endif  // MANAGER_H