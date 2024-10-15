#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>

#include "Admin.h"

// using namespace std;

class Manager : public Admin {
 public:
  // generates a payment report
  void generateReport(std::string reportType);

  // calculates the total pay to the employees throughout one week
  bool calculateAllPay(Company* company);

  // default constructor
  Manager();

  // parameterised constructor
  Manager(int id, std::string name, std::string username, std::string password)
      : Admin(id, name, username, password) {
    payRate = 50;
    adminBonus = 3;
  }
};

#endif  // MANAGER_H