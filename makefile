CC=g++  
CXXFLAGS = -std=c++0x
CFLAGS=-I
skiplist: main.o 
	$(CC) -o ./bin/main main.o --std=c++11 -pthread 
	rm -f ./*.o

clean: 
	rm -f ./*.o
