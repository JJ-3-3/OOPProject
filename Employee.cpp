
#include "Employee.h"

Employee::Employee(int id, std::string name, vector<Share*> theShareList)
    : employeeID(id), employeeName(name), shareList(theShareList) {}

double Employee::returnOverallShareValue() { return *shareList[0]->shareValue; }
void Employee::addShare(Share* addedShare) { shareList.push_back(addedShare); }
// virtual
float Employee::calculatePay() {
  float tempPay = 0;
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 7; k++) {
      std::pair<int, int> times = weeklyHours[i][k];
      tempPay = tempPay + payRate * (times.second - times.first);
    }
  }
  return tempPay;
}

void Employee::printPayments() {
  // entirley GUI code for this maybe?
}

// virtual
string Employee::getWorkTypeName() { return workTypeName; }

void Employee::setClockTimesForDay(int week, int day, int clockIn,
                                   int clockOut) {
  if (week >= 0 && week < 4 && day >= 0 && day < 7) {
    weeklyHours[week][day] = std::make_pair(clockIn, clockOut);
  }
}

void Employee::setPay(float pay) { payRate = pay; }