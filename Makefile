portsetter: portsetter.cpp
	g++-5 -std=c++11 portsetter.cpp -o setport

test: test.cpp
	g++ -std=c++11 test.cpp -o test