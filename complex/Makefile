complex:complex.o Complex.o
	g++ complex.o Complex.o -o complex
complex.o:complex.cpp

Complex.o:Complex.cpp Complex.h
	g++ -c Complex.cpp Complex.h
clean:
	rm -f complex.o complex