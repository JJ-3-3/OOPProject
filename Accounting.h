#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <iostream>

#include "Normal.h"

using namespace std;

// The Accounting class inherits from the Normal class, representing an
// accounting employee
class Accounting : public Normal {
 public:
  // Default constructor
  Accounting();

  // Parameterized constructor to initialize Accounting object with specific
  // details
  Accounting(int id, std::string name, std::string username,
             std::string password)
      : Normal(id, name, username, password) {
    payRate = 35;
  };
  // Method to generate a report based on the specified report type
  void generateReport(string reportType);

  // Method to calculate all pay for the accounting employee
  bool calculateAllPay(Company* company);
};

#endif  // ACCOUNTING_H
