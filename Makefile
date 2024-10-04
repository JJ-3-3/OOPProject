test : test.cpp
	g++ -o testing test.cpp Employee.cpp Share.cpp
	./testing
	rm -f testing