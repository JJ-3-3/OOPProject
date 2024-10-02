#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"

class Admin : public Employee {
 protected:
  bool isAdmin;

 public:
  void addEmployeeBonus(int employeeID);
};

#endif  // ADMIN_H