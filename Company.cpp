#include "Company.h"

#include <iostream>

Employee* Company::findEmployee(std::string username) {
  bool foundID = false;
  for (int i = 0; i < employeeList.size(); i++) {
    if (username == employeeList[i]->get_username()) {
      foundID = true;
      return employeeList[i];
    }
  }
  if (!foundID) {
    return employeeList[0];
  }
}