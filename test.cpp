// testing

#include <iostream>

// #include "Employee.cpp"
// // #include "Employee.h"
#include "Company.h"
#include "Share.cpp"

int main() {
  vector<Share*> shareVect;
  Employee ethan(1, "Ethan Lawrie", shareVect);
  Employee john(2, "John Doe", shareVect);

  vector<Employee*> employeeVect;

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company google(10, 0.2, employeeVect);

  /* code */

  int a = 10;

  Share share1(&a, &google.shareValue);

  ethan.addShare(&share1);

  //   double* variable = create.shareValue;
  //   std::cout << *create.shareValue << std::endl;
  std::cout << ethan.returnOverallShareValue();
  << std::endl;

  std::cout << "test worked" << std::endl;

  return 0;
}
