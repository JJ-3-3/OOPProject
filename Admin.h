#ifndef ADMIN_H
#define ADMIN_H

#include <math.h>

#include "Company.h"
#include "Employee.h"

class Admin : public Employee {
 protected:
  float adminBonus;

 public:
  float calculatePay(Company* company);

  void addEmployeeBonus(int employeeID);
  Admin(int id, std::string name, std::string username, std::string password)
      : Employee(id, name, username, password) {
    isAdmin = true;
  };
};

#endif  // ADMIN_H