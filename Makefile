CXX_FLAG = --std=c++11 -g

all: usestack

usestack: usestack.o intstack.o
	g++ $(CXX_FLAG) -o usestack usestack.o intstack.o

usestack.o: usestack.cpp
	g++ -c $(CXX_FLAG) usestack.cpp

intstack.o: intstack.cpp
	g++ -c $(CXX_FLAG) intstack.cpp