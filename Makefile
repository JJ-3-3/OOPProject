# Makefile for building and testing the program

# Compiler to use
CXX = g++

# Flags for the compiler
CXXFLAGS = -o testing 
# -Wall -std=c++11

# Source files
SRC = Employee.cpp Share.cpp Timesheet.cpp TimesheetEntry.cpp Company.cpp Admin.cpp pageLoader.cpp Normal.cpp Manager.cpp Accounting.cpp CEO.cpp Sales.cpp

# Default target to build and test
all: test share share2 clean 

# Target for testing the basic functionality
test: test.cpp $(SRC)
	$(CXX) $(CXXFLAGS) test.cpp $(SRC)
	./testing
	rm -f testing

# Target for real functionality testing
target: target.cpp $(SRC)
	$(CXX) $(CXXFLAGS) target.cpp $(SRC)
	./testing
	rm -f testing

# Target for testing share functionality
share: testShareFunc.cpp
	$(CXX) $(CXXFLAGS) testShareFunc.cpp
	./testing
	rm -f testingRandShareFunc

# Target for testing page loading functionality
page: pageLoader.cpp
	$(CXX) $(CXXFLAGS) pageLoader.cpp
	./testing
	rm -f testing

# Target for testing share change functionality
share2: testShareChange.cpp $(SRC)
	$(CXX) $(CXXFLAGS) testShareChange.cpp $(SRC)
	./testing
	rm -f testing

# Clean up the generated files
clean:
	rm -f testing testingRandShareFunc

.PHONY: all test target share page share2 clean
