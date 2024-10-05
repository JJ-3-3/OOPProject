// testing

#include <iostream>

// #include "Employee.cpp"
#include "Company.h"
#include "Employee.h"
#include "Share.h"

using namespace std;

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
  std::cout << ethan.returnOverallShareValue() << std::endl;

  std::cout << "test worked" << std::endl;
  



  //for loop to set 9-5 jobs 5 days a week
  for(int i = 0; i < 4; i++){
  for(int k = 0; k < 5; k++){
  ethan.setClockTimesForDay(i,k,9,17);
  }
  }

  //give a base pay rate
  ethan.setPay(25.60);


  cout << "hours worked for month, expecting 160 * payRate" << endl;
  cout << ethan.calculatePay() << endl;

  return 0;
}
