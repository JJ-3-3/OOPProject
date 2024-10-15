#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <iostream>

#include "Normal.h"

using namespace std;

// the Accounting class inherits from the Normal class, representing an
// accounting employee
class Accounting : public Normal {
 public:
  // Default constructor
  Accounting();

  // parameterised default constructor
  Accounting(int id, std::string name, std::string username,
             std::string password)
      : Normal(id, name, username, password) {
    payRate = 35;
  };

  // method to generate a report based on the specified report type
  void generateReport(string reportType);

  // method to calculate all pay for the accounting employee
  bool calculateAllPay(Company* company);
};

#endif  // ACCOUNTING_H
