#ifndef ADMIN_H
#define ADMIN_H

#include <math.h>

#include "Company.h"
#include "Employee.h"

class Admin : public Employee {
 protected:
  float adminBonus;

 public:
  // calculate pay for each employee
  float calculatePay(Company* company);

  // add bonuses to specific employees
  void addEmployeeBonus(int employeeID);

  // default constructor with parameters
  Admin(int id, std::string name, std::string username, std::string password)
      : Employee(id, name, username, password) {
    isAdmin = true;
  };
};

#endif  // ADMIN_H