// testing

#include <iostream>
#include <vector>
// #include "Employee.cpp"
#include "Company.h"
#include "Employee.h"
#include "Share.h"

int main() {
  std::vector<Share*> shareVect;
  Employee ethan(1, "Ethan Lawrie", shareVect);
  Employee john(2, "John Doe", shareVect);

  std::vector<Employee*> employeeVect;

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company google(10, 0.2, employeeVect);

  /* code */

  int a = 10;

  Share share1(&a, &google.shareValue);

  ethan.addShare(&share1);

  //   double* variable = create.shareValue;
  //   std::cout << *create.shareValue << std::endl;
  std::cout << ethan.returnOverallShareValue() << std::endl;

  std::cout << "test worked" << std::endl;

  return 0;
}
