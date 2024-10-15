#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>

#include "Admin.h"

// using namespace std;

class Manager : public Admin {
 public:
  void generateReport(std::string reportType);
  bool calculateAllPay(Company* company);
  Manager();
  Manager(int id, std::string name, std::string username, std::string password)
      : Admin(id, name, username, password) {
    payRate = 50;
    adminBonus = 3;
  }
};

#endif  // MANAGER_H