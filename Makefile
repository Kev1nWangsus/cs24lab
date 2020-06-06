CXX_FLAG = --std=c++11 -g

all: examheap

examheap: examheap.o heap.o
	g++ $(CXX_FLAG) -o examheap examheap.o heap.o

examheap.o: examheap.cpp
	g++ -c $(CXX_FLAG) examheap.cpp

heap.o: heap.cpp
	g++ -c $(CXX_FLAG) heap.cpp

clean:
	rm -f examheap*.o