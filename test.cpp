// testing

#include <math.h>

#include <iomanip>
#include <iostream>
#include <sstream>

// #include "Employee.cpp"
#include "Admin.h"
#include "CEO.h"
#include "Company.h"
#include "Employee.h"
#include "Share.h"
#include "Timesheet.h"
#include "TimesheetEntry.h"

using namespace std;

int main() {
  // vector<Share*> shareVect;
  CEO ethan(1, "Ethan Lawrie", "elawrie", "test123");
  CEO john(2, "John Doe", "jdoe", "strongpassword");

  vector<Employee *> employeeVect;

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company google(10, 0.2, employeeVect);

  /* code */

  Share share1;

  std::vector<Share *> initialShares;

  int shareAmount = 12500000;

  Share::numTotalShares = shareAmount;

  for (int i = 0; i < shareAmount; i++) {
    Share *newshare = new Share();
    initialShares.push_back(newshare);
  }

  for (int i = 0; i < initialShares.size(); i++) {
    ethan.addShare(initialShares[i]);
  }
  // ethan.addShare(&share1);

  //   double* variable = create.shareValue;
  //   std::cout << *create.shareValue << std::endl;
  // std::cout << ethan.returnOverallShareValue() << std::endl;

  std::cout << "test worked" << std::endl;

  // give a base pay rate
  ethan.setPay(25.60);

  // cout << "hours worked for month, expecting 160 * payRate" << endl;
  std::cout << ethan.calculatePay(&google) << std::endl;
  // ethan.printPayments();
  return 0;
}