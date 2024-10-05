test : test.cpp
	g++ -o testing test.cpp Employee.cpp Share.cpp Timesheet.cpp TimesheetEntry.cpp
	./testing
	rm -f testing