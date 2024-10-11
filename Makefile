test : test.cpp
	g++ -o testing test.cpp Employee.cpp Share.cpp Timesheet.cpp TimesheetEntry.cpp Company.cpp
	./testing
	rm -f testing

real : real.cpp
	g++ -o testing real.cpp Employee.cpp Share.cpp Timesheet.cpp TimesheetEntry.cpp Company.cpp
	./testing
	rm -f testing