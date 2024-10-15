#ifndef TIMESHEET_H
#define TIMESHEET_H

#include <time.h>

#include <vector>

#include "TimesheetEntry.h"

class Timesheet {
 private:
  int emplyeeID;
  bool hoursWorkedTrue;

 public:
  // sets previous time
  time_t prevTime;

  // vector of timesheet entries
  std::vector<TimesheetEntry> timesheetEntries;

  // default constructor
  Timesheet(/* args */);

  // timesheet destructor
  ~Timesheet();

  // returns the total time from the timesheets in hours
  float getTotalWorkedTime();

  // resets all timesheet entries
  void resetTimesheetEntries();

  // prints timesheet
  void printTimesheet();

  // adds a timesheet entry
  void addEntry(time_t startedTime, time_t endedTime, int breakTime,
                std::string workingPeriodType, double hoursMultiplier);

  // clocks in employee
  void clockIn();

  // clocks out all employees
  void clockOutAll();

  // clocks out a single employee
  void clockOutSingle(std::string worktype, double hourMult, int breakLength);
};

#endif  // TIMESHEET_H