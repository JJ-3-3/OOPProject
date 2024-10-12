test : test.cpp
	g++ -o testing test.cpp Employee.cpp Share.cpp Timesheet.cpp TimesheetEntry.cpp Company.cpp
	./testing
	rm -f testing

real : real.cpp
	g++ -o testing real.cpp Employee.cpp Share.cpp Timesheet.cpp TimesheetEntry.cpp Company.cpp pageLoader.cpp
	./testing
	rm -f testing

share : testShareFunc.cpp
	g++ -o testing testShareFunc.cpp
	./testing
	rm -f testingRandShareFunc

page system: pageLoader.cpp
	g++ -o testing pageLoader.cpp
	./testing
	rm -f testing

share2 : testShareChange.cpp
	g++ -o testing testShareChange.cpp Company.cpp Employee.cpp Share.cpp Timesheet.cpp TimesheetEntry.cpp
	./testing
	rm -f testing share change function through company