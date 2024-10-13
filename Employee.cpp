
#include "Employee.h"

#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

time_t stringToTime(const std::string& dateStr) {
  struct tm tm = {0};

  strptime(dateStr.c_str(), "%Y-%m-%d %H:%M:%S", &tm);

  return mktime(&tm);
}

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
      isAdmin(anAdmin) {}

// double Employee::returnOverallShareValue() { return shareList[0]->shareValue;
// }
void Employee::addShare(Share* addedShare) { shareList.push_back(addedShare); }
// virtual
float Employee::calculatePay() {
  float hoursWorked = 0;
  float fullPay;

  int timesWorked = employeeTimesheet.timesheetEntries.size();
  hoursWorked = employeeTimesheet.getTotalWorkedTime();

  if (hoursWorked > hoursPerWeek) {
    // Calculate overtime pay (1.5x normal rate)
    fullPay =
        hoursWorked - hoursPerWeek * payRate * 1.5 + hoursPerWeek * payRate;
  } else {
    fullPay = hoursWorked * payRate;
  }

  // store the payment in the employee payments vector
  if (!payments.empty()) {
    // sets the period since the last transaction if there is prev transactions
    payments.push_back(transactionDetail(fullPay, payments.back().endDate,
                                         time(0), timesWorked));
  } else {
    payments.push_back(transactionDetail(fullPay, employeeTimesheet.prevTime,
                                         time(0), timesWorked));
  }

  printPayments();
  return fullPay;
}

// void Employee::printPayments() {
//   for (int i = 0; i < payments.size(); i++) {
//     // printf("Period: %s to %s \n Pay: %0.2f",
//     //        timeToString(payments[i].startDate),
//     //        timeToString(payments[i].endDate), payments[i].payAmount);
//     std::cout << "\nPayment Period: " << timeToString(payments[i].startDate)
//               << " to " << timeToString(payments[i].endDate) << "\nPay: $"
//               << std::fixed << std::setprecision(8) << payments[i].payAmount
//               << "\nTimes Worked: " << payments[i].timesWorked << std::endl;
//   }
// }

void Employee::printPayments() {
  std::cout << std::setw(100) << std::setfill('=') << "=" << std::setfill(' ')
            << std::endl;
  std::cout << std::left << std::setw(40) << "Payment Period" << std::right
            << std::setw(30) << "Pay" << std::setw(20) << "Times Worked"
            << std::endl;
  std::cout << std::setw(100) << std::setfill('=') << "=" << std::setfill(' ')
            << std::endl;

  for (size_t i = 0; i < payments.size(); i++) {
    std::stringstream periodStream;
    periodStream << timeToString(payments[i].startDate) << " to "
                 << timeToString(payments[i].endDate);

    std::stringstream payStream;
    payStream << "$" << std::fixed << std::setprecision(2)
              << payments[i].payAmount;

    std::cout << std::left << std::setw(50) << periodStream.str() << std::right
              << std::setw(25) << payStream.str() << std::setw(25)
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