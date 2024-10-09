
#ifndef TIMESHEETENTRY_H
#define TIMESHEETENTRY_H

#include <time.h>

#include <string>
#include <vector>

class TimesheetEntry {
 private:
  /* data */
  time_t startTime;
  time_t endTime;

  int breakDuration;

  std::string workingPeriodType;

 public:
  int timeWorked;
  double hoursMultiplier;
  TimesheetEntry(time_t startedTime, time_t endedTime, int breakTime,
                 std::string workingPeriodType, double hoursMultiplier);
  TimesheetEntry(/* args */);
  ~TimesheetEntry();
  // void clockIn(time_t currentTime); not needed as ticket is auto clocked
  void clockOut(std::string worktype, double hourMult, int breakLength);
  void calculateEntryTime(time_t start, time_t end, int breakTime);
};

#endif