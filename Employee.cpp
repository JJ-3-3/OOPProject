
#include "Employee.h"

#include <math.h>

#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Company.h"

std::string timeToString(time_t t) {
  struct tm* timeInfo = localtime(&t);
  char formattedStr[80];

  strftime(formattedStr, sizeof(formattedStr), "%Y-%m-%d %H:%M:%S", timeInfo);

  return std::string(formattedStr);
}

Employee::Employee(int id, std::string name, std::string username,
                   std::string password, bool anAdmin)
    : employeeID(id),
      employeeName(name),
      username(username),
      password(password),
      isAdmin(anAdmin),
      payRate(50),
      hoursPerWeek(40) /*TAKE OUT AFTER*/ {}

// double Employee::returnOverallShareValue() { return shareList[0]->shareValue;
// }
void Employee::addShare(Share* addedShare) { shareList.push_back(addedShare); }

// virtual
float Employee::calculatePay(Company* company) {
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
    std::cout << "PAYING FROM COMPANY" << std::endl;
    company->assignShares(this, sharesAllowed);
  } else if (company->companyRep->totalShares() > 0 &&
             company->companyRep->totalShares() < sharesAllowed) {
    std::cout << "PAYING FROM REST OF COMPANY" << std::endl;
    // pays the rest of the available shares
    company->assignShares(this, company->companyRep->totalShares());
  } else {
    // means there are no shares
    //  checks to see if anyone can give share amount and the company first
    //  buybacks them;
    for (int i = 0; i < company->employeeList.size(); i++) {
      std::cout << "FOR EMPLOYEE " << company->employeeList[i]->get_name()
                << ", there are " << company->employeeList[i]->totalShares()
                << " available, " << sharesAllowed << " requested. "
                << std::endl;
      if (company->employeeList[i]->totalShares() >= sharesAllowed) {
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

void Employee::printPayments() {
  std::cout << std::setw(100) << std::setfill('=') << "=" << std::setfill(' ')
            << std::endl;
  std::cout << std::left << std::setw(40) << "Payment Processed Period"
            << std::right << std::setw(30) << "Pay" << std::setw(20)
            << "Times Worked" << std::endl;
  std::cout << std::setw(100) << std::setfill('=') << "=" << std::setfill(' ')
            << std::endl;

  for (size_t i = 0; i < payments.size(); i++) {
    std::stringstream periodStream;
    periodStream << timeToString(payments[i].startDate) << " to "
                 << timeToString(payments[i].endDate);

    std::stringstream payStream;
    payStream << "$" << std::fixed << std::setprecision(2)
              << payments[i].payAmount;

    std::cout << std::left << std::setw(40) << periodStream.str() << std::right
              << std::setw(30) << payStream.str() << std::setw(20)
              << payments[i].timesWorked << std::endl;
  }
  std::cout << std::setw(100) << std::setfill('=') << "=" << std::setfill(' ')
            << std::endl;
}

// virtual
std::string Employee::getWorkTypeName() { return workTypeName; }

void Employee::setClockTimesForDay(int week, int day, int clockIn,
                                   int clockOut) {
  // if (week >= 0 && week < 4 && day >= 0 && day < 7) {
  //   weeklyHours[week][day] = std::make_pair(clockIn, clockOut);
  // }
}

void Employee::setPay(float pay) { payRate = pay; }

void Employee::printShareSummary() {
  std::cout << "\n==================== Share Summary ====================\n\n";
  std::cout << "Amount of shares owned: " << totalShares() << std::endl;
  std::cout << "Value per share: " << Share::shareValue << std::endl;
  std::cout << "Total share value: " << Share::shareValue * totalShares()
            << "\n"
            << std::endl;
}