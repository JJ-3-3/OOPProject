#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

#include "Admin.h"
#include "CEO.h"
#include "Company.h"
#include "Employee.h"
#include "Share.h"
#include "Timesheet.h"
#include "TimesheetEntry.h"

int main(void) {
  // init random seed random functions etc.
  std::srand(static_cast<unsigned int>(time(nullptr)));

  Share test;

  CEO ethan(1, "Ethan Lawrie", "elawrie", "test123");
  CEO john(2, "John Doe", "jdoe", "strongpassword");

  CEO companyPlaceholder(0, "Company", "company", "companypassword");
  CEO defaultUser(-1, "User", "user", "default");

  std::vector<Employee*> employeeVect;

  employeeVect.push_back(&defaultUser);
  employeeVect.push_back(&companyPlaceholder);

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company TaxEvasion(10.99, 0.033, employeeVect);

  for (int i = 0; i < 365; i++) {
    TaxEvasion.changeTotalShareValue();

    std::cout << test.shareValue << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "pre increase number of shares in company: "
            << TaxEvasion.numTotalShares << std::endl;

  std::cout << "expecting 250000 " << std::endl;

  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "testing incremental increase for total shares" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));

  for (int i = 0; i < 100; i++) {
    TaxEvasion.increaseTotalShareNum(20000);
    std::cout << TaxEvasion.numTotalShares << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  std::cout << "post increase number of shares in company: "
            << TaxEvasion.numTotalShares << std::endl;

  std::cout << "expecting 2250000 and should go from 200000 to 2250000 in "
               "incriments of 20000 "
            << std::endl;

  std::cout << "expected values to range, not be consistent. min value 0, max "
               "value 135.33, mean is 18.505"
            << std::endl;
  std::cout << "expects dipping values as well, not just consistently "
               "positive, but an upwards trend is expected"
            << std::endl;

  return 0;
}