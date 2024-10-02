test : test.cpp
	g++ -o testing test.cpp
	./testing
	rm -f testing