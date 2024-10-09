// testing

#include <iostream>

// #include "Employee.cpp"
#include <chrono>
#include <thread>

#include "Company.h"
#include "Employee.h"
#include "Share.h"

using namespace std;

int main() {
  bool hasFinished = false;

  Employee ethan(1, "Ethan Lawrie");
  Employee john(2, "John Doe");

  Employee companyPlaceholder(3, "Company");

  vector<Employee*> employeeVect;

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company google(10, 0.2, employeeVect);

  Share share1;
  Share share2;
  Share share3;
  Share share4;
  Share share5;
  Share share6;
  Share share7;
  Share share8;
  Share share9;
  Share share10;
  vector<Share> initialShares = {share1, share2, share3, share4, share5,
                                 share6, share7, share9, share10};

  for (int i = 0; i < initialShares.size(); i++) {
    companyPlaceholder.addShare(&initialShares[i]);
  }

  //   while (!hasFinished) {
  //     }
  //   ethan.addShare(&share1);

  /* code */

  int a = 10;

  //   double* variable = create.shareValue;
  //   std::cout << *create.shareValue << std::endl;
  // std::cout << ethan.returnOverallShareValue() << std::endl;

  std::cout << "test worked" << std::endl;

  // give a base pay rate
  ethan.setPay(25.60);
  // std::this_thread::sleep_for(std::chrono::seconds(5));

  // cout << "hours worked for month, expecting 160 * payRate" << endl;
  ethan.clock();

  std::this_thread::sleep_for(std::chrono::seconds(8));
  ethan.calculatePay();
  ethan.printPayments();

  return 0;
}
