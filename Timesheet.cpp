#include "Timesheet.h"

#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string timeToHours(time_t t) {
  struct tm* timeInfo = localtime(&t);

  char formattedStr[80];

  strftime(formattedStr, sizeof(formattedStr), "%H:%M:%S", timeInfo);

  return std::string(formattedStr);
}

Timesheet::Timesheet(/* args */) { prevTime = time(0); }

Timesheet::~Timesheet() {}

float Timesheet::getTotalWorkedTime() {
  float totalTime = 0;
  for (int i = 0; i < timesheetEntries.size(); i++) {
    // If any of the entries are not currently finished, finish them
    if (timesheetEntries[i].hoursMultiplier == -1) {
      timesheetEntries[i].clockOut("Normal", 1, 0);
    }
    // adds the time worked (in seconds to hours) times by the work type mult to
    // the total time

    totalTime += ((static_cast<float>(timesheetEntries[i].timeWorked) / 3600) *
                  timesheetEntries[i].hoursMultiplier);
  }

  std::cout << "\nTimesheet Entries: \n~~~~~~~~~~~~~~~~~~~~~~~~ \n"
            << std::endl;
  printTimesheet();

  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;

  resetTimesheetEntries();
  return totalTime;
}

void Timesheet::resetTimesheetEntries() { timesheetEntries.clear(); }

void Timesheet::printTimesheet() {
  std::cout << "\n================ Timesheet Entries ================\n"
            << std::endl;

  for (int i = 0; i < timesheetEntries.size(); i++) {
    std::cout << "Entry #" << i + 1 << ":\n";
    std::cout << "Worked from " << timeToHours(timesheetEntries[i].startTime)
              << " to " << timeToHours(timesheetEntries[i].endTime) << "\n";

    std::cout << "Total Hours Worked: " << std::fixed << std::setprecision(2)
              << (static_cast<float>(timesheetEntries[i].timeWorked) / 3600)
              << " hours\n";

    std::cout << "Type of Work: " << timesheetEntries[i].workingPeriodType
              << "\n";

    if (timesheetEntries[i].breakDuration > 0) {
      std::cout << "Break Length: " << std::fixed << std::setprecision(2)
                << static_cast<float>(timesheetEntries[i].breakDuration)
                << " minutes\n";
    } else {
      std::cout << "Break Length: None\n";
    }

    std::cout << "----------------------------------------------------\n";
  }

  std::cout << "\n===================================================\n"
            << std::endl;
}

void Timesheet::addEntry(time_t startedTime, time_t endedTime, int breakTime,
                         std::string workingPeriodType,
                         double hoursMultiplier) {
  timesheetEntries.push_back(TimesheetEntry(
      startedTime, endedTime, breakTime, workingPeriodType, hoursMultiplier));
}

void Timesheet::clockOutAll() {
  for (int i = 0; i < timesheetEntries.size(); i++) {
    if (timesheetEntries[i].hoursMultiplier == -1) {
      timesheetEntries[i].clockOut("Normal", 1, 0);
    }
  }
}

void Timesheet::clockOutSingle(std::string worktype, double hourMult,
                               int breakLength) {
  timesheetEntries.back().clockOut(worktype, hourMult, breakLength);
}

void Timesheet::clockIn() {
  clockOutAll();
  timesheetEntries.push_back(TimesheetEntry());
}
