#include "TimesheetEntry.h"

// inputs a timesheet entry including start and end times, break duration, work
// period type and an hours multiplier
TimesheetEntry::TimesheetEntry(time_t startedTime, time_t endedTime,
                               int breakTime, std::string workingPeriodType,
                               double hoursMultiplier) {
  startTime = startedTime;
  endTime = endedTime;
  breakDuration = breakTime;
  this->workingPeriodType = workingPeriodType;
  this->hoursMultiplier = hoursMultiplier;
  calculateEntryTime(startedTime, endedTime, breakTime);
}

// default constructor
TimesheetEntry::TimesheetEntry(/* args */) {
  startTime = time(0);
  hoursMultiplier = -1;
}

// timesheet destructor
TimesheetEntry::~TimesheetEntry() {}

// clocks out employee
void TimesheetEntry::clockOut(std::string worktype, double hourMult,
                              int breakLength) {
  endTime = time(0);

  breakDuration = breakLength;
  workingPeriodType = worktype;
  hoursMultiplier = hourMult;
  calculateEntryTime(startTime, endTime, breakDuration);
}

// calculates timesheet entry duration
void TimesheetEntry::calculateEntryTime(time_t start, time_t end,
                                        int breakTime) {
  timeWorked = (end - start) - (breakTime * 60);
  if (timeWorked < 0) {
    // set time to 0 if break was longer than worked time
    timeWorked = 0;
  }
}