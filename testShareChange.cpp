
#include <cstdlib>
#include <ctime>

#include "Company.h"
#include "Employee.h"
#include "Share.h"
#include "Timesheet.h"
#include "TimesheetEntry.h"

int main(void) {
  // init random seed random functions etc.
  std::srand(static_cast<unsigned int>(time(nullptr)));

  Share test;

  Employee ethan(1, "Ethan Lawrie", "elawrie", "test123");
  Employee john(2, "John Doe", "jdoe", "strongpassword");

  Employee companyPlaceholder(0, "Company", "company", "companypassword");
  Employee defaultUser(-1, "User", "user", "default");

  std::vector<Employee*> employeeVect;

  employeeVect.push_back(&defaultUser);
  employeeVect.push_back(&companyPlaceholder);

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company TaxEvasion(10.99, 0.033, employeeVect);

  for (int i = 0; i < 365; i++) {
    TaxEvasion.changeTotalShareValue();

    std::cout << test.shareValue << std::endl;
  }
}