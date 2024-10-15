#ifndef NORMAL_H
#define NORMAL_H

#include "Company.h"
#include "Employee.h"
#include "math.h"

class Normal : public Employee {
 public:
  float calculatePay(Company* company);
  Normal(int id, std::string name, std::string username, std::string password)
      : Employee(id, name, username, password) {
    isAdmin = false;
  };
};

#endif  // NORMAL_H