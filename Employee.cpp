#include "Employee.h"

#include <math.h>

#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Company.h"

// coverts an input time into a string
std::string timeToString(time_t t) {
  struct tm* timeInfo = localtime(&t);
  char formattedStr[80];

  strftime(formattedStr, sizeof(formattedStr), "%Y-%m-%d %H:%M:%S", timeInfo);

  return std::string(formattedStr);
}

Employee::~Employee() {
  // deletes all of the shares to deallocate memeory
  for (int i = 0; i < shareList.size(); i++) {
    delete shareList[i];
  }
}

// paramaterised constructor
Employee::Employee(int id, std::string name, std::string username,
                   std::string password)
    : employeeID(id),
      employeeName(name),
      username(username),
      password(password) {}

// double Employee::returnOverallShareValue() { return shareList[0]->shareValue;
// }
void Employee::addShare(Share* addedShare) { shareList.push_back(addedShare); }

// virtual

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

// pay setter
void Employee::setPay(float pay) { payRate = pay; }

// print number of shares, value of each share, and total value
void Employee::printShareSummary() {
  std::cout << "\n==================== Share Summary ====================\n\n";
  std::cout << "Current total number of shares issued by the company: "
            << Share::numTotalShares << std::endl;
  std::cout << "Amount of shares owned: " << totalShares() << std::endl;
  std::cout << "Current Share Price is: $" << std::fixed << std::setprecision(2)
            << Share::shareValue << std::endl;
  std::cout << "Stake in this Company is : $" << std::fixed
            << std::setprecision(2) << totalShares() * Share::shareValue
            << std::endl;
  std::cout << "Total Company value: $" << std::fixed << std::setprecision(2)
            << Share::shareValue * Share::numTotalShares << "\n"
            << "\n";
}