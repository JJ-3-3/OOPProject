#ifndef NORMAL_H
#define NORMAL_H

#include "Company.h"
#include "Employee.h"
#include "math.h"

class Normal : public Employee {
 public:
  // calculates the pay for each employee for the week
  float calculatePay(Company* company);

  // paramaterised constructor
  Normal(int id, std::string name, std::string username, std::string password)
      : Employee(id, name, username, password) {
    isAdmin = false;
  };
};

#endif  // NORMAL_H