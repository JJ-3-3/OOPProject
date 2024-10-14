#ifndef NORMAL_H
#define NORMAL_H

#include "Employee.h"

class Normal : public Employee {
 protected:
  bool isAdmin;
  public:
  Normal();
};

#endif  // NORMAL_H