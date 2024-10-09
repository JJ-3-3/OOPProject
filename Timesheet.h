
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
  time_t prevTime;
  std::vector<TimesheetEntry> timesheetEntries;
  Timesheet(/* args */);
  ~Timesheet();

  // returns the total time from the timesheets in hours
  float getTotalWorkedTime();
  void resetTimesheetEntries();
  void printTimesheet();
  void addEntry(time_t startedTime, time_t endedTime, int breakTime,
                std::string workingPeriodType, double hoursMultiplier);
  void clockIn();
};

#endif