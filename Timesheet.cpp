#include "Timesheet.h"

#include <vector>

Timesheet::Timesheet(/* args */) {}

Timesheet::~Timesheet() {}

inline int Timesheet::getTotalWorkedTime() {
  int totalTime = 0;
  for (int i = 0; i < timesheetEntries.size(); i++) {
    if (timesheetEntries[i].hoursMultiplier == -1) {
      timesheetEntries[i].clockOut("Normal", 1, 0);
    }
    // adds the time worked (in seconds to hours) times by the work type mult to
    // the total time
    totalTime += ((timesheetEntries[i].timeWorked / 3600) *
                  timesheetEntries[i].hoursMultiplier);
    return totalTime;
  }
}

void Timesheet::resetTimesheetEntries() { timesheetEntries.clear(); }

void Timesheet::addEntry(time_t startedTime, time_t endedTime, int breakTime,
                         std::string workingPeriodType,
                         double hoursMultiplier) {
  timesheetEntries.push_back(TimesheetEntry(
      startedTime, endedTime, breakTime, workingPeriodType, hoursMultiplier));
}

void Timesheet::clockIn() { timesheetEntries.push_back(TimesheetEntry()); }
