#include "Accounting.h"

using namespace std;

// method to generate a report based on the specified report type
void Accounting::generateReport(string reportType) {
  cout << "Generating " << reportType << " report for employee " << employeeName
       << " (ID: " << employeeID << ")." << endl;
  // additional report generation logic can be added here
}

// method to calculate all pay for the accounting employees
bool Accounting::calculateAllPay(Company* company) {
  for (int i = 0; i < company->employeeList.size(); i++) {
    std::cout << "\n\n==================== Pay for "
              << company->employeeList[i]->get_name()
              << " ====================\n\n";
    company->employeeList[i]->calculatePay(company);

    std::cout << "\n================================================";
    std::cout << "================================================\n\n\n";
  }

  return true;

  // example calculation: for simplicity, we might just multiply payRate by a
  // fixed number of hours worked
  //   float hoursWorked = 40.0;  // Assuming a standard 40-hour work week
  //   float totalPay = payRate * hoursWorked;

  //   cout << "Total pay for employee " << employeeName << " (ID: " <<
  //   employeeID
  //        << ") is: $" << totalPay << endl;
  // Additional logic for different pay calculation methods can be implemented
  // here
}
