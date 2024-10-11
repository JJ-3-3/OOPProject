#include "Timesheet.h"

#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string timeToHours(time_t t) {
  // Convert time_t to tm struct for local time
  struct tm* timeInfo = localtime(&t);

  // Create a buffer to store the formatted string
  char formattedStr[80];

  // Format the date and time
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
  std::cout << "\n~~~~~~~~~~~~~~~~~~\n" << std::endl;
  for (int i = 0; i < timesheetEntries.size(); i++) {
    std::cout << "\nWorked from " << timeToHours(timesheetEntries[i].startTime)
              << " to " << timeToHours(timesheetEntries[i].endTime)
              << std::endl;

    std::cout << "Worked for ~ " << std::fixed << std::setprecision(2)
              << (static_cast<float>(timesheetEntries[i].timeWorked) / 3600)
              << " hours " << std::endl;

    std::cout << "Type of work: " << timesheetEntries[i].workingPeriodType
              << std::endl;
    if (timesheetEntries[i].breakDuration > 0) {
      std::cout << "Break Length: " << std::fixed << std::setprecision(2)
                << static_cast<float>(timesheetEntries[i].breakDuration) / 60
                << " minutes " << std::endl;
    }
  }
  std::cout << "\n~~~~~~~~~~~~~~~~~~\n" << std::endl;
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
