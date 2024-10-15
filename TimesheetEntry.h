#ifndef TIMESHEETENTRY_H
#define TIMESHEETENTRY_H

#include <time.h>

#include <string>
#include <vector>

class TimesheetEntry {
 private:
  /* data */

 public:
  time_t startTime;
  time_t endTime;
  int breakDuration;

  std::string workingPeriodType;

  int timeWorked;
  double hoursMultiplier;

  // paramaterised constructor
  TimesheetEntry(time_t startedTime, time_t endedTime, int breakTime,
                 std::string workingPeriodType, double hoursMultiplier);

  // default constructor
  TimesheetEntry(/* args */);

  // timesheet destructor
  ~TimesheetEntry();

  // void clockIn(time_t currentTime); not needed as ticket is auto clocked
  void clockOut(std::string worktype, double hourMult, int breakLength);

  // calculates entry work type
  void calculateEntryTime(time_t start, time_t end, int breakTime);
};

#endif  // TIMESHEETENTRY_H