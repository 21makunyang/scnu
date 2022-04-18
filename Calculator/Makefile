main:main.o Calculator.o
	g++ main.o Calculator.o -o main
main.o:main.cpp Calculator.h
	g++ -c main.cpp
Calculator.o: Calculator.cpp Calculator.h
	g++ -c Calculator.cpp
clean:
	rm -f main main.o Calculator.o