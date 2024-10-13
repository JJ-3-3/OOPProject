#include "TimesheetEntry.h"

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

TimesheetEntry::TimesheetEntry(/* args */) {
  startTime = time(0);
  hoursMultiplier = -1;
}

TimesheetEntry::~TimesheetEntry() {}

void TimesheetEntry::clockOut(std::string worktype, double hourMult,
                              int breakLength) {
  endTime = time(0);

  breakDuration = breakLength;
  workingPeriodType = worktype;
  hoursMultiplier = hourMult;
  calculateEntryTime(startTime, endTime, breakDuration);
}

void TimesheetEntry::calculateEntryTime(time_t start, time_t end,
                                        int breakTime) {
  timeWorked = (end - start) - (breakTime * 60);
  if (timeWorked < 0) {
    // set time to 0 if break was longer than worked time
    timeWorked = 0;
  }
}
