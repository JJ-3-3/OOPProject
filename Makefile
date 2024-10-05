test : test.cpp
	g++ -o testing -Wall test.cpp Employee.cpp Share.cpp
	./testing
	rm -f testing