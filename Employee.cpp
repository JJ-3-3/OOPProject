
#include "Employee.h"

#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

time_t stringToTime(const std::string& dateStr) {
  struct tm tm = {0};  // Initialize the structure to zero

  // Define the format to match the input date string
  strptime(dateStr.c_str(), "%Y-%m-%d %H:%M:%S", &tm);

  // Convert the tm structure to time_t
  return mktime(&tm);
}

std::string timeToString(time_t t) {
  // Convert time_t to tm struct for local time
  struct tm* timeInfo = localtime(&t);

  // Create a buffer to store the formatted string
  char formattedStr[80];

  // Format the date and time
  strftime(formattedStr, sizeof(formattedStr), "%Y-%m-%d %H:%M:%S", timeInfo);

  return std::string(formattedStr);
}

Employee::Employee(int id, std::string name)
    : employeeID(id), employeeName(name) {}

// double Employee::returnOverallShareValue() { return shareList[0]->shareValue;
// }
void Employee::addShare(Share* addedShare) { shareList.push_back(addedShare); }
// virtual
float Employee::calculatePay() {
  float hoursWorked = 0;
  float fullPay;
  // for (int i = 0; i < 4; i++) {
  //   for (int k = 0; k < 7; k++) {
  //     std::pair<int, int> times = weeklyHours[i][k];
  //     tempPay = tempPay + payRate * (times.second - times.first);
  //   }
  // }
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

  return fullPay;
}

void Employee::printPayments() {
  for (int i = 0; i < payments.size(); i++) {
    // printf("Period: %s to %s \n Pay: %0.2f",
    //        timeToString(payments[i].startDate),
    //        timeToString(payments[i].endDate), payments[i].payAmount);
    std::cout << "Period: " << timeToString(payments[i].startDate) << " to "
              << timeToString(payments[i].endDate) << "\nPay: $" << std::fixed
              << std::setprecision(2) << payments[i].payAmount
              << "\nTimes Worked: " << payments[i].timesWorked << std::endl;
  }
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