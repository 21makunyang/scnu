Array:main.o Array.o
	g++ Array.o main.o -o Array
main.o: main.cpp Array.h 
	g++ -c -Wall main.cpp Array.h 
Array.o: Array.h Array.cpp
	g++ -c -Wall Array.h Array.cpp
.PHONY:clean
clean:
	rm -f Array Array.o main.o