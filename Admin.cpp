#include "Admin.h"

float Admin::calculatePay(Company* company) {
  float hoursWorked = 0;
  float fullPay;

  float timesWorked = employeeTimesheet.timesheetEntries.size();
  hoursWorked = employeeTimesheet.getTotalWorkedTime();

  if (hoursWorked > hoursPerWeek) {
    // Calculate overtime pay (1.5x normal rate)
    fullPay =
        (hoursWorked - hoursPerWeek) * payRate * 1.5 + hoursPerWeek * payRate;
  } else {
    fullPay = hoursWorked * payRate;
  }

  // std::cout << "FULL PAY: " << fullPay << std::endl;

  // store the payment in the employee payments vector
  if (!payments.empty()) {
    // sets the period since the last transaction if there is prev transactions
    payments.push_back(transactionDetail(fullPay, payments.back().endDate,
                                         time(0), timesWorked));
  } else {
    payments.push_back(transactionDetail(fullPay, employeeTimesheet.prevTime,
                                         time(0), timesWorked));
  }

  // allocates some available shares to the employee based on the pay
  // employees get an additional 20% of their pay for a period in shares
  // (rounded down)

  // checks if there are shares available in the company employee placeholder
  int sharesAllowed = std::floor((fullPay * 0.2) / Share::shareValue);

  if (company->companyRep->totalShares() >= sharesAllowed) {
    // std::cout << "PAYING FROM COMPANY" << std::endl;
    company->assignShares(this, sharesAllowed);
  } else if (company->companyRep->totalShares() > 0 &&
             company->companyRep->totalShares() < sharesAllowed) {
    // std::cout << "PAYING FROM REST OF COMPANY" << std::endl;
    // pays the rest of the available shares
    company->assignShares(this, company->companyRep->totalShares());
  } else {
    // means there are no shares
    //  checks to see if anyone can give share amount and the company first
    //  buybacks them;
    for (int i = 0; i < company->employeeList.size(); i++) {
      if (company->employeeList[i]->totalShares() >= sharesAllowed &&
          company->employeeList[i] != this) {
        company->buyBackShare(company->employeeList[i]);
        company->assignShares(this, sharesAllowed);
        break;
      }
    }
  }

  printShareSummary();

  printPayments();
  return fullPay;
}