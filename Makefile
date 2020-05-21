#Makefile
CXX_FLAG = --std=c++11 -g

all: testbst

testbst: testbst.o intbst.o
	g++ $(CXX_FLAG) -o testbst testbst.o intbst.o

test_intbst: test_intbst.o intbst.o
	g++ $(CXX_FLAG) -o test_intbst test_intbst.o intbst.o

test_intbst.o: test_intbst.cpp
	g++ -c $(CXX_FLAG) test_intbst.cpp

testbst.o: testbst.cpp
	g++ -c $(CXX_FLAG) testbst.cpp

intbst.o: intbst.cpp
	g++ -c $(CXX_FLAG) intbst.cpp

clean:
	rm -f test_intbst testbst *.o