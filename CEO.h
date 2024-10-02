#ifndef CEO_H
#define CEO_H

#include <iostream>

// using namespace std;

class CEO : public Admin {
 protected:
  float payRate;
  std::string employeeName;
  int employeeID;

 public:
  CEO();
  CEO(float pay, std::string name, int id);
};

#endif  // CEO_H