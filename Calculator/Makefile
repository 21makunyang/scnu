main:main.o Calculator.o
	g++ main.o Calculator.o -o main
main.o:Calculator.h

Calculator.o: Calculator.h

clean:
	rm -f main main.o Calculator.o